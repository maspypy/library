#include "graph/shortest_path/bfs01.hpp"
#include "graph/shortest_path/restore_path.hpp"

template <typename T>
pair<T, vc<int>> tree_diameter(Graph<T>& G) {
  assert(G.is_prepared());
  int A, B;
  {
    auto [dist, par] = bfs01<decltype(G), T>(G, 0);
    A = max_element(all(dist)) - dist.begin();
  }
  auto [dist, par] = bfs01<decltype(G), T>(G, A);
  B = max_element(all(dist)) - dist.begin();
  vc<int> P = restore_path(par, B);
  return {dist[B], P};
}
