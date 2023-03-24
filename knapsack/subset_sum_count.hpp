#pragma once

/*
O(2^{N/2})
subset sum 2^N 通りのうち、[lo, hi) に入るものの個数
*/
template <typename T = ll>
ll subset_sum_count(vc<T> A, T lo, T hi) {
  int n = len(A);
  auto gen = [&](vc<T> A) -> vc<T> {
    vc<T> dp = {0};
    for (auto&& a: A) {
      vc<T> dp1 = dp;
      for (auto&& t: dp1) t += a;
      vc<T> newdp;
      merge(all(dp), all(dp1), back_inserter(newdp));
      swap(dp, newdp);
    }
    return dp;
  };
  vc<T> AL = {A.begin(), A.begin() + n / 2};
  vc<T> AR = {A.begin() + n / 2, A.end()};
  auto dp1 = gen(AL);
  auto dp2 = gen(AR);
  auto f = [&](T lim) -> ll {
    int q = len(dp2);
    ll res = 0;
    FOR(p, len(dp1)) {
      while (q && dp1[p] + dp2[q - 1] >= lim) --q;
      res += q;
    }
    return res;
  };
  return f(hi) - f(lo);
}

/*
O(2^{N/2})
subset sum 2^N 通りのうち、[lo, hi) に入るものの個数。
を使う個数ごとに求める。
*/
template <typename T = ll>
vc<ll> subset_sum_count_by_size(vc<T> A, T lo, T hi) {
  int n = len(A);
  using P = pair<T, int>;
  auto gen = [&](vc<T> A) -> vc<vc<T>> {
    vc<P> dp;
    dp.eb(0, 0);
    for (auto&& a: A) {
      vc<P> dp1 = dp;
      for (auto&& t: dp1) t.fi += a, t.se += 1;
      vc<P> newdp;
      merge(all(dp), all(dp1), back_inserter(newdp));
      swap(dp, newdp);
    }
    vc<vc<T>> res(len(A) + 1);
    for (auto&& p: dp) res[p.se].eb(p.fi);
    return res;
  };
  vc<T> AL = {A.begin(), A.begin() + n / 2};
  vc<T> AR = {A.begin() + n / 2, A.end()};
  auto dp1 = gen(AL);
  auto dp2 = gen(AR);

  auto f = [&](T lim) -> vi {
    vi res(n + 1);
    FOR(s1, len(dp1)) FOR(s2, len(dp2)) {
      auto& X = dp1[s1];
      auto& Y = dp2[s2];
      int q = len(Y);
      ll& cnt = res[s1 + s2];
      for (auto&& x: X) {
        while (q && x + Y[q - 1] >= lim) --q;
        cnt += q;
      }
    }
    return res;
  };
  auto CNT1 = f(hi);
  auto CNT2 = f(lo);
  FOR(i, len(CNT1)) CNT1[i] -= CNT2[i];
  return CNT1;
}
