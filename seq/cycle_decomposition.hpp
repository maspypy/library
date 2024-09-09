#include "ds/splaytree/splaytree_basic.hpp"

// 順列のサイクル分解を管理
// https://atcoder.jp/contests/jag2017summer-day3/tasks/jag2017summer_day3_k
struct Cycle_Decomposition {
  int N, n_comp;
  SplayTree_Basic<int> ST;
  using np = decltype(ST)::np;
  vc<np> node;

  Cycle_Decomposition(int N) : N(N), n_comp(N), ST(N), node(N) { FOR(i, N) node[i] = ST.new_node(i); }

  // v が属する成分の番号, その成分の何番目か
  pair<int, int> get(int v) {
    ST.splay(node[v], true);
    np root = node[v];
    int idx = (root->l ? root->l->size : 0);
    ST.splay_kth(root, 0);
    return {root->x, idx};
  }

  int get_comp(int v) { return get(v).fi; }
  int size(int v) {
    ST.splay(node[v], true);
    return node[v]->size;
  }

  // 末尾に移動
  // [a,b,...,v,...] のときに [...,a,b,...,v] に変形
  void rotate(int v) {
    ST.splay(node[v], true);
    int ls = (node[v]->l ? node[v]->l->size : 0);
    auto [l, r] = ST.split(node[v], ls + 1);
    ST.merge(r, l);
  }

  void swap(int i, int j) {
    if (get_comp(i) != get_comp(j)) {
      --n_comp;
      rotate(i), rotate(j);
      ST.splay(node[i], true), ST.splay(node[j], true);
      ST.merge(node[i], node[j]);
    } else {
      ++n_comp;
      rotate(j);
      ST.splay(node[i], true);
      int k = (node[i]->l ? node[i]->l->size : 0) + 1;
      ST.split(node[i], k);
      ST.splay(node[i], true), ST.splay(node[j], true);
    }
  }
};