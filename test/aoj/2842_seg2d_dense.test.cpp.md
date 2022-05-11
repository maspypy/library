---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: alg/group_add.hpp
    title: alg/group_add.hpp
  - icon: ':x:'
    path: ds/segtree2d_dense.hpp
    title: ds/segtree2d_dense.hpp
  - icon: ':question:'
    path: my_template.hpp
    title: my_template.hpp
  - icon: ':question:'
    path: other/io.hpp
    title: other/io.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2842
    links:
    - https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2842
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.10.4/x64/lib/python3.10/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.10.4/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.10.4/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.10.4/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 312, in update\n    raise BundleErrorAt(path, i + 1, \"#pragma once found\
    \ in a non-first line\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ ds/segtree2d_dense.hpp: line 2: #pragma once found in a non-first line\n"
  code: "#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2842\"\
    \n#include \"my_template.hpp\"\n#include \"other/io.hpp\"\n#include \"ds/segtree2d_dense.hpp\"\
    \n#include \"alg/group_add.hpp\"\n\nvoid solve() {\n  LL(H, W, T, Q);\n  deque<tuple<ll,\
    \ ll, ll>> que;\n  const ll INF = 1LL << 60;\n  vv(ll, time, H, W, INF);\n\n \
    \ SegTree2D_dense<Group_Add<ll>> A(H, W);\n  SegTree2D_dense<Group_Add<ll>> B(H,\
    \ W);\n\n  deque<tuple<ll, ll, ll>> end;\n\n  FOR_(Q) {\n    LL(t, c, x, y);\n\
    \    --x, --y;\n    while (len(end) && get<2>(end.front()) <= t) {\n      auto\
    \ [x, y, t] = end.front();\n      end.pop_front();\n      A.set(x, y, 1);\n  \
    \    B.set(x, y, 0);\n    }\n    if (c == 0) {\n      B.set(x, y, 1);\n      end.eb(x,\
    \ y, t + T);\n    }\n    elif (c == 1) {\n      if (A.prod(x, y, x + 1, y + 1))\
    \ A.set(x, y, 0);\n    }\n    elif (c == 2) {\n      LL(x2, y2);\n      print(A.prod(x,\
    \ y, x2, y2), B.prod(x, y, x2, y2));\n    }\n  }\n}\n\nsigned main() {\n  cin.tie(nullptr);\n\
    \  ios::sync_with_stdio(false);\n  cout << setprecision(15);\n\n  ll T = 1;\n\
    \  // LL(T);\n  FOR(_, T) solve();\n\n  return 0;\n}"
  dependsOn:
  - my_template.hpp
  - other/io.hpp
  - ds/segtree2d_dense.hpp
  - alg/group_add.hpp
  isVerificationFile: true
  path: test/aoj/2842_seg2d_dense.test.cpp
  requiredBy: []
  timestamp: '2022-05-11 19:22:25+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/aoj/2842_seg2d_dense.test.cpp
layout: document
redirect_from:
- /verify/test/aoj/2842_seg2d_dense.test.cpp
- /verify/test/aoj/2842_seg2d_dense.test.cpp.html
title: test/aoj/2842_seg2d_dense.test.cpp
---
