---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: convex/larsch.hpp
    title: convex/larsch.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/3_yukicoder/705.test.cpp
    title: test/3_yukicoder/705.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"convex/monge/monge_shortest_path.hpp\"\n\n#line 1 \"convex/larsch.hpp\"\
    \n// \u5236\u7D04\u304D\u3064\u3044 https://codeforces.com/contest/2183/problem/H\n\
    template <class T, class F>\nclass LARSCH {\n  struct reduce_row;\n  struct reduce_col;\n\
    \  struct ColMap {\n    const ColMap* parent = nullptr;\n    const std::vector<int>*\
    \ v = nullptr;\n\n    inline int map(int j) const {\n      int x = v ? (*v)[j]\
    \ : j;\n      return parent ? parent->map(x) : x;\n    }\n  };\n\n  struct Eval\
    \ {\n    const F* f = nullptr;\n    long long a = 1;  // row = a*i + b\n    long\
    \ long b = 0;\n    const ColMap* cm = nullptr;\n\n    inline T operator()(int\
    \ i, int j) const {\n      int ii = int(a * i + b);\n      int jj = cm ? cm->map(j)\
    \ : j;\n      return (*f)(ii, jj);\n    }\n  };\n\n  struct reduce_row {\n   \
    \ int n;\n    Eval e;\n    int cur_row = 0;\n    int state = 0;\n    std::unique_ptr<reduce_col>\
    \ rec;\n\n    reduce_row(int n_, const Eval& e_) : n(n_), e(e_) {\n      int m\
    \ = n / 2;\n      if (m) {\n        Eval eo = e;\n        eo.b = e.a + e.b;\n\
    \        eo.a = 2 * e.a;\n        rec = std::make_unique<reduce_col>(m, eo);\n\
    \      }\n    }\n\n    inline void reset() {\n      cur_row = 0;\n      state\
    \ = 0;\n      if (rec) rec->reset();\n    }\n\n    inline int get_argmin() {\n\
    \      int i = cur_row++;\n      if ((i & 1) == 0) {\n        int prev = state;\n\
    \        int next = (i + 1 == n ? n - 1 : rec->get_argmin());\n        state =\
    \ next;\n        int ret = prev;\n        for (int j = prev + 1; j <= next; ++j)\
    \ {\n          if (e(i, ret) > e(i, j)) ret = j;\n        }\n        return ret;\n\
    \      } else {\n        return (e(i, state) <= e(i, i)) ? state : i;\n      }\n\
    \    }\n  };\n\n  struct reduce_col {\n    int n;\n    Eval e;\n    int cur_row\
    \ = 0;\n    std::vector<int> cols;\n    ColMap cm_here;\n    reduce_row rec;\n\
    \n    reduce_col(int n_, const Eval& e_)\n        : n(n_),\n          e(e_),\n\
    \          cols(),\n          cm_here{e.cm, &cols},\n          rec(n_, Eval{e.f,\
    \ e.a, e.b, &cm_here}) {\n      cols.reserve(n);\n    }\n\n    inline void reset()\
    \ {\n      cur_row = 0;\n      cols.clear();\n      rec.reset();\n    }\n\n  \
    \  inline void push_col(int j, int i) {\n      while (!cols.empty()) {\n     \
    \   int size = (int)cols.size();\n        if (size == i) break;\n        int last\
    \ = cols.back();\n        if (e(size - 1, last) > e(size - 1, j))\n          cols.pop_back();\n\
    \        else\n          break;\n      }\n      if ((int)cols.size() != n) cols.push_back(j);\n\
    \    }\n\n    inline int get_argmin() {\n      int i = cur_row++;\n      if (i\
    \ == 0) {\n        cols.clear();\n        cols.push_back(0);\n      } else {\n\
    \        push_col(2 * i - 1, i);\n        push_col(2 * i, i);\n      }\n     \
    \ return cols[rec.get_argmin()];\n    }\n  };\n\n  F f_;\n  ColMap root_cm_;\n\
    \  Eval root_eval_;\n  std::unique_ptr<reduce_row> base_;\n\n public:\n  explicit\
    \ LARSCH(int n, F f)\n      : f_(std::move(f)),\n        root_cm_{nullptr, nullptr},\n\
    \        root_eval_{&f_, 1, 0, &root_cm_} {\n    base_ = std::make_unique<reduce_row>(n,\
    \ root_eval_);\n  }\n\n  inline void reset() { base_->reset(); }\n  inline int\
    \ get_argmin() { return base_->get_argmin(); }\n};\n#line 4 \"convex/monge/monge_shortest_path.hpp\"\
    \n\n// dp[r] = min_{0 <= l < r} dp[l] + f(l, r)\n// \u9077\u79FB\u56DE\u6570\u3092\
    \u554F\u308F\u306A\u3044\ntemplate <typename T, typename F>\nvc<T> monge_shortest_path(int\
    \ N, F f) {\n  vc<T> dp(N + 1, infty<T>);\n  dp[0] = 0;\n\n  auto g = [&](int\
    \ i, int j) -> T {\n    ++i;\n    if (i <= j) return infty<T>;\n    return dp[j]\
    \ + f(j, i);\n  };\n\n  LARSCH<T, decltype(g)> larsch(N, g);\n  FOR(r, 1, N +\
    \ 1) {\n    int l = larsch.get_argmin();\n    dp[r] = dp[l] + f(l, r);\n  }\n\
    \  return dp;\n}\n"
  code: "#pragma once\n\n#include \"convex/larsch.hpp\"\n\n// dp[r] = min_{0 <= l\
    \ < r} dp[l] + f(l, r)\n// \u9077\u79FB\u56DE\u6570\u3092\u554F\u308F\u306A\u3044\
    \ntemplate <typename T, typename F>\nvc<T> monge_shortest_path(int N, F f) {\n\
    \  vc<T> dp(N + 1, infty<T>);\n  dp[0] = 0;\n\n  auto g = [&](int i, int j) ->\
    \ T {\n    ++i;\n    if (i <= j) return infty<T>;\n    return dp[j] + f(j, i);\n\
    \  };\n\n  LARSCH<T, decltype(g)> larsch(N, g);\n  FOR(r, 1, N + 1) {\n    int\
    \ l = larsch.get_argmin();\n    dp[r] = dp[l] + f(l, r);\n  }\n  return dp;\n\
    }\n"
  dependsOn:
  - convex/larsch.hpp
  isVerificationFile: false
  path: convex/monge/monge_shortest_path.hpp
  requiredBy: []
  timestamp: '2026-05-31 16:57:43+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/3_yukicoder/705.test.cpp
documentation_of: convex/monge/monge_shortest_path.hpp
layout: document
redirect_from:
- /library/convex/monge/monge_shortest_path.hpp
- /library/convex/monge/monge_shortest_path.hpp.html
title: convex/monge/monge_shortest_path.hpp
---
