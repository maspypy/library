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
    path: test/2_library_checker/number_theory/discrete_logarithm_mod.test.cpp
    title: test/2_library_checker/number_theory/discrete_logarithm_mod.test.cpp
  - icon: ':x:'
    path: test/3_yukicoder/1339.test.cpp
    title: test/3_yukicoder/1339.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
  attributes:
    links:
    - https://github.com/maspypy/library/blob/main/nt/discrete_log.hpp
  bundledCode: "#line 1 \"nt/discrete_log.hpp\"\n// Source: https://github.com/maspypy/library/blob/main/nt/discrete_log.hpp\n\
    #line 1 \"alg/monoid/mul.hpp\"\n// Source: https://github.com/maspypy/library/blob/main/alg/monoid/mul.hpp\n\
    \ntemplate <class T>\nstruct Monoid_Mul {\n  using value_type = T;\n  using X\
    \ = T;\n  static constexpr X op(const X &x, const X &y) noexcept { return x *\
    \ y; }\n  static constexpr X inverse(const X &x) noexcept { return X(1) / x; }\n\
    \  static constexpr X id() { return X(1); }\n  static constexpr bool commute =\
    \ true;\n};\n#line 1 \"alg/acted_set/from_monoid.hpp\"\n// Source: https://github.com/maspypy/library/blob/main/alg/acted_set/from_monoid.hpp\n\
    template <typename Monoid>\nstruct ActedSet_from_Monoid {\n  using Monoid_A =\
    \ Monoid;\n  using A = typename Monoid::value_type;\n  using S = A;\n  static\
    \ S act(const S &x, const A &g) { return Monoid::op(x, g); }\n};\n#line 1 \"ds/hashmap.hpp\"\
    \n// Source: https://github.com/maspypy/library/blob/main/ds/hashmap.hpp\n\n//\
    \ u64 -> Val\ntemplate <typename Val>\nstruct HashMap {\n  // n \u306F\u5165\u308C\
    \u305F\u3044\u3082\u306E\u306E\u500B\u6570\u3067 ok\n  HashMap(u32 n = 0) { build(n);\
    \ }\n  void build(u32 n) {\n    u32 k = 8;\n    while (k < n * 2) k *= 2;\n  \
    \  cap = k / 2, mask = k - 1;\n    key.resize(k), val.resize(k), used.assign(k,\
    \ 0);\n  }\n\n  // size \u3092\u4FDD\u3063\u305F\u307E\u307E. size=0 \u306B\u3059\
    \u308B\u3068\u304D\u306F build \u3059\u308B\u3053\u3068.\n  void clear() {\n \
    \   used.assign(len(used), 0);\n    cap = (mask + 1) / 2;\n  }\n  int size() {\
    \ return len(used) / 2 - cap; }\n\n  int index(const u64& k) {\n    int i = 0;\n\
    \    for (i = hash(k); used[i] && key[i] != k; i = (i + 1) & mask) {\n    }\n\
    \    return i;\n  }\n\n  Val& operator[](const u64& k) {\n    int i = index(k);\n\
    \    if (used[i]) return val[i];\n    if (cap == 0) extend(), i = index(k);\n\
    \    used[i] = 1, key[i] = k, val[i] = Val{}, --cap;\n    return val[i];\n  }\n\
    \n  Val get(const u64& k, Val default_value) {\n    int i = index(k);\n    return\
    \ (used[i] ? val[i] : default_value);\n  }\n\n  bool count(const u64& k) {\n \
    \   int i = index(k);\n    return used[i] && key[i] == k;\n  }\n\n  // f(key,\
    \ val)\n  template <typename F>\n  void enumerate_all(F f) {\n    FOR(i, len(used))\
    \ if (used[i]) f(key[i], val[i]);\n  }\n\n private:\n  u32 cap, mask;\n  vc<u64>\
    \ key;\n  vc<Val> val;\n  vc<bool> used;\n\n  u64 hash(u64 x) {\n    static const\
    \ u64 FIXED_RANDOM =\n        std::chrono::steady_clock::now().time_since_epoch().count();\n\
    \    x += FIXED_RANDOM;\n    x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;\n    x\
    \ = (x ^ (x >> 27)) * 0x94d049bb133111eb;\n    return (x ^ (x >> 31)) & mask;\n\
    \  }\n\n  void extend() {\n    vc<pair<u64, Val>> dat;\n    dat.reserve(len(used)\
    \ / 2 - cap);\n    FOR(i, len(used)) {\n      if (used[i]) dat.eb(key[i], val[i]);\n\
    \    }\n    build(2 * len(dat));\n    for (auto& [a, b] : dat) (*this)[a] = b;\n\
    \  }\n};\n#line 5 \"nt/discrete_log.hpp\"\n\n// \u30E2\u30CE\u30A4\u30C9 X \u306E\
    \u4F5C\u7528\u3059\u308B\u96C6\u5408 S\u3001\u30CF\u30C3\u30B7\u30E5\u95A2\u6570\
    \ H\uFF1AS -> Z\n// x in X, s, t in S \u306B\u5BFE\u3057\u3066 x^ns = t \u3092\
    \u89E3\u304F\n// [lb, ub) \u306E\u6700\u521D\u306E\u89E3\u3092\u304B\u3048\u3059\
    \u3002\u306A\u3051\u308C\u3070 -1 \u3092\u304B\u3048\u3059\u3002\ntemplate <typename\
    \ ActedSet, typename F>\nll discrete_log_acted(typename ActedSet::A x, typename\
    \ ActedSet::S s,\n                      typename ActedSet::S t, F H, ll lb, ll\
    \ ub) {\n  using Mono = typename ActedSet::Monoid_A;\n  using X = typename Mono::value_type;\n\
    \  using S = typename ActedSet::S;\n\n  if (lb >= ub) return -1;\n  auto xpow\
    \ = [&](ll n) -> X {\n    X p = x;\n    X res = Mono::id();\n    while (n) {\n\
    \      if (n & 1) res = Mono::op(res, p);\n      p = Mono::op(p, p);\n      n\
    \ /= 2;\n    }\n    return res;\n  };\n\n  auto Ht = H(t);\n  s = ActedSet::act(s,\
    \ xpow(lb));\n  u64 LIM = ub - lb;\n\n  ll K = sqrt(LIM) + 1;\n\n  HashMap<char>\
    \ MP(K);\n\n  FOR(k, K) {\n    t = ActedSet::act(t, x);\n    MP[H(t)] = 1;\n \
    \ }\n\n  X y = xpow(K);\n  int failed = 0;\n  FOR(k, K + 1) {\n    S s1 = ActedSet::act(s,\
    \ y);\n    if (MP.count(H(s1))) {\n      FOR(i, K) {\n        if (H(s) == Ht)\
    \ {\n          ll ans = k * K + i + lb;\n          return (ans >= ub ? -1 : ans);\n\
    \        }\n        s = ActedSet::act(s, x);\n      }\n      if (failed) return\
    \ -1;\n      failed = 1;\n    }\n    s = s1;\n  }\n  return -1;\n}\n\n// \u7FA4\
    \ X \u306B\u304A\u3051\u308B log_a b \u306E\u8A08\u7B97\n// \u30CF\u30C3\u30B7\
    \u30E5\u95A2\u6570 H : X -> long long \u3092\u6301\u305F\u305B\u308B\n// [lb,\
    \ ub) \u306E\u6700\u521D\u306E\u89E3\u3092\u304B\u3048\u3059\u3001\u306A\u3051\
    \u308C\u3070 -1\ntemplate <typename Monoid, typename F>\nll discrete_log_monoid(typename\
    \ Monoid::X a, typename Monoid::X b, F H, ll lb,\n                       ll ub)\
    \ {\n  using AM = ActedSet_from_Monoid<Monoid>;\n  return discrete_log_acted<AM>(a,\
    \ Monoid::id(), b, H, lb, ub);\n}\n"
  code: "// Source: https://github.com/maspypy/library/blob/main/nt/discrete_log.hpp\n\
    #include \"alg/monoid/mul.hpp\"\n#include \"alg/acted_set/from_monoid.hpp\"\n\
    #include \"ds/hashmap.hpp\"\n\n// \u30E2\u30CE\u30A4\u30C9 X \u306E\u4F5C\u7528\
    \u3059\u308B\u96C6\u5408 S\u3001\u30CF\u30C3\u30B7\u30E5\u95A2\u6570 H\uFF1AS\
    \ -> Z\n// x in X, s, t in S \u306B\u5BFE\u3057\u3066 x^ns = t \u3092\u89E3\u304F\
    \n// [lb, ub) \u306E\u6700\u521D\u306E\u89E3\u3092\u304B\u3048\u3059\u3002\u306A\
    \u3051\u308C\u3070 -1 \u3092\u304B\u3048\u3059\u3002\ntemplate <typename ActedSet,\
    \ typename F>\nll discrete_log_acted(typename ActedSet::A x, typename ActedSet::S\
    \ s,\n                      typename ActedSet::S t, F H, ll lb, ll ub) {\n  using\
    \ Mono = typename ActedSet::Monoid_A;\n  using X = typename Mono::value_type;\n\
    \  using S = typename ActedSet::S;\n\n  if (lb >= ub) return -1;\n  auto xpow\
    \ = [&](ll n) -> X {\n    X p = x;\n    X res = Mono::id();\n    while (n) {\n\
    \      if (n & 1) res = Mono::op(res, p);\n      p = Mono::op(p, p);\n      n\
    \ /= 2;\n    }\n    return res;\n  };\n\n  auto Ht = H(t);\n  s = ActedSet::act(s,\
    \ xpow(lb));\n  u64 LIM = ub - lb;\n\n  ll K = sqrt(LIM) + 1;\n\n  HashMap<char>\
    \ MP(K);\n\n  FOR(k, K) {\n    t = ActedSet::act(t, x);\n    MP[H(t)] = 1;\n \
    \ }\n\n  X y = xpow(K);\n  int failed = 0;\n  FOR(k, K + 1) {\n    S s1 = ActedSet::act(s,\
    \ y);\n    if (MP.count(H(s1))) {\n      FOR(i, K) {\n        if (H(s) == Ht)\
    \ {\n          ll ans = k * K + i + lb;\n          return (ans >= ub ? -1 : ans);\n\
    \        }\n        s = ActedSet::act(s, x);\n      }\n      if (failed) return\
    \ -1;\n      failed = 1;\n    }\n    s = s1;\n  }\n  return -1;\n}\n\n// \u7FA4\
    \ X \u306B\u304A\u3051\u308B log_a b \u306E\u8A08\u7B97\n// \u30CF\u30C3\u30B7\
    \u30E5\u95A2\u6570 H : X -> long long \u3092\u6301\u305F\u305B\u308B\n// [lb,\
    \ ub) \u306E\u6700\u521D\u306E\u89E3\u3092\u304B\u3048\u3059\u3001\u306A\u3051\
    \u308C\u3070 -1\ntemplate <typename Monoid, typename F>\nll discrete_log_monoid(typename\
    \ Monoid::X a, typename Monoid::X b, F H, ll lb,\n                       ll ub)\
    \ {\n  using AM = ActedSet_from_Monoid<Monoid>;\n  return discrete_log_acted<AM>(a,\
    \ Monoid::id(), b, H, lb, ub);\n}\n"
  dependsOn:
  - alg/monoid/mul.hpp
  - alg/acted_set/from_monoid.hpp
  - ds/hashmap.hpp
  isVerificationFile: false
  path: nt/discrete_log.hpp
  requiredBy:
  - mod/mod_log.hpp
  timestamp: '2026-10-15 19:54:56+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - test/3_yukicoder/1339.test.cpp
  - test/2_library_checker/number_theory/discrete_logarithm_mod.test.cpp
documentation_of: nt/discrete_log.hpp
layout: document
redirect_from:
- /library/nt/discrete_log.hpp
- /library/nt/discrete_log.hpp.html
title: nt/discrete_log.hpp
---
