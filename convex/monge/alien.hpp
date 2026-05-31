// T は整数型を仮定
// solve(penalty, minimize_cnt)
// lo: cnt > K, hi: cnt<=K
template <typename T, typename F>
T alien_trick(int K, T lo, T hi, F solve) {
  while (lo + 1 < hi) {
    T mid = (lo + hi) / 2;
    auto [val, cnt] = solve(mid, true);
    if (cnt <= K) {
      hi = mid;
    } else {
      lo = mid;
    }
  }

  auto [val, cnt] = solve(hi, true);
  return val - hi * K;
}