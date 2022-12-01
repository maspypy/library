#define PROBLEM "https://atcoder.jp/contests/abc244/tasks/abc244_Ex"
#include "my_template.hpp"
#include "other/io.hpp"

#include "ds/func/cht.hpp"

void solve() {
  LL(Q);
  CHT_xy<ll> cht;
  FOR(Q) {
    LL(a, b, x, y);
    cht.add(a, b);
    print(cht.get_max(x, y));
  }
}

signed main() {
  solve();

  return 0;
}
