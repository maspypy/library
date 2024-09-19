
// sigma が小さい
// 一般の n 頂点の木構造で O(n) 時間で動く
// https://atcoder.jp/contests/xmascontest2015noon/tasks/xmascontest2015_d
template <int sigma>
struct Trie {
  struct Node {
    array<int, sigma> ch;
    array<int, sigma> nxt; // suffix link -> add c
    int parent;
    int suffix_link;
  };
  int n_node;
  vc<Node> nodes;
  vc<int> words;
  vc<int> BFS; // BFS 順

  Trie() {
    n_node = 0;
    new_node();
  }

  Node& operator[](int i) { return nodes[i]; }

  template <typename STRING>
  int add(STRING S, int off) {
    int v = 0;
    for (auto&& s: S) { v = add_single(v, s, off); }
    words.eb(v);
    return v;
  }

  int add_single(int v, int c, int off) {
    c -= off;
    assert(0 <= c && c < sigma);
    if (nodes[v].ch[c] != -1) return nodes[v].ch[c];
    nodes[v].ch[c] = new_node();
    nodes.back().parent = v;
    return nodes[v].ch[c];
  }

  void calc_suffix_link() {
    BFS.resize(n_node);
    int p = 0, q = 0;
    BFS[q++] = 0;
    fill(all(nodes[0].nxt), 0);
    while (p < q) {
      int v = BFS[p++];
      if (v) nodes[v].nxt = nodes[nodes[v].suffix_link].nxt;
      FOR(s, sigma) {
        int w = nodes[v].ch[s];
        if (w == -1) continue;
        nodes[w].suffix_link = nodes[v].nxt[s];
        nodes[v].nxt[s] = w;
        BFS[q++] = w;
      }
    }
  }

  vc<int> calc_count() {
    vc<int> count(n_node);
    for (auto&& x: words) count[x]++;
    for (auto&& v: BFS)
      if (v) { count[v] += count[nodes[v].suffix_link]; }
    return count;
  }

private:
  int new_node() {
    Node c;
    fill(all(c.ch), -1);
    fill(all(c.nxt), -1);
    c.parent = -1;
    c.suffix_link = -1;
    nodes.eb(c);
    return n_node++;
  }
};
