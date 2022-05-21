#define PROBLEM "https://yukicoder.me/problems/no/1321"
#include "my_template.hpp"
#include "other/io.hpp"
#include "mod/modint.hpp"
#include "seq/surjection.hpp"

using mint = modint998;

void solve() {
  LL(N, M, K);
  auto f = surjection_k<mint>(K, N);
  mint ANS = 0;
  FOR(n, N + 1) {
    // n 個選択
    mint x = C<mint>(N, n);
    // 選択した n 個を決める
    x *= f[n];
    // 他はどうでもよい
    x *= mint(M).pow(N - n);
    ANS += x;
  }
  ANS *= C<mint>(M, K);
  print(ANS);
}

signed main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  cout << setprecision(15);

  ll T = 1;
  // LL(T);
  FOR(T) solve();

  return 0;
}
