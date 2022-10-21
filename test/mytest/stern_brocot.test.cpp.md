---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes: {}
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.10.8/x64/lib/python3.10/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.10.8/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.10.8/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.10.8/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: other/random.hpp:\
    \ line -1: no such header\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/aplusb\"\n#include \"my_template.hpp\"\
    \n#include \"other/io.hpp\"\n#include \"other/random.hpp\"\n#include \"nt/stern_brocot_tree.hpp\"\
    \n\nvoid test() {\n  using SBT = Stern_Brocot_Tree;\n  // get_path\n  assert(SBT::get_path({1,\
    \ 1}) == vi());\n  assert(SBT::get_path({1, 2}) == vi({0, 1}));\n  assert(SBT::get_path({2,\
    \ 1}) == vi({1}));\n  assert(SBT::get_path({1, 3}) == vi({0, 2}));\n  assert(SBT::get_path({2,\
    \ 3}) == vi({0, 1, 1}));\n  assert(SBT::get_path({3, 2}) == vi({1, 1}));\n  assert(SBT::get_path({3,\
    \ 1}) == vi({2}));\n  assert(SBT::get_path({1, 4}) == vi({0, 3}));\n  assert(SBT::get_path({2,\
    \ 5}) == vi({0, 2, 1}));\n  assert(SBT::get_path({3, 5}) == vi({0, 1, 1, 1}));\n\
    \  assert(SBT::get_path({3, 4}) == vi({0, 1, 2}));\n  assert(SBT::get_path({4,\
    \ 3}) == vi({1, 2}));\n  assert(SBT::get_path({5, 3}) == vi({1, 1, 1}));\n  assert(SBT::get_path({5,\
    \ 2}) == vi({2, 1}));\n  assert(SBT::get_path({4, 1}) == vi({3}));\n  // range\n\
    \  assert(SBT::range({1, 1}) == mp(pi{0, 1}, pi{1, 0}));\n  assert(SBT::range({1,\
    \ 2}) == mp(pi{0, 1}, pi{1, 1}));\n  assert(SBT::range({2, 1}) == mp(pi{1, 1},\
    \ pi{1, 0}));\n  assert(SBT::range({1, 3}) == mp(pi{0, 1}, pi{1, 2}));\n  assert(SBT::range({2,\
    \ 3}) == mp(pi{1, 2}, pi{1, 1}));\n  assert(SBT::range({3, 2}) == mp(pi{1, 1},\
    \ pi{2, 1}));\n  assert(SBT::range({3, 1}) == mp(pi{2, 1}, pi{1, 0}));\n  assert(SBT::range({1,\
    \ 4}) == mp(pi{0, 1}, pi{1, 3}));\n  assert(SBT::range({2, 5}) == mp(pi{1, 3},\
    \ pi{1, 2}));\n  assert(SBT::range({3, 5}) == mp(pi{1, 2}, pi{2, 3}));\n  assert(SBT::range({3,\
    \ 4}) == mp(pi{2, 3}, pi{1, 1}));\n  assert(SBT::range({4, 3}) == mp(pi{1, 1},\
    \ pi{3, 2}));\n  assert(SBT::range({5, 3}) == mp(pi{3, 2}, pi{2, 1}));\n  assert(SBT::range({5,\
    \ 2}) == mp(pi{2, 1}, pi{3, 1}));\n  assert(SBT::range({4, 1}) == mp(pi{3, 1},\
    \ pi{1, 0}));\n  // child\n  assert(SBT::child({1, 1}) == mp(pi{1, 2}, pi{2, 1}));\n\
    \  assert(SBT::child({1, 2}) == mp(pi{1, 3}, pi{2, 3}));\n  assert(SBT::child({2,\
    \ 1}) == mp(pi{3, 2}, pi{3, 1}));\n  assert(SBT::child({1, 3}) == mp(pi{1, 4},\
    \ pi{2, 5}));\n  assert(SBT::child({2, 3}) == mp(pi{3, 5}, pi{3, 4}));\n  assert(SBT::child({3,\
    \ 2}) == mp(pi{4, 3}, pi{5, 3}));\n  assert(SBT::child({3, 1}) == mp(pi{5, 2},\
    \ pi{4, 1}));\n  // la\n  pi NG = {-1, -1};\n  assert(SBT::LA({1, 1}, 0) == pi({1,\
    \ 1}));\n  assert(SBT::LA({1, 1}, 1) == NG);\n  assert(SBT::LA({3, 4}, 0) == pi({1,\
    \ 1}));\n  assert(SBT::LA({3, 4}, 1) == pi({1, 2}));\n  assert(SBT::LA({3, 4},\
    \ 2) == pi({2, 3}));\n  assert(SBT::LA({3, 4}, 3) == pi({3, 4}));\n  assert(SBT::LA({3,\
    \ 4}, 4) == NG);\n  assert(SBT::LA({3, 5}, 0) == pi({1, 1}));\n  assert(SBT::LA({3,\
    \ 5}, 1) == pi({1, 2}));\n  assert(SBT::LA({3, 5}, 2) == pi({2, 3}));\n  assert(SBT::LA({3,\
    \ 5}, 3) == pi({3, 5}));\n  assert(SBT::LA({3, 5}, 4) == NG);\n\n  auto get_random\
    \ = [&]() -> pi {\n    while (1) {\n      ll x = RNG(1, 1LL << 60);\n      ll\
    \ y = RNG(1, 1LL << 60);\n      if (gcd(x, y) > 1) continue;\n      return {x,\
    \ y};\n    }\n  };\n\n  FOR(10000) {\n    pi x = get_random();\n    auto [l, r]\
    \ = SBT::range(x);\n    assert(i128(x.fi) * l.se - i128(x.se) * l.fi == 1);\n\
    \    assert(i128(r.fi) * x.se - i128(r.se) * x.fi == 1);\n    assert(l.fi + r.fi\
    \ == x.fi && l.se + r.se == x.se);\n    tie(l, r) = SBT::child(x);\n    assert(i128(x.fi)\
    \ * l.se - i128(x.se) * l.fi == 1);\n    assert(i128(r.fi) * x.se - i128(r.se)\
    \ * x.fi == 1);\n    auto P = SBT::get_path(x);\n    assert(SBT::from_path<ll>(P)\
    \ == x);\n    pi y = get_random();\n    pi z = SBT::LCA(x, y);\n    assert(SBT::in_subtree(x,\
    \ z));\n    assert(SBT::in_subtree(y, z));\n    tie(l, r) = SBT::child(z);\n \
    \   assert(!SBT::in_subtree(x, l) || !SBT::in_subtree(y, l));\n    assert(!SBT::in_subtree(x,\
    \ r) || !SBT::in_subtree(y, r));\n  }\n}\n\nvoid solve() {\n  LL(a, b);\n  print(a\
    \ + b);\n}\n\nsigned main() {\n  test();\n  solve();\n\n  return 0;\n}"
  dependsOn: []
  isVerificationFile: true
  path: test/mytest/stern_brocot.test.cpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/mytest/stern_brocot.test.cpp
layout: document
redirect_from:
- /verify/test/mytest/stern_brocot.test.cpp
- /verify/test/mytest/stern_brocot.test.cpp.html
title: test/mytest/stern_brocot.test.cpp
---
