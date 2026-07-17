---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links:
    - https://qoj.ac/contest/1323/problem/7083
    - https://qoj.ac/problem/12010
  bundledCode: "#line 1 \"other/DFA.hpp\"\n// https://qoj.ac/contest/1323/problem/7083\n\
    struct DFA {\n  // state, alphabet, initial state\n  int n, sigma, q0;\n  vvc<int>\
    \ nxt;    // nxt[state][alphabet]\n  vc<int> output;  // \u5404\u72B6\u614B\u306B\
    \u5BFE\u5FDC\u3059\u308B\u51FA\u529B\u30E9\u30D9\u30EB\n\n  DFA() = default;\n\
    \n  DFA(int n, int sigma, int q0, vvc<int> nxt, vc<int> output)\n      : n(n),\
    \ sigma(sigma), q0(q0), nxt(nxt), output(output) {\n    assert(n >= 1);\n    assert(sigma\
    \ >= 1);\n    assert(0 <= q0 && q0 < n);\n    assert(len(nxt) == n);\n    assert(len(output)\
    \ == n);\n    FOR(q, n) {\n      assert(len(nxt[q]) == sigma);\n      FOR(c, sigma)\
    \ { assert(0 <= nxt[q][c] && nxt[q][c] < n); }\n    }\n  }\n\n  int calc(const\
    \ vc<int>& word) const {\n    int q = q0;\n    for (int c : word) {\n      assert(0\
    \ <= c && c < sigma);\n      q = nxt[q][c];\n    }\n    return output[q];\n  }\n\
    \n  // Hopcroft minimization.\n  DFA minimize_DFA() const {\n    vvv(int, rev,\
    \ sigma, n, 0);\n    FOR(u, n) FOR(c, sigma) { rev[c][nxt[u][c]].eb(u); }\n\n\
    \    map<int, vc<int>> mp;\n    FOR(q, n) mp[output[q]].eb(q);\n\n    vvc<int>\
    \ block;\n    vc<int> cls(n, -1);\n    for (auto& [_, V] : mp) {\n      int id\
    \ = len(block);\n      for (int q : V) cls[q] = id;\n      block.eb(V);\n    }\n\
    \n    // Hopcroft refinement.\n    vc<int> que;\n\n    FOR(b, len(block) - 1)\
    \ que.eb(b);\n\n    vc<bool> vis(n);\n    vc<int> cnt(len(block), 0);\n\n    vc<int>\
    \ V, B;\n    while (!que.empty()) {\n      int b = POP(que);\n      vc<int> A\
    \ = block[b];\n\n      FOR(c, sigma) {\n        V.clear(), B.clear();\n      \
    \  for (int v : A) {\n          for (int u : rev[c][v]) {\n            if (vis[u])\
    \ continue;\n            vis[u] = 1, V.eb(u);\n            int b = cls[u];\n \
    \           if (cnt[b] == 0) B.eb(b);\n            cnt[b]++;\n          }\n  \
    \      }\n\n        for (int b : B) {\n          int x = cnt[b];\n          int\
    \ sz = len(block[b]);\n          if (x == sz) {\n            continue;\n     \
    \     }\n          // split b\n          vc<int> X, Y;\n          X.reserve(x),\
    \ Y.reserve(sz - x);\n\n          for (int q : block[b]) {\n            (vis[q]\
    \ ? X : Y).eb(q);\n          }\n          if (len(X) < len(Y)) swap(X, Y);\n\n\
    \          block[b] = move(X);\n\n          int nb = len(block);\n          for\
    \ (int q : Y) cls[q] = nb;\n          block.eb(move(Y));\n\n          cnt.eb(0),\
    \ que.eb(nb);\n        }\n        for (int b : B) cnt[b] = 0;\n        for (int\
    \ u : V) vis[u] = 0;\n      }\n    }\n\n    int M = len(block);\n    vvc<int>\
    \ new_nxt(M, vc<int>(sigma));\n    vc<int> new_output(M);\n\n    FOR(b, M) {\n\
    \      int rep = block[b][0];\n      new_output[b] = output[rep];\n      FOR(c,\
    \ sigma) { new_nxt[b][c] = cls[nxt[rep][c]]; }\n    }\n\n    int new_q0 = cls[q0];\n\
    \    return DFA(M, sigma, new_q0, new_nxt, new_output);\n  }\n};\n\n// https://qoj.ac/problem/12010\n\
    // out[0], ..., out[A+B+1]\n// |out[i]|=sigma^i, \u8F9E\u66F8\u9806\u306B\u3059\
    \u3079\u3066\u306E\u7D50\u679C\u3092\u5165\u308C\u3066\u304A\u304F\n// A, B \u304C\
    \u63A8\u6E2C\u306E\u305F\u3081\u306B\u7528\u3044\u308B\u9577\u3055\nDFA infer_DFA(int\
    \ sigma, int A, int B, const vvc<int>& out, bool check = true) {\n  vc<int> pw(A\
    \ + B + 2, 1);\n  FOR(i, len(pw) - 1) pw[i + 1] = pw[i] * sigma;\n\n  assert(len(out)\
    \ == A + B + 2);\n  FOR(i, A + B + 2) assert(len(out[i]) == pw[i]);\n\n  vc<pair<int,\
    \ int>> prefix, test;\n\n  FOR(n, A + 1) {\n    FOR(code, pw[n]) { prefix.eb(n,\
    \ code); }\n  }\n\n  FOR(n, B + 1) {\n    FOR(code, pw[n]) { test.eb(n, code);\
    \ }\n  }\n\n  vc<u64> hash_base(len(test));\n  FOR(i, len(test)) { hash_base[i]\
    \ = RNG_64(); }\n\n  auto fingerprint = [&](int lx, u64 x) -> u64 {\n    u64 h\
    \ = 0;\n    FOR(i, len(test)) {\n      auto [lt, t] = test[i];\n      int y =\
    \ out[lx + lt][x * pw[lt] + t];\n      h += hash_base[i] * u64(y + 1);\n    }\n\
    \    return h;\n  };\n\n  map<u64, int> id;\n  vc<pair<int, u64>> rep;\n\n  auto\
    \ get_state = [&](u64 h) -> int {\n    auto it = id.find(h);\n    if (it != id.end())\
    \ return it->se;\n    int s = len(rep);\n    id[h] = s;\n    rep.eb(-1, 0);\n\
    \    return s;\n  };\n\n  for (auto [lx, x] : prefix) {\n    u64 h = fingerprint(lx,\
    \ x);\n    int s = get_state(h);\n    if (rep[s].fi == -1) rep[s] = {lx, x};\n\
    \  }\n\n  int N = len(rep);\n  vvc<int> nxt(N, vc<int>(sigma, -1));\n  vc<int>\
    \ output(N);\n\n  FOR(s, N) {\n    auto [lx, x] = rep[s];\n    output[s] = out[lx][x];\n\
    \    FOR(c, sigma) {\n      int ly = lx + 1;\n      u64 y = x * u64(sigma) + u64(c);\n\
    \      u64 h = fingerprint(ly, y);\n      if (!id.count(h)) {\n        print(\"\
    A is too small\");\n        assert(false);\n      }\n      nxt[s][c] = id[h];\n\
    \    }\n  }\n\n  int q0 = id[fingerprint(0, 0)];\n\n  DFA X(N, sigma, q0, nxt,\
    \ output);\n  X = X.minimize_DFA();\n\n  vc<int> word;\n  auto dfs = [&](auto&\
    \ dfs, u64 k) -> void {\n    if (X.calc(word) != out[len(word)][k]) {\n      print(\"\
    failed\");\n      assert(0);\n    }\n    if (len(word) == A + B + 1) return;\n\
    \    FOR(i, sigma) {\n      word.eb(i);\n      dfs(dfs, k * sigma + i);\n    \
    \  word.pop_back();\n    }\n  };\n  if (check) dfs(dfs, 0);\n  return X;\n}\n"
  code: "// https://qoj.ac/contest/1323/problem/7083\nstruct DFA {\n  // state, alphabet,\
    \ initial state\n  int n, sigma, q0;\n  vvc<int> nxt;    // nxt[state][alphabet]\n\
    \  vc<int> output;  // \u5404\u72B6\u614B\u306B\u5BFE\u5FDC\u3059\u308B\u51FA\u529B\
    \u30E9\u30D9\u30EB\n\n  DFA() = default;\n\n  DFA(int n, int sigma, int q0, vvc<int>\
    \ nxt, vc<int> output)\n      : n(n), sigma(sigma), q0(q0), nxt(nxt), output(output)\
    \ {\n    assert(n >= 1);\n    assert(sigma >= 1);\n    assert(0 <= q0 && q0 <\
    \ n);\n    assert(len(nxt) == n);\n    assert(len(output) == n);\n    FOR(q, n)\
    \ {\n      assert(len(nxt[q]) == sigma);\n      FOR(c, sigma) { assert(0 <= nxt[q][c]\
    \ && nxt[q][c] < n); }\n    }\n  }\n\n  int calc(const vc<int>& word) const {\n\
    \    int q = q0;\n    for (int c : word) {\n      assert(0 <= c && c < sigma);\n\
    \      q = nxt[q][c];\n    }\n    return output[q];\n  }\n\n  // Hopcroft minimization.\n\
    \  DFA minimize_DFA() const {\n    vvv(int, rev, sigma, n, 0);\n    FOR(u, n)\
    \ FOR(c, sigma) { rev[c][nxt[u][c]].eb(u); }\n\n    map<int, vc<int>> mp;\n  \
    \  FOR(q, n) mp[output[q]].eb(q);\n\n    vvc<int> block;\n    vc<int> cls(n, -1);\n\
    \    for (auto& [_, V] : mp) {\n      int id = len(block);\n      for (int q :\
    \ V) cls[q] = id;\n      block.eb(V);\n    }\n\n    // Hopcroft refinement.\n\
    \    vc<int> que;\n\n    FOR(b, len(block) - 1) que.eb(b);\n\n    vc<bool> vis(n);\n\
    \    vc<int> cnt(len(block), 0);\n\n    vc<int> V, B;\n    while (!que.empty())\
    \ {\n      int b = POP(que);\n      vc<int> A = block[b];\n\n      FOR(c, sigma)\
    \ {\n        V.clear(), B.clear();\n        for (int v : A) {\n          for (int\
    \ u : rev[c][v]) {\n            if (vis[u]) continue;\n            vis[u] = 1,\
    \ V.eb(u);\n            int b = cls[u];\n            if (cnt[b] == 0) B.eb(b);\n\
    \            cnt[b]++;\n          }\n        }\n\n        for (int b : B) {\n\
    \          int x = cnt[b];\n          int sz = len(block[b]);\n          if (x\
    \ == sz) {\n            continue;\n          }\n          // split b\n       \
    \   vc<int> X, Y;\n          X.reserve(x), Y.reserve(sz - x);\n\n          for\
    \ (int q : block[b]) {\n            (vis[q] ? X : Y).eb(q);\n          }\n   \
    \       if (len(X) < len(Y)) swap(X, Y);\n\n          block[b] = move(X);\n\n\
    \          int nb = len(block);\n          for (int q : Y) cls[q] = nb;\n    \
    \      block.eb(move(Y));\n\n          cnt.eb(0), que.eb(nb);\n        }\n   \
    \     for (int b : B) cnt[b] = 0;\n        for (int u : V) vis[u] = 0;\n     \
    \ }\n    }\n\n    int M = len(block);\n    vvc<int> new_nxt(M, vc<int>(sigma));\n\
    \    vc<int> new_output(M);\n\n    FOR(b, M) {\n      int rep = block[b][0];\n\
    \      new_output[b] = output[rep];\n      FOR(c, sigma) { new_nxt[b][c] = cls[nxt[rep][c]];\
    \ }\n    }\n\n    int new_q0 = cls[q0];\n    return DFA(M, sigma, new_q0, new_nxt,\
    \ new_output);\n  }\n};\n\n// https://qoj.ac/problem/12010\n// out[0], ..., out[A+B+1]\n\
    // |out[i]|=sigma^i, \u8F9E\u66F8\u9806\u306B\u3059\u3079\u3066\u306E\u7D50\u679C\
    \u3092\u5165\u308C\u3066\u304A\u304F\n// A, B \u304C\u63A8\u6E2C\u306E\u305F\u3081\
    \u306B\u7528\u3044\u308B\u9577\u3055\nDFA infer_DFA(int sigma, int A, int B, const\
    \ vvc<int>& out, bool check = true) {\n  vc<int> pw(A + B + 2, 1);\n  FOR(i, len(pw)\
    \ - 1) pw[i + 1] = pw[i] * sigma;\n\n  assert(len(out) == A + B + 2);\n  FOR(i,\
    \ A + B + 2) assert(len(out[i]) == pw[i]);\n\n  vc<pair<int, int>> prefix, test;\n\
    \n  FOR(n, A + 1) {\n    FOR(code, pw[n]) { prefix.eb(n, code); }\n  }\n\n  FOR(n,\
    \ B + 1) {\n    FOR(code, pw[n]) { test.eb(n, code); }\n  }\n\n  vc<u64> hash_base(len(test));\n\
    \  FOR(i, len(test)) { hash_base[i] = RNG_64(); }\n\n  auto fingerprint = [&](int\
    \ lx, u64 x) -> u64 {\n    u64 h = 0;\n    FOR(i, len(test)) {\n      auto [lt,\
    \ t] = test[i];\n      int y = out[lx + lt][x * pw[lt] + t];\n      h += hash_base[i]\
    \ * u64(y + 1);\n    }\n    return h;\n  };\n\n  map<u64, int> id;\n  vc<pair<int,\
    \ u64>> rep;\n\n  auto get_state = [&](u64 h) -> int {\n    auto it = id.find(h);\n\
    \    if (it != id.end()) return it->se;\n    int s = len(rep);\n    id[h] = s;\n\
    \    rep.eb(-1, 0);\n    return s;\n  };\n\n  for (auto [lx, x] : prefix) {\n\
    \    u64 h = fingerprint(lx, x);\n    int s = get_state(h);\n    if (rep[s].fi\
    \ == -1) rep[s] = {lx, x};\n  }\n\n  int N = len(rep);\n  vvc<int> nxt(N, vc<int>(sigma,\
    \ -1));\n  vc<int> output(N);\n\n  FOR(s, N) {\n    auto [lx, x] = rep[s];\n \
    \   output[s] = out[lx][x];\n    FOR(c, sigma) {\n      int ly = lx + 1;\n   \
    \   u64 y = x * u64(sigma) + u64(c);\n      u64 h = fingerprint(ly, y);\n    \
    \  if (!id.count(h)) {\n        print(\"A is too small\");\n        assert(false);\n\
    \      }\n      nxt[s][c] = id[h];\n    }\n  }\n\n  int q0 = id[fingerprint(0,\
    \ 0)];\n\n  DFA X(N, sigma, q0, nxt, output);\n  X = X.minimize_DFA();\n\n  vc<int>\
    \ word;\n  auto dfs = [&](auto& dfs, u64 k) -> void {\n    if (X.calc(word) !=\
    \ out[len(word)][k]) {\n      print(\"failed\");\n      assert(0);\n    }\n  \
    \  if (len(word) == A + B + 1) return;\n    FOR(i, sigma) {\n      word.eb(i);\n\
    \      dfs(dfs, k * sigma + i);\n      word.pop_back();\n    }\n  };\n  if (check)\
    \ dfs(dfs, 0);\n  return X;\n}"
  dependsOn: []
  isVerificationFile: false
  path: other/DFA.hpp
  requiredBy: []
  timestamp: '2026-07-18 00:22:18+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: other/DFA.hpp
layout: document
redirect_from:
- /library/other/DFA.hpp
- /library/other/DFA.hpp.html
title: other/DFA.hpp
---
