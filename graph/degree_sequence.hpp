#include "ds/csr.hpp"

// O(N). 単純グラフの存在判定. Erdos-Gallai の定理.
bool check_degree_sequence(vc<int> deg) {
  int N = len(deg);
  if (N == 0) return true;
  ll sm = 0;
  vc<int> freq(N, 0);
  FOR(i, N) {
    int d = deg[i];
    if (!(0 <= d && d < N)) return false;
    freq[d]++, sm += d;
  }
  if (sm & 1) return false;
  int p = 0;
  FOR_R(x, N) FOR(freq[x]) deg[p++] = x;

  vi S = cumsum<ll>(deg);
  ll m = 0;  // # of d_i s.t. d_i>=k
  FOR_R(k, N + 1) {
    while (m < N && deg[m] >= k) ++m;
    ll lhs = S[k];
    ll rhs = k * (k - 1);
    if (m < k) {
      rhs += S[N] - S[k];
    } else {
      rhs += (m - k) * k;
      rhs += S[N] - S[m];
    }
    if (lhs > rhs) return false;
  }
  return true;
}

// O(N+M) time
// https://codeforces.com/contest/134/problem/C
pair<bool, vc<pair<int, int>>> construct_from_degree_sequence(vc<int> deg) {
  if (!check_degree_sequence(deg)) return {false, {}};
  int N = len(deg);
  CSR<int> csr(N);
  FOR(v, N) { csr.add(deg[v], v); }
  csr.build();
  vc<int> cnt(N), D(N), V(N);
  int p = 0;
  FOR(x, N) for (auto& v : csr[x]) cnt[x]++, D[p] = x, V[p] = v, ++p;
  assert(p == N);

  vc<pair<int, int>> ANS;
  vc<pair<int, int>> tmp;
  FOR_R(idx, N) {
    int v = V[idx], n = D[idx];
    cnt[D[idx]] -= 1, D[idx] = 0;
    int p = idx;  // [p,n) used
    while (n > 0) {
      int d = D[p - 1];
      int l = p - cnt[d];
      int m = min(n, cnt[d]);
      for (int i = l; i < l + m; ++i) {
        ANS.eb(V[i], v), D[i]--;
      }
      tmp.eb(d, m);
      n -= m, p = l;
    }
    for (auto& [d, m] : tmp) cnt[d] -= m, cnt[d - 1] += m;
    tmp.clear();
  }
  return {true, ANS};
}