#define PROBLEM "https://yukicoder.me/problems/no/1891"
#include "my_template.hpp"
#include "other/io.hpp"
#include "ds/disjointsparse/xor_disjointsparse.hpp"
#include "mod/modint.hpp"
#include "alg/monoid/affine.hpp"

using mint = modint998;

void solve() {
  INT(N, Q);
  using Mono = Monoid_Affine<mint>;
  Xor_DisjointSparse<Mono> seg(N, [](int i) -> typename Mono::value_type {
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
