#include "graph/base.hpp"

template <int sigma = 26>
struct Suffix_Automaton {
  struct Node {
    array<int, sigma> next; // automaton の遷移先
    int link;               // suffix link
    int size;               // node が受理する最長文字列の長さ
    Node(int link, int size) : link(link), size(size) { fill(all(next), -1); }
  };

  vc<Node> nodes;
  int last; // 文字列全体を入れたときの行き先

  Suffix_Automaton() {
    nodes.eb(Node(-1, 0));
    last = 0;
  }

  void add(char c0, char off) {
    int c = c0 - 'a';
    int new_node = len(nodes);
    nodes.eb(Node(-1, nodes[last].size + 1));
    int p = last;
    while (p != -1 && nodes[p].next[c] == -1) {
      nodes[p].next[c] = new_node;
      p = nodes[p].link;
    }
    int q = (p == -1 ? 0 : nodes[p].next[c]);
    if (p == -1 || nodes[p].size + 1 == nodes[q].size) {
      nodes[new_node].link = q;
    } else {
      int new_q = len(nodes);
      nodes.eb(Node(nodes[q].link, nodes[p].size + 1));
      nodes.back().next = nodes[q].next;
      nodes[q].link = new_q;
      nodes[new_node].link = new_q;
      while (p != -1 && nodes[p].next[c] == q) {
        nodes[p].next[c] = new_q;
        p = nodes[p].link;
      }
    }
    last = new_node;
  }

  Graph<int, 1> calc_DAG() {
    int n = len(nodes);
    Graph<int, 1> G(n);
    FOR(v, n) {
      for (auto&& to: nodes[v].next)
        if (to != -1) { G.add(v, to); }
    }
    G.build();
    return G;
  }

  Graph<int, 1> calc_tree() {
    int n = len(nodes);
    Graph<int, 1> G(n);
    FOR(v, 1, n) {
      int p = nodes[v].link;
      G.add(p, v);
    }
    G.build();
    return G;
  }

  int count_substring_at(int p) {
    // あるノードについて、最短と最長の文字列長が分かればよい。
    // 最長は size が持っている
    // 最短は、suffix link 先の最長に 1 を加えたものである。
    if (p == 0) return 0;
    return nodes[p].size - nodes[nodes[p].link].size;
  }

  ll count_substring() {
    ll ANS = 0;
    FOR(i, len(nodes)) ANS += count_substring_at(i);
    return ANS;
  }
};
