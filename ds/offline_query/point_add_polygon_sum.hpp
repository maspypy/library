#include "ds/fenwicktree/fenwicktree.hpp"

/*
polygon は不等式 aix + biy >= ci により渡す。
polygon は凸で、不等式の列は、辺が反時計回りに回るようにする。
(ai, bi) はコンストラクタに渡す。
add_polygon で ci を渡す。
使用例：https://atcoder.jp/contests/pakencamp-2021-day3/tasks/pakencamp_2021_day3_f
*/
template <typename AbelGroup, bool SMALL>
struct Point_Add_Polygon_Sum {
  using G = typename AbelGroup::value_type;
  G total;
  vc<pi> AB;
  vi X, Y;
  vc<G> WT;
  vvc<ll> poly;

  Point_Add_Polygon_Sum(vc<pi> AB) : total(AbelGroup::unit()), AB(AB) {
    poly.resize(len(AB));
  }

  void add_query(ll x, ll y, G g) {
    X.eb(x);
    Y.eb(y);
    WT.eb(g);
    total = AbelGroup::op(total, g);
  }

  void sum_query(vi C) {
    assert(len(C) == len(AB));
    FOR(n, len(AB)) poly[n].eb(C[n]);
  }

  vc<G> calc() {
    int Q = len(poly[0]);
    int N = len(X);
    vc<G> res(Q, total);
    int K = len(AB);
    FOR(k, K) {
      auto [a, b] = AB[(k + K - 1) % K];
      auto [c, d] = AB[k];
      // ax+by>=ci かつ cx+dy<cj となる点の寄与を答から引く
      vi A(N), B(N);
      FOR(i, N) {
        A[i] = -(a * X[i] + b * Y[i]);
        B[i] = c * X[i] + d * Y[i];
      }
      vi C(Q), D(Q);
      FOR(q, Q) {
        C[q] = -(poly[(k + K - 1) % K][q]) + 1;
        D[q] = poly[k][q];
      }
      // A[i]<C[q] かつ B[i]<D[q] となる i の寄与を q から引く
      int NA = 0, NB = 0;
      if (!SMALL) {
        vi keyA = A, keyB = B;
        UNIQUE(keyA), UNIQUE(keyB);
        for (auto&& x: A) x = LB(keyA, x);
        for (auto&& x: B) x = LB(keyB, x);
        for (auto&& x: C) x = LB(keyA, x);
        for (auto&& x: D) x = LB(keyB, x);
        NA = len(keyA) + 1;
        NB = len(keyB) + 1;
      } else {
        ll minA = MIN(A);
        ll minB = MIN(B);
        for (auto&& x: A) x -= minA;
        for (auto&& x: B) x -= minB;
        for (auto&& x: C) x -= minA;
        for (auto&& x: D) x -= minB;
        NA = MAX(A) + 2;
        NB = MAX(B) + 2;
        for (auto&& x: C) x = clamp<ll>(x, 0, NA - 1);
        for (auto&& x: D) x = clamp<ll>(x, 0, NB - 1);
      }
      vvc<int> PID(NB + 1);
      vvc<int> QID(NB + 1);
      FOR(i, N) PID[B[i]].eb(i);
      FOR(q, Q) QID[D[q]].eb(q);

      FenwickTree<AbelGroup> bit(NA);
      FOR(b, NB) {
        for (auto&& q: QID[b]) {
          G x = bit.sum(C[q]);
          res[q] = AbelGroup::op(res[q], AbelGroup::inverse(x));
        }
        for (auto&& i: PID[b]) { bit.add(A[i], WT[i]); }
      }
    }
    return res;
  }
};