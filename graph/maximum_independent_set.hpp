#include "graph/base.hpp"

// vertex id の vector を返す
template <typename Graph>
vector<int> maximum_independent_set(Graph& G, int trial = 1000000) {
  assert(G.is_prepared());
  assert(!G.is_directed());
  int N = G.N;
  vector<uint64_t> bit(N);
  assert(N <= 64);
  FOR(a, N) for (auto&& e: G[a]) bit[a] |= uint64_t(1) << e.to;
  vector<int> ord(N);
  iota(begin(ord), end(ord), 0);
  mt19937 mt(chrono::steady_clock::now().time_since_epoch().count());
  int ret = 0;
  uint64_t ver;
  for (int i = 0; i < trial; i++) {
    shuffle(begin(ord), end(ord), mt);
    uint64_t used = 0;
    int add = 0;
    for (int j: ord) {
      if (used & bit[j]) continue;
      used |= uint64_t(1) << j;
      ++add;
    }
    if (ret < add) {
      ret = add;
      ver = used;
    }
  }
  vector<int> ans;
  for (int i = 0; i < N; i++) {
    if ((ver >> i) & 1) ans.emplace_back(i);
  }
  return ans;
}
