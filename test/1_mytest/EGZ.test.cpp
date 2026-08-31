#define PROBLEM "https://judge.yosupo.jp/problem/aplusb"
#include "my_template.hpp"

#include "random/base.hpp"
#include "nt/EGZ.hpp"

void test(int N) {
  FOR(1000) {
    vc<ll> A(2 * N - 1);
    FOR(i, len(A)) A[i] = RNG(0, N);
    vc<int> I = EGZ(N, A);
    ll sm = 0;
    for (int i : I) sm += A[i];
    assert(len(I) == N && sm % N == 0);
    sort(all(I));
    FOR(i, len(I) - 1) assert(I[i] != I[i + 1]);
  }
}

void solve() {
  int a, b;
  cin >> a >> b;
  cout << a + b << "\n";
}

signed main() {
  FOR(N, 1, 100) test(N);
  solve();
  return 0;
}
