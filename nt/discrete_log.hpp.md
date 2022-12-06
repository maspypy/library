---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: alg/acted_set/from_monoid.hpp
    title: alg/acted_set/from_monoid.hpp
  - icon: ':x:'
    path: ds/hashmap.hpp
    title: ds/hashmap.hpp
  _extendedRequiredBy:
  - icon: ':x:'
    path: mod/mod_log.hpp
    title: mod/mod_log.hpp
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/atcoder/abc270_g.test.cpp
    title: test/atcoder/abc270_g.test.cpp
  - icon: ':x:'
    path: test/library_checker/math/discrete_logarithm_mod.test.cpp
    title: test/library_checker/math/discrete_logarithm_mod.test.cpp
  - icon: ':x:'
    path: test/yukicoder/1339.test.cpp
    title: test/yukicoder/1339.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 1 \"alg/acted_set/from_monoid.hpp\"\ntemplate <typename Monoid>\n\
    struct ActedSet_From_Monoid {\n  using Monoid_A = Monoid;\n  using A = typename\
    \ Monoid::value_type;\n  using S = A;\n  static S act(const S &x, const A &g)\
    \ { return Monoid::op(x, g); }\n};\n#line 2 \"ds/hashmap.hpp\"\ntemplate <typename\
    \ Val, int LOG = 20>\r\nstruct HashMapLL {\r\n  int N;\r\n  ll* keys;\r\n  Val*\
    \ vals;\r\n  vc<int> IDS;\r\n  bitset<1 << LOG> used;\r\n  const int shift;\r\n\
    \  const uint64_t r = 11995408973635179863ULL;\r\n  HashMapLL()\r\n      : N(1\
    \ << LOG), keys(new ll[N]), vals(new Val[N]), shift(64 - __lg(N)) {}\r\n  int\
    \ hash(ll x) {\r\n    static const uint64_t FIXED_RANDOM\r\n        = std::chrono::steady_clock::now().time_since_epoch().count();\r\
    \n    return (uint64_t(x + FIXED_RANDOM) * r) >> shift;\r\n  }\r\n\r\n  int index(const\
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
    \n};\r\n#line 3 \"nt/discrete_log.hpp\"\n\r\n// \u7FA4 X \u306E\u4F5C\u7528\u3059\
    \u308B\u96C6\u5408 S\u3001\u30CF\u30C3\u30B7\u30E5\u95A2\u6570 H\uFF1AS -> Z\r\
    \n// x in G, s, t in S \u306B\u5BFE\u3057\u3066 x^ns = t \u3092\u89E3\u304F\r\n\
    // [lb, ub) \u306E\u6700\u521D\u306E\u89E3\u3092\u304B\u3048\u3059\u3002\u306A\
    \u3051\u308C\u3070 -1 \u3092\u304B\u3048\u3059\u3002\r\ntemplate <typename ActedSet,\
    \ typename F, int MP_SIZE = 20>\r\nll discrete_log_acted(typename ActedSet::A\
    \ x, typename ActedSet::S s,\r\n                      typename ActedSet::S t,\
    \ F H, ll lb, ll ub) {\r\n  static HashMapLL<int, MP_SIZE> MP;\r\n  MP.reset();\r\
    \n  using Group = typename ActedSet::Monoid_A;\r\n  using G = typename Group::value_type;\r\
    \n  if (lb >= ub) return -1;\r\n  auto xpow = [&](ll n) -> G {\r\n    G p = x;\r\
    \n    G res = Group::unit();\r\n    while (n) {\r\n      if (n & 1) res = Group::op(res,\
    \ p);\r\n      p = Group::op(p, p);\r\n      n /= 2;\r\n    }\r\n    return res;\r\
    \n  };\r\n  s = ActedSet::act(s, xpow(lb));\r\n  u64 LIM = ub - lb;\r\n\r\n  ll\
    \ K = sqrt(LIM) + 1;\r\n\r\n  FOR(k, K + 1) {\r\n    ll key = H(s);\r\n    if\
    \ (!MP.count(key)) MP[key] = k;\r\n    if (k != K) s = ActedSet::act(s, x);\r\n\
    \  }\r\n\r\n  x = Group::inverse(xpow(K));\r\n  FOR(k, K + 1) {\r\n    ll key\
    \ = H(t);\r\n    if (MP.count(key)) {\r\n      ll res = k * K + MP[key] + lb;\r\
    \n      return (res >= ub ? -1 : res);\r\n    }\r\n    t = ActedSet::act(t, x);\r\
    \n  }\r\n  return -1;\r\n}\r\n\r\n// \u7FA4 X \u306B\u304A\u3051\u308B log_a b\
    \ \u306E\u8A08\u7B97\r\n// \u30CF\u30C3\u30B7\u30E5\u95A2\u6570 H : X -> long\
    \ long \u3092\u6301\u305F\u305B\u308B\r\n// [lb, ub) \u306E\u6700\u521D\u306E\u89E3\
    \u3092\u304B\u3048\u3059\u3001\u306A\u3051\u308C\u3070 -1\r\ntemplate <typename\
    \ Group, typename F>\r\nll discrete_log_group(typename Group::X a, typename Group::X\
    \ b, F H, ll lb,\r\n                      ll ub) {\r\n  using AM = ActedSet_From_Monoid<Group>;\r\
    \n  return discrete_log_acted<AM>(a, Group::unit(), b, H, lb, ub);\r\n}\n"
  code: "#include \"alg/acted_set/from_monoid.hpp\"\r\n#include \"ds/hashmap.hpp\"\
    \r\n\r\n// \u7FA4 X \u306E\u4F5C\u7528\u3059\u308B\u96C6\u5408 S\u3001\u30CF\u30C3\
    \u30B7\u30E5\u95A2\u6570 H\uFF1AS -> Z\r\n// x in G, s, t in S \u306B\u5BFE\u3057\
    \u3066 x^ns = t \u3092\u89E3\u304F\r\n// [lb, ub) \u306E\u6700\u521D\u306E\u89E3\
    \u3092\u304B\u3048\u3059\u3002\u306A\u3051\u308C\u3070 -1 \u3092\u304B\u3048\u3059\
    \u3002\r\ntemplate <typename ActedSet, typename F, int MP_SIZE = 20>\r\nll discrete_log_acted(typename\
    \ ActedSet::A x, typename ActedSet::S s,\r\n                      typename ActedSet::S\
    \ t, F H, ll lb, ll ub) {\r\n  static HashMapLL<int, MP_SIZE> MP;\r\n  MP.reset();\r\
    \n  using Group = typename ActedSet::Monoid_A;\r\n  using G = typename Group::value_type;\r\
    \n  if (lb >= ub) return -1;\r\n  auto xpow = [&](ll n) -> G {\r\n    G p = x;\r\
    \n    G res = Group::unit();\r\n    while (n) {\r\n      if (n & 1) res = Group::op(res,\
    \ p);\r\n      p = Group::op(p, p);\r\n      n /= 2;\r\n    }\r\n    return res;\r\
    \n  };\r\n  s = ActedSet::act(s, xpow(lb));\r\n  u64 LIM = ub - lb;\r\n\r\n  ll\
    \ K = sqrt(LIM) + 1;\r\n\r\n  FOR(k, K + 1) {\r\n    ll key = H(s);\r\n    if\
    \ (!MP.count(key)) MP[key] = k;\r\n    if (k != K) s = ActedSet::act(s, x);\r\n\
    \  }\r\n\r\n  x = Group::inverse(xpow(K));\r\n  FOR(k, K + 1) {\r\n    ll key\
    \ = H(t);\r\n    if (MP.count(key)) {\r\n      ll res = k * K + MP[key] + lb;\r\
    \n      return (res >= ub ? -1 : res);\r\n    }\r\n    t = ActedSet::act(t, x);\r\
    \n  }\r\n  return -1;\r\n}\r\n\r\n// \u7FA4 X \u306B\u304A\u3051\u308B log_a b\
    \ \u306E\u8A08\u7B97\r\n// \u30CF\u30C3\u30B7\u30E5\u95A2\u6570 H : X -> long\
    \ long \u3092\u6301\u305F\u305B\u308B\r\n// [lb, ub) \u306E\u6700\u521D\u306E\u89E3\
    \u3092\u304B\u3048\u3059\u3001\u306A\u3051\u308C\u3070 -1\r\ntemplate <typename\
    \ Group, typename F>\r\nll discrete_log_group(typename Group::X a, typename Group::X\
    \ b, F H, ll lb,\r\n                      ll ub) {\r\n  using AM = ActedSet_From_Monoid<Group>;\r\
    \n  return discrete_log_acted<AM>(a, Group::unit(), b, H, lb, ub);\r\n}"
  dependsOn:
  - alg/acted_set/from_monoid.hpp
  - ds/hashmap.hpp
  isVerificationFile: false
  path: nt/discrete_log.hpp
  requiredBy:
  - mod/mod_log.hpp
  timestamp: '2022-11-28 21:09:42+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/yukicoder/1339.test.cpp
  - test/library_checker/math/discrete_logarithm_mod.test.cpp
  - test/atcoder/abc270_g.test.cpp
documentation_of: nt/discrete_log.hpp
layout: document
redirect_from:
- /library/nt/discrete_log.hpp
- /library/nt/discrete_log.hpp.html
title: nt/discrete_log.hpp
---
