#define PROBLEM \
  "https://judge.yosupo.jp/problem/range_chmin_chmax_add_range_sum"

#include "my_template.hpp"
#include "other/io.hpp"
#include "ds/segtree/beats_summaxmin_chminchmax.hpp"

void solve() {
  LL(N, Q);
  VEC(ll, A, N);
  Beats_SumMaxMin_ChminChmax seg(A);
  FOR(_, Q) {
    LL(t, L, R);
    if (t == 0) {
      LL(x);
      seg.chmin(L, R, x);
    }
    elif (t == 1) {
      LL(x);
      seg.chmax(L, R, x);
    }
    elif (t == 2) {
      LL(x);
      seg.add(L, R, x);
    }
    elif (t == 3) {
      auto x = seg.prod(L, R);
      print(x.sum);
    }
  }
}

signed main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  cout << setprecision(15);

  solve();

  return 0;
}
