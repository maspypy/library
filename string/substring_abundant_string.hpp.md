---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: string/run_length.hpp
    title: string/run_length.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links:
    - https://oeis.org/A094913
    - https://qoj.ac/contest/1096/problem/5434?v=1
    - https://www.mimuw.edu.pl/~rytter/MYPAPERS/paper.pdf
  bundledCode: "#line 1 \"string/run_length.hpp\"\ntemplate <typename STRING = string,\
    \ typename CHAR = char>\nvc<pair<CHAR, int>> run_length(STRING& S) {\n  vc<pair<CHAR,\
    \ int>> res;\n  for (auto&& x: S) {\n    if (res.empty() || res.back().fi != x)\
    \ { res.emplace_back(x, 0); }\n    res.back().se++;\n  }\n  return res;\n}\n#line\
    \ 2 \"string/substring_abundant_string.hpp\"\n\n// \u90E8\u5206\u6587\u5B57\u5217\
    \u306E\u7A2E\u985E\u6570\u304C\u6700\u5927\u3067\u3042\u308B\u3088\u3046\u306A\
    \ 01 \u6587\u5B57\u5217\u306E\u69CB\u6210\n// https://qoj.ac/contest/1096/problem/5434?v=1\n\
    // https://oeis.org/A094913\n// https://www.mimuw.edu.pl/~rytter/MYPAPERS/paper.pdf\n\
    string substring_abundant_string(ll N) {\n  ll N0 = N;\n  N = 1;\n  while ((1\
    \ << N) + (N - 1) < N0) ++N;\n\n  string S = [&]() -> string {\n    if (N == 1)\
    \ return \"01\";\n    if (N == 2) return \"00110\";\n\n    auto SHIFT = [&](string\
    \ x, string y) -> string {\n      int n = len(x);\n      x += x;\n      FOR(i,\
    \ n, n + n) {\n        if (x.substr(i - len(y), len(y)) == y) { return x.substr(i\
    \ - n, n); }\n      }\n      return \"\";\n    };\n    auto oplus = [&](string\
    \ x, string y) -> string {\n      int n = topbit(len(y));\n      assert(len(x)\
    \ == (1 << n) && len(y) == (1 << n));\n      return x + SHIFT(y, x.substr(len(x)\
    \ - n, n));\n    };\n    auto NOT = [&](string x) -> string {\n      string y;\n\
    \      for (auto&& s: x) y += (s == '0' ? '1' : '0');\n      return y;\n    };\n\
    \    auto PSI = [&](string x) -> string {\n      int a = 0;\n      FOR(i, len(x))\
    \ {\n        a ^= (x[i] - '0');\n        x[i] = ('0' + a);\n      }\n      return\
    \ x;\n    };\n\n    auto NEXT = [&](string x) -> string {\n      x = PSI(x);\n\
    \      return oplus(x, NOT(x));\n    };\n\n    auto otimes = [&](string x, string\
    \ y) -> string {\n      string t;\n      FOR(topbit(len(x))) t += '0';\n     \
    \ x = SHIFT(x, t);\n      y = SHIFT(y, t);\n      rotate(x.begin(), x.end() -\
    \ len(t), x.end());\n      rotate(y.begin(), y.end() - len(t), y.end());\n\n \
    \     int n = len(x);\n      int x0 = 0, x1 = 0, y0 = 0, y1 = 1;\n      for (auto&&\
    \ [k, v]: run_length(x)) {\n        if (k == '0') chmax(x0, v);\n        if (k\
    \ == '1') chmax(x1, v);\n      }\n      for (auto&& [k, v]: run_length(y)) {\n\
    \        if (k == '0') chmax(y0, v);\n        if (k == '1') chmax(y1, v);\n  \
    \    }\n      string X, Y;\n      for (auto&& [k, v]: run_length(x)) {\n     \
    \   if (k == '0' && v < x0) { X += string(v, k); }\n        if (k == '0' && v\
    \ == x0) { X += string(v - 1, k); }\n        if (k == '1' && v < x1) { X += string(v,\
    \ k); }\n        if (k == '1' && v == x1) { X += string(v + 1, k); }\n      }\n\
    \      for (auto&& [k, v]: run_length(y)) {\n        if (k == '0' && v < y0) {\
    \ Y += string(v, k); }\n        if (k == '0' && v == y0) { Y += string(v + 1,\
    \ k); }\n        if (k == '1' && v < y1) { Y += string(v, k); }\n        if (k\
    \ == '1' && v == y1) { Y += string(v - 1, k); }\n      }\n      return X + Y;\n\
    \    };\n\n    string x = \"0011\", y = \"0011\";\n    FOR(i, 2, N - 1) {\n  \
    \    string t;\n      FOR(i) t += '1';\n      x = SHIFT(x, t);\n      x = NEXT(x);\n\
    \      y = SHIFT(y, t);\n      y = NOT(NEXT(y));\n    }\n    x = otimes(x, y);\n\
    \    FOR(i, N - 1) x += x[i];\n    return x;\n  }();\n  return S.substr(0, N0);\n\
    }\n"
  code: "#include \"string/run_length.hpp\"\n\n// \u90E8\u5206\u6587\u5B57\u5217\u306E\
    \u7A2E\u985E\u6570\u304C\u6700\u5927\u3067\u3042\u308B\u3088\u3046\u306A 01 \u6587\
    \u5B57\u5217\u306E\u69CB\u6210\n// https://qoj.ac/contest/1096/problem/5434?v=1\n\
    // https://oeis.org/A094913\n// https://www.mimuw.edu.pl/~rytter/MYPAPERS/paper.pdf\n\
    string substring_abundant_string(ll N) {\n  ll N0 = N;\n  N = 1;\n  while ((1\
    \ << N) + (N - 1) < N0) ++N;\n\n  string S = [&]() -> string {\n    if (N == 1)\
    \ return \"01\";\n    if (N == 2) return \"00110\";\n\n    auto SHIFT = [&](string\
    \ x, string y) -> string {\n      int n = len(x);\n      x += x;\n      FOR(i,\
    \ n, n + n) {\n        if (x.substr(i - len(y), len(y)) == y) { return x.substr(i\
    \ - n, n); }\n      }\n      return \"\";\n    };\n    auto oplus = [&](string\
    \ x, string y) -> string {\n      int n = topbit(len(y));\n      assert(len(x)\
    \ == (1 << n) && len(y) == (1 << n));\n      return x + SHIFT(y, x.substr(len(x)\
    \ - n, n));\n    };\n    auto NOT = [&](string x) -> string {\n      string y;\n\
    \      for (auto&& s: x) y += (s == '0' ? '1' : '0');\n      return y;\n    };\n\
    \    auto PSI = [&](string x) -> string {\n      int a = 0;\n      FOR(i, len(x))\
    \ {\n        a ^= (x[i] - '0');\n        x[i] = ('0' + a);\n      }\n      return\
    \ x;\n    };\n\n    auto NEXT = [&](string x) -> string {\n      x = PSI(x);\n\
    \      return oplus(x, NOT(x));\n    };\n\n    auto otimes = [&](string x, string\
    \ y) -> string {\n      string t;\n      FOR(topbit(len(x))) t += '0';\n     \
    \ x = SHIFT(x, t);\n      y = SHIFT(y, t);\n      rotate(x.begin(), x.end() -\
    \ len(t), x.end());\n      rotate(y.begin(), y.end() - len(t), y.end());\n\n \
    \     int n = len(x);\n      int x0 = 0, x1 = 0, y0 = 0, y1 = 1;\n      for (auto&&\
    \ [k, v]: run_length(x)) {\n        if (k == '0') chmax(x0, v);\n        if (k\
    \ == '1') chmax(x1, v);\n      }\n      for (auto&& [k, v]: run_length(y)) {\n\
    \        if (k == '0') chmax(y0, v);\n        if (k == '1') chmax(y1, v);\n  \
    \    }\n      string X, Y;\n      for (auto&& [k, v]: run_length(x)) {\n     \
    \   if (k == '0' && v < x0) { X += string(v, k); }\n        if (k == '0' && v\
    \ == x0) { X += string(v - 1, k); }\n        if (k == '1' && v < x1) { X += string(v,\
    \ k); }\n        if (k == '1' && v == x1) { X += string(v + 1, k); }\n      }\n\
    \      for (auto&& [k, v]: run_length(y)) {\n        if (k == '0' && v < y0) {\
    \ Y += string(v, k); }\n        if (k == '0' && v == y0) { Y += string(v + 1,\
    \ k); }\n        if (k == '1' && v < y1) { Y += string(v, k); }\n        if (k\
    \ == '1' && v == y1) { Y += string(v - 1, k); }\n      }\n      return X + Y;\n\
    \    };\n\n    string x = \"0011\", y = \"0011\";\n    FOR(i, 2, N - 1) {\n  \
    \    string t;\n      FOR(i) t += '1';\n      x = SHIFT(x, t);\n      x = NEXT(x);\n\
    \      y = SHIFT(y, t);\n      y = NOT(NEXT(y));\n    }\n    x = otimes(x, y);\n\
    \    FOR(i, N - 1) x += x[i];\n    return x;\n  }();\n  return S.substr(0, N0);\n\
    }"
  dependsOn:
  - string/run_length.hpp
  isVerificationFile: false
  path: string/substring_abundant_string.hpp
  requiredBy: []
  timestamp: '2023-01-31 20:02:48+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: string/substring_abundant_string.hpp
layout: document
redirect_from:
- /library/string/substring_abundant_string.hpp
- /library/string/substring_abundant_string.hpp.html
title: string/substring_abundant_string.hpp
---
