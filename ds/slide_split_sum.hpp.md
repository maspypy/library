---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: ds/removable_queue.hpp
    title: ds/removable_queue.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/3_yukicoder/2654.test.cpp
    title: test/3_yukicoder/2654.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 2 \"ds/removable_queue.hpp\"\n\ntemplate <typename QUE_TYPE>\n\
    struct Removable_Queue {\n  using QUE = QUE_TYPE;\n  using T = typename QUE::value_type;\n\
    \n  QUE que, rm_que;\n\n  Removable_Queue() {}\n  Removable_Queue(vc<T>& dat)\
    \ : que(all(dat)) {}\n\n  void push(T x) { que.push(x); }\n  int size() { return\
    \ len(que) - len(rm_que); }\n  bool empty() { return size() == 0; }\n\n  T pop()\
    \ {\n    refresh();\n    return POP(que);\n  }\n  T top() {\n    refresh();\n\
    \    return que.top();\n  }\n\n  void remove(T x) { rm_que.push(x); }\n\n  vc<T>\
    \ get_all() {\n    vc<T> ANS;\n    while (!empty()) { ANS.eb(pop()); }\n    for\
    \ (auto& x: ANS) push(x);\n    return ANS;\n  }\n\nprivate:\n  void refresh()\
    \ {\n    while (len(rm_que) && rm_que.top() == que.top()) { rm_que.pop(), que.pop();\
    \ }\n  }\n};\n#line 2 \"ds/slide_split_sum.hpp\"\n\n/*\n\u30FB\u591A\u91CD\u96C6\
    \u5408\u3092\u6271\u3046\n\u30FB[0,k) \u756A\u76EE\u3068 [k,N) \u756A\u76EE\u306E\
    \ sum \u304C\u3068\u308C\u308B\n\u30FBO(k \u306E\u5909\u5316\u91CF\u306E\u7DCF\
    \u548C x log N)\n*/\ntemplate <typename T, typename SUM_T = T>\nstruct Slide_Split_Sum\
    \ {\n  Removable_Queue<pq_max<T>> ql;\n  Removable_Queue<pq_min<T>> qr;\n  SUM_T\
    \ sl, sr;\n  Slide_Split_Sum() : sl(0), sr(0) {}\n\n  inline int size() { return\
    \ len(ql) + len(qr); }\n  void clear() {\n    ql = Removable_Queue<pq_max<T>>();\n\
    \    qr = Removable_Queue<pq_min<T>>();\n    sl = sr = 0;\n  }\n  void insert(T\
    \ x) { (x <= lmax() ? push_l(x) : push_r(x)); }\n  void erase(T x) { (x <= lmax()\
    \ ? erase_l(x) : erase_r(x)); }\n  pair<SUM_T, SUM_T> query(int k) {\n    slide(k);\n\
    \    return {sl, sr};\n  }\n  // \u4E0B\u4F4D k \u500B\n  SUM_T query_l(int k)\
    \ { return query(k).fi; }\n  // \u4E0A\u4F4D k \u500B\n  SUM_T query_r(int k)\
    \ { return query(size() - k).se; }\n  T kth(int k) {\n    slide(k);\n    return\
    \ qr.top();\n  }\n  void slide(int k) {\n    assert(0 <= k && k <= size());\n\
    \    while (len(ql) < k) {\n      push_l(pop_r());\n    }\n    while (len(ql)\
    \ > k) {\n      push_r(pop_l());\n    }\n  }\n  vc<T> get_all() {\n    vc<T> L\
    \ = ql.get_all();\n    vc<T> R = qr.get_all();\n    reverse(all(L));\n    concat(L,\
    \ R);\n    return L;\n  }\n\n private:\n  inline T lmax() { return (ql.empty()\
    \ ? -infty<T> : ql.top()); }\n  inline T rmin() { return (qr.empty() ? infty<T>\
    \ : qr.top()); }\n  inline T pop_l() {\n    T x = ql.pop();\n    sl -= x;\n  \
    \  return x;\n  }\n  inline T pop_r() {\n    T x = qr.pop();\n    sr -= x;\n \
    \   return x;\n  }\n  inline void push_l(T x) { ql.push(x), sl += x; }\n  inline\
    \ void push_r(T x) { qr.push(x), sr += x; }\n  inline void erase_l(T x) { ql.remove(x),\
    \ sl -= x; }\n  inline void erase_r(T x) { qr.remove(x), sr -= x; }\n};\n"
  code: "#include \"ds/removable_queue.hpp\"\n\n/*\n\u30FB\u591A\u91CD\u96C6\u5408\
    \u3092\u6271\u3046\n\u30FB[0,k) \u756A\u76EE\u3068 [k,N) \u756A\u76EE\u306E sum\
    \ \u304C\u3068\u308C\u308B\n\u30FBO(k \u306E\u5909\u5316\u91CF\u306E\u7DCF\u548C\
    \ x log N)\n*/\ntemplate <typename T, typename SUM_T = T>\nstruct Slide_Split_Sum\
    \ {\n  Removable_Queue<pq_max<T>> ql;\n  Removable_Queue<pq_min<T>> qr;\n  SUM_T\
    \ sl, sr;\n  Slide_Split_Sum() : sl(0), sr(0) {}\n\n  inline int size() { return\
    \ len(ql) + len(qr); }\n  void clear() {\n    ql = Removable_Queue<pq_max<T>>();\n\
    \    qr = Removable_Queue<pq_min<T>>();\n    sl = sr = 0;\n  }\n  void insert(T\
    \ x) { (x <= lmax() ? push_l(x) : push_r(x)); }\n  void erase(T x) { (x <= lmax()\
    \ ? erase_l(x) : erase_r(x)); }\n  pair<SUM_T, SUM_T> query(int k) {\n    slide(k);\n\
    \    return {sl, sr};\n  }\n  // \u4E0B\u4F4D k \u500B\n  SUM_T query_l(int k)\
    \ { return query(k).fi; }\n  // \u4E0A\u4F4D k \u500B\n  SUM_T query_r(int k)\
    \ { return query(size() - k).se; }\n  T kth(int k) {\n    slide(k);\n    return\
    \ qr.top();\n  }\n  void slide(int k) {\n    assert(0 <= k && k <= size());\n\
    \    while (len(ql) < k) {\n      push_l(pop_r());\n    }\n    while (len(ql)\
    \ > k) {\n      push_r(pop_l());\n    }\n  }\n  vc<T> get_all() {\n    vc<T> L\
    \ = ql.get_all();\n    vc<T> R = qr.get_all();\n    reverse(all(L));\n    concat(L,\
    \ R);\n    return L;\n  }\n\n private:\n  inline T lmax() { return (ql.empty()\
    \ ? -infty<T> : ql.top()); }\n  inline T rmin() { return (qr.empty() ? infty<T>\
    \ : qr.top()); }\n  inline T pop_l() {\n    T x = ql.pop();\n    sl -= x;\n  \
    \  return x;\n  }\n  inline T pop_r() {\n    T x = qr.pop();\n    sr -= x;\n \
    \   return x;\n  }\n  inline void push_l(T x) { ql.push(x), sl += x; }\n  inline\
    \ void push_r(T x) { qr.push(x), sr += x; }\n  inline void erase_l(T x) { ql.remove(x),\
    \ sl -= x; }\n  inline void erase_r(T x) { qr.remove(x), sr -= x; }\n};\n"
  dependsOn:
  - ds/removable_queue.hpp
  isVerificationFile: false
  path: ds/slide_split_sum.hpp
  requiredBy: []
  timestamp: '2025-07-04 07:28:26+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/3_yukicoder/2654.test.cpp
documentation_of: ds/slide_split_sum.hpp
layout: document
redirect_from:
- /library/ds/slide_split_sum.hpp
- /library/ds/slide_split_sum.hpp.html
title: ds/slide_split_sum.hpp
---
