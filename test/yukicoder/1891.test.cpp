#define PROBLEM "https://yukicoder.me/problems/no/1891"
#include "my_template.hpp"
#include "other/io.hpp"
#include "mod/modint.hpp"
#include "alg/monoid/affine.hpp"
#include "ds/disjoint_sparse/xor_sparsetable.hpp"

using mint = modint998;

void solve() {
  LL(N, Q);
  ll LOG = topbit(N);
  using Mono = Monoid_Affine<mint>;
  using X = typename Mono::value_type;
  VEC(X, A, N);
  Xor_SparseTable<Mono> seg(A);
  FOR(Q) {
    LL(l, r, p, x);
    auto [a, b] = seg.prod(l, r, p);
    print(a * mint(x) + b);
  }
}

signed main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  cout << setprecision(15);

  ll T = 1;
  // LL(T);
  FOR(_, T) solve();

  return 0;
}
