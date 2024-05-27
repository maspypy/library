#define PROBLEM "https://atcoder.jp/contests/abc301/tasks/abc301_g"
#include "my_template.hpp"
#include "other/io.hpp"

#include "nt/rational.hpp"
#include "geo3d/base.hpp"
#include "geo3d/cross_point.hpp"

using Q = Rational<ll, false>;

using P = Point_3d<ll>;
using PQ = Point_3d<Q>;

void solve() {
  LL(N);
  vc<P> point(N);
  FOR(i, N) {
    LL(a, b, c);
    point[i] = {a, b, c};
  }

  sort(all(point), [&](auto& a, auto& b) -> bool { return a.x < b.x; });

  ll ANS = N;

  vv(ll, CNT, N, N);

  // 直線ひとつだけ
  FOR(i, N) FOR(j, i + 1, N) {
    if (point[i].x == point[j].x) continue;
    Line_3d<ll> L(point[i], point[j]);
    ll cnt = 0;
    FOR(k, N) cnt += L.contain(point[k]);
    CNT[i][j] = cnt;
    chmin(ANS, N - (cnt - 1));
  }

  vc<PQ> point_PQ(N);
  FOR(i, N) point_PQ[i] = {point[i].x, point[i].y, point[i].z};

  // 交点を利用する
  FOR(b, N) FOR(a, b) FOR(d, b) FOR(c, d) {
    Line_3d<ll> L1(point[a], point[b]);
    Line_3d<ll> L2(point[c], point[d]);
    ll n = count_cross(L1, L2);
    if (n != 1) continue;
    PQ p = cross_point<Q>(L1, L2);
    if (p.x >= Q(0)) continue;
    vc<int> OK(N, 1);
    FOR(i, N) {
      PQ a = point_PQ[i] - p;
      FOR(j, i) {
        PQ b = point_PQ[j] - p;
        b = b.cross(a);
        if (b.x == Q(0) && b.y == Q(0) && b.z == Q(0)) OK[i] = 0;
      }
    }
    chmin(ANS, SUM<int>(OK));
  }
  print(ANS);
}

signed main() {
  int T = 1;
  // INT(T);
  FOR(T) solve();
  return 0;
}
