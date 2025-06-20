---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: ds/slide_split_sum.hpp
    title: ds/slide_split_sum.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/2_library_checker/data_structure/double_ended_pq.test.cpp
    title: test/2_library_checker/data_structure/double_ended_pq.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/3_yukicoder/2654.test.cpp
    title: test/3_yukicoder/2654.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/3_yukicoder/772.test.cpp
    title: test/3_yukicoder/772.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/3_yukicoder/902.test.cpp
    title: test/3_yukicoder/902.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"ds/removable_queue.hpp\"\n\ntemplate <typename QUE_TYPE>\n\
    struct Removable_Queue {\n  using QUE = QUE_TYPE;\n  using T = typename QUE::value_type;\n\
    \n  QUE que, rm_que;\n\n  Removable_Queue() {}\n  Removable_Queue(vc<T>& dat)\
    \ : que(all(dat)) {}\n\n  void push(T x) { que.push(x); }\n  int size() { return\
    \ len(que) - len(rm_que); }\n  bool empty() { return size() == 0; }\n\n  T pop()\
    \ {\n    refresh();\n    return POP(que);\n  }\n  T top() {\n    refresh();\n\
    \    return que.top();\n  }\n\n  void remove(T x) { rm_que.push(x); }\n\nprivate:\n\
    \  void refresh() {\n    while (len(rm_que) && rm_que.top() == que.top()) {\n\
    \      rm_que.pop(), que.pop();\n    }\n  }\n};\n"
  code: "#pragma once\n\ntemplate <typename QUE_TYPE>\nstruct Removable_Queue {\n\
    \  using QUE = QUE_TYPE;\n  using T = typename QUE::value_type;\n\n  QUE que,\
    \ rm_que;\n\n  Removable_Queue() {}\n  Removable_Queue(vc<T>& dat) : que(all(dat))\
    \ {}\n\n  void push(T x) { que.push(x); }\n  int size() { return len(que) - len(rm_que);\
    \ }\n  bool empty() { return size() == 0; }\n\n  T pop() {\n    refresh();\n \
    \   return POP(que);\n  }\n  T top() {\n    refresh();\n    return que.top();\n\
    \  }\n\n  void remove(T x) { rm_que.push(x); }\n\nprivate:\n  void refresh() {\n\
    \    while (len(rm_que) && rm_que.top() == que.top()) {\n      rm_que.pop(), que.pop();\n\
    \    }\n  }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: ds/removable_queue.hpp
  requiredBy:
  - ds/slide_split_sum.hpp
  timestamp: '2024-02-24 23:26:31+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/3_yukicoder/772.test.cpp
  - test/3_yukicoder/2654.test.cpp
  - test/3_yukicoder/902.test.cpp
  - test/2_library_checker/data_structure/double_ended_pq.test.cpp
documentation_of: ds/removable_queue.hpp
layout: document
redirect_from:
- /library/ds/removable_queue.hpp
- /library/ds/removable_queue.hpp.html
title: ds/removable_queue.hpp
---
