#include "geo/base.hpp"
#include "ds/splaytree/splaytree_basic.hpp"
#include "graph/planar_graph.hpp"

template <typename T>
vc<tuple<int, int, int>> monotone_polygon_triangulation(vc<Point<T>> point) {
  int N = len(point);
  int rot = min_element(all(point)) - point.begin();
  rotate(point.begin(), point.begin() + rot, point.end());
  int n = max_element(all(point)) - point.begin();
  FOR(i, n) assert(point[i] < point[i + 1]);
  FOR(i, n, N) assert(point[(i + 1) % N] < point[i]);
  vc<tuple<int, int, int>> res;
  auto side = [&](int i) -> int {
    assert(i != 0 && i != n);
    return (i < n ? 0 : 1);
  };
  vc<int> I = argsort(point);
  vc<int> stack = {I[0], I[1]};
  int s = side(I[1]);
  FOR(i, 2, N - 1) {
    int v = I[i], t = side(v);
    if (s == 0 && t == 0) {
      while (len(stack) >= 2 && ccw(point[stack[len(stack) - 2]], point[stack[len(stack) - 1]], point[v]) == 1) {
        res.eb(stack[len(stack) - 2], stack[len(stack) - 1], v), POP(stack);
      }
      stack.eb(v);
    }
    elif (s == 1 && t == 1) {
      while (len(stack) >= 2 && ccw(point[stack[len(stack) - 2]], point[stack[len(stack) - 1]], point[v]) == -1) {
        res.eb(stack[len(stack) - 2], v, stack[len(stack) - 1]), POP(stack);
      }
      stack.eb(v);
    }
    elif (s == 0 && t == 1) {
      FOR(j, len(stack) - 1) res.eb(stack[j], stack[j + 1], v);
      stack = {stack.back(), v}, s = t;
    }
    elif (s == 1 && t == 0) {
      FOR(j, len(stack) - 1) res.eb(stack[j], v, stack[j + 1]);
      stack = {stack.back(), v}, s = t;
    }
  }
  if (s == 0) { FOR(j, len(stack) - 1) res.eb(stack[j], stack[j + 1], n); }
  elif (s == 1) { FOR(j, len(stack) - 1) res.eb(stack[j], n, stack[j + 1]); }
  for (auto& [a, b, c]: res) a = (a + rot) % N, b = (b + rot) % N, c = (c + rot) % N;
  return res;
}

// (i,j,k), ccw
template <typename T>
vc<tuple<int, int, int>> polygon_triangulation(vc<Point<T>> point) {
  using P = Point<T>;
  int N = len(point);
  enum vtype { MERGE, SPLIT, START, END, UPPER, LOWER };
  auto pre = [&](int i) -> int { return (i > 0 ? i - 1 : N - 1); };
  auto nxt = [&](int i) -> int { return (i < N - 1 ? i + 1 : 0); };
  auto get_vtype = [&](int i) -> vtype {
    int l = pre(i), r = nxt(i);
    if (point[i] < point[l] && point[i] < point[r]) { return (ccw(point[l], point[i], point[r]) == 1 ? START : SPLIT); }
    if (point[l] < point[i] && point[r] < point[i]) { return (ccw(point[l], point[i], point[r]) == 1 ? END : MERGE); }
    if (point[l] < point[i] && point[i] < point[r]) return LOWER;
    if (point[r] < point[i] && point[i] < point[l]) return UPPER;
    assert(0);
    return END;
  };
  SplayTree_Basic<int> ST(N);
  using np = decltype(ST)::np;
  vc<np> nodes(N);
  FOR(i, N) nodes[i] = ST.new_node(i);
  np S = ST.new_root();
  auto comp = [&](int i, P p) -> bool {
    P A = point[i], B = point[nxt(i)];
    return ccw(A, B, p) == -1;
  };

  vc<int> helper(N, -1);
  vc<bool> merged(N);

  Planar_Graph<T> G(N, point);
  FOR(i, N) G.add(i, nxt(i));

  auto add_edge = [&](int v, int w) -> void { merged[w] = 1, G.add(v, w); };

  auto fix_up = [&](int v, int e) -> void {
    int w = helper[e];
    if (get_vtype(w) == vtype::MERGE && !merged[w]) { add_edge(v, w); }
  };
  auto I = argsort(point);
  for (auto& i: I) {
    vtype t = get_vtype(i);
    if (t == vtype::MERGE) {
      ST.splay(nodes[i], 1), S = nodes[i];
      int n = (nodes[i]->l ? nodes[i]->l->size : 0);
      auto [L, M, R] = ST.split3(S, n, n + 1);
      int j = ST.get(R, 0);
      S = ST.merge(L, R);
      fix_up(i, i), fix_up(i, j);
      helper[j] = i;
    }
    if (t == vtype::SPLIT) {
      auto [L, R] = ST.split_max_right(S, [&](int k) -> bool { return comp(k, point[i]); });
      int j = ST.get(R, 0);
      add_edge(i, helper[j]);
      helper[j] = i, helper[pre(i)] = i;
      S = ST.merge3(L, nodes[pre(i)], R);
    }
    if (t == vtype::START) {
      auto [L, R] = ST.split_max_right(S, [&](int k) -> bool { return comp(k, point[i]); });
      S = ST.merge3(L, nodes[pre(i)], R), helper[pre(i)] = i;
    }
    if (t == vtype::END) {
      ST.splay(nodes[i], 1), S = nodes[i];
      int n = (nodes[i]->l ? nodes[i]->l->size : 0);
      auto [L, M, R] = ST.split3(S, n, n + 1);
      S = ST.merge(L, R);
      fix_up(i, i);
    }
    if (t == vtype::UPPER) {
      ST.splay(nodes[i], 1), S = nodes[i];
      int n = (nodes[i]->l ? nodes[i]->l->size : 0);
      auto [L, M, R] = ST.split3(S, n, n + 1);
      S = ST.merge3(L, nodes[pre(i)], R);
      fix_up(i, i);
      helper[pre(i)] = i;
    }
    if (t == vtype::LOWER) {
      auto [L, R] = ST.split_max_right(S, [&](int k) -> bool { return comp(k, point[i]); });
      int j = ST.get(R, 0);
      S = ST.merge(L, R);
      fix_up(i, j);
      helper[j] = i;
    }
  }
  G.build();
  vc<tuple<int, int, int>> ANS;
  FOR(f, 1, G.NF) {
    auto [vs, es] = G.get_face_data(f);
    POP(vs);
    vc<P> sub = rearrange(point, vs);
    for (auto& [a, b, c]: monotone_polygon_triangulation(sub)) ANS.eb(vs[a], vs[b], vs[c]);
  }
  return ANS;
}