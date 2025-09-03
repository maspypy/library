#define PROBLEM "https://yukicoder.me/problems/no/902"
#include "my_template.hpp"
#include "other/io.hpp"

#include "graph/ds/link_cut_tree.hpp"
#include "ds/removable_queue.hpp"

// X: cluster data
// VX: vertex data
// MX: light child data
struct Node {
  using np = Node *;
  using VX = ll;
  using X = ll;

  Node *l, *r, *p;
  int idx, size; // size は heavy path の頂点数
  bool rev;
  VX vx = 0;
  X x = 0;

  Node(int i = 0)
      : l(nullptr), r(nullptr), p(nullptr), idx(i), size(1), rev(0) {}

  void update() {
    size = 1;
    x = vx;
    if (l) { size += l->size, x += l->x; }
    if (r) { size += r->size, x += r->x; }
  }

  void push() {
    if (rev) {
      if (l) l->reverse();
      if (r) r->reverse();
      rev = 0;
    }
  }

  // data の reverse も行う
  void reverse() {
    rev ^= 1;
    swap(l, r);
  }

  // LCT 内で expose, update を行うのでここは変更だけ
  void set(VX x) { vx = x; }

  void add_light(np c) {}
  void erase_light(np c) {}
  void change_light(np a, np b) {}
};

void solve() {
  LL(N);
  Link_Cut_Tree<Node> LCT(2 * N - 1);

  FOR(e, N - 1) {
    LL(a, b, c);
    int idx = N + e;
    LCT.set(idx, c);
    LCT.link(a, idx), LCT.link(b, idx);
  }

  auto dist = [&](int a, int b) -> ll {
    LCT.evert(a);
    LCT.expose(b);
    return LCT[b]->x;
  };

  auto solve_1 = [&]() -> void {
    LL(u, v, w, x);
    // uv -> vw(x)
    ll e = LCT.jump(u, v, 1);
    LCT.cut(u, e), LCT.cut(e, v);
    LCT.set(e, x);
    LCT.link(v, e), LCT.link(e, w);
  };

  auto solve_2 = [&]() -> void {
    LL(K);
    VEC(int, X, K);
    // 頂点インデックス順で dfs したときの euler 順にソートできる
    // jump の計算のときに evert しているので LCA 取得前に evert しなおすこと
    int r = X[0];
    sort(all(X), [&](auto a, auto b) -> bool {
      if (a == b) return false;
      LCT.evert(r);
      int c = LCT.lca(a, b);
      if (a == c) return true;
      if (b == c) return false;
      int x = LCT.jump(c, a, 1);
      int y = LCT.jump(c, b, 1);
      return x < y;
    });
    X.eb(X[0]);
    ll ANS = 0;
    FOR(k, K) { ANS += dist(X[k], X[k + 1]); }
    ANS /= 2;
    print(ANS);
  };

  LL(Q);
  FOR(Q) {
    LL(t);
    if (t == 1) solve_1();
    if (t == 2) solve_2();
  }
}

signed main() {
  solve();
  return 0;
}