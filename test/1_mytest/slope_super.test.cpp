#define PROBLEM "https://judge.yosupo.jp/problem/aplusb"
#include "my_template.hpp"

#include "random/shuffle.hpp"
#include "convex/slope_trick/slope_super.hpp"

void test(int N, bool from_zero, int add_prob) {
  Slope_Trick_Super<ll> ST(N);
  using F = typename decltype(ST)::FUNC;

  vc<int> L(2 * N - 1), R(2 * N - 1), A(N), B(N);
  vc<int> I(N);
  FOR(i, N) I[i] = i;

  FOR(i, N) {
    L[i] = RNG(0, 5);
    if (from_zero) L[i] = 0;
    R[i] = RNG(0, 5);
    if (L[i] > R[i]) swap(L[i], R[i]);
    A[i] = RNG(-3, 4);
    B[i] = RNG(-3, 4);
  }
  vvc<ll> dp(2 * N - 1);
  vc<F> func(2 * N - 1);
  FOR(i, N) {
    dp[i].resize(R[i] + 1, infty<ll>);
    FOR(x, L[i], R[i] + 1) dp[i][x] = A[i] * x + B[i];
    func[i] = ST.segment_func(L[i], R[i], A[i], B[i]);
    FOR(x, L[i], R[i] + 1) {
      ll me = ST.eval(func[i], x);
      ll god = dp[i][x];
      assert(me == god);
    }
  }

  FOR(i, N, 2 * N - 1) {
    shuffle(I);
    int t = (RNG(0, 100) < add_prob ? 0 : 1);
    int a = POP(I), b = POP(I);
    I.eb(i);
    if (dp[a].empty() || dp[b].empty()) continue;
    if (t == 0) {
      // ADD
      L[i] = max(L[a], L[b]);
      R[i] = min(R[a], R[b]);
      if (L[i] > R[i]) continue;
      dp[i].assign(R[i] + 1, infty<ll>);
      FOR(x, L[i], R[i] + 1) dp[i][x] = dp[a][x] + dp[b][x];
      func[i] = ST.add(func[a], func[b]);
    }
    if (t == 1) {
      // conv
      L[i] = L[a] + L[b];
      R[i] = R[a] + R[b];
      dp[i].assign(R[i] + 1, infty<ll>);
      FOR(x1, L[a], R[a] + 1) {
        FOR(x2, L[b], R[b] + 1) { chmin(dp[i][x1 + x2], dp[a][x1] + dp[b][x2]); }
      }
      func[i] = ST.convolve(func[a], func[b]);
    }
    vi X(R[i] + 1, infty<ll>);
    FOR(x, L[i], R[i] + 1) X[x] = ST.eval(func[i], x);
    assert(func[i].x0 == L[i]);
    assert(func[i].x1 == R[i]);
    assert(X == dp[i]);
    auto [fx, x] = ST.get_min(func[i]);
    assert(L[i] <= x && x <= R[i]);
    assert(MIN(X) == fx && X[x] == fx);
  }
  int i = 2 * N - 2;
  if (dp[i].empty()) return;
  int t = RNG(0, 2);
  if (t == 0) {
    // clear right
    FOR(x, L[i] + 1, R[i] + 1) chmin(dp[i][x], dp[i][x - 1]);
    ST.clear_right(func[i]);
  }
  if (t == 2) {
    // clear left
    FOR_R(x, L[i] + 1, R[i] + 1) chmin(dp[i][x - 1], dp[i][x]);
    ST.clear_left(func[i]);
  }
  vi X(R[i] + 1, infty<ll>);
  FOR(x, L[i], R[i] + 1) X[x] = ST.eval(func[i], x);
  assert(func[i].x0 == L[i]);
  assert(func[i].x1 == R[i]);
  assert(X == dp[i]);
}

void solve() {
  int x, y;
  cin >> x >> y;
  cout << x + y << "\n";
}

signed main() {
  vc<int> ns = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 1000};
  vc<int> ps = {50, 100, 0, 95, 5};
  for (auto& n: ns) {
    for (auto& p: ps) {
      FOR(20) {
        test(n, false, p);
        test(n, true, p);
      }
    }
  }

  solve();
  return 0;
}
