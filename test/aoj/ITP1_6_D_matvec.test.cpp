#define PROBLEM \
  "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_6_D"
#include "my_template.hpp"
#include "other/io.hpp"
#include "linalg/mat_mul.hpp"

void solve() {
  LL(H, W);
  VV(ll, A, H, W);
  VEC(ll, B, W);
  auto C = mat_vec_mul(A, B);
  for (auto&& c: C) print(c);
}

signed main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  cout << setprecision(15);

  ll T = 1;
  // LL(T);
  FOR(_, T) solve();

  return 0;
}
