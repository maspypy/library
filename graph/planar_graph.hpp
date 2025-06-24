#include "graph/base.hpp"
#include "geo/base.hpp"
#include "geo/angle_sort.hpp"

/*
・連結平面グラフになっていないときにどう動作するかは何も考えていない
・N=1 も扱わない
・0番目に外面が入る
・次数 1 の点とかはあっても大丈夫っぽい？
*/
template <typename XY>
struct Planar_Graph {
  using P = Point<XY>;
  int NV, NE, NF;
  // 頂点, 辺からなるグラフ. 有向辺を 2 つ入れておく
  Graph<int, 1> G;
  // 頂点属性
  vc<P> point; // 座標
  // 辺属性
  vc<int> left_face; // 有向辺の左にある面の番号
  vc<int> nxt_edge;  // 面を反時計回りにまわるときの次の辺
  // 面属性
  vc<int> first_edge;

  Planar_Graph(int N, vc<P> point) : NV(N), G(N), point(point) { assert(N > 1); }

  void add(int a, int b) { G.add(a, b), G.add(b, a); }
  void build() {
    G.build();
    NE = G.M / 2;
    nxt_edge.assign(G.M, -1);
    left_face.assign(G.M, -1);
    int v0 = 0;
    int e0 = 0;
    FOR(v, NV) {
      if (point[v] < point[v0]) v0 = v;
      vc<int> eid;
      vc<P> dir;
      for (auto& e: G[v]) {
        eid.eb(e.id);
        dir.eb(point[e.to] - point[e.frm]);
      }
      auto I = angle_sort(dir);
      assert(len(I) > 0);
      FOR(k, len(I)) {
        int i = (k == 0 ? I.back() : I[k - 1]);
        int j = I[k];
        i = eid[i], j = eid[j];
        nxt_edge[j ^ 1] = i;
      }
      if (v == v0) e0 = eid[I[0]] ^ 1;
    }
    for (auto& x: nxt_edge) assert(x != -1);

    auto make_face = [&](int e) -> void {
      int p = len(first_edge);
      first_edge.eb(e);
      while (left_face[e] == -1) {
        left_face[e] = p;
        e = nxt_edge[e];
      }
    };

    make_face(e0);
    FOR(e, 2 * NE) {
      if (left_face[e] == -1) make_face(e);
    }
    NF = len(first_edge);
    assert(NV - NE + NF == 2);
  }

  // return {vs, es}
  // vs = [v0,v1,v2,v0], es = [e0,e1,e2]
  pair<vc<int>, vc<int>> get_face_data(int fid) {
    vc<int> eid = {first_edge[fid]};
    while (1) {
      int e = nxt_edge[eid.back()];
      if (e == first_edge[fid]) break;
      eid.eb(e);
    }
    vc<int> vid;
    for (auto& e: eid) vid.eb(G.edges[e].frm);
    vid.eb(vid[0]);
    return {vid, eid};
  }
};
