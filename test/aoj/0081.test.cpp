#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=0081"
#define ERROR 0.0001
#include "my_template.hpp"
#include "other/io.hpp"
#include "geo/base.hpp"
#include "string/split.hpp"
#include "geo/reflection.hpp"

void solve() {
  string s;
  using Re = double;
  while (cin >> s) {
    auto tokens = split(s, ",");
    Point<Re> A(stod(tokens[0]), stod(tokens[1]));
    Point<Re> B(stod(tokens[2]), stod(tokens[3]));
    Point<Re> C(stod(tokens[4]), stod(tokens[5]));
    Line<Re> L(A, B);
    Point<Re> D = reflection<Re, Re, Re>(C, L);
    print(D.x, D.y);
  }
}

signed main() {
  cout << fixed << setprecision(15);

  ll T = 1;
  // LL(T);
  FOR(T) solve();

  return 0;
}
