#include "my_template.hpp"
#include "other/io.hpp"
#include "ds/static_range_product_group.hpp"

// 対象: ds/static_range_product_group.hpp のコンストラクタ・build・prod。
// 非可換群 S4（4点の置換）の区間積を、配列を左から逐次合成する独立oracleで照合する。
// prefix[l] の逆元の掛け方・積の順序、空区間、再build時の旧状態残存を検出する。
// 単体元を含む全24置換、n=0・1・2^k前後、固定seed 20261120 を使用。
// 入力はすべて正当な置換と有効な半開区間 [l,r)。

using P = std::array<int, 4>;
struct Permutation_Group {
  using value_type = P;
  static P id() { return {0, 1, 2, 3}; }
  // op(a,b) = a ∘ b。非可換である。
  static P op(const P &a, const P &b) {
    P c{};
    for (int i = 0; i < 4; ++i) c[i] = a[b[i]];
    return c;
  }
  static P inverse(const P &a) {
    P b{};
    for (int i = 0; i < 4; ++i) b[a[i]] = i;
    return b;
  }
};

static std::vector<P> all_perms() {
  std::vector<P> res;
  P p = Permutation_Group::id();
  do { res.push_back(p); } while (std::next_permutation(p.begin(), p.end()));
  return res;
}

static void test_permutation() {
  const auto perms = all_perms();
  assert(perms.size() == 24);
  std::mt19937_64 rng(20261120);
  const std::vector<int> sizes = {0, 1, 2, 3, 4, 7, 8, 9, 15, 16, 17, 31, 32, 33, 63, 64, 65, 127, 128, 129};
  for (int n : sizes) {
    std::vector<P> a(n, Permutation_Group::id());
    Static_Range_Product_Group<Permutation_Group> st;
    for (int round = 0; round < 22; ++round) {
      for (auto &v : a) v = perms[rng() % 24];
      if (round % 2 == 0) st.build(a);
      else st.build(n, [&](int i) -> P { return a[i]; });
      assert(st.n == n);
      auto check = [&](int l, int r) {
        P expected = Permutation_Group::id();
        for (int i = l; i < r; ++i) expected = Permutation_Group::op(expected, a[i]);
        P actual = st.prod(l, r);
        if (actual != expected) {
          std::cerr << "PERM group n=" << n << " round=" << round << " l=" << l << " r=" << r << "\n";
          std::abort();
        }
      };
      for (int i = 0; i <= n; ++i) {
        check(i, i);
        if (i < n) check(i, i + 1);
      }
      check(0, n);
      for (int it = 0; it < 180; ++it) {
        int l = rng() % (n + 1), r = rng() % (n + 1);
        if (l > r) std::swap(l, r);
        check(l, r);
      }
    }
    // vectorを受けるコンストラクタも検証する。
    Static_Range_Product_Group<Permutation_Group> from_vec(a);
    P expected = Permutation_Group::id();
    for (auto p : a) expected = Permutation_Group::op(expected, p);
    assert(from_vec.prod(0, n) == expected);
    Static_Range_Product_Group<Permutation_Group> from_func(n, [&](int i) { return a[i]; });
    assert(from_func.prod(0, n) == expected);
  }
}

static void test_additive() {
  std::mt19937_64 rng(20261121);
  Static_Range_Product_Group<Monoid_Add<long long>> st;
  for (int n : {0, 1, 2, 31, 64, 65, 127, 512}) {
    std::vector<long long> a(n);
    for (int round = 0; round < 10; ++round) {
      for (auto &x : a) x = static_cast<long long>(rng() % 2000001) - 1000000;
      st.build(a);
      for (int it = 0; it < 400; ++it) {
        int l = rng() % (n + 1), r = rng() % (n + 1);
        if (l > r) std::swap(l, r);
        long long expected = 0;
        for (int i = l; i < r; ++i) expected += a[i];
        if (st.prod(l, r) != expected) {
          std::cerr << "ADD group n=" << n << " round=" << round << " l=" << l << " r=" << r << "\n";
          std::abort();
        }
      }
    }
  }
}

int main() {
  test_permutation();
  test_additive();
  std::cerr << "PASS static_range_product_group_noncommutative\n";
}
