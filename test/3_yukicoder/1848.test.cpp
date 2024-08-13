#define PROBLEM "https://yukicoder.me/problems/no/1848"
#include "my_template.hpp"
#include "other/io.hpp"
#include "string/zalgorithm.hpp"
#include "mod/modint.hpp"

using mint = modint107;

void solve() {
  LL(N);
  VEC(int, A, N);
  STR(S);
  auto Ac = cumsum<ll>(A);

  // 1 文字目以降
  vc<pair<char, int>> dat;
  FOR(i, 1, N) dat.eb(S[i], A[i]);
  auto Z = zalgorithm<decltype(dat)>(dat);

  mint ANS = 0;
  FOR(i, N) {
    if (S[i] != S[0]) continue;
    ll a = A[0], b = A[i];
    ll k = min(a, b);
    ANS += mint(k * (k + 1) / 2);
    ANS += mint(a * (b - k));

    if (A[i] < A[0] || i == N - 1) continue;
    ll z = Z[i];
    ll s = Ac[z + 1];
    if (i + z + 1 < N && S[1 + z] == S[1 + z + i]) {
      s += min(A[1 + z], A[1 + z + i]);
    }
    ANS += mint(s - a);
  }
  print(ANS);
}

signed main() {
  cout << fixed << setprecision(15);

  ll T = 1;
  // LL(T);
  FOR(T) solve();

  return 0;
}
