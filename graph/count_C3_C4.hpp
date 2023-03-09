
// 各点に対して、その点を含む C3, C4 を数える
template <typename GT>
pair<vi, vi> count_C3_C4_pointwise(GT &G) {
  int N = G.N;
  auto deg = G.deg_array();
  auto I = argsort(deg);
  reverse(all(I));
  vc<int> rk(N);
  FOR(i, N) rk[I[i]] = i;

  // 遷移先を降順に並べる
  vvc<int> TO(N);
  for (auto &&e: G.edges) {
    int a = rk[e.frm], b = rk[e.to];
    TO[a].eb(b);
    TO[b].eb(a);
  }
  FOR(v, N) {
    sort(all(TO[v]));
    reverse(all(TO[v]));
  }

  vc<int> A(N);
  vi C3(N), C4(N);
  FOR(a, N) {
    for (auto &&b: TO[a]) TO[b].pop_back();
    for (auto &&b: TO[a]) {
      for (auto &&c: TO[b]) { C4[a] += A[c], C4[c] += A[c], A[c] += 1; }
    }
    for (auto &&b: TO[a]) {
      C3[a] += A[b], C3[b] += A[b] + A[b];
      for (auto &&c: TO[b]) { C4[b] += A[c] - 1; }
    }
    for (auto &&b: TO[a]) {
      for (auto &&c: TO[b]) { A[c] = 0; }
    }
  }
  for (auto &&x: C3) x /= 2;
  C3 = rearrange(C3, rk);
  C4 = rearrange(C4, rk);
  return {C3, C4};
}

// (2e5,5e5) で 500 ms
// https://codeforces.com/gym/104053/problem/K
template <typename GT>
pair<ll, ll> count_C3_C4(GT &G) {
  int N = G.N;
  ll x3 = 0, x4 = 0;
  auto deg = G.deg_array();
  auto I = argsort(deg);
  reverse(all(I));
  vc<int> rk(N);
  FOR(i, N) rk[I[i]] = i;

  // 遷移先を降順に並べる
  vvc<int> TO(N);
  for (auto &&e: G.edges) {
    int a = rk[e.frm], b = rk[e.to];
    TO[a].eb(b);
    TO[b].eb(a);
  }
  FOR(v, N) {
    sort(all(TO[v]));
    reverse(all(TO[v]));
  }

  vc<int> A(N);
  FOR(a, N) {
    for (auto &&b: TO[a]) TO[b].pop_back();
    for (auto &&b: TO[a]) {
      for (auto &&c: TO[b]) { x4 += A[c]++; }
    }
    for (auto &&b: TO[a]) { x3 += A[b]; }
    for (auto &&b: TO[a]) {
      for (auto &&c: TO[b]) { A[c] = 0; }
    }
  }
  x3 /= 2;
  return {x3, x4};
}
