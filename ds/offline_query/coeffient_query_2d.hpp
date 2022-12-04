#include "ds/fenwicktree/fenwicktree.hpp"

// A, B：定数
// Sparse Laurent Polynomial f(x,y) を与える
// [x^py^q] f(x,y)/(1-x)^A(1-y)^B をたくさん求める
// O(AB N logN) 時間
template <int A, int B, typename T>
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

  vc<tuple<ll, ll, T>> F;
  vc<pi> QUERY;

  Coefficient_Query_2D() {}
  void add(ll x, ll y, T c) { F.eb(x, y, c); }
  void query(ll p, ll q) { QUERY.eb(p, q); }

  // 最後に (A-1)!(B-1)! で割るかどうか。ふつうは割る。
  vc<T> calc(bool div_fact = true) {
    // 加算する点の x について座圧
    sort(all(F),
         [&](auto& a, auto& b) -> bool { return get<0>(a) < get<0>(b); });
    vi keyX;
    keyX.reserve(len(F));
    for (auto&& [a, b, c]: F) {
      if (keyX.empty() || keyX.back() != a) keyX.eb(a);
      a = len(keyX) - 1;
    }
    keyX.shrink_to_fit();

    // y 昇順にクエリ処理する
    const int Q = len(QUERY);
    vc<int> I(Q);
    iota(all(I), 0);
    sort(all(I),
         [&](auto& a, auto& b) -> bool { return QUERY[a].se < QUERY[b].se; });
    sort(all(F),
         [&](auto& a, auto& b) -> bool { return get<1>(a) < get<1>(b); });

    FenwickTree<Mono> bit(len(keyX));

    vc<T> res(Q);
    int ptr = 0;
    for (auto&& qid: I) {
      auto [p, q] = QUERY[qid];
      // y <= q となる F の加算
      while (ptr < len(F) && get<1>(F[ptr]) <= q) {
        auto& [ia, b, w] = F[ptr++];
        ll a = keyX[ia];
        // w(p-a+1)...(p-a+A-1)(q-b+1)...(q-b+B-1) を p,q の多項式として
        vc<T> f(A), g(B);
        f[0] = w, g[0] = 1;
        FOR(i, A - 1) { FOR_R(j, i + 1) f[j + 1] += f[j] * T(-a + 1 + i); }
        FOR(i, B - 1) { FOR_R(j, i + 1) g[j + 1] += g[j] * T(-b + 1 + i); }
        reverse(all(f));
        reverse(all(g));
        array<T, A * B> G{};
        FOR(i, A) FOR(j, B) G[B * i + j] = f[i] * g[j];
        bit.add(ia, G);
      }
      auto SM = bit.sum(UB(keyX, p));
      T sm = 0;
      T pow_p = 1;
      FOR(i, A) {
        T prod = pow_p;
        FOR(j, B) {
          sm += prod * SM[B * i + j];
          prod *= T(q);
        }
        pow_p *= T(p);
      }
      res[qid] = sm;
    }
    if (div_fact) {
      T cf = T(1);
      FOR(a, 1, A) cf *= T(a);
      FOR(b, 1, B) cf *= T(b);
      for (auto&& x: res) x /= cf;
    }
    return res;
  }
};