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
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: ds/pds/array.hpp:\
    \ line -1: no such header\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/persistent_queue\"\r\n\
    #include \"my_template.hpp\"\r\n#include \"other/io.hpp\"\r\n\r\n#include \"ds/pds/array.hpp\"\
    \r\n\r\nvoid solve() {\r\n  LL(Q);\r\n  vi L(Q + 1), R(Q + 1);\r\n\r\n  using\
    \ PA = PersistentArray<int>;\r\n  using np = PA::np;\r\n  vc<np> PAS(Q + 1);\r\
    \n  PA array;\r\n  PAS[0] = array.get_root();\r\n  L[0] = 0, R[0] = 0;\r\n  FOR(q,\
    \ Q) {\r\n    LL(t);\r\n    if (t == 0) {\r\n      LL(k, x);\r\n      ++k;\r\n\
    \      PAS[q + 1] = array.set(PAS[k], R[k], x);\r\n      L[q + 1] = L[k];\r\n\
    \      R[q + 1] = R[k] + 1;\r\n    }\r\n    elif (t == 1) {\r\n      LL(k);\r\n\
    \      ++k;\r\n      print(array.get(PAS[k], L[k]));\r\n      PAS[q + 1] = PAS[k];\r\
    \n      L[q + 1] = L[k] + 1;\r\n      R[q + 1] = R[k];\r\n    }\r\n  }\r\n}\r\n\
    \r\nsigned main() {\r\n  cin.tie(nullptr);\r\n  ios::sync_with_stdio(false);\r\
    \n  cout << setprecision(15);\r\n\r\n  solve();\r\n\r\n  return 0;\r\n}\r\n"
  dependsOn: []
  isVerificationFile: true
  path: test/library_checker/datastructure/persistent_queue.test.cpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/library_checker/datastructure/persistent_queue.test.cpp
layout: document
redirect_from:
- /verify/test/library_checker/datastructure/persistent_queue.test.cpp
- /verify/test/library_checker/datastructure/persistent_queue.test.cpp.html
title: test/library_checker/datastructure/persistent_queue.test.cpp
---
