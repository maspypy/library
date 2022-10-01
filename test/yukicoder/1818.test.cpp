#define PROBLEM "https://yukicoder.me/problems/no/1818"
#include "my_template.hpp"
#include "other/io.hpp"
#include "dp/edit_distance.hpp"

void solve() {
  LL(N, M);
  VEC(ll, A, N);
  VEC(ll, B, M);
  string S, T;
  FOR(i, N) {
    FOR(A[i]) S += 'a';
    S += 'b';
  }
  FOR(i, M) {
    FOR(B[i]) T += 'a';
    T += 'b';
  }

  print(edit_distance(S, T));
}

signed main() {
  cout << fixed << setprecision(15);

  ll T = 1;
  // LL(T);
  FOR(T) solve();

  return 0;
}
