#define PROBLEM "https://yukicoder.me/problems/no/2935"
#include "my_template.hpp"
#include "other/io.hpp"

#include "alg/monoid/min.hpp"
#include "ds/segtree/dynamic_segtree.hpp"

// x に対して, 1,2,3 個あるための最小の L を持つ

const int LIM = 100'100;

void solve() {
  LL(N);
  VEC(int, A, N);
  Dynamic_SegTree<Monoid_Min<int>, true> seg(10000000, 0, LIM);

  using np = decltype(seg)::np;
  vvc<np> root(4);
  FOR(i, 4) root[i].resize(N + 1);
  vc<int> S(LIM, -1);
  FOR(i, 1, 4) root[i][0] = seg.new_node(S);
  vvc<int> I(LIM);

  FOR(i, N) {
    int x = A[i];
    FOR(k, 4) root[k][i + 1] = root[k][i];

    root[1][i + 1] = seg.set(root[1][i + 1], x, i);
    if (len(I[x]) >= 1) {
      root[2][i + 1] = seg.set(root[2][i + 1], x, I[x][len(I[x]) - 1]);
    }
    if (len(I[x]) >= 2) {
      root[3][i + 1] = seg.set(root[3][i + 1], x, I[x][len(I[x]) - 2]);
    }
    I[x].eb(i);
  }

  LL(Q);
  ll last = 0;

  auto solve = [&](ll L, ll R) -> ll {
    vi ANS;
    FOR(k, 1, 4) {
      ll x = seg.max_right(
          root[k][R], [&](auto e) -> bool { return e >= L; }, 0);
      ANS.eb(x);
    }
    // non-empty とかいう条件に対処する必要がある！
    ll ans = SUM<ll>(ANS);
    SHOW(L, R, ANS);
    if (ANS[2] > 0)
      return ans;
    if (ANS[1] > 0) {
      if (ANS[0] + ANS[1] < R - L) {
        return ans;
      }
      return ans - 1;
    }
    chmin(ans, R - L - 2);
    return ans;
  };
  FOR(Q) {
    LL(L, R);
    L ^= last;
    R ^= last;
    --L;
    ll ans = solve(L, R);
    print(ans);
    last = ans;
  }
}

signed main() { solve(); }