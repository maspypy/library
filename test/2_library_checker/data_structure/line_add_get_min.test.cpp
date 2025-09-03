#define PROBLEM "https://judge.yosupo.jp/problem/line_add_get_min"
#include "my_template.hpp"
#include "other/io.hpp"
#include "convex/cht.hpp"

void solve() {
  LL(N, Q);
  CHT_min<ll> cht_min;
  CHT_max<ll> cht_max;
  FOR(N) {
    LL(a, b);
    cht_min.add(a, b);
    cht_max.add(-a, -b);
  }
  FOR(Q) {
    LL(t);
    if (t == 0) {
      LL(a, b);
      cht_min.add(a, b);
      cht_max.add(-a, -b);
    } else {
      LL(x);
      ll y = cht_min.query(x);
      ll z = cht_max.query(x);
      assert(y + z == 0);
      print(y);
    }
  }
}

signed main() {
  solve();

  return 0;
}
