---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: alg/monoid/add_pair.hpp
    title: alg/monoid/add_pair.hpp
  - icon: ':heavy_check_mark:'
    path: ds/node_pool.hpp
    title: ds/node_pool.hpp
  - icon: ':heavy_check_mark:'
    path: ds/splaytree/splaytree.hpp
    title: ds/splaytree/splaytree.hpp
  - icon: ':heavy_check_mark:'
    path: ds/splaytree/splaytree_acted_set.hpp
    title: ds/splaytree/splaytree_acted_set.hpp
  - icon: ':heavy_check_mark:'
    path: my_template.hpp
    title: my_template.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/aplusb
    links:
    - https://judge.yosupo.jp/problem/aplusb
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.13.7/x64/lib/python3.13/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n          \
    \         ~~~~~~~~~~~~~~~^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \  File \"/opt/hostedtoolcache/Python/3.13.7/x64/lib/python3.13/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n    ~~~~~~~~~~~~~~^^^^^^\n  File\
    \ \"/opt/hostedtoolcache/Python/3.13.7/x64/lib/python3.13/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \    ~~~~~~~~~~~^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \  File \"/opt/hostedtoolcache/Python/3.13.7/x64/lib/python3.13/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \    ~~~~~~~~~~~^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \  File \"/opt/hostedtoolcache/Python/3.13.7/x64/lib/python3.13/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 312, in update\n    raise BundleErrorAt(path, i + 1, \"#pragma once found\
    \ in a non-first line\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ ds/splaytree/splaytree.hpp: line 3: #pragma once found in a non-first line\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/aplusb\"\n#include \"my_template.hpp\"\
    \n#include \"alg/monoid/add_pair.hpp\"\n#include \"ds/splaytree/splaytree_acted_set.hpp\"\
    \n\n// (\u6240\u6301\u91D1, \u64CD\u4F5C\u56DE\u6570, query index)\nstruct AS\
    \ {\n  using Monoid_A = Monoid_Add_Pair<int>;\n  using A = Monoid_A::value_type;\n\
    \  using S = tuple<int, int, int>;\n  static S act(const S& s, const A& x) {\n\
    \    auto [a, b, c] = s;\n    return {a + x.fi, b + x.se, c};\n  }\n};\n\nvc<int>\
    \ solve_cf702F(vc<pair<int, int>> CQ, vc<int> query) {\n  const int Q = len(query);\n\
    \  sort(all(CQ), [&](auto& a, auto& b) -> bool {\n    if (a.se != b.se) return\
    \ a.se > b.se;\n    return a.fi < b.fi;\n  });\n  using T = tuple<int, int, int>;\n\
    \  vc<T> dat(Q);\n  FOR(q, Q) {\n    int x = query[q];\n    dat[q] = {x, 0, q};\n\
    \  }\n  sort(all(dat));\n\n  const int MAX = 500'000;\n\n  SplayTree_ActedSet<AS>\
    \ X(MAX);\n  using np = decltype(X)::np;\n  using S = typename AS::S;\n  np root\
    \ = X.new_node(dat);\n\n  FOR(i, len(CQ)) {\n    ll c = CQ[i].fi;\n    np nm,\
    \ nr;\n    tie(root, nr) = X.split_max_right(root, [&](S& s) { return get<0>(s)\
    \ < c; });\n    X.apply(nr, {-c, 1});\n    tie(nm, nr) = X.split_max_right(nr,\
    \ [&](S& s) { return get<0>(s) < c; });\n    for (auto&& [aa, bb, cc]: X.get_all(nm))\
    \ assert(aa < c);\n    for (auto&& [aa, bb, cc]: X.get_all(nr)) assert(aa >= c);\n\
    \    for (auto [val, cnt, idx]: X.get_all(nm)) {\n      ll t = val;\n      auto\
    \ [l_root, r_root] = X.split_max_right(root, [&](S& s) { return get<0>(s) < t;\
    \ });\n      root = X.merge(l_root, X.new_node({val, cnt, idx}));\n      root\
    \ = X.merge(root, r_root);\n    }\n    root = X.merge(root, nr);\n  }\n  vc<int>\
    \ ANS(Q);\n  for (auto [val, cnt, idx]: X.get_all(root)) { ANS[idx] = cnt; }\n\
    \  return ANS;\n}\n\nvoid test_1() {\n  vc<pair<int, int>> CQ;\n  CQ.eb(7, 5);\n\
    \  CQ.eb(3, 5);\n  CQ.eb(4, 3);\n  vc<int> query = {13, 14};\n  vc<int> ANS =\
    \ solve_cf702F(CQ, query);\n  assert(ANS == vc<int>({2, 3}));\n}\n\nvoid test_2()\
    \ {\n  vc<pair<int, int>> CQ;\n  CQ.eb(100, 500);\n  CQ.eb(50, 499);\n  vc<int>\
    \ query = {50, 200, 150, 100};\n  vc<int> ANS = solve_cf702F(CQ, query);\n  assert(ANS\
    \ == vc<int>({1, 2, 2, 1}));\n}\n\nvoid solve() {\n  int a, b;\n  cin >> a >>\
    \ b;\n  cout << a + b << \"\\n\";\n}\n\nsigned main() {\n  test_1();\n  test_2();\n\
    \  solve();\n\n  return 0;\n}\n"
  dependsOn:
  - my_template.hpp
  - alg/monoid/add_pair.hpp
  - ds/splaytree/splaytree_acted_set.hpp
  - ds/splaytree/splaytree.hpp
  - ds/node_pool.hpp
  isVerificationFile: true
  path: test/1_mytest/cf702_F_splay.test.cpp
  requiredBy: []
  timestamp: '2025-09-16 13:47:23+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/1_mytest/cf702_F_splay.test.cpp
layout: document
redirect_from:
- /verify/test/1_mytest/cf702_F_splay.test.cpp
- /verify/test/1_mytest/cf702_F_splay.test.cpp.html
title: test/1_mytest/cf702_F_splay.test.cpp
---
