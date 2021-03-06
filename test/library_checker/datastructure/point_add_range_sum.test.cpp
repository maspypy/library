#define PROBLEM "https://judge.yosupo.jp/problem/point_add_range_sum"
#include "my_template.hpp"
#include "other/io.hpp"

#include "ds/fenwick.hpp"

void solve() {
  LL(N, Q);
  VEC(ll, A, N);
  FenwickTree<Group_Add<ll>> bit(A);

  FOR(_, Q) {
    LL(t, a, b);
    if (t == 0) {
      bit.add(a, b);
    } else {
      print(bit.sum(a, b));
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
