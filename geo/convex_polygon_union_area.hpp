#include "geo/base.hpp"

// それぞれが ccw order の strict convex polygon
// O(N^2logN)
// 6角形784個: 840ms
// https://ac.nowcoder.com/acm/contest/133876/K
template <typename Re>
Re convex_polygon_union_area(vvc<Point<ll>> dat) {
  using P = Point<ll>;
  /*
  線分の寄与に分解
  境界に現れるところを足す

  各辺について、他の多角形の内部にあるところを消すという感じ

  タイブレイクを慎重にやる
  同じ辺：小さい番号の辺を優先することにする
  */

  // strict ?
  for (auto &X : dat) {
    int n = len(X);
    if (n <= 2) continue;
    FOR(i, n) {
      P A = X[i], B = X[(i + 1) % n], C = X[(i + 2) % n];
      assert(ccw(A, B, C) == 1);
    }
  }

  ll N = len(dat);
  Re ANS = 0.0;
  FOR(i, N) {
    FOR(k, len(dat[i])) {
      P A = dat[i][k];
      P B = dat[i][(k + 1) % len(dat[i])];
      vc<pair<Re, Re>> ng;

      FOR(j, N) {
        if (j == i) continue;
        Re L = 0.0, R = 1.0;
        FOR(kk, len(dat[j])) {
          P C = dat[j][kk];
          P D = dat[j][(kk + 1) % len(dat[j])];

          P norm = (D - C).rot90(true);
          ll d = norm.dot(C);
          // left of CD: norm v > d

          if ((A - B).det(C - D) == 0) {
            // 平行です
            ll sgn = A.dot(norm) - d;
            if (sgn > 0) {
              continue;
            }
            elif (sgn == 0) {
              if ((B - A).dot(D - C) < 0) {
                // 逆向き
                continue;
              }
              // 同じ向き
              // 小さい番号からくる部分を消す
              if (j < i) {
                Re c = Re((C - A).dot(B - A)) / Re((B - A).dot(B - A));
                Re d = Re((D - A).dot(B - A)) / Re((B - A).dot(B - A));
                chmax(L, c), chmin(R, d);
                // [c,d)]
              } else {
                // 一切消さないようにする
                L = 1.0, R = 0.0;
              }
            }
            elif (sgn < 0) {
              // 内部にならない
              L = 1.0, R = 0.0;
              break;
            }
            else {
              assert(0);
            }
          } else {
            // 平行ではない
            // 0 以上になっている部分が切り取られる
            ll a = A.dot(norm) - d;
            ll b = B.dot(norm) - d;
            Re t = Re(0 - a) / Re(b - a);
            if (a < b) {
              chmax(L, t);
            }
            elif (a > b) { chmin(R, t); }
            else {
              assert(0);
            }
          }
        }
        if (L < R) ng.eb(L, R);
      }
      vc<pair<Re, int>> event;
      for (auto &[a, b] : ng) {
        if (a >= b) continue;
        event.eb(a, 1);
        event.eb(b, -1);
      }

      Re prv = 0.0;
      int cnt = 0;
      sort(all(event));
      Re ans = 0.0;
      for (auto &[x, t] : event) {
        Re dx = x - prv;
        prv = x;
        if (cnt == 0) ans += dx;
        cnt += t;
      }
      Re dx = 1.0 - prv;
      ans += dx;
      ll det = A.det(B);
      ANS += det * ans;
    }
  }
  ANS /= 2;
  return ANS;
}