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
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.11.2/x64/lib/python3.11/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n          \
    \         ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \  File \"/opt/hostedtoolcache/Python/3.11.2/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.11.2/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \                ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n \
    \ File \"/opt/hostedtoolcache/Python/3.11.2/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: graph/tree_dp.hpp:\
    \ line -1: no such header\n"
  code: "#include \"mod/modint61.hpp\"\n#include \"graph/base.hpp\"\n#include \"graph/tree.hpp\"\
    \n#include \"random/base.hpp\"\n#include \"graph/tree_dp.hpp\"\n\ntemplate <typename\
    \ TREE>\nvc<ll> classify_subtree(TREE& tree) {\n  using mint = modint61;\n  static\
    \ vc<mint> hash_base;\n  auto get = [&](int k) -> mint {\n    while (len(hash_base)\
    \ <= k) hash_base.eb(RNG(mint::get_mod()));\n    return hash_base[k];\n  };\n\
    \  int N = tree.G.N;\n  using T = pair<int, mint>;\n  T unit = {0, mint(1)};\n\
    \n  auto f_ee = [&](T A, T B) -> T { return {max(A.fi, B.fi), A.se * B.se}; };\n\
    \  auto f_ev = [&](T A, int v) -> T { return {A.fi + 1, A.se}; };\n  auto f_ve\
    \ = [&](T A, const auto& e) -> T { return {A.fi, A.se + get(A.fi)}; };\n\n  auto\
    \ dp = tree_dp<decltype(tree), T>(tree, f_ee, f_ev, f_ve, unit);\n  vc<ll> res(N);\n\
    \  FOR(v, N) res[v] = dp[v].se.val;\n  return res;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: graph/classify_subtree.hpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: graph/classify_subtree.hpp
layout: document
redirect_from:
- /library/graph/classify_subtree.hpp
- /library/graph/classify_subtree.hpp.html
title: graph/classify_subtree.hpp
---
