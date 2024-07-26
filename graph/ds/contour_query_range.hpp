#include "graph/centroid_decomposition.hpp"

// 距離 0 は含めていないことに注意！
template <typename GT, bool WEIGHTED>
struct Contour_Query_Range {
  using WT = std::conditional_t<WEIGHTED, typename GT::cost_type, int>;
  int N;
  vc<int> V;
  vc<int> comp;
  vc<WT> dep;
  vc<int> info_idx, info_indptr;
  vc<int> comp_range;

  Contour_Query_Range(GT& G0) : N(G0.N) {
    int p = 0;
    comp_range = {0};
    auto f = [&](vc<int>& par, vc<int>& vs, vc<int>& color) -> void {
      const int n = len(par);
      vc<WT> dist(n);
      FOR(v, 1, n) {
        static_assert(!WEIGHTED);
        dist[v] = dist[par[v]] + 1;
      }
      FOR(c1, 2) {
        vc<int> A, B;
        FOR(v, n) {
          if (color[v] == c1) A.eb(v);
          if (color[v] > c1) B.eb(v);
        }
        if (A.empty() || B.empty()) continue;
        int mx_A = 0, mx_B = 0;
        for (auto& v: A) {
          V.eb(vs[v]), comp.eb(p), dep.eb(dist[v]), chmax(mx_A, dist[v]);
        }
        comp_range.eb(comp_range.back() + mx_A + 1), ++p;
        for (auto& v: B) {
          V.eb(vs[v]), comp.eb(p), dep.eb(dist[v]), chmax(mx_B, dist[v]);
        }
        comp_range.eb(comp_range.back() + mx_B + 1), ++p;
      }
    };
    centroid_decomposition<2>(G0, f);
    info_indptr.assign(N + 1, 0);
    for (auto& v: V) info_indptr[1 + v]++;
    FOR(v, N) { info_indptr[v + 1] += info_indptr[v]; }
    auto counter = info_indptr;
    info_idx.resize(info_indptr.back());
    FOR(i, len(V)) { info_idx[counter[V[i]]++] = i; }
  }

  int size() { return comp_range.back(); }

  vc<pair<int, int>> get_contour_range(int v, WT l, WT r) {
    vc<pair<int, int>> res;
    FOR(k, info_indptr[v], info_indptr[v + 1]) {
      int idx = info_idx[k];
      int p = comp[idx] ^ 1;
      int lo = l - dep[idx], hi = r - dep[idx];
      int L = comp_range[p], R = comp_range[p + 1];
      int n = R - L;
      chmax(lo, 0), chmin(hi, n);
      if (lo < hi) { res.eb(comp_range[p] + lo, comp_range[p] + hi); }
    }
    return res;
  }

  vc<int> get_indices(int v) {
    vc<int> res;
    FOR(k, info_indptr[v], info_indptr[v + 1]) {
      int idx = info_idx[k];
      int p = comp[idx];
      res.eb(comp_range[p] + dep[idx]);
    }
    return res;
  }
};