---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: ds/hashmap.hpp
    title: ds/hashmap.hpp
  - icon: ':x:'
    path: mod/modint61.hpp
    title: mod/modint61.hpp
  - icon: ':x:'
    path: random/base.hpp
    title: random/base.hpp
  - icon: ':x:'
    path: random/hash_vector.hpp
    title: random/hash_vector.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/mytest/tdpc_grid_dp.test.cpp
    title: test/mytest/tdpc_grid_dp.test.cpp
  - icon: ':x:'
    path: test/yukicoder/1397.test.cpp
    title: test/yukicoder/1397.test.cpp
  - icon: ':x:'
    path: test/yukicoder/1561.test.cpp
    title: test/yukicoder/1561.test.cpp
  - icon: ':x:'
    path: test/yukicoder/541.test.cpp
    title: test/yukicoder/541.test.cpp
  - icon: ':x:'
    path: test/yukicoder/578.test.cpp
    title: test/yukicoder/578.test.cpp
  - icon: ':x:'
    path: test/yukicoder/579.test.cpp
    title: test/yukicoder/579.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 2 \"ds/hashmap.hpp\"\ntemplate <typename Val, int LOG = 20>\r\
    \nstruct HashMapLL {\r\n  int N;\r\n  ll* keys;\r\n  Val* vals;\r\n  vc<int> IDS;\r\
    \n  bitset<1 << LOG> used;\r\n  const int shift;\r\n  const uint64_t r = 11995408973635179863ULL;\r\
    \n  HashMapLL()\r\n      : N(1 << LOG), keys(new ll[N]), vals(new Val[N]), shift(64\
    \ - __lg(N)) {}\r\n  int hash(ll x) {\r\n    static const uint64_t FIXED_RANDOM\r\
    \n        = std::chrono::steady_clock::now().time_since_epoch().count();\r\n \
    \   return (uint64_t(x + FIXED_RANDOM) * r) >> shift;\r\n  }\r\n\r\n  int index(const\
    \ ll& key) {\r\n    int i = 0;\r\n    for (i = hash(key); used[i] && keys[i] !=\
    \ key; (i += 1) &= (N - 1)) {}\r\n    return i;\r\n  }\r\n\r\n  Val& operator[](const\
    \ ll& key) {\r\n    int i = index(key);\r\n    if (!used[i]) IDS.eb(i), used[i]\
    \ = 1, keys[i] = key, vals[i] = Val{};\r\n    return vals[i];\r\n  }\r\n\r\n \
    \ Val get(const ll& key, Val default_value) {\r\n    int i = index(key);\r\n \
    \   if (!used[i]) return default_value;\r\n    return vals[i];\r\n  }\r\n\r\n\
    \  bool contain(const ll& key) {\r\n    int i = index(key);\r\n    return used[i]\
    \ && keys[i] == key;\r\n  }\r\n\r\n  bool count(const ll& key) {\r\n    int i\
    \ = index(key);\r\n    return used[i] && keys[i] == key;\r\n  }\r\n\r\n  void\
    \ reset() {\r\n    for (auto&& i: IDS) used[i] = 0;\r\n    IDS.clear();\r\n  }\r\
    \n\r\n  vc<pair<ll, Val>> items() {\r\n    vc<pair<ll, Val>> res;\r\n    res.reserve(len(IDS));\r\
    \n    for (auto&& i: IDS) res.eb(keys[i], vals[i]);\r\n    return res;\r\n  }\r\
    \n};\r\n\r\ntemplate <typename KEY, typename VAL, int LOG>\r\nstruct HashMap {\r\
    \n  HashMapLL<VAL, LOG> MP;\r\n  function<ll(KEY)> f;\r\n  HashMap(function<ll(KEY)>\
    \ f) : MP(), f(f) {}\r\n\r\n  int index(const KEY& key) { return MP.index(f(key));\
    \ }\r\n\r\n  VAL& operator[](const KEY& key) { return MP[f(key)]; }\r\n\r\n  bool\
    \ contain(const KEY& key) { return MP.contain(f(key)); }\r\n\r\n  bool count(const\
    \ KEY& key) { return MP.count(f(key)); }\r\n\r\n  void reset() { MP.reset(); }\r\
    \n};\r\n#line 2 \"random/hash_vector.hpp\"\n\n#line 2 \"random/base.hpp\"\n\n\
    u64 RNG_64() {\n  static uint64_t x_\n      = uint64_t(chrono::duration_cast<chrono::nanoseconds>(\n\
    \                     chrono::high_resolution_clock::now().time_since_epoch())\n\
    \                     .count())\n        * 10150724397891781847ULL;\n  x_ ^= x_\
    \ << 7;\n  return x_ ^= x_ >> 9;\n}\n\nu64 RNG(u64 lim) { return RNG_64() % lim;\
    \ }\n\nll RNG(ll l, ll r) { return l + RNG_64() % (r - l); }\n#line 2 \"mod/modint61.hpp\"\
    \nstruct modint61 {\r\n  static constexpr bool is_modint = true;\r\n  static constexpr\
    \ ll mod = (1LL << 61) - 1;\r\n  ll val;\r\n  constexpr modint61(const ll x =\
    \ 0) : val(x) {\r\n    while(val < 0) val += mod;\r\n    while(val >= mod) val\
    \ -= mod;\r\n  }\r\n  bool operator<(const modint61 &other) const {\r\n    return\
    \ val < other.val;\r\n  } // To use std::map\r\n  bool operator==(const modint61\
    \ &p) const { return val == p.val; }\r\n  bool operator!=(const modint61 &p) const\
    \ { return val != p.val; }\r\n  modint61 &operator+=(const modint61 &p) {\r\n\
    \    if ((val += p.val) >= mod) val -= mod;\r\n    return *this;\r\n  }\r\n  modint61\
    \ &operator-=(const modint61 &p) {\r\n    if ((val += mod - p.val) >= mod) val\
    \ -= mod;\r\n    return *this;\r\n  }\r\n  modint61 &operator*=(const modint61\
    \ &p) {\r\n    ll a = val, b = p.val;\r\n    const ll MASK30 = (1LL << 30) - 1;\r\
    \n    const ll MASK31 = (1LL << 31) - 1;\r\n    const ll MASK61 = (1LL << 61)\
    \ - 1;\r\n    ll au = a >> 31, ad = a & MASK31;\r\n    ll bu = b >> 31, bd = b\
    \ & MASK31;\r\n    ll x = ad * bu + au * bd;\r\n    ll xu = x >> 30, xd = x &\
    \ MASK30;\r\n    x = au * bu * 2 + xu + (xd << 31) + ad * bd;\r\n    xu = x >>\
    \ 61, xd = x & MASK61;\r\n    x = xu + xd;\r\n    if (x >= MASK61) x -= MASK61;\r\
    \n    val = x;\r\n    return *this;\r\n  }\r\n  modint61 operator-() const { return\
    \ modint61(get_mod() - val); }\r\n  modint61 &operator/=(const modint61 &p) {\r\
    \n    *this *= p.inverse();\r\n    return *this;\r\n  }\r\n  modint61 operator+(const\
    \ modint61 &p) const { return modint61(*this) += p; }\r\n  modint61 operator-(const\
    \ modint61 &p) const { return modint61(*this) -= p; }\r\n  modint61 operator*(const\
    \ modint61 &p) const { return modint61(*this) *= p; }\r\n  modint61 operator/(const\
    \ modint61 &p) const { return modint61(*this) /= p; }\r\n\r\n  modint61 inverse()\
    \ const {\r\n    ll a = val, b = mod, u = 1, v = 0, t;\r\n    while (b > 0) {\r\
    \n      t = a / b;\r\n      swap(a -= t * b, b), swap(u -= t * v, v);\r\n    }\r\
    \n    return modint61(u);\r\n  }\r\n  modint61 pow(int64_t n) const {\r\n    modint61\
    \ ret(1), mul(val);\r\n    while (n > 0) {\r\n      if (n & 1) ret = ret * mul;\r\
    \n      mul = mul * mul;\r\n      n >>= 1;\r\n    }\r\n    return ret;\r\n  }\r\
    \n  static constexpr ll get_mod() { return mod; }\r\n};\r\n#line 5 \"random/hash_vector.hpp\"\
    \n\ntemplate <typename T>\nll hash_vector(vc<T> X) {\n  using mint = modint61;\n\
    \  static vc<mint> hash_base;\n  int n = len(X);\n  while (len(hash_base) <= n)\
    \ { hash_base.eb(RNG(mint::get_mod())); }\n  mint H = 0;\n  FOR(i, n) H += hash_base[i]\
    \ * mint(X[i]);\n  H += hash_base[n];\n  return H.val;\n}\n#line 3 \"connected_dp/squares.hpp\"\
    \n\nnamespace connected_dp_squares {\n// pair<\u65B0\u3057\u3044\u72B6\u614B\u3001\
    \u4ECA\u306E\u6210\u5206 \u2192 \u65B0\u3057\u3044\u6210\u5206>\nvc<pair<vc<int>,\
    \ vc<int>>> next_states(const vc<int>& now) {\n  int N = len(now);\n  vc<pair<vc<int>,\
    \ vc<int>>> res;\n  FOR(s, 1 << N) {\n    vc<int> par(N + N);\n    FOR(i, N) par[i]\
    \ = (s & 1 << i ? i : -1);\n    FOR(i, N) par[N + i] = (now[i] == -1 ? -1 : now[i]\
    \ + N);\n    auto find = [&](int x) -> int {\n      while (par[x] != x) { x =\
    \ par[x] = par[par[x]]; }\n      return x;\n    };\n    auto merge = [&](int a,\
    \ int b) -> void {\n      a = find(a), b = find(b);\n      if (a == b) return;\n\
    \      if (a > b) swap(a, b);\n      par[b] = a;\n    };\n\n    FOR(i, N - 1)\
    \ if (par[i] != -1 && par[i + 1] != -1) merge(i, i + 1);\n    FOR(i, N) if (par[i]\
    \ != -1 && par[N + i] != -1) merge(i, N + i);\n    FOR(i, N + N) if (par[i] !=\
    \ -1) par[i] = find(i);\n    FOR(i, N, N + N) if (par[i] >= N) par[i] = -1;\n\
    \    res.eb(vc<int>(par.begin(), par.begin() + N),\n           vc<int>(par.begin()\
    \ + N, par.end()));\n  }\n  return res;\n}\n\nvc<int> reverse_state(const vc<int>&\
    \ now) {\n  int N = len(now);\n  vc<int> max_i(N, -1);\n  FOR(i, N) if (now[i]\
    \ != -1) max_i[now[i]] = i;\n  vc<int> rev(N, -1);\n  FOR(i, N) {\n    if (now[i]\
    \ == -1) continue;\n    int x = max_i[now[i]];\n    rev[N - 1 - i] = N - 1 - x;\n\
    \  }\n  return rev;\n}\n\n// 0, 1 \uFF1A\u7A7A\u306E\u5217\u3001\u9818\u57DF\u306E\
    \u624B\u524D\u3001\u5F8C\u308D\n// \u9023\u7D50\u9818\u57DF\u3092\u3072\u3068\u3064\
    \u4F5C\u308B\u3002\u591A\u89D2\u5F62\u3068\u306F\u9650\u3089\u306A\u3044\u3002\
    \npair<vvc<int>, vc<pair<int, int>>> connedted_dp_graph(int N,\n             \
    \                                         bool merge_reverse) {\n  static HashMapLL<int>\
    \ MP;\n  MP.reset();\n  vvc<int> states;\n  vc<pair<int, int>> edges;\n\n  states.eb(vc<int>(N,\
    \ -1));\n  states.eb(vc<int>(N, -1));\n  MP[hash_vector<int>(states[0])] = 0;\n\
    \n  int p = -1;\n  while (1) {\n    if (++p == len(states)) break;\n    if (p\
    \ == 1) {\n      edges.eb(1, 1);\n      continue;\n    }\n    vc<int> now = states[p];\n\
    \    for (auto&& [nxt, convert]: next_states(now)) {\n      // \u4ECA\u306E\u6210\
    \u5206\u6570\u3001\u6D88\u3048\u308B\u6210\u5206\u6570\n      int a = 0, b = 0;\n\
    \      FOR(v, N) if (now[v] == v) {\n        ++a;\n        if (convert[v] == -1)\
    \ ++b;\n      }\n      // \u6D88\u3048\u308B\u6210\u5206\u304C\u3042\u3063\u3066\
    \u3088\u3044\u306E\u306F\u3001\u7D42\u72B6\u614B\u306B\u3044\u304F\u3068\u304D\
    \u306E\u307F\n      if (b >= 2) continue;\n      if (b == 1) {\n        if (MAX(nxt)\
    \ != -1) continue;\n        edges.eb(p, 1);\n        continue;\n      }\n    \
    \  ll h = hash_vector<int>(nxt);\n      if (merge_reverse) { chmin(h, hash_vector<int>(reverse_state(nxt)));\
    \ }\n      if (!MP.count(h)) {\n        MP[h] = len(states);\n        states.eb(nxt);\n\
    \      }\n      edges.eb(p, MP[h]);\n    }\n  }\n  return {states, edges};\n}\n\
    \npair<vvc<int>, vc<pair<int, int>>> polygon_dp_graph(int N) {\n  static HashMapLL<int>\
    \ MP;\n  MP.reset();\n  vvc<int> states;\n  vc<pair<int, int>> edges;\n\n  states.eb(vc<int>(N,\
    \ -1));\n  states.eb(vc<int>(N, -1));\n  MP[hash_vector<int>(states[0])] = 0;\n\
    \n  int p = -1;\n  while (1) {\n    if (++p == len(states)) break;\n    if (p\
    \ == 1) {\n      edges.eb(1, 1);\n      continue;\n    }\n    vc<int> now = states[p];\n\
    \    for (auto&& [nxt, convert]: next_states(now)) {\n      // \u4ECA\u306E\u6210\
    \u5206\u6570\u3001\u6D88\u3048\u308B\u6210\u5206\u6570\n      int a = 0, b = 0;\n\
    \      FOR(v, N) if (now[v] == v) {\n        ++a;\n        if (convert[v] == -1)\
    \ ++b;\n      }\n      // \u6D88\u3048\u308B\u6210\u5206\u304C\u3042\u3063\u3066\
    \u3088\u3044\u306E\u306F\u3001\u7D42\u72B6\u614B\u306B\u3044\u304F\u3068\u304D\
    \u306E\u307F\n      if (b >= 2) continue;\n      if (b == 1) {\n        if (MAX(nxt)\
    \ != -1) continue;\n        edges.eb(p, 1);\n        continue;\n      }\n    \
    \  bool ok = [&](vc<int>& now, vc<int>& nxt, vc<int>& convert) -> bool {\n   \
    \     // \u9802\u70B9\u306E\u307F\u3067\u63A5\u3059\u308B\u306E\u306F\u30C0\u30E1\
    \n        FOR(i, N - 1) {\n          bool a1 = now[i] != -1, a2 = now[i + 1] !=\
    \ -1;\n          bool b1 = nxt[i] != -1, b2 = nxt[i + 1] != -1;\n          if\
    \ (a1 && !a2 && !b1 && b2) return false;\n          if (!a1 && a2 && b1 && !b2)\
    \ return false;\n        }\n        // empty region \u3092\u9589\u3058\u308B\u3053\
    \u3068\u3068\u3001\u7570\u306A\u308B\u9023\u7D50\u6210\u5206\u304C\u30DE\u30FC\
    \u30B8\u3055\u308C\u308B\u3053\u3068\u304C\u540C\u5024\n        int close = 0;\n\
    \        int after = 0;\n        vc<bool> is_new(N, 1);\n        FOR(i, N) if\
    \ (convert[i] != -1) is_new[convert[i]] = 0;\n        FOR(i, N) if (nxt[i] ==\
    \ i && !is_new[i])++ after;\n        vc<int> I;\n        FOR(i, N) if (now[i]\
    \ != -1) I.eb(i);\n        FOR(k, len(I) - 1) {\n          int i = I[k], j = I[k\
    \ + 1];\n          if (j == i + 1) continue;\n          bool cl = 1;\n       \
    \   FOR(p, i + 1, j) if (nxt[p] == -1) cl = 0;\n          if (cl) close++;\n \
    \       }\n        return a - close == after;\n      }(now, nxt, convert);\n \
    \     if (!ok) continue;\n      ll h = hash_vector<int>(nxt);\n      if (!MP.count(h))\
    \ {\n        MP[h] = len(states);\n        states.eb(nxt);\n      }\n      edges.eb(p,\
    \ MP[h]);\n    }\n  }\n  return {states, edges};\n}\n\n} // namespace connected_dp_squares\n"
  code: "#include \"ds/hashmap.hpp\"\n#include \"random/hash_vector.hpp\"\n\nnamespace\
    \ connected_dp_squares {\n// pair<\u65B0\u3057\u3044\u72B6\u614B\u3001\u4ECA\u306E\
    \u6210\u5206 \u2192 \u65B0\u3057\u3044\u6210\u5206>\nvc<pair<vc<int>, vc<int>>>\
    \ next_states(const vc<int>& now) {\n  int N = len(now);\n  vc<pair<vc<int>, vc<int>>>\
    \ res;\n  FOR(s, 1 << N) {\n    vc<int> par(N + N);\n    FOR(i, N) par[i] = (s\
    \ & 1 << i ? i : -1);\n    FOR(i, N) par[N + i] = (now[i] == -1 ? -1 : now[i]\
    \ + N);\n    auto find = [&](int x) -> int {\n      while (par[x] != x) { x =\
    \ par[x] = par[par[x]]; }\n      return x;\n    };\n    auto merge = [&](int a,\
    \ int b) -> void {\n      a = find(a), b = find(b);\n      if (a == b) return;\n\
    \      if (a > b) swap(a, b);\n      par[b] = a;\n    };\n\n    FOR(i, N - 1)\
    \ if (par[i] != -1 && par[i + 1] != -1) merge(i, i + 1);\n    FOR(i, N) if (par[i]\
    \ != -1 && par[N + i] != -1) merge(i, N + i);\n    FOR(i, N + N) if (par[i] !=\
    \ -1) par[i] = find(i);\n    FOR(i, N, N + N) if (par[i] >= N) par[i] = -1;\n\
    \    res.eb(vc<int>(par.begin(), par.begin() + N),\n           vc<int>(par.begin()\
    \ + N, par.end()));\n  }\n  return res;\n}\n\nvc<int> reverse_state(const vc<int>&\
    \ now) {\n  int N = len(now);\n  vc<int> max_i(N, -1);\n  FOR(i, N) if (now[i]\
    \ != -1) max_i[now[i]] = i;\n  vc<int> rev(N, -1);\n  FOR(i, N) {\n    if (now[i]\
    \ == -1) continue;\n    int x = max_i[now[i]];\n    rev[N - 1 - i] = N - 1 - x;\n\
    \  }\n  return rev;\n}\n\n// 0, 1 \uFF1A\u7A7A\u306E\u5217\u3001\u9818\u57DF\u306E\
    \u624B\u524D\u3001\u5F8C\u308D\n// \u9023\u7D50\u9818\u57DF\u3092\u3072\u3068\u3064\
    \u4F5C\u308B\u3002\u591A\u89D2\u5F62\u3068\u306F\u9650\u3089\u306A\u3044\u3002\
    \npair<vvc<int>, vc<pair<int, int>>> connedted_dp_graph(int N,\n             \
    \                                         bool merge_reverse) {\n  static HashMapLL<int>\
    \ MP;\n  MP.reset();\n  vvc<int> states;\n  vc<pair<int, int>> edges;\n\n  states.eb(vc<int>(N,\
    \ -1));\n  states.eb(vc<int>(N, -1));\n  MP[hash_vector<int>(states[0])] = 0;\n\
    \n  int p = -1;\n  while (1) {\n    if (++p == len(states)) break;\n    if (p\
    \ == 1) {\n      edges.eb(1, 1);\n      continue;\n    }\n    vc<int> now = states[p];\n\
    \    for (auto&& [nxt, convert]: next_states(now)) {\n      // \u4ECA\u306E\u6210\
    \u5206\u6570\u3001\u6D88\u3048\u308B\u6210\u5206\u6570\n      int a = 0, b = 0;\n\
    \      FOR(v, N) if (now[v] == v) {\n        ++a;\n        if (convert[v] == -1)\
    \ ++b;\n      }\n      // \u6D88\u3048\u308B\u6210\u5206\u304C\u3042\u3063\u3066\
    \u3088\u3044\u306E\u306F\u3001\u7D42\u72B6\u614B\u306B\u3044\u304F\u3068\u304D\
    \u306E\u307F\n      if (b >= 2) continue;\n      if (b == 1) {\n        if (MAX(nxt)\
    \ != -1) continue;\n        edges.eb(p, 1);\n        continue;\n      }\n    \
    \  ll h = hash_vector<int>(nxt);\n      if (merge_reverse) { chmin(h, hash_vector<int>(reverse_state(nxt)));\
    \ }\n      if (!MP.count(h)) {\n        MP[h] = len(states);\n        states.eb(nxt);\n\
    \      }\n      edges.eb(p, MP[h]);\n    }\n  }\n  return {states, edges};\n}\n\
    \npair<vvc<int>, vc<pair<int, int>>> polygon_dp_graph(int N) {\n  static HashMapLL<int>\
    \ MP;\n  MP.reset();\n  vvc<int> states;\n  vc<pair<int, int>> edges;\n\n  states.eb(vc<int>(N,\
    \ -1));\n  states.eb(vc<int>(N, -1));\n  MP[hash_vector<int>(states[0])] = 0;\n\
    \n  int p = -1;\n  while (1) {\n    if (++p == len(states)) break;\n    if (p\
    \ == 1) {\n      edges.eb(1, 1);\n      continue;\n    }\n    vc<int> now = states[p];\n\
    \    for (auto&& [nxt, convert]: next_states(now)) {\n      // \u4ECA\u306E\u6210\
    \u5206\u6570\u3001\u6D88\u3048\u308B\u6210\u5206\u6570\n      int a = 0, b = 0;\n\
    \      FOR(v, N) if (now[v] == v) {\n        ++a;\n        if (convert[v] == -1)\
    \ ++b;\n      }\n      // \u6D88\u3048\u308B\u6210\u5206\u304C\u3042\u3063\u3066\
    \u3088\u3044\u306E\u306F\u3001\u7D42\u72B6\u614B\u306B\u3044\u304F\u3068\u304D\
    \u306E\u307F\n      if (b >= 2) continue;\n      if (b == 1) {\n        if (MAX(nxt)\
    \ != -1) continue;\n        edges.eb(p, 1);\n        continue;\n      }\n    \
    \  bool ok = [&](vc<int>& now, vc<int>& nxt, vc<int>& convert) -> bool {\n   \
    \     // \u9802\u70B9\u306E\u307F\u3067\u63A5\u3059\u308B\u306E\u306F\u30C0\u30E1\
    \n        FOR(i, N - 1) {\n          bool a1 = now[i] != -1, a2 = now[i + 1] !=\
    \ -1;\n          bool b1 = nxt[i] != -1, b2 = nxt[i + 1] != -1;\n          if\
    \ (a1 && !a2 && !b1 && b2) return false;\n          if (!a1 && a2 && b1 && !b2)\
    \ return false;\n        }\n        // empty region \u3092\u9589\u3058\u308B\u3053\
    \u3068\u3068\u3001\u7570\u306A\u308B\u9023\u7D50\u6210\u5206\u304C\u30DE\u30FC\
    \u30B8\u3055\u308C\u308B\u3053\u3068\u304C\u540C\u5024\n        int close = 0;\n\
    \        int after = 0;\n        vc<bool> is_new(N, 1);\n        FOR(i, N) if\
    \ (convert[i] != -1) is_new[convert[i]] = 0;\n        FOR(i, N) if (nxt[i] ==\
    \ i && !is_new[i])++ after;\n        vc<int> I;\n        FOR(i, N) if (now[i]\
    \ != -1) I.eb(i);\n        FOR(k, len(I) - 1) {\n          int i = I[k], j = I[k\
    \ + 1];\n          if (j == i + 1) continue;\n          bool cl = 1;\n       \
    \   FOR(p, i + 1, j) if (nxt[p] == -1) cl = 0;\n          if (cl) close++;\n \
    \       }\n        return a - close == after;\n      }(now, nxt, convert);\n \
    \     if (!ok) continue;\n      ll h = hash_vector<int>(nxt);\n      if (!MP.count(h))\
    \ {\n        MP[h] = len(states);\n        states.eb(nxt);\n      }\n      edges.eb(p,\
    \ MP[h]);\n    }\n  }\n  return {states, edges};\n}\n\n} // namespace connected_dp_squares"
  dependsOn:
  - ds/hashmap.hpp
  - random/hash_vector.hpp
  - random/base.hpp
  - mod/modint61.hpp
  isVerificationFile: false
  path: connected_dp/squares.hpp
  requiredBy: []
  timestamp: '2022-10-26 12:54:16+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/yukicoder/541.test.cpp
  - test/yukicoder/1561.test.cpp
  - test/yukicoder/578.test.cpp
  - test/yukicoder/579.test.cpp
  - test/yukicoder/1397.test.cpp
  - test/mytest/tdpc_grid_dp.test.cpp
documentation_of: connected_dp/squares.hpp
layout: document
redirect_from:
- /library/connected_dp/squares.hpp
- /library/connected_dp/squares.hpp.html
title: connected_dp/squares.hpp
---
