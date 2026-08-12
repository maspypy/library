---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"template/prefix_state_segtree.hpp\"\n// template/prefix_state_segtree.hpp\n\
    /*\nprefix state \u3092\u6301\u3061\u306A\u304C\u3089\u5DE6\u304B\u3089\u5217\u3092\
    \u8AAD\u3080\u30BF\u30A4\u30D7\u306E SegTree \u306E\u9AA8\u683C\nStateMonoid:\n\
    \  prefix state \u306E\u30E2\u30CE\u30A4\u30C9\n  init state \u304C\u5358\u4F4D\
    \u5143\u3067\u3001\u533A\u9593\u3092\u901A\u3063\u305F\u3068\u304D\u306E state\
    \ \u304C\u30E2\u30CE\u30A4\u30C9\u306E\u7DCF\u7A4D\u3067\u3042\u308B\u3068\u3059\
    \u308B\n\nAnswerMonoid:\n  \u8AAD\u3093\u3067\u3044\u308B\u9014\u4E2D\u3067\u5F97\
    \u3089\u308C\u308B\u7B54\u3048\u306E\u30E2\u30CE\u30A4\u30C9\n\n\u5185\u90E8\u30CE\
    \u30FC\u30C9 v=left+right \u306B\u306F\n  dat[v].state: \u533A\u9593 v \u3092\
    \ init state \u304B\u3089\u5168\u90E8\u8AAD\u3093\u3060\u3068\u304D\u306E finish\
    \ state\n  dat[v].r_ans:\n    prefix state \u304C dat[left].state \u306E\u72B6\
    \u614B\u304B\u3089 right \u3092\u8AAD\u3093\u3060\u3068\u304D\u306E\u7B54\u3048\
    \n\n\n\u6B21\u306E\u5B9F\u88C5\u306F problem specific \u3067\u3042\u308B\n\ndfs(v,\
    \ s):\n  prefix state \u304C s \u306E\u72B6\u614B\u304B\u3089\u533A\u9593 v \u3092\
    \u8AAD\u3093\u3060\u3068\u304D\u306E\u7B54\u3048\u3092\u5F97\u308B\n\n\u5404\u9AD8\
    \u3055\u3067\u9AD8\u3005\u7247\u65B9\u306E\u5B50\u306B\u3057\u304B\u518D\u5E30\
    \u3057\u306A\u3044\u3088\u3046\u306B\u66F8\u3051\u3070\nupdate, query : O(log^2\
    \ n)\n*/\ntemplate <typename StateMonoid, typename AnswerMonoid>\nstruct Prefix_State_SegTree\
    \ {\n  using MS = StateMonoid;\n  using MX = AnswerMonoid;\n  using S = typename\
    \ MS::value_type;\n  using X = typename MX::value_type;\n\n  struct Data {\n \
    \   S state;\n    X r_ans;\n  };\n\n  int n, size, log;\n  vc<Data> dat;\n\n \
    \ Prefix_State_SegTree() {}\n\n  template <typename F>\n  Prefix_State_SegTree(int\
    \ n, F f) {\n    build(n, f);\n  }\n\n  template <typename F>\n  void build(int\
    \ m, F f) {\n    n = m, log = 0;\n    while ((1 << log) < n) ++log;\n    size\
    \ = 1 << log;\n\n    dat.assign(2 * size, {MS::unit(), MX::unit()});\n    FOR(i,\
    \ n) dat[size + i].state = f(i);\n    FOR_R(i, 1, size) update(i);\n  }\n\n  void\
    \ set(int i, S s) {\n    i += size;\n    dat[i] = {s, MX::unit()};\n    while\
    \ (i > 1) i /= 2, update(i);\n  }\n\n  // prefix state = s \u304B\u3089 [L,R)\
    \ \u3092\u8AAD\u3093\u3060\u3068\u304D\u306E finish state, ANS\n  pair<S, X> prod(int\
    \ L, int R, S s = MS::unit()) {\n    vc<int> suff;\n    X ans = MX::unit();\n\n\
    \    L += size, R += size;\n    while (L < R) {\n      if (L & 1) {\n        dfs(L,\
    \ s, ans);\n        s = MS::op(s, dat[L].state);\n        ++L;\n      }\n    \
    \  if (R & 1) suff.eb(--R);\n      L /= 2, R /= 2;\n    }\n\n    reverse(all(suff));\n\
    \    for (int v : suff) {\n      dfs(v, s, ans);\n      s = MS::op(s, dat[v].state);\n\
    \    }\n    return {s, ans};\n  }\n\n private:\n  void update(int v) {\n    auto&\
    \ L = dat[2 * v];\n    auto& R = dat[2 * v + 1];\n    dat[v].state = MS::op(L.state,\
    \ R.state);\n    dat[v].r_ans = dfs(2 * v + 1, L.state);\n  }\n\n  // prefix state\
    \ = s \u304B\u3089 subtree v \u3092\u8AAD\u3093\u3060\u3068\u304D\u306E\u7B54\u3048\
    \n  X dfs(int v, S s) {\n    // TODO: problem specific\n    /* typically:\n  \
    \  auto& L = dat[2 * v];\n    auto& R = dat[2 * v + 1];\n    if (left \u3092\u98DB\
    \u3070\u305B\u308B) {\n      s = MS::op(s, L.state);\n      return dfs(2 * v +\
    \ 1, s);\n    } else {\n      return MX::op(dfs(2 * v, s), dat[v].r_ans);\n  \
    \  }\n    */\n  }\n};\n"
  code: "// template/prefix_state_segtree.hpp\n/*\nprefix state \u3092\u6301\u3061\
    \u306A\u304C\u3089\u5DE6\u304B\u3089\u5217\u3092\u8AAD\u3080\u30BF\u30A4\u30D7\
    \u306E SegTree \u306E\u9AA8\u683C\nStateMonoid:\n  prefix state \u306E\u30E2\u30CE\
    \u30A4\u30C9\n  init state \u304C\u5358\u4F4D\u5143\u3067\u3001\u533A\u9593\u3092\
    \u901A\u3063\u305F\u3068\u304D\u306E state \u304C\u30E2\u30CE\u30A4\u30C9\u306E\
    \u7DCF\u7A4D\u3067\u3042\u308B\u3068\u3059\u308B\n\nAnswerMonoid:\n  \u8AAD\u3093\
    \u3067\u3044\u308B\u9014\u4E2D\u3067\u5F97\u3089\u308C\u308B\u7B54\u3048\u306E\
    \u30E2\u30CE\u30A4\u30C9\n\n\u5185\u90E8\u30CE\u30FC\u30C9 v=left+right \u306B\
    \u306F\n  dat[v].state: \u533A\u9593 v \u3092 init state \u304B\u3089\u5168\u90E8\
    \u8AAD\u3093\u3060\u3068\u304D\u306E finish state\n  dat[v].r_ans:\n    prefix\
    \ state \u304C dat[left].state \u306E\u72B6\u614B\u304B\u3089 right \u3092\u8AAD\
    \u3093\u3060\u3068\u304D\u306E\u7B54\u3048\n\n\n\u6B21\u306E\u5B9F\u88C5\u306F\
    \ problem specific \u3067\u3042\u308B\n\ndfs(v, s):\n  prefix state \u304C s \u306E\
    \u72B6\u614B\u304B\u3089\u533A\u9593 v \u3092\u8AAD\u3093\u3060\u3068\u304D\u306E\
    \u7B54\u3048\u3092\u5F97\u308B\n\n\u5404\u9AD8\u3055\u3067\u9AD8\u3005\u7247\u65B9\
    \u306E\u5B50\u306B\u3057\u304B\u518D\u5E30\u3057\u306A\u3044\u3088\u3046\u306B\
    \u66F8\u3051\u3070\nupdate, query : O(log^2 n)\n*/\ntemplate <typename StateMonoid,\
    \ typename AnswerMonoid>\nstruct Prefix_State_SegTree {\n  using MS = StateMonoid;\n\
    \  using MX = AnswerMonoid;\n  using S = typename MS::value_type;\n  using X =\
    \ typename MX::value_type;\n\n  struct Data {\n    S state;\n    X r_ans;\n  };\n\
    \n  int n, size, log;\n  vc<Data> dat;\n\n  Prefix_State_SegTree() {}\n\n  template\
    \ <typename F>\n  Prefix_State_SegTree(int n, F f) {\n    build(n, f);\n  }\n\n\
    \  template <typename F>\n  void build(int m, F f) {\n    n = m, log = 0;\n  \
    \  while ((1 << log) < n) ++log;\n    size = 1 << log;\n\n    dat.assign(2 * size,\
    \ {MS::unit(), MX::unit()});\n    FOR(i, n) dat[size + i].state = f(i);\n    FOR_R(i,\
    \ 1, size) update(i);\n  }\n\n  void set(int i, S s) {\n    i += size;\n    dat[i]\
    \ = {s, MX::unit()};\n    while (i > 1) i /= 2, update(i);\n  }\n\n  // prefix\
    \ state = s \u304B\u3089 [L,R) \u3092\u8AAD\u3093\u3060\u3068\u304D\u306E finish\
    \ state, ANS\n  pair<S, X> prod(int L, int R, S s = MS::unit()) {\n    vc<int>\
    \ suff;\n    X ans = MX::unit();\n\n    L += size, R += size;\n    while (L <\
    \ R) {\n      if (L & 1) {\n        dfs(L, s, ans);\n        s = MS::op(s, dat[L].state);\n\
    \        ++L;\n      }\n      if (R & 1) suff.eb(--R);\n      L /= 2, R /= 2;\n\
    \    }\n\n    reverse(all(suff));\n    for (int v : suff) {\n      dfs(v, s, ans);\n\
    \      s = MS::op(s, dat[v].state);\n    }\n    return {s, ans};\n  }\n\n private:\n\
    \  void update(int v) {\n    auto& L = dat[2 * v];\n    auto& R = dat[2 * v +\
    \ 1];\n    dat[v].state = MS::op(L.state, R.state);\n    dat[v].r_ans = dfs(2\
    \ * v + 1, L.state);\n  }\n\n  // prefix state = s \u304B\u3089 subtree v \u3092\
    \u8AAD\u3093\u3060\u3068\u304D\u306E\u7B54\u3048\n  X dfs(int v, S s) {\n    //\
    \ TODO: problem specific\n    /* typically:\n    auto& L = dat[2 * v];\n    auto&\
    \ R = dat[2 * v + 1];\n    if (left \u3092\u98DB\u3070\u305B\u308B) {\n      s\
    \ = MS::op(s, L.state);\n      return dfs(2 * v + 1, s);\n    } else {\n     \
    \ return MX::op(dfs(2 * v, s), dat[v].r_ans);\n    }\n    */\n  }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: template/prefix_state_segtree.hpp
  requiredBy: []
  timestamp: '2026-08-12 15:20:42+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: template/prefix_state_segtree.hpp
layout: document
redirect_from:
- /library/template/prefix_state_segtree.hpp
- /library/template/prefix_state_segtree.hpp.html
title: template/prefix_state_segtree.hpp
---
