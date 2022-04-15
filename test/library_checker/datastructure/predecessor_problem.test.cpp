#define PROBLEM "https://judge.yosupo.jp/problem/predecessor_problem"
#include "my_template.hpp"
#include "other/io.hpp"
#include "ds/fastset.hpp"

void solve() {
  LL(N, Q);
  FastSet ss(N);
  STR(S);
  FOR(x, N) {
    if (S[x] == '1') ss.insert(x);
  }

  FOR(_, Q) {
    LL(t, k);
    if (t == 0) { ss.insert(k); }
    elif (t == 1) { ss.erase(k); }
    elif (t == 2) { print(ss[k]); }
    elif (t == 3) {
      ll x = ss.next(k);
      if (x == N) x = -1;
      print(x);
    }
    elif (t == 4) { print(ss.prev(k)); }
  }
}

signed main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  cout << setprecision(15);

  solve();

  return 0;
}
