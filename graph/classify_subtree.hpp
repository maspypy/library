#include "mod/modint61.hpp"
#include "graph/base.hpp"
#include "graph/tree.hpp"
#include "other/random.hpp"
#include "graph/tree_dp.hpp"

template <typename TREE>
vc<ll> classify_subtree(TREE& tree) {
  using mint = modint61;
  static vc<mint> hash_base;
  auto get = [&](int k) -> mint {
    while (len(hash_base) <= k) hash_base.eb(RNG(mint::get_mod()));
    return hash_base[k];
  };
  int N = tree.G.N;
  using T = pair<int, mint>;
  T unit = {0, mint(1)};

  auto f_ee = [&](T A, T B) -> T { return {max(A.fi, B.fi), A.se * B.se}; };
  auto f_ev = [&](T A, int v) -> T { return {A.fi + 1, A.se}; };
  auto f_ve = [&](T A, const auto& e) -> T { return {A.fi, A.se + get(A.fi)}; };

  auto dp = tree_dp<decltype(tree), T>(tree, f_ee, f_ev, f_ve, unit);
  vc<ll> res(N);
  FOR(v, N) res[v] = dp[v].se.val;
  return res;
}
