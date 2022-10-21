#include "graph/base.hpp"

// vertex id の vector を返す
template <typename Graph>
vector<int> maximum_independent_set(Graph& G, int trial = 1000000) {
  using T = i128;
  assert(G.is_prepared());
  assert(!G.is_directed());
  int N = G.N;
  vector<T> bit(N);
  FOR(a, N) for (auto&& e: G[a]) bit[a] |= T(1) << e.to;
  vector<int> ord(N);
  iota(begin(ord), end(ord), 0);
  mt19937 mt(chrono::steady_clock::now().time_since_epoch().count());
  pair<int, T> best;
  for (int i = 0; i < trial; i++) {
    shuffle(begin(ord), end(ord), mt);
    T used = 0;
    int add = 0;
    for (int j: ord) {
      if (used & bit[j]) continue;
      used |= T(1) << j;
      ++add;
    }
    if (chmax(best.fi, add)) best.se = used;
  }
  vector<int> ans;
  for (int i = 0; i < N; i++) {
    if (best.se >> i & 1) ans.emplace_back(i);
  }
  return ans;
}

// vertex id の vector を返す
template <typename Graph, int MAX_V>
vector<int> _maximum_independent_set(Graph& G, int trial = 1000000) {
  using BS = bitset<MAX_V>;
  assert(G.is_prepared());
  assert(!G.is_directed());
  int N = G.N;
  vector<BS> bit(N);
  FOR(a, N) for (auto&& e: G[a]) bit[a][e.to] = 1;
  vector<int> ord(N);
  iota(begin(ord), end(ord), 0);
  mt19937 mt(chrono::steady_clock::now().time_since_epoch().count());
  pair<int, BS> best;
  for (int i = 0; i < trial; i++) {
    shuffle(begin(ord), end(ord), mt);
    BS used;
    int add = 0;
    for (int j: ord) {
      if ((used & bit[j]).any()) continue;
      used[j] = 1;
      ++add;
    }
    if (chmax(best.fi, add)) best.se = used;
  }
  vector<int> ans;
  for (int i = 0; i < N; i++) {
    if (best.se[i]) ans.emplace_back(i);
  }
  return ans;
}
