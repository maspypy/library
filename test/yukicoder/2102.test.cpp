#define PROBLEM "https://yukicoder.me/problems/no/2102"
#include "my_template.hpp"
#include "other/io.hpp"

#include "string/rollinghash.hpp"
#include "ds/hashset.hpp"

void solve() {
  HashSetLL<21> MP;

  RollingHash RH;

  LL(N);
  FOR(N) {
    STR(S);
    ll n = len(S);
    auto SH = RH.build(S);
    using M61 = modint61;
    vc<M61> X;
    X.eb(RH.query(SH, 0, n));
    FOR(i, n - 1) {
      string mi;
      mi += S[i + 1];
      mi += S[i];
      M61 m = RH.query(RH.build(mi), 0, 2);
      M61 l = RH.query(SH, 0, i);
      M61 r = RH.query(SH, i + 2, n);
      l = RH.combine(l, m, 2);
      l = RH.combine(l, r, n - i - 2);
      X.eb(l);
    }
    bool ok = 0;
    for (auto&& x: X) {
      if (MP.count(x.val)) ok = 1;
    }
    Yes(ok);
    MP.insert(X[0].val);
  }
}

signed main() {
  cout << fixed << setprecision(15);

  ll T = 1;
  // LL(T);
  FOR(T) solve();

  return 0;
}
