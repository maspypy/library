#include "geo/outcircle.hpp"
#include "ds/fastset.hpp"

// 座標の 4 乗がオーバーフローしない
// return : array<int,3>, triangles
// https://codeforces.com/contest/549/problem/E
template <typename T>
vc<array<int, 3>> delaunay_triangulation_of_convex_polygon(vc<Point<T>> A, bool farthest) {
  using P = Point<T>;
  int N = len(A);
  if (N <= 2) return {};

  FastSet FS(N);

  vc<int> I(N);
  FOR(i, N) I[i] = i;
  shuffle(I);

  sort(I.end() - 3, I.end());

  struct E {
    int a, b, nxt, rev;
  };

  int c = POP(I), b = POP(I), a = POP(I);
  vc<E> dat;
  dat.eb(a, b, 1, -1);
  dat.eb(b, c, 2, -1);
  dat.eb(c, a, 0, -1);
  vc<int> v_to_e(N, -1);
  v_to_e[a] = 0, v_to_e[b] = 1, v_to_e[c] = 2;
  FS.insert(a), FS.insert(b), FS.insert(c);

  auto dfs = [&](auto& dfs, int i) -> void {
    int j = dat[i].rev;
    if (j == -1) return;
    int i1 = dat[i].nxt;
    int i2 = dat[i1].nxt;
    int j1 = dat[j].nxt;
    int j2 = dat[j1].nxt;
    int b = dat[i].a, c = dat[i1].a, a = dat[i2].a, d = dat[j2].a;
    int side = outcircle_side(A[a], A[b], A[c], A[d]);
    bool flip = (farthest ? (side == -1) : (side == 1));
    if (!flip) return;
    dat[i] = {d, a, i2, j};
    dat[j] = {a, d, j2, i};
    dat[i1].nxt = j, dat[i2].nxt = j1, dat[j1].nxt = i, dat[j2].nxt = i1;
    dfs(dfs, i1), dfs(dfs, i2), dfs(dfs, j1), dfs(dfs, j2);
  };

  while (len(I)) {
    int v = POP(I);
    int l = FS.prev(v), r = FS.next(v);
    if (l == -1) l = FS.prev(N);
    if (r == N) r = FS.next(0);
    FS.insert(v);
    int k = v_to_e[l];
    int s = len(dat);
    v_to_e[l] = s + 1, v_to_e[v] = s + 2;
    dat[k].rev = s;
    dat.eb(r, l, s + 1, k);
    dat.eb(l, v, s + 2, -1);
    dat.eb(v, r, s, -1);
    dfs(dfs, k);
  }
  vc<array<int, 3>> ANS;
  FOR(i, len(dat)) {
    int j = dat[i].nxt;
    int k = dat[j].nxt;
    if (i > j || i > k) continue;
    ANS.eb(array<int, 3>{dat[i].a, dat[j].a, dat[k].a});
  }

  return ANS;
}
