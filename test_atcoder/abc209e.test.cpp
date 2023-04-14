#define PROBLEM "https://atcoder.jp/contests/abc209/tasks/abc209_e"

#include "my_template.hpp"
#include "other/io.hpp"
#include "game/graph_game.hpp"
#include "graph/base.hpp"

void solve() {
  LL(N);
  VEC(string, dat, N);
  vc<string> states;
  FOR(i, N) {
    string a = dat[i].substr(0, 3);
    string b = dat[i].substr(len(dat[i]) - 3, 3);
    states.eb(a);
    states.eb(b);
  }
  UNIQUE(states);

  Graph<bool, 1> G(len(states));
  FOR(i, N) {
    string a = dat[i].substr(0, 3);
    string b = dat[i].substr(len(dat[i]) - 3, 3);
    G.add(LB(states, a), LB(states, b));
  }
  G.build();

  auto out = [&](bool win, bool lose) -> void {
    if (win) return print("Aoki");
    if (lose) return print("Takahashi");
    return print("Draw");
  };

  Graph_Game X(G);
  FOR(i, N) {
    int v = G.edges[i].to;
    out(X.win[v], X.lose[v]);
  }
}

signed main() {
  int T = 1;
  // INT(T);
  FOR(T) solve();
  return 0;
}
