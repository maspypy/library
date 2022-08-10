/*
円環上の MCF。
cost[i]：i → i+1 のコスト
https://atcoder.jp/contests/dwango2015-prelims/tasks/dwango2015_prelims_4
*/
template <typename CAP, typename COST>
COST cyclic_bflow(vc<CAP> supply, vc<COST> cost) {
  const int N = len(supply);
  if (N == 0) return 0;
  assert(SUM(supply) == 0);
  auto f = [&](ll x) -> ll {
    // N-1 → 0 の移動が x
    ll res = abs(x) * cost.back();
    FOR(i, N - 1) {
      // 右に出る量は？
      x += supply[i];
      res += abs(x) * cost[i];
    }
    return res;
  };

  auto check = [&](ll x) -> bool { return f(x) <= f(x + 1); };
  ll LIM = 5;
  for (auto&& x: supply) LIM += max<ll>(x, 0);
  ll x = binary_search(check, LIM, -LIM);
  return f(x);
}
