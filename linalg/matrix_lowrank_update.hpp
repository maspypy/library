#include "linalg/matrix_inv.hpp"
#include "linalg/matrix_rank.hpp"

// https://en.wikipedia.org/wiki/Woodbury_matrix_identity
template <typename T>
struct Lowrank_Update {
  int n;
  vvc<T> A, IA;
  Lowrank_Update() {}
  Lowrank_Update(vvc<T> A) : A(A) {
    n = len(A);
    T det;
    tie(det, IA) = matrix_inv(A);
    assert(det != T(0));
  }

  // A + UV が可逆なら足して true, そうでないなら何もせず false.
  bool update(vvc<T> &U, vvc<T> &V, bool update_A) {
    int r = len(V);
    assert(len(U) == n && len(U[0]) == r);
    assert(len(V) == r && len(V[0]) == n);
    vc<T> X(n), Y(n);
    FOR(k, r) {
      FOR(i, n) X[i] = U[i][k], Y[i] = V[k][i];
      rank_one_update(X, Y, update_A);
    }
  }

  // A + c U transepose(V) が可逆なら足して true, そうでないなら何もせず false.
  // O(n^2)
  bool rank_one_update(T c, vc<T> &U, vc<T> &V, bool update_A) {
    vc<int> I, J;
    FOR(i, n) if (U[i] != T(0)) I.eb(i);
    FOR(i, n) if (V[i] != T(0)) J.eb(i);
    T x = 0;
    for (auto &j: J) {
      for (auto &i: I) { x += V[j] * IA[j][i] * U[i]; }
    }
    x = T(1) + c * x;
    if (x == T(0)) return false;
    if (update_A) {
      for (auto &i: I) {
        T t = c * U[i];
        for (auto &j: J) { A[i][j] += t * V[j]; }
      }
    }
    x = c / x;
    vc<T> L(n), R(n);
    for (auto &i: I) {
      T u = U[i] * x;
      FOR(j, n) L[j] += IA[j][i] * u;
    }
    for (auto &j: J) { FOR(i, n) R[i] += V[j] * IA[j][i]; }
    FOR(i, n) FOR(j, n) IA[i][j] -= L[i] * R[j];
    return true;
  }
};

// lowrank update / rank query
template <typename mint>
struct Matrix_Rank_Lowrank_Update {
  int n;
  bool is_prepared;
  Lowrank_Update<mint> X;
  vc<pair<vc<mint>, vc<mint>>> dat;

  Matrix_Rank_Lowrank_Update(int n) : n(n) {
    vv(mint, A, n, n, mint(0));
    build(A, 0);
  }
  Matrix_Rank_Lowrank_Update(vvc<mint> &A) : n(len(A)) { build(A); }

  void build(vvc<mint> A, int r = -1) {
    if (r == -1) r = matrix_rank(A);
    FOR(n - r) {
      vc<mint> x(n), y(n);
      FOR(i, n) x[i] = RNG(0, mint::get_mod());
      FOR(i, n) y[i] = RNG(0, mint::get_mod());
      dat.eb(x, y);
      FOR(i, n) FOR(j, n) A[i][j] += x[i] * y[j];
    }
    X = Lowrank_Update(A);
    is_prepared = 1;
  }

  int rank() {
    while (!is_prepared && !dat.empty()) {
      auto [x, y] = dat.back();
      if (!X.rank_one_update(-1, x, y, false)) break;
      POP(dat);
    }
    is_prepared = 1;
    return n - len(dat);
  }

  void rank_one_update(mint c, vc<mint> &U, vc<mint> &V) {
    is_prepared = 0;
    while (!X.rank_one_update(c, U, V, false)) {
      vc<mint> x(n), y(n);
      FOR(i, n) x[i] = RNG(0, mint::get_mod());
      FOR(i, n) y[i] = RNG(0, mint::get_mod());
      dat.eb(x, y);
      X.rank_one_update(1, x, y, false);
    }
  }
};