/*
dp[i] := 第 i 項で終わる lis 長の最大値
となる dp テーブルを返す。O(Nlog N) 時間。
狭義・広義はテンプレートで指定。デフォルトは strong
*/
template <typename T, bool strong = true>
vc<int> longest_increasing_subsequence(vector<T> A) {
  ll N = A.size();

  T INF = numeric_limits<T>::max();
  vc<T> dp(N, INF);
  vc<int> lis_rank(N);
  FOR(i, N) {
    int j = (strong ? LB(dp, A[i]) : UB(dp, A[i]));
    dp[j] = A[i];
    lis_rank[i] = j + 1;
  }
  return lis_rank;
}
