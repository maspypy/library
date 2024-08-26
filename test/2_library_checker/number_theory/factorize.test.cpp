#define PROBLEM "https://judge.yosupo.jp/problem/factorize"
#include "my_template.hpp"
#include "other/io.hpp"

#include "nt/factor.hpp"

void solve() {
  LL(x);
  auto pf = factor(x);
  vi ANS;
  for (auto&& [p, e]: pf) { FOR(_, e) ANS.eb(p); }
  if (len(ANS))
    print(len(ANS), ANS);
  else
    print(0);
}

signed main() {
  INT(T);
  FOR(T) solve();

  return 0;
}
