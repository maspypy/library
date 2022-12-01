#pragma once

/*
列もクエリも static な場合。計算量 O((N+Q)LOG)
example
https://atcoder.jp/contests/abc223/tasks/abc223_h
https://codeforces.com/contest/1100/problem/F
*/
template <typename INT_TYPE, int LOG>
struct Range_Xor_Basis_Query {
  int n;
  vc<INT_TYPE>& A;
  vc<pair<int, int>> query;
  vc<vi> QIDS;

  Range_Xor_Basis_Query(vc<INT_TYPE>& A) : n(len(A)), A(A) {
    QIDS.resize(n + 1);
  }

  void add(int l, int r) {
    assert(0 <= l && l <= r && r <= n);
    QIDS[r].eb(len(query));
    query.eb(l, r);
  }

  // query_id, basis(vector) -> void という関数 F を渡す
  template <typename CALC>
  void calc(CALC F) {
    using P = pair<INT_TYPE, int>;
    int Q = len(query);
    FOR(q, Q) { QIDS[query[q].se].eb(q); }
    array<P, LOG> dat;
    FOR(k, LOG) dat[k] = {INT_TYPE(1) << k, -1};
    vc<INT_TYPE> basis;

    FOR(i, n + 1) {
      for (auto&& q: QIDS[i]) {
        auto& [l, r] = query[q];
        basis.clear();
        FOR_R(k, LOG) {
          if (dat[k].se >= l) basis.eb(dat[k].fi);
        }
        F(q, basis);
      }
      if (i == n) break;
      P p = {A[i], i};
      FOR_R(k, LOG) {
        if (p.fi >> k & 1) {
          if (p.se > dat[k].se) swap(p, dat[k]);
          p.fi ^= dat[k].fi;
        }
      }
    }
  }
};