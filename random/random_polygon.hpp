
#include "random/base.hpp"
#include "geo/base.hpp"
#include "geo/convex_hull.hpp"
#include "geo/cross_point.hpp"
#include "geo/count_points_in_triangles.hpp"

vc<Point<ll>> random_polygon(int N, int XY_ABS_MAX = 10) {
  assert(N >= 3);
  using P = Point<ll>;
  auto trial = [&]() -> vc<P> {
    set<Point<ll>> S;
    while (len(S) < N) {
      int x = RNG(-XY_ABS_MAX, XY_ABS_MAX + 1);
      int y = RNG(-XY_ABS_MAX, XY_ABS_MAX + 1);
      S.insert(Point<ll>(x, y));
    }
    vc<P> point(all(S));
    auto I = ConvexHull<ll, true>(point);
    Count_Points_In_Triangles CT(point, point);
    vc<int> other;
    vc<int> done(N);
    for (auto& i: I) done[i]++;
    if (MAX(done) >= 2) return {};
    FOR(i, N) if (!done[i]) other.eb(i);
    int fail = 0;
    while (len(other)) {
      if (fail > 1000) return {};
      ++fail;
      int i = RNG(0, len(I)), j = RNG(0, len(other));
      swap(other[j], other.back());
      int a = I[i], b = I[(i + 1) % len(I)], c = other.back();
      if ((point[b] - point[a]).det(point[c] - point[a]) < 0) continue;
      if (CT.count3(a, b, c)) continue;
      if (CT.count2(a, c) + CT.count2(b, c)) continue;
      bool ok = 1;
      for (auto& v: {a, b}) {
        FOR(i, len(I)) {
          Segment<ll> S1(point[v], point[c]);
          Segment<ll> S2(point[I[i]], point[I[(i + 1) % len(I)]]);
          if (count_cross(S1, S2, false)) ok = 0;
        }
      }
      if (!ok) continue;
      fail = 0;
      I.insert(I.begin() + i + 1, POP(other));
    }
    point = rearrange(point, I);
    FOR(i, N) {
      if ((point[(i + 2) % N] - point[i]).det(point[(i + 1) % N] - point[i]) == 0) return {};
    }
    return point;
  };
  while (1) {
    vc<P> ANS = trial();
    if (ANS.empty()) continue;
    int k = RNG(0, len(ANS));
    rotate(ANS.begin(), ANS.begin() + k, ANS.end());
    return ANS;
  }
}