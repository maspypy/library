#pragma once

#include "graph/tree.hpp"
#include "string/trie.hpp"

/*
入力：複数文字列 or trie
O(|trie nodes|)
node 番号は topological 順に付け直している
*/

template <int sigma = 26>
struct Generalized_Suffix_Automaton {
  struct Node {
    array<int, sigma> nxt;
    int link;
    int max_len;

    Node(int link, int max_len) : link(link), max_len(max_len) {
      fill(all(nxt), -1);
    }
  };

  using GT = Graph<int, 1>;
  using TREE = Tree<GT>;

  vc<Node> nodes;
  int n_node;

  Node& operator[](int i) { return nodes[i]; }
  const Node& operator[](int i) const { return nodes[i]; }

  Generalized_Suffix_Automaton() {}

  template <typename STRING>
  Generalized_Suffix_Automaton(const vc<STRING>& SS, int off) {
    build(SS, off);
  }

  // n 頂点 trie から構築. O(n sigma).
  void build(const Trie<sigma>& TRIE) {
    int N = TRIE.n_node;

    nodes.clear();
    vc<int> trie_pos(N, -1);
    nodes.reserve(2 * N);

    nodes.eb(-1, 0);
    trie_pos[0] = 0;

    // trie を BFS (depth 昇順) で処理する.
    vc<int> que(N);
    int ql = 0, qr = 0;
    que[qr++] = 0;
    while (ql < qr) {
      int v = que[ql++];
      int p = trie_pos[v];
      FOR(c, sigma) {
        int w = TRIE.nodes[v].ch[c];
        if (w == -1) continue;
        trie_pos[w] = add_single(p, c);
        que[qr++] = w;
      }
    }

    normalize();
  }

  // 複数文字列から trie を作り、それを generalized SAM にする.
  template <typename STRING>
  void build(const vc<STRING>& SS, int off) {
    Trie<sigma> TRIE;
    for (auto& S : SS) TRIE.add(S, off);
    build(TRIE);
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

  // 1 文字読み、入力文字列群の部分文字列である最長 suffix に遷移.
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
  // trie の edge: SAM state p --c--> ? を追加する generalized extension.
  // p は trie depth 順に処理される.
  int add_single(int p, int c) {
    // 既に遷移がある場合、その遷移先の max_len がちょうどなら再利用する.
    // 長さが飛んでいる場合は split する.
    if (nodes[p].nxt[c] != -1) {
      int q = nodes[p].nxt[c];
      if (nodes[p].max_len + 1 == nodes[q].max_len) return q;

      int clone = len(nodes);
      nodes.eb(nodes[q].link, nodes[p].max_len + 1);
      nodes[clone].nxt = nodes[q].nxt;

      int x = p;
      while (x != -1 && nodes[x].nxt[c] == q) {
        nodes[x].nxt[c] = clone;
        x = nodes[x].link;
      }
      nodes[q].link = clone;
      return clone;
    }

    int cur = len(nodes);
    nodes.eb(-1, nodes[p].max_len + 1);

    int x = p;
    while (x != -1 && nodes[x].nxt[c] == -1) {
      nodes[x].nxt[c] = cur;
      x = nodes[x].link;
    }

    if (x == -1) {
      nodes[cur].link = 0;
      return cur;
    }

    int q = nodes[x].nxt[c];
    if (nodes[x].max_len + 1 == nodes[q].max_len) {
      nodes[cur].link = q;
      return cur;
    }

    int clone = len(nodes);
    nodes.eb(nodes[q].link, nodes[x].max_len + 1);
    nodes[clone].nxt = nodes[q].nxt;

    while (x != -1 && nodes[x].nxt[c] == q) {
      nodes[x].nxt[c] = clone;
      x = nodes[x].link;
    }

    nodes[q].link = clone;
    nodes[cur].link = clone;
    return cur;
  }

  // max_len 昇順に reindex.
  void normalize() {
    int n = len(nodes);
    int max_len = 0;
    for (auto& x : nodes) chmax(max_len, x.max_len);

    vc<int> cnt(max_len + 1);
    for (auto& x : nodes) ++cnt[x.max_len];
    FOR(i, max_len) cnt[i + 1] += cnt[i];

    vc<int> ord(n);
    FOR_R(v, n) {
      int k = nodes[v].max_len;
      ord[--cnt[k]] = v;
    }

    vc<int> new_idx(n);
    FOR(i, n) new_idx[ord[i]] = i;

    vc<Node> new_nodes;
    new_nodes.reserve(n);
    FOR(i, n) new_nodes.eb(move(nodes[ord[i]]));

    FOR(v, n) {
      auto& nd = new_nodes[v];
      if (nd.link != -1) nd.link = new_idx[nd.link];
      for (auto& to : nd.nxt) {
        if (to != -1) to = new_idx[to];
      }
    }

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
};
