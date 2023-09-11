---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test_atcoder/abc312f.test.cpp
    title: test_atcoder/abc312f.test.cpp
  - icon: ':x:'
    path: test_atcoder/abc314g.test.cpp
    title: test_atcoder/abc314g.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
  attributes:
    links: []
  bundledCode: "#line 1 \"ds/slide_split_sum.hpp\"\n/*\n\u30FB\u591A\u91CD\u96C6\u5408\
    \u3092\u6271\u3046\n\u30FB[0,k) \u756A\u76EE\u3068 [k,N) \u756A\u76EE\u306E sum\
    \ \u304C\u3068\u308C\u308B\n\u30FBO(k \u306E\u5909\u5316\u91CF\u306E\u7DCF\u548C\
    \ x log N)\n*/\ntemplate <typename T>\nstruct Slide_Split_Sum {\n  pq<T> ql, rm_ql;\n\
    \  pqg<T> qr, rm_qr;\n  T sl, sr;\n  Slide_Split_Sum() : sl(0), sr(0) {}\n\n \
    \ inline int size() { return size_l() + size_r(); }\n  void insert(T x) {\n  \
    \  if (x <= lmax())\n      push_l(x);\n    else\n      push_r(x);\n  }\n  void\
    \ erase(T x) {\n    if (x <= lmax()) {\n      erase_l(x);\n    } else {\n    \
    \  erase_r(x);\n    }\n  }\n  pair<T, T> query(int k) {\n    assert(0 <= k &&\
    \ k <= size());\n    while (size_l() < k) { push_l(pop_r()); }\n    while (size_l()\
    \ > k) { push_r(pop_l()); }\n    return {sl, sr};\n  }\n  T query_l(int k) { return\
    \ query(k).fi; }\n  T query_r(int k) { return query(size() - k).se; }\n\nprivate:\n\
    \  inline T lmax() {\n    while (!rm_ql.empty() && ql.top() == rm_ql.top()) rm_ql.pop(),\
    \ ql.pop();\n    return (ql.empty() ? -infty<T> : ql.top());\n  }\n  inline T\
    \ rmin() {\n    while (!rm_qr.empty() && qr.top() == rm_qr.top()) rm_qr.pop(),\
    \ qr.pop();\n    return (qr.empty() ? infty<T> : qr.top());\n  }\n  inline T pop_l()\
    \ {\n    while (!rm_ql.empty() && ql.top() == rm_ql.top()) rm_ql.pop(), ql.pop();\n\
    \    T x = POP(ql);\n    sl -= x;\n    return x;\n  }\n  inline T pop_r() {\n\
    \    while (!rm_qr.empty() && qr.top() == rm_qr.top()) rm_qr.pop(), qr.pop();\n\
    \    T x = POP(qr);\n    sr -= x;\n    return x;\n  }\n  inline void push_l(T\
    \ x) { ql.emplace(x), sl += x; }\n  inline void push_r(T x) { qr.emplace(x), sr\
    \ += x; }\n  inline void erase_l(T x) { rm_ql.emplace(x), sl -= x; }\n  inline\
    \ void erase_r(T x) { rm_qr.emplace(x), sr -= x; }\n  inline int size_l() { return\
    \ ql.size() - rm_ql.size(); }\n  inline int size_r() { return qr.size() - rm_qr.size();\
    \ }\n};\n"
  code: "/*\n\u30FB\u591A\u91CD\u96C6\u5408\u3092\u6271\u3046\n\u30FB[0,k) \u756A\u76EE\
    \u3068 [k,N) \u756A\u76EE\u306E sum \u304C\u3068\u308C\u308B\n\u30FBO(k \u306E\
    \u5909\u5316\u91CF\u306E\u7DCF\u548C x log N)\n*/\ntemplate <typename T>\nstruct\
    \ Slide_Split_Sum {\n  pq<T> ql, rm_ql;\n  pqg<T> qr, rm_qr;\n  T sl, sr;\n  Slide_Split_Sum()\
    \ : sl(0), sr(0) {}\n\n  inline int size() { return size_l() + size_r(); }\n \
    \ void insert(T x) {\n    if (x <= lmax())\n      push_l(x);\n    else\n     \
    \ push_r(x);\n  }\n  void erase(T x) {\n    if (x <= lmax()) {\n      erase_l(x);\n\
    \    } else {\n      erase_r(x);\n    }\n  }\n  pair<T, T> query(int k) {\n  \
    \  assert(0 <= k && k <= size());\n    while (size_l() < k) { push_l(pop_r());\
    \ }\n    while (size_l() > k) { push_r(pop_l()); }\n    return {sl, sr};\n  }\n\
    \  T query_l(int k) { return query(k).fi; }\n  T query_r(int k) { return query(size()\
    \ - k).se; }\n\nprivate:\n  inline T lmax() {\n    while (!rm_ql.empty() && ql.top()\
    \ == rm_ql.top()) rm_ql.pop(), ql.pop();\n    return (ql.empty() ? -infty<T> :\
    \ ql.top());\n  }\n  inline T rmin() {\n    while (!rm_qr.empty() && qr.top()\
    \ == rm_qr.top()) rm_qr.pop(), qr.pop();\n    return (qr.empty() ? infty<T> :\
    \ qr.top());\n  }\n  inline T pop_l() {\n    while (!rm_ql.empty() && ql.top()\
    \ == rm_ql.top()) rm_ql.pop(), ql.pop();\n    T x = POP(ql);\n    sl -= x;\n \
    \   return x;\n  }\n  inline T pop_r() {\n    while (!rm_qr.empty() && qr.top()\
    \ == rm_qr.top()) rm_qr.pop(), qr.pop();\n    T x = POP(qr);\n    sr -= x;\n \
    \   return x;\n  }\n  inline void push_l(T x) { ql.emplace(x), sl += x; }\n  inline\
    \ void push_r(T x) { qr.emplace(x), sr += x; }\n  inline void erase_l(T x) { rm_ql.emplace(x),\
    \ sl -= x; }\n  inline void erase_r(T x) { rm_qr.emplace(x), sr -= x; }\n  inline\
    \ int size_l() { return ql.size() - rm_ql.size(); }\n  inline int size_r() { return\
    \ qr.size() - rm_qr.size(); }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: ds/slide_split_sum.hpp
  requiredBy: []
  timestamp: '2023-08-06 03:47:07+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - test_atcoder/abc312f.test.cpp
  - test_atcoder/abc314g.test.cpp
documentation_of: ds/slide_split_sum.hpp
layout: document
redirect_from:
- /library/ds/slide_split_sum.hpp
- /library/ds/slide_split_sum.hpp.html
title: ds/slide_split_sum.hpp
---
