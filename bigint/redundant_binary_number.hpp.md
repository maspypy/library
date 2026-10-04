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
    - https://qoj.ac/problem/382
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.12.14/x64/lib/python3.12/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n          \
    \         ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \  File \"/opt/hostedtoolcache/Python/3.12.14/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.12.14/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.12.14/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \                ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n \
    \ File \"/opt/hostedtoolcache/Python/3.12.14/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: other/bit.hpp:\
    \ line -1: no such header\n"
  code: "#include \"ds/fastset.hpp\"\n\n// 2^i \u3092\u8DB3\u3057\u305F\u308A\u5F15\
    \u3044\u305F\u308A. k-th digit \u306E\u53D6\u5F97.\n// fastset \u4F7F\u7528\u7248\
    .\n// https://qoj.ac/problem/382\nstruct Redundant_Binary_Number_Fast {\n  const\
    \ int n;\n  vc<char> dat;\n  FastSet S;\n  Redundant_Binary_Number_Fast(int n)\
    \ : n(n), dat(n), S(n) {}\n\n  int sgn() {\n    int k = S.prev(n - 1);\n    return\
    \ (k == -1 ? 0 : dat[k]);\n  }\n\n  // k-th bit in [0,1]\n  int kth(int k) {\n\
    \    int j = S.prev(k - 1);\n    int x = dat[k];\n    int y = (j == -1 ? 0 : dat[j]);\n\
    \    if (x == 0) return (y >= 0 ? 0 : 1);\n    return (y >= 0 ? 1 : 0);\n  }\n\
    \n  // 2^k * x \u3092\u8DB3\u3059\n  void add(int k, ll x) {\n    while (x) {\n\
    \      x += dat[k];\n      dat[k] = x % 2;\n      if (dat[k] == 0) {\n       \
    \ S.erase(k);\n      } else {\n        S.insert(k);\n      }\n      ++k, x /=\
    \ 2;\n    }\n  }\n\n  // 2^k \u3092\u8DB3\u3059\n  void add(int k) { add(k, 1);\
    \ }\n  void sub(int k) { add(k, -1); }\n\n  string to_string() {\n    string ANS;\n\
    \    for (auto& x: dat) { ANS += (x == 0 ? '0' : (x == 1 ? '+' : '-')); }\n  \
    \  return ANS;\n  }\n};\n\n// 2^i \u3092\u8DB3\u3057\u305F\u308A\u5F15\u3044\u305F\
    \u308A. k-th digit \u306E\u53D6\u5F97.\ntemplate <typename KETA_TYPE = int>\n\
    struct Redundant_Binary_Number {\n  using T = KETA_TYPE;\n  map<T, char> dat;\n\
    \  Redundant_Binary_Number() {}\n\n  int sgn() {\n    auto [k, x] = prev(infty<T>);\n\
    \    return x;\n  }\n\n  // k-th bit in [0,1]\n  int kth(T k) {\n    int x = (dat.count(k)\
    \ ? dat[k] : 0);\n    int y = prev(k - 1).se;\n    if (x == 0) return (y >= 0\
    \ ? 0 : 1);\n    return (y >= 0 ? 1 : 0);\n  }\n\n  // 2^k * x \u3092\u8DB3\u3059\
    \n  void add(T k, ll x) {\n    while (x) {\n      x += dat[k];\n      if (x %\
    \ 2 == 0) {\n        dat.erase(k);\n      } else {\n        dat[k] = x % 2;\n\
    \      }\n      ++k, x /= 2;\n    }\n  }\n\n  // 2^k \u3092\u8DB3\u3059\n  void\
    \ add(T k) { add_inner(k, 1); }\n  void sub(T k) { add_inner(k, -1); }\n\nprivate:\n\
    \  pair<T, char> prev(T k) {\n    while (1) {\n      auto it = dat.upper_bound(k);\n\
    \      if (it == dat.begin()) return {-1, 0};\n      it = ::prev(it);\n      return\
    \ *it;\n    }\n  }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: bigint/redundant_binary_number.hpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: bigint/redundant_binary_number.hpp
layout: document
redirect_from:
- /library/bigint/redundant_binary_number.hpp
- /library/bigint/redundant_binary_number.hpp.html
title: bigint/redundant_binary_number.hpp
---
