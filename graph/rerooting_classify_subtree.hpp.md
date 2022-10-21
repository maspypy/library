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
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.10.8/x64/lib/python3.10/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.10.8/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.10.8/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.10.8/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: other/random.hpp:\
    \ line -1: no such header\n"
  code: "#include \"mod/modint61.hpp\"\n#include \"graph/base.hpp\"\n#include \"graph/tree.hpp\"\
    \n#include \"other/random.hpp\"\n#include \"graph/rerooting_dp.hpp\"\n\ntemplate\
    \ <typename TREE>\nstruct Rerooting_classify_subtree {\n  using mint = modint61;\n\
    \  TREE& tree;\n  vc<ll> dp, dp_1, dp_2;\n\n  Rerooting_classify_subtree(TREE&\
    \ tree) : tree(tree) {\n    int N = tree.G.N;\n    using T = pair<int, mint>;\n\
    \    T unit = {0, mint(1)};\n\n    auto f_ee = [&](T A, T B) -> T { return {max(A.fi,\
    \ B.fi), A.se * B.se}; };\n    auto f_ev = [&](T A, int v) -> T { return {A.fi\
    \ + 1, A.se}; };\n    auto f_ve = [&](T A, const auto& e) -> T {\n      return\
    \ {A.fi, A.se + hash_base(A.fi)};\n    };\n\n    Rerooting_dp<decltype(tree),\
    \ T> DP(tree, f_ee, f_ev, f_ve, unit);\n    dp.resize(N), dp_1.resize(N), dp_2.resize(N);\n\
    \    FOR(v, N) dp[v] = DP.dp[v].se.val;\n    FOR(v, N) dp_1[v] = DP.dp_1[v].se.val;\n\
    \    FOR(v, N) dp_2[v] = DP.dp_2[v].se.val;\n  }\n\n  // v \u3092\u6839\u3068\u3057\
    \u305F\u3068\u304D\u306E full tree\n  ll operator[](int v) { return dp[v]; }\n\
    \n  // root \u3092\u6839\u3068\u3057\u305F\u3068\u304D\u306E\u90E8\u5206\u6728\
    \ v\n  ll get(int root, int v) {\n    if (root == v) return dp[v];\n    if (!tree.in_subtree(root,\
    \ v)) { return dp_1[v]; }\n    int w = tree.jump(v, root);\n    return dp_2[w];\n\
    \  }\n\n  static mint hash_base(int k) {\n    static vc<mint> dat;\n    while\
    \ (len(dat) <= k) dat.eb(RNG(mint::get_mod()));\n    return dat[k];\n  }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: graph/rerooting_classify_subtree.hpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: graph/rerooting_classify_subtree.hpp
layout: document
redirect_from:
- /library/graph/rerooting_classify_subtree.hpp
- /library/graph/rerooting_classify_subtree.hpp.html
title: graph/rerooting_classify_subtree.hpp
---
