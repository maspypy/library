#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=0058"
#include "my_template.hpp"
#include "other/io.hpp"
#include "string/split.hpp"
#include "geo/base.hpp"

void solve() {
  string s;
  while (getline(cin, s)) {
    auto tokens = split(s, " ");
    if (len(tokens) != 8) break;
    vc<int> A(8);
    FOR(i, 8) A[i] = int(round(100000 * stod(tokens[i])));
    Line<ll> X(Point<ll>(A[0], A[1]), Point<ll>(A[2], A[3]));
    Line<ll> Y(Point<ll>(A[4], A[5]), Point<ll>(A[6], A[7]));
    YES(X.is_orthogonal(Y));
  }
}

signed main() {
  cout << fixed << setprecision(15);

  ll T = 1;
  // LL(T);
  FOR(T) solve();

  return 0;
}
