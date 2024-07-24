
template <typename T, typename F>
vi nth_element_from_sorted_matrix(ll N, ll M, ll K, F f, int k1 = 0, int k2 = 0,
                                  bool tr = false) {
  if (K == 0) return vi(N, 0);
  if (N > M) {
    vi A = nth_element_from_sorted_matrix<T>(M, N, K, f, k2, k1, !tr);
    vi B(N + 1);
    FOR(i, M) B[0] += 1, B[A[i]] -= 1;
    FOR(i, N) B[i + 1] += B[i];
    B.pop_back();
    return B;
  }
  vi A(N);
  if (K > N) {
    A = nth_element_from_sorted_matrix<T>(N, M / 2, (K - N) / 2, f, k1, k2 + 1,
                                          tr);
    for (auto& a: A) a *= 2;
    K = K - (K - N) / 2 * 2;
  }
  pqg<pair<T, int>> que;
  auto g = [&](ll i, ll j) -> T {
    i = ((i + 1) << k1) - 1;
    j = ((j + 1) << k2) - 1;
    return (tr ? f(j, i) : f(i, j));
  };
  FOR(i, N) if (A[i] < M) que.emplace(g(i, A[i]), i);
  while (K) {
    --K;
    auto [x, i] = POP(que);
    A[i]++;
    if (K && A[i] < M) que.emplace(g(i, A[i]), i);
  }
  return A;
}