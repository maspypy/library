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
    - https://qoj.ac/contest/1803/problem/9406
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.12.13/x64/lib/python3.12/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n          \
    \         ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \  File \"/opt/hostedtoolcache/Python/3.12.13/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.12.13/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.12.13/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.12.13/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \                ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n \
    \ File \"/opt/hostedtoolcache/Python/3.12.13/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: bit.hpp: line\
    \ -1: no such header\n"
  code: "#include \"string/suffix_array.hpp\"\n\n// https://qoj.ac/contest/1803/problem/9406\n\
    // SEG_TYPE=0: SegTree, 1: SparseTable, 2: StaticRangeProduct\ntemplate <int SEG_TYPE>\n\
    struct Many_String_Compare {\n  int n;\n  string ALL;\n  vc<int> pos;\n  Suffix_Array<SEG_TYPE>\
    \ X;\n\n  template <typename F>\n  Many_String_Compare(int n, F f) : n(n) {\n\
    \    pos = {0};\n    FOR(i, n) {\n      ALL += f(i);\n      pos.eb(len(ALL));\n\
    \    }\n    X = Suffix_Array<SEG_TYPE>(ALL);\n  }\n\n  // S[a][la:lb), S[b][lb:rb)\n\
    \  int lcp(int a, int la, int ra, int b, int lb, int rb) {\n    assert(0 <= a\
    \ && a < n && 0 <= b && b < n);\n    assert(0 <= la && la <= ra && ra <= length(a));\n\
    \    assert(0 <= lb && lb <= rb && rb <= length(b));\n    int n = X.lcp(pos[a]\
    \ + la, pos[b] + lb);\n    return min({n, ra - la, rb - lb});\n  }\n\n  // [<]-1,\
    \ [=]0, [>]1\n  int comp3(int a, int la, int ra, int b, int lb, int rb) {\n  \
    \  int na = ra - la, nb = rb - lb;\n    if (na > nb) return -comp3(b, lb, rb,\
    \ a, la, ra);\n    int n = lcp(a, la, ra, b, lb, rb);\n    if (n == na) {\n  \
    \    return (na == nb ? 0 : -1);\n    }\n    return (ALL[pos[a] + la + n] < ALL[pos[b]\
    \ + lb + n] ? -1 : 1);\n  }\n\n  // [<]-1, [=]0, [>]1, (S+T) vs (T+S)\n  int ST_TS_comp3(int\
    \ a, int la, int ra, int b, int lb, int rb) {\n    int na = ra - la, nb = rb -\
    \ lb;\n    if (na > nb) return -ST_TS_comp3(b, lb, rb, a, la, ra);\n    int k\
    \ = comp3(a, la, la + na, b, lb, lb + na);\n    if (k != 0) return k;\n    k =\
    \ comp3(b, lb, lb + nb - na, b, lb + na, rb);\n    if (k != 0) return k;\n   \
    \ return comp3(b, lb + nb - na, rb, a, la, ra);\n  }\n\n  // [<]-1, [=]0, [>]1,\
    \ vc of {idx, l, r}\n  int comp3(const vc<tuple<int, int, int>> &A,\n        \
    \    const vc<tuple<int, int, int>> &B) {\n    int pa = 0, pb = 0;\n    int ka\
    \ = 0, kb = 0;\n    while (1) {\n      while (pa < len(A)) {\n        auto [i,\
    \ l, r] = A[pa];\n        if (l + ka < r) break;\n        ++pa, ka = 0;\n    \
    \  }\n      while (pb < len(B)) {\n        auto [i, l, r] = B[pb];\n        if\
    \ (l + kb < r) break;\n        ++pb, kb = 0;\n      }\n      if (pa == len(A)\
    \ && pb == len(B)) return 0;\n      if (pa == len(A)) return -1;\n      if (pb\
    \ == len(B)) return 1;\n      auto [a, la, ra] = A[pa];\n      auto [b, lb, rb]\
    \ = B[pb];\n      la += ka, lb += kb;\n      int k = lcp(a, la, ra, b, lb, rb);\n\
    \      if (k == 0) return (ALL[pos[a] + la] < ALL[pos[b] + lb] ? -1 : 1);\n  \
    \    ka += k, kb += k;\n    }\n    assert(0);\n  }\n\n  int length(int a) { return\
    \ pos[a + 1] - pos[a]; }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: string/many_string_compare.hpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: string/many_string_compare.hpp
layout: document
redirect_from:
- /library/string/many_string_compare.hpp
- /library/string/many_string_compare.hpp.html
title: string/many_string_compare.hpp
---
