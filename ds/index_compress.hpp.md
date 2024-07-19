---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/mytest/index_compress.test.cpp
    title: test/mytest/index_compress.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"ds/index_compress.hpp\"\ntemplate <typename T>\nstruct To_Unique_Index_SMALL\
    \ {\n  static_assert(is_same_v<T, int>);\n  int mi, ma;\n  vc<int> dat;\n  vc<int>\
    \ build(vc<int> X) {\n    mi = 0, ma = -1;\n    if (!X.empty()) mi = MIN(X), ma\
    \ = MAX(X);\n    dat.assign(ma - mi + 2, 0);\n    for (auto& x: X) dat[x - mi\
    \ + 1]++;\n    FOR(i, len(dat) - 1) dat[i + 1] += dat[i];\n    for (auto& x: X)\
    \ { x = dat[x - mi]++; }\n    FOR_R(i, 1, len(dat)) dat[i] = dat[i - 1];\n   \
    \ dat[0] = 0;\n    return X;\n  }\n  int operator()(ll x) { return dat[clamp<ll>(x\
    \ - mi, 0, ma - mi + 1)]; }\n};\n\ntemplate <typename T>\nstruct To_Unique_Index_LARGE\
    \ {\n  vc<T> dat;\n  vc<int> build(vc<T> X) {\n    vc<int> I = argsort(X);\n \
    \   dat = rearrange(X, I);\n    sort(all(dat));\n    vc<int> res(len(X));\n  \
    \  FOR(i, len(X)) res[I[i]] = i;\n    return res;\n  }\n  int operator()(T x)\
    \ { return LB(dat, x); }\n};\n\n// \u307E\u305A X \u306E\u5404\u8981\u7D20\u3092\
    \ [0,n) \u306B\u3046\u3064\u3059, \u5358\u5C04\u306B\u3059\u308B\n// [2,2,3] ->\
    \ [0,1,2]\n// (x): lower_bound(X,x) \u3092\u304B\u3048\u3059\ntemplate <typename\
    \ T, bool SMALL>\nusing To_Unique_Index =\n    typename std::conditional<SMALL,\
    \ To_Unique_Index_SMALL<T>,\n                              To_Unique_Index_LARGE<T>>::type;\n"
  code: "template <typename T>\nstruct To_Unique_Index_SMALL {\n  static_assert(is_same_v<T,\
    \ int>);\n  int mi, ma;\n  vc<int> dat;\n  vc<int> build(vc<int> X) {\n    mi\
    \ = 0, ma = -1;\n    if (!X.empty()) mi = MIN(X), ma = MAX(X);\n    dat.assign(ma\
    \ - mi + 2, 0);\n    for (auto& x: X) dat[x - mi + 1]++;\n    FOR(i, len(dat)\
    \ - 1) dat[i + 1] += dat[i];\n    for (auto& x: X) { x = dat[x - mi]++; }\n  \
    \  FOR_R(i, 1, len(dat)) dat[i] = dat[i - 1];\n    dat[0] = 0;\n    return X;\n\
    \  }\n  int operator()(ll x) { return dat[clamp<ll>(x - mi, 0, ma - mi + 1)];\
    \ }\n};\n\ntemplate <typename T>\nstruct To_Unique_Index_LARGE {\n  vc<T> dat;\n\
    \  vc<int> build(vc<T> X) {\n    vc<int> I = argsort(X);\n    dat = rearrange(X,\
    \ I);\n    sort(all(dat));\n    vc<int> res(len(X));\n    FOR(i, len(X)) res[I[i]]\
    \ = i;\n    return res;\n  }\n  int operator()(T x) { return LB(dat, x); }\n};\n\
    \n// \u307E\u305A X \u306E\u5404\u8981\u7D20\u3092 [0,n) \u306B\u3046\u3064\u3059\
    , \u5358\u5C04\u306B\u3059\u308B\n// [2,2,3] -> [0,1,2]\n// (x): lower_bound(X,x)\
    \ \u3092\u304B\u3048\u3059\ntemplate <typename T, bool SMALL>\nusing To_Unique_Index\
    \ =\n    typename std::conditional<SMALL, To_Unique_Index_SMALL<T>,\n        \
    \                      To_Unique_Index_LARGE<T>>::type;\n"
  dependsOn: []
  isVerificationFile: false
  path: ds/index_compress.hpp
  requiredBy: []
  timestamp: '2024-07-19 14:18:20+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/mytest/index_compress.test.cpp
documentation_of: ds/index_compress.hpp
layout: document
redirect_from:
- /library/ds/index_compress.hpp
- /library/ds/index_compress.hpp.html
title: ds/index_compress.hpp
---
