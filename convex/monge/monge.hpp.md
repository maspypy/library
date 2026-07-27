---
data:
  _extendedDependsOn:
  - icon: ':warning:'
    path: convex/larsch.hpp
    title: convex/larsch.hpp
  - icon: ':question:'
    path: convex/smawk.hpp
    title: convex/smawk.hpp
  - icon: ':question:'
    path: other/fibonacci_search.hpp
    title: other/fibonacci_search.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links:
    - https://codeforces.com/contest/2183/problem/H
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
    \n\n// \u5404\u884C\u306E\u6700\u9069\u5217\u3092\u6C42\u3081\u308B.\n// better(i,j,k):\
    \ \u884C i \u306B\u304A\u3044\u3066\u5217 k \u304C\u5217 j \u3088\u308A\u826F\u3044\
    \u3068\u304D true.\n// \u9069\u7528\u6761\u4EF6\uFF1Atotally monotone matrix.\n\
    template <typename F>\nvc<int> smawk(int H, int W, F better) {\n  if (H == 0)\
    \ return {};\n  assert(W > 0);\n\n  auto dfs = [&](auto& dfs, vc<int> X, vc<int>\
    \ Y) -> vc<int> {\n    int N = len(X);\n    if (N == 0) return {};\n\n    vc<int>\
    \ YY;\n    for (auto&& y : Y) {\n      while (len(YY)) {\n        int py = YY.back(),\
    \ x = X[len(YY) - 1];\n        if (!better(x, py, y)) break;\n        YY.pop_back();\n\
    \      }\n      if (len(YY) < len(X)) YY.eb(y);\n    }\n\n    vc<int> XX;\n  \
    \  FOR(i, 1, len(X), 2) XX.eb(X[i]);\n\n    vc<int> II = dfs(dfs, XX, YY);\n \
    \   vc<int> I(N);\n    FOR(i, len(II)) I[i + i + 1] = II[i];\n\n    int p = 0;\n\
    \    FOR(i, 0, N, 2) {\n      int lim = (i + 1 == N ? Y.back() : I[i + 1]);\n\
    \      int best = Y[p];\n      while (Y[p] < lim) {\n        ++p;\n        if\
    \ (better(X[i], best, Y[p])) best = Y[p];\n      }\n      I[i] = best;\n    }\n\
    \    return I;\n  };\n\n  vc<int> X(H), Y(W);\n  iota(all(X), 0), iota(all(Y),\
    \ 0);\n  return dfs(dfs, X, Y);\n}\n#line 1 \"other/fibonacci_search.hpp\"\n//\
    \ returns: {fx, x}\n// [L, R) \u3067\u306E\u6975\u5C0F\u5024\u3092\u3072\u3068\
    \u3064\u6C42\u3081\u308B\u3001\u5358\u5CF0\u306F\u4E0D\u8981\ntemplate <typename\
    \ T, bool MINIMIZE, typename F>\npair<T, ll> fibonacci_search(F f, ll L, ll R)\
    \ {\n  assert(L < R);\n  --R;\n  ll a = L, b = L + 1, c = L + 2, d = L + 3;\n\
    \  int n = 0;\n  while (d < R) { b = c, c = d, d = b + c - a, ++n; }\n  auto get\
    \ = [&](ll x) -> T {\n    if (R < x) return infty<T>;\n    return (MINIMIZE ?\
    \ f(x) : -f(x));\n  };\n  T ya = get(a), yb = get(b), yc = get(c), yd = get(d);\n\
    \  // \u3053\u306E\u4E2D\u3067\u6975\u5C0F\u306A\u3089\u3070\u5168\u4F53\u3067\
    \u3082\u6975\u5C0F\u3001\u3092\u7DAD\u6301\u3059\u308B\n  FOR(n) {\n    if (yb\
    \ <= yc) {\n      d = c, c = b, b = a + d - c;\n      yd = yc, yc = yb, yb = get(b);\n\
    \    } else {\n      a = b, b = c, c = a + d - b;\n      ya = yb, yb = yc, yc\
    \ = get(c);\n    }\n  }\n  ll x = a;\n  T y = ya;\n  if (chmin(y, yb)) x = b;\n\
    \  if (chmin(y, yc)) x = c;\n  if (chmin(y, yd)) x = d;\n  if (MINIMIZE) return\
    \ {y, x};\n  return {-y, x};\n}\n#line 4 \"convex/monge/monge.hpp\"\n\r\n// https://codeforces.com/contest/2183/problem/H\r\
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
    \ == d) break;\r\n    (k > d ? lo : hi) = mi;\r\n  }\r\n  return ANS;\r\n}\r\n"
  code: "#include \"convex/larsch.hpp\"\r\n#include \"convex/smawk.hpp\"\r\n#include\
    \ \"other/fibonacci_search.hpp\"\r\n\r\n// https://codeforces.com/contest/2183/problem/H\r\
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
    \ == d) break;\r\n    (k > d ? lo : hi) = mi;\r\n  }\r\n  return ANS;\r\n}\r\n"
  dependsOn:
  - convex/larsch.hpp
  - convex/smawk.hpp
  - other/fibonacci_search.hpp
  isVerificationFile: false
  path: convex/monge/monge.hpp
  requiredBy: []
  timestamp: '2026-06-20 11:40:52+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: convex/monge/monge.hpp
layout: document
redirect_from:
- /library/convex/monge/monge.hpp
- /library/convex/monge/monge.hpp.html
title: convex/monge/monge.hpp
---
