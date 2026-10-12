
/*
position:
x<=L: L+a
L<=x<=R:x+a
R<=x: R+a

cost:
x<=L: b-(L-x)
L<=x<=R: b
R<=x: b-(x-R)
*/

struct Monoid_Add_Chmin_Chmax_with_Cost {
  struct S {
    ll L, R, a, b;
  };
  using value_type = S;
  using X = value_type;
  static X op(const X& f, const X& g) {
    // g(f(x))
    ll l = clamp(g.L - f.a, f.L, f.R);
    ll r = clamp(g.R - f.a, f.L, f.R);
    ll y = clamp(l + f.a, g.L, g.R);
    ll a = y + g.a - l;
    ll b = f.b + g.b - abs(l + f.a - y);
    return {l, r, a, b};
  }
  static constexpr X id() { return {-infty<ll>, infty<ll>, 0, 0}; }
  static constexpr bool commute = 0;
  // return: {position, cost}
  static pair<ll, ll> eval(const S& f, ll x) {
    auto [L, R, a, b] = f;
    if (x <= L) {
      return {L + a, b - (L - x)};
    }
    elif (x <= R) { return {x + a, b}; }
    else {
      return {R + a, b - (x - R)};
    }
  }
};