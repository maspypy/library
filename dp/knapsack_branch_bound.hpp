// 分枝限定法。yukicoder 626
template <typename WT, typename VAL>
VAL knapsack_branch_bound(vc<WT> wt, vc<VAL> val, WT LIM) {
  int N = len(val);
  using Re = long double;
  vc<Re> sort_key(N);
  FOR(i, N) sort_key[i] = Re(val[i]) / wt[i];
  auto I = argsort(sort_key);
  reverse(all(I));
  wt = rearrange(wt, I);
  val = rearrange(val, I);

  VAL ANS = 0;
  auto dfs = [&](auto dfs, int nxt, WT now_wt, VAL now_val) -> void {
    if (now_wt > LIM) return;
    chmax(ANS, now_val);
    if (nxt == N) return;
    Re bd = now_val;
    Re rest = LIM - now_wt;
    FOR3(i, nxt, N) {
      if (rest >= wt[i]) {
        rest -= wt[i];
        bd += val[i];
        continue;
      }
      bd += rest / wt[i] * val[i];
      break;
    }
    if (bd <= ANS) return;
    dfs(dfs, nxt + 1, now_wt + wt[nxt], now_val + val[nxt]);
    dfs(dfs, nxt + 1, now_wt, now_val);
  };

  dfs(dfs, 0, 0, 0);
  return ANS;
}