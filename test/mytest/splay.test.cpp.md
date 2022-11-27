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
    \                ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n \
    \ File \"/opt/hostedtoolcache/Python/3.11.0/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: alg/group/affine.hpp:\
    \ line -1: no such header\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/aplusb\"\n#include \"my_template.hpp\"\
    \n#include \"other/io.hpp\"\n#include \"alg/group/affine.hpp\"\n#include \"mod/modint.hpp\"\
    \n#include \"random/base.hpp\"\n#include \"ds/bbst/splaytree_monoid.hpp\"\n\n\
    void test() {\n  // reverse, set, prod \u306E\u52D5\u4F5C\u3092\u78BA\u8A8D\n\
    \  using mint = modint998;\n  using Mono = Group_Affine<mint>;\n  using X = Mono::value_type;\n\
    \  SplayTree_Monoid<Mono> ST;\n\n  auto rnd_X = [&]() -> X {\n    ll a = RNG(0,\
    \ 1 << 30);\n    ll b = RNG(0, 1 << 30);\n    return {mint(a), mint(b)};\n  };\n\
    \  auto get_lr = [&](int N) -> pi {\n    int l = RNG(0, N);\n    int r = RNG(0,\
    \ N);\n    if (l > r) swap(l, r);\n    ++r;\n    return {l, r};\n  };\n\n  FOR(N,\
    \ 1, 10) {\n    ST.reset();\n\n    vc<X> A(N);\n    FOR(i, N) { A[i] = rnd_X();\
    \ }\n\n    auto root = ST.new_node(A);\n    FOR(100) {\n      int t = RNG(0, 3);\n\
    \      if (t == 0) {\n        // set\n        int i = RNG(0, N);\n        X x\
    \ = rnd_X();\n        A[i] = x;\n        ST.set(root, i, x);\n      }\n      if\
    \ (t == 1) {\n        // reverse\n        auto [l, r] = get_lr(N);\n        reverse(A.begin()\
    \ + l, A.begin() + r);\n        ST.reverse(root, l, r);\n      }\n      if (t\
    \ == 2) {\n        // prod\n        auto [l, r] = get_lr(N);\n        X a = Mono::unit();\n\
    \        FOR(i, l, r) a = Mono::op(a, A[i]);\n        X b = ST.prod(root, l, r);\n\
    \        assert(a == b);\n      }\n    }\n  }\n}\n\nvoid solve() {\n  LL(a, b);\n\
    \  print(a + b);\n}\n\nsigned main() {\n  cout << fixed << setprecision(15);\n\
    \n  test();\n\n  ll T = 1;\n  FOR(T) solve();\n\n  return 0;\n}\n"
  dependsOn: []
  isVerificationFile: true
  path: test/mytest/splay.test.cpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/mytest/splay.test.cpp
layout: document
redirect_from:
- /verify/test/mytest/splay.test.cpp
- /verify/test/mytest/splay.test.cpp.html
title: test/mytest/splay.test.cpp
---
