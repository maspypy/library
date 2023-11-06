#define PROBLEM "https://judge.yosupo.jp/problem/staticrmq"
#include "my_template.hpp"
#include "other/io.hpp"

#include "alg/monoid/min.hpp"
#include "ds/static_range_product.hpp"

signed main() {
  using Mono = Monoid_Min<u32>;
  using ST = Sparse_Table<Mono>;
  INT(N, Q);
  Static_Range_Product<Mono, ST> X(N, [&](int i) -> u32 {
    u32 x;
    read(x);
    return x;
  });
  FOR(Q) {
    u32 L, R;
    read(L, R);
    print(X.prod(L, R));
  }
  return 0;
}
