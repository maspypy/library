
// x -> (x+a)/b+c
// 合成のいたるところでinfty<ll>/2以上にならないことを仮定くらいで大丈夫だと思う.
// https://codeforces.com/contest/878/problem/E
// https://contest.ucup.ac/contest/3426/problem/17272
struct Monoid_Add_Divide {
  using value_type = tuple<ll, ll, ll>;
  using X = value_type;
  static X op(X L, X R) {
    auto [a1, b1, c1] = L;
    auto [a2, b2, c2] = R;
    auto [q, r] = divmod<ll>(c1 + a2, b2);
    i128 a = a1 + i128(b1) * r;
    i128 b = i128(b1) * b2;
    ll c = q + c2;
    while (a >= b) a -= b, c += 1;
    assert(0 <= a && a < b);
    if (b < infty<ll>) return {a, b, c};
    i128 t = b - a;
    if (a <= infty<ll> / 2) return {a, infty<ll>, c};
    if (t <= infty<ll> / 2) return {infty<ll> - t, infty<ll>, c};
    return {infty<ll> / 2, infty<ll>, c};
  }
  static X add(ll x) { return {x, 1, 0}; }
  static X divide(ll x) { return {0, 1, x}; }

  static ll eval(X f, ll x) {
    auto [a, b, c] = f;
    return floor<ll>(x + a, b) + c;
  }

  static constexpr X id() { return {0, 1, 0}; }
  static constexpr bool commute = 0;
};