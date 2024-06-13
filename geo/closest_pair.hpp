#include "geo/base.hpp"
#include "random/base.hpp"
#include "random/shuffle.hpp"
#include "ds/hashmap.hpp"
#include "random/hash_pair.hpp"

template <typename T>
pair<int, int> closest_pair(vc<Point<T>> points) {
  int N = len(points);
  assert(N >= 2);
  HashMap<int> MP(N);
  vc<int> I(N);
  iota(all(I), 0);
  shuffle(I);
  points = rearrange(points, I);

  auto calc = [&](int i, int j) -> T {
    return (points[j] - points[i]).dot(points[j] - points[i]);
  };

  T best = calc(0, 1);
  pair<int, int> res = {0, 1};
  T w = sqrtl(best);

  vc<int> nxt(N, -1);

  auto insert = [&](int i) -> void {
    u64 k = hash_pair<ll>({points[i].x / w, points[i].y / w});
    nxt[i] = MP.get(k, -1);
    MP[k] = i;
  };

  auto query = [&](int i) -> bool {
    ll a = points[i].x / w;
    ll b = points[i].y / w;
    bool upd = 0;
    FOR(dx, -1, 2) FOR(dy, -1, 2) {
      u64 k = hash_pair<ll>({a + dx, b + dy});
      int j = MP.get(k, -1);
      while (j != -1) {
        if (chmin(best, calc(i, j))) { upd = 1, res = {i, j}, w = sqrtl(best); }
        j = nxt[j];
      }
    }
    return upd;
  };

  if (best == T(0)) {
    res.fi = I[res.fi], res.se = I[res.se];
    return res;
  }

  insert(0), insert(1);
  FOR(i, 2, N) {
    if (query(i)) {
      if (best == T(0)) break;
      MP.build(N);
      FOR(j, i) insert(j);
    }
    insert(i);
  }
  res.fi = I[res.fi], res.se = I[res.se];
  return res;
}

pair<int, int> closest_pair_dc(vc<Point<ll>> point) {
  int N = len(point);
  assert(N >= 2);

  auto I = argsort(point);
  point = rearrange(point, I);

  ll best = -1;
  pair<int, int> best_pair = {-1, -1};

  auto upd = [&](int i, int j) -> void {
    Point<ll> p = point[i] - point[j];
    ll d = p.dot(p);
    if (best == -1 || best > d) { best = d, best_pair = {I[i], I[j]}; }
  };
  upd(0, 1);

  auto dfs = [&](auto &dfs, int L, int R) -> vc<int> {
    // return: [L,R) を y について sort したもの
    if (R == L + 1) return {L};
    int M = (L + R) / 2;
    vc<int> I0 = dfs(dfs, L, M);
    vc<int> I1 = dfs(dfs, M, R);
    vc<int> I;
    vc<int> near;
    int a = 0, b = 0;
    FOR(R - L) {
      int idx = [&]() -> int {
        if (a == len(I0)) return I1[b++];
        if (b == len(I1)) return I0[a++];
        int i = I0[a], j = I1[b];
        if (point[i].y < point[j].y) {
          ++a;
          return i;
        }
        ++b;
        return j;
      }();
      I.eb(idx);
      ll dx = point[M].x - point[idx].x;
      if (dx * dx > best) { continue; }
      FOR_R(k, len(near)) {
        int j = near[k];
        ll dy = point[idx].y - point[j].y;
        if (best == 0 || dy * dy > best) break;
        upd(idx, j);
      }
      near.eb(idx);
    }
    return I;
  };
  dfs(dfs, 0, N);
  return best_pair;
}
