#define PROBLEM "https://judge.yosupo.jp/problem/factorize"
#include "my_template.hpp"
#include "other/io.hpp"

#include "nt/factor.hpp"

void solve() {
  LL(Q);
  FOR(_, Q) {
    LL(x);
    auto pf = factor(x);
    vi ANS;
    for (auto&& [p, e]: pf) { FOR(_, e) ANS.eb(p); }
    if (len(ANS))
      print(len(ANS), ANS);
    else
      print(0);
  }
}

signed main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  cout << setprecision(15);

  solve();

  return 0;
}
