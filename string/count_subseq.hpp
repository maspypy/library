// https://noshi91.hatenablog.com/entry/2023/02/26/135340
// 行列にするときは、(mp[x]+1) の列を持つと小さい行列になることがある.
// https://yukicoder.me/problems/no/2762
template <typename mint, typename STRING>
mint count_subseq(STRING& S) {
  map<int, mint> dp;
  mint sm = 1;
  for (auto&& x: S) {
    auto it = dp.find(x);
    if (it == dp.end()) {
      dp[x] = sm;
      sm += sm;
    } else {
      mint d = (*it).se;
      (*it).se = sm;
      sm += sm - d;
    }
  }
  return sm;
}