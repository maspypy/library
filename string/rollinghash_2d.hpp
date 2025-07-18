#include "mod/modint61.hpp"
#include "random/base.hpp"

// https://codeforces.com/contest/958/problem/A2
struct RollingHash_2D {
  using M61 = modint61;
  const M61 b1, b2;
  vc<M61> pow1;
  vc<M61> pow2;

  RollingHash_2D()
      : b1(generate_base()), b2(generate_base()), pow1{M61(1)}, pow2{M61(1)} {}

  template <typename STRING> vvc<M61> build(const vc<STRING> &S) {
    int H = len(S);
    int W = len(S[0]);
    vv(M61, res, H + 1, W + 1);
    FOR(x, H) {
      FOR(y, W) { res[x + 1][y + 1] = res[x + 1][y] * b2 + M61(S[x][y] + 1); }
      FOR(y, W + 1) res[x + 1][y] += b1 * res[x][y];
    }
    expand(pow1, b1, H);
    expand(pow2, b2, W);
    return res;
  }

  M61 query(const vvc<M61> &A, int xl, int xr, int yl, int yr) {
    assert(0 <= xl && xl <= xr && xr <= len(A));
    assert(0 <= yl && yl <= yr && yr <= len(A[0]));
    M61 a = A[xr][yr] - A[xr][yl] * pow2[yr - yl];
    M61 b = A[xl][yr] - A[xl][yl] * pow2[yr - yl];
    return a - b * pow1[xr - xl];
  }

private:
  static inline u64 generate_base() { return RNG(M61::get_mod()); }

  void expand(vc<M61> &pow, const M61 &b, int n) {
    while (len(pow) <= n)
      pow.eb(pow.back() * b);
  }
};
