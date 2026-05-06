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
    - https://codeforces.com/contest/2183/problem/H
    - https://topcoder-g-hatena-ne-jp.jag-icpc.org/spaghetti_source/20120915/1347668163.html
  bundledCode: "#line 1 \"convex/larsch.hpp\"\n// \u5236\u7D04\u304D\u3064\u3044 https://codeforces.com/contest/2183/problem/H\n\
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
    \ get_argmin() { return base_->get_argmin(); }\n};\n#line 2 \"convex/smawk.hpp\"\
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
    \ N, F f) {\r\n  vc<T> dp(N + 1, infty<T>);\r\n  dp[0] = 0;\r\n  auto g = [&](int\
    \ i, int j) -> T {\r\n    ++i;\r\n    if (i <= j) return infty<T>;\r\n    return\
    \ dp[j] + f(j, i);\r\n  };\r\n  LARSCH<T, decltype(g)> larsch(N, g);\r\n  FOR(r,\
    \ 1, N + 1) {\r\n    int l = larsch.get_argmin();\r\n    dp[r] = dp[l] + f(l,\
    \ r);\r\n  }\r\n  return dp;\r\n}\r\n\r\n// https://codeforces.com/contest/2183/problem/H\r\
    \ntemplate <typename T, typename F>\r\nT monge_shortest_path_d_edge(int N, int\
    \ d, T flim, F f) {\r\n  assert(1 <= d && d <= N);\r\n  if (d == 1) return f(0,\
    \ N);\r\n  if (d == N) {\r\n    T ans = 0;\r\n    FOR(i, N) ans += f(i, i + 1);\r\
    \n    return ans;\r\n  }\r\n  if (d == 2) {\r\n    T ans = infty<T>;\r\n    FOR(i,\
    \ 1, N) chmin(ans, f(0, i) + f(i, N));\r\n    return ans;\r\n  }\r\n\r\n  vc<pair<T,\
    \ int>> dp(N + 1);\r\n  map<T, pair<T, int>> MP;\r\n  T ANS = -infty<T>;\r\n \
    \ auto calc = [&](T lambda) -> pair<T, int> {\r\n    if (MP.count(lambda)) return\
    \ MP[lambda];\r\n    dp[0] = {0, 0};\r\n    auto eval = [&](int i, int j) -> T\
    \ {\r\n      ++i;\r\n      if (i <= j) return infty<T>;\r\n      return dp[j].fi\
    \ + f(j, i);\r\n    };\r\n    LARSCH<T, decltype(eval)> larsch(N, eval);\r\n\r\
    \n    FOR(r, 1, N + 1) {\r\n      int l = larsch.get_argmin();\r\n      dp[r].fi\
    \ = dp[l].fi + f(l, r) + lambda;\r\n      dp[r].se = dp[l].se + 1;\r\n    }\r\n\
    \    chmax(ANS, dp[N].fi - lambda * d);\r\n    return MP[lambda] = dp[N];\r\n\
    \  };\r\n\r\n  T lo = -3 * flim - 10, hi = 3 * flim + 10;\r\n  while (lo + 1 <\
    \ hi) {\r\n    T mi = (lo + hi) / 2;\r\n    int k = calc(mi).se;\r\n    if (k\
    \ == d) break;\r\n    (k > d ? lo : hi) = mi;\r\n  }\r\n  return ANS;\r\n}\r\n\
    \r\n// https://topcoder-g-hatena-ne-jp.jag-icpc.org/spaghetti_source/20120915/1347668163.html\r\
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
    \ N, F f) {\r\n  vc<T> dp(N + 1, infty<T>);\r\n  dp[0] = 0;\r\n  auto g = [&](int\
    \ i, int j) -> T {\r\n    ++i;\r\n    if (i <= j) return infty<T>;\r\n    return\
    \ dp[j] + f(j, i);\r\n  };\r\n  LARSCH<T, decltype(g)> larsch(N, g);\r\n  FOR(r,\
    \ 1, N + 1) {\r\n    int l = larsch.get_argmin();\r\n    dp[r] = dp[l] + f(l,\
    \ r);\r\n  }\r\n  return dp;\r\n}\r\n\r\n// https://codeforces.com/contest/2183/problem/H\r\
    \ntemplate <typename T, typename F>\r\nT monge_shortest_path_d_edge(int N, int\
    \ d, T flim, F f) {\r\n  assert(1 <= d && d <= N);\r\n  if (d == 1) return f(0,\
    \ N);\r\n  if (d == N) {\r\n    T ans = 0;\r\n    FOR(i, N) ans += f(i, i + 1);\r\
    \n    return ans;\r\n  }\r\n  if (d == 2) {\r\n    T ans = infty<T>;\r\n    FOR(i,\
    \ 1, N) chmin(ans, f(0, i) + f(i, N));\r\n    return ans;\r\n  }\r\n\r\n  vc<pair<T,\
    \ int>> dp(N + 1);\r\n  map<T, pair<T, int>> MP;\r\n  T ANS = -infty<T>;\r\n \
    \ auto calc = [&](T lambda) -> pair<T, int> {\r\n    if (MP.count(lambda)) return\
    \ MP[lambda];\r\n    dp[0] = {0, 0};\r\n    auto eval = [&](int i, int j) -> T\
    \ {\r\n      ++i;\r\n      if (i <= j) return infty<T>;\r\n      return dp[j].fi\
    \ + f(j, i);\r\n    };\r\n    LARSCH<T, decltype(eval)> larsch(N, eval);\r\n\r\
    \n    FOR(r, 1, N + 1) {\r\n      int l = larsch.get_argmin();\r\n      dp[r].fi\
    \ = dp[l].fi + f(l, r) + lambda;\r\n      dp[r].se = dp[l].se + 1;\r\n    }\r\n\
    \    chmax(ANS, dp[N].fi - lambda * d);\r\n    return MP[lambda] = dp[N];\r\n\
    \  };\r\n\r\n  T lo = -3 * flim - 10, hi = 3 * flim + 10;\r\n  while (lo + 1 <\
    \ hi) {\r\n    T mi = (lo + hi) / 2;\r\n    int k = calc(mi).se;\r\n    if (k\
    \ == d) break;\r\n    (k > d ? lo : hi) = mi;\r\n  }\r\n  return ANS;\r\n}\r\n\
    \r\n// https://topcoder-g-hatena-ne-jp.jag-icpc.org/spaghetti_source/20120915/1347668163.html\r\
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
  timestamp: '2026-03-14 22:08:09+09:00'
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
