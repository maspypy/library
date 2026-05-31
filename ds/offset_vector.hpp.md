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
  bundledCode: "#line 1 \"ds/offset_vector.hpp\"\n// V[L],...,V[R-1] \u3092\u5927\u304D\
    \u3055 R-L \u306E vector \u3067\u7BA1\u7406\u3059\u308B\ntemplate <typename T>\n\
    struct OffsetVector {\n  int off;\n  vc<T> dat;\n  OffsetVector(int L = 0, int\
    \ R = 0, T t = {}) : off(L), dat(R - L, t) {}\n  T& operator[](int i) { return\
    \ dat[i - off]; }\n  const T& operator[](int i) const { return dat[i - off]; }\n\
    \  int size() const { return dat.size(); }\n  int L() const { return off; }\n\
    \  int R() const { return off + (dat.size()); }\n};\n"
  code: "// V[L],...,V[R-1] \u3092\u5927\u304D\u3055 R-L \u306E vector \u3067\u7BA1\
    \u7406\u3059\u308B\ntemplate <typename T>\nstruct OffsetVector {\n  int off;\n\
    \  vc<T> dat;\n  OffsetVector(int L = 0, int R = 0, T t = {}) : off(L), dat(R\
    \ - L, t) {}\n  T& operator[](int i) { return dat[i - off]; }\n  const T& operator[](int\
    \ i) const { return dat[i - off]; }\n  int size() const { return dat.size(); }\n\
    \  int L() const { return off; }\n  int R() const { return off + (dat.size());\
    \ }\n};"
  dependsOn: []
  isVerificationFile: false
  path: ds/offset_vector.hpp
  requiredBy: []
  timestamp: '2026-05-31 16:42:56+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: ds/offset_vector.hpp
layout: document
redirect_from:
- /library/ds/offset_vector.hpp
- /library/ds/offset_vector.hpp.html
title: ds/offset_vector.hpp
---
