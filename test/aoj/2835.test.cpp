#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2835"

#include "my_template.hpp"
#include "other/io.hpp"

#include "flow/maxflow.hpp"

void solve() {
  LL(N, M);
  using T = tuple<int, int, int>;
  VEC(T, dat, M);
  MaxFlow<int> G(N, 0, N - 1);
  FOR(i, M) {
    auto [a, b, c] = dat[i];
    G.add(a, b, c);
    G.add(b, a, c);
  }
  int ans = G.flow();
  int LIM = 10'000;
  if (ans > LIM + 1) return print(-1);

  FOR(i, M) {
    auto [a, b, c] = dat[i];
    if (c == 1) {
      G.change_capacity(2 * i + 0, 0);
      G.change_capacity(2 * i + 1, 0);
      chmin(ans, G.flow());
      G.change_capacity(2 * i + 0, 1);
      G.change_capacity(2 * i + 1, 1);
    }
  }
  if (ans > LIM) return print(-1);
  print(ans);
}

signed main() {
  solve();
  return 0;
}
