#define PROBLEM "https://judge.yosupo.jp/problem/aplusb"
#include "my_template.hpp"

#include "mod/modint.hpp"
#include "seq/famous/narayana.hpp"

using mint = modint107;

void test(int a, int b) {
  int n = a + b;
  vc<mint> ANS(n + 1);
  FOR(s, 1 << n) {
    if (popcnt(s) != a) continue;
    vc<int> A(n);
    FOR(i, n) A[i] = (s >> i & 1 ? 1 : -1);
    auto Ac = cumsum<int>(A);
    if (MIN(Ac) < 0) continue;
    int k = 0;
    FOR(i, n - 1) k += (A[i] != A[i + 1]);
    ANS[k] += 1;
  }
  FOR(k, n + 1) { assert(ANS[k] == narayana_number<mint>(a, b, k)); }
}

void solve() {
  int a, b;
  cin >> a >> b;
  cout << a + b << "\n";
}

signed main() {
  FOR(a, 10) FOR(b, 10) test(a, b);
  solve();
}
