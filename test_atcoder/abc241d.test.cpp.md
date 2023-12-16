---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes: {}
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.12.1/x64/lib/python3.12/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n          \
    \         ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \  File \"/opt/hostedtoolcache/Python/3.12.1/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.12.1/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \                ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n \
    \ File \"/opt/hostedtoolcache/Python/3.12.1/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: ds/my_multiset.hpp:\
    \ line -1: no such header\n"
  code: "#define PROBLEM \"https://atcoder.jp/contests/abc241/tasks/abc241_d\"\n\n\
    #include \"my_template.hpp\"\n#include \"other/io.hpp\"\n\n#include \"ds/my_multiset.hpp\"\
    \n\nvoid solve() {\n  LL(Q);\n  My_Multiset<200100> X;\n  auto c = X.new_root();\n\
    \  FOR(Q) {\n    LL(t);\n    if (t == 1) {\n      LL(x);\n      c = X.add(c, x);\n\
    \    }\n    if (t == 2) {\n      LL(x, k);\n      auto [cnt, sm] = X.get_range(c,\
    \ -infty<ll>, x + 1);\n      if (cnt < k) {\n        print(-1);\n      } else\
    \ {\n        ll ans = X.prefix_kth(c, cnt - k).fi;\n        print(ans);\n    \
    \  }\n    }\n    if (t == 3) {\n      LL(x, k);\n      auto [cnt, sm] = X.get_range(c,\
    \ x, infty<ll>);\n      if (cnt < k) {\n        print(-1);\n      } else {\n \
    \       ll ans = X.suffix_kth(c, cnt - k).fi;\n        print(ans);\n      }\n\
    \    }\n  }\n}\n\nsigned main() {\n  solve();\n  return 0;\n}\n"
  dependsOn: []
  isVerificationFile: true
  path: test_atcoder/abc241d.test.cpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test_atcoder/abc241d.test.cpp
layout: document
redirect_from:
- /verify/test_atcoder/abc241d.test.cpp
- /verify/test_atcoder/abc241d.test.cpp.html
title: test_atcoder/abc241d.test.cpp
---
