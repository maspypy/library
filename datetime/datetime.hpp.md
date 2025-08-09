---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/1_mytest/datetime.test.cpp
    title: test/1_mytest/datetime.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/3_yukicoder/2109.test.cpp
    title: test/3_yukicoder/2109.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/3_yukicoder/779.test.cpp
    title: test/3_yukicoder/779.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links:
    - https://codeforces.com/problemset/problem/698/E
  bundledCode: "#line 1 \"datetime/datetime.hpp\"\n// https://codeforces.com/problemset/problem/698/E\n\
    struct DateTime {\n  static constexpr int month_days[13] = {0, 31, 28, 31, 30,\
    \ 31, 30, 31, 31, 30, 31, 30, 31};\n  ll year;\n  int month, day;\n  DateTime(ll\
    \ y, int m, int d) : year(y), month(m), day(d) {}\n\n  // 1\u5E741\u67081\u65E5\
    \u304C 0 \u3068\u306A\u308B\u3088\u3046\u306B\u5909\u63DB (return: long long)\n\
    \  ll to_int() {\n    ll y = (month <= 2 ? year - 1 : year);\n    int m = (month\
    \ <= 2 ? month + 12 : month);\n    int d = day;\n    return 365 * y + y / 4 -\
    \ y / 100 + y / 400 + 306 * (m + 1) / 10 + d - 429;\n  }\n\n  // to_int() \u306E\
    \u9006\u95A2\u6570\n  static DateTime from_int(ll x) {\n    ll y = x * 400 / 146097\
    \ + 1;\n    int d = x - DateTime(y, 1, 1).to_int();\n    int m = 1;\n    while\
    \ (d >= 28) {\n      int k = month_days[m] + (m == 2 && is_leap_year(y) ? 1 :\
    \ 0);\n      if (d < k) break;\n      ++m;\n      d -= k;\n    }\n    if (m ==\
    \ 13) {\n      ++y;\n      m = 1;\n    }\n    ++d;\n    return DateTime(y, m,\
    \ d);\n  }\n\n  // \u65E5\u66DC\u65E5\u304C 0 \u3068\u3057\u3066\u3001\u66DC\u65E5\
    \u3092 [0, 7) \u3067\u8FD4\u3059\n  int weekday() { return (to_int() + 1) % 7;\
    \ }\n\n  DateTime& operator++() {\n    ++day;\n    int lim = month_days[month];\n\
    \    if (is_leap_year(year) && month == 2) lim = 29;\n    if (day <= lim) return\
    \ (*this);\n    day = 1;\n    ++month;\n    if (month == 13) {\n      ++year;\n\
    \      month = 1;\n    }\n    return (*this);\n  }\n  DateTime operator++(int)\
    \ {\n    DateTime tmp = *this;\n    ++*this;\n    return tmp;\n  }\n\n  bool operator==(DateTime\
    \ const& rhs) const { return to_tuple() == rhs.to_tuple(); }\n  bool operator!=(DateTime\
    \ const& rhs) const { return to_tuple() != rhs.to_tuple(); }\n  bool operator<(DateTime\
    \ const& rhs) const { return to_tuple() < rhs.to_tuple(); }\n  bool operator<=(DateTime\
    \ const& rhs) const { return to_tuple() <= rhs.to_tuple(); }\n  bool operator>(DateTime\
    \ const& rhs) const { return to_tuple() > rhs.to_tuple(); }\n  bool operator>=(DateTime\
    \ const& rhs) const { return to_tuple() >= rhs.to_tuple(); }\n\n  // yyyy[sep]mm[sep]dd\n\
    \  string to_string(string sep = \"-\") {\n    string y = std::to_string(year);\n\
    \    string m = std::to_string(month);\n    string d = std::to_string(day);\n\
    \    while (len(y) < 4) y = \"0\" + y;\n    while (len(m) < 2) m = \"0\" + m;\n\
    \    while (len(d) < 2) d = \"0\" + d;\n    return y + sep + m + sep + d;\n  }\n\
    \n  tuple<ll, int, int> to_tuple() const { return {year, month, day}; }\n\n  static\
    \ bool is_leap_year(ll y) {\n    if (y % 400 == 0) return true;\n    return (y\
    \ % 4 == 0 && y % 100 != 0);\n  }\n\n  static bool is_valid_date(ll y, int m,\
    \ int d) {\n    if (!(1 <= m && m <= 12)) return 0;\n    int mx = month_days[m];\n\
    \    if (m == 2 && is_leap_year(y)) ++mx;\n    return (1 <= d && d <= mx);\n \
    \ }\n};\n"
  code: "// https://codeforces.com/problemset/problem/698/E\nstruct DateTime {\n \
    \ static constexpr int month_days[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30,\
    \ 31, 30, 31};\n  ll year;\n  int month, day;\n  DateTime(ll y, int m, int d)\
    \ : year(y), month(m), day(d) {}\n\n  // 1\u5E741\u67081\u65E5\u304C 0 \u3068\u306A\
    \u308B\u3088\u3046\u306B\u5909\u63DB (return: long long)\n  ll to_int() {\n  \
    \  ll y = (month <= 2 ? year - 1 : year);\n    int m = (month <= 2 ? month + 12\
    \ : month);\n    int d = day;\n    return 365 * y + y / 4 - y / 100 + y / 400\
    \ + 306 * (m + 1) / 10 + d - 429;\n  }\n\n  // to_int() \u306E\u9006\u95A2\u6570\
    \n  static DateTime from_int(ll x) {\n    ll y = x * 400 / 146097 + 1;\n    int\
    \ d = x - DateTime(y, 1, 1).to_int();\n    int m = 1;\n    while (d >= 28) {\n\
    \      int k = month_days[m] + (m == 2 && is_leap_year(y) ? 1 : 0);\n      if\
    \ (d < k) break;\n      ++m;\n      d -= k;\n    }\n    if (m == 13) {\n     \
    \ ++y;\n      m = 1;\n    }\n    ++d;\n    return DateTime(y, m, d);\n  }\n\n\
    \  // \u65E5\u66DC\u65E5\u304C 0 \u3068\u3057\u3066\u3001\u66DC\u65E5\u3092 [0,\
    \ 7) \u3067\u8FD4\u3059\n  int weekday() { return (to_int() + 1) % 7; }\n\n  DateTime&\
    \ operator++() {\n    ++day;\n    int lim = month_days[month];\n    if (is_leap_year(year)\
    \ && month == 2) lim = 29;\n    if (day <= lim) return (*this);\n    day = 1;\n\
    \    ++month;\n    if (month == 13) {\n      ++year;\n      month = 1;\n    }\n\
    \    return (*this);\n  }\n  DateTime operator++(int) {\n    DateTime tmp = *this;\n\
    \    ++*this;\n    return tmp;\n  }\n\n  bool operator==(DateTime const& rhs)\
    \ const { return to_tuple() == rhs.to_tuple(); }\n  bool operator!=(DateTime const&\
    \ rhs) const { return to_tuple() != rhs.to_tuple(); }\n  bool operator<(DateTime\
    \ const& rhs) const { return to_tuple() < rhs.to_tuple(); }\n  bool operator<=(DateTime\
    \ const& rhs) const { return to_tuple() <= rhs.to_tuple(); }\n  bool operator>(DateTime\
    \ const& rhs) const { return to_tuple() > rhs.to_tuple(); }\n  bool operator>=(DateTime\
    \ const& rhs) const { return to_tuple() >= rhs.to_tuple(); }\n\n  // yyyy[sep]mm[sep]dd\n\
    \  string to_string(string sep = \"-\") {\n    string y = std::to_string(year);\n\
    \    string m = std::to_string(month);\n    string d = std::to_string(day);\n\
    \    while (len(y) < 4) y = \"0\" + y;\n    while (len(m) < 2) m = \"0\" + m;\n\
    \    while (len(d) < 2) d = \"0\" + d;\n    return y + sep + m + sep + d;\n  }\n\
    \n  tuple<ll, int, int> to_tuple() const { return {year, month, day}; }\n\n  static\
    \ bool is_leap_year(ll y) {\n    if (y % 400 == 0) return true;\n    return (y\
    \ % 4 == 0 && y % 100 != 0);\n  }\n\n  static bool is_valid_date(ll y, int m,\
    \ int d) {\n    if (!(1 <= m && m <= 12)) return 0;\n    int mx = month_days[m];\n\
    \    if (m == 2 && is_leap_year(y)) ++mx;\n    return (1 <= d && d <= mx);\n \
    \ }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: datetime/datetime.hpp
  requiredBy: []
  timestamp: '2025-01-06 16:30:28+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/1_mytest/datetime.test.cpp
  - test/3_yukicoder/779.test.cpp
  - test/3_yukicoder/2109.test.cpp
documentation_of: datetime/datetime.hpp
layout: document
redirect_from:
- /library/datetime/datetime.hpp
- /library/datetime/datetime.hpp.html
title: datetime/datetime.hpp
---
