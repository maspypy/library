#define PROBLEM "https://atcoder.jp/contests/arc064/tasks/arc064_c"
#define ERROR 1e-9
#include "my_template.hpp"
#include "other/io.hpp"

#include "graph/base.hpp"
#include "graph/shortest_path/dijkstra.hpp"
#include "geo/base.hpp"

using Re = double;

using P = Point<Re>;

void solve() {
  vc<P> dat(2);
  read(dat[0]), read(dat[1]);
  vc<Re> rad(2);
  LL(N);
  FOR(N) {
    P p;
    Re r;
    read(p), read(r);
    dat.eb(p);
    rad.eb(r);
  }
  N += 2;
  Graph<Re, 0> G(N);
  FOR(j, N) FOR(i, j) {
    Re d = dist<Re, Re>(dat[i], dat[j]);
    d -= rad[i] + rad[j];
    chmax(d, 0);
    G.add(i, j, d);
  }
  G.build();
  auto [dist, par] = dijkstra<Re, decltype(G), true>(G, 0);
  print(dist[1]);
}

signed main() {
  solve();
  return 0;
}
