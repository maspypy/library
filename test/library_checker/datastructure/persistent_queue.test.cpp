#define PROBLEM "https://judge.yosupo.jp/problem/persistent_queue"
#include "my_template.hpp"
#include "other/io.hpp"

#include "ds/persistent_array.hpp"

void solve() {
  LL(Q);
  vi L(Q + 1), R(Q + 1);

  using PA = PersistentArray<int>;
  using np = PA::np;
  vc<np> PAS(Q + 1);
  PA array;
  PAS[0] = array.get_root();
  L[0] = 0, R[0] = 0;
  FOR(q, Q) {
    LL(t);
    if (t == 0) {
      LL(k, x);
      ++k;
      PAS[q + 1] = array.set(PAS[k], R[k], x);
      L[q + 1] = L[k];
      R[q + 1] = R[k] + 1;
    }
    elif (t == 1) {
      LL(k);
      ++k;
      print(array.get(PAS[k], L[k]));
      PAS[q + 1] = PAS[k];
      L[q + 1] = L[k] + 1;
      R[q + 1] = R[k];
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
