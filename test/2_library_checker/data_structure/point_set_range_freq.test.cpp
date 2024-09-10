#define PROBLEM "https://judge.yosupo.jp/problem/point_set_range_frequency"
#include "my_template.hpp"
#include "other/io.hpp"
#include "ds/fenwicktree/fenwicktree_01.hpp"
#include "ds/hashmap.hpp"

void solve() {
  INT(N, Q);
  HashMap<int> MP(N + Q);
  vvc<pair<int, int>> dat(N + Q);
  int p = 0;
  auto get = [&](int x) -> int {
    int k = MP.get(x, -1);
    return (k == -1 ? MP[x] = p++ : k);
  };

  vc<int> A(N);

  FOR(i, N) {
    INT(x);
    A[i] = get(x);
    dat[A[i]].eb(0, i);
  }

  vc<pair<int, int>> LR;

  FOR(Q) {
    INT(t);
    if (t == 0) {
      INT(i, v);
      v = get(v);
      dat[A[i]].eb(1, i);
      A[i] = v;
      dat[A[i]].eb(0, i);
    }
    if (t == 1) {
      INT(L, R, x);
      x = get(x);
      dat[x].eb(2, len(LR));
      LR.eb(L, R);
    }
  }
  FOR(i, N) { dat[A[i]].eb(1, i); }
  Q = len(LR);
  vc<int> ANS(Q);

  FenwickTree_01 bit(N);
  FOR(x, p) {
    for (auto& [t, i]: dat[x]) {
      if (t == 0) bit.add(i);
      elif (t == 1) bit.remove(i);
      else {
        auto [L, R] = LR[i];
        ANS[i] = bit.sum(L, R);
      }
    }
  }
  for (auto& x: ANS) print(x);
}

signed main() {
  solve();
  return 0;
}
