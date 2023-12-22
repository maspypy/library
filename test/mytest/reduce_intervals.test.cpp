#define PROBLEM "https://judge.yosupo.jp/problem/aplusb"
#include "my_template.hpp"

#include "random/base.hpp"
#include "other/reduce_intervals.hpp"

void test(bool rm_included) {
  FOR(mx, 100) {
    FOR(N, 100) {
      vc<int> L(N), R(N);
      FOR(i, N) {
        int a = RNG(0, mx + 1);
        int b = RNG(0, mx + 1);
        if (a > b) swap(a, b);
        L[i] = a, R[i] = b;
      }
      auto I = reduce_intervals(L, R, rm_included);
      vc<int> rm(N);
      FOR(i, N) FOR(j, N) {
        if (L[i] <= L[j] && R[j] <= R[i] && R[i] - L[i] > R[j] - L[j]) {
          rm[(rm_included ? j : i)] = 1;
        }
      }
      vc<int> cnt(N);
      for (auto& i: I) cnt[i]++;
      FOR(i, N) { assert(cnt[i] == 1 - rm[i]); }
      L = rearrange(L, I);
      R = rearrange(R, I);
      FOR(k, len(L) - 1) { assert(L[k] <= L[k + 1] && R[k] <= R[k + 1]); }
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