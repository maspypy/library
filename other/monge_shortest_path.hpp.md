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
    - https://dic.kimiyuki.net/d-edge-shortest-path-monge
  bundledCode: "#line 1 \"other/monge_shortest_path.hpp\"\n#include <functional>\r\
    \n#include <memory>\r\ntemplate <class T>\r\nclass LARSCH {\r\n  struct reduce_row;\r\
    \n  struct reduce_col;\r\n\r\n  struct reduce_row {\r\n    int n;\r\n    std::function<T(int,\
    \ int)> f;\r\n    int cur_row;\r\n    int state;\r\n    std::unique_ptr<reduce_col>\
    \ rec;\r\n\r\n    reduce_row(int n_) : n(n_), f(), cur_row(0), state(0), rec()\
    \ {\r\n      const int m = n / 2;\r\n      if (m != 0) { rec = std::make_unique<reduce_col>(m);\
    \ }\r\n    }\r\n\r\n    void set_f(std::function<T(int, int)> f_) {\r\n      f\
    \ = f_;\r\n      if (rec) {\r\n        rec->set_f([&](int i, int j) -> T { return\
    \ f(2 * i + 1, j); });\r\n      }\r\n    }\r\n\r\n    int get_argmin() {\r\n \
    \     const int cur_row_ = cur_row;\r\n      cur_row += 1;\r\n      if (cur_row_\
    \ % 2 == 0) {\r\n        const int prev_argmin = state;\r\n        const int next_argmin\
    \ = [&]() {\r\n          if (cur_row_ + 1 == n) {\r\n            return n - 1;\r\
    \n          } else {\r\n            return rec->get_argmin();\r\n          }\r\
    \n        }();\r\n        state = next_argmin;\r\n        int ret = prev_argmin;\r\
    \n        for (int j = prev_argmin + 1; j <= next_argmin; j += 1) {\r\n      \
    \    if (f(cur_row_, ret) > f(cur_row_, j)) { ret = j; }\r\n        }\r\n    \
    \    return ret;\r\n      } else {\r\n        if (f(cur_row_, state) <= f(cur_row_,\
    \ cur_row_)) {\r\n          return state;\r\n        } else {\r\n          return\
    \ cur_row_;\r\n        }\r\n      }\r\n    }\r\n  };\r\n\r\n  struct reduce_col\
    \ {\r\n    int n;\r\n    std::function<T(int, int)> f;\r\n    int cur_row;\r\n\
    \    std::vector<int> cols;\r\n    reduce_row rec;\r\n\r\n    reduce_col(int n_)\
    \ : n(n_), f(), cur_row(0), cols(), rec(n) {}\r\n\r\n    void set_f(std::function<T(int,\
    \ int)> f_) {\r\n      f = f_;\r\n      rec.set_f([&](int i, int j) -> T { return\
    \ f(i, cols[j]); });\r\n    }\r\n\r\n    int get_argmin() {\r\n      const int\
    \ cur_row_ = cur_row;\r\n      cur_row += 1;\r\n      const auto cs = [&]() ->\
    \ std::vector<int> {\r\n        if (cur_row_ == 0) {\r\n          return {{0}};\r\
    \n        } else {\r\n          return {{2 * cur_row_ - 1, 2 * cur_row_}};\r\n\
    \        }\r\n      }();\r\n      for (const int j : cs) {\r\n        while ([&]()\
    \ {\r\n          const int size = cols.size();\r\n          return size != cur_row_\
    \ && f(size - 1, cols.back()) > f(size - 1, j);\r\n        }()) {\r\n        \
    \  cols.pop_back();\r\n        }\r\n        if (cols.size() != n) { cols.push_back(j);\
    \ }\r\n      }\r\n      return cols[rec.get_argmin()];\r\n    }\r\n  };\r\n\r\n\
    \  std::unique_ptr<reduce_row> base;\r\n\r\npublic:\r\n  LARSCH(int n, std::function<T(int,\
    \ int)> f)\r\n      : base(std::make_unique<reduce_row>(n)) {\r\n    base->set_f(f);\r\
    \n  }\r\n\r\n  int get_argmin() { return base->get_argmin(); }\r\n};\r\n\r\ntemplate\
    \ <typename F>\r\nll d_edge_shortest_path_monge(ll N, ll d, F f, ll f_lim) {\r\
    \n  /*\r\n  https://dic.kimiyuki.net/d-edge-shortest-path-monge\r\n  \u4E0A\u51F8\
    \u95A2\u6570 calc_L(lambda) \u306E\u6700\u5927\u5024\u3092\u6C42\u3081\u308B\u554F\
    \u984C\u306B\u5E30\u7740\r\n  |f| \u306E\u4E0A\u9650 f_lim \u3082\u6E21\u3059\r\
    \n  */\r\n  const ll INF = 1LL << 60;\r\n  auto calc_L = [&](ll lambda) -> ll\
    \ {\r\n    auto cost = [&](int frm, int to) -> ll { return f(frm, to) + lambda;\
    \ };\r\n    vector<ll> DP(N, INF);\r\n    DP[0] = 0;\r\n    LARSCH<ll> larsch(N\
    \ - 1, [&](int i, int j) {\r\n      // dp[j] \u304B\u3089 dp[i+1] \u3078\u306E\
    \u9077\u79FB\r\n      if (i + 1 <= j) return INF;\r\n      return DP[j] + cost(j,\
    \ i + 1);\r\n    });\r\n    FOR3(v, 1, N) {\r\n      ll frm = larsch.get_argmin();\r\
    \n      DP[v] = DP[frm] + cost(frm, v);\r\n    }\r\n    ll ANS = DP.back() - lambda\
    \ * d;\r\n    return ANS;\r\n  };\r\n\r\n  ll ANS = -INF;\r\n  ll L = -3 * f_lim\
    \ - 10;\r\n  ll R = 3 * f_lim + 10;\r\n  ll x = binary_search([&](ll x) { return\
    \ calc_L(x - 1) <= calc_L(x); }, L, R);\r\n  return calc_L(x);\r\n}\n"
  code: "#include <functional>\r\n#include <memory>\r\ntemplate <class T>\r\nclass\
    \ LARSCH {\r\n  struct reduce_row;\r\n  struct reduce_col;\r\n\r\n  struct reduce_row\
    \ {\r\n    int n;\r\n    std::function<T(int, int)> f;\r\n    int cur_row;\r\n\
    \    int state;\r\n    std::unique_ptr<reduce_col> rec;\r\n\r\n    reduce_row(int\
    \ n_) : n(n_), f(), cur_row(0), state(0), rec() {\r\n      const int m = n / 2;\r\
    \n      if (m != 0) { rec = std::make_unique<reduce_col>(m); }\r\n    }\r\n\r\n\
    \    void set_f(std::function<T(int, int)> f_) {\r\n      f = f_;\r\n      if\
    \ (rec) {\r\n        rec->set_f([&](int i, int j) -> T { return f(2 * i + 1, j);\
    \ });\r\n      }\r\n    }\r\n\r\n    int get_argmin() {\r\n      const int cur_row_\
    \ = cur_row;\r\n      cur_row += 1;\r\n      if (cur_row_ % 2 == 0) {\r\n    \
    \    const int prev_argmin = state;\r\n        const int next_argmin = [&]() {\r\
    \n          if (cur_row_ + 1 == n) {\r\n            return n - 1;\r\n        \
    \  } else {\r\n            return rec->get_argmin();\r\n          }\r\n      \
    \  }();\r\n        state = next_argmin;\r\n        int ret = prev_argmin;\r\n\
    \        for (int j = prev_argmin + 1; j <= next_argmin; j += 1) {\r\n       \
    \   if (f(cur_row_, ret) > f(cur_row_, j)) { ret = j; }\r\n        }\r\n     \
    \   return ret;\r\n      } else {\r\n        if (f(cur_row_, state) <= f(cur_row_,\
    \ cur_row_)) {\r\n          return state;\r\n        } else {\r\n          return\
    \ cur_row_;\r\n        }\r\n      }\r\n    }\r\n  };\r\n\r\n  struct reduce_col\
    \ {\r\n    int n;\r\n    std::function<T(int, int)> f;\r\n    int cur_row;\r\n\
    \    std::vector<int> cols;\r\n    reduce_row rec;\r\n\r\n    reduce_col(int n_)\
    \ : n(n_), f(), cur_row(0), cols(), rec(n) {}\r\n\r\n    void set_f(std::function<T(int,\
    \ int)> f_) {\r\n      f = f_;\r\n      rec.set_f([&](int i, int j) -> T { return\
    \ f(i, cols[j]); });\r\n    }\r\n\r\n    int get_argmin() {\r\n      const int\
    \ cur_row_ = cur_row;\r\n      cur_row += 1;\r\n      const auto cs = [&]() ->\
    \ std::vector<int> {\r\n        if (cur_row_ == 0) {\r\n          return {{0}};\r\
    \n        } else {\r\n          return {{2 * cur_row_ - 1, 2 * cur_row_}};\r\n\
    \        }\r\n      }();\r\n      for (const int j : cs) {\r\n        while ([&]()\
    \ {\r\n          const int size = cols.size();\r\n          return size != cur_row_\
    \ && f(size - 1, cols.back()) > f(size - 1, j);\r\n        }()) {\r\n        \
    \  cols.pop_back();\r\n        }\r\n        if (cols.size() != n) { cols.push_back(j);\
    \ }\r\n      }\r\n      return cols[rec.get_argmin()];\r\n    }\r\n  };\r\n\r\n\
    \  std::unique_ptr<reduce_row> base;\r\n\r\npublic:\r\n  LARSCH(int n, std::function<T(int,\
    \ int)> f)\r\n      : base(std::make_unique<reduce_row>(n)) {\r\n    base->set_f(f);\r\
    \n  }\r\n\r\n  int get_argmin() { return base->get_argmin(); }\r\n};\r\n\r\ntemplate\
    \ <typename F>\r\nll d_edge_shortest_path_monge(ll N, ll d, F f, ll f_lim) {\r\
    \n  /*\r\n  https://dic.kimiyuki.net/d-edge-shortest-path-monge\r\n  \u4E0A\u51F8\
    \u95A2\u6570 calc_L(lambda) \u306E\u6700\u5927\u5024\u3092\u6C42\u3081\u308B\u554F\
    \u984C\u306B\u5E30\u7740\r\n  |f| \u306E\u4E0A\u9650 f_lim \u3082\u6E21\u3059\r\
    \n  */\r\n  const ll INF = 1LL << 60;\r\n  auto calc_L = [&](ll lambda) -> ll\
    \ {\r\n    auto cost = [&](int frm, int to) -> ll { return f(frm, to) + lambda;\
    \ };\r\n    vector<ll> DP(N, INF);\r\n    DP[0] = 0;\r\n    LARSCH<ll> larsch(N\
    \ - 1, [&](int i, int j) {\r\n      // dp[j] \u304B\u3089 dp[i+1] \u3078\u306E\
    \u9077\u79FB\r\n      if (i + 1 <= j) return INF;\r\n      return DP[j] + cost(j,\
    \ i + 1);\r\n    });\r\n    FOR3(v, 1, N) {\r\n      ll frm = larsch.get_argmin();\r\
    \n      DP[v] = DP[frm] + cost(frm, v);\r\n    }\r\n    ll ANS = DP.back() - lambda\
    \ * d;\r\n    return ANS;\r\n  };\r\n\r\n  ll ANS = -INF;\r\n  ll L = -3 * f_lim\
    \ - 10;\r\n  ll R = 3 * f_lim + 10;\r\n  ll x = binary_search([&](ll x) { return\
    \ calc_L(x - 1) <= calc_L(x); }, L, R);\r\n  return calc_L(x);\r\n}"
  dependsOn: []
  isVerificationFile: false
  path: other/monge_shortest_path.hpp
  requiredBy: []
  timestamp: '2022-04-16 04:26:49+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: other/monge_shortest_path.hpp
layout: document
redirect_from:
- /library/other/monge_shortest_path.hpp
- /library/other/monge_shortest_path.hpp.html
title: other/monge_shortest_path.hpp
---
