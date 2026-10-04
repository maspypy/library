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
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.12.14/x64/lib/python3.12/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n          \
    \         ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \  File \"/opt/hostedtoolcache/Python/3.12.14/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.12.14/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.12.14/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \                ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n \
    \ File \"/opt/hostedtoolcache/Python/3.12.14/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: other/bit.hpp:\
    \ line -1: no such header\n"
  code: "\n#include \"graph/tree.hpp\"\n#include \"string/trie.hpp\"\n#include \"\
    ds/fastset.hpp\"\n#include \"ds/csr.hpp\"\n\n// T[i] distinct \u304C\u5FC5\u8981\
    \n// T[i] \u304C S \u306B\u73FE\u308C\u308B\u4F4D\u7F6E\u3092\u6607\u9806\u5217\
    \u6319\n// call f(i, vc<int>&pos)\n// O(T + Slog^2S + Ssqrt(T))\ntemplate <typename\
    \ STRING, int SIGMA = 26, int off = 'a', typename F>\nvoid enumerate_occurrences(STRING\
    \ S, vc<STRING> T, F f) {\n  Trie<SIGMA> trie;\n  FOR(i, len(T)) trie.add(T[i],\
    \ off);\n  trie.calc_suffix_link();\n\n  int n = trie.n_node;\n  Graph<int, 1>\
    \ G(n);\n  FOR(i, 1, n) G.add(trie.nodes[i].suffix_link, i);\n  G.build();\n \
    \ Tree<decltype(G)> tree(G);\n\n  vc<int> TID(n, -1);\n  FOR(i, len(T)) { TID[trie.words[i]]\
    \ = i; }\n  CSR<int> csr(n);\n  {\n    int v = 0;\n    FOR(i, len(S)) {\n    \
    \  v = trie.nodes[v].nxt[S[i] - off];\n      csr.add(v, i);\n    }\n  }\n  csr.build();\n\
    \n  FastSet FS(len(S));\n  vc<int> nxt(len(S));\n  vc<int> pos;\n  auto dfs =\
    \ [&](auto& dfs, int h) -> void {\n    auto path = tree.heavy_path_at(h);\n  \
    \  for (auto& v : path) {\n      for (auto& e : G[v]) {\n        if (tree.head[e.to]\
    \ != h) dfs(dfs, e.to);\n      }\n    }\n\n    FS.reset();\n    auto ins = [&](int\
    \ i) -> void {\n      int a = FS.prev(i), b = FS.next(i);\n      if (a != -1)\
    \ nxt[a] = i;\n      nxt[i] = b;\n      FS.insert(i);\n    };\n    auto ins_v\
    \ = [&](int v) -> void {\n      for (int i : csr[v]) ins(i);\n    };\n\n    int\
    \ prv = -1;\n    FOR_R(k, len(path)) {\n      int v = path[k];\n      ins_v(v);\n\
    \      int L = 0, R = 0;\n      if (prv != -1) L = tree.RID[prv], R = tree.RID[v];\n\
    \      FOR(i, L, R) ins_v(tree.V[i]);\n      prv = v;\n\n      int t = TID[v];\n\
    \      if (t != -1) {\n        int M = len(T[t]);\n        pos.clear();\n    \
    \    for (int i = FS.next(0); i < len(S); i = nxt[i]) {\n          // [i-M+1,i]\n\
    \          pos.eb(i - M + 1);\n        }\n        f(t, pos);\n      }\n    }\n\
    \  };\n  dfs(dfs, 0);\n}"
  dependsOn: []
  isVerificationFile: false
  path: string/enumerate_occurrences.hpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: string/enumerate_occurrences.hpp
layout: document
redirect_from:
- /library/string/enumerate_occurrences.hpp
- /library/string/enumerate_occurrences.hpp.html
title: string/enumerate_occurrences.hpp
---
