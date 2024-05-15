---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: alg/acted_set/from_monoid.hpp
    title: alg/acted_set/from_monoid.hpp
  - icon: ':question:'
    path: alg/monoid/mul.hpp
    title: alg/monoid/mul.hpp
  - icon: ':question:'
    path: ds/hashmap.hpp
    title: ds/hashmap.hpp
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: mod/mod_log.hpp
    title: mod/mod_log.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/library_checker/math/discrete_logarithm_mod.test.cpp
    title: test/library_checker/math/discrete_logarithm_mod.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/1339.test.cpp
    title: test/yukicoder/1339.test.cpp
  - icon: ':x:'
    path: test_atcoder/abc222g.test.cpp
    title: test_atcoder/abc222g.test.cpp
  - icon: ':x:'
    path: test_atcoder/abc270_g.test.cpp
    title: test_atcoder/abc270_g.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
  attributes:
    links: []
  bundledCode: "#line 2 \"alg/monoid/mul.hpp\"\n\r\ntemplate <class T>\r\nstruct Monoid_Mul\
    \ {\r\n  using value_type = T;\r\n  using X = T;\r\n  static constexpr X op(const\
    \ X &x, const X &y) noexcept { return x * y; }\r\n  static constexpr X inverse(const\
    \ X &x) noexcept { return X(1) / x; }\r\n  static constexpr X unit() { return\
    \ X(1); }\r\n  static constexpr bool commute = true;\r\n};\r\n#line 1 \"alg/acted_set/from_monoid.hpp\"\
    \ntemplate <typename Monoid>\nstruct ActedSet_From_Monoid {\n  using Monoid_A\
    \ = Monoid;\n  using A = typename Monoid::value_type;\n  using S = A;\n  static\
    \ S act(const S &x, const A &g) { return Monoid::op(x, g); }\n};\n#line 2 \"ds/hashmap.hpp\"\
    \n\r\n// u64 -> Val\r\ntemplate <typename Val>\r\nstruct HashMap {\r\n  // n \u306F\
    \u5165\u308C\u305F\u3044\u3082\u306E\u306E\u500B\u6570\u3067 ok\r\n  HashMap(u32\
    \ n = 0) { build(n); }\r\n  void build(u32 n) {\r\n    u32 k = 8;\r\n    while\
    \ (k < n * 2) k *= 2;\r\n    cap = k / 2, mask = k - 1;\r\n    key.resize(k),\
    \ val.resize(k), used.assign(k, 0);\r\n  }\r\n\r\n  // size \u3092\u4FDD\u3063\
    \u305F\u307E\u307E. size=0 \u306B\u3059\u308B\u3068\u304D\u306F build \u3059\u308B\
    \u3053\u3068.\r\n  void clear() { used.assign(len(used), 0); }\r\n  int size()\
    \ { return len(used) - cap; }\r\n\r\n  int index(const u64& k) {\r\n    int i\
    \ = 0;\r\n    for (i = hash(k); used[i] && key[i] != k; i = (i + 1) & mask) {}\r\
    \n    return i;\r\n  }\r\n\r\n  Val& operator[](const u64& k) {\r\n    if (cap\
    \ == 0) extend();\r\n    int i = index(k);\r\n    if (!used[i]) { used[i] = 1,\
    \ key[i] = k, val[i] = Val{}, --cap; }\r\n    return val[i];\r\n  }\r\n\r\n  Val\
    \ get(const u64& k, Val default_value) {\r\n    int i = index(k);\r\n    return\
    \ (used[i] ? val[i] : default_value);\r\n  }\r\n\r\n  bool count(const u64& k)\
    \ {\r\n    int i = index(k);\r\n    return used[i] && key[i] == k;\r\n  }\r\n\r\
    \n  // f(key, val)\r\n  template <typename F>\r\n  void enumerate_all(F f) {\r\
    \n    FOR(i, len(used)) if (used[i]) f(key[i], val[i]);\r\n  }\r\n\r\nprivate:\r\
    \n  u32 cap, mask;\r\n  vc<u64> key;\r\n  vc<Val> val;\r\n  vc<bool> used;\r\n\
    \r\n  u64 hash(u64 x) {\r\n    static const u64 FIXED_RANDOM\r\n        = std::chrono::steady_clock::now().time_since_epoch().count();\r\
    \n    x += FIXED_RANDOM;\r\n    x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;\r\n\
    \    x = (x ^ (x >> 27)) * 0x94d049bb133111eb;\r\n    return (x ^ (x >> 31)) &\
    \ mask;\r\n  }\r\n\r\n  void extend() {\r\n    vc<pair<u64, Val>> dat;\r\n   \
    \ dat.reserve(len(used) - cap);\r\n    FOR(i, len(used)) {\r\n      if (used[i])\
    \ dat.eb(key[i], val[i]);\r\n    }\r\n    build(2 * len(dat));\r\n    for (auto&\
    \ [a, b]: dat) (*this)[a] = b;\r\n  }\r\n};\n#line 4 \"nt/discrete_log.hpp\"\n\
    \r\n// \u30E2\u30CE\u30A4\u30C9 X \u306E\u4F5C\u7528\u3059\u308B\u96C6\u5408 S\u3001\
    \u30CF\u30C3\u30B7\u30E5\u95A2\u6570 H\uFF1AS -> Z\r\n// x in X, s, t in S \u306B\
    \u5BFE\u3057\u3066 x^ns = t \u3092\u89E3\u304F\r\n// [lb, ub) \u306E\u6700\u521D\
    \u306E\u89E3\u3092\u304B\u3048\u3059\u3002\u306A\u3051\u308C\u3070 -1 \u3092\u304B\
    \u3048\u3059\u3002\r\ntemplate <typename ActedSet, typename F>\r\nll discrete_log_acted(typename\
    \ ActedSet::A x, typename ActedSet::S s,\r\n                      typename ActedSet::S\
    \ t, F H, ll lb, ll ub) {\r\n  using Mono = typename ActedSet::Monoid_A;\r\n \
    \ using X = typename Mono::value_type;\r\n  using S = typename ActedSet::S;\r\n\
    \r\n  if (lb >= ub) return -1;\r\n  auto xpow = [&](ll n) -> X {\r\n    X p =\
    \ x;\r\n    X res = Mono::unit();\r\n    while (n) {\r\n      if (n & 1) res =\
    \ Mono::op(res, p);\r\n      p = Mono::op(p, p);\r\n      n /= 2;\r\n    }\r\n\
    \    return res;\r\n  };\r\n\r\n  auto Ht = H(t);\r\n  s = ActedSet::act(s, xpow(lb));\r\
    \n  u64 LIM = ub - lb;\r\n\r\n  ll K = sqrt(LIM) + 1;\r\n\r\n  HashMap<char> MP(K);\r\
    \n\r\n  FOR(k, K) {\r\n    t = ActedSet::act(t, x);\r\n    MP[H(t)] = 1;\r\n \
    \ }\r\n\r\n  X y = xpow(K);\r\n  int failed = 0;\r\n  FOR(k, K + 1) {\r\n    S\
    \ s1 = ActedSet::act(s, y);\r\n    if (MP.count(H(s1))) {\r\n      FOR(i, K) {\r\
    \n        if (H(s) == Ht) {\r\n          ll ans = k * K + i + lb;\r\n        \
    \  return (ans >= ub ? -1 : ans);\r\n        }\r\n        s = ActedSet::act(s,\
    \ x);\r\n      }\r\n      if (failed) return -1;\r\n      failed = 1;\r\n    }\r\
    \n    s = s1;\r\n  }\r\n  return -1;\r\n}\r\n\r\n// \u7FA4 X \u306B\u304A\u3051\
    \u308B log_a b \u306E\u8A08\u7B97\r\n// \u30CF\u30C3\u30B7\u30E5\u95A2\u6570 H\
    \ : X -> long long \u3092\u6301\u305F\u305B\u308B\r\n// [lb, ub) \u306E\u6700\u521D\
    \u306E\u89E3\u3092\u304B\u3048\u3059\u3001\u306A\u3051\u308C\u3070 -1\r\ntemplate\
    \ <typename Monoid, typename F>\r\nll discrete_log_monoid(typename Monoid::X a,\
    \ typename Monoid::X b, F H, ll lb,\r\n                       ll ub) {\r\n  using\
    \ AM = ActedSet_From_Monoid<Monoid>;\r\n  return discrete_log_acted<AM>(a, Monoid::unit(),\
    \ b, H, lb, ub);\r\n}\r\n"
  code: "#include \"alg/monoid/mul.hpp\"\r\n#include \"alg/acted_set/from_monoid.hpp\"\
    \r\n#include \"ds/hashmap.hpp\"\r\n\r\n// \u30E2\u30CE\u30A4\u30C9 X \u306E\u4F5C\
    \u7528\u3059\u308B\u96C6\u5408 S\u3001\u30CF\u30C3\u30B7\u30E5\u95A2\u6570 H\uFF1A\
    S -> Z\r\n// x in X, s, t in S \u306B\u5BFE\u3057\u3066 x^ns = t \u3092\u89E3\u304F\
    \r\n// [lb, ub) \u306E\u6700\u521D\u306E\u89E3\u3092\u304B\u3048\u3059\u3002\u306A\
    \u3051\u308C\u3070 -1 \u3092\u304B\u3048\u3059\u3002\r\ntemplate <typename ActedSet,\
    \ typename F>\r\nll discrete_log_acted(typename ActedSet::A x, typename ActedSet::S\
    \ s,\r\n                      typename ActedSet::S t, F H, ll lb, ll ub) {\r\n\
    \  using Mono = typename ActedSet::Monoid_A;\r\n  using X = typename Mono::value_type;\r\
    \n  using S = typename ActedSet::S;\r\n\r\n  if (lb >= ub) return -1;\r\n  auto\
    \ xpow = [&](ll n) -> X {\r\n    X p = x;\r\n    X res = Mono::unit();\r\n   \
    \ while (n) {\r\n      if (n & 1) res = Mono::op(res, p);\r\n      p = Mono::op(p,\
    \ p);\r\n      n /= 2;\r\n    }\r\n    return res;\r\n  };\r\n\r\n  auto Ht =\
    \ H(t);\r\n  s = ActedSet::act(s, xpow(lb));\r\n  u64 LIM = ub - lb;\r\n\r\n \
    \ ll K = sqrt(LIM) + 1;\r\n\r\n  HashMap<char> MP(K);\r\n\r\n  FOR(k, K) {\r\n\
    \    t = ActedSet::act(t, x);\r\n    MP[H(t)] = 1;\r\n  }\r\n\r\n  X y = xpow(K);\r\
    \n  int failed = 0;\r\n  FOR(k, K + 1) {\r\n    S s1 = ActedSet::act(s, y);\r\n\
    \    if (MP.count(H(s1))) {\r\n      FOR(i, K) {\r\n        if (H(s) == Ht) {\r\
    \n          ll ans = k * K + i + lb;\r\n          return (ans >= ub ? -1 : ans);\r\
    \n        }\r\n        s = ActedSet::act(s, x);\r\n      }\r\n      if (failed)\
    \ return -1;\r\n      failed = 1;\r\n    }\r\n    s = s1;\r\n  }\r\n  return -1;\r\
    \n}\r\n\r\n// \u7FA4 X \u306B\u304A\u3051\u308B log_a b \u306E\u8A08\u7B97\r\n\
    // \u30CF\u30C3\u30B7\u30E5\u95A2\u6570 H : X -> long long \u3092\u6301\u305F\u305B\
    \u308B\r\n// [lb, ub) \u306E\u6700\u521D\u306E\u89E3\u3092\u304B\u3048\u3059\u3001\
    \u306A\u3051\u308C\u3070 -1\r\ntemplate <typename Monoid, typename F>\r\nll discrete_log_monoid(typename\
    \ Monoid::X a, typename Monoid::X b, F H, ll lb,\r\n                       ll\
    \ ub) {\r\n  using AM = ActedSet_From_Monoid<Monoid>;\r\n  return discrete_log_acted<AM>(a,\
    \ Monoid::unit(), b, H, lb, ub);\r\n}\r\n"
  dependsOn:
  - alg/monoid/mul.hpp
  - alg/acted_set/from_monoid.hpp
  - ds/hashmap.hpp
  isVerificationFile: false
  path: nt/discrete_log.hpp
  requiredBy:
  - mod/mod_log.hpp
  timestamp: '2024-05-14 16:33:21+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - test/yukicoder/1339.test.cpp
  - test/library_checker/math/discrete_logarithm_mod.test.cpp
  - test_atcoder/abc222g.test.cpp
  - test_atcoder/abc270_g.test.cpp
documentation_of: nt/discrete_log.hpp
layout: document
redirect_from:
- /library/nt/discrete_log.hpp
- /library/nt/discrete_log.hpp.html
title: nt/discrete_log.hpp
---
