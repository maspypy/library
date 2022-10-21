---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: ds/hashmap.hpp
    title: ds/hashmap.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
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
    \n};\r\n#line 2 \"nt/discrete_log.hpp\"\n// log_a b \u306E\u8A08\u7B97\r\n// \u30CF\
    \u30C3\u30B7\u30E5\u95A2\u6570 H : X -> long long \u3092\u6301\u305F\u305B\u308B\
    \r\n// [lb, ub) \u306E\u6700\u521D\u306E\u89E3\u3092\u304B\u3048\u3059\r\n// \u306A\
    \u3051\u308C\u3070 -1\r\ntemplate <typename Group>\r\nll discrete_log(typename\
    \ Group::X a, typename Group::X b,\r\n                function<ll(typename Group::X)>\
    \ H, ll lb, ll ub) {\r\n  using G = typename Group::X;\r\n  if (lb >= ub) return\
    \ -1;\r\n  {\r\n    ll n = lb;\r\n    G p = a;\r\n    G x = Group::unit();\r\n\
    \    while (n) {\r\n      if (n & 1) x = Group::op(x, p);\r\n      p = Group::op(p,\
    \ p);\r\n      n /= 2;\r\n    }\r\n    x = Group::inverse(x);\r\n    b = Group::op(b,\
    \ x);\r\n  }\r\n  ll LIM = ub - lb;\r\n\r\n  ll K = 1;\r\n  while (K * K < LIM)\
    \ ++K;\r\n\r\n  static HashMapLL<int, 20> MP;\r\n  MP.reset();\r\n\r\n  G p =\
    \ Group::unit();\r\n  FOR(k, K + 1) {\r\n    auto key = H(p);\r\n    if (!MP.count(key))\
    \ MP[key] = k;\r\n    if (k != K) p = Group::op(p, a);\r\n  }\r\n  p = Group::inverse(p);\r\
    \n  FOR(k, K + 1) {\r\n    auto key = H(b);\r\n    if (MP.count(key)) {\r\n  \
    \    ll res = k * K + MP[key] + lb;\r\n      return (res >= ub ? -1 : res);\r\n\
    \    }\r\n    b = Group::op(b, p);\r\n  }\r\n  return -1;\r\n}\r\n\r\n// yuki1648\r\
    \n// G \u96C6\u5408 X \u304C\u3042\u308B\u3002\r\n// a in G, x, y in X \u306B\u5BFE\
    \u3057\u3066 a^nx=y \u3092\u89E3\u304F\r\n// \u30CF\u30C3\u30B7\u30E5\u95A2\u6570\
    \ H : X -> long long \u3092\u6301\u305F\u305B\u308B\r\n// [lb, ub) \u306E\u6700\
    \u521D\u306E\u89E3\u3092\u304B\u3048\u3059\r\n// \u306A\u3051\u308C\u3070 -1\r\
    \ntemplate <typename GSet>\r\nll discrete_log_gset(typename GSet::G a, typename\
    \ GSet::X x, typename GSet::X y,\r\n                     function<ll(typename\
    \ GSet::X)> H, ll lb, ll ub) {\r\n  using Group = typename GSet::Group;\r\n  using\
    \ G = typename Group::value_type;\r\n  if (lb >= ub) return -1;\r\n  auto apow\
    \ = [&](ll n) -> G {\r\n    G p = a;\r\n    G res = Group::unit();\r\n    while\
    \ (n) {\r\n      if (n & 1) res = Group::op(res, p);\r\n      p = Group::op(p,\
    \ p);\r\n      n /= 2;\r\n    }\r\n    return res;\r\n  };\r\n  x = GSet::act(apow(lb),\
    \ x);\r\n  ll LIM = ub - lb;\r\n\r\n  ll K = 1;\r\n  while (K * K < LIM) ++K;\r\
    \n\r\n  static HashMapLL<int, 20> MP;\r\n  MP.reset();\r\n\r\n  FOR(k, K + 1)\
    \ {\r\n    auto key = H(x);\r\n    if (!MP.count(key)) MP[key] = k;\r\n    if\
    \ (k != K) x = GSet::act(a, x);\r\n  }\r\n\r\n  a = Group::inverse(apow(K));\r\
    \n  FOR(k, K + 1) {\r\n    auto key = H(y);\r\n    if (MP.count(key)) {\r\n  \
    \    ll res = k * K + MP[key] + lb;\r\n      return (res >= ub ? -1 : res);\r\n\
    \    }\r\n    y = GSet::act(a, y);\r\n  }\r\n  return -1;\r\n}\n"
  code: "#include \"ds/hashmap.hpp\"\r\n// log_a b \u306E\u8A08\u7B97\r\n// \u30CF\
    \u30C3\u30B7\u30E5\u95A2\u6570 H : X -> long long \u3092\u6301\u305F\u305B\u308B\
    \r\n// [lb, ub) \u306E\u6700\u521D\u306E\u89E3\u3092\u304B\u3048\u3059\r\n// \u306A\
    \u3051\u308C\u3070 -1\r\ntemplate <typename Group>\r\nll discrete_log(typename\
    \ Group::X a, typename Group::X b,\r\n                function<ll(typename Group::X)>\
    \ H, ll lb, ll ub) {\r\n  using G = typename Group::X;\r\n  if (lb >= ub) return\
    \ -1;\r\n  {\r\n    ll n = lb;\r\n    G p = a;\r\n    G x = Group::unit();\r\n\
    \    while (n) {\r\n      if (n & 1) x = Group::op(x, p);\r\n      p = Group::op(p,\
    \ p);\r\n      n /= 2;\r\n    }\r\n    x = Group::inverse(x);\r\n    b = Group::op(b,\
    \ x);\r\n  }\r\n  ll LIM = ub - lb;\r\n\r\n  ll K = 1;\r\n  while (K * K < LIM)\
    \ ++K;\r\n\r\n  static HashMapLL<int, 20> MP;\r\n  MP.reset();\r\n\r\n  G p =\
    \ Group::unit();\r\n  FOR(k, K + 1) {\r\n    auto key = H(p);\r\n    if (!MP.count(key))\
    \ MP[key] = k;\r\n    if (k != K) p = Group::op(p, a);\r\n  }\r\n  p = Group::inverse(p);\r\
    \n  FOR(k, K + 1) {\r\n    auto key = H(b);\r\n    if (MP.count(key)) {\r\n  \
    \    ll res = k * K + MP[key] + lb;\r\n      return (res >= ub ? -1 : res);\r\n\
    \    }\r\n    b = Group::op(b, p);\r\n  }\r\n  return -1;\r\n}\r\n\r\n// yuki1648\r\
    \n// G \u96C6\u5408 X \u304C\u3042\u308B\u3002\r\n// a in G, x, y in X \u306B\u5BFE\
    \u3057\u3066 a^nx=y \u3092\u89E3\u304F\r\n// \u30CF\u30C3\u30B7\u30E5\u95A2\u6570\
    \ H : X -> long long \u3092\u6301\u305F\u305B\u308B\r\n// [lb, ub) \u306E\u6700\
    \u521D\u306E\u89E3\u3092\u304B\u3048\u3059\r\n// \u306A\u3051\u308C\u3070 -1\r\
    \ntemplate <typename GSet>\r\nll discrete_log_gset(typename GSet::G a, typename\
    \ GSet::X x, typename GSet::X y,\r\n                     function<ll(typename\
    \ GSet::X)> H, ll lb, ll ub) {\r\n  using Group = typename GSet::Group;\r\n  using\
    \ G = typename Group::value_type;\r\n  if (lb >= ub) return -1;\r\n  auto apow\
    \ = [&](ll n) -> G {\r\n    G p = a;\r\n    G res = Group::unit();\r\n    while\
    \ (n) {\r\n      if (n & 1) res = Group::op(res, p);\r\n      p = Group::op(p,\
    \ p);\r\n      n /= 2;\r\n    }\r\n    return res;\r\n  };\r\n  x = GSet::act(apow(lb),\
    \ x);\r\n  ll LIM = ub - lb;\r\n\r\n  ll K = 1;\r\n  while (K * K < LIM) ++K;\r\
    \n\r\n  static HashMapLL<int, 20> MP;\r\n  MP.reset();\r\n\r\n  FOR(k, K + 1)\
    \ {\r\n    auto key = H(x);\r\n    if (!MP.count(key)) MP[key] = k;\r\n    if\
    \ (k != K) x = GSet::act(a, x);\r\n  }\r\n\r\n  a = Group::inverse(apow(K));\r\
    \n  FOR(k, K + 1) {\r\n    auto key = H(y);\r\n    if (MP.count(key)) {\r\n  \
    \    ll res = k * K + MP[key] + lb;\r\n      return (res >= ub ? -1 : res);\r\n\
    \    }\r\n    y = GSet::act(a, y);\r\n  }\r\n  return -1;\r\n}"
  dependsOn:
  - ds/hashmap.hpp
  isVerificationFile: false
  path: nt/discrete_log.hpp
  requiredBy: []
  timestamp: '2022-10-21 20:37:52+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: nt/discrete_log.hpp
layout: document
redirect_from:
- /library/nt/discrete_log.hpp
- /library/nt/discrete_log.hpp.html
title: nt/discrete_log.hpp
---
