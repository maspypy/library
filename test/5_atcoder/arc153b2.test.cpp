#define PROBLEM "https://atcoder.jp/contests/arc153/tasks/arc153_b"
#include "my_template.hpp"
#include "other/io.hpp"

#include "alg/monoid/dihedral.hpp"

void solve() {
  LL(H, W);
  VEC(string, A, H);
  using MonoX = Dihedral<0>;
  using MonoY = Dihedral<1>;
  pair<int, int> fX = {0, 0}, fY = {0, 0};
  MonoX::set_n(H);
  MonoY::set_n(W);
  LL(Q);
  FOR(Q) {
    LL(a, b);
    fX = MonoX::op(fX, {1, a - 1});
    fY = MonoY::op(fY, {1, b - 1});
  }
  A = MonoX::apply(fX, A);
  FOR(i, H) A[i] = MonoY::apply(fY, A[i]);
  FOR(i, H) print(A[i]);
}

signed main() {
  solve();
  return 0;
}
