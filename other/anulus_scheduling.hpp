
// return: [1周以上するのにかかる回数, 始点].
// dist[i]: i から進める距離.
// 区間に単調性があるとする. i+dist[i]<=(i+1)+dist[i+1]
// https://codeforces.com/contest/526/problem/E
pair<int, int> anulus_scheduling(int N, vc<int> dist) {
  assert(len(dist) == N);
  FOR(i, N - 1) assert(dist[i] <= 1 + dist[i + 1]);
  assert(dist[N - 1] <= 1 + dist[0]);
  FOR(v, N) {
    assert(dist[v] > 0);
    if (dist[v] >= N) return {1, v};
  }
  vc<int> end(N);
  vc<int> cnt(N);
  FOR_R(i, N) {
    int j = i + dist[i];
    if (j >= N) {
      end[i] = j, cnt[i] = 1;
    } else {
      end[i] = end[j], cnt[i] = cnt[j] + 1;
      if (end[i] >= N + i) return {cnt[i], i};
    }
  }
  assert(0);
}