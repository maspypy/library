#define PROBLEM "https://yukicoder.me/problems/no/686"
#include "my_template.hpp"
#include "other/io.hpp"
#include "alg/acted_monoid/max_add.hpp"
#include "ds/bbst/rbst_acted_monoid.hpp"

void solve() {
  LL(N);
  using AM = ActedMonoid_Max_Add<int>;
  RBST_ActedMonoid<AM, false, 100'010> X;
  using np = decltype(X)::np;

  const int INF = 1 << 30;
  np root = X.new_node(INF);

  FOR(N) {
    if (X.prod(root) != INF) root = X.merge(root, X.new_node(INF));
    LL(L, R);
    // L未満 / R 未満
    np a, b, c, c1, c2;
    auto check_L = [&](int e) -> bool { return e < L; };
    auto check_R = [&](int e) -> bool { return e < R; };
    tie(a, root) = X.split_max_right(root, check_L);
    tie(b, c) = X.split_max_right(root, check_R);
    tie(c1, c2) = X.split(c, 1);
    b = X.apply(b, 1);
    c1 = X.set(c1, 0, L);
    root = X.merge4(a, c1, b, c2);
  }
  auto check = [&](int e) -> bool { return e < INF; };
  auto [n1, n2] = X.split_max_right(root, check);
  int ANS = (n1 ? n1->size : 0);
  print(ANS);
}

signed main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  cout << setprecision(15);

  ll T = 1;
  // LL(T);
  FOR(T) solve();

  return 0;
}
