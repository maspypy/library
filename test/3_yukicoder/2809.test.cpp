#define PROBLEM "https://yukicoder.me/problems/no/2809"
#include "my_template.hpp"
#include "other/io.hpp"

#include "ds/sortable_array.hpp"

void solve() {
  LL(N, Q);
  VEC(ll, A, N);
  vc<tuple<ll, ll, ll>> query;
  vi X = A;
  FOR(Q) {
    INT(t);
    if (t == 1) {
      LL(k, x);
      query.eb(t, --k, x);
      X.eb(x);
    }
    if (t == 2) { query.eb(t, -1, -1); }
    if (t == 3) {
      LL(k);
      query.eb(t, --k, -1);
    }
  }
  UNIQUE(X);
  for (auto& x: A) x = LB(X, x);

  vc<int> now(N);
  FOR(i, N) now[i] = A[i];
  Sortable_Array SA(20000000, len(X), now);

  for (auto& [t, k, x]: query) {
    if (t == 1) {
      x = LB(X, x);
      SA.set(k, x);
    }
    if (t == 2) { SA.sort_inc(0, N); }
    if (t == 3) {
      ll x = SA.get(k);
      print(X[x]);
    }
  }
}

signed main() {
  int T = 1;
  // INT(T);
  FOR(T) solve();
  return 0;
}
