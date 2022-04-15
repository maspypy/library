#include "ds/fenwick.hpp"
#include "graph/hld.hpp"

template <typename HLD, typename AbelGroup, bool edge = false,
          bool path_query = true, bool subtree_query = false>
struct TreeAbelGroup {
  using X = typename AbelGroup::value_type;
  HLD &hld;
  int N;
  FenwickTree<AbelGroup> bit, bit_subtree;

  TreeAbelGroup(HLD &hld) : hld(hld), N(hld.N) {
    if (path_query) { bit = FenwickTree<AbelGroup>(2 * N); }
    if (subtree_query) { bit_subtree = FenwickTree<AbelGroup>(N); }
  }

  TreeAbelGroup(HLD &hld, vc<X> dat) : hld(hld), N(hld.N) {
    if (path_query) {
      vc<X> bit_raw(2 * N);
      if (!edge) {
        assert(len(dat) == N);
        FOR(v, N) {
          bit_raw[hld.ELID(v)] = dat[v];
          bit_raw[hld.ERID(v)] = AbelGroup::inverse(dat[v]);
        }
      } else {
        assert(len(dat) == N - 1);
        FOR(e, N - 1) {
          int v = hld.e_to_v(e);
          bit_raw[hld.ELID(v)] = dat[e];
          bit_raw[hld.ERID(v)] = AbelGroup::inverse(dat[e]);
        }
      }
      bit = FenwickTree<AbelGroup>(bit_raw);
    }
    if (subtree_query) {
      vc<X> bit_raw(N);
      if (!edge) {
        assert(len(dat) == N);
        FOR(v, N) bit_raw[hld.LID[v]] = dat[v];
      } else {
        assert(len(dat) == N - 1);
        FOR(e, N - 1) {
          int v = hld.e_to_v(e);
          bit_raw[hld.LID[v]] = dat[e];
        }
      }
      bit_subtree = FenwickTree<AbelGroup>(bit_raw);
    }
  }

  void add(int i, X x) {
    int v = (edge ? hld.e_to_v(i) : i);
    if (path_query) {
      X inv_x = AbelGroup::inverse(x);
      bit.add(hld.ELID(v), x);
      bit.add(hld.ERID(v), inv_x);
    }
    if (subtree_query) bit_subtree.add(hld.LID[v], x);
  }

  X sum_path(int frm, int to) {
    assert(path_query);
    int lca = hld.LCA(frm, to);
    // [frm, lca)
    X x1 = bit.sum(hld.ELID(lca) + 1, hld.ELID(frm) + 1);
    // edge なら (lca, to]、vertex なら [lca, to]
    X x2 = bit.sum(hld.ELID(lca) + edge, hld.ELID(to) + 1);
    return AbelGroup::op(x1, x2);
  }

  X prod_subtree(int u) {
    assert(subtree_query);
    int l = hld.LID[u], r = hld.RID[u];
    return bit_subtree.sum(l + edge, r);
  }

  void debug() {
    hld.debug();
    bit.debug();
    bit_subtree.debug();
  }

  void doc() {
    print("EulerTour + FenwickTree。");
    print("逆元を利用して、パスクエリを O(logN) 時間で行う。");
    print("部分木クエリ O(logN) 時間、パスクエリ O(logN) 時間。");
  }
};