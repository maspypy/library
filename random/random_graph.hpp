#include "graph/base.hpp"
#include "random/base.hpp"
#include "random/shuffle.hpp"
#include "ds/unionfind/unionfind.hpp"

void random_relabel(int N, vc<pair<int, int>>& G) {
  shuffle(G);
  vc<int> A(N);
  FOR(i, N) A[i] = i;
  shuffle(A);
  for (auto& [a, b]: G) a = A[a], b = A[b];
}

template <int DIRECTED>
vc<pair<int, int>> random_graph(int n, bool simple) {
  vc<pair<int, int>> G, cand;
  FOR(a, n) FOR(b, n) {
    if (simple && a == b) continue;
    if (!DIRECTED && a > b) continue;
    cand.eb(a, b);
  }
  int m = RNG(0, len(cand) + 1);
  set<int> ss;
  FOR(m) {
    while (1) {
      int i = RNG(0, len(cand));
      if (simple && ss.count(i)) continue;
      ss.insert(i);
      auto [a, b] = cand[i];
      G.eb(a, b);
      break;
    }
  }
  random_relabel(n, G);
  return G;
}

vc<pair<int, int>> random_tree(int n) {
  vc<pair<int, int>> G;
  FOR(i, 1, n) { G.eb(RNG(0, i), i); }
  random_relabel(n, G);
  return G;
}

// EDGE = true: 各辺が唯一のサイクル（関節点でサイクルまたは辺）
// EDGE = false： 各頂点が唯一のサイクル（橋でサイクルまたは辺）
vc<pair<int, int>> random_cactus(int N, bool EDGE) {
  if (!EDGE) {
    // n 頂点を 1 または 3 以上に分割
    vvc<int> A;
    int n = RNG(1, N + 1);
    vc<int> S(n, 1);
    int rest = N - n;
    while (rest > 0) {
      int k = RNG(0, n);
      if (S[k] == 1) {
        if (rest == 1) {
          S.eb(1), rest = 0;
        } else {
          S[k] += 2, rest -= 2;
        }
      } else {
        S[k]++, rest--;
      }
    }
    n = len(S);
    int p = 0;
    FOR(i, n) {
      vc<int> C;
      FOR(v, p, p + S[i]) C.eb(v);
      A.eb(C);
      p += S[i];
    }
    int m = len(A);
    auto H = random_tree(m);
    vc<pair<int, int>> G;
    FOR(i, m) {
      vc<int>& V = A[i];
      if (len(V) == 1) continue;
      FOR(k, len(V)) { G.eb(V[k], V[(1 + k) % len(V)]); }
    }
    for (auto& [c1, c2]: H) {
      int a = A[c1][RNG(0, len(A[c1]))];
      int b = A[c2][RNG(0, len(A[c2]))];
      G.eb(a, b);
    }
    random_relabel(N, G);
    return G;
  }
  assert(EDGE);
  if (N == 1) return {};
  int n = RNG(1, N);
  vc<int> S(n, 2);
  int rest = N - 1 - n;
  while (rest > 0) {
    int k = RNG(0, n);
    S[k]++, --rest;
  }
  vvc<int> A;
  int p = 0;
  FOR(i, n) {
    vc<int> C;
    FOR(v, p, p + S[i]) C.eb(v);
    A.eb(C);
    p += S[i];
  }
  assert(p == N + n - 1);
  UnionFind uf(p);
  auto H = random_tree(n);
  for (auto& [c1, c2]: H) {
    int a = A[c1][RNG(0, len(A[c1]))];
    int b = A[c2][RNG(0, len(A[c2]))];
    uf.merge(a, b);
  }
  vc<int> new_idx(p);
  int x = 0;
  FOR(i, p) if (uf[i] == i) new_idx[i] = x++;
  assert(x == N);
  FOR(i, p) new_idx[i] = new_idx[uf[i]];
  vc<pair<int, int>> G;
  FOR(i, n) {
    vc<int>& V = A[i];
    for (auto& v: V) v = new_idx[v];
    if (len(V) == 2) {
      G.eb(V[0], V[1]);
    } else {
      FOR(k, len(V)) { G.eb(V[k], V[(1 + k) % len(V)]); }
    }
  }
  random_relabel(N, G);
  return G;
}

// |child| = 0 or 2 or (1 if can1), ラベルはトポロジカル
// return: par
vc<int> random_binary_tree(int N, bool can_1) {
  if (can_1) {
    vc<int> S;
    S.eb(0), S.eb(0);
    vc<int> par(N, -1);
    FOR(v, 1, N) {
      int k = RNG(0, len(S));
      swap(S[k], S.back());
      par[v] = POP(S);
      S.eb(v), S.eb(v);
    }
    return par;
  }
  // 0 or 2
  assert(N % 2 == 1);
  vc<int> par(N, -1);
  vc<int> S;
  FOR(v, N / 2, N) S.eb(v);
  int nxt = N / 2 - 1;
  while (len(S) >= 2) {
    shuffle(S);
    int a = POP(S), b = POP(S);
    par[a] = par[b] = nxt;
    S.eb(nxt), --nxt;
  }
  return par;
}
