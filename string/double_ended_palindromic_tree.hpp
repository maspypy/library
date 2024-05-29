// https://arxiv.org/abs/2210.02292
// https://codeforces.com/contest/1738/submission/263034583
template <int sigma, char offset>
struct Double_Ended_Palindromic_Tree {
  struct Node {
    array<int, sigma> TO; // 両端にある文字を追加してできる回文
    int par;              // 両端にある文字を除いてできる回文
    int link;             // longest suffix palindrome ノード
    int length;           // その回文の長さ
    int cnt;
    int linkcnt; // suffix link tree での子の個数

    // link の計算をメモ化したもの
    // str(v)+c の longest palindrome suffix = c+str(w)+c となる w
    array<int, sigma> direct_link;
  };
  static constexpr int ODD = 0, EVEN = 1;
  vc<Node> nodes;
  vc<int> FREE; // Node が削除済で使われていない index

  // 文字列の position ごとに持つもの
  struct T {
    int c;
    // その文字から左右に伸びる極大回文が surface ならばその node
    // surface でないならば EVEN
    int left_surface, right_surface;
  };

  int mod, mask;
  vc<T> dat;
  int L = 0, R = 0; // global index range
  int num_node = 0;

  int new_node(int par, int link, int length, int c = -1) {
    ++num_node;
    Node n;
    fill(all(n.TO), -1);
    fill(all(n.direct_link), -1);
    n.par = par, n.link = link, n.length = length;
    n.linkcnt = n.cnt = 0;
    if (link != -1) nodes[link].linkcnt += 1;
    int p = 0;
    if (FREE.empty()) {
      p = len(nodes);
      nodes.eb(n);
    } else {
      p = POP(FREE);
      nodes[p] = n;
    }
    if (par != -1) nodes[par].TO[c] = p;
    return p;
  }

  void remove_node(int nid, int c) {
    --num_node;
    int pid = nodes[nid].par;
    assert(nodes[pid].TO[c] == nid);
    nodes[pid].TO[c] = -1;
    int k = nodes[nid].link;
    nodes[k].linkcnt -= 1;
    if (nodes[k].linkcnt == 0) FREE.eb(nid);
  }

  Double_Ended_Palindromic_Tree(int max_size) { // odd, even
    assert(ODD == new_node(-1, -1, -1));
    assert(EVEN == new_node(-1, 0, 0));
    nodes[ODD].cnt = infty<int>, nodes[EVEN].cnt = infty<int>;
    mod = 4;
    while (mod < max_size) mod *= 2;
    dat.resize(mod);
    mask = mod - 1;
  }

  int suffix_node() {
    return (L == R ? EVEN : dat[(R - 1) & mask].left_surface);
  }
  int prefix_node() { return (L == R ? EVEN : dat[L & mask].right_surface); }

  void push_back(int c) {
    assert(R - L <= mask);
    c -= offset;
    int v = suffix_node();
    dat[R & mask].c = c;
    // update palindromic tree, v <- nxt suffix node
    v = [&]() -> int {
      auto dfs = [&](auto& dfs, int v) -> int {
        // str(v)+c の longest suffix palindrome = c+str(w)+c
        int& w = nodes[v].direct_link[c];
        if (w != -1) { return w; }
        int p = nodes[v].link;
        int j = R - 1 - nodes[p].length;
        if (L <= j && j <= R && dat[j & mask].c == c) { return w = p; }
        return w = dfs(dfs, p);
      };
      // いまのノードに足せないなら戻る
      int j = R - 1 - nodes[v].length;
      if (!(L <= j && j <= R && dat[j & mask].c == c)) { v = dfs(dfs, v); }
      // c+str(v)+c を作る
      if (nodes[v].TO[c] != -1) { return nodes[v].TO[c]; }
      int link = (v == ODD ? EVEN : nodes[dfs(dfs, v)].TO[c]);
      return new_node(v, link, nodes[v].length + 2, c);
    }();
    dat[R & mask].right_surface = EVEN;
    dat[(R - nodes[v].length + 1) & mask].right_surface = v;
    dat[R & mask].left_surface = v;
    int w = nodes[v].link;

    int k = (R - nodes[v].length + nodes[w].length);
    if (nodes[w].length >= 1 && dat[k & mask].left_surface == w) {
      dat[k & mask].left_surface = EVEN;
    }
    ++R, nodes[v].cnt += 1;
  }

  void pop_back() {
    assert(L < R);
    int v = suffix_node();
    int w = nodes[v].link;
    int k = R - 1 - nodes[v].length + nodes[w].length;
    if (nodes[dat[k & mask].left_surface].length < nodes[w].length) {
      dat[k & mask].left_surface = w;
      dat[(k - nodes[w].length + 1) & mask].right_surface = w;
    } else {
      dat[(k - nodes[w].length + 1) & mask].right_surface = EVEN;
    }
    nodes[v].cnt--;
    if (nodes[v].linkcnt == 0 && nodes[v].cnt == 0) {
      remove_node(v, dat[(R - 1) & mask].c);
    }
    --R;
  }

  void push_front(int c) {
    assert(R - L <= mask);
    c -= offset;
    int v = prefix_node();
    dat[(L - 1) & mask].c = c;
    // update palindromic tree, v <- nxt suffix node
    v = [&]() -> int {
      auto dfs = [&](auto& dfs, int v) -> int {
        // str(v)+c の longest suffix palindrome = c+str(w)+c
        int& w = nodes[v].direct_link[c];
        if (w != -1) { return w; }
        int p = nodes[v].link;
        int j = L + nodes[p].length;
        if (L - 1 <= j && j <= R - 1 && dat[j & mask].c == c) { return w = p; }
        return w = dfs(dfs, p);
      };
      // いまのノードに足せないなら戻る
      int j = L + nodes[v].length;
      if (!(L - 1 <= j && j <= R - 1 && dat[j & mask].c == c)) {
        v = dfs(dfs, v);
      }
      // c+str(v)+c を作る
      if (nodes[v].TO[c] != -1) { return nodes[v].TO[c]; }
      int link = (v == ODD ? EVEN : nodes[dfs(dfs, v)].TO[c]);
      return new_node(v, link, nodes[v].length + 2, c);
    }();
    dat[(L - 1) & mask].left_surface = EVEN;
    dat[(L - 2 + nodes[v].length) & mask].left_surface = v;
    dat[(L - 1) & mask].right_surface = v;
    int w = nodes[v].link;

    int k = ((L - 1) + nodes[v].length - nodes[w].length);
    if (nodes[w].length >= 1 && dat[k & mask].right_surface == w) {
      dat[k & mask].right_surface = EVEN;
    }
    --L, nodes[v].cnt += 1;
  }

  void pop_front() {
    assert(L < R);
    int v = prefix_node();
    int w = nodes[v].link;
    int k = L + nodes[v].length - nodes[w].length;
    if (nodes[dat[k & mask].right_surface].length < nodes[w].length) {
      dat[k & mask].right_surface = w;
      dat[(k + nodes[w].length - 1) & mask].left_surface = w;
    } else {
      dat[(k + nodes[w].length - 1) & mask].left_surface = EVEN;
    }
    nodes[v].cnt--;
    if (nodes[v].linkcnt == 0 && nodes[v].cnt == 0) {
      remove_node(v, dat[L & mask].c);
    }
    ++L;
  }

  int count_distinct_palindrome() { return num_node - 2; }
  int maximum_prefix_palindrome() { return nodes[prefix_node()].length; }
  int maximum_suffix_palindrome() { return nodes[suffix_node()].length; }
};
