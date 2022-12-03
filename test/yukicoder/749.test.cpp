#define PROBLEM "https://yukicoder.me/problems/no/749"
#include "my_template.hpp"
#include "other/io.hpp"
#include "mod/modint.hpp"
#include "ds/segtree/lazy_segtree.hpp"
#include "alg/monoid/add_pair.hpp"

using mint = modint107;

// (a, fsum)
using MonoX = Monoid_Add_Pair<mint>;

// pa + q + rf, f
struct MonoA {
  using value_type = tuple<mint, mint, mint>;
  using X = value_type;
  static X op(X x, X y) {
    auto [a, b, c] = y;
    auto [d, e, f] = x;
    return {a * d, a * e + b, a * f + c};
  }
  static constexpr X unit() { return {mint(1), mint(0), mint(0)}; }
  static constexpr bool commute = true;
};

struct AM {
  using Monoid_X = MonoX;
  using Monoid_A = MonoA;
  using X = typename Monoid_X::value_type;
  using A = typename Monoid_A::value_type;
  static X act(const X &x, const A &a, const ll &size) {
    auto [sum, fsum] = x;
    auto [p, q, r] = a;
    return {p * sum + q * mint(size) + r * fsum, fsum};
  }
};

void solve() {
  LL(N, Q);
  vc<mint> F(N);
  F[1] = 1;
  FOR3(i, 2, N) F[i] = F[i - 2] + F[i - 1];
  Lazy_SegTree<AM> seg(N, [&](int i) -> typename MonoX::value_type {
    return {mint(0), F[i]};
  });

  FOR(Q) {
    LL(t, L, R, k);
    ++R;
    if (t == 0) { print(seg.prod(L, R).fi * mint(k)); }
    if (t == 1) { seg.apply(L, R, {mint(0), mint(k), mint(0)}); }
    if (t == 2) { seg.apply(L, R, {mint(1), mint(k), mint(0)}); }
    if (t == 3) { seg.apply(L, R, {mint(k), mint(0), mint(0)}); }
    if (t == 4) { seg.apply(L, R, {mint(1), mint(0), mint(k)}); }
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
