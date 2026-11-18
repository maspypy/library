#include "my_template.hpp"
#include "ds/point_set_range_sum_sqrt.hpp"
#include "alg/monoid/xor.hpp"

/*
対象: ds/point_set_range_sum_sqrt.hpp
  Point_Set_Range_Sum_Sqrt::build / set / add / multiply / prod / sum /
  prod_all / sum_all を検証する。

独立オラクル: 各要素を std::vector に保持し、[l,r) を直接畳み込む。
  実装のブロック分割・補集合を利用した差分計算は模倣しない。
  加算群と XOR 群の両方で、逆元の使い方や符号の取り違えを検査する。

狙う不具合: ブロック境界の off-by-one、部分ブロックと全体集約の
  二重計上、set の旧値除去忘れ、build の再利用時の古い値の残留。
  空配列・空区間・ちょうどブロック長・前後 1 要素を明示的に含む。

条件: b_sz > 0、問い合わせは 0 <= l <= r <= n、更新先は 0 <= i < n。
  加算値は小さい整数に限定し、符号付き整数のオーバーフローを避ける。
  乱数は mt19937_64 の固定 seed 0x21a9b17（型・ブロック長で分離）。
*/

template <class Group, int B>
void run_group(const char* group_name, uint64_t seed) {
  using E = typename Group::value_type;
  using DS = Point_Set_Range_Sum_Sqrt<Group, B>;
  mt19937_64 rng(seed ^ (uint64_t(B) * 0x9e3779b97f4a7c15ULL));
  auto rand_value = [&]() -> E {
    if constexpr (std::is_signed<E>::value) {
      return E(int(rng() % 20001) - 10000);
    } else {
      return E(rng());
    }
  };

  set<int> sizes{0, 1, 2, 3, 4, 7, 8, 9, 15, 16, 17,
                 31, 32, 33, 63, 64, 65, 127, 128, 129, 255, 256, 257,
                 B - 1, B, B + 1, 2 * B - 1, 2 * B, 2 * B + 1};
  for (int n : sizes) {
    DS ds(n);
    vector<E> ref(n, Group::id());
    auto brute = [&](int l, int r) -> E {
      E ans = Group::id();
      for (int i = l; i < r; ++i) ans = Group::op(ans, ref[i]);
      return ans;
    };
    auto fail = [&](int step, int l, int r, E got, E expected) {
      cerr << "Point_Set_Range_Sum_Sqrt mismatch: " << group_name
           << " B=" << B << " n=" << n << " step=" << step
           << " range=[" << l << ',' << r << ") got=" << got
           << " expected=" << expected << '\n';
      abort();
    };
    auto check = [&](int step, int l, int r) {
      E expected = brute(l, r);
      E got = ds.prod(l, r);
      if (got != expected) fail(step, l, r, got, expected);
      got = ds.sum(l, r);
      if (got != expected) fail(step, l, r, got, expected);
    };
    auto check_all = [&](int step) {
      E expected = brute(0, n);
      if (ds.prod_all() != expected)
        fail(step, 0, n, ds.prod_all(), expected);
      if (ds.sum_all() != expected)
        fail(step, 0, n, ds.sum_all(), expected);
      int k = int(rng() % uint64_t(n + 1));
      E prefix = brute(0, k);
      if (ds.sum(k) != prefix) fail(step, 0, k, ds.sum(k), prefix);
      if (ds.prod(k) != prefix) fail(step, 0, k, ds.prod(k), prefix);
      check(step, 0, 0);
      check(step, n, n);
      check(step, 0, n);
    };

    // 値を返すコンストラクタと再 build を、同じ配列に対して照合する。
    for (auto& x : ref) x = rand_value();
    DS constructed(n, [&](int i) -> E { return ref[i]; });
    if (constructed.prod_all() != brute(0, n)) abort();
    ds.build(ref);
    check_all(-1);

    for (int step = 0; step < 520; ++step) {
      int action = int(rng() % 10);
      if (n && action < 5) {
        int i = int(rng() % uint64_t(n));
        E x = rand_value();
        if (action == 0 || action == 1) {
          ds.set(i, x);
          ref[i] = x;
        } else if (action == 2 || action == 3) {
          ds.add(i, x);
          ref[i] = Group::op(ref[i], x);
        } else {
          ds.multiply(i, x);
          ref[i] = Group::op(ref[i], x);
        }
      } else if (action == 5) {
        ds.build(ref);
      } else if (action == 6) {
        ds.build(n, [&](int i) -> E { return ref[i]; });
      } else if (action == 7) {
        ds.build(n);
        fill(ref.begin(), ref.end(), Group::id());
      }

      // 毎回ランダム区間を複数チェック。空区間も自然に出現する。
      for (int j = 0; j < 3; ++j) {
        int l = int(rng() % uint64_t(n + 1));
        int r = int(rng() % uint64_t(n + 1));
        if (l > r) swap(l, r);
        check(step, l, r);
      }
      check_all(step);
      // 境界を固定して照合し、乱択だけでは漏れやすい空端と全区間を覆う。
      if (step % 73 == 0) {
        for (int l : {0, n / 2, n})
          for (int r : {l, n}) check(step, l, r);
      }
    }
    ds.build(n);
    fill(ref.begin(), ref.end(), Group::id());
    check_all(521);
  }
  cerr << "PASS " << group_name << " block=" << B << '\n';
}

int main() {
  run_group<Monoid_Add<ll>, 1>("add_ll", 0x21a9b17ULL);
  run_group<Monoid_Add<ll>, 3>("add_ll", 0x21a9b17ULL);
  run_group<Monoid_Add<ll>, 7>("add_ll", 0x21a9b17ULL);
  run_group<Monoid_Add<ll>, 16>("add_ll", 0x21a9b17ULL);
  run_group<Monoid_Add<ll>, 64>("add_ll", 0x21a9b17ULL);
  run_group<Monoid_Xor<u64>, 1>("xor_u64", 0x21a9b17ULL);
  run_group<Monoid_Xor<u64>, 3>("xor_u64", 0x21a9b17ULL);
  run_group<Monoid_Xor<u64>, 7>("xor_u64", 0x21a9b17ULL);
  run_group<Monoid_Xor<u64>, 16>("xor_u64", 0x21a9b17ULL);
  run_group<Monoid_Xor<u64>, 64>("xor_u64", 0x21a9b17ULL);
}
