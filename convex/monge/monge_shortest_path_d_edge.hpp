#pragma once

#include "convex/alien.hpp"
#include "convex/monge/monge_shortest_path.hpp"

// return: {ans, pena}
template <typename T, typename F>
pair<T, T> monge_shortest_path_d_edge(int N, int d, F f) {
  Monge_Shortest_Path<T> solver(N);
  auto solve = [&](T pena) -> pair<T, int> {
    return solver.solve([&](int l, int r) -> T { return f(l, r) + pena; });
  };
  return alien_trick<T>(d, solve);
}
