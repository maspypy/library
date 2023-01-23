#pragma once

// 列もクエリも static
template <typename INT_TYPE, int LOG>
struct Range_Xor_Basis_Query {
  int n;
  int Q;
  vc<INT_TYPE>& A;
  vvc<pair<int, int>> QUERY;

  Range_Xor_Basis_Query(vc<INT_TYPE>& A) : n(len(A)), Q(0), A(A) {
    QUERY.resize(n + 1);
  }

  // クエリ追加。
  void query(int L, int R) {
    assert(0 <= L && L <= R && R <= n);
    QUERY[R].eb(Q++, L);
  }

  // 関数 F(qid, basis) を渡す
  template <typename CALC>
  void calc(CALC F) {
    using P = pair<INT_TYPE, int>;
    array<P, LOG> d;
    FOR(k, LOG) d[k] = {INT_TYPE(1) << k, -1};
    vc<INT_TYPE> basis;
    FOR(i, n + 1) {
      for (auto&& [qid, L]: QUERY[i]) {
        basis.clear();
        FOR_R(k, LOG) if (d[k].se >= L) basis.eb(d[k].fi);
        F(qid, basis);
      }
      if (i == n) break;
      P p = {A[i], i};
      FOR_R(k, LOG) {
        if (!(p.fi >> k & 1)) continue;
        if (p.se > d[k].se) swap(p, d[k]);
        p.fi ^= d[k].fi;
      }
    }
  }
};