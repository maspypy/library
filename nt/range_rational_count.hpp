
#include "nt/mertens.hpp"
#include "mod/floor_sum_of_linear.hpp"

// 最大分母 N を指定する
// 既約分数を数えたり k 番目を求めたりする
struct Range_Rational_Count {
  u32 N;
  u64 total;
  Mertens<int> M;
  Range_Rational_Count(u32 N) : N(N), M(N) { total = count(1, 1); }

  // [0, a/b)
  u64 count(u32 a, u32 b) {
    assert(a <= b);
    if (a == 0) return 0;
    // [0,a/b]
    u64 ans = 1;
    floor_range(N, [&](u32 q, u32 l, u32 r) -> void {
      ans += u64(M[q]) * floor_sum_of_linear<u64, u64>(l, r, a, 0, b);
    });
    // a/b
    if (b <= N) --ans;
    return ans;
  }

  // [0,1) の中で k 番目
  pair<u32, u32> kth(u64 k) {
    assert(k < total);
    u32 int_part = k / total;
    k %= total;
    map<pair<u32, u32>, u64> MP;
    auto query = [&](u32 a, u32 b) -> u64 {
      pair<u32, u32> k = {a, b};
      if (MP.count(k)) return MP[k];
      return MP[k] = count(a, b);
    };
    // k 個以下なものの max
    u32 a = 0, b = 1, c = 1, d = 1;
    while (b + d <= N) {
      // 右に進む
      u32 l = 0, r = 1;
      while (b + r * d <= N && query(a + r * c, b + r * d) <= k) {
        l = r, r = 2 * r;
      }
      while (l + 1 < r) {
        u32 m = l + (r - l) / 2;
        (query(a + m * c, b + m * d) <= k ? l : r) = m;
      }
      a += l * c, b += l * d;
      // 左に進む
      l = 0, r = 1;
      while (r * b + d <= N && query(r * a + c, r * b + d) > k) {
        l = r, r = 2 * r;
      }
      while (l + 1 < r) {
        u32 m = l + (r - l) / 2;
        (query(m * a + c, m * b + d) > k ? l : r) = m;
      }
      c += l * a, d += l * b;
    }
    return {int_part * b + a, b};
  }
};