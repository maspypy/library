---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: mod/barret.hpp
    title: mod/barret.hpp
  - icon: ':question:'
    path: mod/mod_inv.hpp
    title: mod/mod_inv.hpp
  - icon: ':question:'
    path: mod/modint.hpp
    title: mod/modint.hpp
  - icon: ':question:'
    path: mod/modint_common.hpp
    title: mod/modint_common.hpp
  - icon: ':question:'
    path: poly/convolution.hpp
    title: poly/convolution.hpp
  - icon: ':question:'
    path: poly/convolution_naive.hpp
    title: poly/convolution_naive.hpp
  - icon: ':question:'
    path: poly/fft.hpp
    title: poly/fft.hpp
  - icon: ':question:'
    path: poly/ntt.hpp
    title: poly/ntt.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test_atcoder/agc058d.test.cpp
    title: test_atcoder/agc058d.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links:
    - https://atcoder.jp/contests/agc058/tasks/agc058_d
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.11.3/x64/lib/python3.11/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n          \
    \         ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \  File \"/opt/hostedtoolcache/Python/3.11.3/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.11.3/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.11.3/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.11.3/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 312, in update\n    raise BundleErrorAt(path, i + 1, \"#pragma once found\
    \ in a non-first line\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ poly/ntt.hpp: line 2: #pragma once found in a non-first line\n"
  code: "#include \"poly/convolution.hpp\"\n\n/*\n[x^N] F(x,y)/G(x,y) \u306E\u8A08\
    \u7B97\u3002\u7D50\u679C\u306F y \u306E\u591A\u9805\u5F0F\u3002\n[x^0] G = 1 \u3092\
    \u4EEE\u5B9A\u3057\u3066\u3044\u308B\u3002\ndeg G = (3, 1) \u306E N = 3\xD710^6\
    \ \u3067 500 ms \u306E\u5B9F\u7E3E\u304C\u3042\u308B\u304C\u3001\u304B\u306A\u308A\
    \u758E\u3060\u304B\u3089\u304B\u3082\u3002\nhttps://atcoder.jp/contests/agc058/tasks/agc058_d\n\
    */\ntemplate <typename mint>\nvc<mint> coef_of_rational_fps_2d(vector<vector<mint>>\
    \ F, vector<vector<mint>> G,\n                                 int N) {\n  using\
    \ poly = vc<mint>;\n\n  // x^N mod reverse(G) \u3092\u8A08\u7B97\u3059\u308B\n\
    \  int m = len(G) - 1;\n\n  auto add_at = [&](poly& f, int i, mint x) -> void\
    \ {\n    if (len(f) <= i) f.resize(i + 1);\n    f[i] += x;\n  };\n\n  auto simplify\
    \ = [&](poly& f) -> void {\n    while (len(f) && f.back() == mint(0)) f.pop_back();\n\
    \  };\n\n  auto dfs = [&](auto& dfs, int n) -> vc<poly> {\n    if (n == 0) { return\
    \ {poly({mint(1)})}; }\n    vc<poly> f = dfs(dfs, n / 2);\n    // 2 \u4E57\u3057\
    \u305F\u3044\n    int nf = 0;\n    FOR(i, len(f)) chmax(nf, len(f[i]));\n    int\
    \ K = 1;\n    while (K < 2 * nf) K *= 2;\n    FOR(i, len(f)) {\n      f[i].resize(K);\n\
    \      ntt(f[i], 0);\n    }\n    vc<poly> g(2 * len(f) - 1);\n    FOR(i, 2 * len(f)\
    \ - 1) g[i].resize(K);\n    FOR(i, len(f)) FOR(j, len(f)) {\n      FOR(k, K) g[i\
    \ + j][k] += f[i][k] * f[j][k];\n    }\n    FOR(i, len(g)) ntt(g[i], 1);\n   \
    \ swap(f, g);\n\n    if (n % 2 == 1) { f.insert(f.begin(), poly({})); }\n    FOR_R(i,\
    \ m, len(f)) {\n      FOR(j, 1, m + 1) {\n        FOR(ny, len(G[j])) {\n     \
    \     mint cf = -G[j][ny];\n          if (cf == mint(0)) continue;\n         \
    \ FOR(k, len(f[i])) {\n            mint& x = f[i][k];\n            if (x == mint(0))\
    \ continue;\n            add_at(f[i - j], k + ny, cf * x);\n          }\n    \
    \    }\n      }\n    }\n    f.resize(m);\n    FOR(i, m) simplify(f[i]);\n    return\
    \ f;\n  };\n\n  vc<poly> h = dfs(dfs, N);\n  // \u7DDA\u5F62\u6F38\u5316\u5F0F\
    \u306E\u6700\u521D\u306E\u65B9\u3092\u6C42\u3081\u308B\n  vc<poly> A(m);\n  FOR(i,\
    \ m) {\n    A[i] = (i < len(F) ? F[i] : poly());\n    FOR(j, 1, i + 1) {\n   \
    \   int k = i - j;\n      poly tmp = convolution(A[k], G[j]);\n      FOR(t, len(tmp))\
    \ { add_at(A[i], t, -tmp[t]); }\n    }\n  }\n\n  vc<mint> res;\n  FOR(i, m) {\n\
    \    vc<mint> f = convolution(h[i], A[i]);\n    FOR(i, len(f)) add_at(res, i,\
    \ f[i]);\n  }\n  return res;\n}\n"
  dependsOn:
  - poly/convolution.hpp
  - mod/modint.hpp
  - mod/modint_common.hpp
  - mod/mod_inv.hpp
  - poly/convolution_naive.hpp
  - poly/ntt.hpp
  - mod/barret.hpp
  - poly/fft.hpp
  isVerificationFile: false
  path: poly/coef_of_rational_fps_2d.hpp
  requiredBy: []
  timestamp: '2023-04-27 03:47:30+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test_atcoder/agc058d.test.cpp
documentation_of: poly/coef_of_rational_fps_2d.hpp
layout: document
redirect_from:
- /library/poly/coef_of_rational_fps_2d.hpp
- /library/poly/coef_of_rational_fps_2d.hpp.html
title: poly/coef_of_rational_fps_2d.hpp
---
