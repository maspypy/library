#pragma once

// basis[i]: i 番目に追加成功したもの. 別のラベルがあるなら外で管理する.
// rbasis: 上三角化された基底. [i][i]==1.
// way[i][j]: rbasis[i] = sum way[i][j] basis[j]
template <typename mint>
struct Basis {
  int n, rank;
  vvc<mint> basis;
  vvc<mint> rbasis;
  vvc<mint> way;
  Basis(int max_dim) : n(max_dim), rank(0), basis{} {
    rbasis.assign(max_dim, vc<mint>(max_dim));
    way.assign(max_dim, vc<mint>(max_dim));
  }

  // return : (sum==X にできるか, その方法)
  pair<bool, vc<mint>> solve(vc<mint> X) {
    vc<mint> CF(n);
    FOR(i, n) {
      if (rbasis[i][i] == mint(1)) {
        CF[i] = X[i];
        FOR(j, i, n) X[j] -= CF[i] * rbasis[i][j];
      }
    }
    for (auto& x: X) {
      if (x != mint(0)) { return {false, {}}; }
    }
    vc<mint> ANS(rank);
    FOR(i, n) { FOR(j, rank) ANS[j] += CF[i] * way[i][j]; }
    return {true, ANS};
  }

  // return : (sum==x にできるか, その方法). false の場合には追加する
  pair<bool, vc<mint>> solve_or_add(vc<mint> X) {
    vc<mint> Y = X;
    vc<mint> CF(n);
    FOR(i, n) {
      if (rbasis[i][i] == mint(1)) {
        CF[i] = X[i];
        FOR(j, i, n) X[j] -= CF[i] * rbasis[i][j];
      }
    }
    int p = [&]() -> int {
      FOR(i, n) if (X[i] != mint(0)) return i;
      return -1;
    }();
    if (p == -1) {
      vc<mint> ANS(rank);
      FOR(i, n) { FOR(j, rank) ANS[j] += CF[i] * way[i][j]; }
      return {true, ANS};
    }
    mint c = X[p].inverse();
    FOR(j, p, n) X[j] *= c;
    FOR(i, n) CF[i] *= c;
    basis.eb(Y), rbasis[p] = X;
    way[p][rank] = c;
    FOR(i, n) { FOR(j, rank) way[p][j] -= CF[i] * way[i][j]; }
    ++rank;
    return {false, {}};
  }

  // rank==r の時点まで戻す. Frobenius Form 用.
  void rollback(int r) {
    while (rank > r) {
      --rank;
      POP(basis);
      FOR(i, n) if (way[i][rank] != mint(0)) {
        fill(all(rbasis[i]), mint(0));
        fill(all(way[i]), mint(0));
      }
    }
  }
};
