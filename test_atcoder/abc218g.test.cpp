#define PROBLEM "https://atcoder.jp/contests/abc218/tasks/abc218_g"
#include "my_template.hpp"
#include "other/io.hpp"

#include "ds/binary_trie.hpp"

ll A[100010];
int N, m[100010];
Binary_Trie<30, false, 200'100, u32> BT;
using np = decltype(BT)::np;
np root;

vector<int> G[100010];

int get_med() {
  int cnt = root->cnt;
  if (cnt & 1) { return BT.kth(root, cnt / 2, 0); }
  return (BT.kth(root, cnt / 2, 0) + BT.kth(root, (cnt - 1) / 2, 0)) / 2;
}

void dfs(int v, int p, int mode) {
  bool f = true;
  if (mode) m[v] = 1 << 30;
  root = BT.add(root, A[v], 1);
  for (auto u: G[v]) {
    if (u == p) continue;
    f = false;
    dfs(u, v, (mode + 1) & 1);
    if (mode) {
      chmin(m[v], m[u]);
    } else {
      chmax(m[v], m[u]);
    }
  }
  if (f) m[v] = get_med();
  root = BT.add(root, A[v], -1);
}

void solve() {
  INT(N);
  root = BT.new_root();
  FOR(i, 1, N + 1) read(A[i]);
  FOR(i, 1, N) {
    INT(x, y);
    G[x].eb(y), G[y].eb(x);
  }
  dfs(1, 0, 0);
  print(m[1]);
}

signed main() {
  solve();
  return 0;
}
