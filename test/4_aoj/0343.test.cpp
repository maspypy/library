#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=0343"
#include "my_template.hpp"
#include "other/io.hpp"
#include "ds/pbds.hpp"

void solve() {
  LL(N, Q);
  // (score, -idx)
  pbds_set<pi> ss;
  vi A(N);
  FOR(i, N) ss.insert({A[i], -i});
  FOR(Q) {
    LL(tp);
    if (tp == 0) {
      LL(idx, p);
      --idx;
      ss.erase({A[idx], -idx});
      A[idx] += p;
      ss.insert({A[idx], -idx});
    } else {
      LL(rk);
      rk = N - rk;
      auto [a, b] = *(ss.find_by_order(rk));
      b = 1 + (-b);
      print(b, a);
    }
  }
}

signed main() {
  cout << fixed << setprecision(15);

  ll T = 1;
  // LL(T);
  FOR(T) solve();

  return 0;
}
