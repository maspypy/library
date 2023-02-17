#include "geo/base.hpp"
#include "random/base.hpp"
#include "random/shuffle.hpp"
#include "ds/hashmap.hpp"
#include "random/hash_pair.hpp"

template <typename T>
pair<int, int> closest_pair(vc<Point<T>> points) {
  static HashMap<int> MP;
  MP.reset();
  int N = len(points);
  assert(N >= 2);
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

  insert(0), insert(1);
  FOR(i, 2, N) {
    if (query(i)) {
      if (best == T(0)) break;
      MP.reset();
      FOR(j, i) insert(j);
    }
    insert(i);
  }
  res.fi = I[res.fi], res.se = I[res.se];
  return res;
}