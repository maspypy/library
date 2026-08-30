
#include "geo/base.hpp"

// 20260812, written by GPT-5.6 Sol
//
// A: CCW convex polygon, consecutive edges should not be collinear.
// Voronoi diagram of the edges of a convex polygon, restricted to its interior.
// Each Voronoi edge is represented by
//   center(t) = p1 + t (p2 - p1)
//   radius(t) = r1 + t (r2 - r1), 0 <= t <= 1.
// O(N log N) time.
// If a circle is tangent to 4 or more edges simultaneously,
// the combinatorial structure may be tie-broken arbitrarily by floating errors.
template <typename P, typename Re>
struct Convex_Polygon_Edge_Voronoi {
  using RP = Point<Re>;
  struct Edge {
    int i, j;
    RP p1, p2;
    Re r1, r2;
  };

  int N;
  vc<P> A;

  // polygon edge i:
  //   U[i].dot(x) <= H[i]
  // where U[i] is the id outward normal.
  vc<RP> U;
  vc<Re> H;

  vc<Edge> edges;
  vc<vc<int>> incident;

  Convex_Polygon_Edge_Voronoi(vc<P> A) : N(len(A)), A(A) { build(); }

  RP point(const Edge& e, Re t) const { return e.p1 + (e.p2 - e.p1) * t; }
  Re radius(const Edge& e, Re t) const { return e.r1 + (e.r2 - e.r1) * t; }
  pair<RP, RP> segment(const Edge& e) const { return {e.p1, e.p2}; }

  // Voronoi cell of polygon edge i.
  // Collinear points on the boundary may be removed.
  vc<RP> cell(int i) const {
    vc<RP> X;
    X.eb(RP(A[i]));
    X.eb(RP(A[(i + 1) % N]));

    for (int k : incident[i]) {
      X.eb(edges[k].p1);
      X.eb(edges[k].p2);
    }

    sort(all(X), [&](const RP& a, const RP& b) -> bool {
      if (a.x != b.x) return a.x < b.x;
      return a.y < b.y;
    });
    X.erase(unique(all(X),
                   [&](const RP& a, const RP& b) -> bool {
                     return a.x == b.x && a.y == b.y;
                   }),
            X.end());
    if (len(X) <= 2) return X;
    vc<RP> H;
    auto push = [&](RP p) -> void {
      while (len(H) >= 2) {
        RP a = H[len(H) - 2];
        RP b = H[len(H) - 1];
        if ((b - a).det(p - b) > 0) break;
        H.pop_back();
      }
      H.eb(p);
    };
    for (auto& p : X) push(p);
    int k = len(H);
    for (int i = len(X) - 2; i >= 0; --i) push(X[i]);
    H.pop_back();
    return H;
  }

 private:
  void add_edge(int i, int j, RP p1, Re r1, RP p2, Re r2) {
    // Except for tiny errors around simultaneous events,
    // radius is nondecreasing along a medial-axis branch.
    if (r1 > r2) {
      swap(p1, p2);
      swap(r1, r2);
    }

    int k = len(edges);
    edges.eb(Edge{i, j, p1, p2, r1, r2});
    incident[i].eb(k);
    incident[j].eb(k);
  }

  // For three consecutive active polygon edges a,b,c,
  // returns the center and radius where b disappears.
  pair<RP, Re> event(int a, int b, int c) const {
    RP p = U[a] - U[b];
    RP q = U[b] - U[c];
    Re s = H[a] - H[b];
    Re t = H[b] - H[c];
    Re det = p.det(q);
    assert(det != Re(0));
    RP x((s * q.y - p.y * t) / det, (p.x * t - s * q.x) / det);
    Re r = H[b] - U[b].dot(x);
    return {x, r};
  }

  void build() {
    assert(N >= 3);

    U.resize(N);
    H.resize(N);
    incident.resize(N);

    FOR(i, N) {
      int j = (i + 1) % N;
      Re dx = Re(A[j].x) - Re(A[i].x);
      Re dy = Re(A[j].y) - Re(A[i].y);
      Re d = sqrt(dx * dx + dy * dy);
      // A is CCW, so the right normal is outward.
      U[i] = RP(dy / d, -dx / d);
      H[i] = U[i].dot(RP(A[i]));
    }

    vc<int> nxt(N), pre(N);
    FOR(i, N) {
      nxt[i] = (i + 1) % N;
      pre[nxt[i]] = i;
    }

    vc<bool> alive(N, true);

    vc<RP> born_point(N);
    vc<Re> born_radius(N, Re(0));
    FOR(i, N) { born_point[i] = RP(A[(i + 1) % N]); }

    vc<Re> rm_time(N);
    vc<int> version(N, 0);

    pq_min<tuple<Re, int, int>> que;

    auto upd = [&](int b) -> void {
      if (!alive[b]) return;
      int a = pre[b];
      int c = nxt[b];
      auto [x, t] = event(a, b, c);
      rm_time[b] = t;
      ++version[b];
      que.emplace(t, b, version[b]);
    };

    FOR(i, N) upd(i);
    int n_alive = N;
    while (n_alive > 3) {
      Re t;
      int b, ver;
      while (1) {
        tie(t, b, ver) = que.top();
        que.pop();
        if (!alive[b]) continue;
        if (ver != version[b]) continue;
        break;
      }

      int a = pre[b], c = nxt[b];
      auto [x, r] = event(a, b, c);

      add_edge(a, b, born_point[a], born_radius[a], x, r);
      add_edge(b, c, born_point[b], born_radius[b], x, r);

      alive[b] = false;
      --n_alive;
      nxt[a] = c, pre[c] = a;

      born_point[a] = x;
      born_radius[a] = r;

      upd(a);
      upd(c);
    }

    // three active edges remain
    int a = -1;
    FOR(i, N) if (alive[i]) {
      a = i;
      break;
    }
    int b = nxt[a], c = nxt[b];
    assert(nxt[c] == a);

    auto [x, r] = event(a, b, c);
    add_edge(a, b, born_point[a], born_radius[a], x, r);
    add_edge(b, c, born_point[b], born_radius[b], x, r);
    add_edge(c, a, born_point[c], born_radius[c], x, r);
  }
};