#include "ds/my_bitset.hpp"
#include "enumerate/bits.hpp"

// O(N MAX(vals))
template <typename T>
vc<int> subset_sum_solution_1(vc<T>& vals, int target) {
  int n = len(vals);
  if (n == 0) return {};
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
    int new_size = len(dp) + v;
    newdp.resize(new_size);
    newdp.or_to_range(v, new_size, dp);
    if (len(newdp) > target + 1) newdp.resize(target + 1);
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

// O(sum^{1.5} / w)
// sum=10^6 で 150ms：https://codeforces.com/contest/755/problem/F
template <typename T>
vc<int> subset_sum_solution_3(vc<T>& vals, int target) {
  int SM = SUM<int>(vals);
  int N = len(vals);
  vvc<int> IDS(SM + 1);
  FOR(i, N) IDS[vals[i]].eb(i);
  vc<pair<int, int>> par(N, {-1, -1});
  vc<int> grp_vals;
  vc<int> raw_idx;
  FOR(x, 1, SM + 1) {
    auto& I = IDS[x];
    while (len(I) >= 3) {
      int a = POP(I), b = POP(I);
      int c = len(par);
      par.eb(a, b);
      IDS[2 * x].eb(c);
    }
    for (auto& i: I) {
      grp_vals.eb(x);
      raw_idx.eb(i);
    }
  }
  auto I = subset_sum_solution_2<int>(grp_vals, target);
  vc<int> ANS;
  for (auto& i: I) {
    vc<int> st = {raw_idx[i]};
    while (len(st)) {
      auto c = POP(st);
      if (c < N) {
        ANS.eb(c);
        continue;
      }
      auto [a, b] = par[c];
      st.eb(a), st.eb(b);
    }
  }
  return ANS;
}

template <typename T>
vc<int> subset_sum_solution_4(vc<T>& vals, T target) {
  if (target <= 0) return {};
  int N = len(vals);
  int M = N / 2;

  auto calc = [&](int L, int R) -> vc<T> {
    int n = R - L;
    vc<T> dp = {0};
    FOR(i, n) {
      T a = vals[L + i];
      vc<T> dp1(len(dp));
      FOR(k, len(dp)) dp1[k] = dp[k] + a;
      vc<T> newdp;
      merge(all(dp), all(dp1), back_inserter(newdp));
      swap(dp, newdp);
    }
    return dp;
  };

  auto restore = [&](int L, int R, T v) -> vc<int> {
    int n = R - L;
    vc<T> dp(1 << n);
    FOR(i, n) FOR(s, 1 << i) dp[s | 1 << i] = dp[s] + vals[L + i];
    FOR(s, 1 << n) {
      if (dp[s] == v) {
        vc<int> I;
        FOR(i, n) if (s >> i & 1) I.eb(L + i);
        return I;
      }
    }
    assert(0);
    return {};
  };

  auto dp1 = calc(0, M);
  auto dp2 = calc(M, N);
  int t = 0;
  FOR_R(s, len(dp1)) {
    while (t + 1 < len(dp2) && dp1[s] + dp2[t + 1] <= target) { ++t; }
    if (dp1[s] + dp2[t] == target) {
      vc<int> I1 = restore(0, M, dp1[s]);
      vc<int> I2 = restore(M, N, dp2[t]);
      I1.insert(I1.end(), all(I2));
      return I1;
    }
  }
  return {};
}

template <typename T>
vc<int> subset_sum(vc<T>& vals, T target) {
  if (target <= 0) return {};
  int n = len(vals);
  if (n == 0) return {};
  int mx = MAX(vals);

  // しきい値の調整をしていない
  // solution 1: O(N mx))
  // solution 2: O(N target / w)
  // solution 3: O(sum^1.5 / w)
  // solution 4: O(2^(N/2))
  double x1 = double(len(vals)) * mx;
  double x2 = double(len(vals)) * target / 500.0;
  double x3 = pow(SUM<double>(vals), 1.5) / 500.0;
  double x4 = pow(2.0, 0.5 * len(vals));
  double mi = min({x1, x2, x3, x4});
  if (x1 == mi) return subset_sum_solution_1(vals, target);
  if (x2 == mi) return subset_sum_solution_2(vals, target);
  if (x3 == mi) return subset_sum_solution_3(vals, target);
  return subset_sum_solution_4(vals, target);
}
