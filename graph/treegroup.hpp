#include "ds/segtree.hpp"
#include "graph/hld.hpp"
#include "alg/group_reverse.hpp"

// 作ってみたものの、HLD(log^2N)より遅いがち？
template <typename HLD, typename Group, bool edge = false,
          bool path_query = true, bool subtree_query = false>
struct TreeGroup {
  using RevGroup = Group_Reverse<Group>;
  using X = typename Group::value_type;
  HLD &hld;
  int N;
  SegTree<Group> seg, seg_subtree;
  SegTree<RevGroup> seg_r;

  TreeGroup(HLD &hld) : hld(hld), N(hld.N) {
    if (path_query) {
      seg = SegTree<Group>(2 * N);
      if (!Group::commute) seg_r = SegTree<RevGroup>(2 * N);
    }
    if (subtree_query) {
      assert(Group::commute);
      seg_subtree = SegTree<Group>(N);
    }
  }

  TreeGroup(HLD &hld, vc<X> dat) : hld(hld), N(hld.N) {
    if (path_query) {
      vc<X> seg_raw(2 * N);
      if (!edge) {
        assert(len(dat) == N);
        FOR(v, N) {
          seg_raw[hld.ELID(v)] = dat[v];
          seg_raw[hld.ERID(v)] = Group::inverse(dat[v]);
        }
      } else {
        assert(len(dat) == N - 1);
        FOR(e, N - 1) {
          int v = hld.e_to_v(e);
          seg_raw[hld.ELID(v)] = dat[e];
          seg_raw[hld.ERID(v)] = Group::inverse(dat[e]);
        }
      }
      seg = SegTree<Group>(seg_raw);
      if (!Group::commute) seg_r = SegTree<RevGroup>(seg_raw);
    }
    if (subtree_query) {
      assert(Group::commute);
      vc<X> seg_raw(N);
      if (!edge) {
        assert(len(dat) == N);
        FOR(v, N) seg_raw[hld.LID[v]] = dat[v];
      } else {
        assert(len(dat) == N - 1);
        FOR(e, N - 1) {
          int v = hld.e_to_v(e);
          seg_raw[hld.LID[v]] = dat[e];
        }
      }
      seg_subtree = SegTree<Group>(seg_raw);
    }
  }

  void set_path(int v, X x) {
    X inv_x = Group::inverse(x);
    seg.set(hld.ELID(v), x);
    seg.set(hld.ERID(v), inv_x);
    if (!Group::commute) {
      seg_r.set(hld.ELID(v), x);
      seg_r.set(hld.ERID(v), inv_x);
    }
  }

  void set_subtree(int v, X x) { seg_subtree.set(hld.LID[v], x); }

  void set(int i, X x) {
    int v = (edge ? hld.e_to_v(i) : i);
    if (path_query) set_path(v, x);
    if (subtree_query) set_subtree(v, x);
  }

  X prod_path(int frm, int to) {
    assert(path_query);
    int lca = hld.LCA(frm, to);
    // [frm, lca)
    X x1 = (Group::commute ? seg.prod(hld.ELID(lca) + 1, hld.ELID(frm) + 1)
                           : seg_r.prod(hld.ELID(lca) + 1, hld.ELID(frm) + 1));
    // edge なら (lca, to]、vertex なら [lca, to]
    X x2 = seg.prod(hld.ELID(lca) + edge, hld.ELID(to) + 1);
    return Group::op(x1, x2);
  }

  X prod_subtree(int u) {
    assert(subtree_query);
    int l = hld.LID[u], r = hld.RID[u];
    return seg_subtree.prod(l + edge, r);
  }

  void debug() {
    print("hld");
    hld.debug();
    print("seg");
    seg.debug();
    print("seg_r");
    seg_r.debug();
    print("seg_subtree");
    seg_subtree.debug();
  }

  void doc() {
    print("EulerTour + セグ木。");
    print("逆元を利用して、パスクエリを O(logN) 時間で行う。");
    print("部分木クエリ O(logN) 時間、パスクエリ O(logN) 時間。");
  }
};