
// 行の要素数が S[0], S[1], ..., S[N-1]
// O(N(logN+logK)) time
// query num: O(NlogK), あまり最適じゃないと思う
// 通ったがあやしいっぽい: https://codeforces.com/contest/1275/problem/F
// 列方向もソートされているなら matrix を使おう!!
// https://codeforces.com/problemset/problem/1034/D
template <typename T, typename F>
vi nth_element_from_sorted_lists(vi S, ll K, F f, int k = 0) {
  ll N = len(S);
  ll sm = 0;
  for (auto& x: S) sm += x >> k;
  assert(0 <= K && K <= sm);
  if (K == 0) return vi(N, 0);
  if (K == sm) return S;

  ll row = 0;
  for (auto& x: S) row += (x >= (1LL << k));

  auto g = [&](int i, ll j) -> T {
    j = ((j + 1) << k) - 1;
    return (j >= S[i] ? infty<T> : f(i, j));
  };
  vi A(N);
  if (K > row) {
    A = nth_element_from_sorted_lists<T>(S, (K - row) / 2, f, k + 1);
    for (auto& a: A) a *= 2;
    K = K - (K - row) / 2 * 2;
  }
  pqg<pair<T, int>> que;
  FOR(i, N) que.emplace(g(i, A[i]), i);
  while (K) {
    --K;
    auto [x, i] = POP(que);
    A[i]++;
    if (K) que.emplace(g(i, A[i]), i);
  }
  return A;
}
