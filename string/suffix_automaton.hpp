#pragma once

#include "graph/tree.hpp"

/*
SAM のノードは部分文字列を endpos 集合で分類している
reverse(S) の suffix tree というのとだいたい同じ
(v,k): node[v] で length[k]

node 番号が topological 順になるようにインデックスを付け直している
*/

template <int sigma = 26>
struct Suffix_Automaton {
  struct Node {
    array<int, sigma> nxt;
    int link;
    int max_len;

    // endpos information
    int occ;
    int min_pos;
    int max_pos;

    Node(int link, int max_len)
        : link(link),
          max_len(max_len),
          occ(0),
          min_pos(infty<int>),
          max_pos(-infty<int>) {
      fill(all(nxt), -1);
    }
  };

  using GT = Graph<int, 1>;
  using TREE = Tree<GT>;

  vc<Node> nodes;
  int n_node;

  Node& operator[](int i) { return nodes[i]; }

  // pos[i] := S[0:i) に対応する node
  vc<int> pos;

  Suffix_Automaton() {}
  template <typename STRING>
  Suffix_Automaton(const STRING& S, int off) {
    build(S, off);
  }

  template <typename STRING>
  void build(const STRING& S, int off) {
    int N = len(S);

    nodes.clear();
    pos.clear();
    nodes.reserve(2 * N);
    pos.reserve(N + 1);

    nodes.eb(-1, 0);
    pos.eb(0);

    int last = 0;
    for (auto&& x : S) {
      int c = x - off;
      assert(0 <= c && c < sigma);
      last = add_single(last, c);
      pos.eb(last);
    }

    FOR(i, N + 1) {
      int v = pos[i];
      ++nodes[v].occ;
      chmin(nodes[v].min_pos, i);
      chmax(nodes[v].max_pos, i);
    }

    // max_len 昇順
    int n = len(nodes);
    vc<int> cnt(N + 1);
    for (auto& x : nodes) ++cnt[x.max_len];
    FOR(i, N) cnt[i + 1] += cnt[i];

    vc<int> ord(n);
    FOR_R(v, n) {
      int k = nodes[v].max_len;
      ord[--cnt[k]] = v;
    }

    FOR_R(i, 1, n) {
      int v = ord[i];
      int p = nodes[v].link;
      nodes[p].occ += nodes[v].occ;
      chmin(nodes[p].min_pos, nodes[v].min_pos);
      chmax(nodes[p].max_pos, nodes[v].max_pos);
    }

    vc<int> new_idx(n);
    FOR(i, n) new_idx[ord[i]] = i;

    vc<Node> new_nodes;
    new_nodes.reserve(n);

    FOR(i, n) {
      int v = ord[i];
      new_nodes.eb(move(nodes[v]));
    }

    FOR(v, n) {
      auto& nd = new_nodes[v];
      if (nd.link != -1) nd.link = new_idx[nd.link];
      for (auto& to : nd.nxt) {
        if (to != -1) to = new_idx[to];
      }
    }
    for (auto& v : pos) v = new_idx[v];
    nodes = move(new_nodes);

    n_node = n;
    assert(nodes[0].link == -1);
    FOR(v, 1, n) assert(nodes[v].link < v);
    FOR(v, n) {
      for (auto to : nodes[v].nxt) {
        if (to != -1) assert(v < to);
      }
    }
  }

  // node v が表す文字列長の半開区間
  pair<int, int> len_range(int v) const {
    assert(0 <= v && v < len(nodes));
    if (v == 0) return {0, 1};
    return {nodes[nodes[v].link].max_len + 1, nodes[v].max_len + 1};
  }

  // suffix-link tree
  pair<GT, TREE> build_tree() const {
    int n = len(nodes);
    GT G(n);
    FOR(v, 1, n) G.add(nodes[v].link, v);
    G.build();
    TREE tree(G, 0);
    return {move(G), move(tree)};
  }

  // S[L:R) を表す (node, length)
  pair<int, int> find_node(const TREE& tree, int L, int R) const {
    int N = len(pos) - 1;
    assert(0 <= L && L <= R && R <= N);

    if (L == R) return {0, 0};

    int k = R - L;
    int v = pos[R];

    v = tree.max_path(
        [&](int u) -> bool { return nodes[u].max_len >= k; }, v, 0);

    assert(v != -1);
    auto [a, b] = len_range(v);
    assert(a <= k && k < b);

    return {v, k};
  }

  // 1 文字読み S の部分文字列である最長 suffix に遷移
  pair<int, int> next(pair<int, int> p, int c) const {
    auto [v, k] = p;
    assert(0 <= c && c < sigma);

    while (v != 0 && nodes[v].nxt[c] == -1) {
      v = nodes[v].link;
      k = nodes[v].max_len;
    }

    int to = nodes[v].nxt[c];
    if (to == -1) return {0, 0};

    return {to, k + 1};
  }

 private:
  int add_single(int last, int c) {
    int cur = len(nodes);
    nodes.eb(-1, nodes[last].max_len + 1);

    int p = last;
    while (p != -1 && nodes[p].nxt[c] == -1) {
      nodes[p].nxt[c] = cur;
      p = nodes[p].link;
    }

    if (p == -1) {
      nodes[cur].link = 0;
      return cur;
    }

    int q = nodes[p].nxt[c];

    if (nodes[p].max_len + 1 == nodes[q].max_len) {
      nodes[cur].link = q;
      return cur;
    }

    int clone = len(nodes);
    nodes.eb(nodes[q].link, nodes[p].max_len + 1);
    nodes[clone].nxt = nodes[q].nxt;

    while (p != -1 && nodes[p].nxt[c] == q) {
      nodes[p].nxt[c] = clone;
      p = nodes[p].link;
    }

    nodes[q].link = clone;
    nodes[cur].link = clone;

    return cur;
  }
};