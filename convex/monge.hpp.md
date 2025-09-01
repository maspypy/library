---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: convex/larsch.hpp
    title: convex/larsch.hpp
  - icon: ':x:'
    path: convex/smawk.hpp
    title: convex/smawk.hpp
  - icon: ':x:'
    path: other/fibonacci_search.hpp
    title: other/fibonacci_search.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/3_yukicoder/705.test.cpp
    title: test/3_yukicoder/705.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links:
    - https://noshi91.github.io/algorithm-encyclopedia/d-edge-shortest-path-monge
    - https://topcoder-g-hatena-ne-jp.jag-icpc.org/spaghetti_source/20120915/1347668163.html
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
    \  }\n\n  int get_argmin() { return base->get_argmin(); }\n};\n#line 2 \"convex/smawk.hpp\"\
    \n\n// select(i,j,k) \u306F (i,j) -> (i,k) \u3092\u884C\u3046\u304B\u3069\u3046\
    \u304B\n// \u6B8B\u5FF5\u306A\u304C\u3089 monotone minima \u3088\u308A\u9AD8\u901F\
    \u306A\u5834\u5408\u304C\u5B58\u5728\u3057\u306A\u3044\u8AAC\u304C\u3042\u308B\
    \n// https://codeforces.com/contest/1423/problem/M\ntemplate <typename F>\nvc<int>\
    \ smawk(int H, int W, F select) {\n  auto dfs = [&](auto& dfs, vc<int> X, vc<int>\
    \ Y) -> vc<int> {\n    int N = len(X);\n    if (N == 0) return {};\n    vc<int>\
    \ YY;\n    for (auto&& y: Y) {\n      while (len(YY)) {\n        int py = YY.back(),\
    \ x = X[len(YY) - 1];\n        if (!select(x, py, y)) break;\n        YY.pop_back();\n\
    \      }\n      if (len(YY) < len(X)) YY.eb(y);\n    }\n    vc<int> XX;\n    FOR(i,\
    \ 1, len(X), 2) XX.eb(X[i]);\n    vc<int> II = dfs(dfs, XX, YY);\n    vc<int>\
    \ I(N);\n    FOR(i, len(II)) I[i + i + 1] = II[i];\n    int p = 0;\n    FOR(i,\
    \ 0, N, 2) {\n      int LIM = (i + 1 == N ? Y.back() : I[i + 1]);\n      int best\
    \ = Y[p];\n      while (Y[p] < LIM) {\n        ++p;\n        if (select(X[i],\
    \ best, Y[p])) best = Y[p];\n      }\n      I[i] = best;\n    }\n    return I;\n\
    \  };\n  vc<int> X(H), Y(W);\n  iota(all(X), 0), iota(all(Y), 0);\n  return dfs(dfs,\
    \ X, Y);\n}\n#line 1 \"other/fibonacci_search.hpp\"\n// returns: {fx, x}\n// [L,\
    \ R) \u3067\u306E\u6975\u5C0F\u5024\u3092\u3072\u3068\u3064\u6C42\u3081\u308B\u3001\
    \u5358\u5CF0\u306F\u4E0D\u8981\ntemplate <typename T, bool MINIMIZE, typename\
    \ F>\npair<T, ll> fibonacci_search(F f, ll L, ll R) {\n  assert(L < R);\n  --R;\n\
    \  ll a = L, b = L + 1, c = L + 2, d = L + 3;\n  int n = 0;\n  while (d < R) {\
    \ b = c, c = d, d = b + c - a, ++n; }\n  auto get = [&](ll x) -> T {\n    if (R\
    \ < x) return infty<T>;\n    return (MINIMIZE ? f(x) : -f(x));\n  };\n  T ya =\
    \ get(a), yb = get(b), yc = get(c), yd = get(d);\n  // \u3053\u306E\u4E2D\u3067\
    \u6975\u5C0F\u306A\u3089\u3070\u5168\u4F53\u3067\u3082\u6975\u5C0F\u3001\u3092\
    \u7DAD\u6301\u3059\u308B\n  FOR(n) {\n    if (yb <= yc) {\n      d = c, c = b,\
    \ b = a + d - c;\n      yd = yc, yc = yb, yb = get(b);\n    } else {\n      a\
    \ = b, b = c, c = a + d - b;\n      ya = yb, yb = yc, yc = get(c);\n    }\n  }\n\
    \  ll x = a;\n  T y = ya;\n  if (chmin(y, yb)) x = b;\n  if (chmin(y, yc)) x =\
    \ c;\n  if (chmin(y, yd)) x = d;\n  if (MINIMIZE) return {y, x};\n  return {-y,\
    \ x};\n}\n#line 4 \"convex/monge.hpp\"\n\r\n// \u5B9A\u7FA9\u57DF [0, N] \u306E\
    \u7BC4\u56F2\u3067 f \u306E monge \u6027\u3092\u78BA\u8A8D\r\ntemplate <typename\
    \ T, typename F>\r\nbool check_monge(int N, F f) {\r\n  FOR(l, N + 1) FOR(k, l)\
    \ FOR(j, k) FOR(i, j) {\r\n    T lhs = f(i, l) + f(j, k);\r\n    T rhs = f(i,\
    \ k) + f(j, l);\r\n    if (lhs < rhs) {\r\n      print(\"monge ng\");\r\n    \
    \  print(i, j, k, l, f(i, k), f(i, l), f(j, k), f(j, l), lhs, rhs);\r\n      return\
    \ false;\r\n    }\r\n  }\r\n  print(\"monge ok\");\r\n  return true;\r\n}\r\n\r\
    \n// newdp[j] = min (dp[i] + f(i,j))\r\ntemplate <typename T, typename F>\r\n\
    vc<T> monge_dp_update(int N, vc<T>& dp, F f) {\r\n  assert(len(dp) == N + 1);\r\
    \n  auto select = [&](int i, int j, int k) -> int {\r\n    if (i <= k) return\
    \ j;\r\n    return (dp[j] + f(j, i) > dp[k] + f(k, i) ? k : j);\r\n  };\r\n  vc<int>\
    \ I = SMAWK(N + 1, N + 1, select);\r\n  vc<T> newdp(N + 1, infty<T>);\r\n  FOR(j,\
    \ N + 1) {\r\n    int i = I[j];\r\n    chmin(newdp[j], dp[i] + f(i, j));\r\n \
    \ }\r\n  return newdp;\r\n}\r\n\r\n// \u9077\u79FB\u56DE\u6570\u3092\u554F\u308F\
    \u306A\u3044\u5834\u5408\r\ntemplate <typename T, typename F>\r\nvc<T> monge_shortest_path(int\
    \ N, F f) {\r\n  vc<T> dp(N + 1, infty<T>);\r\n  dp[0] = 0;\r\n  LARSCH<T> larsch(N,\
    \ [&](int i, int j) -> T {\r\n    ++i;\r\n    if (i <= j) return infty<T>;\r\n\
    \    return dp[j] + f(j, i);\r\n  });\r\n  FOR(r, 1, N + 1) {\r\n    int l = larsch.get_argmin();\r\
    \n    dp[r] = dp[l] + f(l, r);\r\n  }\r\n  return dp;\r\n}\r\n\r\n// https://noshi91.github.io/algorithm-encyclopedia/d-edge-shortest-path-monge\r\
    \n// |f| \u306E\u4E0A\u9650 f_lim \u3082\u6E21\u3059\r\n// \u30FBlarsch \u304C\
    \u7D50\u69CB\u91CD\u3044\u306E\u3067\u3001\u81EA\u524D\u3067 dp \u3067\u304D\u308B\
    \u306A\u3089\u305D\u306E\u65B9\u304C\u3088\u3044\r\n// \u30FB\u8907\u6570\u306E\
    \ d \u3067\u8A08\u7B97\u3059\u308B\u3068\u304D\uFF1A\u540C\u3058 lambda\r\n//\
    \ \u306B\u5BFE\u3059\u308B\u8A08\u7B97\u3092\u30E1\u30E2\u5316\u3057\u3066\u304A\
    \u304F\u3068\u5B9A\u6570\u500D\u9AD8\u901F\uFF1F \u3000\u30FBABC305\r\ntemplate\
    \ <typename T, typename F>\r\nT monge_shortest_path_d_edge(int N, int d, T f_lim,\
    \ F f) {\r\n  assert(d <= N);\r\n  auto calc_L = [&](T lambda) -> T {\r\n    auto\
    \ cost = [&](int frm, int to) -> T { return f(frm, to) + lambda; };\r\n    vc<T>\
    \ dp = monge_shortest_path<T>(N, cost);\r\n    return dp[N] - lambda * d;\r\n\
    \  };\r\n\r\n  auto [fx, x] = fibonacci_search<T, false>(calc_L, -3 * f_lim, 3\
    \ * f_lim + 1);\r\n  return fx;\r\n}\r\n\r\n// https://topcoder-g-hatena-ne-jp.jag-icpc.org/spaghetti_source/20120915/1347668163.html\r\
    \n// Prop 1\r\n// \u4E0A\u4E09\u89D2 monge A, B\r\n// C[i][j] = min_k (A[i][k]\
    \ + B[k][j])\r\ntemplate <typename T, typename F1, typename F2>\r\nvvc<T> monge_matrix_product(int\
    \ N, F1 A, F2 B) {\r\n  vv(T, C, N + 1, N + 1, infty<T>);\r\n  vc<int> K(N + 1);\r\
    \n  FOR(i, N + 1) C[i][i] = A(i, i) + B(i, i), K[i] = i;\r\n  FOR(s, 1, N + 1)\
    \ {\r\n    vc<int> newK(N + 1 - s);\r\n    FOR(i, N + 1 - s) {\r\n      int j\
    \ = i + s;\r\n      int p = K[i], q = K[i + 1];\r\n      FOR(k, p, q + 1) if (chmin(C[i][j],\
    \ A(i, k) + B(k, j))) newK[i] = k;\r\n    }\r\n    swap(K, newK);\r\n  }\r\n \
    \ return C;\r\n}\r\n"
  code: "#include \"convex/larsch.hpp\"\r\n#include \"convex/smawk.hpp\"\r\n#include\
    \ \"other/fibonacci_search.hpp\"\r\n\r\n// \u5B9A\u7FA9\u57DF [0, N] \u306E\u7BC4\
    \u56F2\u3067 f \u306E monge \u6027\u3092\u78BA\u8A8D\r\ntemplate <typename T,\
    \ typename F>\r\nbool check_monge(int N, F f) {\r\n  FOR(l, N + 1) FOR(k, l) FOR(j,\
    \ k) FOR(i, j) {\r\n    T lhs = f(i, l) + f(j, k);\r\n    T rhs = f(i, k) + f(j,\
    \ l);\r\n    if (lhs < rhs) {\r\n      print(\"monge ng\");\r\n      print(i,\
    \ j, k, l, f(i, k), f(i, l), f(j, k), f(j, l), lhs, rhs);\r\n      return false;\r\
    \n    }\r\n  }\r\n  print(\"monge ok\");\r\n  return true;\r\n}\r\n\r\n// newdp[j]\
    \ = min (dp[i] + f(i,j))\r\ntemplate <typename T, typename F>\r\nvc<T> monge_dp_update(int\
    \ N, vc<T>& dp, F f) {\r\n  assert(len(dp) == N + 1);\r\n  auto select = [&](int\
    \ i, int j, int k) -> int {\r\n    if (i <= k) return j;\r\n    return (dp[j]\
    \ + f(j, i) > dp[k] + f(k, i) ? k : j);\r\n  };\r\n  vc<int> I = SMAWK(N + 1,\
    \ N + 1, select);\r\n  vc<T> newdp(N + 1, infty<T>);\r\n  FOR(j, N + 1) {\r\n\
    \    int i = I[j];\r\n    chmin(newdp[j], dp[i] + f(i, j));\r\n  }\r\n  return\
    \ newdp;\r\n}\r\n\r\n// \u9077\u79FB\u56DE\u6570\u3092\u554F\u308F\u306A\u3044\
    \u5834\u5408\r\ntemplate <typename T, typename F>\r\nvc<T> monge_shortest_path(int\
    \ N, F f) {\r\n  vc<T> dp(N + 1, infty<T>);\r\n  dp[0] = 0;\r\n  LARSCH<T> larsch(N,\
    \ [&](int i, int j) -> T {\r\n    ++i;\r\n    if (i <= j) return infty<T>;\r\n\
    \    return dp[j] + f(j, i);\r\n  });\r\n  FOR(r, 1, N + 1) {\r\n    int l = larsch.get_argmin();\r\
    \n    dp[r] = dp[l] + f(l, r);\r\n  }\r\n  return dp;\r\n}\r\n\r\n// https://noshi91.github.io/algorithm-encyclopedia/d-edge-shortest-path-monge\r\
    \n// |f| \u306E\u4E0A\u9650 f_lim \u3082\u6E21\u3059\r\n// \u30FBlarsch \u304C\
    \u7D50\u69CB\u91CD\u3044\u306E\u3067\u3001\u81EA\u524D\u3067 dp \u3067\u304D\u308B\
    \u306A\u3089\u305D\u306E\u65B9\u304C\u3088\u3044\r\n// \u30FB\u8907\u6570\u306E\
    \ d \u3067\u8A08\u7B97\u3059\u308B\u3068\u304D\uFF1A\u540C\u3058 lambda\r\n//\
    \ \u306B\u5BFE\u3059\u308B\u8A08\u7B97\u3092\u30E1\u30E2\u5316\u3057\u3066\u304A\
    \u304F\u3068\u5B9A\u6570\u500D\u9AD8\u901F\uFF1F \u3000\u30FBABC305\r\ntemplate\
    \ <typename T, typename F>\r\nT monge_shortest_path_d_edge(int N, int d, T f_lim,\
    \ F f) {\r\n  assert(d <= N);\r\n  auto calc_L = [&](T lambda) -> T {\r\n    auto\
    \ cost = [&](int frm, int to) -> T { return f(frm, to) + lambda; };\r\n    vc<T>\
    \ dp = monge_shortest_path<T>(N, cost);\r\n    return dp[N] - lambda * d;\r\n\
    \  };\r\n\r\n  auto [fx, x] = fibonacci_search<T, false>(calc_L, -3 * f_lim, 3\
    \ * f_lim + 1);\r\n  return fx;\r\n}\r\n\r\n// https://topcoder-g-hatena-ne-jp.jag-icpc.org/spaghetti_source/20120915/1347668163.html\r\
    \n// Prop 1\r\n// \u4E0A\u4E09\u89D2 monge A, B\r\n// C[i][j] = min_k (A[i][k]\
    \ + B[k][j])\r\ntemplate <typename T, typename F1, typename F2>\r\nvvc<T> monge_matrix_product(int\
    \ N, F1 A, F2 B) {\r\n  vv(T, C, N + 1, N + 1, infty<T>);\r\n  vc<int> K(N + 1);\r\
    \n  FOR(i, N + 1) C[i][i] = A(i, i) + B(i, i), K[i] = i;\r\n  FOR(s, 1, N + 1)\
    \ {\r\n    vc<int> newK(N + 1 - s);\r\n    FOR(i, N + 1 - s) {\r\n      int j\
    \ = i + s;\r\n      int p = K[i], q = K[i + 1];\r\n      FOR(k, p, q + 1) if (chmin(C[i][j],\
    \ A(i, k) + B(k, j))) newK[i] = k;\r\n    }\r\n    swap(K, newK);\r\n  }\r\n \
    \ return C;\r\n}\r\n"
  dependsOn:
  - convex/larsch.hpp
  - convex/smawk.hpp
  - other/fibonacci_search.hpp
  isVerificationFile: false
  path: convex/monge.hpp
  requiredBy: []
  timestamp: '2025-07-25 21:12:10+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/3_yukicoder/705.test.cpp
documentation_of: convex/monge.hpp
layout: document
redirect_from:
- /library/convex/monge.hpp
- /library/convex/monge.hpp.html
title: convex/monge.hpp
---
