#define PROBLEM "https://yukicoder.me/problems/no/1167"
#include "my_template.hpp"
#include "other/io.hpp"
#include "ds/offline_query/range_xor_basis_query.hpp"
#include "mod/modint.hpp"

using mint = modint107;

void solve() {
  LL(N, Q);
  VEC(u32, A, N);
  vvc<pi> query(Q);
  FOR(q, Q) {
    LL(M);
    VEC(ll, B, M);
    B.insert(B.begin(), 0);
    B.eb(N);
    FOR(k, len(B) - 1) query[q].eb(B[k], B[k + 1]);
  }

  Range_Xor_Basis_Query<u32, 32> X(A);
  FOR(q, Q) {
    for (auto&& [l, r]: query[q]) { X.query(l, r); }
  }

  vc<int> dims(X.Q);
  auto CALC = [&](int q, vc<u32> basis) -> void { dims[q] = len(basis); };

  X.calc(CALC);
  int p = 0;
  FOR(q, Q) {
    int e = 0;
    for (auto&& [l, r]: query[q]) {
      int d = dims[p++];
      e += r - l - d;
    }
    print(mint(2).pow(e));
  }
}

signed main() {
  solve();
  return 0;
}
