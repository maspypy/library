/*
knapsack01 の全列挙
・O(2^n) で、(wt, val) を全列挙 + wt でソート
・remove extra = true → val が増加になるところだけ残す
*/
template <typename WT, typename VAL>
vc<pair<WT, VAL>> knapsack01_gen_all(vc<WT> weight, vc<VAL> val,
                                     bool remove_extra) {
  int n = len(weight);
  using P = pair<WT, VAL>;
  vc<P> dp;
  dp.eb(0, 0);
  FOR(i, n) {
    vc<P> tmp(len(dp));
    FOR(j, len(dp)) tmp[j] = {dp[j].fi + weight[i], dp[j].se + val[i]};
    vc<P> res;
    merge(all(dp), all(tmp), back_inserter(res));
    swap(dp, res);
  }
  if (!remove_extra) return dp;
  vc<P> res;
  res.reserve(len(dp));
  for (auto&& [w, v]: dp) {
    while (len(res) && res.back().fi == w) res.pop_back();
    if (len(res) && res.back().se >= v) continue;
    res.eb(w, v);
  }
  return res;
}

template <typename WT, typename VAL>
VAL knapsack01(vc<WT> weight, vc<VAL> val, WT LIM) {
  chmin(LIM, SUM<WT>(weight));
  int n = len(weight);
  assert(len(val) == n);

  // 半分全列挙 + 尺取り法
  // O(2^{N/2})
  auto sol_1 = [&]() -> VAL {
    vc<WT> wt_l = {weight.begin(), weight.begin() + n / 2};
    vc<WT> wt_r = {weight.begin() + n / 2, weight.end()};
    vc<VAL> val_l = {val.begin(), val.begin() + n / 2};
    vc<VAL> val_r = {val.begin() + n / 2, val.end()};
    auto dp1 = knapsack01_gen_all(wt_l, val_l, true);
    auto dp2 = knapsack01_gen_all(wt_r, val_r, true);
    int q = len(dp2);
    VAL ANS = 0;
    FOR(p, len(dp1)) {
      while (q && (dp1[p].fi + dp2[q - 1].fi > LIM)) --q;
      if (q == 0) break;
      chmax(ANS, dp1[p].se + dp2[q - 1].se);
    }
    return ANS;
  };

  // wt ごとの dp
  // O(N LIM)
  auto sol_2 = [&]() -> VAL {
    vc<VAL> dp(LIM + 1);
    ll total = 0;
    FOR(k, n) {
      ll mx = min<ll>(LIM - weight[k], total);
      FOR_R(i, mx + 1) chmax(dp[i + weight[k]], dp[i] + val[k]);
      total += weight[k];
    };
    return MAX(dp);
  };

  // val ごとの dp
  // O(N sum val)
  auto sol_3 = [&]() -> VAL {
    // val -> min wt
    vc<WT> dp(SUM<VAL>(val) + 1, LIM + 1);
    dp[0] = 0;
    ll total = 0;
    FOR(k, n) {
      FOR_R(i, total + 1) { chmin(dp[i + val[k]], dp[i] + weight[k]); }
      total += val[k];
    }
    VAL ANS = 0;
    FOR(i, total + 1) if (dp[i] <= LIM) ANS = i;
    return ANS;
  };

  double t1 = log(2) * n * 0.5;
  double t2 = log((n + 1) * (LIM + 1));
  double t3 = log((n + 1) * (SUM<WT>(val) + 1));
  double t = min({t1, t2, t3});
  if (t == t1) return sol_1();
  if (t == t2) return sol_2();
  return sol_3();
}
