---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: ds/fastset.hpp
    title: ds/fastset.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/atcoder/abc256d.test.cpp
    title: test/atcoder/abc256d.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links:
    - https://codeforces.com/contest/1638/problem/E
    - https://codeforces.com/contest/897/problem/E
  bundledCode: "#line 1 \"ds/intervals.hpp\"\n// https://codeforces.com/contest/1638/problem/E\n\
    // https://codeforces.com/contest/897/problem/E\n// \u6301\u3064\u5024\u306E\u30BF\
    \u30A4\u30D7 T\u3001\u5EA7\u6A19\u30BF\u30A4\u30D7 X\n// \u30B3\u30F3\u30B9\u30C8\
    \u30E9\u30AF\u30BF\u3067\u306F T none_val \u3092\u6307\u5B9A\u3059\u308B\ntemplate\
    \ <typename T = ll, typename X = ll>\nstruct Intervals {\n  static constexpr X\
    \ LLIM = numeric_limits<X>::lowest();\n  static constexpr X RLIM = numeric_limits<X>::max();\n\
    \  const T none_val;\n  // none_val \u3067\u306A\u3044\u533A\u9593\u306E\u500B\
    \u6570\u3068\u9577\u3055\u5408\u8A08\n  int total_num;\n  X total_len;\n  map<X,\
    \ T> dat;\n\n  Intervals(T none_val) : none_val(none_val), total_num(0), total_len(0)\
    \ {\n    dat[LLIM] = none_val;\n    dat[RLIM] = none_val;\n  }\n\n  tuple<X, X,\
    \ T> get(X x) {\n    auto it = dat.upper_bound(x);\n    X r = (*it).fi;\n    auto\
    \ [l, t] = *prev(it);\n    return {l, r, t};\n  }\n\n  template <typename ADD,\
    \ typename RM>\n  void set(X L, X R, T t, ADD& add_f, RM& rm_f) {\n    if (L ==\
    \ R) return;\n    assert(L < R);\n    // \u533A\u9593 [l, r) \u3092 t \u306B\u5909\
    \u66F4\u3059\u308B\n    // \u307E\u305A\u306F\u3001\u91CD\u306A\u308B\u304B\u96A3\
    \u308A\u5408\u3046\u533A\u9593\u3092\u5168\u5217\u6319\n    vc<tuple<X, X, T>>\
    \ tmp;\n    auto it = prev(dat.lower_bound(L));\n    while (1) {\n      auto [l,\
    \ t] = *it;\n      if (R < l) break;\n      it = next(it);\n      X r = (*it).fi;\n\
    \      tmp.eb(l, r, t);\n    }\n    auto [lx, _, lt] = tmp[0];\n    auto [__,\
    \ rx, rt] = tmp.back();\n    // \u3068\u308A\u3042\u3048\u305A\u5168\u90E8\u524A\
    \u9664\n    for (auto&& [l, r, t]: tmp) {\n      dat.erase(l);\n      if (t ==\
    \ none_val) continue;\n      total_num--;\n      total_len -= r - l;\n      rm_f(l,\
    \ r, t);\n    }\n    if (lt == t) chmin(L, lx);\n    if (rt == t) chmax(R, rx);\n\
    \    if (lx < L) {\n      // [lx, L)\n      dat[lx] = lt;\n      if (lt != none_val)\
    \ {\n        total_num++;\n        total_len += L - lx;\n        add_f(lx, L,\
    \ lt);\n      }\n    }\n    if (R < rx) {\n      // [R, rx)\n      dat[R] = rt;\n\
    \      if (rt != none_val) {\n        total_num++;\n        total_len += rx -\
    \ R;\n        add_f(R, rx, rt);\n      }\n    }\n    // [L, R)\n    dat[L] = t;\n\
    \    if (t != none_val) {\n      total_num++;\n      total_len += R - L;\n   \
    \   add_f(L, R, t);\n    }\n  }\n\n  void set(X L, X R, T t = 1) {\n    auto f\
    \ = [&](X L, X R, T t) -> void {};\n    set(L, R, t, f, f);\n  }\n\n  void erase(X\
    \ L, X R) {\n    auto f = [&](X L, X R, T t) -> void {};\n    set(L, R, none_val,\
    \ f, f);\n  }\n\n  // L, R \u5185\u306E\u30C7\u30FC\u30BF (l, r, t) \u3092\u5168\
    \u90E8\u53D6\u5F97\u3059\u308B\n  vc<tuple<X, X, T>> get(X L, X R) {\n    vc<tuple<X,\
    \ X, T>> res;\n    auto it = dat.lower_bound(L);\n    if(it != dat.begin()) it\
    \ = prev(it);\n    while (1) {\n      auto [l, t] = *it;\n      if (R <= l) break;\n\
    \      it = next(it);\n      X r = (*it).fi;\n      X l0 = max(l, L);\n      X\
    \ r0 = min(r, R);\n      if (l0 < r0) res.eb(l0, r0, t);\n    }\n    return res;\n\
    \  }\n\n  vc<tuple<X, X, T>> get_all() {\n    return get(LLIM, RLIM);\n  }\n\n\
    \  void debug() {\n    auto it = dat.begin();\n    print(\"Intervals\");\n   \
    \ print(\"total_num\", total_num);\n    print(\"total_len\", total_len);\n   \
    \ while (1) {\n      auto [l, t] = *it;\n      ++it;\n      if (it == dat.end())\
    \ break;\n      X r = (*it).fi;\n      print(\"l, r, t\", l, r, t);\n    }\n \
    \ }\n};\n\n\n#line 1 \"ds/fastset.hpp\"\n/* 64\u5206\u6728\u3002\r\ninsert, erase\r\
    \n[]\u3067\u306E\u5B58\u5728\u5224\u5B9A\r\nnext, prev\r\n*/\r\nstruct FastSet\
    \ {\r\n  using uint = unsigned;\r\n  using ull = unsigned long long;\r\n\r\n \
    \ int bsr(ull x) { return 63 - __builtin_clzll(x); }\r\n  int bsf(ull x) { return\
    \ __builtin_ctzll(x); }\r\n\r\n  static constexpr uint B = 64;\r\n  int n, lg;\r\
    \n  vector<vector<ull>> seg;\r\n  FastSet(int _n) : n(_n) {\r\n    do {\r\n  \
    \    seg.push_back(vector<ull>((_n + B - 1) / B));\r\n      _n = (_n + B - 1)\
    \ / B;\r\n    } while (_n > 1);\r\n    lg = int(seg.size());\r\n  }\r\n  bool\
    \ operator[](int i) const { return (seg[0][i / B] >> (i % B) & 1) != 0; }\r\n\
    \  void insert(int i) {\r\n    for (int h = 0; h < lg; h++) {\r\n      seg[h][i\
    \ / B] |= 1ULL << (i % B);\r\n      i /= B;\r\n    }\r\n  }\r\n  void erase(int\
    \ i) {\r\n    for (int h = 0; h < lg; h++) {\r\n      seg[h][i / B] &= ~(1ULL\
    \ << (i % B));\r\n      if (seg[h][i / B]) break;\r\n      i /= B;\r\n    }\r\n\
    \  }\r\n\r\n  // x\u4EE5\u4E0A\u6700\u5C0F\u306E\u8981\u7D20\u3092\u8FD4\u3059\
    \u3002\u5B58\u5728\u3057\u306A\u3051\u308C\u3070 n\u3002\r\n  int next(int i)\
    \ {\r\n    chmax(i, 0);\r\n    if (i >= n) return n;\r\n    for (int h = 0; h\
    \ < lg; h++) {\r\n      if (i / B == seg[h].size()) break;\r\n      ull d = seg[h][i\
    \ / B] >> (i % B);\r\n      if (!d) {\r\n        i = i / B + 1;\r\n        continue;\r\
    \n      }\r\n      // find\r\n      i += bsf(d);\r\n      for (int g = h - 1;\
    \ g >= 0; g--) {\r\n        i *= B;\r\n        i += bsf(seg[g][i / B]);\r\n  \
    \    }\r\n      return i;\r\n    }\r\n    return n;\r\n  }\r\n\r\n  // x\u4EE5\
    \u4E0B\u6700\u5927\u306E\u8981\u7D20\u3092\u8FD4\u3059\u3002\u5B58\u5728\u3057\
    \u306A\u3051\u308C\u3070 -1\u3002\r\n  int prev(int i) {\r\n    if (i < 0) return\
    \ -1;\r\n    if (i >= n) i = n - 1;\r\n    for (int h = 0; h < lg; h++) {\r\n\
    \      if (i == -1) break;\r\n      ull d = seg[h][i / B] << (63 - i % 64);\r\n\
    \      if (!d) {\r\n        i = i / B - 1;\r\n        continue;\r\n      }\r\n\
    \      // find\r\n      i += bsr(d) - (B - 1);\r\n      for (int g = h - 1; g\
    \ >= 0; g--) {\r\n        i *= B;\r\n        i += bsr(seg[g][i / B]);\r\n    \
    \  }\r\n      return i;\r\n    }\r\n    return -1;\r\n  }\r\n\r\n  // [l, r) \u5185\
    \u306E\u8981\u7D20\u3092\u5168\u90E8\u96C6\u3081\u308B\r\n  vector<int> collect(int\
    \ l, int r) {\r\n    vector<int> res;\r\n    int x = l - 1;\r\n    while (1) {\r\
    \n      x = next(x + 1);\r\n      if (x >= r) break;\r\n      res.emplace_back(x);\r\
    \n    }\r\n    return res;\r\n  }\r\n\r\n  void debug() {\r\n    string s;\r\n\
    \    for (int i = 0; i < n; ++i) s += ((*this)[i] ? '1' : '0');\r\n    print(s);\r\
    \n  }\r\n};\r\n#line 129 \"ds/intervals.hpp\"\n\n// FastSet \u3067\u9AD8\u901F\
    \u5316\u3057\u305F\u3082\u306E\ntemplate <typename T>\nstruct Intervals_Fast {\n\
    \  const int LLIM, RLIM;\n  const T none_val;\n  // none_val \u3067\u306A\u3044\
    \u533A\u9593\u306E\u500B\u6570\u3068\u9577\u3055\u5408\u8A08\n  int total_num;\n\
    \  int total_len;\n  vc<T> dat;\n  FastSet ss;\n\n  Intervals_Fast(int N, T none_val)\n\
    \      : LLIM(0),\n        RLIM(N),\n        none_val(none_val),\n        total_num(0),\n\
    \        total_len(0),\n        dat(N, none_val),\n        ss(N + 1) {\n    ss.insert(0);\n\
    \    ss.insert(N);\n  }\n\n  tuple<int, int, T> get(int x) {\n    auto l = ss.prev(x);\n\
    \    auto r = ss.next(x + 1);\n    return {l, r, dat[l]};\n  }\n\n  template <typename\
    \ ADD, typename RM>\n  void set(int L, int R, T t, ADD& add_f, RM& rm_f) {\n \
    \   assert(LLIM <= L && L <= R && R <= RLIM);\n    if (L == R) return;\n    assert(L\
    \ < R);\n    // \u533A\u9593 [l, r) \u3092 t \u306B\u5909\u66F4\u3059\u308B\n\
    \    // \u307E\u305A\u306F\u3001\u91CD\u306A\u308B\u304B\u96A3\u308A\u5408\u3046\
    \u533A\u9593\u3092\u5168\u5217\u6319\n    vc<tuple<int, int, T>> tmp;\n    auto\
    \ l = ss.prev(L);\n    while (l < R) {\n      auto r = ss.next(l + 1);\n     \
    \ auto t = dat[l];\n      tmp.eb(l, r, t);\n      l = r;\n    }\n    auto [lx,\
    \ _, lt] = tmp[0];\n    auto [__, rx, rt] = tmp.back();\n    // \u3068\u308A\u3042\
    \u3048\u305A\u5168\u90E8\u524A\u9664\n    for (auto&& [l, r, t]: tmp) {\n    \
    \  ss.erase(l);\n      if (t == none_val) continue;\n      total_num--;\n    \
    \  total_len -= r - l;\n      rm_f(l, r, t);\n    }\n    if (lt == t) chmin(L,\
    \ lx);\n    if (rt == t) chmax(R, rx);\n    if (lx < L) {\n      // [lx, L)\n\
    \      ss.insert(lx);\n      dat[lx] = lt;\n      if (lt != none_val) {\n    \
    \    total_num++;\n        total_len += L - lx;\n        add_f(lx, L, lt);\n \
    \     }\n    }\n    if (R < rx) {\n      // [R, rx)\n      ss.insert(R);\n   \
    \   dat[R] = rt;\n      if (rt != none_val) {\n        total_num++;\n        total_len\
    \ += rx - R;\n        add_f(R, rx, rt);\n      }\n    }\n    // [L, R)\n    ss.insert(L);\n\
    \    dat[L] = t;\n    if (t != none_val) {\n      total_num++;\n      total_len\
    \ += R - L;\n      add_f(L, R, t);\n    }\n  }\n\n  void set(int L, int R, T t)\
    \ {\n    auto f = [&](int L, int R, T t) -> void {};\n    set(L, R, t, f, f);\n\
    \  }\n\n  void erase(int L, int R) {\n    auto f = [&](int L, int R, T t) -> void\
    \ {};\n    set(L, R, none_val, f, f);\n  }\n\n  // L, R \u5185\u306E\u30C7\u30FC\
    \u30BF (l, r, t) \u3092\u5168\u90E8\u53D6\u5F97\u3059\u308B\n  vc<tuple<int, int,\
    \ T>> get(int L, int R) {\n    assert(LLIM <= L && L <= R && R <= RLIM);\n   \
    \ vc<tuple<int, int, T>> res;\n    auto l = ss.prev(L);\n    while (l < R) {\n\
    \      auto t = dat[l];\n      auto r = ss.next(l + 1);\n      int l0 = max(l,\
    \ L);\n      int r0 = min(r, R);\n      if (l0 < r0) res.eb(l0, r0, t);\n    \
    \  l = r;\n    }\n    return res;\n  }\n\n  vc<tuple<int, int, T>> get_all() {\
    \ return get(LLIM, RLIM); }\n\n  void debug() {\n    print(\"Intervals\");\n \
    \   print(\"total_num\", total_num);\n    print(\"total_len\", total_len);\n \
    \   int l = 0;\n    while (l < RLIM) {\n      auto t = dat[l];\n      auto r =\
    \ ss.next(l + 1);\n      print(\"l, r, t\", l, r, t);\n      l = r;\n    }\n \
    \ }\n};\n"
  code: "// https://codeforces.com/contest/1638/problem/E\n// https://codeforces.com/contest/897/problem/E\n\
    // \u6301\u3064\u5024\u306E\u30BF\u30A4\u30D7 T\u3001\u5EA7\u6A19\u30BF\u30A4\u30D7\
    \ X\n// \u30B3\u30F3\u30B9\u30C8\u30E9\u30AF\u30BF\u3067\u306F T none_val \u3092\
    \u6307\u5B9A\u3059\u308B\ntemplate <typename T = ll, typename X = ll>\nstruct\
    \ Intervals {\n  static constexpr X LLIM = numeric_limits<X>::lowest();\n  static\
    \ constexpr X RLIM = numeric_limits<X>::max();\n  const T none_val;\n  // none_val\
    \ \u3067\u306A\u3044\u533A\u9593\u306E\u500B\u6570\u3068\u9577\u3055\u5408\u8A08\
    \n  int total_num;\n  X total_len;\n  map<X, T> dat;\n\n  Intervals(T none_val)\
    \ : none_val(none_val), total_num(0), total_len(0) {\n    dat[LLIM] = none_val;\n\
    \    dat[RLIM] = none_val;\n  }\n\n  tuple<X, X, T> get(X x) {\n    auto it =\
    \ dat.upper_bound(x);\n    X r = (*it).fi;\n    auto [l, t] = *prev(it);\n   \
    \ return {l, r, t};\n  }\n\n  template <typename ADD, typename RM>\n  void set(X\
    \ L, X R, T t, ADD& add_f, RM& rm_f) {\n    if (L == R) return;\n    assert(L\
    \ < R);\n    // \u533A\u9593 [l, r) \u3092 t \u306B\u5909\u66F4\u3059\u308B\n\
    \    // \u307E\u305A\u306F\u3001\u91CD\u306A\u308B\u304B\u96A3\u308A\u5408\u3046\
    \u533A\u9593\u3092\u5168\u5217\u6319\n    vc<tuple<X, X, T>> tmp;\n    auto it\
    \ = prev(dat.lower_bound(L));\n    while (1) {\n      auto [l, t] = *it;\n   \
    \   if (R < l) break;\n      it = next(it);\n      X r = (*it).fi;\n      tmp.eb(l,\
    \ r, t);\n    }\n    auto [lx, _, lt] = tmp[0];\n    auto [__, rx, rt] = tmp.back();\n\
    \    // \u3068\u308A\u3042\u3048\u305A\u5168\u90E8\u524A\u9664\n    for (auto&&\
    \ [l, r, t]: tmp) {\n      dat.erase(l);\n      if (t == none_val) continue;\n\
    \      total_num--;\n      total_len -= r - l;\n      rm_f(l, r, t);\n    }\n\
    \    if (lt == t) chmin(L, lx);\n    if (rt == t) chmax(R, rx);\n    if (lx <\
    \ L) {\n      // [lx, L)\n      dat[lx] = lt;\n      if (lt != none_val) {\n \
    \       total_num++;\n        total_len += L - lx;\n        add_f(lx, L, lt);\n\
    \      }\n    }\n    if (R < rx) {\n      // [R, rx)\n      dat[R] = rt;\n   \
    \   if (rt != none_val) {\n        total_num++;\n        total_len += rx - R;\n\
    \        add_f(R, rx, rt);\n      }\n    }\n    // [L, R)\n    dat[L] = t;\n \
    \   if (t != none_val) {\n      total_num++;\n      total_len += R - L;\n    \
    \  add_f(L, R, t);\n    }\n  }\n\n  void set(X L, X R, T t = 1) {\n    auto f\
    \ = [&](X L, X R, T t) -> void {};\n    set(L, R, t, f, f);\n  }\n\n  void erase(X\
    \ L, X R) {\n    auto f = [&](X L, X R, T t) -> void {};\n    set(L, R, none_val,\
    \ f, f);\n  }\n\n  // L, R \u5185\u306E\u30C7\u30FC\u30BF (l, r, t) \u3092\u5168\
    \u90E8\u53D6\u5F97\u3059\u308B\n  vc<tuple<X, X, T>> get(X L, X R) {\n    vc<tuple<X,\
    \ X, T>> res;\n    auto it = dat.lower_bound(L);\n    if(it != dat.begin()) it\
    \ = prev(it);\n    while (1) {\n      auto [l, t] = *it;\n      if (R <= l) break;\n\
    \      it = next(it);\n      X r = (*it).fi;\n      X l0 = max(l, L);\n      X\
    \ r0 = min(r, R);\n      if (l0 < r0) res.eb(l0, r0, t);\n    }\n    return res;\n\
    \  }\n\n  vc<tuple<X, X, T>> get_all() {\n    return get(LLIM, RLIM);\n  }\n\n\
    \  void debug() {\n    auto it = dat.begin();\n    print(\"Intervals\");\n   \
    \ print(\"total_num\", total_num);\n    print(\"total_len\", total_len);\n   \
    \ while (1) {\n      auto [l, t] = *it;\n      ++it;\n      if (it == dat.end())\
    \ break;\n      X r = (*it).fi;\n      print(\"l, r, t\", l, r, t);\n    }\n \
    \ }\n};\n\n\n#include \"ds/fastset.hpp\"\n\n// FastSet \u3067\u9AD8\u901F\u5316\
    \u3057\u305F\u3082\u306E\ntemplate <typename T>\nstruct Intervals_Fast {\n  const\
    \ int LLIM, RLIM;\n  const T none_val;\n  // none_val \u3067\u306A\u3044\u533A\
    \u9593\u306E\u500B\u6570\u3068\u9577\u3055\u5408\u8A08\n  int total_num;\n  int\
    \ total_len;\n  vc<T> dat;\n  FastSet ss;\n\n  Intervals_Fast(int N, T none_val)\n\
    \      : LLIM(0),\n        RLIM(N),\n        none_val(none_val),\n        total_num(0),\n\
    \        total_len(0),\n        dat(N, none_val),\n        ss(N + 1) {\n    ss.insert(0);\n\
    \    ss.insert(N);\n  }\n\n  tuple<int, int, T> get(int x) {\n    auto l = ss.prev(x);\n\
    \    auto r = ss.next(x + 1);\n    return {l, r, dat[l]};\n  }\n\n  template <typename\
    \ ADD, typename RM>\n  void set(int L, int R, T t, ADD& add_f, RM& rm_f) {\n \
    \   assert(LLIM <= L && L <= R && R <= RLIM);\n    if (L == R) return;\n    assert(L\
    \ < R);\n    // \u533A\u9593 [l, r) \u3092 t \u306B\u5909\u66F4\u3059\u308B\n\
    \    // \u307E\u305A\u306F\u3001\u91CD\u306A\u308B\u304B\u96A3\u308A\u5408\u3046\
    \u533A\u9593\u3092\u5168\u5217\u6319\n    vc<tuple<int, int, T>> tmp;\n    auto\
    \ l = ss.prev(L);\n    while (l < R) {\n      auto r = ss.next(l + 1);\n     \
    \ auto t = dat[l];\n      tmp.eb(l, r, t);\n      l = r;\n    }\n    auto [lx,\
    \ _, lt] = tmp[0];\n    auto [__, rx, rt] = tmp.back();\n    // \u3068\u308A\u3042\
    \u3048\u305A\u5168\u90E8\u524A\u9664\n    for (auto&& [l, r, t]: tmp) {\n    \
    \  ss.erase(l);\n      if (t == none_val) continue;\n      total_num--;\n    \
    \  total_len -= r - l;\n      rm_f(l, r, t);\n    }\n    if (lt == t) chmin(L,\
    \ lx);\n    if (rt == t) chmax(R, rx);\n    if (lx < L) {\n      // [lx, L)\n\
    \      ss.insert(lx);\n      dat[lx] = lt;\n      if (lt != none_val) {\n    \
    \    total_num++;\n        total_len += L - lx;\n        add_f(lx, L, lt);\n \
    \     }\n    }\n    if (R < rx) {\n      // [R, rx)\n      ss.insert(R);\n   \
    \   dat[R] = rt;\n      if (rt != none_val) {\n        total_num++;\n        total_len\
    \ += rx - R;\n        add_f(R, rx, rt);\n      }\n    }\n    // [L, R)\n    ss.insert(L);\n\
    \    dat[L] = t;\n    if (t != none_val) {\n      total_num++;\n      total_len\
    \ += R - L;\n      add_f(L, R, t);\n    }\n  }\n\n  void set(int L, int R, T t)\
    \ {\n    auto f = [&](int L, int R, T t) -> void {};\n    set(L, R, t, f, f);\n\
    \  }\n\n  void erase(int L, int R) {\n    auto f = [&](int L, int R, T t) -> void\
    \ {};\n    set(L, R, none_val, f, f);\n  }\n\n  // L, R \u5185\u306E\u30C7\u30FC\
    \u30BF (l, r, t) \u3092\u5168\u90E8\u53D6\u5F97\u3059\u308B\n  vc<tuple<int, int,\
    \ T>> get(int L, int R) {\n    assert(LLIM <= L && L <= R && R <= RLIM);\n   \
    \ vc<tuple<int, int, T>> res;\n    auto l = ss.prev(L);\n    while (l < R) {\n\
    \      auto t = dat[l];\n      auto r = ss.next(l + 1);\n      int l0 = max(l,\
    \ L);\n      int r0 = min(r, R);\n      if (l0 < r0) res.eb(l0, r0, t);\n    \
    \  l = r;\n    }\n    return res;\n  }\n\n  vc<tuple<int, int, T>> get_all() {\
    \ return get(LLIM, RLIM); }\n\n  void debug() {\n    print(\"Intervals\");\n \
    \   print(\"total_num\", total_num);\n    print(\"total_len\", total_len);\n \
    \   int l = 0;\n    while (l < RLIM) {\n      auto t = dat[l];\n      auto r =\
    \ ss.next(l + 1);\n      print(\"l, r, t\", l, r, t);\n      l = r;\n    }\n \
    \ }\n};\n"
  dependsOn:
  - ds/fastset.hpp
  isVerificationFile: false
  path: ds/intervals.hpp
  requiredBy: []
  timestamp: '2023-01-02 17:13:38+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/atcoder/abc256d.test.cpp
documentation_of: ds/intervals.hpp
layout: document
redirect_from:
- /library/ds/intervals.hpp
- /library/ds/intervals.hpp.html
title: ds/intervals.hpp
---
