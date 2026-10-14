#define PROBLEM "https://judge.yosupo.jp/problem/aplusb"
#include "my_template.hpp"

#include "random/shuffle.hpp"
#include "convex/slope_trick/slope_trick_super.hpp"

void test(int N, bool from_zero, int add_prob) {
  Slope_Trick_Super<ll> ST;
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
      F f = func[a], g = func[b];
      ST.restrict_domain(f, L[i], R[i]);
      ST.restrict_domain(g, L[i], R[i]);
      func[i] = ST.add(f, g);
    }
    if (t == 1) {
      // conv
      L[i] = L[a] + L[b];
      R[i] = R[a] + R[b];
      dp[i].assign(R[i] + 1, infty<ll>);
      FOR(x1, L[a], R[a] + 1) {
        FOR(x2, L[b], R[b] + 1) {
          chmin(dp[i][x1 + x2], dp[a][x1] + dp[b][x2]);
        }
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

void test_repeated_middle_insert() {
  // (x-0)+, (x-2)+ の間に (x-1)+ を繰り返し加える。
  // DFS で直接差し込む実装ではここで木が片寄る。
  constexpr int N = 20000;
  Slope_Trick_Super<ll> ST;
  auto f = ST.segment_func(-1LL, 4LL, 0LL, 0LL);
  ST.add_x_minus_a(f, 0);
  ST.add_x_minus_a(f, 2);
  FOR(N) ST.add_x_minus_a(f, 1);
  assert(f.size() == N + 2);
  assert(ST.eval(f, -1) == 0);
  assert(ST.eval(f, 0) == 0);
  assert(ST.eval(f, 1) == 1);
  assert(ST.eval(f, 2) == N + 2);
  assert(ST.eval(f, 4) == 3LL * N + 6);
}

void test_sum_all_duplicate_breakpoints() {
  constexpr int N = 1000;
  Slope_Trick_Super<ll> ST;
  using F = typename decltype(ST)::FUNC;
  vc<F> funcs;
  FOR(N) {
    auto f = ST.segment_func(-1LL, 4LL, 0LL, 0LL);
    ST.add_x_minus_a(f, 1);
    funcs.eb(f);
  }
  auto f = ST.sum_all(funcs);
  assert(f.size() == N);
  assert(ST.eval(f, -1) == 0);
  assert(ST.eval(f, 1) == 0);
  assert(ST.eval(f, 4) == 3LL * N);
}

void test_unite_cancellation_and_lazy_shift() {
  Slope_Trick_Super<ll> ST;
  vc<pair<ll, ll>> p = {{-1, 0}, {1, 0}, {4, 3}};
  vc<pair<ll, ll>> q = {{-1, 0}, {1, 0}, {4, -3}};
  auto f = ST.from_points(p);
  auto g = ST.from_points(q);
  f = ST.add(f, g);
  assert(f.size() == 2);
  FOR(x, -1, 5) assert(ST.eval(f, x) == 0);

  f = ST.segment_func(-1LL, 4LL, 0LL, 0LL);
  ST.add_x_minus_a(f, 0);
  ST.add_x_minus_a(f, 2);
  ST.shift(f, 5, 7);
  g = ST.segment_func(4LL, 9LL, 0LL, 0LL);
  ST.add_x_minus_a(g, 6);
  f = ST.add(f, g);
  assert(ST.eval(f, 4) == 7);
  assert(ST.eval(f, 5) == 7);
  assert(ST.eval(f, 6) == 8);
  assert(ST.eval(f, 7) == 10);
  assert(ST.eval(f, 9) == 16);
}

void test_sum_all_random() {
  Slope_Trick_Super<ll> ST;
  using F = typename decltype(ST)::FUNC;
  FOR(100) {
    constexpr int L = -3, R = 4;
    vc<F> funcs;
    vc<ll> want(R - L + 1);
    int N = RNG(1, 30);
    FOR(N) {
      ll a = RNG(-3, 4), b = RNG(-3, 4);
      auto f = ST.segment_func(L, R, a, b);
      FOR(x, L, R + 1) want[x - L] += a * x + b;
      int p = RNG(L + 1, R);
      if (RNG(0, 2)) {
        ST.add_x_minus_a(f, p);
        FOR(x, L, R + 1) want[x - L] += max(0LL, x - p);
      } else {
        ST.add_a_minus_x(f, p);
        FOR(x, L, R + 1) want[x - L] += max(0LL, p - x);
      }
      funcs.eb(f);
    }
    auto f = ST.sum_all(funcs);
    FOR(x, L, R + 1) assert(ST.eval(f, x) == want[x - L]);
    auto dat = ST.ST.get_all(f.root);
    FOR(i, len(dat) - 1) assert(dat[i].fi <= dat[i + 1].fi);
  }
}

signed main() {
  vc<int> ns = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 1000};
  vc<int> ps = {50, 100, 0, 95, 5};
  for (auto& n : ns) {
    for (auto& p : ps) {
      FOR(20) {
        test(n, false, p);
        test(n, true, p);
      }
    }
  }
  test_repeated_middle_insert();
  test_sum_all_duplicate_breakpoints();
  test_unite_cancellation_and_lazy_shift();
  test_sum_all_random();

  solve();
  return 0;
}
