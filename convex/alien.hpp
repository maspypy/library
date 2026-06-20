#pragma once

// T は整数型を仮定
// solve(penalty) -> {val, cnt}
// lo: cnt > K, hi: cnt <= K
// return: ans, pena
template <typename T, typename F>
pair<T, T> alien_trick(int N, int K, T lo, T hi, F solve) {
  while (lo + 1 < hi) {
    T mid = lo + (hi - lo) / 2;
    auto [val, cnt] = solve(mid);
    (cnt <= K ? hi : lo) = mid;
  }
  auto [val, cnt] = solve(hi);
  return {val - hi * K, hi};
}

template <typename T, typename F>
pair<T, T> alien_trick_auto_search_range(int N, int K, F solve) {
  T lo = 0, hi = 0;
  int c0 = solve(0).se;
  if (c0 <= K) {
    lo = -1, hi = 0;
    while (solve(lo).se < K) {
      T d = hi - lo;
      lo -= 2 * d, hi -= d;
    }
  } else {
    lo = 0, hi = 1;
    while (solve(hi).se > K) {
      T d = hi - lo;
      lo += d, hi += 2 * d;
    }
  }
  return alien_trick(N, K, lo, hi, solve);
}
