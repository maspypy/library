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
  bundledCode: "#line 1 \"ds/my_deque.hpp\"\n\ntemplate <typename T>\nstruct My_Deque\
    \ {\n  vc<T> dat1, dat2;\n\n  vc<T> get_all() {\n    vc<T> ANS(len(dat1) + len(dat2));\n\
    \    FOR(i, len(dat1)) ANS[i] = dat1[len(dat1) - 1 - i];\n    FOR(i, len(dat2))\
    \ ANS[len(dat1) + i] = dat2[i];\n    return ANS;\n  }\n\n  int size() { return\
    \ len(dat1) + len(dat2); }\n  bool empty() { return dat1.empty() && dat2.empty();\
    \ }\n  void reverse() { swap(dat1, dat2); }\n\n  void push_back(T x) { dat2.push_back(x);\
    \ }\n  void push_front(T x) { dat1.push_back(x); }\n\n  void push(T x) { push_back(x);\
    \ }\n\n  void clear() { dat1.clear(), dat2.clear(); }\n  void pop_front() {\n\
    \    assert(!empty());\n    if (size() == 1) return clear();\n    if (dat1.empty())\
    \ rebuild();\n    dat1.pop_back();\n  }\n\n  void pop_back() {\n    if (size()\
    \ == 1) return clear();\n    if (dat2.empty()) rebuild();\n    dat2.pop_back();\n\
    \  }\n\n  T& operator[](int i) {\n    assert(0 <= i && i < size());\n    return\
    \ (i < len(dat1) ? dat1[len(dat1) - 1 - i] : dat2[i - len(dat1)]);\n  }\n\n  T&\
    \ front() { return (*this)[0]; }\n  T& back() { return (*this)[size() - 1]; }\n\
    \n private:\n  void rebuild() {\n    ::reverse(all(dat1));\n    concat(dat1, dat2);\n\
    \    int m = len(dat1) / 2;\n    dat2 = {dat1.begin() + m, dat1.end()};\n    dat1.resize(m);\n\
    \    ::reverse(all(dat1));\n  }\n};\n"
  code: "\ntemplate <typename T>\nstruct My_Deque {\n  vc<T> dat1, dat2;\n\n  vc<T>\
    \ get_all() {\n    vc<T> ANS(len(dat1) + len(dat2));\n    FOR(i, len(dat1)) ANS[i]\
    \ = dat1[len(dat1) - 1 - i];\n    FOR(i, len(dat2)) ANS[len(dat1) + i] = dat2[i];\n\
    \    return ANS;\n  }\n\n  int size() { return len(dat1) + len(dat2); }\n  bool\
    \ empty() { return dat1.empty() && dat2.empty(); }\n  void reverse() { swap(dat1,\
    \ dat2); }\n\n  void push_back(T x) { dat2.push_back(x); }\n  void push_front(T\
    \ x) { dat1.push_back(x); }\n\n  void push(T x) { push_back(x); }\n\n  void clear()\
    \ { dat1.clear(), dat2.clear(); }\n  void pop_front() {\n    assert(!empty());\n\
    \    if (size() == 1) return clear();\n    if (dat1.empty()) rebuild();\n    dat1.pop_back();\n\
    \  }\n\n  void pop_back() {\n    if (size() == 1) return clear();\n    if (dat2.empty())\
    \ rebuild();\n    dat2.pop_back();\n  }\n\n  T& operator[](int i) {\n    assert(0\
    \ <= i && i < size());\n    return (i < len(dat1) ? dat1[len(dat1) - 1 - i] :\
    \ dat2[i - len(dat1)]);\n  }\n\n  T& front() { return (*this)[0]; }\n  T& back()\
    \ { return (*this)[size() - 1]; }\n\n private:\n  void rebuild() {\n    ::reverse(all(dat1));\n\
    \    concat(dat1, dat2);\n    int m = len(dat1) / 2;\n    dat2 = {dat1.begin()\
    \ + m, dat1.end()};\n    dat1.resize(m);\n    ::reverse(all(dat1));\n  }\n};"
  dependsOn: []
  isVerificationFile: false
  path: ds/my_deque.hpp
  requiredBy: []
  timestamp: '2025-11-18 00:27:27+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: ds/my_deque.hpp
layout: document
redirect_from:
- /library/ds/my_deque.hpp
- /library/ds/my_deque.hpp.html
title: ds/my_deque.hpp
---
