#include "graph/tree.hpp"
#include "ds/offline_query/mo.hpp"

// https://codeforces.com/contest/852/problem/I
// とりあえずパスの向きがないものとして作成
// 未対応：パスの向きあり / 辺データ
template <typename TREE, bool ORIENTED = false>
struct Mo_on_Tree {
  TREE& tree;
  vc<pair<int, int>> LR;

  Mo mo;
  Mo_on_Tree(TREE& tree) : tree(tree) {}
  void add(int u, int v) {
    if constexpr (!ORIENTED) {
      if (tree.LID[u] > tree.LID[v]) swap(u, v);
    }
    LR.eb(tree.ELID(u) + 1, tree.ELID(v) + 1);
  }

  // init(): root だけからなる path
  // add_l(v), add_r(v)：パスの先頭 / 末尾に v を追加
  // rm_l(v), rm_r(v)：パスの先頭 / 末尾から v を削除
  // query(qid)
  template <typename F1, typename F2, typename F3, typename F4, typename F5,
            typename F6>
  void calc_vertex(F1 init, F2 add_l, F3 add_r, F4 rm_l, F5 rm_r, F6 query) {
    const int N = tree.G.N;
    auto I = Mo::get_mo_order(LR);

    vc<int> FRM(2 * N), TO(2 * N), idx(2 * N);
    vc<int> cnt(N);
    deque<int> path = {0};
    FOR(v, N) {
      int a = tree.ELID(v), b = tree.ERID(v);
      FRM[a] = tree.parent[v], TO[a] = v;
      FRM[b] = v, TO[b] = tree.parent[v];
      idx[a] = idx[b] = v;
    }

    auto flip_left = [&](int i) -> void {
      const int a = FRM[i], b = TO[i], c = idx[i];
      if (cnt[c] == 0) {
        int v = path.front() ^ a ^ b;
        path.emplace_front(v), add_l(v);
      } else {
        int v = path.front();
        path.pop_front(), rm_l(v);
      }
      cnt[c] ^= 1;
    };
    auto flip_right = [&](int i) -> void {
      const int a = FRM[i], b = TO[i], c = idx[i];
      if (cnt[c] == 0) {
        int v = path.back() ^ a ^ b;
        path.emplace_back(v), add_r(v);
      } else {
        int v = path.back();
        path.pop_back(), rm_r(v);
      }
      cnt[c] ^= 1;
    };

    init();

    int l = 1, r = 1;
    for (auto idx: I) {
      int L = LR[idx].fi, R = LR[idx].se;
      while (l > L) { flip_left(--l); }
      while (r < R) { flip_right(r++); }
      while (l < L) { flip_left(l++); }
      while (r > R) { flip_right(--r); }
      query(idx);
    }
  }

  // init(): root だけからなる path
  // add_l(frm, to), add_r(frm, to)：パスの先頭 / 末尾に (frm,to) を追加
  // rm_l(frm, to), rm_r(frm, to)：パスの先頭 / 末尾に (frm,to) を追加
  // query(qid)
  template <typename F1, typename F2, typename F3, typename F4, typename F5,
            typename F6>
  void calc_edge(F1 init, F2 add_l, F3 add_r, F4 rm_l, F5 rm_r, F6 query) {
    const int N = tree.G.N;
    auto I = Mo::get_mo_order(LR);

    vc<int> FRM(2 * N), TO(2 * N), idx(2 * N);
    vc<int> cnt(N);
    deque<int> path = {0};
    FOR(v, N) {
      int a = tree.ELID(v), b = tree.ERID(v);
      FRM[a] = tree.parent[v], TO[a] = v;
      FRM[b] = v, TO[b] = tree.parent[v];
      idx[a] = idx[b] = v;
    }

    auto flip_left = [&](int i) -> void {
      const int a = FRM[i], b = TO[i], c = idx[i];
      if (cnt[c] == 0) {
        int v = path.front() ^ a ^ b;
        path.emplace_front(v), add_l(v, v ^ a ^ b);
      } else {
        int v = path.front();
        path.pop_front(), rm_l(v, v ^ a ^ b);
      }
      cnt[c] ^= 1;
    };
    auto flip_right = [&](int i) -> void {
      const int a = FRM[i], b = TO[i], c = idx[i];
      if (cnt[c] == 0) {
        int v = path.back() ^ a ^ b;
        path.emplace_back(v), add_r(v ^ a ^ b, v);
      } else {
        int v = path.back();
        path.pop_back(), rm_r(v ^ a ^ b, v);
      }
      cnt[c] ^= 1;
    };

    init();

    int l = 1, r = 1;
    for (auto idx: I) {
      int L = LR[idx].fi, R = LR[idx].se;
      while (l > L) { flip_left(--l); }
      while (r < R) { flip_right(r++); }
      while (l < L) { flip_left(l++); }
      while (r > R) { flip_right(--r); }
      query(idx);
    }
  }
};