---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links:
    - https://judge.yosupo.jp/submission/21623
    - https://judge.yosupo.jp/submission/70667
  bundledCode: "#line 1 \"other/io_mmap.hpp\"\n\n#include <unistd.h>\n#include <sys/mman.h>\n\
    #include <sys/stat.h>\n\nnamespace fastio {\n// https://judge.yosupo.jp/submission/21623\n\
    // https://judge.yosupo.jp/submission/70667\n\nstruct Pre {\n  char num[10000][4];\n\
    \  constexpr Pre() : num() {\n    for (int i = 0; i < 10000; i++) {\n      int\
    \ n = i;\n      for (int j = 3; j >= 0; j--) {\n        num[i][j] = n % 10 | '0';\n\
    \        n /= 10;\n      }\n    }\n  }\n} constexpr pre;\n\nconstexpr int BSZ\
    \ = 1 << 19;\nchar *ibuf, obuf[BSZ], out[100];\nint outi, obufi;\n\n// gcc expansion.\
    \ called automaticall before main.\nvoid __attribute__((constructor)) _c() {\n\
    \  struct stat sb;\n  fstat(0, &sb);\n  ibuf\n      = (char *)mmap(0, sb.st_size,\
    \ PROT_READ, MAP_SHARED | MAP_POPULATE, 0, 0);\n}\n\nvoid flush() { write(1, obuf,\
    \ obufi), obufi = 0; }\n\nvoid rd(char &c) { c = *ibuf++; }\nvoid rd(string &x)\
    \ {\n  x.clear();\n  char c;\n  do { rd(c); } while (isspace(c));\n  do { x +=\
    \ c, rd(c); } while (!isspace(c));\n}\n\ntemplate <typename T>\nvoid rd_integer(T\
    \ &x) {\n  char c;\n  do\n    rd(c);\n  while (c < '-');\n  bool minus = 0;\n\
    \  if constexpr (is_signed<T>::value || is_same_v<T, i128>) {\n    if (c == '-')\
    \ { minus = 1, rd(c); }\n  }\n  x = 0;\n  while (c >= '0') { x = x * 10 + (c &\
    \ 15), rd(c); }\n  if constexpr (is_signed<T>::value || is_same_v<T, i128>) {\n\
    \    if (minus) x = -x;\n  }\n}\n\ntemplate <typename T>\nvoid rd_real(T &x) {\n\
    \  string s;\n  rd(s);\n  x = stod(s);\n}\n\nvoid rd(int &x) { rd_integer(x);\
    \ }\nvoid rd(ll &x) { rd_integer(x); }\nvoid rd(i128 &x) { rd_integer(x); }\n\
    void rd(u32 &x) { rd_integer(x); }\nvoid rd(u64 &x) { rd_integer(x); }\nvoid rd(u128\
    \ &x) { rd_integer(x); }\nvoid rd(double &x) { rd_real(x); }\nvoid rd(long double\
    \ &x) { rd_real(x); }\nvoid rd(f128 &x) { rd_real(x); }\ntemplate <class T>\n\
    void rd(vc<T> &x) {\n  for (auto &d: x) rd(d);\n}\ntemplate <size_t N = 0, typename\
    \ T>\nvoid rd(array<T, N> &x) {\n  for (auto &d: x) rd(d);\n}\ntemplate <class\
    \ T, class U>\nvoid rd(pair<T, U> &p) {\n  return rd(p.first), rd(p.second);\n\
    }\ntemplate <size_t N = 0, typename T>\nvoid rd(T &t) {\n  if constexpr (N < std::tuple_size<T>::value)\
    \ {\n    auto &x = std::get<N>(t);\n    rd(x);\n    rd<N + 1>(t);\n  }\n}\ntemplate\
    \ <class... T>\nvoid rd(tuple<T...> &tpl) {\n  rd(tpl);\n}\n\nvoid read() {}\n\
    template <class H, class... T>\nvoid read(H &h, T &... t) {\n  rd(h), read(t...);\n\
    }\n\nvoid wt(const char c) {\n  if (obufi == BSZ) flush();\n  obuf[obufi++] =\
    \ c;\n}\nvoid wt(const string &s) {\n  for (char c: s) wt(c);\n}\n\ntemplate <typename\
    \ T>\nvoid wt_integer(T x) {\n  if (obufi > BSZ - 100) flush();\n  if (x < 0)\
    \ { obuf[obufi++] = '-', x = -x; }\n  for (outi = 96; x >= 10000; outi -= 4) {\n\
    \    memcpy(out + outi, pre.num[x % 10000], 4);\n    x /= 10000;\n  }\n  if (x\
    \ >= 1000) {\n    memcpy(obuf + obufi, pre.num[x], 4);\n    obufi += 4;\n  } else\
    \ if (x >= 100) {\n    memcpy(obuf + obufi, pre.num[x] + 1, 3);\n    obufi +=\
    \ 3;\n  } else if (x >= 10) {\n    int q = (x * 103) >> 10;\n    obuf[obufi] =\
    \ q | '0';\n    obuf[obufi + 1] = (x - q * 10) | '0';\n    obufi += 2;\n  } else\n\
    \    obuf[obufi++] = x | '0';\n  memcpy(obuf + obufi, out + outi + 4, 96 - outi);\n\
    \  obufi += 96 - outi;\n}\n\ntemplate <typename T>\nvoid wt_real(T x) {\n  ostringstream\
    \ oss;\n  oss << fixed << setprecision(15) << double(x);\n  string s = oss.str();\n\
    \  wt(s);\n}\n\nvoid wt(int x) { wt_integer(x); }\nvoid wt(ll x) { wt_integer(x);\
    \ }\nvoid wt(i128 x) { wt_integer(x); }\nvoid wt(u32 x) { wt_integer(x); }\nvoid\
    \ wt(u64 x) { wt_integer(x); }\nvoid wt(u128 x) { wt_integer(x); }\nvoid wt(double\
    \ x) { wt_real(x); }\nvoid wt(long double x) { wt_real(x); }\nvoid wt(f128 x)\
    \ { wt_real(x); }\n\ntemplate <class T>\nvoid wt(const vector<T> val) {\n  auto\
    \ n = val.size();\n  for (size_t i = 0; i < n; i++) {\n    if (i) wt(' ');\n \
    \   wt(val[i]);\n  }\n}\ntemplate <class T, class U>\nvoid wt(const pair<T, U>\
    \ val) {\n  wt(val.first);\n  wt(' ');\n  wt(val.second);\n}\ntemplate <size_t\
    \ N = 0, typename T>\nvoid wt_tuple(const T t) {\n  if constexpr (N < std::tuple_size<T>::value)\
    \ {\n    if constexpr (N > 0) { wt(' '); }\n    const auto x = std::get<N>(t);\n\
    \    wt(x);\n    wt_tuple<N + 1>(t);\n  }\n}\ntemplate <class... T>\nvoid wt(tuple<T...>\
    \ tpl) {\n  wt_tuple(tpl);\n}\ntemplate <class T, size_t S>\nvoid wt(const array<T,\
    \ S> val) {\n  auto n = val.size();\n  for (size_t i = 0; i < n; i++) {\n    if\
    \ (i) wt(' ');\n    wt(val[i]);\n  }\n}\n\nvoid print() { wt('\\n'); }\ntemplate\
    \ <class Head, class... Tail>\nvoid print(Head &&head, Tail &&... tail) {\n  wt(head);\n\
    \  if (sizeof...(Tail)) wt(' ');\n  print(forward<Tail>(tail)...);\n}\n\n// gcc\
    \ expansion. called automaticall after main.\nvoid __attribute__((destructor))\
    \ _d() { flush(); }\n} // namespace fastio\n\nusing fastio::read;\nusing fastio::print;\n\
    using fastio::flush;\n\n#define INT(...)   \\\n  int __VA_ARGS__; \\\n  read(__VA_ARGS__)\n\
    #define LL(...)   \\\n  ll __VA_ARGS__; \\\n  read(__VA_ARGS__)\n#define STR(...)\
    \      \\\n  string __VA_ARGS__; \\\n  read(__VA_ARGS__)\n#define CHAR(...)  \
    \ \\\n  char __VA_ARGS__; \\\n  read(__VA_ARGS__)\n#define DBL(...)      \\\n\
    \  double __VA_ARGS__; \\\n  read(__VA_ARGS__)\n\n#define VEC(type, name, size)\
    \ \\\n  vector<type> name(size);    \\\n  read(name)\n#define VV(type, name, h,\
    \ w)                     \\\n  vector<vector<type>> name(h, vector<type>(w));\
    \ \\\n  read(name)\n\nvoid YES(bool t = 1) { print(t ? \"YES\" : \"NO\"); }\n\
    void NO(bool t = 1) { YES(!t); }\nvoid Yes(bool t = 1) { print(t ? \"Yes\" : \"\
    No\"); }\nvoid No(bool t = 1) { Yes(!t); }\nvoid yes(bool t = 1) { print(t ? \"\
    yes\" : \"no\"); }\nvoid no(bool t = 1) { yes(!t); }\n"
  code: "\n#include <unistd.h>\n#include <sys/mman.h>\n#include <sys/stat.h>\n\nnamespace\
    \ fastio {\n// https://judge.yosupo.jp/submission/21623\n// https://judge.yosupo.jp/submission/70667\n\
    \nstruct Pre {\n  char num[10000][4];\n  constexpr Pre() : num() {\n    for (int\
    \ i = 0; i < 10000; i++) {\n      int n = i;\n      for (int j = 3; j >= 0; j--)\
    \ {\n        num[i][j] = n % 10 | '0';\n        n /= 10;\n      }\n    }\n  }\n\
    } constexpr pre;\n\nconstexpr int BSZ = 1 << 19;\nchar *ibuf, obuf[BSZ], out[100];\n\
    int outi, obufi;\n\n// gcc expansion. called automaticall before main.\nvoid __attribute__((constructor))\
    \ _c() {\n  struct stat sb;\n  fstat(0, &sb);\n  ibuf\n      = (char *)mmap(0,\
    \ sb.st_size, PROT_READ, MAP_SHARED | MAP_POPULATE, 0, 0);\n}\n\nvoid flush()\
    \ { write(1, obuf, obufi), obufi = 0; }\n\nvoid rd(char &c) { c = *ibuf++; }\n\
    void rd(string &x) {\n  x.clear();\n  char c;\n  do { rd(c); } while (isspace(c));\n\
    \  do { x += c, rd(c); } while (!isspace(c));\n}\n\ntemplate <typename T>\nvoid\
    \ rd_integer(T &x) {\n  char c;\n  do\n    rd(c);\n  while (c < '-');\n  bool\
    \ minus = 0;\n  if constexpr (is_signed<T>::value || is_same_v<T, i128>) {\n \
    \   if (c == '-') { minus = 1, rd(c); }\n  }\n  x = 0;\n  while (c >= '0') { x\
    \ = x * 10 + (c & 15), rd(c); }\n  if constexpr (is_signed<T>::value || is_same_v<T,\
    \ i128>) {\n    if (minus) x = -x;\n  }\n}\n\ntemplate <typename T>\nvoid rd_real(T\
    \ &x) {\n  string s;\n  rd(s);\n  x = stod(s);\n}\n\nvoid rd(int &x) { rd_integer(x);\
    \ }\nvoid rd(ll &x) { rd_integer(x); }\nvoid rd(i128 &x) { rd_integer(x); }\n\
    void rd(u32 &x) { rd_integer(x); }\nvoid rd(u64 &x) { rd_integer(x); }\nvoid rd(u128\
    \ &x) { rd_integer(x); }\nvoid rd(double &x) { rd_real(x); }\nvoid rd(long double\
    \ &x) { rd_real(x); }\nvoid rd(f128 &x) { rd_real(x); }\ntemplate <class T>\n\
    void rd(vc<T> &x) {\n  for (auto &d: x) rd(d);\n}\ntemplate <size_t N = 0, typename\
    \ T>\nvoid rd(array<T, N> &x) {\n  for (auto &d: x) rd(d);\n}\ntemplate <class\
    \ T, class U>\nvoid rd(pair<T, U> &p) {\n  return rd(p.first), rd(p.second);\n\
    }\ntemplate <size_t N = 0, typename T>\nvoid rd(T &t) {\n  if constexpr (N < std::tuple_size<T>::value)\
    \ {\n    auto &x = std::get<N>(t);\n    rd(x);\n    rd<N + 1>(t);\n  }\n}\ntemplate\
    \ <class... T>\nvoid rd(tuple<T...> &tpl) {\n  rd(tpl);\n}\n\nvoid read() {}\n\
    template <class H, class... T>\nvoid read(H &h, T &... t) {\n  rd(h), read(t...);\n\
    }\n\nvoid wt(const char c) {\n  if (obufi == BSZ) flush();\n  obuf[obufi++] =\
    \ c;\n}\nvoid wt(const string &s) {\n  for (char c: s) wt(c);\n}\n\ntemplate <typename\
    \ T>\nvoid wt_integer(T x) {\n  if (obufi > BSZ - 100) flush();\n  if (x < 0)\
    \ { obuf[obufi++] = '-', x = -x; }\n  for (outi = 96; x >= 10000; outi -= 4) {\n\
    \    memcpy(out + outi, pre.num[x % 10000], 4);\n    x /= 10000;\n  }\n  if (x\
    \ >= 1000) {\n    memcpy(obuf + obufi, pre.num[x], 4);\n    obufi += 4;\n  } else\
    \ if (x >= 100) {\n    memcpy(obuf + obufi, pre.num[x] + 1, 3);\n    obufi +=\
    \ 3;\n  } else if (x >= 10) {\n    int q = (x * 103) >> 10;\n    obuf[obufi] =\
    \ q | '0';\n    obuf[obufi + 1] = (x - q * 10) | '0';\n    obufi += 2;\n  } else\n\
    \    obuf[obufi++] = x | '0';\n  memcpy(obuf + obufi, out + outi + 4, 96 - outi);\n\
    \  obufi += 96 - outi;\n}\n\ntemplate <typename T>\nvoid wt_real(T x) {\n  ostringstream\
    \ oss;\n  oss << fixed << setprecision(15) << double(x);\n  string s = oss.str();\n\
    \  wt(s);\n}\n\nvoid wt(int x) { wt_integer(x); }\nvoid wt(ll x) { wt_integer(x);\
    \ }\nvoid wt(i128 x) { wt_integer(x); }\nvoid wt(u32 x) { wt_integer(x); }\nvoid\
    \ wt(u64 x) { wt_integer(x); }\nvoid wt(u128 x) { wt_integer(x); }\nvoid wt(double\
    \ x) { wt_real(x); }\nvoid wt(long double x) { wt_real(x); }\nvoid wt(f128 x)\
    \ { wt_real(x); }\n\ntemplate <class T>\nvoid wt(const vector<T> val) {\n  auto\
    \ n = val.size();\n  for (size_t i = 0; i < n; i++) {\n    if (i) wt(' ');\n \
    \   wt(val[i]);\n  }\n}\ntemplate <class T, class U>\nvoid wt(const pair<T, U>\
    \ val) {\n  wt(val.first);\n  wt(' ');\n  wt(val.second);\n}\ntemplate <size_t\
    \ N = 0, typename T>\nvoid wt_tuple(const T t) {\n  if constexpr (N < std::tuple_size<T>::value)\
    \ {\n    if constexpr (N > 0) { wt(' '); }\n    const auto x = std::get<N>(t);\n\
    \    wt(x);\n    wt_tuple<N + 1>(t);\n  }\n}\ntemplate <class... T>\nvoid wt(tuple<T...>\
    \ tpl) {\n  wt_tuple(tpl);\n}\ntemplate <class T, size_t S>\nvoid wt(const array<T,\
    \ S> val) {\n  auto n = val.size();\n  for (size_t i = 0; i < n; i++) {\n    if\
    \ (i) wt(' ');\n    wt(val[i]);\n  }\n}\n\nvoid print() { wt('\\n'); }\ntemplate\
    \ <class Head, class... Tail>\nvoid print(Head &&head, Tail &&... tail) {\n  wt(head);\n\
    \  if (sizeof...(Tail)) wt(' ');\n  print(forward<Tail>(tail)...);\n}\n\n// gcc\
    \ expansion. called automaticall after main.\nvoid __attribute__((destructor))\
    \ _d() { flush(); }\n} // namespace fastio\n\nusing fastio::read;\nusing fastio::print;\n\
    using fastio::flush;\n\n#define INT(...)   \\\n  int __VA_ARGS__; \\\n  read(__VA_ARGS__)\n\
    #define LL(...)   \\\n  ll __VA_ARGS__; \\\n  read(__VA_ARGS__)\n#define STR(...)\
    \      \\\n  string __VA_ARGS__; \\\n  read(__VA_ARGS__)\n#define CHAR(...)  \
    \ \\\n  char __VA_ARGS__; \\\n  read(__VA_ARGS__)\n#define DBL(...)      \\\n\
    \  double __VA_ARGS__; \\\n  read(__VA_ARGS__)\n\n#define VEC(type, name, size)\
    \ \\\n  vector<type> name(size);    \\\n  read(name)\n#define VV(type, name, h,\
    \ w)                     \\\n  vector<vector<type>> name(h, vector<type>(w));\
    \ \\\n  read(name)\n\nvoid YES(bool t = 1) { print(t ? \"YES\" : \"NO\"); }\n\
    void NO(bool t = 1) { YES(!t); }\nvoid Yes(bool t = 1) { print(t ? \"Yes\" : \"\
    No\"); }\nvoid No(bool t = 1) { Yes(!t); }\nvoid yes(bool t = 1) { print(t ? \"\
    yes\" : \"no\"); }\nvoid no(bool t = 1) { yes(!t); }"
  dependsOn: []
  isVerificationFile: false
  path: other/io_mmap.hpp
  requiredBy: []
  timestamp: '2024-05-04 19:14:00+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: other/io_mmap.hpp
layout: document
redirect_from:
- /library/other/io_mmap.hpp
- /library/other/io_mmap.hpp.html
title: other/io_mmap.hpp
---
