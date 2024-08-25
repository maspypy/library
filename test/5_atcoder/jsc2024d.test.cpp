#define PROBLEM "https://atcoder.jp/contests/jsc2024-final/tasks/jsc2024_final_d"
#include "my_template.hpp"
#include "other/io.hpp"

#include "ds/segtree/beats_kinetic.hpp"

void solve() {
  LL(N);
  VEC(int, A, N);
  vc<int> X = A;
  UNIQUE(X);
  vc<int> rk(N);
  FOR(i, N) rk[i] = LB(X, A[i]);

  vc<int> mrk = rk;
  FOR(i, N - 1) chmin(mrk[i + 1], mrk[i]);

  ll n = len(X);
  Beats_Kinetic_Max<ll, ll> seg(n, [&](int i) -> pi { return {X[i], 0}; });

  ll ADD = A[0];
  FOR(i, 1, N) {
    ll mr = mrk[i - 1], r = rk[i];
    if (mr > r) {
      ADD += X[r];
    } else {
      ll ma = seg.prod(r, n).se;
      ADD += X[mr];

      seg.apply(0, r, 1, -X[mr]);
      ll now = seg.prod(r, r + 1).se;
      ll add = ma + X[r] - X[mr] - now;
      if (add > 0) { seg.apply(r, r + 1, 0, add); }
    }
  }

  ll ANS = seg.prod(0, n).se;
  ANS += ADD;
  print(ANS);
}

signed main() { solve(); }
