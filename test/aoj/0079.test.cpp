#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=0079"
#define ERROR 0.000001

#include "my_template.hpp"
#include "other/io2.hpp"
#include "string/split.hpp"

#include "geo/incremental_convexhull.hpp"

void solve() {
  using Re = double;
  Incremental_ConvexHull<Re> X;
  string S;
  while (getline(cin, S)) {
    auto tokens = split(S, ",");
    Re x = stod(tokens[0]);
    Re y = stod(tokens[1]);
    X.add(Point<Re>(x, y));
  }
  print(X.area<Re>());
}

signed main() {
  cout << fixed << setprecision(15);

  ll T = 1;
  // LL(T);
  FOR(T) solve();

  return 0;
}
