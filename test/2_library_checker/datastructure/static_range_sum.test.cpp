#define PROBLEM "https://judge.yosupo.jp/problem/static_range_sum"

#include "my_template.hpp"
#include "other/io.hpp"

#include "ds/static_range_product_group.hpp"

void solve() {
  LL(N, Q);

  Prefix_Sum<u64> seg(N, [&](int i) -> u32 {
    U32(x);
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