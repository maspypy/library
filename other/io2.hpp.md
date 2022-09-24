---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/ITP1_9_A.test.cpp
    title: test/aoj/ITP1_9_A.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"other/io2.hpp\"\n#define INT(...) \\\r\n  int __VA_ARGS__;\
    \ \\\r\n  IN(__VA_ARGS__)\r\n#define LL(...) \\\r\n  ll __VA_ARGS__; \\\r\n  IN(__VA_ARGS__)\r\
    \n#define STR(...) \\\r\n  string __VA_ARGS__; \\\r\n  IN(__VA_ARGS__)\r\n#define\
    \ CHR(...) \\\r\n  char __VA_ARGS__; \\\r\n  IN(__VA_ARGS__)\r\n#define DBL(...)\
    \ \\\r\n  long double __VA_ARGS__; \\\r\n  IN(__VA_ARGS__)\r\n\r\n#define VEC(type,\
    \ name, size) \\\r\n  vector<type> name(size);    \\\r\n  read(name)\r\n#define\
    \ VV(type, name, h, w)                     \\\r\n  vector<vector<type>> name(h,\
    \ vector<type>(w)); \\\r\n  read(name)\r\n\r\nvoid read(int &a) { cin >> a; }\r\
    \nvoid read(long long &a) { cin >> a; }\r\nvoid read(char &a) { cin >> a; }\r\n\
    void read(double &a) { cin >> a; }\r\nvoid read(long double &a) { cin >> a; }\r\
    \nvoid read(string &a) { cin >> a; }\r\ntemplate <class T, class S> void read(pair<T,\
    \ S> &p) { read(p.first), read(p.second); }\r\ntemplate <class T> void read(vector<T>\
    \ &a) {for(auto &i : a) read(i);}\r\ntemplate <class T> void read(T &a) { cin\
    \ >> a; }\r\nvoid IN() {}\r\ntemplate <class Head, class... Tail> void IN(Head\
    \ &head, Tail &...tail) {\r\n  read(head);\r\n  IN(tail...);\r\n}\r\n\r\ntemplate\
    \ <typename T, typename U>\r\nostream& operator<<(ostream& os, const pair<T, U>&\
    \ A) {\r\n  os << A.fi << \" \" << A.se;\r\n  return os;\r\n}\r\n\r\ntemplate\
    \ <typename T>\r\nostream& operator<<(ostream& os, const vector<T>& A) {\r\n \
    \ for (size_t i = 0; i < A.size(); i++) {\r\n    if(i) os << \" \";\r\n    os\
    \ << A[i];\r\n  }\r\n  return os;\r\n}\r\n\r\nvoid print() {\r\n  cout << \"\\\
    n\";\r\n  cout.flush();\r\n}\r\n\r\ntemplate <class Head, class... Tail>\r\nvoid\
    \ print(Head&& head, Tail&&... tail) {\r\n  cout << head;\r\n  if (sizeof...(Tail))\
    \ cout << \" \";\r\n  print(forward<Tail>(tail)...);\r\n}\r\n\r\nvoid YES(bool\
    \ t = 1) { print(t ? \"YES\" : \"NO\"); }\r\nvoid NO(bool t = 1) { YES(!t); }\r\
    \nvoid Yes(bool t = 1) { print(t ? \"Yes\" : \"No\"); }\r\nvoid No(bool t = 1)\
    \ { Yes(!t); }\r\nvoid yes(bool t = 1) { print(t ? \"yes\" : \"no\"); }\r\nvoid\
    \ no(bool t = 1) { yes(!t); }\r\n"
  code: "#define INT(...) \\\r\n  int __VA_ARGS__; \\\r\n  IN(__VA_ARGS__)\r\n#define\
    \ LL(...) \\\r\n  ll __VA_ARGS__; \\\r\n  IN(__VA_ARGS__)\r\n#define STR(...)\
    \ \\\r\n  string __VA_ARGS__; \\\r\n  IN(__VA_ARGS__)\r\n#define CHR(...) \\\r\
    \n  char __VA_ARGS__; \\\r\n  IN(__VA_ARGS__)\r\n#define DBL(...) \\\r\n  long\
    \ double __VA_ARGS__; \\\r\n  IN(__VA_ARGS__)\r\n\r\n#define VEC(type, name, size)\
    \ \\\r\n  vector<type> name(size);    \\\r\n  read(name)\r\n#define VV(type, name,\
    \ h, w)                     \\\r\n  vector<vector<type>> name(h, vector<type>(w));\
    \ \\\r\n  read(name)\r\n\r\nvoid read(int &a) { cin >> a; }\r\nvoid read(long\
    \ long &a) { cin >> a; }\r\nvoid read(char &a) { cin >> a; }\r\nvoid read(double\
    \ &a) { cin >> a; }\r\nvoid read(long double &a) { cin >> a; }\r\nvoid read(string\
    \ &a) { cin >> a; }\r\ntemplate <class T, class S> void read(pair<T, S> &p) {\
    \ read(p.first), read(p.second); }\r\ntemplate <class T> void read(vector<T> &a)\
    \ {for(auto &i : a) read(i);}\r\ntemplate <class T> void read(T &a) { cin >> a;\
    \ }\r\nvoid IN() {}\r\ntemplate <class Head, class... Tail> void IN(Head &head,\
    \ Tail &...tail) {\r\n  read(head);\r\n  IN(tail...);\r\n}\r\n\r\ntemplate <typename\
    \ T, typename U>\r\nostream& operator<<(ostream& os, const pair<T, U>& A) {\r\n\
    \  os << A.fi << \" \" << A.se;\r\n  return os;\r\n}\r\n\r\ntemplate <typename\
    \ T>\r\nostream& operator<<(ostream& os, const vector<T>& A) {\r\n  for (size_t\
    \ i = 0; i < A.size(); i++) {\r\n    if(i) os << \" \";\r\n    os << A[i];\r\n\
    \  }\r\n  return os;\r\n}\r\n\r\nvoid print() {\r\n  cout << \"\\n\";\r\n  cout.flush();\r\
    \n}\r\n\r\ntemplate <class Head, class... Tail>\r\nvoid print(Head&& head, Tail&&...\
    \ tail) {\r\n  cout << head;\r\n  if (sizeof...(Tail)) cout << \" \";\r\n  print(forward<Tail>(tail)...);\r\
    \n}\r\n\r\nvoid YES(bool t = 1) { print(t ? \"YES\" : \"NO\"); }\r\nvoid NO(bool\
    \ t = 1) { YES(!t); }\r\nvoid Yes(bool t = 1) { print(t ? \"Yes\" : \"No\"); }\r\
    \nvoid No(bool t = 1) { Yes(!t); }\r\nvoid yes(bool t = 1) { print(t ? \"yes\"\
    \ : \"no\"); }\r\nvoid no(bool t = 1) { yes(!t); }\r\n"
  dependsOn: []
  isVerificationFile: false
  path: other/io2.hpp
  requiredBy: []
  timestamp: '2022-04-16 04:26:49+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj/ITP1_9_A.test.cpp
documentation_of: other/io2.hpp
layout: document
redirect_from:
- /library/other/io2.hpp
- /library/other/io2.hpp.html
title: other/io2.hpp
---
