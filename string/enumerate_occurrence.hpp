
#include "graph/tree.hpp"
#include "string/trie.hpp"
#include "ds/fastset.hpp"
#include "ds/csr.hpp"

// T[i] distinct が必要
// T[i] が S に現れる位置を昇順列挙
// call f(i, vc<int>&pos)
// O(T + Slog^2S + Ssqrt(T))
template <typename STRING, int SIGMA = 26, int off = 'a', typename F>
void enumerate_occurrence(STRING S, vc<STRING> T, F f) {
  Trie<SIGMA> trie;
  FOR(i, len(T)) trie.add(T[i], off);
  trie.calc_suffix_link();

  int n = trie.n_node;
  Graph<int, 1> G(n);
  FOR(i, 1, n) G.add(trie.nodes[i].suffix_link, i);
  G.build();
  Tree<decltype(G)> tree(G);

  vc<int> TID(n, -1);
  FOR(i, len(T)) { TID[trie.words[i]] = i; }
  CSR<int> csr(n);
  {
    int v = 0;
    FOR(i, len(S)) {
      v = trie.nodes[v].nxt[S[i] - off];
      csr.add(v, i);
    }
  }
  csr.build();

  FastSet FS(len(S));
  vc<int> nxt(len(S));
  vc<int> pos;
  auto dfs = [&](auto& dfs, int h) -> void {
    auto path = tree.heavy_path_at(h);
    for (auto& v : path) {
      for (auto& e : G[v]) {
        if (tree.head[e.to] != h) dfs(dfs, e.to);
      }
    }

    FS.reset();
    auto ins = [&](int i) -> void {
      int a = FS.prev(i), b = FS.next(i);
      if (a != -1) nxt[a] = i;
      nxt[i] = b;
      FS.insert(i);
    };
    auto ins_v = [&](int v) -> void {
      for (int i : csr[v]) ins(i);
    };

    int prv = -1;
    FOR_R(k, len(path)) {
      int v = path[k];
      ins_v(v);
      int L = 0, R = 0;
      if (prv != -1) L = tree.RID[prv], R = tree.RID[v];
      FOR(i, L, R) ins_v(tree.V[i]);
      prv = v;

      int t = TID[v];
      if (t != -1) {
        int M = len(T[t]);
        pos.clear();
        for (int i = FS.next(0); i < len(S); i = nxt[i]) {
          // [i-M+1,i]
          pos.eb(i - M + 1);
        }
        f(t, pos);
      }
    }
  };
  dfs(dfs, 0);
}