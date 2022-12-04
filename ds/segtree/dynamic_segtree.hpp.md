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
    - https://judge.yosupo.jp/problem/double_ended_priority_queue
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.11.0/x64/lib/python3.11/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n          \
    \         ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \  File \"/opt/hostedtoolcache/Python/3.11.0/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.11.0/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.11.0/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.11.0/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 269, in update\n    raise BundleErrorAt(path, -1, \"cycle found in inclusion\
    \ relations\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: ds/segtree/dynamic_segtree.hpp:\
    \ line -1: cycle found in inclusion relations\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/double_ended_priority_queue\"\
    \r\n\r\n#include \"my_template.hpp\"\r\n#include \"other/io.hpp\"\r\n#include\
    \ \"ds/segtree/dynamic_segtree.hpp\"\r\n#include \"alg/monoid/add.hpp\"\r\n\r\n\
    void solve() {\r\n  // \u52D5\u7684\u30BB\u30B0\u6728\u3067\u306E\u4E8C\u5206\u63A2\
    \u7D22\r\n  LL(N, Q);\r\n  VEC(int, A, N);\r\n  const int LIM = 1'000'000'000;\r\
    \n\r\n  Dynamic_SegTree<Monoid_Add<int>, false, 30'000'000> seg(-LIM, LIM + 1);\r\
    \n  auto root = seg.new_node(-LIM, LIM + 1);\r\n  for (auto&& a: A) root = seg.multiply(root,\
    \ a, 1);\r\n\r\n  FOR(Q) {\r\n    LL(t);\r\n    if (t == 0) {\r\n      LL(x);\r\
    \n      seg.multiply(root, x, 1);\r\n    }\r\n    if (t == 1) {\r\n      auto\
    \ check = [&](auto e) -> bool { return e == 0; };\r\n      int ANS = seg.max_right(root,\
    \ check, -LIM);\r\n      print(ANS);\r\n      root = seg.multiply(root, ANS, -1);\r\
    \n    }\r\n    if (t == 2) {\r\n      auto check = [&](auto e) -> bool { return\
    \ e == 0; };\r\n      int ANS = seg.min_left(root, check, LIM + 1) - 1;\r\n  \
    \    print(ANS);\r\n      root = seg.multiply(root, ANS, -1);\r\n    }\r\n  }\r\
    \n}\r\n\r\nsigned main() {\r\n  solve();\r\n\r\n  return 0;\r\n}\r\n"
  dependsOn: []
  isVerificationFile: false
  path: ds/segtree/dynamic_segtree.hpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: ds/segtree/dynamic_segtree.hpp
layout: document
redirect_from:
- /library/ds/segtree/dynamic_segtree.hpp
- /library/ds/segtree/dynamic_segtree.hpp.html
title: ds/segtree/dynamic_segtree.hpp
---
