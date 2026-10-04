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
  code: "#include \"graph/tree.hpp\"\n#include \"ds/fastset.hpp\"\n#include \"graph/fast_lca.hpp\"\
    \n\ntemplate <typename TREE>\nstruct Compress_Tree {\n  FastSet FS;\n  TREE& tree;\n\
    \  Compress_Tree(TREE& tree) : tree(tree) {}\n\n  using GT = typename TREE::Graph_type;\n\
    \  using WT = typename GT::cost_type;\n\n  pair<vc<int>, GT> compress(vc<int>&\
    \ V, bool sorted = false) {\n    return compress_impl(\n        V, sorted, [&](int\
    \ a, int b) -> int { return tree.LCA(a, b); });\n  }\n\n  pair<vc<int>, GT> compress_fast(\n\
    \      vc<int>& V, Fast_LCA<TREE>& LCA, bool sorted = false) {\n    return compress_impl(\n\
    \        V, sorted, [&](int a, int b) -> int { return LCA.LCA(a, b); });\n  }\n\
    \n  void sort_vertices(vc<int>& V) {\n    int N = tree.N;\n    if (len(FS) ==\
    \ 0) FS.build(N);\n    for (int v : V) FS.insert(tree.LID[v]);\n    int k = 0;\n\
    \    FS.enumerate(0, N, [&](int i) -> void {\n      FS.erase(i);\n      V[k++]\
    \ = tree.V[i];\n    });\n    V.resize(k);\n  }\n\n  template <typename F>\n  pair<vc<int>,\
    \ GT> compress_impl(vc<int> V, bool sorted, F&& get_lca) {\n    assert(!V.empty());\n\
    \    if (!sorted) sort_vertices(V);\n    int n = len(V);\n    int root = get_lca(V[0],\
    \ V.back());\n    vc<int> key = move(V);\n    V.clear();\n    V.reserve(2 * n);\n\
    \n    // \u5727\u7E2E\u6728\u4E0A\u306E\u89AA\u756A\u53F7\n    vc<int> par;\n\
    \    par.reserve(2 * n);\n\n    auto add = [&](int v) -> int {\n      int k =\
    \ len(V);\n      V.eb(v), par.eb(-1);\n      return k;\n    };\n\n    add(root);\n\
    \    vc<int> st = {0};\n    st.reserve(2 * n);\n\n    for (int v : key) {\n  \
    \    if (v == root) continue;\n      int l = get_lca(V[st.back()], v);\n     \
    \ while (len(st) >= 2 && tree.depth[V[st[len(st) - 2]]] >= tree.depth[l]) {\n\
    \        int a = st[len(st) - 2];\n        int b = POP(st);\n        par[b] =\
    \ a;\n      }\n      if (V[st.back()] != l) {\n        int a = add(l);\n     \
    \   par[st.back()] = a;\n        st.back() = a;\n      }\n      st.eb(add(v));\n\
    \    }\n\n    while (len(st) >= 2) {\n      int a = st[len(st) - 2], b = POP(st);\n\
    \      par[b] = a;\n    }\n\n    GT G(len(V));\n    FOR(v, 1, len(V)) {\n    \
    \  int p = par[v];\n      WT d = tree.depth_weighted[V[v]] - tree.depth_weighted[V[p]];\n\
    \      G.add(p, v, d);\n    }\n    G.build();\n    return {move(V), move(G)};\n\
    \  }\n};"
  dependsOn: []
  isVerificationFile: false
  path: graph/compress_tree.hpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: graph/compress_tree.hpp
layout: document
redirect_from:
- /library/graph/compress_tree.hpp
- /library/graph/compress_tree.hpp.html
title: graph/compress_tree.hpp
---
