
#include "string/suffix_array.hpp"
#include "seq/cartesian_tree.hpp"
#include "graph/base.hpp"
#include "ds/fastset.hpp"

// https://twitter.com/maspy_stars/status/1565901414236205057?s=20&t=S2Tu6ayozHcakxai8dmh4g
// 各ノードは、suffix array での長方形領域と見なして、
// グラフおよび、領域データを作る。
// sample: test/my_test/suffix_tree.test.cpp
template <typename STRING, typename SUFFIX>
struct Suffix_Tree {
  STRING& S;
  SUFFIX& X;
  Suffix_Tree(STRING& S, SUFFIX& X) : S(S), X(X) {}

  pair<Graph<int, 1>, vc<tuple<int, int, int, int>>> build() {
    auto& SA = X.SA;
    auto& LCP = X.LCP;

    vc<tuple<int, int, int, int>> dat;
    vc<tuple<int, int, int>> edges;

    int N = len(SA);
    if (N == 1) {
      Graph<int, 1> G(2);
      G.add(0, 1);
      G.build();
      dat.eb(0, 1, 0, 1), dat.eb(0, 1, 1, 2);
      return {G, dat};
    }

    dat.eb(0, N, -1, 0);
    CartesianTree<int, true> CT(LCP);

    auto dfs = [&](auto& dfs, int p, int idx, int h) -> void {
      int L = CT.range[idx].fi;
      int R = CT.range[idx].se + 1;
      int hh = LCP[idx];
      if (h < hh) {
        edges.eb(p, len(dat), hh - h);
        p = len(dat);
        dat.eb(L, R, h, hh);
      }
      if (CT.lch[idx] == -1) {
        if (hh < N - SA[idx]) {
          edges.eb(p, len(dat), N - SA[idx] - hh);
          dat.eb(idx, idx + 1, hh, N - SA[idx]);
        }
      } else {
        dfs(dfs, p, CT.lch[idx], hh);
      }
      if (CT.rch[idx] == -1) {
        if (hh < N - SA[idx + 1]) {
          edges.eb(p, len(dat), N - SA[idx + 1] - hh);
          dat.eb(idx + 1, idx + 2, hh, N - SA[idx + 1]);
        }
      } else {
        dfs(dfs, p, CT.rch[idx], hh);
      }
    };
    int r = CT.root;
    if (LCP[r] > 0) {
      edges.eb(0, 1, LCP[r]);
      dat.eb(0, N, 0, LCP[r]);
      dfs(dfs, 1, r, LCP[r]);
    } else {
      dfs(dfs, 0, r, 0);
    }
    for (auto& [a, b, c, d]: dat) ++c, ++d;

    Graph<int, 1> G(len(dat));
    for (auto&& [a, b, c]: edges) G.add(a, b, c);
    G.build();
    return {G, dat};
  }

  // S[i:N) に対応するノード番号を返す
  // https://codeforces.com/problemset/problem/1098/F
  vc<int> get_suffix_positions(Graph<int, 1>& G, vc<tuple<int, int, int, int>>& dat) {
    int N = len(S);
    FastSet FS(N);
    FOR(i, N) FS.insert(i);
    vc<int> ANS(N);
    FOR_R(v, len(dat)) {
      auto [a, b, c, d] = dat[v];
      FS.enumerate(a, b, [&](int i) -> void {
        FS.erase(i);
        ANS[X.SA[i]] = v;
      });
    }
    return ANS;
  }

  // trie の要領ですすむ（failure link はない）
  // (node, length)
  // 行き過ぎ：(-1,0)
  pair<int, int> next(Graph<int, 1>& G, vc<tuple<int, int, int, int>>& dat, pair<int, int> p, int ch) {
    auto [node, length] = p;
    if (node == -1) return {-1, 0};
    auto [l, r, a, b] = dat[node];
    if (length + 1 < b) {
      int i = X.SA[l];
      // S[i:i+length]
      if (ch != S[i + length]) return {-1, 0};
      return {node, length + 1};
    }
    for (auto& e: G[node]) {
      int n = e.to;
      auto [l, r, a, b] = dat[n];
      assert(a == length + 1);
      int i = X.SA[l];
      // S[i:i+length]
      if (ch == S[i + length]) return {n, length + 1};
    }
    return {-1, 0};
  }
};
