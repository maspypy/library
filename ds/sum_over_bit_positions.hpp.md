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
    - https://qoj.ac/contest/1784/problem/9244
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
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: ds/my_bitset.hpp:\
    \ line -1: no such header\n"
  code: "#include \"ds/my_bitset.hpp\"\n\n// https://qoj.ac/contest/1784/problem/9244\n\
    // sum bitset[i]*wt[i]\n// T \u306F 11bit sum \u304C\u304A\u3055\u307E\u308C\u3070\
    \ ok\n// (N=Q=100000:0.9 sec)\ntemplate <typename T, int MAXSIZE>\nstruct Sum_Over_Bit_Positions\
    \ {\n  int N;\n  vc<T> base;\n  static T table[MAXSIZE / 64 * 6 + 10][1 << 11];\n\
    \n  template <typename F>\n  Sum_Over_Bit_Positions(int N, F f) : N(N) {\n   \
    \ base.resize(N);\n    assert(0 <= N && N <= MAXSIZE);\n    int NB = (N + 63)\
    \ / 64;\n    FOR(block, NB) {\n      FOR(k, 6) {\n        int b = 6 * block +\
    \ k;\n        FOR(i, 11) {\n          int idx = 64 * block + 11 * k + i;\n   \
    \       T x = 0;\n          if ((k < 5 || i < 9) && idx < N) x = base[idx] = f(idx);\n\
    \          FOR(s, 1 << i) { table[b][s | 1 << i] = table[b][s] + x; }\n      \
    \  }\n      }\n    }\n  }\n\n  // bitset \u306E [l,r) \u90E8\u5206\n  template\
    \ <typename SUM_TYPE>\n  SUM_TYPE query(Bit_Array &x, int l, int r) {\n    SUM_TYPE\
    \ ANS = 0;\n    while (l < r && (l & 63)) {\n      if (x[l]) ANS += base[l];\n\
    \      l++;\n    }\n    while (l < r && (r & 63)) {\n      --r;\n      if (x[r])\
    \ ANS += base[r];\n    }\n    if (l == r) return ANS;\n    l /= 64, r /= 64;\n\
    \    FOR(b, l, r) {\n      u64 s = x.dat[b];\n      ANS += table[b * 6 + 0][s\
    \ >> 0 & 2047];\n      ANS += table[b * 6 + 1][s >> 11 & 2047];\n      ANS +=\
    \ table[b * 6 + 2][s >> 22 & 2047];\n      ANS += table[b * 6 + 3][s >> 33 & 2047];\n\
    \      ANS += table[b * 6 + 4][s >> 44 & 2047];\n      ANS += table[b * 6 + 5][s\
    \ >> 55 & 2047];\n    }\n    return ANS;\n  }\n};\ntemplate <typename T, int MAXSIZE>\n\
    T Sum_Over_Bit_Positions<T, MAXSIZE>::table[MAXSIZE / 64 * 6 + 10][1 << 11];\n"
  dependsOn: []
  isVerificationFile: false
  path: ds/sum_over_bit_positions.hpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: ds/sum_over_bit_positions.hpp
layout: document
redirect_from:
- /library/ds/sum_over_bit_positions.hpp
- /library/ds/sum_over_bit_positions.hpp.html
title: ds/sum_over_bit_positions.hpp
---
