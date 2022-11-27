#include "alg/monoid/add.hpp"

// 終端ノードに value を入れる。
// failure link を作ると、そこが終端であるような文字列の value を
// Monoid で集約した value が入る。
template <int sigma, typename Monoid = Monoid_Add<int>>
struct Trie {
  using X = typename Monoid::value_type;
  int n_node;
  vector<array<int, sigma>> TO;
  vector<int> PAR;
  vector<X> node_value;
  vector<int> BFS;
  vector<int> FAIL;

  Trie()
      : n_node(1),
        TO({array<int, sigma>()}),
        PAR({-1}),
        node_value({Monoid::unit()}) {
    FOR(s, sigma) TO[0][s] = -1;
  }

  template <typename STRING>
  int add(STRING S, int off, X val) {
    int v = 0;
    for (auto&& ss: S) {
      int s = ss - off;
      assert(0 <= s && s < sigma);
      if (TO[v][s] == -1) {
        TO[v][s] = create_node();
        PAR[TO[v][s]] = v;
      }
      v = TO[v][s];
    }
    node_value[v] = Monoid::op(node_value[v], val);
    return v;
  }

  void make_failure() {
    FAIL.assign(n_node, 0);
    BFS.reserve(n_node);
    deque<int> que;
    que.emplace_back(0);
    BFS.emplace_back(0);
    while (!que.empty()) {
      int v = que.front();
      que.pop_front();
      node_value[v] = Monoid::op(node_value[v], node_value[FAIL[v]]);
      for (int s = 0; s < sigma; ++s) {
        if (TO[v][s] == -1) continue;
        int w = TO[v][s];
        que.emplace_back(w);
        BFS.emplace_back(w);
        if (v == 0) continue;
        int f = FAIL[v];
        while (f && TO[f][s] == -1) f = FAIL[f];
        if (TO[f][s] == -1)
          FAIL[w] = 0;
        else
          FAIL[w] = TO[f][s];
      }
    }
    for (auto&& v: BFS) {
      FOR(s, sigma) if (TO[v][s] == -1) {
        int f = FAIL[v];
        TO[v][s] = TO[f][s];
        if (TO[v][s] == -1) TO[v][s] = 0;
      }
    }
  }

private:
  int create_node() {
    TO.eb(array<int, sigma>());
    FOR(s, sigma) TO.back()[s] = -1;
    PAR.eb(-1);
    node_value.eb(Monoid::unit());
    return n_node++;
  }
};
