#define PROBLEM "https://yukicoder.me/problems/no/1618"
#include "my_template.hpp"
#include "other/io.hpp"
#include "poly/convolution.hpp"

void solve() {
  LL(N);
  VEC(ll, A, N);
  VEC(ll, B, N);
  A.insert(A.begin(), 0);
  B.insert(B.begin(), 0);
  vc<ll> f(N + 1);
  iota(all(f), 0);
  A = convolution(A, f);
  B = convolution(B, f);
  FOR(i, len(A)) A[i] += B[i];
  A.erase(A.begin());
  print(A);
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
