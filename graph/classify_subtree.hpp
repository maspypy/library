#include "mod/modint61.hpp"
#include "graph/base.hpp"
#include "graph/tree.hpp"
#include "other/random.hpp"
#include "graph/tree_dp.hpp"

template <typename TREE>
vc<int> classify_subtree(TREE& tree) {
  int N = tree.G.N;
  RandomNumberGenerator RNG;
  using mint = modint61;
  using T = mint;
  T unit = mint(1);
  vc<mint> hash_base(N + 1);
  FOR(i, N + 1) hash_base[i] = RNG(mint::get_mod());

  auto f_ee = [&](T& A, T B) -> T { return A * B; };
  auto f_ev = [&](T& A, int v) -> T { return A; };
  auto f_ve = [&](T A, const auto& e) -> T {
    int k = tree.subtree_size(e.frm);
    return A + hash_base[k];
  };

  auto dp = tree_dp<decltype(tree), T>(tree, f_ee, f_ev, f_ve, unit);
  auto key = dp;
  UNIQUE(key);
  vc<int> ANS(N);
  FOR(i, N) ANS[i] = LB(key, dp[i]);
  return ANS;
}
