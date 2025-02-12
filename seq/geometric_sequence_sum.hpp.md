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
    - https://judge.yosupo.jp/problem/aplusb
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.13.2/x64/lib/python3.13/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n          \
    \         ~~~~~~~~~~~~~~~^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \  File \"/opt/hostedtoolcache/Python/3.13.2/x64/lib/python3.13/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n    ~~~~~~~~~~~~~~^^^^^^\n  File\
    \ \"/opt/hostedtoolcache/Python/3.13.2/x64/lib/python3.13/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \    ~~~~~~~~~~~^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \  File \"/opt/hostedtoolcache/Python/3.13.2/x64/lib/python3.13/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \    ~~~~~~~~~~~^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \  File \"/opt/hostedtoolcache/Python/3.13.2/x64/lib/python3.13/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 269, in update\n    raise BundleErrorAt(path, -1, \"cycle found in inclusion\
    \ relations\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: seq/geometric_sequence_sum.hpp:\
    \ line -1: cycle found in inclusion relations\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/aplusb\"\n#include \"my_template.hpp\"\
    \n\n#include \"mod/dynamic_modint.hpp\"\n#include \"seq/geometric_sequence_sum.hpp\"\
    \n\ntemplate <int K>\nvoid test() {\n  using mint = dmint;\n  FOR(p, 1, 50) {\n\
    \    FOR(r, 50) {\n      FOR(n, 50) {\n        mint::set_mod(p);\n        auto\
    \ A = geometic_sequence_sum_K<mint, K>(r, n);\n        FOR(k, K + 1) {\n     \
    \     mint ans = 0;\n          mint pow = 1;\n          FOR(i, n) { ans += pow\
    \ * mint(i).pow(k), pow *= mint(r); }\n          assert(A[k] == ans);\n      \
    \  }\n      }\n    }\n  }\n}\n\nvoid test_sum() {\n  using mint = dmint;\n  FOR(p,\
    \ 1, 50) {\n    FOR(r, 50) {\n      FOR(n, 50) {\n        mint::set_mod(p);\n\
    \        mint ans = 0;\n        mint pow = 1;\n        FOR(i, n) { ans += pow,\
    \ pow *= mint(r); }\n        mint me = geometic_sequence_sum<mint>(r, n);\n  \
    \      assert(ans == me);\n      }\n    }\n  }\n}\n\nvoid solve() {\n  int a,\
    \ b;\n  cin >> a >> b;\n  cout << a + b << \"\\n\";\n}\n\nsigned main() {\n  test<0>();\n\
    \  test<1>();\n  test<2>();\n  test<3>();\n  test<4>();\n  test_sum();\n  solve();\n\
    \  return 0;\n}"
  dependsOn: []
  isVerificationFile: false
  path: seq/geometric_sequence_sum.hpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: seq/geometric_sequence_sum.hpp
layout: document
redirect_from:
- /library/seq/geometric_sequence_sum.hpp
- /library/seq/geometric_sequence_sum.hpp.html
title: seq/geometric_sequence_sum.hpp
---
