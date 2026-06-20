#pragma once

#include "convex/alien.hpp"
#include "convex/monge/monge_shortest_path.hpp"

// lo: penalty = lo では cnt > d
// hi: penalty = hi では cnt <= d
template <typename T, typename F>
T monge_shortest_path_d_edge(int N, int d, T lo, T hi, F f) {
  Monge_Shortest_Path<T> solver(N);
  auto solve = [&](T pena) -> pair<T, int> {
    return solver.solve([&](int l, int r) -> T { return f(l, r) + penalty; });
  };
  return alien_trick<T>(N, d, lo, hi, solve);
}

template <typename T, typename F>
T monge_shortest_path_d_edge_auto_search_range(int N, int d, T lo, T hi, F f) {
  Monge_Shortest_Path<T> solver(N);
  auto solve = [&](T pena) -> pair<T, int> {
    return solver.solve([&](int l, int r) -> T { return f(l, r) + penalty; });
  };

  return alien_trick_auto_search_range<T>(N, d, solve);
}
