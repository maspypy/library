// Source: https://github.com/maspypy/library/blob/main/convex/nth_element_from_sorted_lists.hpp

// 行の要素数が S[0], S[1], ..., S[N-1]
// MINIMIZE=true: 昇順ソートされていて小さい方からとる
// MINIMIZE=false: 降順されていて大きい方からとる
// O(N(logN+logK)) time
// query num: O(NlogK), あまり最適じゃないと思う
// 通ったがあやしいっぽい: https://codeforces.com/contest/1275/problem/F
// 列方向もソートされているなら matrix を使おう!!
// https://codeforces.com/problemset/problem/1034/D
template <typename T, bool MINIMIZE, typename F>
vi nth_element_from_sorted_lists(vi S, ll K, F f, int k = 0) {
  static_assert(is_same_v<T, int> || is_same_v<T, ll> || is_same_v<T, i128>);
  ll N = len(S);
  i128 sm = 0;
  for (auto& x : S) sm += x >> k;
  assert(0 <= K && K <= sm);
  if (K == 0) return vi(N, 0);
  if (K == sm) return S;

  ll row = 0;
  for (auto& x : S) row += (x >= (1LL << k));

  auto g = [&](int i, ll j) -> T {
    j = ((j + 1) << k) - 1;
    if (j >= S[i]) return infty<T>;
    T x = f(i, j);
    return (MINIMIZE ? x : -x);
  };
  vi A(N);
  if (K > row) {
    A = nth_element_from_sorted_lists<T, MINIMIZE>(S, (K - row) / 2, f, k + 1);
    for (auto& a : A) a *= 2;
    K = K - (K - row) / 2 * 2;
  }
  pq_min<pair<T, int>> que;
  FOR(i, N) que.emplace(g(i, A[i]), i);
  while (K) {
    --K;
    auto [x, i] = POP(que);
    A[i]++;
    if (K) que.emplace(g(i, A[i]), i);
  }
  return A;
}
