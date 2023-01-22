---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: convex/larsch.hpp
    title: convex/larsch.hpp
  - icon: ':heavy_check_mark:'
    path: convex/smawk.hpp
    title: convex/smawk.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/705.test.cpp
    title: test/yukicoder/705.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links:
    - https://dic.kimiyuki.net/d-edge-shortest-path-monge
  bundledCode: "#line 2 \"convex/larsch.hpp\"\n\n// https://noshi91.github.io/Library/algorithm/larsch.cpp.html\n\
    template <class T>\nclass LARSCH {\n  struct reduce_row;\n  struct reduce_col;\n\
    \n  struct reduce_row {\n    int n;\n    std::function<T(int, int)> f;\n    int\
    \ cur_row;\n    int state;\n    std::unique_ptr<reduce_col> rec;\n\n    reduce_row(int\
    \ n_) : n(n_), f(), cur_row(0), state(0), rec() {\n      const int m = n / 2;\n\
    \      if (m != 0) { rec = std::make_unique<reduce_col>(m); }\n    }\n\n    void\
    \ set_f(std::function<T(int, int)> f_) {\n      f = f_;\n      if (rec) {\n  \
    \      rec->set_f([&](int i, int j) -> T { return f(2 * i + 1, j); });\n     \
    \ }\n    }\n\n    int get_argmin() {\n      const int cur_row_ = cur_row;\n  \
    \    cur_row += 1;\n      if (cur_row_ % 2 == 0) {\n        const int prev_argmin\
    \ = state;\n        const int next_argmin = [&]() {\n          if (cur_row_ +\
    \ 1 == n) {\n            return n - 1;\n          } else {\n            return\
    \ rec->get_argmin();\n          }\n        }();\n        state = next_argmin;\n\
    \        int ret = prev_argmin;\n        for (int j = prev_argmin + 1; j <= next_argmin;\
    \ j += 1) {\n          if (f(cur_row_, ret) > f(cur_row_, j)) { ret = j; }\n \
    \       }\n        return ret;\n      } else {\n        if (f(cur_row_, state)\
    \ <= f(cur_row_, cur_row_)) {\n          return state;\n        } else {\n   \
    \       return cur_row_;\n        }\n      }\n    }\n  };\n\n  struct reduce_col\
    \ {\n    int n;\n    std::function<T(int, int)> f;\n    int cur_row;\n    std::vector<int>\
    \ cols;\n    reduce_row rec;\n\n    reduce_col(int n_) : n(n_), f(), cur_row(0),\
    \ cols(), rec(n) {}\n\n    void set_f(std::function<T(int, int)> f_) {\n     \
    \ f = f_;\n      rec.set_f([&](int i, int j) -> T { return f(i, cols[j]); });\n\
    \    }\n\n    int get_argmin() {\n      const int cur_row_ = cur_row;\n      cur_row\
    \ += 1;\n      const auto cs = [&]() -> std::vector<int> {\n        if (cur_row_\
    \ == 0) {\n          return {{0}};\n        } else {\n          return {{2 * cur_row_\
    \ - 1, 2 * cur_row_}};\n        }\n      }();\n      for (const int j: cs) {\n\
    \        while ([&]() {\n          const int size = cols.size();\n          return\
    \ size != cur_row_ && f(size - 1, cols.back()) > f(size - 1, j);\n        }())\
    \ {\n          cols.pop_back();\n        }\n        if (int(cols.size()) != n)\
    \ { cols.push_back(j); }\n      }\n      return cols[rec.get_argmin()];\n    }\n\
    \  };\n\n  std::unique_ptr<reduce_row> base;\n\npublic:\n  LARSCH(int n, std::function<T(int,\
    \ int)> f)\n      : base(std::make_unique<reduce_row>(n)) {\n    base->set_f(f);\n\
    \  }\n\n  int get_argmin() { return base->get_argmin(); }\n};\n#line 1 \"convex/smawk.hpp\"\
    \n// select(i,j,k) \u306F (i,j) \u3068 (i,k) \u306E\u3046\u3061\u9078\u3076\u65B9\
    \uFF08j or k\uFF09\ntemplate <typename F>\nvc<int> SMAWK(int H, int W, F select)\
    \ {\n  auto dfs = [&](auto& dfs, vc<int> X, vc<int> Y) -> vc<int> {\n    int N\
    \ = len(X);\n    if (N == 0) return {};\n    vc<int> YY;\n    for (auto&& y: Y)\
    \ {\n      while (len(YY)) {\n        int py = YY.back(), x = X[len(YY) - 1];\n\
    \        if (select(x, py, y) == py) break;\n        YY.pop_back();\n      }\n\
    \      if (len(YY) < len(X)) YY.eb(y);\n    }\n    vc<int> XX;\n    FOR(i, 1,\
    \ len(X), 2) XX.eb(X[i]);\n    vc<int> II = dfs(dfs, XX, YY);\n    vc<int> I(N);\n\
    \    FOR(i, len(II)) I[i + i + 1] = II[i];\n    int p = 0;\n    FOR(i, 0, N, 2)\
    \ {\n      int LIM = (i + 1 == N ? Y.back() : I[i + 1]);\n      int best = Y[p];\n\
    \      while (Y[p] < LIM) {\n        ++p;\n        best = select(X[i], best, Y[p]);\n\
    \      }\n      I[i] = best;\n    }\n    return I;\n  };\n  vc<int> X(H), Y(W);\n\
    \  iota(all(X), 0), iota(all(Y), 0);\n  return dfs(dfs, X, Y);\n}\n#line 3 \"\
    convex/monge.hpp\"\n\r\n// \u5B9A\u7FA9\u57DF [0, N] \u306E\u7BC4\u56F2\u3067\
    \ f \u306E monge \u6027\u3092\u78BA\u8A8D\r\ntemplate <typename T, typename F>\r\
    \nbool check_monge(int N, F f) {\r\n  FOR(l, N + 1) FOR(k, l) FOR(j, k) FOR(i,\
    \ j) {\r\n    T lhs = f(i, l) + f(j, k);\r\n    T rhs = f(i, k) + f(j, l);\r\n\
    \    if (lhs < rhs) return false;\r\n  }\r\n  return true;\r\n}\r\n\r\ntemplate\
    \ <ll INF, typename F>\r\nvi monge_shortest_path(int N, F f) {\r\n  vi dp(N +\
    \ 1, INF);\r\n  dp[0] = 0;\r\n  LARSCH<ll> larsch(N, [&](int i, int j) {\r\n \
    \   ++i;\r\n    if (i <= j) return INF;\r\n    return dp[j] + f(j, i);\r\n  });\r\
    \n  FOR3(r, 1, N + 1) {\r\n    ll l = larsch.get_argmin();\r\n    dp[r] = dp[l]\
    \ + f(l, r);\r\n  }\r\n  return dp;\r\n}\r\n\r\n/*\r\nhttps://dic.kimiyuki.net/d-edge-shortest-path-monge\r\
    \n\u4E0A\u51F8\u95A2\u6570 calc_L(lambda) \u306E\u6700\u5927\u5024\u3092\u6C42\
    \u3081\u308B\u554F\u984C\u306B\u5E30\u7740\r\n|f| \u306E\u4E0A\u9650 f_lim \u3082\
    \u6E21\u3059\r\n*/\r\ntemplate <ll INF, typename F>\r\nll monge_shortest_path_d_edge(ll\
    \ N, F f, ll d, ll f_lim) {\r\n  auto calc_L = [&](ll lambda) -> ll {\r\n    auto\
    \ cost = [&](int frm, int to) -> ll { return f(frm, to) + lambda; };\r\n    auto\
    \ dp = monge_shortest_path<INF>(N, cost);\r\n    return dp.back() - lambda * d;\r\
    \n  };\r\n\r\n  ll ANS = -INF;\r\n  ll L = -3 * f_lim - 10;\r\n  ll R = 3 * f_lim\
    \ + 10;\r\n  ll x = binary_search([&](ll x) { return calc_L(x - 1) <= calc_L(x);\
    \ }, L, R);\r\n  return calc_L(x);\r\n}\r\n"
  code: "#include \"convex/larsch.hpp\"\r\n#include \"convex/smawk.hpp\"\r\n\r\n//\
    \ \u5B9A\u7FA9\u57DF [0, N] \u306E\u7BC4\u56F2\u3067 f \u306E monge \u6027\u3092\
    \u78BA\u8A8D\r\ntemplate <typename T, typename F>\r\nbool check_monge(int N, F\
    \ f) {\r\n  FOR(l, N + 1) FOR(k, l) FOR(j, k) FOR(i, j) {\r\n    T lhs = f(i,\
    \ l) + f(j, k);\r\n    T rhs = f(i, k) + f(j, l);\r\n    if (lhs < rhs) return\
    \ false;\r\n  }\r\n  return true;\r\n}\r\n\r\ntemplate <ll INF, typename F>\r\n\
    vi monge_shortest_path(int N, F f) {\r\n  vi dp(N + 1, INF);\r\n  dp[0] = 0;\r\
    \n  LARSCH<ll> larsch(N, [&](int i, int j) {\r\n    ++i;\r\n    if (i <= j) return\
    \ INF;\r\n    return dp[j] + f(j, i);\r\n  });\r\n  FOR3(r, 1, N + 1) {\r\n  \
    \  ll l = larsch.get_argmin();\r\n    dp[r] = dp[l] + f(l, r);\r\n  }\r\n  return\
    \ dp;\r\n}\r\n\r\n/*\r\nhttps://dic.kimiyuki.net/d-edge-shortest-path-monge\r\n\
    \u4E0A\u51F8\u95A2\u6570 calc_L(lambda) \u306E\u6700\u5927\u5024\u3092\u6C42\u3081\
    \u308B\u554F\u984C\u306B\u5E30\u7740\r\n|f| \u306E\u4E0A\u9650 f_lim \u3082\u6E21\
    \u3059\r\n*/\r\ntemplate <ll INF, typename F>\r\nll monge_shortest_path_d_edge(ll\
    \ N, F f, ll d, ll f_lim) {\r\n  auto calc_L = [&](ll lambda) -> ll {\r\n    auto\
    \ cost = [&](int frm, int to) -> ll { return f(frm, to) + lambda; };\r\n    auto\
    \ dp = monge_shortest_path<INF>(N, cost);\r\n    return dp.back() - lambda * d;\r\
    \n  };\r\n\r\n  ll ANS = -INF;\r\n  ll L = -3 * f_lim - 10;\r\n  ll R = 3 * f_lim\
    \ + 10;\r\n  ll x = binary_search([&](ll x) { return calc_L(x - 1) <= calc_L(x);\
    \ }, L, R);\r\n  return calc_L(x);\r\n}\r\n"
  dependsOn:
  - convex/larsch.hpp
  - convex/smawk.hpp
  isVerificationFile: false
  path: convex/monge.hpp
  requiredBy: []
  timestamp: '2023-01-22 16:43:58+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yukicoder/705.test.cpp
documentation_of: convex/monge.hpp
layout: document
redirect_from:
- /library/convex/monge.hpp
- /library/convex/monge.hpp.html
title: convex/monge.hpp
---
