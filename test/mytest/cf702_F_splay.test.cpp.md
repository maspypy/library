---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes: {}
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.11.0/x64/lib/python3.11/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n          \
    \         ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \  File \"/opt/hostedtoolcache/Python/3.11.0/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.11.0/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.11.0/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \                ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n \
    \ File \"/opt/hostedtoolcache/Python/3.11.0/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: ds/splay/splaytree.hpp:\
    \ line -1: no such header\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/aplusb\"\n#include \"my_template.hpp\"\
    \n#include \"other/io.hpp\"\n#include \"alg/monoid/add_pair.hpp\"\n#include \"\
    ds/splaytree/splaytree_acted_set.hpp\"\n\n// (\u6240\u6301\u91D1, \u64CD\u4F5C\
    \u56DE\u6570, query index)\nstruct AS {\n  using Monoid_A = Monoid_Add_Pair<int>;\n\
    \  using A = Monoid_A::value_type;\n  using S = tuple<int, int, int>;\n  static\
    \ S act(const S& s, const A& x) {\n    auto [a, b, c] = s;\n    return {a + x.fi,\
    \ b + x.se, c};\n  }\n};\n\nvc<int> solve_cf702F(vc<pair<int, int>> CQ, vc<int>\
    \ query) {\n  const int Q = len(query);\n  sort(all(CQ), [&](auto& a, auto& b)\
    \ -> bool {\n    if (a.se != b.se) return a.se > b.se;\n    return a.fi < b.fi;\n\
    \  });\n  using T = tuple<int, int, int>;\n  vc<T> dat(Q);\n  FOR(q, Q) {\n  \
    \  int x = query[q];\n    dat[q] = {x, 0, q};\n  }\n  sort(all(dat));\n\n  const\
    \ int MAX = 500'000;\n\n  SplayTree_ActedSet<AS, MAX> X;\n  using np = decltype(X)::np;\n\
    \  using S = typename AS::S;\n  np root = X.new_node(dat);\n\n  FOR(i, len(CQ))\
    \ {\n    ll c = CQ[i].fi;\n    np nm, nr;\n    tie(root, nr)\n        = X.split_max_right(root,\
    \ [&](S& s) { return get<0>(s) < c; });\n    X.apply(nr, {-c, 1});\n    tie(nm,\
    \ nr) = X.split_max_right(nr, [&](S& s) { return get<0>(s) < c; });\n    for (auto&&\
    \ [aa, bb, cc]: X.get_all(nm)) assert(aa < c);\n    for (auto&& [aa, bb, cc]:\
    \ X.get_all(nr)) assert(aa >= c);\n    for (auto [val, cnt, idx]: X.get_all(nm))\
    \ {\n      ll t = val;\n      auto [l_root, r_root]\n          = X.split_max_right(root,\
    \ [&](S& s) { return get<0>(s) < t; });\n      root = X.merge(l_root, X.new_node({val,\
    \ cnt, idx}));\n      root = X.merge(root, r_root);\n    }\n    root = X.merge(root,\
    \ nr);\n  }\n  vc<int> ANS(Q);\n  for (auto [val, cnt, idx]: X.get_all(root))\
    \ { ANS[idx] = cnt; }\n  return ANS;\n}\n\nvoid test_1() {\n  vc<pair<int, int>>\
    \ CQ;\n  CQ.eb(7, 5);\n  CQ.eb(3, 5);\n  CQ.eb(4, 3);\n  vc<int> query = {13,\
    \ 14};\n  vc<int> ANS = solve_cf702F(CQ, query);\n  assert(ANS == vc<int>({2,\
    \ 3}));\n}\n\nvoid test_2() {\n  vc<pair<int, int>> CQ;\n  CQ.eb(100, 500);\n\
    \  CQ.eb(50, 499);\n  vc<int> query = {50, 200, 150, 100};\n  vc<int> ANS = solve_cf702F(CQ,\
    \ query);\n  assert(ANS == vc<int>({1, 2, 2, 1}));\n}\n\nvoid solve() {\n  LL(a,\
    \ b);\n  print(a + b);\n}\n\nsigned main() {\n  cin.tie(nullptr);\n  ios::sync_with_stdio(false);\n\
    \  cout << setprecision(15);\n  test_1();\n  test_2();\n  solve();\n\n  return\
    \ 0;\n}\n"
  dependsOn: []
  isVerificationFile: true
  path: test/mytest/cf702_F_splay.test.cpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/mytest/cf702_F_splay.test.cpp
layout: document
redirect_from:
- /verify/test/mytest/cf702_F_splay.test.cpp
- /verify/test/mytest/cf702_F_splay.test.cpp.html
title: test/mytest/cf702_F_splay.test.cpp
---
