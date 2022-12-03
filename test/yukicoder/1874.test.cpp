#define PROBLEM "https://yukicoder.me/problems/no/1874"
#include "my_template.hpp"
#include "other/io.hpp"
#include "ds/fenwicktree/fenwicktree.hpp"

struct Grp {
  using value_type = tuple<ll, ll, ll, ll>;
  using X = value_type;
  static X op(const X& x, const X& y) {
    auto& [ax, bx, cx, dx] = x;
    auto& [ay, by, cy, dy] = y;
    return {ax + ay, bx + by, cx + cy, dx + dy};
  }
  static X inverse(const X& x) {
    auto& [ax, bx, cx, dx] = x;
    return {-ax, -bx, -cx, -dx};
  }
  // static X power(const X &x, ll n) { return n * x; }
  static constexpr X unit() { return {0, 0, 0, 0}; }
  static constexpr bool commute = 1;
};

void solve() {
  LL(N);
  ll LIM = 1'000'000;
  vvc<int> Y_to_X(LIM + 1);
  using T = typename Grp::value_type;
  vc<T> bit_raw(LIM + 1);
  vc<int> X;

  FOR(N) {
    LL(x, y);
    bit_raw[x] = Grp::op(bit_raw[x], {1, x, y, x * y});
    Y_to_X[y].eb(x);
    X.eb(x);
  }
  UNIQUE(X);

  FenwickTree<Grp> bit(bit_raw);

  ll ANS = 1LL << 60;
  unordered_map<int, ll> MP;
  FOR(y, LIM + 1) {
    if (len(Y_to_X[y]) == 0) continue;
    for (auto&& x: Y_to_X[y]) { bit.add(x, {-2, -2 * x, -2 * y, -2 * x * y}); }
    MP.clear();

    auto f = [&](ll x) -> ll {
      if (MP.count(x)) return MP[x];
      auto [a, b, c, d] = bit.sum(x);
      auto [a1, b1, c1, d1] = bit.sum_all();
      a = a1 - 2 * a;
      b = b1 - 2 * b;
      c = c1 - 2 * c;
      d = d1 - 2 * d;
      ll res = a * x * y - b * y - c * x + d;
      chmin(ANS, res);
      return (MP[x] = res);
    };

    auto check = [&](int k) -> bool {
      if (k == 0) return true;
      return f(X[k - 1]) >= f(X[k]);
    };
    int k = binary_search(check, 0, len(X));
    f(k);
  }
  print(ANS);
}

signed main() {
  cout << fixed << setprecision(15);

  ll T = 1;
  // LL(T);
  FOR(T) solve();

  return 0;
}
