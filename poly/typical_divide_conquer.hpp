#include "poly/convolution.hpp"
#include "poly/middle_product.hpp"

// given polynomial L_i, R_i, f.
// For each i, calculate [x^n]f(x)L(x)R(x)
// L(x) = prod_{j<i}L_j(x)
// R(x) = prod_{i<j}R_j(x)
// set しなかった L_i, R_i には 1 が入る
template <typename mint>
struct Typical_Divide_Conquer {
  int N;
  using poly = vc<mint>;
  vc<poly> A;
  vc<poly> B;

  Typical_Divide_Conquer(int N) : N(N), A(N), B(N) {}

  void set_L(int i, poly f) {
    assert(0 <= i && i < N - 1);
    A[i] = f;
  }
  void set_R(int i, poly f) {
    assert(1 <= i && i < N);
    B[i] = f;
  }

  // [x^K]  prod_{i<=j}R_j(x) f(x) prod_{j<i}L_j(x)
  vc<mint> calc(int K, poly f) {
    if (N == 0) return {};
    f.resize(K + 1);
    // 準備
    vc<int> lch(N, -1), rch(N, -1);
    vc<int> deg(N);
    FOR(i, N) {
      if (A[i].empty()) A[i] = {1};
      if (B[i].empty()) B[i] = {1};
      deg[i] = max(len(A[i]) - 1, len(B[i]) - 1);
      A[i].resize(deg[i] + 1);
      B[i].resize(deg[i] + 1);
    }
    {
      auto dfs = [&](auto& dfs, int L, int R) -> int {
        if (R == L + 1) return L;
        int M = (L + R) / 2;
        int a = dfs(dfs, L, M), b = dfs(dfs, M, R);
        int v = len(lch);
        lch.eb(a), rch.eb(b);
        A.eb(convolution(A[a], A[b]));
        B.eb(convolution(B[a], B[b]));
        deg.eb(len(A.back()) - 1);
        return v;
      };
      dfs(dfs, 0, N);
    }
    int root = len(lch) - 1;
    int d = deg[root];
    if (K < d) {
      int add = d - K;
      vc<mint> g(len(f) + add);
      FOR(i, len(f)) g[add + i] = f[i];
      swap(f, g);
      K = d;
    }
    assert(len(f) == K + 1);
    if (K > d) {
      int rm = K - d;
      f = {f.begin() + rm, f.end()};
      K = d;
    }
    reverse(all(f));
    assert(len(f) == d + 1);
    vc<mint> ANS(N);
    {
      auto dfs = [&](auto& dfs, int k, poly& g) -> void {
        assert(len(g) - 1 == deg[k]);
        if (k < N) {
          ANS[k] = g[0];
          return;
        }
        poly g1 = middle_product(g, B[rch[k]]);
        poly g2 = middle_product(g, A[lch[k]]);
        dfs(dfs, lch[k], g1), dfs(dfs, rch[k], g2);
      };
      dfs(dfs, root, f);
    }
    return ANS;
  }
};