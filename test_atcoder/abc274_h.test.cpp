#define PROBLEM "https://atcoder.jp/contests/abc274/tasks/abc274_Ex"
#include "my_template.hpp"
#include "other/io.hpp"

#include "random/base.hpp"
#include "nt/GF2.hpp"
#include "string/rollinghash_field.hpp"

void solve() {
  LL(N, Q);
  VEC(ll, A, N);
  using F = GF2<60>;
  RollingHash_Field<F> X;
  auto HA = X.build(A);

  FOR(Q) {
    LL(a, b, c, d, e, f);
    --a, --c, --e;
    ll n1 = b - a, n2 = f - e;

    auto check = [&](int n) -> bool {
      // lcp >= n
      if (n1 < n || n2 < n) return false;
      F x1 = X.query(HA, a, a + n);
      F x2 = X.query(HA, c, c + n);
      F x3 = X.query(HA, e, e + n);
      return (x1 + x2) == x3;
    };

    ll n = binary_search(check, 0, N + 1);
    if (n < min(n1, n2)) {
      u64 x = A[a + n] ^ A[c + n];
      u64 y = A[e + n];
      Yes(x < y);
    } else {
      // prefix
      Yes(n1 < n2);
    }
  }
}

signed main() {
  cout << fixed << setprecision(15);

  ll T = 1;
  // LL(T);
  FOR(T) solve();

  return 0;
}
