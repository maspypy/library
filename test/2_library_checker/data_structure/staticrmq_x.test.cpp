#define PROBLEM "https://judge.yosupo.jp/problem/staticrmq"
#include "my_template.hpp"
#include "other/io.hpp"

#include "ds/static_rmq.hpp"
#include "alg/monoid/min.hpp"

void solve() {
  INT(N, Q);
  Static_RMQ<Monoid_Min<int>> seg(N, [&](int i) -> int {
    INT(x);
    return x;
  });
  FOR(Q) {
    INT(l, r);
    print(seg.prod(l, r));
  }
}

signed main() {
  solve();
  return 0;
}
