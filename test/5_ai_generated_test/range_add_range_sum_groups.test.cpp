#include "my_template.hpp"
#include "other/io.hpp"
#include "ds/range_add_range_sum.hpp"

// 対象: ds/range_add_range_sum.hpp の build / add / sum。
// 区間加算・区間和を vector による逐次更新と直接走査で独立検証する。
// 加算群と XOR 群の両方で検査し、更新式の符号・境界係数・power の扱いを確認。
// 空区間、L=0/R=n、同一区間の反復、再buildで過去の更新が残らないことを重点検証。
// 正当な [L,R) (0<=L<=R<=n)、値は小さくoverflowしない範囲。seed固定。

struct Test_Xor_Group {
  using value_type = unsigned long long;
  static constexpr bool commute = true;
  static value_type id() { return 0; }
  static value_type op(value_type a, value_type b) { return a ^ b; }
  static value_type inverse(value_type a) { return a; }
  static value_type power(value_type a, long long n) { return (n & 1) ? a : 0; }
};

template <class Group, bool XOR_CASE>
static void check_group(unsigned long long seed) {
  using E = typename Group::value_type;
  std::mt19937_64 rng(seed);
  Range_Add_Range_Sum<Group> ds;
  auto random_value = [&]() -> E {
    if constexpr (XOR_CASE) return static_cast<E>(rng() % 65536);
    else return static_cast<E>(static_cast<long long>(rng() % 200001) - 100000);
  };
  for (int n : {0, 1, 2, 3, 7, 8, 15, 16, 17, 31, 32, 33, 63, 64, 65, 127, 128, 129, 257}) {
    std::vector<E> a(n, Group::id());
    for (int round = 0; round < 7; ++round) {
      if (round % 3 == 0) {
        ds.build(n);
        std::fill(a.begin(), a.end(), Group::id());
      } else {
        for (auto &x : a) x = random_value();
        if (round % 3 == 1) ds.build(a);
        else ds.build(n, [&](int i) -> E { return a[i]; });
      }
      auto query = [&](int l, int r, int it) {
        E expected = Group::id();
        for (int i = l; i < r; ++i) expected = Group::op(expected, a[i]);
        E got = ds.sum(l, r);
        if (got != expected) {
          std::cerr << "range add sum mismatch: xor=" << XOR_CASE << " seed=" << seed
                    << " n=" << n << " round=" << round << " it=" << it
                    << " l=" << l << " r=" << r << " got=" << got << " expected=" << expected << "\n";
          std::abort();
        }
      };
      for (int it = 0; it < 950; ++it) {
        int l = rng() % (n + 1), r = rng() % (n + 1);
        if (l > r) std::swap(l, r);
        const int mode = rng() % 10;
        if (mode <= 5) {
          if (mode == 0) l = 0;
          if (mode == 1) r = n;
          if (mode == 2) r = l;  // 空区間
          E x = random_value();
          ds.add(l, r, x);
          for (int i = l; i < r; ++i) a[i] = Group::op(a[i], x);
        } else {
          query(l, r, it);
        }
        query(0, n, it);
        query(l, r, it);
        query(l, l, it);
        query(r, r, it);
        if (n && (it % 37 == 0)) {
          int pos = rng() % n;
          query(pos, pos + 1, it);
        }
      }
    }
  }
}

int main() {
  check_group<Monoid_Add<long long>, false>(20261120);
  check_group<Test_Xor_Group, true>(20261121);
  std::cerr << "PASS range_add_range_sum_groups\n";
}
