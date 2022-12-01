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
    \  File \"/opt/hostedtoolcache/Python/3.11.0/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \                ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n \
    \ File \"/opt/hostedtoolcache/Python/3.11.0/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: ds/disjointsparse.hpp:\
    \ line -1: no such header\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/aplusb\"\n\n#include \"\
    my_template.hpp\"\n#include \"other/io.hpp\"\n\n#include \"string/suffix_tree.hpp\"\
    \n\n/*\nS = aabbabbaa\n\nsuffix array\na--------\naa-------\naabbabbaa\nabbaa----\n\
    abbabbaa-\nbaa------\nbabbaa---\nbbaa-----\nbbabbaa--\n\nsuffix tree \u306E node\
    \ \u306F\u3053\u306E\u9577\u65B9\u5F62\u9818\u57DF\u3092\u8868\u3059\n1--------\n\
    12-------\n123333333\n14445----\n14446666-\n789------\n780000---\n7112-----\n\
    7113-----\n*/\nvoid test() {\n  string S = \"aabbabbaa\";\n  SuffixArray X(S);\n\
    \  auto [G, dat] = suffix_tree(X);\n  using T = tuple<int, int, int, int>;\n \
    \ auto check_dat = [&](T t, int xl, int yl, int xr, int yr) -> void {\n    auto\
    \ [a, b, c, d] = t;\n    assert(a == xl && b == yl && c == xr && d == yr);\n \
    \ };\n  auto check_edge = [&](auto e, int frm, int to) -> void {\n    assert(e.frm\
    \ == frm && e.to == to);\n  };\n  check_dat(dat[0], 0, 0, 9, 0);\n  check_dat(dat[1],\
    \ 0, 0, 5, 1);\n  check_dat(dat[2], 1, 1, 3, 2);\n  check_dat(dat[3], 2, 2, 3,\
    \ 9);\n  check_dat(dat[4], 3, 1, 5, 4);\n  check_dat(dat[5], 3, 4, 4, 5);\n  check_dat(dat[6],\
    \ 4, 4, 5, 8);\n  check_dat(dat[7], 5, 0, 9, 1);\n  check_dat(dat[8], 5, 1, 7,\
    \ 2);\n  check_dat(dat[9], 5, 2, 6, 3);\n  check_dat(dat[10], 6, 2, 7, 6);\n \
    \ check_dat(dat[11], 7, 1, 9, 3);\n  check_dat(dat[12], 7, 3, 8, 4);\n  check_dat(dat[13],\
    \ 8, 3, 9, 7);\n  check_edge(G.edges[0], 0, 1);\n  check_edge(G.edges[1], 1, 2);\n\
    \  check_edge(G.edges[2], 2, 3);\n  check_edge(G.edges[3], 1, 4);\n  check_edge(G.edges[4],\
    \ 4, 5);\n  check_edge(G.edges[5], 4, 6);\n  check_edge(G.edges[6], 0, 7);\n \
    \ check_edge(G.edges[7], 7, 8);\n  check_edge(G.edges[8], 8, 9);\n  check_edge(G.edges[9],\
    \ 8, 10);\n  check_edge(G.edges[10], 7, 11);\n  check_edge(G.edges[11], 11, 12);\n\
    \  check_edge(G.edges[12], 11, 13);\n}\n\nvoid solve() {\n  LL(a, b);\n  print(a\
    \ + b);\n}\n\nsigned main() {\n  cin.tie(nullptr);\n  ios::sync_with_stdio(false);\n\
    \  cout << setprecision(15);\n\n  test();\n\n  ll T = 1;\n  FOR(T) solve();\n\n\
    \  return 0;\n}"
  dependsOn: []
  isVerificationFile: true
  path: test/mytest/suffix_tree.test.cpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/mytest/suffix_tree.test.cpp
layout: document
redirect_from:
- /verify/test/mytest/suffix_tree.test.cpp
- /verify/test/mytest/suffix_tree.test.cpp.html
title: test/mytest/suffix_tree.test.cpp
---
