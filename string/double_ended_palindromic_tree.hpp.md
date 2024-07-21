---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/library_checker/string/palindromes_in_deque.test.cpp
    title: test/library_checker/string/palindromes_in_deque.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links:
    - https://arxiv.org/abs/2210.02292
    - https://codeforces.com/contest/1738/submission/263034583
  bundledCode: "#line 1 \"string/double_ended_palindromic_tree.hpp\"\n// https://arxiv.org/abs/2210.02292\n\
    // https://codeforces.com/contest/1738/submission/263034583\ntemplate <int sigma,\
    \ char offset>\nstruct Double_Ended_Palindromic_Tree {\n  struct Node {\n    array<int,\
    \ sigma> TO; // \u4E21\u7AEF\u306B\u3042\u308B\u6587\u5B57\u3092\u8FFD\u52A0\u3057\
    \u3066\u3067\u304D\u308B\u56DE\u6587\n    int par;              // \u4E21\u7AEF\
    \u306B\u3042\u308B\u6587\u5B57\u3092\u9664\u3044\u3066\u3067\u304D\u308B\u56DE\
    \u6587\n    int link;             // longest suffix palindrome \u30CE\u30FC\u30C9\
    \n    int length;           // \u305D\u306E\u56DE\u6587\u306E\u9577\u3055\n  \
    \  int cnt;\n    int linkcnt; // suffix link tree \u3067\u306E\u5B50\u306E\u500B\
    \u6570\n\n    // link \u306E\u8A08\u7B97\u3092\u30E1\u30E2\u5316\u3057\u305F\u3082\
    \u306E\n    // str(v)+c \u306E longest palindrome suffix = c+str(w)+c \u3068\u306A\
    \u308B w\n    array<int, sigma> direct_link;\n  };\n  static constexpr int ODD\
    \ = 0, EVEN = 1;\n  vc<Node> nodes;\n  vc<int> FREE; // Node \u304C\u524A\u9664\
    \u6E08\u3067\u4F7F\u308F\u308C\u3066\u3044\u306A\u3044 index\n\n  // \u6587\u5B57\
    \u5217\u306E position \u3054\u3068\u306B\u6301\u3064\u3082\u306E\n  struct T {\n\
    \    int c;\n    // \u305D\u306E\u6587\u5B57\u304B\u3089\u5DE6\u53F3\u306B\u4F38\
    \u3073\u308B\u6975\u5927\u56DE\u6587\u304C surface \u306A\u3089\u3070\u305D\u306E\
    \ node\n    // surface \u3067\u306A\u3044\u306A\u3089\u3070 EVEN\n    int left_surface,\
    \ right_surface;\n  };\n\n  int mod, mask;\n  vc<T> dat;\n  int L = 0, R = 0;\
    \ // global index range\n  int num_node = 0;\n\n  int new_node(int par, int link,\
    \ int length, int c = -1) {\n    ++num_node;\n    Node n;\n    fill(all(n.TO),\
    \ -1);\n    fill(all(n.direct_link), -1);\n    n.par = par, n.link = link, n.length\
    \ = length;\n    n.linkcnt = n.cnt = 0;\n    if (link != -1) nodes[link].linkcnt\
    \ += 1;\n    int p = 0;\n    if (FREE.empty()) {\n      p = len(nodes);\n    \
    \  nodes.eb(n);\n    } else {\n      p = POP(FREE);\n      nodes[p] = n;\n   \
    \ }\n    if (par != -1) nodes[par].TO[c] = p;\n    return p;\n  }\n\n  void remove_node(int\
    \ nid, int c) {\n    --num_node;\n    int pid = nodes[nid].par;\n    assert(nodes[pid].TO[c]\
    \ == nid);\n    nodes[pid].TO[c] = -1;\n    int k = nodes[nid].link;\n    nodes[k].linkcnt\
    \ -= 1;\n    if (nodes[k].linkcnt == 0) FREE.eb(nid);\n  }\n\n  Double_Ended_Palindromic_Tree(int\
    \ max_size) { // odd, even\n    assert(ODD == new_node(-1, -1, -1));\n    assert(EVEN\
    \ == new_node(-1, 0, 0));\n    nodes[ODD].cnt = infty<int>, nodes[EVEN].cnt =\
    \ infty<int>;\n    mod = 4;\n    while (mod < max_size) mod *= 2;\n    dat.resize(mod);\n\
    \    mask = mod - 1;\n  }\n\n  int suffix_node() {\n    return (L == R ? EVEN\
    \ : dat[(R - 1) & mask].left_surface);\n  }\n  int prefix_node() { return (L ==\
    \ R ? EVEN : dat[L & mask].right_surface); }\n\n  void push_back(int c) {\n  \
    \  assert(R - L <= mask);\n    c -= offset;\n    int v = suffix_node();\n    dat[R\
    \ & mask].c = c;\n    // update palindromic tree, v <- nxt suffix node\n    v\
    \ = [&]() -> int {\n      auto dfs = [&](auto& dfs, int v) -> int {\n        //\
    \ str(v)+c \u306E longest suffix palindrome = c+str(w)+c\n        int& w = nodes[v].direct_link[c];\n\
    \        if (w != -1) { return w; }\n        int p = nodes[v].link;\n        int\
    \ j = R - 1 - nodes[p].length;\n        if (L <= j && j <= R && dat[j & mask].c\
    \ == c) { return w = p; }\n        return w = dfs(dfs, p);\n      };\n      //\
    \ \u3044\u307E\u306E\u30CE\u30FC\u30C9\u306B\u8DB3\u305B\u306A\u3044\u306A\u3089\
    \u623B\u308B\n      int j = R - 1 - nodes[v].length;\n      if (!(L <= j && j\
    \ <= R && dat[j & mask].c == c)) { v = dfs(dfs, v); }\n      // c+str(v)+c \u3092\
    \u4F5C\u308B\n      if (nodes[v].TO[c] != -1) { return nodes[v].TO[c]; }\n   \
    \   int link = (v == ODD ? EVEN : nodes[dfs(dfs, v)].TO[c]);\n      return new_node(v,\
    \ link, nodes[v].length + 2, c);\n    }();\n    dat[R & mask].right_surface =\
    \ EVEN;\n    dat[(R - nodes[v].length + 1) & mask].right_surface = v;\n    dat[R\
    \ & mask].left_surface = v;\n    int w = nodes[v].link;\n\n    int k = (R - nodes[v].length\
    \ + nodes[w].length);\n    if (nodes[w].length >= 1 && dat[k & mask].left_surface\
    \ == w) {\n      dat[k & mask].left_surface = EVEN;\n    }\n    ++R, nodes[v].cnt\
    \ += 1;\n  }\n\n  void pop_back() {\n    assert(L < R);\n    int v = suffix_node();\n\
    \    int w = nodes[v].link;\n    int k = R - 1 - nodes[v].length + nodes[w].length;\n\
    \    if (nodes[dat[k & mask].left_surface].length < nodes[w].length) {\n     \
    \ dat[k & mask].left_surface = w;\n      dat[(k - nodes[w].length + 1) & mask].right_surface\
    \ = w;\n    } else {\n      dat[(k - nodes[w].length + 1) & mask].right_surface\
    \ = EVEN;\n    }\n    nodes[v].cnt--;\n    if (nodes[v].linkcnt == 0 && nodes[v].cnt\
    \ == 0) {\n      remove_node(v, dat[(R - 1) & mask].c);\n    }\n    --R;\n  }\n\
    \n  void push_front(int c) {\n    assert(R - L <= mask);\n    c -= offset;\n \
    \   int v = prefix_node();\n    dat[(L - 1) & mask].c = c;\n    // update palindromic\
    \ tree, v <- nxt suffix node\n    v = [&]() -> int {\n      auto dfs = [&](auto&\
    \ dfs, int v) -> int {\n        // str(v)+c \u306E longest suffix palindrome =\
    \ c+str(w)+c\n        int& w = nodes[v].direct_link[c];\n        if (w != -1)\
    \ { return w; }\n        int p = nodes[v].link;\n        int j = L + nodes[p].length;\n\
    \        if (L - 1 <= j && j <= R - 1 && dat[j & mask].c == c) { return w = p;\
    \ }\n        return w = dfs(dfs, p);\n      };\n      // \u3044\u307E\u306E\u30CE\
    \u30FC\u30C9\u306B\u8DB3\u305B\u306A\u3044\u306A\u3089\u623B\u308B\n      int\
    \ j = L + nodes[v].length;\n      if (!(L - 1 <= j && j <= R - 1 && dat[j & mask].c\
    \ == c)) {\n        v = dfs(dfs, v);\n      }\n      // c+str(v)+c \u3092\u4F5C\
    \u308B\n      if (nodes[v].TO[c] != -1) { return nodes[v].TO[c]; }\n      int\
    \ link = (v == ODD ? EVEN : nodes[dfs(dfs, v)].TO[c]);\n      return new_node(v,\
    \ link, nodes[v].length + 2, c);\n    }();\n    dat[(L - 1) & mask].left_surface\
    \ = EVEN;\n    dat[(L - 2 + nodes[v].length) & mask].left_surface = v;\n    dat[(L\
    \ - 1) & mask].right_surface = v;\n    int w = nodes[v].link;\n\n    int k = ((L\
    \ - 1) + nodes[v].length - nodes[w].length);\n    if (nodes[w].length >= 1 &&\
    \ dat[k & mask].right_surface == w) {\n      dat[k & mask].right_surface = EVEN;\n\
    \    }\n    --L, nodes[v].cnt += 1;\n  }\n\n  void pop_front() {\n    assert(L\
    \ < R);\n    int v = prefix_node();\n    int w = nodes[v].link;\n    int k = L\
    \ + nodes[v].length - nodes[w].length;\n    if (nodes[dat[k & mask].right_surface].length\
    \ < nodes[w].length) {\n      dat[k & mask].right_surface = w;\n      dat[(k +\
    \ nodes[w].length - 1) & mask].left_surface = w;\n    } else {\n      dat[(k +\
    \ nodes[w].length - 1) & mask].left_surface = EVEN;\n    }\n    nodes[v].cnt--;\n\
    \    if (nodes[v].linkcnt == 0 && nodes[v].cnt == 0) {\n      remove_node(v, dat[L\
    \ & mask].c);\n    }\n    ++L;\n  }\n\n  int count_distinct_palindrome() { return\
    \ num_node - 2; }\n  int maximum_prefix_palindrome() { return nodes[prefix_node()].length;\
    \ }\n  int maximum_suffix_palindrome() { return nodes[suffix_node()].length; }\n\
    };\n"
  code: "// https://arxiv.org/abs/2210.02292\n// https://codeforces.com/contest/1738/submission/263034583\n\
    template <int sigma, char offset>\nstruct Double_Ended_Palindromic_Tree {\n  struct\
    \ Node {\n    array<int, sigma> TO; // \u4E21\u7AEF\u306B\u3042\u308B\u6587\u5B57\
    \u3092\u8FFD\u52A0\u3057\u3066\u3067\u304D\u308B\u56DE\u6587\n    int par;   \
    \           // \u4E21\u7AEF\u306B\u3042\u308B\u6587\u5B57\u3092\u9664\u3044\u3066\
    \u3067\u304D\u308B\u56DE\u6587\n    int link;             // longest suffix palindrome\
    \ \u30CE\u30FC\u30C9\n    int length;           // \u305D\u306E\u56DE\u6587\u306E\
    \u9577\u3055\n    int cnt;\n    int linkcnt; // suffix link tree \u3067\u306E\u5B50\
    \u306E\u500B\u6570\n\n    // link \u306E\u8A08\u7B97\u3092\u30E1\u30E2\u5316\u3057\
    \u305F\u3082\u306E\n    // str(v)+c \u306E longest palindrome suffix = c+str(w)+c\
    \ \u3068\u306A\u308B w\n    array<int, sigma> direct_link;\n  };\n  static constexpr\
    \ int ODD = 0, EVEN = 1;\n  vc<Node> nodes;\n  vc<int> FREE; // Node \u304C\u524A\
    \u9664\u6E08\u3067\u4F7F\u308F\u308C\u3066\u3044\u306A\u3044 index\n\n  // \u6587\
    \u5B57\u5217\u306E position \u3054\u3068\u306B\u6301\u3064\u3082\u306E\n  struct\
    \ T {\n    int c;\n    // \u305D\u306E\u6587\u5B57\u304B\u3089\u5DE6\u53F3\u306B\
    \u4F38\u3073\u308B\u6975\u5927\u56DE\u6587\u304C surface \u306A\u3089\u3070\u305D\
    \u306E node\n    // surface \u3067\u306A\u3044\u306A\u3089\u3070 EVEN\n    int\
    \ left_surface, right_surface;\n  };\n\n  int mod, mask;\n  vc<T> dat;\n  int\
    \ L = 0, R = 0; // global index range\n  int num_node = 0;\n\n  int new_node(int\
    \ par, int link, int length, int c = -1) {\n    ++num_node;\n    Node n;\n   \
    \ fill(all(n.TO), -1);\n    fill(all(n.direct_link), -1);\n    n.par = par, n.link\
    \ = link, n.length = length;\n    n.linkcnt = n.cnt = 0;\n    if (link != -1)\
    \ nodes[link].linkcnt += 1;\n    int p = 0;\n    if (FREE.empty()) {\n      p\
    \ = len(nodes);\n      nodes.eb(n);\n    } else {\n      p = POP(FREE);\n    \
    \  nodes[p] = n;\n    }\n    if (par != -1) nodes[par].TO[c] = p;\n    return\
    \ p;\n  }\n\n  void remove_node(int nid, int c) {\n    --num_node;\n    int pid\
    \ = nodes[nid].par;\n    assert(nodes[pid].TO[c] == nid);\n    nodes[pid].TO[c]\
    \ = -1;\n    int k = nodes[nid].link;\n    nodes[k].linkcnt -= 1;\n    if (nodes[k].linkcnt\
    \ == 0) FREE.eb(nid);\n  }\n\n  Double_Ended_Palindromic_Tree(int max_size) {\
    \ // odd, even\n    assert(ODD == new_node(-1, -1, -1));\n    assert(EVEN == new_node(-1,\
    \ 0, 0));\n    nodes[ODD].cnt = infty<int>, nodes[EVEN].cnt = infty<int>;\n  \
    \  mod = 4;\n    while (mod < max_size) mod *= 2;\n    dat.resize(mod);\n    mask\
    \ = mod - 1;\n  }\n\n  int suffix_node() {\n    return (L == R ? EVEN : dat[(R\
    \ - 1) & mask].left_surface);\n  }\n  int prefix_node() { return (L == R ? EVEN\
    \ : dat[L & mask].right_surface); }\n\n  void push_back(int c) {\n    assert(R\
    \ - L <= mask);\n    c -= offset;\n    int v = suffix_node();\n    dat[R & mask].c\
    \ = c;\n    // update palindromic tree, v <- nxt suffix node\n    v = [&]() ->\
    \ int {\n      auto dfs = [&](auto& dfs, int v) -> int {\n        // str(v)+c\
    \ \u306E longest suffix palindrome = c+str(w)+c\n        int& w = nodes[v].direct_link[c];\n\
    \        if (w != -1) { return w; }\n        int p = nodes[v].link;\n        int\
    \ j = R - 1 - nodes[p].length;\n        if (L <= j && j <= R && dat[j & mask].c\
    \ == c) { return w = p; }\n        return w = dfs(dfs, p);\n      };\n      //\
    \ \u3044\u307E\u306E\u30CE\u30FC\u30C9\u306B\u8DB3\u305B\u306A\u3044\u306A\u3089\
    \u623B\u308B\n      int j = R - 1 - nodes[v].length;\n      if (!(L <= j && j\
    \ <= R && dat[j & mask].c == c)) { v = dfs(dfs, v); }\n      // c+str(v)+c \u3092\
    \u4F5C\u308B\n      if (nodes[v].TO[c] != -1) { return nodes[v].TO[c]; }\n   \
    \   int link = (v == ODD ? EVEN : nodes[dfs(dfs, v)].TO[c]);\n      return new_node(v,\
    \ link, nodes[v].length + 2, c);\n    }();\n    dat[R & mask].right_surface =\
    \ EVEN;\n    dat[(R - nodes[v].length + 1) & mask].right_surface = v;\n    dat[R\
    \ & mask].left_surface = v;\n    int w = nodes[v].link;\n\n    int k = (R - nodes[v].length\
    \ + nodes[w].length);\n    if (nodes[w].length >= 1 && dat[k & mask].left_surface\
    \ == w) {\n      dat[k & mask].left_surface = EVEN;\n    }\n    ++R, nodes[v].cnt\
    \ += 1;\n  }\n\n  void pop_back() {\n    assert(L < R);\n    int v = suffix_node();\n\
    \    int w = nodes[v].link;\n    int k = R - 1 - nodes[v].length + nodes[w].length;\n\
    \    if (nodes[dat[k & mask].left_surface].length < nodes[w].length) {\n     \
    \ dat[k & mask].left_surface = w;\n      dat[(k - nodes[w].length + 1) & mask].right_surface\
    \ = w;\n    } else {\n      dat[(k - nodes[w].length + 1) & mask].right_surface\
    \ = EVEN;\n    }\n    nodes[v].cnt--;\n    if (nodes[v].linkcnt == 0 && nodes[v].cnt\
    \ == 0) {\n      remove_node(v, dat[(R - 1) & mask].c);\n    }\n    --R;\n  }\n\
    \n  void push_front(int c) {\n    assert(R - L <= mask);\n    c -= offset;\n \
    \   int v = prefix_node();\n    dat[(L - 1) & mask].c = c;\n    // update palindromic\
    \ tree, v <- nxt suffix node\n    v = [&]() -> int {\n      auto dfs = [&](auto&\
    \ dfs, int v) -> int {\n        // str(v)+c \u306E longest suffix palindrome =\
    \ c+str(w)+c\n        int& w = nodes[v].direct_link[c];\n        if (w != -1)\
    \ { return w; }\n        int p = nodes[v].link;\n        int j = L + nodes[p].length;\n\
    \        if (L - 1 <= j && j <= R - 1 && dat[j & mask].c == c) { return w = p;\
    \ }\n        return w = dfs(dfs, p);\n      };\n      // \u3044\u307E\u306E\u30CE\
    \u30FC\u30C9\u306B\u8DB3\u305B\u306A\u3044\u306A\u3089\u623B\u308B\n      int\
    \ j = L + nodes[v].length;\n      if (!(L - 1 <= j && j <= R - 1 && dat[j & mask].c\
    \ == c)) {\n        v = dfs(dfs, v);\n      }\n      // c+str(v)+c \u3092\u4F5C\
    \u308B\n      if (nodes[v].TO[c] != -1) { return nodes[v].TO[c]; }\n      int\
    \ link = (v == ODD ? EVEN : nodes[dfs(dfs, v)].TO[c]);\n      return new_node(v,\
    \ link, nodes[v].length + 2, c);\n    }();\n    dat[(L - 1) & mask].left_surface\
    \ = EVEN;\n    dat[(L - 2 + nodes[v].length) & mask].left_surface = v;\n    dat[(L\
    \ - 1) & mask].right_surface = v;\n    int w = nodes[v].link;\n\n    int k = ((L\
    \ - 1) + nodes[v].length - nodes[w].length);\n    if (nodes[w].length >= 1 &&\
    \ dat[k & mask].right_surface == w) {\n      dat[k & mask].right_surface = EVEN;\n\
    \    }\n    --L, nodes[v].cnt += 1;\n  }\n\n  void pop_front() {\n    assert(L\
    \ < R);\n    int v = prefix_node();\n    int w = nodes[v].link;\n    int k = L\
    \ + nodes[v].length - nodes[w].length;\n    if (nodes[dat[k & mask].right_surface].length\
    \ < nodes[w].length) {\n      dat[k & mask].right_surface = w;\n      dat[(k +\
    \ nodes[w].length - 1) & mask].left_surface = w;\n    } else {\n      dat[(k +\
    \ nodes[w].length - 1) & mask].left_surface = EVEN;\n    }\n    nodes[v].cnt--;\n\
    \    if (nodes[v].linkcnt == 0 && nodes[v].cnt == 0) {\n      remove_node(v, dat[L\
    \ & mask].c);\n    }\n    ++L;\n  }\n\n  int count_distinct_palindrome() { return\
    \ num_node - 2; }\n  int maximum_prefix_palindrome() { return nodes[prefix_node()].length;\
    \ }\n  int maximum_suffix_palindrome() { return nodes[suffix_node()].length; }\n\
    };\n"
  dependsOn: []
  isVerificationFile: false
  path: string/double_ended_palindromic_tree.hpp
  requiredBy: []
  timestamp: '2024-05-29 22:32:29+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/library_checker/string/palindromes_in_deque.test.cpp
documentation_of: string/double_ended_palindromic_tree.hpp
layout: document
redirect_from:
- /library/string/double_ended_palindromic_tree.hpp
- /library/string/double_ended_palindromic_tree.hpp.html
title: string/double_ended_palindromic_tree.hpp
---
