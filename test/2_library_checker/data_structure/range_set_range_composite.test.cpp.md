---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes: {}
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.12.14/x64/lib/python3.12/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n          \
    \         ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \  File \"/opt/hostedtoolcache/Python/3.12.14/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.12.14/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.12.14/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.12.14/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \                ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n \
    \ File \"/opt/hostedtoolcache/Python/3.12.14/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: other/bit.hpp:\
    \ line -1: no such header\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/range_set_range_composite\"\
    \n\n#include \"my_template.hpp\"\n#include \"other/io.hpp\"\n\n#include \"mod/modint.hpp\"\
    \n#include \"alg/monoid/affine.hpp\"\n#include \"ds/segtree/range_assignment_segtree.hpp\"\
    \n\nusing mint = modint998;\nusing Mono = Monoid_Affine<mint>;\nusing AFF = typename\
    \ Mono::value_type;\n\nvoid solve() {\n  INT(N, Q);\n\n  Range_Assignment_SegTree<Mono>\
    \ seg(N, [&](int i) -> AFF {\n    INT(a, b);\n    return {mint(a), mint(b)};\n\
    \  });\n\n  FOR(Q) {\n    INT(t);\n    if (t == 0) {\n      INT(l, r, b, c);\n\
    \      seg.assign(l, r, {mint(b), mint(c)});\n    }\n    if (t == 1) {\n     \
    \ INT(l, r, x);\n      AFF f = seg.prod(l, r);\n      mint ans = Mono::eval(f,\
    \ x);\n      print(ans);\n    }\n  }\n}\n\nsigned main() {\n  solve();\n  return\
    \ 0;\n}\n"
  dependsOn: []
  isVerificationFile: true
  path: test/2_library_checker/data_structure/range_set_range_composite.test.cpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/2_library_checker/data_structure/range_set_range_composite.test.cpp
layout: document
redirect_from:
- /verify/test/2_library_checker/data_structure/range_set_range_composite.test.cpp
- /verify/test/2_library_checker/data_structure/range_set_range_composite.test.cpp.html
title: test/2_library_checker/data_structure/range_set_range_composite.test.cpp
---
