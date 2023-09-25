#include "graph/base.hpp"
#include "ds/unionfind/unionfind.hpp"

template <typename GT, int NODES>
struct Directed_MST_Solver {
  using T = typename GT::cost_type;
  GT &G;

  Directed_MST_Solver(GT &G) : G(G), pid(0) {
    pool = new Node[NODES];
    assert(G.N + G.M <= NODES);
  }

  vc<int> calc(int root) {
    int N = G.N, M = G.M;
    vc<np> que(N);
    for (auto &e: G.edges) {
      que[e.to] = meld(que[e.to], new_node(e.frm, e.cost, e.id));
    }
    vc<char> used(N + M);
    used[root] = 2;
    vc<Edge> best_edge(N + M);
    vc<int> par(N + M, -1); // merge 過程の木
    vc<int> rt(N + M);
    FOR(i, N) rt[i] = i;
    UnionFind uf(N + M);
    int nxt = N;
    for (int s = 0; s < N; ++s) {
      if (used[s] != 0) continue;
      vc<int> path = {s};
      while (1) {
        int a = path.back();
        assert(used[a] == 0);
        used[a] = 1;
        if (!que[a]) { return {}; }
        best_edge[a] = pop(que[a]);
        int to = rt[uf[best_edge[a].to]];
        if (used[to] == 0) {
          path.eb(to);
          continue;
        }
        if (used[to] == 2) break;
        // cycle 発見
        int v = nxt++;
        que.eb(nullptr);
        while (1) {
          int w = POP(path);
          T sub = best_edge[w].cost;
          que[v] = meld(que[v], add(que[w], -sub));
          uf.merge(v, w), par[w] = v;
          used[w] = 2;
          if (w == to) break;
        }
        rt[uf[v]] = v;
        path.eb(v);
      }
      for (auto &v: path) used[v] = 2;
    }

    vc<int> res;
    vc<bool> done(nxt);
    done[root] = 1;
    FOR_R(v, nxt) {
      if (done[v]) continue;
      int id = best_edge[v].id;
      res.eb(id);
      int x = G.edges[id].to;
      while (x != -1 && !done[x]) { done[x] = 1, x = par[x]; }
    }
    return res;
  }

private:
  struct Edge {
    int to, id;
    T cost;
  };

  struct Node {
    Node *l, *r;
    Edge e;
    T lazy;
    int s;
  };

  Node *pool;
  using np = Node *;
  int pid;

  np new_node(int to, T cost, int id) {
    pool[pid].l = pool[pid].r = nullptr;
    pool[pid].s = 1;
    pool[pid].e = Edge{to, id, cost};
    pool[pid].lazy = 0;
    return &(pool[pid++]);
  }

  np add(np a, T x) {
    if (a) a->e.cost += x, a->lazy += x;
    return a;
  }

  np meld(np a, np b) {
    if (!a) return b;
    if (!b) return a;
    if ((a->e.cost) > (b->e.cost)) swap(a, b);
    b = add(b, -(a->lazy));
    a->r = (a->r ? meld(a->r, b) : b);
    if (!(a->l) || (a->l->s < a->r->s)) swap(a->l, a->r);
    a->s = (a->r ? a->r->s : 0) + 1;
    return a;
  }

  Edge pop(np &a) {
    Edge e = a->e;
    a = meld(add(a->l, a->lazy), add(a->r, a->lazy));
    return e;
  }
};

template <typename GT, int MAX_N>
pair<typename GT::cost_type, vc<int>> directed_mst(GT &G, int root) {
  Directed_MST_Solver<GT, 2 * MAX_N> D(G);
  using T = typename GT::cost_type;
  auto I = D.calc(root);
  T cost = 0;
  for (auto &i: I) cost += G.edges[i].cost;
  return {cost, I};
};
