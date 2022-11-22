#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=0350"
#include "my_template.hpp"
#include "other/io.hpp"
#include "nt/rational.hpp"

void solve() {
  STR(S);
  if (S.back() != ')') S += "(0)";
  using Q = Rational<ll, true>;
  vi POW(12);
  POW[0] = 1;
  FOR(i, 11) POW[i + 1] = 10 * POW[i];

  int p = S.find('.');
  string A = S.substr(0, p);
  string B = S.substr(p + 1);

  Q ANS;

  FOR(i, len(A)) {
    ll x = A[i] - '0';
    x *= POW[len(A) - 1 - i];
    ANS += Q(x, 1);
  }

  p = B.find('(');
  string C = B.substr(p + 1);
  B = B.substr(0, p);

  FOR(i, len(B)) {
    ll b = B[i] - '0';
    ANS += Q(b, POW[i + 1]);
  }
  Q cf = Q(1, POW[len(B)]);
  C.pop_back();
  ANS += cf * Q(stoi(C), POW[len(C)] - 1);
  print(ANS.to_string());
}

signed main() {
  cout << fixed << setprecision(15);

  ll T = 1;
  // LL(T);
  FOR(T) solve();

  return 0;
}
