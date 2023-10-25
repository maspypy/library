#define PROBLEM "https://judge.yosupo.jp/problem/aplusb"
#include "my_template.hpp"
#include "other/io.hpp"

#include "mod/dynamic_modint.hpp"
#include "seq/geometric_sequence_sum.hpp"

template <int K>
void test() {
  using mint = dmint;
  FOR(p, 1, 50) {
    FOR(r, 50) {
      FOR(n, 50) {
        mint::set_mod(p);
        auto A = geometic_sequence_sum_K<mint, K>(r, n);
        FOR(k, K + 1) {
          mint ans = 0;
          mint pow = 1;
          FOR(i, n) { ans += pow * mint(i).pow(k), pow *= mint(r); }
          assert(A[k] == ans);
        }
      }
    }
  }
}

void solve() {
  LL(a, b);
  print(a + b);
}

signed main() {
  test<0>();
  test<1>();
  test<2>();
  test<3>();
  test<4>();
  solve();
  return 0;
}