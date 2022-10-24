#define PROBLEM "https://judge.yosupo.jp/problem/aplusb"
#include "my_template.hpp"
#include "other/io.hpp"

#include "ds/hashmap.hpp"
#include "random/hash_vector.hpp"
#include "mod/modint.hpp"
#include "connected_dp/squares.hpp"

using mint = modint107;

mint calc_tdpc_grid(int H, int W) {
  HashMapLL<int> MP;

  using P = pair<vc<int>, int>;
  vc<P> states;

  auto get_hash = [&](vc<int> a, int b) -> ll {
    a.eb(b);
    return hash_vector<int>(a);
  };

  vc<int> init(H, -1);
  init[0] = 0;
  states.eb(init, 0);
  vc<int> end(H, -1);
  end[H - 1] = H - 1;
  states.eb(end, H - 1);
  FOR(i, 2) {
    auto [a, b] = states[i];
    ll h = get_hash(a, b);
    MP[h] = i;
  }

  vc<pi> edges;

  int p = -1;
  while (1) {
    ++p;
    if (p >= len(states)) break;
    auto [now, r] = states[p];
    for (auto&& [nxt, convert]: connected_dp_squares::next_states(now)) {
      int s = convert[r];
      if (s == -1) continue;
      ll h = get_hash(nxt, s);
      if (!MP.count(h)) {
        MP[h] = len(states);
        states.eb(nxt, s);
      }
      edges.eb(p, MP[h]);
    }
  }

  int S = len(states);
  vc<mint> dp(S);
  dp[0] = mint(1);
  FOR(W + 1) {
    vc<mint> newdp(S);
    for (auto&& [a, b]: edges) newdp[b] += dp[a];
    swap(dp, newdp);
  }
  return dp[1];
}

void solve() {
  LL(H, W);
  mint ANS = calc_tdpc_grid(H, W);
  print(ANS);
}