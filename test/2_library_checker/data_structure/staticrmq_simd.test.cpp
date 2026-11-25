#define PROBLEM "https://judge.yosupo.jp/problem/staticrmq"

#include "my_template.hpp"
#include "other/io.hpp"

#include "ds/segtree/range_min.hpp"

void solve() {
  INT(N, Q);
  Range_Min<int> seg(N, [&](int i) -> int {
    INT(x);
    return x;
  });
  FOR(Q) {
    INT(l, r);
    print(seg.prod(l, r));
  }
}

signed main() {
  int T = 1;
  // INT(T);
  FOR(T) solve();
  return 0;
}
