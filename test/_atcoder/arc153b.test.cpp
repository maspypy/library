#define PROBLEM "https://atcoder.jp/contests/arc153/tasks/arc153_b"
#include "my_template.hpp"
#include "other/io.hpp"
#include "ds/splaytree/splaytree_basic.hpp"

void solve() {
  LL(H, W);
  VEC(string, G, H);
  SplayTree_Basic<int, 300'000> X;

  vc<int> A(H), B(W);
  iota(all(A), 0), iota(all(B), 0);

  using np = decltype(X)::np;
  auto root_1 = X.new_node(A);
  auto root_2 = X.new_node(B);

  LL(Q);
  FOR(Q) {
    LL(a, b);
    X.reverse(root_1, 0, a);
    X.reverse(root_1, a, H);
    X.reverse(root_2, 0, b);
    X.reverse(root_2, b, W);
  }

  A = X.get_all(root_1);
  B = X.get_all(root_2);

  vc<string> ANS(H, string(W, '?'));
  FOR(i, H) FOR(j, W) { ANS[i][j] = G[A[i]][B[j]]; }
  FOR(i, H) print(ANS[i]);
}

signed main() {
  cout << fixed << setprecision(15);

  ll T = 1;
  // LL(T);
  FOR(T) solve();

  return 0;
}