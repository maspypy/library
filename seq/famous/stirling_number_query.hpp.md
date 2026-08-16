---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.12.13/x64/lib/python3.12/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n          \
    \         ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \  File \"/opt/hostedtoolcache/Python/3.12.13/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.12.13/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \                ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n \
    \ File \"/opt/hostedtoolcache/Python/3.12.13/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: nt/primetest.hpp:\
    \ line -1: no such header\n"
  code: "#include \"nt/primetest.hpp\"\n\n// O(p^2) \u6642\u9593\u306E\u524D\u8A08\
    \u7B97\u306E\u3082\u3068\u3001O(log n) \u6642\u9593\nstruct Stirling_Number_Query\
    \ {\n  const int p;\n  vvc<int> MEMO_C;\n  vvc<int> MEMO_S1;\n  vvc<int> MEMO_S2;\n\
    \n  Stirling_Number_Query(int p, bool first_kind = true, bool second_kind = true)\n\
    \      : p(p) {\n    assert(primetest(p));\n    assert(p <= (1 << 15));\n    build_C();\n\
    \    if (first_kind) build_S1();\n    if (second_kind) build_S2();\n  }\n\n  int\
    \ C(ll n, ll k) {\n    if (k < 0 || k > n) return 0;\n    int res = 1;\n    while\
    \ (n) {\n      int i = n % p, j = k % p;\n      if (j > i) return 0;\n      res\
    \ = res * MEMO_C[i][j] % p;\n      n /= p;\n      k /= p;\n    }\n    return res;\n\
    \  }\n\n  int S1(ll n, ll k) {\n    if (k < 0 || k > n) return 0;\n    ll i =\
    \ n / p;\n    int j = n % p;\n    if (i > k) return 0;\n    ll a = (k - i) / (p\
    \ - 1);\n    int b = (k - i) % (p - 1);\n    if (b == 0 && j > 0) {\n      b +=\
    \ (p - 1);\n      a -= 1;\n    }\n    if (a < 0 || i < a || b > j) return 0;\n\
    \    int x = C(i, a);\n    int y = MEMO_S1[j][b];\n    int res = x * y % p;\n\
    \    if ((i + a) % 2 == 1 && res) { res = p - res; }\n    return res;\n  }\n\n\
    \  int S2(ll n, ll k) {\n    if (k < 0 || k > n) return 0;\n    if (n == 0) return\
    \ 1;\n    ll i = k / p;\n    int j = k % p;\n    if (n < i) return 0;\n    ll\
    \ a = (n - i) / (p - 1);\n    int b = (n - i) - (p - 1) * a;\n    if (b == 0)\
    \ {\n      b += p - 1;\n      a -= 1;\n    }\n    if (a < 0 || j > b) return 0;\n\
    \    if (b < p - 1) { return C(a, i) * MEMO_S2[b][j] % p; }\n    if (j == 0) return\
    \ C(a, i - 1);\n    return C(a, i) * MEMO_S2[p - 1][j] % p;\n  }\n\nprivate:\n\
    \  void build_C() {\n    auto& A = MEMO_C;\n    A.resize(p);\n    A[0] = {1};\n\
    \    FOR(i, 1, p) {\n      A[i] = A[i - 1];\n      A[i].emplace_back(0);\n   \
    \   FOR(j, 1, i + 1) {\n        A[i][j] += A[i - 1][j - 1];\n        if (A[i][j]\
    \ >= p) A[i][j] -= p;\n      }\n    }\n  }\n\n  void build_S1() {\n    auto& A\
    \ = MEMO_S1;\n    A.resize(p);\n    A[0] = {1};\n    FOR(i, 1, p) {\n      A[i].assign(i\
    \ + 1, 0);\n      FOR(j, i + 1) {\n        if (j) A[i][j] += A[i - 1][j - 1];\n\
    \        if (j < i) A[i][j] += A[i - 1][j] * (p - i + 1);\n        A[i][j] %=\
    \ p;\n      }\n    }\n  }\n\n  void build_S2() {\n    auto& A = MEMO_S2;\n   \
    \ A.resize(p);\n    A[0] = {1};\n    FOR(i, 1, p) {\n      A[i].assign(i + 1,\
    \ 0);\n      FOR(j, i + 1) {\n        if (j) A[i][j] += A[i - 1][j - 1];\n   \
    \     if (j < i) A[i][j] += A[i - 1][j] * j;\n        A[i][j] %= p;\n      }\n\
    \    }\n  }\n};"
  dependsOn: []
  isVerificationFile: false
  path: seq/famous/stirling_number_query.hpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: seq/famous/stirling_number_query.hpp
layout: document
redirect_from:
- /library/seq/famous/stirling_number_query.hpp
- /library/seq/famous/stirling_number_query.hpp.html
title: seq/famous/stirling_number_query.hpp
---
