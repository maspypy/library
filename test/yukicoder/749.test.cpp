#define PROBLEM "https://yukicoder.me/problems/no/749"
#include "my_template.hpp"
#include "other/io.hpp"
#include "mod/modint.hpp"
#include "ds/segtree/lazysegtree.hpp"

using mint = modint107;

// (a,cnt,fsum)
struct MonoX {
  using value_type = tuple<mint, mint, mint>;
  using X = value_type;
  static X op(X x, X y) {
    auto [a, b, c] = x;
    auto [d, e, f] = y;
    return {a + d, b + e, c + f};
  }
  static constexpr X unit() { return {mint(0), mint(0), mint(0)}; }
  static constexpr bool commute = true;
};

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
  static X act(const X &x, const A &a) {
    auto [sum, cnt, fsum] = x;
    auto [p, q, r] = a;
    return {p * sum + q * cnt + r * fsum, cnt, fsum};
  }
};

void solve() {
  LL(N, Q);
  vc<mint> F(N);
  F[1] = 1;
  FOR3(i, 2, N) F[i] = F[i - 2] + F[i - 1];
  LazySegTree<AM> seg(N);
  FOR(i, N) seg.set(i, {mint(0), mint(1), F[i]});

  FOR(Q) {
    LL(t, L, R, k);
    mint mk = k;
    ++R;
    if (t == 0) {
      auto [sum, cnt, fsum] = seg.prod(L, R);
      print(sum * mk);
    }
    if (t == 1) { seg.apply(L, R, {mint(0), mk, mint(0)}); }
    if (t == 2) { seg.apply(L, R, {mint(1), mk, mint(0)}); }
    if (t == 3) { seg.apply(L, R, {mk, mint(0), mint(0)}); }
    if (t == 4) { seg.apply(L, R, {mint(1), mint(0), mk}); }
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
