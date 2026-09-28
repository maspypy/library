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
  bundledCode: "#line 1 \"setfunc/xor_submask_lower_bound.hpp\"\n\n// a <= b xor (submask\
    \ S) \u3068\u306A\u308B\u4E2D\u3067\u53F3\u8FBA\u306E\u6700\u5C0F\n// \u306A\u3051\
    \u308C\u3070 UINT(-1)\ntemplate <typename UINT>\nUINT xor_submask_lower_bound(UINT\
    \ a, UINT b, UINT S) {\n  // a <= (b ^ submask(S)), minimize rhs\n  b &= ~S;\n\
    \  if (a <= b) return b;\n  u32 c = b | S;\n  if (a > c) return -1;\n  u32 D =\
    \ (a ^ b) & ~S;\n  if (D == 0) return a;\n  int k = topbit(D);\n  if ((b >> k)\
    \ & 1) {\n    b |= (a & S) & ~full_mask(k + 1);\n    return b;\n  }\n  u32 X =\
    \ S & ~a;\n  X &= ~full_mask(k + 1);\n  k = lowbit(X);\n  b |= (a & S) & ~full_mask(k\
    \ + 1);\n  b |= u32(1) << k;\n  assert(a <= b);\n  return b;\n};\n"
  code: "\n// a <= b xor (submask S) \u3068\u306A\u308B\u4E2D\u3067\u53F3\u8FBA\u306E\
    \u6700\u5C0F\n// \u306A\u3051\u308C\u3070 UINT(-1)\ntemplate <typename UINT>\n\
    UINT xor_submask_lower_bound(UINT a, UINT b, UINT S) {\n  // a <= (b ^ submask(S)),\
    \ minimize rhs\n  b &= ~S;\n  if (a <= b) return b;\n  u32 c = b | S;\n  if (a\
    \ > c) return -1;\n  u32 D = (a ^ b) & ~S;\n  if (D == 0) return a;\n  int k =\
    \ topbit(D);\n  if ((b >> k) & 1) {\n    b |= (a & S) & ~full_mask(k + 1);\n \
    \   return b;\n  }\n  u32 X = S & ~a;\n  X &= ~full_mask(k + 1);\n  k = lowbit(X);\n\
    \  b |= (a & S) & ~full_mask(k + 1);\n  b |= u32(1) << k;\n  assert(a <= b);\n\
    \  return b;\n};"
  dependsOn: []
  isVerificationFile: false
  path: setfunc/xor_submask_lower_bound.hpp
  requiredBy: []
  timestamp: '2026-09-28 10:13:21+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: setfunc/xor_submask_lower_bound.hpp
layout: document
redirect_from:
- /library/setfunc/xor_submask_lower_bound.hpp
- /library/setfunc/xor_submask_lower_bound.hpp.html
title: setfunc/xor_submask_lower_bound.hpp
---
