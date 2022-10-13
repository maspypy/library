// palindromic tree を作る
template <int sigma>
struct Palindromic_Tree {
  struct Node {
    array<int, sigma> TO;
    int link;
    int length;
    pair<int, int> pos; // position of first ocurrence
    Node(int link, int length, int l, int r)
        : link(link), length(length), pos({l, r}) {
      fill(all(TO), -1);
    }
  };

  vc<Node> nodes;
  vc<int> path;

  template <typename STRING>
  Palindromic_Tree(const STRING& S, char off) {
    nodes.eb(Node(-1, -1, 0, -1));
    nodes.eb(Node(0, 0, 0, 0));
    path = {0};
    int p = 0;
    FOR(i, len(S)) {
      path.eb(p);
      int x = S[i] - off;
      while (p) {
        int j = i - 1 - nodes[p].length;
        bool can = (j >= 0 && S[j] - off == x);
        if (!can) {
          p = nodes[p].link;
          continue;
        }
        break;
      }
      if (nodes[p].TO[x] != -1) {
        p = nodes[p].TO[x];
        continue;
      }
      int to = len(nodes);
      int l = i - 1 - nodes[p].length;
      int r = i + 1;
      nodes[p].TO[x] = to;

      int link;
      if (p == 0) link = 1;
      if (p != 0) {
        while (1) {
          p = nodes[p].link;
          int j = i - 1 - nodes[p].length;
          bool can = (j >= 0 && S[j] - off == x) || (p == 0);
          if (can) break;
        }
        assert(nodes[p].TO[x] != -1);
        link = nodes[p].TO[x];
      }
      nodes.eb(Node(link, r - l, l, r));
      p = to;
    }
    path.eb(p);
  }

  vc<int> count() {
    vc<int> res(len(nodes));
    for (auto&& p: path) res[p]++;
    FOR_R(k, 1, len(nodes)) {
      int link = nodes[k].link;
      res[link] += res[k];
    }
    return res;
  }
};