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
    links:
    - https://github.com/maspypy/library/blob/main/other/io2.hpp
  bundledCode: "#line 1 \"other/io2.hpp\"\n// Source: https://github.com/maspypy/library/blob/main/other/io2.hpp\n\
    #define INT(...)   \\\n  int __VA_ARGS__; \\\n  IN(__VA_ARGS__)\n#define LL(...)\
    \   \\\n  ll __VA_ARGS__; \\\n  IN(__VA_ARGS__)\n#define STR(...)      \\\n  string\
    \ __VA_ARGS__; \\\n  IN(__VA_ARGS__)\n#define CHR(...)    \\\n  char __VA_ARGS__;\
    \ \\\n  IN(__VA_ARGS__)\n#define DBL(...)           \\\n  long double __VA_ARGS__;\
    \ \\\n  IN(__VA_ARGS__)\n\n#define VEC(type, name, size) \\\n  vector<type> name(size);\
    \    \\\n  read(name)\n#define VV(type, name, h, w)                     \\\n \
    \ vector<vector<type>> name(h, vector<type>(w)); \\\n  read(name)\n\nvoid read(int\
    \ &a) { cin >> a; }\nvoid read(long long &a) { cin >> a; }\nvoid read(char &a)\
    \ { cin >> a; }\nvoid read(double &a) { cin >> a; }\nvoid read(long double &a)\
    \ { cin >> a; }\nvoid read(string &a) { cin >> a; }\ntemplate <class T, class\
    \ S>\nvoid read(pair<T, S> &p) {\n  read(p.first), read(p.second);\n}\ntemplate\
    \ <class T>\nvoid read(vector<T> &a) {\n  for (auto &i : a) read(i);\n}\ntemplate\
    \ <class T>\nvoid read(T &a) {\n  cin >> a;\n}\nvoid IN() {}\ntemplate <class\
    \ Head, class... Tail>\nvoid IN(Head &head, Tail &...tail) {\n  read(head);\n\
    \  IN(tail...);\n}\n\ntemplate <typename T, typename U>\nostream &operator<<(ostream\
    \ &os, const pair<T, U> &A) {\n  os << A.fi << \" \" << A.se;\n  return os;\n\
    }\n\ntemplate <typename T>\nostream &operator<<(ostream &os, const vector<T> &A)\
    \ {\n  for (size_t i = 0; i < A.size(); i++) {\n    if (i) os << \" \";\n    os\
    \ << A[i];\n  }\n  return os;\n}\n\nclass CoutInitializer {\n public:\n  CoutInitializer()\
    \ { std::cout << std::fixed << std::setprecision(15); }\n};\nstatic CoutInitializer\
    \ cout_initializer;\n\nvoid print() {\n  cout << \"\\n\";\n  cout.flush();\n}\n\
    \ntemplate <class Head, class... Tail>\nvoid print(Head &&head, Tail &&...tail)\
    \ {\n  cout << head;\n  if (sizeof...(Tail)) cout << \" \";\n  print(forward<Tail>(tail)...);\n\
    }\n\n#if defined(LOCAL)\ntemplate <class... Ts>\ninline void _show_pack(const\
    \ char *func, int line, const char *names,\n                       Ts &&...args)\
    \ {\n  // [DEBUG] solve:123 \u306E\u3088\u3046\u306B\u5148\u982D\u306B\u51FA\u3059\
    \n  cout << \"[DEBUG \" << func << ':' << line << \"] \";\n\n  const char *p =\
    \ names;\n  bool first = true;\n\n  auto next_token = [&]() -> std::pair<const\
    \ char *, const char *> {\n    while (*p == ' ' || *p == ',') ++p;\n    const\
    \ char *l = p;\n    while (*p && *p != ',') ++p;\n    const char *r = p;\n   \
    \ return {l, r};\n  };\n\n  (\n      [&] {\n        auto [l, r] = next_token();\n\
    \        while (r > l && r[-1] == ' ') --r;\n        if (!first) cout << ' ';\n\
    \        first = false;\n        std::string name(l, r);\n        cout << name\
    \ << \" = \" << args;\n      }(),\n      ...);\n  print();\n}\n\n#define SHOW(...)\
    \ _show_pack(__func__, __LINE__, #__VA_ARGS__, __VA_ARGS__)\n#else\n#define SHOW(...)\n\
    #endif\n\nvoid YES(bool t = 1) { print(t ? \"YES\" : \"NO\"); }\nvoid NO(bool\
    \ t = 1) { YES(!t); }\nvoid Yes(bool t = 1) { print(t ? \"Yes\" : \"No\"); }\n\
    void No(bool t = 1) { Yes(!t); }\nvoid yes(bool t = 1) { print(t ? \"yes\" : \"\
    no\"); }\nvoid no(bool t = 1) { yes(!t); }\n"
  code: "// Source: https://github.com/maspypy/library/blob/main/other/io2.hpp\n#define\
    \ INT(...)   \\\n  int __VA_ARGS__; \\\n  IN(__VA_ARGS__)\n#define LL(...)   \\\
    \n  ll __VA_ARGS__; \\\n  IN(__VA_ARGS__)\n#define STR(...)      \\\n  string\
    \ __VA_ARGS__; \\\n  IN(__VA_ARGS__)\n#define CHR(...)    \\\n  char __VA_ARGS__;\
    \ \\\n  IN(__VA_ARGS__)\n#define DBL(...)           \\\n  long double __VA_ARGS__;\
    \ \\\n  IN(__VA_ARGS__)\n\n#define VEC(type, name, size) \\\n  vector<type> name(size);\
    \    \\\n  read(name)\n#define VV(type, name, h, w)                     \\\n \
    \ vector<vector<type>> name(h, vector<type>(w)); \\\n  read(name)\n\nvoid read(int\
    \ &a) { cin >> a; }\nvoid read(long long &a) { cin >> a; }\nvoid read(char &a)\
    \ { cin >> a; }\nvoid read(double &a) { cin >> a; }\nvoid read(long double &a)\
    \ { cin >> a; }\nvoid read(string &a) { cin >> a; }\ntemplate <class T, class\
    \ S>\nvoid read(pair<T, S> &p) {\n  read(p.first), read(p.second);\n}\ntemplate\
    \ <class T>\nvoid read(vector<T> &a) {\n  for (auto &i : a) read(i);\n}\ntemplate\
    \ <class T>\nvoid read(T &a) {\n  cin >> a;\n}\nvoid IN() {}\ntemplate <class\
    \ Head, class... Tail>\nvoid IN(Head &head, Tail &...tail) {\n  read(head);\n\
    \  IN(tail...);\n}\n\ntemplate <typename T, typename U>\nostream &operator<<(ostream\
    \ &os, const pair<T, U> &A) {\n  os << A.fi << \" \" << A.se;\n  return os;\n\
    }\n\ntemplate <typename T>\nostream &operator<<(ostream &os, const vector<T> &A)\
    \ {\n  for (size_t i = 0; i < A.size(); i++) {\n    if (i) os << \" \";\n    os\
    \ << A[i];\n  }\n  return os;\n}\n\nclass CoutInitializer {\n public:\n  CoutInitializer()\
    \ { std::cout << std::fixed << std::setprecision(15); }\n};\nstatic CoutInitializer\
    \ cout_initializer;\n\nvoid print() {\n  cout << \"\\n\";\n  cout.flush();\n}\n\
    \ntemplate <class Head, class... Tail>\nvoid print(Head &&head, Tail &&...tail)\
    \ {\n  cout << head;\n  if (sizeof...(Tail)) cout << \" \";\n  print(forward<Tail>(tail)...);\n\
    }\n\n#if defined(LOCAL)\ntemplate <class... Ts>\ninline void _show_pack(const\
    \ char *func, int line, const char *names,\n                       Ts &&...args)\
    \ {\n  // [DEBUG] solve:123 \u306E\u3088\u3046\u306B\u5148\u982D\u306B\u51FA\u3059\
    \n  cout << \"[DEBUG \" << func << ':' << line << \"] \";\n\n  const char *p =\
    \ names;\n  bool first = true;\n\n  auto next_token = [&]() -> std::pair<const\
    \ char *, const char *> {\n    while (*p == ' ' || *p == ',') ++p;\n    const\
    \ char *l = p;\n    while (*p && *p != ',') ++p;\n    const char *r = p;\n   \
    \ return {l, r};\n  };\n\n  (\n      [&] {\n        auto [l, r] = next_token();\n\
    \        while (r > l && r[-1] == ' ') --r;\n        if (!first) cout << ' ';\n\
    \        first = false;\n        std::string name(l, r);\n        cout << name\
    \ << \" = \" << args;\n      }(),\n      ...);\n  print();\n}\n\n#define SHOW(...)\
    \ _show_pack(__func__, __LINE__, #__VA_ARGS__, __VA_ARGS__)\n#else\n#define SHOW(...)\n\
    #endif\n\nvoid YES(bool t = 1) { print(t ? \"YES\" : \"NO\"); }\nvoid NO(bool\
    \ t = 1) { YES(!t); }\nvoid Yes(bool t = 1) { print(t ? \"Yes\" : \"No\"); }\n\
    void No(bool t = 1) { Yes(!t); }\nvoid yes(bool t = 1) { print(t ? \"yes\" : \"\
    no\"); }\nvoid no(bool t = 1) { yes(!t); }\n"
  dependsOn: []
  isVerificationFile: false
  path: other/io2.hpp
  requiredBy: []
  timestamp: '2026-10-15 19:54:56+09:00'
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
