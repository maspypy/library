#include "mod/modint61.hpp"
#include "graph/base.hpp"
#include "graph/tree.hpp"
#include "random/base.hpp"
#include "graph/tree_dp/rerooting_dp.hpp"

template <typename TREE>
struct SubTree_Hash {
  using mint = modint61;
  TREE& tree;
  vc<ll> dp, dp_1, dp_2;

  SubTree_Hash(TREE& tree) : tree(tree) {
    int N = tree.N;
    using T = pair<int, mint>;
    T unit = {0, mint(1)};

    auto f_ee = [&](T A, T B) -> T { return {max(A.fi, B.fi), A.se * B.se}; };
    auto f_ev = [&](T A, int v) -> T { return {A.fi + 1, A.se}; };
    auto f_ve = [&](T A, const auto& e) -> T {
      return {A.fi, A.se + hash_base(A.fi)};
    };

    Rerooting_dp<decltype(tree), T> DP(tree, f_ee, f_ev, f_ve, unit);
    dp.resize(N), dp_1.resize(N), dp_2.resize(N);
    FOR(v, N) dp[v] = DP.dp[v].se.val;
    FOR(v, N) dp_1[v] = DP.dp_1[v].se.val;
    FOR(v, N) dp_2[v] = DP.dp_2[v].se.val;
  }

  // v を根としたときの full tree
  ll operator[](int v) { return dp[v]; }

  // root を根としたときの部分木 v
  ll get(int root, int v) {
    if (root == v) return dp[v];
    if (!tree.in_subtree(root, v)) { return dp_1[v]; }
    int w = tree.jump(v, root, 1);
    return dp_2[w];
  }

  static mint hash_base(int k) {
    static vc<mint> dat;
    while (len(dat) <= k) dat.eb(RNG(mint::get_mod()));
    return dat[k];
  }
};
