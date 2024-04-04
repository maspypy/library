#define PROBLEM "https://atcoder.jp/contests/abc306/tasks/abc306_ex"

#include "my_template.hpp"
#include "other/io.hpp"

#include "mod/modint.hpp"
#include "setfunc/sps_inv.hpp"

using mint = modint998;
void solve() {
  LL(N, M);
  vc<int> nbd(N);
  FOR(M) {
    INT(a, b);
    --a, --b;
    nbd[a] |= 1 << b;
    nbd[b] |= 1 << a;
  }

  vc<mint> F(1 << N);
  FOR(s, 1 << N) {
    int comp = 0;
    int yet = s;
    while (yet) {
      int root = lowbit(yet);
      yet ^= 1 << root;
      ++comp;
      int que = 1 << root;
      while (que) {
        int p = lowbit(que);
        que ^= 1 << p;
        int nxt = nbd[p] & yet;
        while (nxt) {
          int to = lowbit(nxt);
          que |= 1 << to, nxt ^= 1 << to, yet ^= 1 << to;
        }
      }
    }
    F[s] = (comp % 2 == 0 ? 1 : -1);
  }

  F = sps_inv<mint, 17>(F);
  print(F.back());
}

signed main() {
  int T = 1;
  // INT(T);
  FOR(T) solve();
  return 0;
}
