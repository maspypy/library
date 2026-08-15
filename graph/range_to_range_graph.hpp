#include "graph/base.hpp"

template <typename T>
struct Range_to_Range_Graph {
  int n;
  int n_node;
  vc<tuple<int, int, T>> edges;

  Range_to_Range_Graph(int n) : n(n), n_node(n * 3) {
    FOR3(i, 2, n + n) { edges.eb(to_upper_idx(i / 2), to_upper_idx(i), 0); }
    FOR3(i, 2, n + n) { edges.eb(to_lower_idx(i), to_lower_idx(i / 2), 0); }
  }

  inline int to_upper_idx(const int& i) {
    if (i >= n) return i - n;
    return n + i;
  }

  inline int to_lower_idx(const int& i) {
    if (i >= n) return i - n;
    return n + n + i;
  }

  void add(int frm, int to, T wt) { edges.eb(frm, to, wt); }

  void add_frm_range(int frm_l, int frm_r, int to, T wt) {
    int l = frm_l + n, r = frm_r + n;
    while (l < r) {
      if (l & 1) add(to_lower_idx(l++), to, wt);
      if (r & 1) add(to_lower_idx(--r), to, wt);
      l >>= 1, r >>= 1;
    }
  }

  void add_to_range(int frm, int to_l, int to_r, T wt) {
    int l = to_l + n, r = to_r + n;
    while (l < r) {
      if (l & 1) add(frm, to_upper_idx(l++), wt);
      if (r & 1) add(frm, to_upper_idx(--r), wt);
      l >>= 1, r >>= 1;
    }
  }

  void add_range_to_range(int frm_l, int frm_r, int to_l, int to_r, T wt) {
    int new_node = n_node++;
    add_frm_range(frm_l, frm_r, new_node, wt);
    add_to_range(new_node, to_l, to_r, T(0));
  }

  Graph<T, 1> build() {
    Graph<T, 1> G(n_node);
    for (auto&& [a, b, c] : edges) G.add(a, b, c);
    G.build();
    return G;
  }
};

// DST 方式
// template <typename T>
// struct Range_to_Range_Graph {
//   int n;
//   int n_node;
//   vc<tuple<int, int, T>> edges;
//   vc<tuple<int, int, int, T>> FRM, TO;
//   vc<int> A;

//   const int K = 16;

//   Range_to_Range_Graph(int n) : n(n), n_node(n), A(n) {}

//   void add(int frm, int to, T wt = 1) { edges.eb(frm, to, wt); }
//   void add_frm_range(int frm_l, int frm_r, int to, T wt = 1) {
//     assert(0 <= frm_l && frm_l <= frm_r && frm_r <= n);
//     if (frm_l == frm_r) return;
//     if (frm_r == frm_l + 1) return add(frm_l, to, wt);
//     FRM.eb(frm_l, frm_r, to, wt);
//   }

//   void add_to_range(int frm, int to_l, int to_r, T wt = 1) {
//     assert(0 <= to_l && to_l <= to_r && to_r <= n);
//     if (to_l == to_r) return;
//     if (to_r == to_l + 1) return add(frm, to_l, wt);
//     TO.eb(frm, to_l, to_r, wt);
//   }

//   // n_node, edges がいい感じになる
//   void build() {
//     int blk = ceil<int>(N, K);
//     vvc<int> SI(blk);
//     if (len(FRM)) {
//       vc<int> A(N), B(N);

//       FOR(i, len(FRM)) { auto [a, b, c, w] = FRM[i]; }
//       int Q = len(FRM);
//       vc<int> I(Q);
//       FOR(i, Q) I[i] = i;
//       rec_frm(0, n, I);
//       FRM.clear(), FRM.shrink_to_fit();
//     }

//     Q = len(TO);
//     I.resize(Q);
//     FOR(i, Q) I[i] = i;
//     rec_to(0, n, I);
//     TO.clear(), TO.shrink_to_fit();
//     // Graph<T, 1> G(n_node);
//     // for (auto& [a, b, w] : edges) G.add(a, b, w);
//     // G.build();
//     // return G;
//   }

//  private:
//   void rec_frm_small(int L, int R, vc<int>& I) {
//     if (I.empty()) return;
//     int M = (L + R) / 2;
//     vc<int> I1, I2, J;
//     int s = M, t = M;
//     for (int i : I) {
//       auto [a, b, c, w] = FRM[i];
//       if (b <= M) {
//         I1.eb(i);
//       }
//       elif (M <= a) { I2.eb(i); }
//       else {
//         chmin(s, a), chmax(t, b);
//         J.eb(i);
//       }
//     }
//     rec_frm_small(L, M, I1), rec_frm_small(M, R, I2);
//     if (J.empty()) return;
//     A[M - 1] = M - 1, A[M] = M;
//     FOR_R(i, s, M - 1) {
//       A[i] = n_node++;
//       add(i, A[i], 0), add(A[i + 1], A[i], 0);
//     }
//     FOR(i, M + 1, t) {
//       A[i] = n_node++;
//       add(i, A[i], 0), add(A[i - 1], A[i], 0);
//     }
//     for (int i : J) {
//       auto [a, b, c, w] = FRM[i];
//       add(A[a], c, w), add(A[b - 1], c, w);
//     }
//   }

//   void rec_to(int L, int R, vc<int>& I) {
//     if (I.empty()) return;
//     int M = (L + R) / 2;
//     vc<int> I1, I2, J;
//     int s = M, t = M;
//     for (int i : I) {
//       auto [c, a, b, w] = TO[i];
//       if (b <= M) {
//         I1.eb(i);
//       }
//       elif (M <= a) { I2.eb(i); }
//       else {
//         chmin(s, a), chmax(t, b);
//         J.eb(i);
//       }
//     }
//     rec_to(L, M, I1), rec_to(M, R, I2);
//     if (J.empty()) return;
//     A[M - 1] = M - 1, A[M] = M;
//     FOR_R(i, s, M - 1) {
//       A[i] = n_node++;
//       add(A[i], i, 0), add(A[i], A[i + 1], 0);
//     }
//     FOR(i, M + 1, t) {
//       A[i] = n_node++;
//       add(A[i], i, 0), add(A[i], A[i - 1], 0);
//     }
//     for (int i : J) {
//       auto [c, a, b, w] = TO[i];
//       add(c, A[a], w), add(c, A[b - 1], w);
//     }
//   }
// };