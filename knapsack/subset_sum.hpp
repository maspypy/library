#include "ds/my_bitset.hpp"
#include "enumerate/bits.hpp"

// O(N MAX(vals))
template <typename T>
vc<int> subset_sum_solution_1(vc<T>& vals, int target) {
  int n = len(vals);
  int mx = MAX(vals);
  int b = 0, sb = 0;
  while (b < n && sb + vals[b] <= target) { sb += vals[b++]; }
  if (b == n && sb != target) return {};

  int off = target - mx + 1;
  vc<int> dp(2 * mx, -1);
  vv(int, PAR, n, 2 * mx, -1);
  dp[sb - off] = b;
  FOR3(i, b, n) {
    auto newdp = dp;
    auto& par = PAR[i];
    int a = vals[i];
    FOR(j, mx) {
      if (chmax(newdp[j + a], dp[j])) { par[j + a] = -2; }
    }
    FOR3_R(j, mx, 2 * mx) {
      FOR3_R(k, max(dp[j], 0), newdp[j]) {
        if (chmax(newdp[j - vals[k]], k)) par[j - vals[k]] = k;
      }
    }
    swap(dp, newdp);
  }
  if (dp[mx - 1] == -1) return {};
  vc<bool> use(n);
  int i = n - 1, j = mx - 1;
  while (i >= b) {
    int p = PAR[i][j];
    if (p == -2) {
      use[i] = !use[i];
      j -= vals[i--];
    }
    elif (p == -1) { --i; }
    else {
      use[p] = !use[p];
      j += vals[p];
    }
  }
  while (i >= 0) {
    use[i] = !use[i];
    --i;
  }
  vc<int> I;
  FOR(i, n) if (use[i]) I.eb(i);

  ll sm = 0;
  for (auto&& i: I) sm += vals[i];
  assert(sm == target);

  return I;
}

// O(N target / w)
template <typename T>
vc<int> subset_sum_solution_2(vc<T>& vals, int target) {
  int n = len(vals);
  auto I = argsort(vals);
  My_Bitset dp(1, 1);
  vc<int> last(target + 1, -1);
  FOR(k, n) {
    int v = vals[I[k]];
    if (v > target) continue;
    My_Bitset newdp = dp;
    int new_size = min<int>(len(dp) + v, target + 1);
    newdp.resize(new_size);
    dp.resize(new_size - v);
    newdp.or_to_range(v, new_size, dp);
    // update したところをメモ
    FOR(i, len(newdp.dat)) {
      u64 upd = (i < len(dp.dat) ? dp.dat[i] : u64(0)) ^ newdp.dat[i];
      enumerate_bits_64(upd, [&](int p) -> void { last[(i << 6) | p] = I[k]; });
    }
    swap(dp, newdp);
  }
  if (target >= len(dp) || !dp[target]) return {};
  vc<int> ANS;
  while (target > 0) {
    int i = last[target];
    ANS.eb(i);
    target -= vals[i];
  }
  return ANS;
}

template <typename T>
vc<int> subset_sum(vc<T>& vals, int target) {
  if (target <= 0) return {};
  int n = len(vals);
  if (n == 0) return {};
  int mx = MAX(vals);

  // しきい値の調整をしていない
  // solution 1: O(N mx))
  // solution 2: O(N target / w)
  return mx <= target / 500 ? subset_sum_solution_1(vals, target)
                            : subset_sum_solution_2(vals, target);
}
