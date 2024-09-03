#define PROBLEM "https://judge.yosupo.jp/problem/point_set_tree_path_composite_sum"
#include "my_template.hpp"
#include "other/io.hpp"

#include "graph/ds/dynamic_rerooting_tree_dp.hpp"
#include "mod/modint.hpp"

using mint = modint998;

struct Data {
  mint a, b; // path composition = x -> ax+b
  mint cnt;
  mint ans;
  void out() { SHOW(a, b, cnt, ans); }
};

struct TREE_DP {
  using value_type = Data;
  using X = value_type;

  static X unit() { return {mint(1), mint(0), mint(0), mint(0)}; }
  static X rake(X& L, X& R) { return {L.a, L.b, L.cnt + R.cnt, L.ans + R.ans}; }
  static X compress(X& L, X& R) {
    mint a = L.a, b = L.b;
    mint c = R.a, d = R.b;
    // x -> (cx+d) -> a(cx+d)+b
    mint aa = a * c, bb = a * d + b;
    mint cnt = L.cnt + R.cnt;
    mint ans = L.ans + a * R.ans + b * R.cnt;
    return {aa, bb, cnt, ans};
  }
  static X rake2(X& L, X& R) { return {L.a, L.b, L.cnt + R.cnt, L.ans + L.a * R.ans + L.b * R.cnt}; }
  static X rake3(X& L, X& R) { return rake(L, R); }
  static X compress2(X& L, X& R) { return compress(R, L); }
};

void solve() {
  LL(N, Q);
  VEC(mint, A, N);
  vc<mint> B(N - 1), C(N - 1);
  Graph<int, 0> G(N);
  FOR(i, N - 1) {
    INT(u, v);
    G.add(u, v);
    read(B[i], C[i]);
  }
  G.build();

  Tree<decltype(G)> tree(G);

  auto single = [&](int v) -> pair<Data, Data> {
    assert(v > 0);
    int e = tree.v_to_e(v);
    Data up = {B[e], C[e], 1, B[e] * A[v] + C[e]};
    Data down = {B[e], C[e], 1, A[v]};
    return {up, down};
  };

  Dynamic_Rerooting_Tree_Dp<decltype(tree), TREE_DP> DP(tree, single);

  FOR(Q) {
    INT(t);
    if (t == 0) {
      INT(w, x);
      A[w] = x;
      if (w > 0) DP.set(w, single(w));
    }
    if (t == 1) {
      INT(e, b, c);
      B[e] = b, C[e] = c;
      int v = tree.e_to_v(e);
      DP.set(v, single(v));
    }
    INT(r);
    Data x = DP.prod_all(r);
    // x.out();
    mint ans = x.ans + x.a * A[0] + x.b;
    print(ans);
  }
}

signed main() {
  solve();
  return 0;
}
