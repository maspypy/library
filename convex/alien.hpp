#pragma once

// MINIMIZE に応じて、base_score + add * cnt を最小化 / 最大化する
// solve(add) -> {val, cnt}
// val は add * cnt を含む最適値
// 最適解が複数ある場合、cnt はそのうちどれを返してもよい
//
// ある T 型の整数 add に対して、cnt = K の解が最適解に含まれること、
// および探索・solve 内のすべての計算がオーバーフローしないことを仮定する
template <typename T, bool MINIMIZE, typename F>
pair<T, T> alien_trick(int K, F solve) {
  static_assert(is_same_v<T, ll> || is_same_v<T, i128>);

  if constexpr (!MINIMIZE) {
    auto [val, slope] = alien_trick<T, true>(K, [&](T pena) -> pair<T, int> {
      auto [val, cnt] = solve(-pena);
      return {-val, cnt};
    });
    return {-val, -slope};
  }

  auto [val_0, cnt_0] = solve(T(0));
  if (cnt_0 == K) return {val_0, T(0)};

  T lo = 0, hi = 0;
  T val_lo = val_0, val_hi = val_0;
  int cnt_lo = cnt_0, cnt_hi = cnt_0;

  if (cnt_0 < K) {
    lo = T(-1);
    tie(val_lo, cnt_lo) = solve(lo);

    while (cnt_lo < K) {
      assert(lo < hi);
      T d = hi - lo;

      hi = lo;
      tie(val_hi, cnt_hi) = mp(val_lo, cnt_lo);

      lo -= T(2) * d;
      tie(val_lo, cnt_lo) = solve(lo);
    }
  } else {
    hi = T(1);
    tie(val_hi, cnt_hi) = solve(hi);

    while (cnt_hi > K) {
      T d = hi - lo;

      lo = hi;
      tie(val_lo, cnt_lo) = mp(val_hi, cnt_hi);

      hi += T(2) * d;
      tie(val_hi, cnt_hi) = solve(hi);
    }
  }

  assert(cnt_lo >= K && cnt_hi <= K);

  if (cnt_lo == K) return {val_lo - lo * T(K), lo};
  if (cnt_hi == K) return {val_hi - hi * T(K), hi};

  while (lo + T(1) < hi) {
    T mid = lo + (hi - lo) / T(2);
    auto [val, cnt] = solve(mid);

    if (cnt == K) return {val - mid * T(K), mid};

    if (cnt > K) {
      lo = mid;
      tie(val_lo, cnt_lo) = mp(val, cnt);
    } else {
      hi = mid;
      tie(val_hi, cnt_hi) = mp(val, cnt);
    }
  }

  T ans_lo = val_lo - lo * T(K);
  T ans_hi = val_hi - hi * T(K);

  if (ans_lo >= ans_hi) return {ans_lo, lo};
  return {ans_hi, hi};
}