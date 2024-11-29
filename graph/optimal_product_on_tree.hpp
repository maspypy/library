#include "graph/tree.hpp"
#include "ds/unionfind/unionfind.hpp"
#include "ds/segtree/segtree.hpp"

// 木の各頂点に全順序モノイドの元が置かれている（x<=y -> axb<=ayb）
// topological 順序でかけるとき，結果を最大化する
// https://atcoder.jp/contests/agc023/tasks/agc023_f
// https://qoj.ac/problem/6561
// いや抽象化が足りていないな、x<=y iff xy<=yx がいるか？
template <typename TREE, typename Monoid, bool MINIMIZE, typename F>
pair<vc<int>, typename Monoid::value_type> optimal_product_on_tree(TREE& tree, vc<typename Monoid::value_type> A, F compare) {
  const int N = tree.N;
  const int root = tree.V[0];
  using X = typename Monoid::value_type;

  vc<int> head(N), tail(N), nxt(N);
  FOR(v, N) head[v] = v, tail[v] = v, nxt[v] = -1;

  UnionFind uf(N);

  int size = 1;
  while (size < N) size *= 2;
  vc<int> seg(2 * size, -1);

  // prique だと動的データ構造を持たせるときに混乱したのでセグ木で
  auto upd = [&](int i) -> void {
    int a = seg[2 * i + 0], b = seg[2 * i + 1];
    if (a == -1) seg[i] = b;
    elif (b == -1) seg[i] = a;
    else seg[i] = (compare(A[a], A[b]) ? a : b);
  };
  // if seg[i]==x: return しようと思ったがデータが変わるという話なのでまずい
  auto set = [&](int i, int x) -> void {
    i += size;
    seg[i] = x;
    while (i > 1) { i /= 2, upd(i); }
  };
  FOR(i, N) if (i != root) seg[size + i] = i;
  FOR_R(i, 1, size) upd(i);

  FOR(N - 1) {
    int v = seg[1];
    int a = head[uf[v]], b = tail[uf[v]];
    int p = uf[tree.parent[a]];
    int c = head[p], d = tail[p];
    X pv = Monoid::op(A[p], A[v]);
    uf.merge(p, v);
    int w = uf[v];
    A[w] = pv, head[v] = c, tail[v] = b, nxt[d] = a;
    int av = -1, ap = -1;
    if (v == w && uf[v] != uf[root]) av = v;
    if (p == w && uf[p] != uf[root]) ap = p;
    set(v, av), set(p, ap);
  }
  vc<int> I = {root};
  while (nxt[I.back()] != -1) I.eb(nxt[I.back()]);
  return {I, A[uf[root]]};
}