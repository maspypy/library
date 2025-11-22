---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/4_aoj/ITP2_11_D.test.cpp
    title: test/4_aoj/ITP2_11_D.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"setfunc/all_k_subset.hpp\"\n\n#ifdef _MSC_VER\n#include\
    \ <intrin.h>\n#else\n#include <x86intrin.h>\n#endif\n\ntemplate <typename UINT>\n\
    struct all_k_subset {\n  static_assert(is_unsigned<UINT>::value);\n  struct iter\
    \ {\n    const UINT n, k, s;\n    UINT t;\n    iter(UINT s, UINT k) : n(UINT(1)\
    \ << popcnt(s)), k(k), s(s), t((UINT(1) << k) - 1) {}\n    __attribute__((target(\"\
    bmi2\"))) auto operator*() const { return _pdep_u64(t, s); }\n    auto operator++()\
    \ {\n      if (k == 0) {\n        t = UINT(-1);\n      } else {\n        UINT\
    \ y = t + (-t & t);\n        t = y | ((y ^ t) >> lowbit(t << 2));\n      }\n \
    \   }\n    auto operator!=(const iter) const { return t < n; }\n  };\n  UINT s,\
    \ k;\n  all_k_subset(UINT s, UINT k) : s(s), k(k) { assert(s != UINT(-1)); }\n\
    \  auto begin() { return iter(s, k); }\n  auto end() { return iter(0, 0); }\n\
    };\n\n// all_nCk\u95A2\u6570\u306E\u5B9F\u88C5\nauto all_nCk(int n, int k) { return\
    \ all_k_subset<u32>((u32(1) << n) - 1, k); }\n"
  code: "\n#ifdef _MSC_VER\n#include <intrin.h>\n#else\n#include <x86intrin.h>\n#endif\n\
    \ntemplate <typename UINT>\nstruct all_k_subset {\n  static_assert(is_unsigned<UINT>::value);\n\
    \  struct iter {\n    const UINT n, k, s;\n    UINT t;\n    iter(UINT s, UINT\
    \ k) : n(UINT(1) << popcnt(s)), k(k), s(s), t((UINT(1) << k) - 1) {}\n    __attribute__((target(\"\
    bmi2\"))) auto operator*() const { return _pdep_u64(t, s); }\n    auto operator++()\
    \ {\n      if (k == 0) {\n        t = UINT(-1);\n      } else {\n        UINT\
    \ y = t + (-t & t);\n        t = y | ((y ^ t) >> lowbit(t << 2));\n      }\n \
    \   }\n    auto operator!=(const iter) const { return t < n; }\n  };\n  UINT s,\
    \ k;\n  all_k_subset(UINT s, UINT k) : s(s), k(k) { assert(s != UINT(-1)); }\n\
    \  auto begin() { return iter(s, k); }\n  auto end() { return iter(0, 0); }\n\
    };\n\n// all_nCk\u95A2\u6570\u306E\u5B9F\u88C5\nauto all_nCk(int n, int k) { return\
    \ all_k_subset<u32>((u32(1) << n) - 1, k); }"
  dependsOn: []
  isVerificationFile: false
  path: setfunc/all_k_subset.hpp
  requiredBy: []
  timestamp: '2025-05-05 02:10:07+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/4_aoj/ITP2_11_D.test.cpp
documentation_of: setfunc/all_k_subset.hpp
layout: document
redirect_from:
- /library/setfunc/all_k_subset.hpp
- /library/setfunc/all_k_subset.hpp.html
title: setfunc/all_k_subset.hpp
---
