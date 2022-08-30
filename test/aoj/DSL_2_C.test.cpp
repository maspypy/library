#define PROBLEM \
  "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_C"
#include "my_template.hpp"
#include "other/io.hpp"
#include "ds/kdtree_monoid.hpp"

struct Mono {
  using value_type = vc<int>;
  using X = value_type;
  static X op(X x, X y) {
    x.insert(x.end(), all(y));
    return x;
  }
  static X unit() { return {}; }
  static constexpr bool commute = 1;
};

void solve() {
  LL(N);
  vi X, Y;
  vvc<int> idx(N);
  FOR(i, N) {
    LL(x, y);
    X.eb(x);
    Y.eb(y);
    idx[i].eb(i);
  }
  KDTree_Monoid<Mono> KDT(X, Y, idx);

  LL(Q);
  FOR(Q) {
    LL(xl, xr, yl, yr);
    flush();
    auto e = KDT.prod(xl, yl, xr + 1, yr + 1);
    sort(all(e));
    for (auto&& v: e) print(v);
    print();
  }
}

signed main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  cout << fixed << setprecision(15);

  ll T = 1;
  // LL(T);
  FOR(T) solve();

  return 0;
}
