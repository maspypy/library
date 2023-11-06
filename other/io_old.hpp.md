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
  bundledCode: "#line 1 \"other/io_old.hpp\"\n// based on yosupo's fastio\n#include\
    \ <unistd.h>\n\nnamespace fastio {\n#define FASTIO\nstruct has_write_impl {\n\
    \  template <class T>\n  static auto check(T &&x) -> decltype(x.write(), std::true_type{});\n\
    \n  template <class T>\n  static auto check(...) -> std::false_type;\n};\n\ntemplate\
    \ <class T>\nclass has_write : public decltype(has_write_impl::check<T>(std::declval<T>()))\
    \ {\n};\n\nstruct has_read_impl {\n  template <class T>\n  static auto check(T\
    \ &&x) -> decltype(x.read(), std::true_type{});\n\n  template <class T>\n  static\
    \ auto check(...) -> std::false_type;\n};\n\ntemplate <class T>\nclass has_read\
    \ : public decltype(has_read_impl::check<T>(std::declval<T>())) {};\n\nstruct\
    \ Scanner {\n  FILE *fp;\n  char line[(1 << 15) + 1];\n  size_t st = 0, ed = 0;\n\
    \  void reread() {\n    memmove(line, line + st, ed - st);\n    ed -= st;\n  \
    \  st = 0;\n    ed += fread(line + ed, 1, (1 << 15) - ed, fp);\n    line[ed] =\
    \ '\\0';\n  }\n  bool succ() {\n    while (true) {\n      if (st == ed) {\n  \
    \      reread();\n        if (st == ed) return false;\n      }\n      while (st\
    \ != ed && isspace(line[st])) st++;\n      if (st != ed) break;\n    }\n    if\
    \ (ed - st <= 50) {\n      bool sep = false;\n      for (size_t i = st; i < ed;\
    \ i++) {\n        if (isspace(line[i])) {\n          sep = true;\n          break;\n\
    \        }\n      }\n      if (!sep) reread();\n    }\n    return true;\n  }\n\
    \  template <class T, enable_if_t<is_same<T, string>::value, int> = 0>\n  bool\
    \ read_single(T &ref) {\n    if (!succ()) return false;\n    while (true) {\n\
    \      size_t sz = 0;\n      while (st + sz < ed && !isspace(line[st + sz])) sz++;\n\
    \      ref.append(line + st, sz);\n      st += sz;\n      if (!sz || st != ed)\
    \ break;\n      reread();\n    }\n    return true;\n  }\n  template <class T,\
    \ enable_if_t<is_integral<T>::value, int> = 0>\n  bool read_single(T &ref) {\n\
    \    if (!succ()) return false;\n    bool neg = false;\n    if (line[st] == '-')\
    \ {\n      neg = true;\n      st++;\n    }\n    ref = T(0);\n    while (isdigit(line[st]))\
    \ { ref = 10 * ref + (line[st++] & 0xf); }\n    if (neg) ref = -ref;\n    return\
    \ true;\n  }\n  template <typename T,\n            typename enable_if<has_read<T>::value>::type\
    \ * = nullptr>\n  inline bool read_single(T &x) {\n    x.read();\n    return true;\n\
    \  }\n  bool read_single(double &ref) {\n    string s;\n    if (!read_single(s))\
    \ return false;\n    ref = std::stod(s);\n    return true;\n  }\n  bool read_single(char\
    \ &ref) {\n    string s;\n    if (!read_single(s) || s.size() != 1) return false;\n\
    \    ref = s[0];\n    return true;\n  }\n  template <class T>\n  bool read_single(vector<T>\
    \ &ref) {\n    for (auto &d: ref) {\n      if (!read_single(d)) return false;\n\
    \    }\n    return true;\n  }\n  template <class T, class U>\n  bool read_single(pair<T,\
    \ U> &p) {\n    return (read_single(p.first) && read_single(p.second));\n  }\n\
    \  template <size_t N = 0, typename T>\n  void read_single_tuple(T &t) {\n   \
    \ if constexpr (N < std::tuple_size<T>::value) {\n      auto &x = std::get<N>(t);\n\
    \      read_single(x);\n      read_single_tuple<N + 1>(t);\n    }\n  }\n  template\
    \ <class... T>\n  bool read_single(tuple<T...> &tpl) {\n    read_single_tuple(tpl);\n\
    \    return true;\n  }\n  void read() {}\n  template <class H, class... T>\n \
    \ void read(H &h, T &... t) {\n    bool f = read_single(h);\n    assert(f);\n\
    \    read(t...);\n  }\n  Scanner(FILE *fp) : fp(fp) {}\n};\n\nstruct Printer {\n\
    \  Printer(FILE *_fp) : fp(_fp) {}\n  ~Printer() { flush(); }\n\n  static constexpr\
    \ size_t SIZE = 1 << 15;\n  FILE *fp;\n  char line[SIZE], small[50];\n  size_t\
    \ pos = 0;\n  void flush() {\n    fwrite(line, 1, pos, fp);\n    pos = 0;\n  }\n\
    \  void write(const char val) {\n    if (pos == SIZE) flush();\n    line[pos++]\
    \ = val;\n  }\n  template <class T, enable_if_t<is_integral<T>::value, int> =\
    \ 0>\n  void write(T val) {\n    if (pos > (1 << 15) - 50) flush();\n    if (val\
    \ == 0) {\n      write('0');\n      return;\n    }\n    if (val < 0) {\n     \
    \ write('-');\n      val = -val; // todo min\n    }\n    size_t len = 0;\n   \
    \ while (val) {\n      small[len++] = char(0x30 | (val % 10));\n      val /= 10;\n\
    \    }\n    for (size_t i = 0; i < len; i++) { line[pos + i] = small[len - 1 -\
    \ i]; }\n    pos += len;\n  }\n  void write(const string s) {\n    for (char c:\
    \ s) write(c);\n  }\n  void write(const char *s) {\n    size_t len = strlen(s);\n\
    \    for (size_t i = 0; i < len; i++) write(s[i]);\n  }\n  void write(const double\
    \ x) {\n    ostringstream oss;\n    oss << fixed << setprecision(15) << x;\n \
    \   string s = oss.str();\n    write(s);\n  }\n  void write(const long double\
    \ x) {\n    ostringstream oss;\n    oss << fixed << setprecision(15) << x;\n \
    \   string s = oss.str();\n    write(s);\n  }\n  template <typename T,\n     \
    \       typename enable_if<has_write<T>::value>::type * = nullptr>\n  inline void\
    \ write(T x) {\n    x.write();\n  }\n  template <class T>\n  void write(const\
    \ vector<T> val) {\n    auto n = val.size();\n    for (size_t i = 0; i < n; i++)\
    \ {\n      if (i) write(' ');\n      write(val[i]);\n    }\n  }\n  template <class\
    \ T, class U>\n  void write(const pair<T, U> val) {\n    write(val.first);\n \
    \   write(' ');\n    write(val.second);\n  }\n  template <size_t N = 0, typename\
    \ T>\n  void write_tuple(const T t) {\n    if constexpr (N < std::tuple_size<T>::value)\
    \ {\n      if constexpr (N > 0) { write(' '); }\n      const auto x = std::get<N>(t);\n\
    \      write(x);\n      write_tuple<N + 1>(t);\n    }\n  }\n  template <class...\
    \ T>\n  bool write(tuple<T...> tpl) {\n    write_tuple(tpl);\n    return true;\n\
    \  }\n  template <class T, size_t S>\n  void write(const array<T, S> val) {\n\
    \    auto n = val.size();\n    for (size_t i = 0; i < n; i++) {\n      if (i)\
    \ write(' ');\n      write(val[i]);\n    }\n  }\n  void write(i128 val) {\n  \
    \  string s;\n    bool negative = 0;\n    if (val < 0) {\n      negative = 1;\n\
    \      val = -val;\n    }\n    while (val) {\n      s += '0' + int(val % 10);\n\
    \      val /= 10;\n    }\n    if (negative) s += \"-\";\n    reverse(all(s));\n\
    \    if (len(s) == 0) s = \"0\";\n    write(s);\n  }\n};\nScanner scanner = Scanner(stdin);\n\
    Printer printer = Printer(stdout);\nvoid flush() { printer.flush(); }\nvoid print()\
    \ { printer.write('\\n'); }\ntemplate <class Head, class... Tail>\nvoid print(Head\
    \ &&head, Tail &&... tail) {\n  printer.write(head);\n  if (sizeof...(Tail)) printer.write('\
    \ ');\n  print(forward<Tail>(tail)...);\n}\n\nvoid read() {}\ntemplate <class\
    \ Head, class... Tail>\nvoid read(Head &head, Tail &... tail) {\n  scanner.read(head);\n\
    \  read(tail...);\n}\n} // namespace fastio\nusing fastio::print;\nusing fastio::flush;\n\
    using fastio::read;\n\n#define INT(...)   \\\n  int __VA_ARGS__; \\\n  read(__VA_ARGS__)\n\
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
  code: "// based on yosupo's fastio\n#include <unistd.h>\n\nnamespace fastio {\n\
    #define FASTIO\nstruct has_write_impl {\n  template <class T>\n  static auto check(T\
    \ &&x) -> decltype(x.write(), std::true_type{});\n\n  template <class T>\n  static\
    \ auto check(...) -> std::false_type;\n};\n\ntemplate <class T>\nclass has_write\
    \ : public decltype(has_write_impl::check<T>(std::declval<T>())) {\n};\n\nstruct\
    \ has_read_impl {\n  template <class T>\n  static auto check(T &&x) -> decltype(x.read(),\
    \ std::true_type{});\n\n  template <class T>\n  static auto check(...) -> std::false_type;\n\
    };\n\ntemplate <class T>\nclass has_read : public decltype(has_read_impl::check<T>(std::declval<T>()))\
    \ {};\n\nstruct Scanner {\n  FILE *fp;\n  char line[(1 << 15) + 1];\n  size_t\
    \ st = 0, ed = 0;\n  void reread() {\n    memmove(line, line + st, ed - st);\n\
    \    ed -= st;\n    st = 0;\n    ed += fread(line + ed, 1, (1 << 15) - ed, fp);\n\
    \    line[ed] = '\\0';\n  }\n  bool succ() {\n    while (true) {\n      if (st\
    \ == ed) {\n        reread();\n        if (st == ed) return false;\n      }\n\
    \      while (st != ed && isspace(line[st])) st++;\n      if (st != ed) break;\n\
    \    }\n    if (ed - st <= 50) {\n      bool sep = false;\n      for (size_t i\
    \ = st; i < ed; i++) {\n        if (isspace(line[i])) {\n          sep = true;\n\
    \          break;\n        }\n      }\n      if (!sep) reread();\n    }\n    return\
    \ true;\n  }\n  template <class T, enable_if_t<is_same<T, string>::value, int>\
    \ = 0>\n  bool read_single(T &ref) {\n    if (!succ()) return false;\n    while\
    \ (true) {\n      size_t sz = 0;\n      while (st + sz < ed && !isspace(line[st\
    \ + sz])) sz++;\n      ref.append(line + st, sz);\n      st += sz;\n      if (!sz\
    \ || st != ed) break;\n      reread();\n    }\n    return true;\n  }\n  template\
    \ <class T, enable_if_t<is_integral<T>::value, int> = 0>\n  bool read_single(T\
    \ &ref) {\n    if (!succ()) return false;\n    bool neg = false;\n    if (line[st]\
    \ == '-') {\n      neg = true;\n      st++;\n    }\n    ref = T(0);\n    while\
    \ (isdigit(line[st])) { ref = 10 * ref + (line[st++] & 0xf); }\n    if (neg) ref\
    \ = -ref;\n    return true;\n  }\n  template <typename T,\n            typename\
    \ enable_if<has_read<T>::value>::type * = nullptr>\n  inline bool read_single(T\
    \ &x) {\n    x.read();\n    return true;\n  }\n  bool read_single(double &ref)\
    \ {\n    string s;\n    if (!read_single(s)) return false;\n    ref = std::stod(s);\n\
    \    return true;\n  }\n  bool read_single(char &ref) {\n    string s;\n    if\
    \ (!read_single(s) || s.size() != 1) return false;\n    ref = s[0];\n    return\
    \ true;\n  }\n  template <class T>\n  bool read_single(vector<T> &ref) {\n   \
    \ for (auto &d: ref) {\n      if (!read_single(d)) return false;\n    }\n    return\
    \ true;\n  }\n  template <class T, class U>\n  bool read_single(pair<T, U> &p)\
    \ {\n    return (read_single(p.first) && read_single(p.second));\n  }\n  template\
    \ <size_t N = 0, typename T>\n  void read_single_tuple(T &t) {\n    if constexpr\
    \ (N < std::tuple_size<T>::value) {\n      auto &x = std::get<N>(t);\n      read_single(x);\n\
    \      read_single_tuple<N + 1>(t);\n    }\n  }\n  template <class... T>\n  bool\
    \ read_single(tuple<T...> &tpl) {\n    read_single_tuple(tpl);\n    return true;\n\
    \  }\n  void read() {}\n  template <class H, class... T>\n  void read(H &h, T\
    \ &... t) {\n    bool f = read_single(h);\n    assert(f);\n    read(t...);\n \
    \ }\n  Scanner(FILE *fp) : fp(fp) {}\n};\n\nstruct Printer {\n  Printer(FILE *_fp)\
    \ : fp(_fp) {}\n  ~Printer() { flush(); }\n\n  static constexpr size_t SIZE =\
    \ 1 << 15;\n  FILE *fp;\n  char line[SIZE], small[50];\n  size_t pos = 0;\n  void\
    \ flush() {\n    fwrite(line, 1, pos, fp);\n    pos = 0;\n  }\n  void write(const\
    \ char val) {\n    if (pos == SIZE) flush();\n    line[pos++] = val;\n  }\n  template\
    \ <class T, enable_if_t<is_integral<T>::value, int> = 0>\n  void write(T val)\
    \ {\n    if (pos > (1 << 15) - 50) flush();\n    if (val == 0) {\n      write('0');\n\
    \      return;\n    }\n    if (val < 0) {\n      write('-');\n      val = -val;\
    \ // todo min\n    }\n    size_t len = 0;\n    while (val) {\n      small[len++]\
    \ = char(0x30 | (val % 10));\n      val /= 10;\n    }\n    for (size_t i = 0;\
    \ i < len; i++) { line[pos + i] = small[len - 1 - i]; }\n    pos += len;\n  }\n\
    \  void write(const string s) {\n    for (char c: s) write(c);\n  }\n  void write(const\
    \ char *s) {\n    size_t len = strlen(s);\n    for (size_t i = 0; i < len; i++)\
    \ write(s[i]);\n  }\n  void write(const double x) {\n    ostringstream oss;\n\
    \    oss << fixed << setprecision(15) << x;\n    string s = oss.str();\n    write(s);\n\
    \  }\n  void write(const long double x) {\n    ostringstream oss;\n    oss <<\
    \ fixed << setprecision(15) << x;\n    string s = oss.str();\n    write(s);\n\
    \  }\n  template <typename T,\n            typename enable_if<has_write<T>::value>::type\
    \ * = nullptr>\n  inline void write(T x) {\n    x.write();\n  }\n  template <class\
    \ T>\n  void write(const vector<T> val) {\n    auto n = val.size();\n    for (size_t\
    \ i = 0; i < n; i++) {\n      if (i) write(' ');\n      write(val[i]);\n    }\n\
    \  }\n  template <class T, class U>\n  void write(const pair<T, U> val) {\n  \
    \  write(val.first);\n    write(' ');\n    write(val.second);\n  }\n  template\
    \ <size_t N = 0, typename T>\n  void write_tuple(const T t) {\n    if constexpr\
    \ (N < std::tuple_size<T>::value) {\n      if constexpr (N > 0) { write(' ');\
    \ }\n      const auto x = std::get<N>(t);\n      write(x);\n      write_tuple<N\
    \ + 1>(t);\n    }\n  }\n  template <class... T>\n  bool write(tuple<T...> tpl)\
    \ {\n    write_tuple(tpl);\n    return true;\n  }\n  template <class T, size_t\
    \ S>\n  void write(const array<T, S> val) {\n    auto n = val.size();\n    for\
    \ (size_t i = 0; i < n; i++) {\n      if (i) write(' ');\n      write(val[i]);\n\
    \    }\n  }\n  void write(i128 val) {\n    string s;\n    bool negative = 0;\n\
    \    if (val < 0) {\n      negative = 1;\n      val = -val;\n    }\n    while\
    \ (val) {\n      s += '0' + int(val % 10);\n      val /= 10;\n    }\n    if (negative)\
    \ s += \"-\";\n    reverse(all(s));\n    if (len(s) == 0) s = \"0\";\n    write(s);\n\
    \  }\n};\nScanner scanner = Scanner(stdin);\nPrinter printer = Printer(stdout);\n\
    void flush() { printer.flush(); }\nvoid print() { printer.write('\\n'); }\ntemplate\
    \ <class Head, class... Tail>\nvoid print(Head &&head, Tail &&... tail) {\n  printer.write(head);\n\
    \  if (sizeof...(Tail)) printer.write(' ');\n  print(forward<Tail>(tail)...);\n\
    }\n\nvoid read() {}\ntemplate <class Head, class... Tail>\nvoid read(Head &head,\
    \ Tail &... tail) {\n  scanner.read(head);\n  read(tail...);\n}\n} // namespace\
    \ fastio\nusing fastio::print;\nusing fastio::flush;\nusing fastio::read;\n\n\
    #define INT(...)   \\\n  int __VA_ARGS__; \\\n  read(__VA_ARGS__)\n#define LL(...)\
    \   \\\n  ll __VA_ARGS__; \\\n  read(__VA_ARGS__)\n#define STR(...)      \\\n\
    \  string __VA_ARGS__; \\\n  read(__VA_ARGS__)\n#define CHAR(...)   \\\n  char\
    \ __VA_ARGS__; \\\n  read(__VA_ARGS__)\n#define DBL(...)      \\\n  double __VA_ARGS__;\
    \ \\\n  read(__VA_ARGS__)\n\n#define VEC(type, name, size) \\\n  vector<type>\
    \ name(size);    \\\n  read(name)\n#define VV(type, name, h, w)              \
    \       \\\n  vector<vector<type>> name(h, vector<type>(w)); \\\n  read(name)\n\
    \nvoid YES(bool t = 1) { print(t ? \"YES\" : \"NO\"); }\nvoid NO(bool t = 1) {\
    \ YES(!t); }\nvoid Yes(bool t = 1) { print(t ? \"Yes\" : \"No\"); }\nvoid No(bool\
    \ t = 1) { Yes(!t); }\nvoid yes(bool t = 1) { print(t ? \"yes\" : \"no\"); }\n\
    void no(bool t = 1) { yes(!t); }"
  dependsOn: []
  isVerificationFile: false
  path: other/io_old.hpp
  requiredBy: []
  timestamp: '2023-11-06 14:40:18+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: other/io_old.hpp
layout: document
redirect_from:
- /library/other/io_old.hpp
- /library/other/io_old.hpp.html
title: other/io_old.hpp
---
