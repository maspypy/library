#include "flow/maxflow.hpp"

template <typename T, bool MINIMIZE>
struct Binary_Optimization {
  int n;
  int nxt;
  int source, sink;
  T base_cost;
  map<pair<int, int>, T> edges;

  Binary_Optimization(int n) : n(n), base_cost(0) {
    source = n;
    sink = n + 1;
    nxt = n + 2;
  }

  // xi を 0, 1 にするときにかかるコストを追加する。
  void add_1(int i, T x0, T x1) {
    assert(0 <= i && i < n);
    if (!MINIMIZE) { x0 = -x0, x1 = -x1; }
    _add_1(i, x0, x1);
  }

  // (xi,xj) = (00,01,10,11) とするときにかかるコストを追加する。
  // コストが劣モ x00 + x11 <= x10 + x10 になっている必要がある。
  // 特に、対角成分に利得を与えることができる。
  void add_2(int i, int j, T x00, T x01, T x10, T x11) {
    assert(i != j);
    assert(0 <= i && i < n);
    assert(0 <= j && j < n);
    if (!MINIMIZE) {
      x00 = -x00, x01 = -x01;
      x10 = -x10, x11 = -x11;
    }
    _add_2(i, j, x00, x01, x10, x11);
  }

  // (xi,xj,xk) = (000,001,010,011,100,101,110,111)
  // とするときにかかるコストを追加する。劣モになっている必要がある。
  // 特に、000 や 111 に利得を与えることができる。
  void add_3(int i, int j, int k, T x000, T x001, T x010, T x011, T x100,
             T x101, T x110, T x111) {
    assert(i != j && i != k && j != k);
    assert(0 <= i && i < n);
    assert(0 <= j && j < n);
    assert(0 <= k && k < n);
    if (!MINIMIZE) {
      x000 = -x000, x001 = -x001;
      x010 = -x010, x011 = -x011;
      x100 = -x100, x101 = -x101;
      x110 = -x110, x111 = -x111;
    }
    _add_3(i, j, k, x000, x001, x010, x011, x100, x101, x110, x111);
  }

  // 最小値および、01 列を返す
  pair<T, vc<int>> calc() {
    MaxFlowGraph<T> G(nxt);
    for (auto&& [key, cap]: edges) {
      auto [frm, to] = key;
      G.add(frm, to, cap);
    }

    auto [val, cut] = G.cut(source, sink);
    val += base_cost;
    chmin(val, INF<T>);
    cut.resize(n);
    if (!MINIMIZE) val = -val;
    return {val, cut};
  }

  void debug() {
    print("base_cost", base_cost);
    print("source=", source, "sink=", sink);
    for (auto&& [key, cap]: edges) print(key, cap);
  }

private:
  void add_edge(int i, int j, T t) {
    assert(t >= 0);
    if (t == 0) return;
    pair<int, int> key = mp(i, j);
    edges[key] += t;
    chmin(edges[key], INF<T>);
  }

  void _add_1(int i, T x0, T x1) {
    if (x0 <= x1) {
      base_cost += x0;
      add_edge(source, i, x1 - x0);
    } else {
      base_cost += x1;
      add_edge(i, sink, x0 - x1);
    }
  }

  void _add_2(int i, int j, T x00, T x01, T x10, T x11) {
    assert(x00 + x11 <= x01 + x10);
    _add_1(i, x00, x10);
    _add_1(j, 0, x11 - x10);
    add_edge(i, j, x01 + x10 - x00 - x11);
  }

  void _add_3(int i, int j, int k, T x000, T x001, T x010, T x011, T x100,
              T x101, T x110, T x111) {
    T p = x000 - x100 - x010 - x001 + x110 + x101 + x011 - x111;
    if (p > 0) {
      base_cost += x000;
      _add_1(i, 0, x100 - x000);
      _add_1(j, 0, x010 - x000);
      _add_1(k, 0, x001 - x000);
      _add_2(i, j, 0, 0, 0, x000 + x110 - x100 - x010);
      _add_2(i, k, 0, 0, 0, x000 + x101 - x100 - x001);
      _add_2(j, k, 0, 0, 0, x000 + x011 - x010 - x001);
      // あとは、111 のときに利得 p を追加する
      base_cost -= p;
      // 111 以外だとコスト p
      add_edge(i, nxt, p);
      add_edge(j, nxt, p);
      add_edge(k, nxt, p);
      add_edge(nxt, sink, p);
      ++nxt;
    } else {
      p = -p;
      base_cost += x111;
      _add_1(i, x011 - x111, 0);
      _add_1(i, x101 - x111, 0);
      _add_1(i, x110 - x111, 0);
      _add_2(i, j, x111 + x001 - x011 - x101, 0, 0, 0);
      _add_2(i, k, x111 + x010 - x011 - x110, 0, 0, 0);
      _add_2(j, k, x111 + x100 - x101 - x110, 0, 0, 0);
      // 000 のときに利得 p を追加する
      base_cost -= p;
      // 000 以外だとコスト p
      add_edge(nxt, i, p);
      add_edge(nxt, j, p);
      add_edge(nxt, k, p);
      add_edge(source, nxt, p);
      ++nxt;
    }
  }
};
