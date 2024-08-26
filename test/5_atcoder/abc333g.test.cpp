#define PROBLEM "https://atcoder.jp/contests/abc333/tasks/abc333_g"
#include "my_template.hpp"
#include "other/io.hpp"
#include "nt/rational_binary_search.hpp"
#include "bigint/base.hpp"

using T = BigInteger;

void solve() {
  STR(S);
  LL(N);
  i128 B = 1;
  i128 A = 1;
  if (count(all(S), '.') == 0) {
    B = 1;
    A = stoi(S);
  } else {
    int p = S.find('.');
    A = stoi(S.substr(0, p));
    S = S.substr(p + 1);
    while (len(S)) {
      B *= 10;
      A = 10 * A + (S[0] - '0');
      S = S.substr(1);
    }
  }

  auto [a, b, c, d] = rational_binary_search<ll>(
      [&](i128 a, i128 b) -> bool {
        // a/b <= A/B
        return a * B <= A * b;
      },
      N);

  // A/B-a/b vs c/d-A/B
  // (Ab-Ba)/(Bb) bs (Bc-Ad)/(Bd)
  // d(Ab-Ba) bs b(Bc-Ad)

  T LHS = T(d) * T(A * b - B * a);
  T RHS = T(b) * T(B * c - A * d);
  if (LHS <= RHS)
    print(a, b);
  else
    print(c, d);
}

signed main() {
  int T = 1;
  // INT(T);
  FOR(T) solve();
  return 0;
}
