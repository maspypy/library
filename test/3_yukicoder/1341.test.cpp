#define PROBLEM "https://yukicoder.me/problems/no/1341"
#include "my_template.hpp"
#include "other/io.hpp"
#include "flow/mincostflow.hpp"

void solve() {
  LL(N, M);
  vi A(N), X(N), C(N);
  FOR(i, N) {
    LL(a, b, c);
    if (a > c) swap(a, c);
    A[i] = a, C[i] = c;
    X[i] = b;
  }
  sort(all(X));

  int source = 0;
  auto idx_ac = [&](int i) -> int { return 1 + i; };
  auto idx_a = [&](int i) -> int { return 1 + N + i; };
  auto idx_c = [&](int i) -> int { return 1 + N + N + i; };
  auto idx_x = [&](int i) -> int { return 1 + 3 * N + (N - 1 - i); };
  auto idx_y = [&](int i) -> int { return 1 + 4 * N + i; };
  auto idx_xy = [&](int i) -> int { return 1 + 5 * N + i; };
  int sink = 1 + 6 * N;
  Min_Cost_Flow<int, ll, true> G(sink + 1, source, sink);

  // x：a の下として使う
  // y：c の上として使う
  FOR(i, N) G.add(source, idx_ac(i), 1, 0);
  FOR(i, N) { G.add(idx_ac(i), idx_a(i), 1, -C[i]); }
  FOR(i, N) { G.add(idx_ac(i), idx_c(i), 1, 0); }
  FOR(i, N) { G.add(idx_x(i), idx_xy(i), 1, 0); }
  FOR(i, N) { G.add(idx_y(i), idx_xy(i), 1, -X[i]); }
  FOR(i, N) { G.add(idx_xy(i), sink, 1, 0); }
  FOR(i, N - 1) { G.add(idx_x(i + 1), idx_x(i), N, 0); }
  FOR(i, N - 1) { G.add(idx_y(i), idx_y(i + 1), N, 0); }

  FOR(i, N) {
    // A[i] 未満であるようなものの最大
    int k = LB(X, A[i]) - 1;
    if (k != -1) G.add(idx_a(i), idx_x(k), 1, 0);
  }
  FOR(i, N) {
    // C[i] より大であるようなものの最小
    int k = UB(X, C[i]);
    if (k != N) G.add(idx_c(i), idx_y(k), 1, 0);
  }

  auto [flow, cost] = G.flow();
  YES(flow == N);
  if (flow == N) {
    cost = -cost;
    print(cost >= M ? "KADOMATSU!" : "NO");
  }
}

signed main() {
  solve();
  return 0;
}