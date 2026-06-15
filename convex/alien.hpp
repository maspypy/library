#pragma once

// T は整数型を仮定
// solve(penalty, minimize_cnt) -> {dp, frm}
// lo: cnt > K, hi: cnt <= K
template <typename T, typename F>
T alien_trick(int N, int K, T lo, T hi, F solve) {
  while (lo + 1 < hi) {
    T mid = lo + (hi - lo) / 2;

    auto [dp, frm] = solve(mid, true);
    int cnt = 0, v = N;
    while (v) ++cnt, v = frm[v];

    if (cnt <= K) {
      hi = mid;
    } else {
      lo = mid;
    }
  }

  auto [dp, frm] = solve(hi, true);
  return dp[N] - hi * K;
}

// T は整数型を仮定
// solve(penalty, minimize_cnt) -> {dp, frm}
// lo: cnt > K, hi: cnt <= K
template <typename T, typename F, typename G>
pair<T, vc<int>> alien_trick_restore(int N, int K, type_identity_t<T> lo,
                                     type_identity_t<T> hi, F solve, G cost) {
  while (lo + 1 < hi) {
    T mid = lo + (hi - lo) / 2;
    auto [dp, frm] = solve(mid, true);
    int cnt = 0, v = N;
    while (v) ++cnt, v = frm[v];

    if (cnt <= K) {
      hi = mid;
    } else {
      lo = mid;
    }
  }

  auto [dp, frm1] = solve(hi, true);
  auto [dp2, frm2] = solve(hi, false);
  assert(dp2 == dp);
  vc<int> cnt_min(N + 1), cnt_max(N + 1);
  T ANS = dp[N] - hi * K;
  FOR(i, 1, N + 1) cnt_min[i] = cnt_min[frm1[i]] + 1;
  FOR(i, 1, N + 1) cnt_max[i] = cnt_max[frm2[i]] + 1;
  assert(cnt_min[N] <= K && K <= cnt_max[N]);
  vc<int> path;
  path.eb(N);
  int rest = K;
  int j = N;
  FOR_R(i, N) {
    if (dp[j] == dp[i] + cost(i, j) + hi && cnt_min[i] <= rest - 1 &&
        rest - 1 <= cnt_max[i]) {
      path.eb(i);
      --rest;
      j = i;
    }
  }
  assert(j == 0 && rest == 0);
  reverse(all(path));
  return {ANS, path};
}
