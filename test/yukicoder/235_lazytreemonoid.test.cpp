#define PROBLEM "https://yukicoder.me/problems/no/235"
#include "my_template.hpp"
#include "other/io.hpp"
#include "graph/hld.hpp"
#include "graph/lazytreemonoid.hpp"
#include "alg/lazy_cntsum_add.hpp"
#include "mod/modint.hpp"

using mint = modint107;
using Lazy = Lazy_CntSum_Add<mint>;

void solve() {
  LL(N);
  VEC(ll, S, N);
  VEC(ll, C, N);
  Graph G(N);
  G.read_tree();
  HLD hld(G);
  vc<pair<mint, mint>> dat;
  FOR(i, N) dat.eb(C[i], S[i]);
  LazyTreeMonoid<decltype(hld), Lazy, false> TM(hld, dat);
  LL(Q);
  FOR(Q) {
    LL(t);
    if (t == 0) {
      LL(a, b, c);
      --a, --b;
      TM.apply_path(a, b, c);
    } else {
      LL(a, b);
      --a, --b;
      print(TM.prod_path(a, b).se);
    }
  }
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
