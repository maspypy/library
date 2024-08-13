#define PROBLEM "https://yukicoder.me/problems/no/1288"
#include "my_template.hpp"
#include "other/io.hpp"
#include "flow/mincostflow.hpp"

void solve() {
  LL(N);
  STR(S);
  VEC(ll, X, N);
  auto A = [&](int i) -> int { return i; };
  auto B = [&](int i) -> int { return N + 1 + i; };
  auto C = [&](int i) -> int { return 2 * (N + 1) + i; };
  auto D = [&](int i) -> int { return 3 * (N + 1) + i; };
  auto E = [&](int i) -> int { return 4 * (N + 1) + i; };
  Min_Cost_Flow<int, ll, true> G(5 * N + 5, A(0), E(N));
  FOR(i, N) G.add(A(i), A(i + 1), N, 0);
  FOR(i, N) G.add(B(i), B(i + 1), N, 0);
  FOR(i, N) G.add(C(i), C(i + 1), N, 0);
  FOR(i, N) G.add(D(i), D(i + 1), N, 0);
  FOR(i, N) G.add(E(i), E(i + 1), N, 0);
  FOR(i, N) {
    if (S[i] == 'y') G.add(A(i), B(i + 1), 1, -X[i]);
    if (S[i] == 'u') G.add(B(i), C(i + 1), 1, -X[i]);
    if (S[i] == 'k') G.add(C(i), D(i + 1), 1, -X[i]);
    if (S[i] == 'i') G.add(D(i), E(i + 1), 1, -X[i]);
  }
  ll ANS = 0;
  for (auto&& [x, y]: G.slope()) chmax(ANS, -y);
  print(ANS);
}

signed main() {
  solve();
  return 0;
}