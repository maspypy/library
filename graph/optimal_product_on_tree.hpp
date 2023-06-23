#include "graph/tree.hpp"
#include "ds/unionfind/unionfind.hpp"

// 木の各頂点に全順序モノイドの元が置かれている（x<=y -> axb<=ayb）
// topological 順序でかけるとき，結果を最大化する
// https://atcoder.jp/contests/agc023/tasks/agc023_f
// https://qoj.ac/problem/6561
// いや抽象化が足りていないな、x<=y iff xy<=yx がいるか？
template <typename TREE, typename Monoid, bool MINIMIZE, typename F>
pair<vc<int>, typename Monoid::value_type> optimal_product_on_tree(
    TREE& tree, vc<typename Monoid::value_type> A, F compare) {
  const int N = tree.N;
  const int root = tree.V[0];
  using X = typename Monoid::value_type;

  vc<int> head(N), tail(N), nxt(N);
  FOR(v, N) head[v] = v, tail[v] = v, nxt[v] = -1;

  UnionFind uf(N);
  // (x, v, size v)
  using T = tuple<X, int, int>;
  auto my_compare = [&](T& t1, T& t2) -> bool {
    X& x1 = get<0>(t1);
    X& x2 = get<0>(t2);
    if constexpr (MINIMIZE) return compare(x2, x1);
    if constexpr (!MINIMIZE) return compare(x1, x2);
  };

  priority_queue<T, vc<T>, decltype(my_compare)> que(my_compare);
  FOR(v, N) if (v != root) que.emplace(A[v], v, 1);

  while (len(que)) {
    auto [_, v, sv] = que.top();
    que.pop();
    if (uf.size(v) != sv) continue;
    int a = head[uf[v]], b = tail[uf[v]];
    int p = uf[tree.parent[a]];
    int c = head[p], d = tail[p];
    X x = Monoid::op(A[p], A[v]);
    uf.merge(p, v);
    v = uf[v];
    A[v] = x, head[v] = c, tail[v] = b, nxt[d] = a;
    if (uf[v] == uf[root]) continue;
    que.emplace(A[v], v, uf.size(v));
  }
  vc<int> I = {root};
  while (nxt[I.back()] != -1) I.eb(nxt[I.back()]);
  return {I, A[uf[root]]};
}