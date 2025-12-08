#include "ds/index_compression.hpp"
#include "ds/fenwicktree/fenwicktree.hpp"

// A, B：定数
// 座標は ll で係数は T
// Sparse Laurent Polynomial f(x,y) を与える
// [x^py^q] f(x,y)/(1-x)^A(1-y)^B をたくさん求める
// O(AB N logN) 時間
template <int A, int B, typename T, bool STATIC>
struct Coefficient_Query_2D {
  struct Mono {
    using value_type = array<T, A * B>;
    using X = value_type;
    static X op(X x, X y) {
      FOR(i, A * B) x[i] += y[i];
      return x;
    }
    static constexpr X unit() { return X{}; }
    static constexpr bool commute = 1;
  };
  vc<tuple<ll, ll, T, int>> query;

  int nsum = 0;
  Coefficient_Query_2D() {}
  void add_query(ll x, ll y, T c) {
    if (c != T(0)) query.eb(x, y, c, -1);
  }
  void sum_query(ll p, ll q) { query.eb(p, q, 0, nsum++); }

  // オーバーフローなどの状況次第で書き換える
  template <int n>
  void comb_array(ll x, array<T, n>& S) {
    static_assert(n < 4);
    if constexpr (n == 1) S = {T(1)};
    if constexpr (n == 2) S = {T(1), T(x)};
    if constexpr (n == 3) S = {T(1), T(x), T(x * (x - 1) / 2)};
  }
  template <int n>
  void coef_array(ll b, array<T, n>& S) {
    static_assert(n < 4);
    // [t^x]t^b(1-t)^{-n} を binom(x,k) の線形結合で表す係数
    if constexpr (n == 1) S = {T(1)};
    if constexpr (n == 2) S = {T(1 - b), T(1)};
    if constexpr (n == 3) S = {T((b - 1) * (b - 2) / 2), T(2 - b), T(1)};
  }

  vc<T> ANS;
  bool done = false;
  void calc_static(const vc<int>& ADD_I, vc<int>& GET_I) {
    if (ADD_I.empty() || GET_I.empty()) return;
    Index_Compression<ll, true, false> IY;
    {
      vc<ll> tmp;
      for (int q : ADD_I) {
        auto [a, b, w, qid] = query[q];
        if (qid == -1) tmp.eb(b);
      }
      IY.build(tmp);
    }

    FenwickTree<Mono> bit(len(IY));

    array<T, A> CX;
    array<T, B> CY;
    array<T, A * B> tmp;

    int ptr = 0;
    for (int q : GET_I) {
      auto [a, b, w, qid] = query[q];
      while (ptr < len(ADD_I) && (get<0>(query[ADD_I[ptr]])) <= a) {
        int q = ADD_I[ptr++];
        auto [a, b, w, qid] = query[q];
        coef_array<A>(a, CX);
        coef_array<B>(b, CY);
        FOR(i, A) FOR(j, B) tmp[B * i + j] = CX[i] * CY[j] * w;
        bit.add(IY(b), tmp);
      }
      comb_array<A>(a, CX);
      comb_array<B>(b, CY);
      // calc query
      tmp = bit.prod(IY(b + 1));
      T ans = 0;
      FOR(i, A) FOR(j, B) ans += tmp[B * i + j] * CX[i] * CY[j];
      ANS[qid] += ans;
    }
  }

  vc<T> calc() {
    assert(!done);
    done = 1;
    ANS.assign(nsum, 0);
    int Q = len(query);
    auto comp = [&](int i, int j) -> bool {
      return (get<0>(query[i])) < (get<0>(query[j]));
    };
    if (STATIC) {
      vc<int> ADD, GET;
      FOR(i, Q) { (get<3>(query[i]) == -1 ? ADD : GET).eb(i); }
      sort(all(ADD), comp);
      sort(all(GET), comp);
      calc_static(ADD, GET);
      return ANS;
    }
    auto dfs = [&](auto& dfs, int L, int R) -> pair<vc<int>, vc<int>> {
      vc<int> ADD, GET;
      if (R == L + 1) {
        (get<3>(query[L]) == -1 ? ADD : GET).eb(L);
        return {ADD, GET};
      }
      int M = (L + R) / 2;
      auto [ADD1, GET1] = dfs(dfs, L, M);
      auto [ADD2, GET2] = dfs(dfs, M, R);
      calc_static(ADD1, GET2);
      ADD.resize(len(ADD1) + len(ADD2));
      GET.resize(len(GET1) + len(GET2));
      merge(all(ADD1), all(ADD2), ADD.begin(), comp);
      merge(all(GET1), all(GET2), GET.begin(), comp);
      return {ADD, GET};
    };
    dfs(dfs, 0, Q);
    return ANS;
  }
};
