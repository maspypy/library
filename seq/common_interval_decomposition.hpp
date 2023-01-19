#include "ds/segtree/lazy_segtree.hpp"
#include "alg/acted_monoid/min_add.hpp"

template <int NODES>
struct Common_Inverval_Decomposition {
  struct Node {
    vc<Node*> ch;
    bool inc, dec;
    int l, r, lo, hi;
  };

  Node* pool;
  Node* root;
  int pid;

  Common_Inverval_Decomposition(vc<int>& P) : pid(0) {
    pool = new Node[NODES];
    build(P);
  }

  Node* new_node(bool inc, bool dec, int l, int r, int lo, int hi) {
    pool[pid].inc = inc;
    pool[pid].dec = dec;
    pool[pid].l = l;
    pool[pid].r = r;
    pool[pid].lo = lo;
    pool[pid].hi = hi;
    return &(pool[pid++]);
  }

  void build(vc<int>& P) {
    int N = len(P);
    Lazy_SegTree<ActedMonoid_Min_Add<int>> seg(vc<int>(N, 0));

    vc<Node*> st;
    vc<int> mi = {-1}, ma = {-1};
    FOR(i, N) {
      while (mi.back() != -1 && P[i] < P[mi.back()]) {
        int j = POP(mi);
        seg.apply(mi.back() + 1, j + 1, P[j] - P[i]);
      }
      while (ma.back() != -1 && P[i] > P[ma.back()]) {
        int j = POP(ma);
        seg.apply(ma.back() + 1, j + 1, P[i] - P[j]);
      }
      mi.eb(i), ma.eb(i);

      Node* now = new_node(0, 0, i, i + 1, P[i], P[i] + 1);
      while (len(st)) {
        Node* n = st.back();
        if (n->hi == now->lo) {
          if (n->inc) {
            n->ch.eb(now);
            n->r = now->r;
            n->hi = now->hi;
            now = n;
            st.pop_back();
          } else {
            Node* p = new_node(1, 0, n->l, now->r, n->lo, now->hi);
            p->ch.eb(n);
            p->ch.eb(now);
            now = p;
            st.pop_back();
          }
          continue;
        }
        if (n->lo == now->hi) {
          if (n->dec) {
            n->ch.eb(now);
            n->r = now->r;
            n->lo = now->lo;
            now = n;
            st.pop_back();
          } else {
            Node* p = new_node(0, 1, n->l, now->r, now->lo, n->hi);
            p->ch.eb(n);
            p->ch.eb(now);
            now = p;
            st.pop_back();
          }
          continue;
        }
        // prime supernode creation
        if (seg.prod(0, now->l) != 0) break;
        Node* p = new_node(0, 0, now->l, now->r, now->lo, now->hi);
        p->ch.eb(now);
        now = p;
        while (1) {
          auto c = POP(st);
          now->l = c->l;
          chmin(now->lo, c->lo);
          chmax(now->hi, c->hi);
          now->ch.eb(c);
          if (now->r - now->l == now->hi - now->lo) break;
        }
        reverse(all(now->ch));
      }
      st.eb(now);
      seg.apply(0, i + 1, -1);
    }
    assert(len(st) == 1);
    root = POP(st);
    return;
  }

  void debug() {
    auto dfs = [&](auto& dfs, Node* n) -> void {
      print("l, r, lo, hi", n->l, n->r, n->lo, n->hi);
      for (auto&& c: n->ch) dfs(dfs, c);
    };
    dfs(dfs, root);
  };
};
