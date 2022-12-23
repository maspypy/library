#define PROBLEM "https://judge.yosupo.jp/problem/associative_array"
#include "my_template.hpp"
#include "other/io.hpp"
#include "ds/hashmap.hpp"

void solve() {
  LL(Q);
  HashMap<ll> A;
  FOR(Q) {
    LL(t);
    if (t == 0) {
      LL(k, v);
      A[k] = v;
    } else {
      LL(k);
      print(A[k]);
    }
  }
}

signed main() {
  solve();

  return 0;
}
