#define PROBLEM "https://yukicoder.me/problems/no/1142"
#include "my_template.hpp"
#include "other/io.hpp"
#include "setfunc/xor_convolution.hpp"

void solve() {
  LL(N, M, K);
  ll a = 0;
  ll LIM = 1024;
  vc<i128> f(LIM), g(LIM);
  f[0] = g[0] = 1;
  FOR(i, N) {
    LL(x);
    a ^= x;
    f[a]++;
  }
  a = 0;
  FOR(i, M) {
    LL(x);
    a ^= x;
    g[a]++;
  }
  f = xor_convolution(f, f);
  g = xor_convolution(g, g);
  f[0] -= N + 1;
  g[0] -= M + 1;
  f = xor_convolution(f, g);
  print((f[K] / 4) % 1000000007);
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
