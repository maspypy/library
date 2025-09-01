---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/4_aoj/ITP1_9_A.test.cpp
    title: test/4_aoj/ITP1_9_A.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 1 \"other/io2.hpp\"\n#define INT(...)   \\\r\n  int __VA_ARGS__;\
    \ \\\r\n  IN(__VA_ARGS__)\r\n#define LL(...)   \\\r\n  ll __VA_ARGS__; \\\r\n\
    \  IN(__VA_ARGS__)\r\n#define STR(...)      \\\r\n  string __VA_ARGS__; \\\r\n\
    \  IN(__VA_ARGS__)\r\n#define CHR(...)    \\\r\n  char __VA_ARGS__; \\\r\n  IN(__VA_ARGS__)\r\
    \n#define DBL(...)           \\\r\n  long double __VA_ARGS__; \\\r\n  IN(__VA_ARGS__)\r\
    \n\r\n#define VEC(type, name, size) \\\r\n  vector<type> name(size);    \\\r\n\
    \  read(name)\r\n#define VV(type, name, h, w)                     \\\r\n  vector<vector<type>>\
    \ name(h, vector<type>(w)); \\\r\n  read(name)\r\n\r\nvoid read(int &a) { cin\
    \ >> a; }\r\nvoid read(long long &a) { cin >> a; }\r\nvoid read(char &a) { cin\
    \ >> a; }\r\nvoid read(double &a) { cin >> a; }\r\nvoid read(long double &a) {\
    \ cin >> a; }\r\nvoid read(string &a) { cin >> a; }\r\ntemplate <class T, class\
    \ S>\r\nvoid read(pair<T, S> &p) {\r\n  read(p.first), read(p.second);\r\n}\r\n\
    template <class T>\r\nvoid read(vector<T> &a) {\r\n  for (auto &i : a) read(i);\r\
    \n}\r\ntemplate <class T>\r\nvoid read(T &a) {\r\n  cin >> a;\r\n}\r\nvoid IN()\
    \ {}\r\ntemplate <class Head, class... Tail>\r\nvoid IN(Head &head, Tail &...tail)\
    \ {\r\n  read(head);\r\n  IN(tail...);\r\n}\r\n\r\ntemplate <typename T, typename\
    \ U>\r\nostream &operator<<(ostream &os, const pair<T, U> &A) {\r\n  os << A.fi\
    \ << \" \" << A.se;\r\n  return os;\r\n}\r\n\r\ntemplate <typename T>\r\nostream\
    \ &operator<<(ostream &os, const vector<T> &A) {\r\n  for (size_t i = 0; i < A.size();\
    \ i++) {\r\n    if (i) os << \" \";\r\n    os << A[i];\r\n  }\r\n  return os;\r\
    \n}\r\n\r\nclass CoutInitializer {\r\n public:\r\n  CoutInitializer() { std::cout\
    \ << std::defaultfloat << std::setprecision(15); }\r\n};\r\nstatic CoutInitializer\
    \ cout_initializer;\r\n\r\nvoid print() {\r\n  cout << \"\\n\";\r\n  cout.flush();\r\
    \n}\r\n\r\ntemplate <class Head, class... Tail>\r\nvoid print(Head &&head, Tail\
    \ &&...tail) {\r\n  cout << head;\r\n  if (sizeof...(Tail)) cout << \" \";\r\n\
    \  print(forward<Tail>(tail)...);\r\n}\r\n\r\n#if defined(LOCAL)\r\ntemplate <class...\
    \ Ts>\r\ninline void _show_pack(const char *func, int line, const char *names,\r\
    \n                       Ts &&...args) {\r\n  // [DEBUG] solve:123 \u306E\u3088\
    \u3046\u306B\u5148\u982D\u306B\u51FA\u3059\r\n  cout << \"[DEBUG \" << func <<\
    \ ':' << line << \"] \";\r\n\r\n  const char *p = names;\r\n  bool first = true;\r\
    \n\r\n  auto next_token = [&]() -> std::pair<const char *, const char *> {\r\n\
    \    while (*p == ' ' || *p == ',') ++p;\r\n    const char *l = p;\r\n    while\
    \ (*p && *p != ',') ++p;\r\n    const char *r = p;\r\n    return {l, r};\r\n \
    \ };\r\n\r\n  (\r\n      [&] {\r\n        auto [l, r] = next_token();\r\n    \
    \    while (r > l && r[-1] == ' ') --r;\r\n        if (!first) cout << ' ';\r\n\
    \        first = false;\r\n        std::string name(l, r);\r\n        cout <<\
    \ name << \" = \" << args;\r\n      }(),\r\n      ...);\r\n  print();\r\n}\r\n\
    \r\n#define SHOW(...) _show_pack(__func__, __LINE__, #__VA_ARGS__, __VA_ARGS__)\r\
    \n#else\r\n#define SHOW(...)\r\n#endif\r\n\r\nvoid YES(bool t = 1) { print(t ?\
    \ \"YES\" : \"NO\"); }\r\nvoid NO(bool t = 1) { YES(!t); }\r\nvoid Yes(bool t\
    \ = 1) { print(t ? \"Yes\" : \"No\"); }\r\nvoid No(bool t = 1) { Yes(!t); }\r\n\
    void yes(bool t = 1) { print(t ? \"yes\" : \"no\"); }\r\nvoid no(bool t = 1) {\
    \ yes(!t); }\r\n"
  code: "#define INT(...)   \\\r\n  int __VA_ARGS__; \\\r\n  IN(__VA_ARGS__)\r\n#define\
    \ LL(...)   \\\r\n  ll __VA_ARGS__; \\\r\n  IN(__VA_ARGS__)\r\n#define STR(...)\
    \      \\\r\n  string __VA_ARGS__; \\\r\n  IN(__VA_ARGS__)\r\n#define CHR(...)\
    \    \\\r\n  char __VA_ARGS__; \\\r\n  IN(__VA_ARGS__)\r\n#define DBL(...)   \
    \        \\\r\n  long double __VA_ARGS__; \\\r\n  IN(__VA_ARGS__)\r\n\r\n#define\
    \ VEC(type, name, size) \\\r\n  vector<type> name(size);    \\\r\n  read(name)\r\
    \n#define VV(type, name, h, w)                     \\\r\n  vector<vector<type>>\
    \ name(h, vector<type>(w)); \\\r\n  read(name)\r\n\r\nvoid read(int &a) { cin\
    \ >> a; }\r\nvoid read(long long &a) { cin >> a; }\r\nvoid read(char &a) { cin\
    \ >> a; }\r\nvoid read(double &a) { cin >> a; }\r\nvoid read(long double &a) {\
    \ cin >> a; }\r\nvoid read(string &a) { cin >> a; }\r\ntemplate <class T, class\
    \ S>\r\nvoid read(pair<T, S> &p) {\r\n  read(p.first), read(p.second);\r\n}\r\n\
    template <class T>\r\nvoid read(vector<T> &a) {\r\n  for (auto &i : a) read(i);\r\
    \n}\r\ntemplate <class T>\r\nvoid read(T &a) {\r\n  cin >> a;\r\n}\r\nvoid IN()\
    \ {}\r\ntemplate <class Head, class... Tail>\r\nvoid IN(Head &head, Tail &...tail)\
    \ {\r\n  read(head);\r\n  IN(tail...);\r\n}\r\n\r\ntemplate <typename T, typename\
    \ U>\r\nostream &operator<<(ostream &os, const pair<T, U> &A) {\r\n  os << A.fi\
    \ << \" \" << A.se;\r\n  return os;\r\n}\r\n\r\ntemplate <typename T>\r\nostream\
    \ &operator<<(ostream &os, const vector<T> &A) {\r\n  for (size_t i = 0; i < A.size();\
    \ i++) {\r\n    if (i) os << \" \";\r\n    os << A[i];\r\n  }\r\n  return os;\r\
    \n}\r\n\r\nclass CoutInitializer {\r\n public:\r\n  CoutInitializer() { std::cout\
    \ << std::defaultfloat << std::setprecision(15); }\r\n};\r\nstatic CoutInitializer\
    \ cout_initializer;\r\n\r\nvoid print() {\r\n  cout << \"\\n\";\r\n  cout.flush();\r\
    \n}\r\n\r\ntemplate <class Head, class... Tail>\r\nvoid print(Head &&head, Tail\
    \ &&...tail) {\r\n  cout << head;\r\n  if (sizeof...(Tail)) cout << \" \";\r\n\
    \  print(forward<Tail>(tail)...);\r\n}\r\n\r\n#if defined(LOCAL)\r\ntemplate <class...\
    \ Ts>\r\ninline void _show_pack(const char *func, int line, const char *names,\r\
    \n                       Ts &&...args) {\r\n  // [DEBUG] solve:123 \u306E\u3088\
    \u3046\u306B\u5148\u982D\u306B\u51FA\u3059\r\n  cout << \"[DEBUG \" << func <<\
    \ ':' << line << \"] \";\r\n\r\n  const char *p = names;\r\n  bool first = true;\r\
    \n\r\n  auto next_token = [&]() -> std::pair<const char *, const char *> {\r\n\
    \    while (*p == ' ' || *p == ',') ++p;\r\n    const char *l = p;\r\n    while\
    \ (*p && *p != ',') ++p;\r\n    const char *r = p;\r\n    return {l, r};\r\n \
    \ };\r\n\r\n  (\r\n      [&] {\r\n        auto [l, r] = next_token();\r\n    \
    \    while (r > l && r[-1] == ' ') --r;\r\n        if (!first) cout << ' ';\r\n\
    \        first = false;\r\n        std::string name(l, r);\r\n        cout <<\
    \ name << \" = \" << args;\r\n      }(),\r\n      ...);\r\n  print();\r\n}\r\n\
    \r\n#define SHOW(...) _show_pack(__func__, __LINE__, #__VA_ARGS__, __VA_ARGS__)\r\
    \n#else\r\n#define SHOW(...)\r\n#endif\r\n\r\nvoid YES(bool t = 1) { print(t ?\
    \ \"YES\" : \"NO\"); }\r\nvoid NO(bool t = 1) { YES(!t); }\r\nvoid Yes(bool t\
    \ = 1) { print(t ? \"Yes\" : \"No\"); }\r\nvoid No(bool t = 1) { Yes(!t); }\r\n\
    void yes(bool t = 1) { print(t ? \"yes\" : \"no\"); }\r\nvoid no(bool t = 1) {\
    \ yes(!t); }\r\n"
  dependsOn: []
  isVerificationFile: false
  path: other/io2.hpp
  requiredBy: []
  timestamp: '2025-09-01 20:37:38+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/4_aoj/ITP1_9_A.test.cpp
documentation_of: other/io2.hpp
layout: document
redirect_from:
- /library/other/io2.hpp
- /library/other/io2.hpp.html
title: other/io2.hpp
---
