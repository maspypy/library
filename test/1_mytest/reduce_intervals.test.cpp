#define PROBLEM "https://judge.yosupo.jp/problem/aplusb"
#include "my_template.hpp"

#include "other/reduce_intervals.hpp"
#include "random/base.hpp"

void test(bool rm_included) {
  FOR(mx, 100) {
    FOR(NN, 100) {
      set<pair<int, int>> st;
      vc<int> L, R;
      FOR(i, NN) {
        int a = RNG(0, mx + 1);
        int b = RNG(0, mx + 1);
        if (a > b)
          swap(a, b);
        pair<int, int> p = {a, b};
        if (st.count(p))
          continue;
        st.insert(p);
        L.eb(a), R.eb(b);
      }
      int N = len(L);
      auto I = reduce_intervals(L, R, rm_included);
      vc<int> er(N, 1);
      for (auto &i : I)
        er[i] = 0;
      FOR(i, N) if (er[i]) {
        bool ok = 0;
        for (auto &j : I) {
          if (rm_included && L[j] <= L[i] && R[i] <= R[j])
            ok = 1;
          if (!rm_included && L[i] <= L[j] && R[j] <= R[i])
            ok = 1;
        }
        assert(ok);
      }
      L = rearrange(L, I);
      R = rearrange(R, I);
      FOR(k, len(L) - 1) { assert(L[k] < L[k + 1] && R[k] < R[k + 1]); }
    }
  }
}

void solve() {
  int a, b;
  cin >> a >> b;
  cout << a + b << '\n';
}

signed main() {
  test(false);
  test(true);
  solve();
  return 0;
}
