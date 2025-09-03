#define PROBLEM "https://yukicoder.me/problems/no/1891"
#include "my_template.hpp"
#include "other/io.hpp"
#include "ds/sparse_table/xor_disjoint_sparse_table.hpp"
#include "mod/modint.hpp"
#include "alg/monoid/affine.hpp"

using mint = modint998;
using Mono = Monoid_Affine<mint>;
using DST = Xor_Disjoint_Sparse_Table<Mono>;
void solve() {
  INT(N, Q);
  DST seg(N, [](int i) -> typename Mono::value_type {
    INT(a, b);
    return {a, b};
  });
  FOR(Q) {
    INT(l, r, p, x);
    auto f = seg.prod(l, r, p);
    print(Mono::eval(f, x));
  }
}

signed main() {
  solve();

  return 0;
}
