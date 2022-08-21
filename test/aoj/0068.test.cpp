#include "my_template.hpp"
#include "other/io.hpp"
#include "geo/incremental_convexhull.hpp"
#include "string/split.hpp"

using Re = double;

void solve() {
  string t;
  while (getline(cin, t)) {
    if (t == "0") break;
    Incremental_ConvexHull<Re> X;
    int N = stoi(t);
    FOR(N) {
      string S;
      getline(cin, S);
      auto tokens = split(S, ",");
      Re x = stod(tokens[0]);
      Re y = stod(tokens[1]);
      X.add(Point<Re>(x, y));
    }
    print(N - X.V());
  }
}

signed main() {
  cout << fixed << setprecision(15);

  ll T = 1;
  // LL(T);
  FOR(T) solve();

  return 0;
}
