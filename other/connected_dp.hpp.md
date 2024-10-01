---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: ds/hashmap.hpp
    title: ds/hashmap.hpp
  - icon: ':heavy_check_mark:'
    path: mod/modint61.hpp
    title: mod/modint61.hpp
  - icon: ':question:'
    path: random/base.hpp
    title: random/base.hpp
  - icon: ':heavy_check_mark:'
    path: random/hash_vector.hpp
    title: random/hash_vector.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/1_mytest/tdpc_grid_dp.test.cpp
    title: test/1_mytest/tdpc_grid_dp.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/3_yukicoder/1397.test.cpp
    title: test/3_yukicoder/1397.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/3_yukicoder/1561.test.cpp
    title: test/3_yukicoder/1561.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/3_yukicoder/541.test.cpp
    title: test/3_yukicoder/541.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/3_yukicoder/578.test.cpp
    title: test/3_yukicoder/578.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/3_yukicoder/579.test.cpp
    title: test/3_yukicoder/579.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links:
    - https://atcoder.jp/contests/ttpc2023/submissions/57905985
  bundledCode: "#line 2 \"ds/hashmap.hpp\"\n\r\n// u64 -> Val\r\ntemplate <typename\
    \ Val>\r\nstruct HashMap {\r\n  // n \u306F\u5165\u308C\u305F\u3044\u3082\u306E\
    \u306E\u500B\u6570\u3067 ok\r\n  HashMap(u32 n = 0) { build(n); }\r\n  void build(u32\
    \ n) {\r\n    u32 k = 8;\r\n    while (k < n * 2) k *= 2;\r\n    cap = k / 2,\
    \ mask = k - 1;\r\n    key.resize(k), val.resize(k), used.assign(k, 0);\r\n  }\r\
    \n\r\n  // size \u3092\u4FDD\u3063\u305F\u307E\u307E. size=0 \u306B\u3059\u308B\
    \u3068\u304D\u306F build \u3059\u308B\u3053\u3068.\r\n  void clear() {\r\n   \
    \ used.assign(len(used), 0);\r\n    cap = (mask + 1) / 2;\r\n  }\r\n  int size()\
    \ { return len(used) / 2 - cap; }\r\n\r\n  int index(const u64& k) {\r\n    int\
    \ i = 0;\r\n    for (i = hash(k); used[i] && key[i] != k; i = (i + 1) & mask)\
    \ {}\r\n    return i;\r\n  }\r\n\r\n  Val& operator[](const u64& k) {\r\n    if\
    \ (cap == 0) extend();\r\n    int i = index(k);\r\n    if (!used[i]) { used[i]\
    \ = 1, key[i] = k, val[i] = Val{}, --cap; }\r\n    return val[i];\r\n  }\r\n\r\
    \n  Val get(const u64& k, Val default_value) {\r\n    int i = index(k);\r\n  \
    \  return (used[i] ? val[i] : default_value);\r\n  }\r\n\r\n  bool count(const\
    \ u64& k) {\r\n    int i = index(k);\r\n    return used[i] && key[i] == k;\r\n\
    \  }\r\n\r\n  // f(key, val)\r\n  template <typename F>\r\n  void enumerate_all(F\
    \ f) {\r\n    FOR(i, len(used)) if (used[i]) f(key[i], val[i]);\r\n  }\r\n\r\n\
    private:\r\n  u32 cap, mask;\r\n  vc<u64> key;\r\n  vc<Val> val;\r\n  vc<bool>\
    \ used;\r\n\r\n  u64 hash(u64 x) {\r\n    static const u64 FIXED_RANDOM = std::chrono::steady_clock::now().time_since_epoch().count();\r\
    \n    x += FIXED_RANDOM;\r\n    x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;\r\n\
    \    x = (x ^ (x >> 27)) * 0x94d049bb133111eb;\r\n    return (x ^ (x >> 31)) &\
    \ mask;\r\n  }\r\n\r\n  void extend() {\r\n    vc<pair<u64, Val>> dat;\r\n   \
    \ dat.reserve(len(used) / 2 - cap);\r\n    FOR(i, len(used)) {\r\n      if (used[i])\
    \ dat.eb(key[i], val[i]);\r\n    }\r\n    build(2 * len(dat));\r\n    for (auto&\
    \ [a, b]: dat) (*this)[a] = b;\r\n  }\r\n};\n#line 2 \"random/hash_vector.hpp\"\
    \n\n#line 2 \"random/base.hpp\"\n\nu64 RNG_64() {\n  static uint64_t x_\n    \
    \  = uint64_t(chrono::duration_cast<chrono::nanoseconds>(chrono::high_resolution_clock::now().time_since_epoch()).count())\
    \ * 10150724397891781847ULL;\n  x_ ^= x_ << 7;\n  return x_ ^= x_ >> 9;\n}\n\n\
    u64 RNG(u64 lim) { return RNG_64() % lim; }\n\nll RNG(ll l, ll r) { return l +\
    \ RNG_64() % (r - l); }\n#line 2 \"mod/modint61.hpp\"\n\r\nstruct modint61 {\r\
    \n  static constexpr u64 mod = (1ULL << 61) - 1;\r\n  u64 val;\r\n  constexpr\
    \ modint61() : val(0ULL) {}\r\n  constexpr modint61(u32 x) : val(x) {}\r\n  constexpr\
    \ modint61(u64 x) : val(x % mod) {}\r\n  constexpr modint61(int x) : val((x <\
    \ 0) ? (x + static_cast<ll>(mod)) : x) {}\r\n  constexpr modint61(ll x) : val(((x\
    \ %= static_cast<ll>(mod)) < 0) ? (x + static_cast<ll>(mod)) : x) {}\r\n  static\
    \ constexpr u64 get_mod() { return mod; }\r\n\r\n  modint61 &operator+=(const\
    \ modint61 &a) {\r\n    val = ((val += a.val) >= mod) ? (val - mod) : val;\r\n\
    \    return *this;\r\n  }\r\n  modint61 &operator-=(const modint61 &a) {\r\n \
    \   val = ((val -= a.val) >= mod) ? (val + mod) : val;\r\n    return *this;\r\n\
    \  }\r\n  modint61 &operator*=(const modint61 &a) {\r\n    const unsigned __int128\
    \ y = static_cast<unsigned __int128>(val) * a.val;\r\n    val = (y >> 61) + (y\
    \ & mod);\r\n    val = (val >= mod) ? (val - mod) : val;\r\n    return *this;\r\
    \n  }\r\n  modint61 operator-() const { return modint61(val ? mod - val : u64(0));\
    \ }\r\n  modint61 &operator/=(const modint61 &a) { return (*this *= a.inverse());\
    \ }\r\n  modint61 operator+(const modint61 &p) const { return modint61(*this)\
    \ += p; }\r\n  modint61 operator-(const modint61 &p) const { return modint61(*this)\
    \ -= p; }\r\n  modint61 operator*(const modint61 &p) const { return modint61(*this)\
    \ *= p; }\r\n  modint61 operator/(const modint61 &p) const { return modint61(*this)\
    \ /= p; }\r\n  bool operator<(const modint61 &other) const { return val < other.val;\
    \ }\r\n  bool operator==(const modint61 &p) const { return val == p.val; }\r\n\
    \  bool operator!=(const modint61 &p) const { return val != p.val; }\r\n  modint61\
    \ inverse() const {\r\n    ll a = val, b = mod, u = 1, v = 0, t;\r\n    while\
    \ (b > 0) {\r\n      t = a / b;\r\n      swap(a -= t * b, b), swap(u -= t * v,\
    \ v);\r\n    }\r\n    return modint61(u);\r\n  }\r\n  modint61 pow(ll n) const\
    \ {\r\n    assert(n >= 0);\r\n    modint61 ret(1), mul(val);\r\n    while (n >\
    \ 0) {\r\n      if (n & 1) ret *= mul;\r\n      mul *= mul, n >>= 1;\r\n    }\r\
    \n    return ret;\r\n  }\r\n};\r\n\r\n#ifdef FASTIO\r\nvoid rd(modint61 &x) {\r\
    \n  fastio::rd(x.val);\r\n  assert(0 <= x.val && x.val < modint61::mod);\r\n}\r\
    \n\r\nvoid wt(modint61 x) { fastio::wt(x.val); }\r\n#endif\n#line 5 \"random/hash_vector.hpp\"\
    \n\ntemplate <typename T>\nu64 hash_vector(vc<T> X) {\n  using mint = modint61;\n\
    \  static vc<mint> hash_base;\n  int n = len(X);\n  while (len(hash_base) <= n)\
    \ { hash_base.eb(RNG(mint::get_mod())); }\n  mint H = 0;\n  FOR(i, n) H += hash_base[i]\
    \ * mint(X[i]);\n  H += hash_base[n];\n  return H.val;\n}\n#line 3 \"other/connected_dp.hpp\"\
    \n\n// dot case: https://atcoder.jp/contests/ttpc2023/submissions/57905985\n\n\
    namespace connected_dp_squares {\n// pair<\u65B0\u3057\u3044\u72B6\u614B\u3001\
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
    \    res.eb(vc<int>(par.begin(), par.begin() + N), vc<int>(par.begin() + N, par.end()));\n\
    \  }\n  return res;\n}\n\nvc<int> reverse_state(const vc<int>& now) {\n  int N\
    \ = len(now);\n  vc<int> max_i(N, -1);\n  FOR(i, N) if (now[i] != -1) max_i[now[i]]\
    \ = i;\n  vc<int> rev(N, -1);\n  FOR(i, N) {\n    if (now[i] == -1) continue;\n\
    \    int x = max_i[now[i]];\n    rev[N - 1 - i] = N - 1 - x;\n  }\n  return rev;\n\
    }\n\n// 0, 1 \uFF1A\u7A7A\u306E\u5217\u3001\u9818\u57DF\u306E\u624B\u524D\u3001\
    \u5F8C\u308D\n// \u9023\u7D50\u9818\u57DF\u3092\u3072\u3068\u3064\u4F5C\u308B\u3002\
    \n// \u72B6\u614B\uFF1A-1 \u304C\u9078\u3093\u3067\u3044\u306A\u3044\u30020,1,2,3\
    \ \u7B49\u306F\u540C\u3058\u6210\u5206\u306B\u306F\u540C\u3058\u5024\u304C\u5165\
    \u308B\u3002\n// [states, edges]\npair<vvc<int>, vc<pair<int, int>>> connedted_dp_graph(int\
    \ N, bool merge_reverse) {\n  HashMap<int> MP;\n  vvc<int> states;\n  vc<pair<int,\
    \ int>> edges;\n\n  states.eb(vc<int>(N, -1));\n  states.eb(vc<int>(N, -1));\n\
    \  MP[hash_vector<int>(states[0])] = 0;\n\n  int p = -1;\n  while (1) {\n    if\
    \ (++p == len(states)) break;\n    if (p == 1) {\n      edges.eb(1, 1);\n    \
    \  continue;\n    }\n    vc<int> now = states[p];\n    for (auto&& [nxt, convert]:\
    \ next_states(now)) {\n      // \u4ECA\u306E\u6210\u5206\u6570\u3001\u6D88\u3048\
    \u308B\u6210\u5206\u6570\n      int a = 0, b = 0;\n      FOR(v, N) if (now[v]\
    \ == v) {\n        ++a;\n        if (convert[v] == -1) ++b;\n      }\n      //\
    \ \u6D88\u3048\u308B\u6210\u5206\u304C\u3042\u3063\u3066\u3088\u3044\u306E\u306F\
    \u3001\u7D42\u72B6\u614B\u306B\u3044\u304F\u3068\u304D\u306E\u307F\n      if (b\
    \ >= 2) continue;\n      if (b == 1) {\n        if (MAX(nxt) != -1) continue;\n\
    \        edges.eb(p, 1);\n        continue;\n      }\n      u64 h = hash_vector<int>(nxt);\n\
    \      if (merge_reverse) { chmin(h, hash_vector<int>(reverse_state(nxt))); }\n\
    \      if (!MP.count(h)) { MP[h] = len(states), states.eb(nxt); }\n      edges.eb(p,\
    \ MP[h]);\n    }\n  }\n  return {states, edges};\n}\n\n// 0, 1 \uFF1A\u7A7A\u306E\
    \u5217\u3001\u9818\u57DF\u306E\u624B\u524D\u3001\u5F8C\u308D\n// \u591A\u89D2\u5F62\
    \uFF08\u7A7A\u6D1E\u306A\u3057\uFF09\u3092\u3072\u3068\u3064\u4F5C\u308B\u3002\
    \n// \u72B6\u614B\uFF1A-1 \u304C\u9078\u3093\u3067\u3044\u306A\u3044\u30020,1,2,3\
    \ \u7B49\u306F\u540C\u3058\u6210\u5206\u306B\u306F\u540C\u3058\u5024\u304C\u5165\
    \u308B\u3002\n// [states, edges]\npair<vvc<int>, vc<pair<int, int>>> polygon_dp_graph(int\
    \ N) {\n  HashMap<int> MP;\n  vvc<int> states;\n  vc<pair<int, int>> edges;\n\n\
    \  states.eb(vc<int>(N, -1));\n  states.eb(vc<int>(N, -1));\n  MP[hash_vector<int>(states[0])]\
    \ = 0;\n\n  int p = -1;\n  while (1) {\n    if (++p == len(states)) break;\n \
    \   if (p == 1) {\n      edges.eb(1, 1);\n      continue;\n    }\n    vc<int>\
    \ now = states[p];\n    for (auto&& [nxt, convert]: next_states(now)) {\n    \
    \  // \u4ECA\u306E\u6210\u5206\u6570\u3001\u6D88\u3048\u308B\u6210\u5206\u6570\
    \n      int a = 0, b = 0;\n      FOR(v, N) if (now[v] == v) {\n        ++a;\n\
    \        if (convert[v] == -1) ++b;\n      }\n      // \u6D88\u3048\u308B\u6210\
    \u5206\u304C\u3042\u3063\u3066\u3088\u3044\u306E\u306F\u3001\u7D42\u72B6\u614B\
    \u306B\u3044\u304F\u3068\u304D\u306E\u307F\n      if (b >= 2) continue;\n    \
    \  if (b == 1) {\n        if (MAX(nxt) != -1) continue;\n        edges.eb(p, 1);\n\
    \        continue;\n      }\n      bool ok = [&](vc<int>& now, vc<int>& nxt, vc<int>&\
    \ convert) -> bool {\n        // \u9802\u70B9\u306E\u307F\u3067\u63A5\u3059\u308B\
    \u306E\u306F\u30C0\u30E1\n        FOR(i, N - 1) {\n          bool a1 = now[i]\
    \ != -1, a2 = now[i + 1] != -1;\n          bool b1 = nxt[i] != -1, b2 = nxt[i\
    \ + 1] != -1;\n          if (a1 && !a2 && !b1 && b2) return false;\n         \
    \ if (!a1 && a2 && b1 && !b2) return false;\n        }\n        // empty region\
    \ \u3092\u9589\u3058\u308B\u3053\u3068\u3068\u3001\u7570\u306A\u308B\u9023\u7D50\
    \u6210\u5206\u304C\u30DE\u30FC\u30B8\u3055\u308C\u308B\u3053\u3068\u304C\u540C\
    \u5024\n        int close = 0;\n        int after = 0;\n        vc<bool> is_new(N,\
    \ 1);\n        FOR(i, N) if (convert[i] != -1) is_new[convert[i]] = 0;\n     \
    \   FOR(i, N) if (nxt[i] == i && !is_new[i])++ after;\n        vc<int> I;\n  \
    \      FOR(i, N) if (now[i] != -1) I.eb(i);\n        FOR(k, len(I) - 1) {\n  \
    \        int i = I[k], j = I[k + 1];\n          if (j == i + 1) continue;\n  \
    \        bool cl = 1;\n          FOR(p, i + 1, j) if (nxt[p] == -1) cl = 0;\n\
    \          if (cl) close++;\n        }\n        return a - close == after;\n \
    \     }(now, nxt, convert);\n      if (!ok) continue;\n      u64 h = hash_vector<int>(nxt);\n\
    \      if (!MP.count(h)) {\n        MP[h] = len(states);\n        states.eb(nxt);\n\
    \      }\n      edges.eb(p, MP[h]);\n    }\n  }\n  return {states, edges};\n}\n\
    } // namespace connected_dp_squares\n"
  code: "#include \"ds/hashmap.hpp\"\n#include \"random/hash_vector.hpp\"\n\n// dot\
    \ case: https://atcoder.jp/contests/ttpc2023/submissions/57905985\n\nnamespace\
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
    \    res.eb(vc<int>(par.begin(), par.begin() + N), vc<int>(par.begin() + N, par.end()));\n\
    \  }\n  return res;\n}\n\nvc<int> reverse_state(const vc<int>& now) {\n  int N\
    \ = len(now);\n  vc<int> max_i(N, -1);\n  FOR(i, N) if (now[i] != -1) max_i[now[i]]\
    \ = i;\n  vc<int> rev(N, -1);\n  FOR(i, N) {\n    if (now[i] == -1) continue;\n\
    \    int x = max_i[now[i]];\n    rev[N - 1 - i] = N - 1 - x;\n  }\n  return rev;\n\
    }\n\n// 0, 1 \uFF1A\u7A7A\u306E\u5217\u3001\u9818\u57DF\u306E\u624B\u524D\u3001\
    \u5F8C\u308D\n// \u9023\u7D50\u9818\u57DF\u3092\u3072\u3068\u3064\u4F5C\u308B\u3002\
    \n// \u72B6\u614B\uFF1A-1 \u304C\u9078\u3093\u3067\u3044\u306A\u3044\u30020,1,2,3\
    \ \u7B49\u306F\u540C\u3058\u6210\u5206\u306B\u306F\u540C\u3058\u5024\u304C\u5165\
    \u308B\u3002\n// [states, edges]\npair<vvc<int>, vc<pair<int, int>>> connedted_dp_graph(int\
    \ N, bool merge_reverse) {\n  HashMap<int> MP;\n  vvc<int> states;\n  vc<pair<int,\
    \ int>> edges;\n\n  states.eb(vc<int>(N, -1));\n  states.eb(vc<int>(N, -1));\n\
    \  MP[hash_vector<int>(states[0])] = 0;\n\n  int p = -1;\n  while (1) {\n    if\
    \ (++p == len(states)) break;\n    if (p == 1) {\n      edges.eb(1, 1);\n    \
    \  continue;\n    }\n    vc<int> now = states[p];\n    for (auto&& [nxt, convert]:\
    \ next_states(now)) {\n      // \u4ECA\u306E\u6210\u5206\u6570\u3001\u6D88\u3048\
    \u308B\u6210\u5206\u6570\n      int a = 0, b = 0;\n      FOR(v, N) if (now[v]\
    \ == v) {\n        ++a;\n        if (convert[v] == -1) ++b;\n      }\n      //\
    \ \u6D88\u3048\u308B\u6210\u5206\u304C\u3042\u3063\u3066\u3088\u3044\u306E\u306F\
    \u3001\u7D42\u72B6\u614B\u306B\u3044\u304F\u3068\u304D\u306E\u307F\n      if (b\
    \ >= 2) continue;\n      if (b == 1) {\n        if (MAX(nxt) != -1) continue;\n\
    \        edges.eb(p, 1);\n        continue;\n      }\n      u64 h = hash_vector<int>(nxt);\n\
    \      if (merge_reverse) { chmin(h, hash_vector<int>(reverse_state(nxt))); }\n\
    \      if (!MP.count(h)) { MP[h] = len(states), states.eb(nxt); }\n      edges.eb(p,\
    \ MP[h]);\n    }\n  }\n  return {states, edges};\n}\n\n// 0, 1 \uFF1A\u7A7A\u306E\
    \u5217\u3001\u9818\u57DF\u306E\u624B\u524D\u3001\u5F8C\u308D\n// \u591A\u89D2\u5F62\
    \uFF08\u7A7A\u6D1E\u306A\u3057\uFF09\u3092\u3072\u3068\u3064\u4F5C\u308B\u3002\
    \n// \u72B6\u614B\uFF1A-1 \u304C\u9078\u3093\u3067\u3044\u306A\u3044\u30020,1,2,3\
    \ \u7B49\u306F\u540C\u3058\u6210\u5206\u306B\u306F\u540C\u3058\u5024\u304C\u5165\
    \u308B\u3002\n// [states, edges]\npair<vvc<int>, vc<pair<int, int>>> polygon_dp_graph(int\
    \ N) {\n  HashMap<int> MP;\n  vvc<int> states;\n  vc<pair<int, int>> edges;\n\n\
    \  states.eb(vc<int>(N, -1));\n  states.eb(vc<int>(N, -1));\n  MP[hash_vector<int>(states[0])]\
    \ = 0;\n\n  int p = -1;\n  while (1) {\n    if (++p == len(states)) break;\n \
    \   if (p == 1) {\n      edges.eb(1, 1);\n      continue;\n    }\n    vc<int>\
    \ now = states[p];\n    for (auto&& [nxt, convert]: next_states(now)) {\n    \
    \  // \u4ECA\u306E\u6210\u5206\u6570\u3001\u6D88\u3048\u308B\u6210\u5206\u6570\
    \n      int a = 0, b = 0;\n      FOR(v, N) if (now[v] == v) {\n        ++a;\n\
    \        if (convert[v] == -1) ++b;\n      }\n      // \u6D88\u3048\u308B\u6210\
    \u5206\u304C\u3042\u3063\u3066\u3088\u3044\u306E\u306F\u3001\u7D42\u72B6\u614B\
    \u306B\u3044\u304F\u3068\u304D\u306E\u307F\n      if (b >= 2) continue;\n    \
    \  if (b == 1) {\n        if (MAX(nxt) != -1) continue;\n        edges.eb(p, 1);\n\
    \        continue;\n      }\n      bool ok = [&](vc<int>& now, vc<int>& nxt, vc<int>&\
    \ convert) -> bool {\n        // \u9802\u70B9\u306E\u307F\u3067\u63A5\u3059\u308B\
    \u306E\u306F\u30C0\u30E1\n        FOR(i, N - 1) {\n          bool a1 = now[i]\
    \ != -1, a2 = now[i + 1] != -1;\n          bool b1 = nxt[i] != -1, b2 = nxt[i\
    \ + 1] != -1;\n          if (a1 && !a2 && !b1 && b2) return false;\n         \
    \ if (!a1 && a2 && b1 && !b2) return false;\n        }\n        // empty region\
    \ \u3092\u9589\u3058\u308B\u3053\u3068\u3068\u3001\u7570\u306A\u308B\u9023\u7D50\
    \u6210\u5206\u304C\u30DE\u30FC\u30B8\u3055\u308C\u308B\u3053\u3068\u304C\u540C\
    \u5024\n        int close = 0;\n        int after = 0;\n        vc<bool> is_new(N,\
    \ 1);\n        FOR(i, N) if (convert[i] != -1) is_new[convert[i]] = 0;\n     \
    \   FOR(i, N) if (nxt[i] == i && !is_new[i])++ after;\n        vc<int> I;\n  \
    \      FOR(i, N) if (now[i] != -1) I.eb(i);\n        FOR(k, len(I) - 1) {\n  \
    \        int i = I[k], j = I[k + 1];\n          if (j == i + 1) continue;\n  \
    \        bool cl = 1;\n          FOR(p, i + 1, j) if (nxt[p] == -1) cl = 0;\n\
    \          if (cl) close++;\n        }\n        return a - close == after;\n \
    \     }(now, nxt, convert);\n      if (!ok) continue;\n      u64 h = hash_vector<int>(nxt);\n\
    \      if (!MP.count(h)) {\n        MP[h] = len(states);\n        states.eb(nxt);\n\
    \      }\n      edges.eb(p, MP[h]);\n    }\n  }\n  return {states, edges};\n}\n\
    } // namespace connected_dp_squares\n"
  dependsOn:
  - ds/hashmap.hpp
  - random/hash_vector.hpp
  - random/base.hpp
  - mod/modint61.hpp
  isVerificationFile: false
  path: other/connected_dp.hpp
  requiredBy: []
  timestamp: '2024-09-19 17:42:21+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/1_mytest/tdpc_grid_dp.test.cpp
  - test/3_yukicoder/541.test.cpp
  - test/3_yukicoder/578.test.cpp
  - test/3_yukicoder/1397.test.cpp
  - test/3_yukicoder/1561.test.cpp
  - test/3_yukicoder/579.test.cpp
documentation_of: other/connected_dp.hpp
layout: document
redirect_from:
- /library/other/connected_dp.hpp
- /library/other/connected_dp.hpp.html
title: other/connected_dp.hpp
---
