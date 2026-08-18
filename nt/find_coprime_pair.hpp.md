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
    - https://codeforces.com/contest/1148/problem/G
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
  code: "#include \"ds/my_bitset.hpp\"\n#include \"nt/lpf_table.hpp\"\n#include \"\
    nt/factor.hpp\"\n\n// A[i] \u3068\u4E92\u3044\u306B\u7D20\u306A A[j] \u3092\u691C\
    \u51FA / A[i] \u306E\u524A\u9664\n// N=1e5,A=1e7 \u9023\u7D50\u6210\u5206\u5206\
    \u89E3 1030ms\n// https://codeforces.com/contest/1148/problem/G\ntemplate <int\
    \ thresh = 200>\nstruct Find_Coprime_Pair {\n  // thresh \u4EE5\u4E0A\u3042\u308B\
    \u7D20\u6570\u3092 bitset \u7BA1\u7406\n  using BS = Bit_Array;\n  int N;\n  vc<int>\
    \ A;\n  vc<int> lpf;\n  vc<int> S;\n  vc<int> ptr;\n  vc<int> bidx;\n  vc<BS>\
    \ dat;\n  BS remain;\n  // 20 \u4EE5\u4E0B\u306E\u7D20\u6570\u306E\u7A4D\n  const\
    \ int prod = 9699690;\n\n  Find_Coprime_Pair(vc<int> A) : A(A) {\n    N = len(A);\n\
    \    int ma = MAX(A);\n    lpf = lpf_table(ma);\n    vc<int> ptr1(ma + 1);\n \
    \   vc<int> ids(N);\n    for (auto& x : A) ptr1[x]++;\n    ptr1 = cumsum<int>(ptr1);\n\
    \    FOR(i, N) { ids[ptr1[A[i]]++] = i; }\n    FOR_R(i, len(ptr1) - 1) ptr1[i\
    \ + 1] = ptr1[i];\n\n    ptr.resize(ma + 2);\n    FOR(p, 23, ma + 1) {\n     \
    \ if (lpf[p] != p) continue;\n      ptr[p] = len(S);\n      for (int n = p; n\
    \ <= ma; n += p) {\n        FOR(k, ptr1[n], ptr1[n + 1]) S.eb(ids[k]);\n     \
    \ }\n      ptr[p + 1] = len(S);\n    }\n\n    bidx.assign(ma + 1, -1);\n    {\n\
    \      vc<int> prime = {2, 3, 5, 7, 11, 13, 17, 19};\n      vc<BS> tmp(1 << 8);\n\
    \      tmp[0] = BS(N, 1);\n      FOR(i, 8) {\n        BS bs(N, 1);\n        FOR(j,\
    \ N) if (A[j] % prime[i] == 0) bs[j] = 0;\n        FOR(s, 1 << i) tmp[s | 1 <<\
    \ i] = tmp[s] & bs;\n      }\n      FOR(s, 1 << 8) {\n        int prd = 1;\n \
    \       FOR(i, 8) if (s >> i & 1) prd *= prime[i];\n        if (prd <= ma) {\n\
    \          bidx[prd] = len(dat);\n          dat.eb(tmp[s]);\n        }\n     \
    \ }\n    }\n\n    FOR(p, 23, ma + 1) {\n      if (lpf[p] != p) continue;\n   \
    \   int cnt = ptr[p + 1] - ptr[p];\n      if (cnt < thresh) continue;\n      BS\
    \ bs(N, 1);\n      FOR(i, ptr[p], ptr[p + 1]) bs[S[i]] = 0;\n      bidx[p] = len(dat);\n\
    \      dat.eb(bs);\n    }\n    remain = BS(N, 1);\n  }\n\n  void remove(int i)\
    \ { remain[i] = 0; }\n\n  // \u81EA\u5206\u81EA\u8EAB\u306F\u9664\u3044\u3066\n\
    \  template <typename F>\n  void enumerate_all(int i, F f) {\n    int d = gcd(A[i],\
    \ prod);\n    BS x = remain & dat[bidx[d]];\n    for (auto& [p, e] : factor_by_lpf(A[i],\
    \ lpf)) {\n      if (p < 20) continue;\n      if (bidx[p] == -1) {\n        FOR(k,\
    \ ptr[p], ptr[p + 1]) { x[S[k]] = 0; }\n      } else {\n        x &= dat[bidx[p]];\n\
    \      }\n    }\n    x.enumerate(0, N, f);\n  }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: nt/find_coprime_pair.hpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: nt/find_coprime_pair.hpp
layout: document
redirect_from:
- /library/nt/find_coprime_pair.hpp
- /library/nt/find_coprime_pair.hpp.html
title: nt/find_coprime_pair.hpp
---
