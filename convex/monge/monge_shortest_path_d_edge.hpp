
#include "convex/alien_trick.hpp"
#include "convex/monge/monge_shortest_path.hpp"

// return: {ans, pena}
template <typename T, typename F>
pair<T, T> monge_shortest_path_d_edge(int N, int d, F f) {
  Monge_Shortest_Path<T> solver;

  auto solve = [&](T pena) -> pair<T, int> {
    T val = solver.solve(N, [&](int l, int r) -> T { return f(l, r) + pena; });
    return {val, solver.cnt[N]};
  };

  return alien_trick<T, true>(d, solve);
}