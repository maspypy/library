// Source: https://github.com/maspypy/library/blob/main/string/palindromic_tree.hpp
template <int sigma>
struct Palindromic_Tree {
  struct Node {
    array<int, sigma> TO;
    int link;
    int length;
    int diff;            // link との差分
    int slink;           // series link, diff でなるべくたどった先
    pair<int, int> pos;  // one occurrence [l, r)

    Node(int link = -1, int length = 0, int l = 0, int r = 0)
        : link(link), length(length), diff(0), slink(0), pos({l, r}) {
      fill(all(TO), -1);
    }
  };

  vc<Node> nodes;
  // |path|=|S|+1
  // path[i]: longest palindromic suffix of S[0, i)
  vc<int> path;

  Palindromic_Tree() {}

  template <typename STRING>
  Palindromic_Tree(const STRING& S, char off) {
    build(S, off);
  }

  int size() const { return len(nodes); }

  template <typename STRING>
  void build(const STRING& S, char off) {
    nodes.clear();
    path.clear();

    // 0: imaginary root (length = -1)
    // 1: empty root (length = 0)
    nodes.eb(Node(-1, -1, 0, -1));
    nodes.eb(Node(0, 0, 0, 0));
    nodes[0].diff = nodes[1].diff = 0;
    nodes[0].slink = nodes[1].slink = 0;

    int p = 1;
    FOR(i, len(S)) {
      path.eb(p);
      int x = S[i] - off;
      assert(0 <= x && x < sigma);

      while (p) {
        int j = i - 1 - nodes[p].length;
        bool can = (j >= 0 && S[j] - off == x);
        if (can) break;
        p = nodes[p].link;
      }

      if (nodes[p].TO[x] != -1) {
        p = nodes[p].TO[x];
        continue;
      }

      int to = len(nodes);
      int l = i - 1 - nodes[p].length;
      int r = i + 1;
      nodes[p].TO[x] = to;

      int link = 1;
      if (p != 0) {
        int q = nodes[p].link;
        while (1) {
          int j = i - 1 - nodes[q].length;
          bool can = (j >= 0 && S[j] - off == x);
          if (can) break;
          q = nodes[q].link;
        }
        assert(nodes[q].TO[x] != -1);
        link = nodes[q].TO[x];
      }

      nodes.eb(Node(link, r - l, l, r));
      nodes[to].diff = nodes[to].length - nodes[link].length;
      nodes[to].slink =
          (nodes[to].diff == nodes[link].diff ? nodes[link].slink : link);
      p = to;
    }
    path.eb(p);
  }

  // length of maximum suffix palindrome of [l,r)
  int max_suffix_length(int l, int r) {
    assert(0 <= l && l < r && r < len(path));
    int n = r - l;
    int v = path[r];
    while (v > 1) {
      int d = nodes[v].diff;
      int hi = nodes[v].length;
      int u = nodes[v].slink;
      int low = nodes[u].length + d;
      if (hi <= n) return hi;
      if (low <= n) {
        // hi - xd <= n
        int x = ceil<int>(hi - n, d);
        return hi - x * d;
      }
      v = u;
    }
    assert(false);
  }

  // node(>=2) ごとの出現回数
  vc<int> count() {
    vc<int> res(len(nodes));
    for (auto&& p : path) res[p]++;
    FOR_R(k, 1, len(nodes)) {
      int link = nodes[k].link;
      res[link] += res[k];
    }
    res[0] = res[1] = 0;
    return res;
  }
};
