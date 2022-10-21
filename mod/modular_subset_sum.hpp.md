---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.10.8/x64/lib/python3.10/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.10.8/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.10.8/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.10.8/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: other/random.hpp:\
    \ line -1: no such header\n"
  code: "#include \"other/random.hpp\"\r\n#include \"mod/modint61.hpp\"\r\n\r\n//\
    \ Faster Deterministic Modular Subset Sum. arXiv preprint arXiv:2012.06062.\r\n\
    // modular subset sum \u306E\u305F\u3081\u306E\u3001\u30B7\u30D5\u30C8\u4ED8\u304D\
    \u30BB\u30B0\u6728\r\n// shift \u306B\u306F 2^(N-k) \u6642\u9593\u304B\u304B\u308B\
    \r\nstruct ShiftTree {\r\n  using M61 = modint61;\r\n  int delta;\r\n  int N,\
    \ n;\r\n  M61 base;\r\n  vc<M61> dat;\r\n  vc<M61> base_pow;\r\n\r\n  ShiftTree(int\
    \ N, ll base) : delta(0), N(N), n(topbit(N)), base(base) {\r\n    assert(N ==\
    \ (1 << n));\r\n    dat.assign(2 * N, 0);\r\n\r\n    base_pow.assign(n, 1);\r\n\
    \    base_pow[n - 1] = base;\r\n    FOR_R(i, n - 1) base_pow[i] = base_pow[i +\
    \ 1] * base_pow[i + 1];\r\n  }\r\n\r\n  inline int skew(int k) { return (delta\
    \ >> (n - k)) & 1; }\r\n\r\n  inline int left(int k, int i) {\r\n    int mask\
    \ = (1 << (k + 1)) - 1;\r\n    return ((2 * i + 0 - skew(k + 1)) & mask) + (1\
    \ << (k + 1));\r\n  }\r\n\r\n  inline int right(int k, int i) {\r\n    int mask\
    \ = (1 << (k + 1)) - 1;\r\n    return ((2 * i + 1 - skew(k + 1)) & mask) + (1\
    \ << (k + 1));\r\n  }\r\n\r\n  inline int parent(int k, int i) {\r\n    int mask\
    \ = (1 << k) - 1;\r\n    return (((i + skew(k)) & mask) + (1 << k)) / 2;\r\n \
    \ }\r\n\r\n  inline void update(int k, int i) {\r\n    M61 b = base_pow[k];\r\n\
    \    dat[i] = b * dat[left(k, i)] + dat[right(k, i)];\r\n  }\r\n\r\n  inline void\
    \ set(int i, ll x) {\r\n    i = (i + N - delta) % N + N;\r\n    dat[i] = x;\r\n\
    \    int k = n;\r\n    while (i != 1) {\r\n      i = parent(k, i);\r\n      --k;\r\
    \n      update(k, i);\r\n    }\r\n  }\r\n\r\n  void shift(int k) {\r\n    k %=\
    \ N;\r\n    if (k < 0) k += N;\r\n    if (k == 0) return;\r\n    int j = lowbit(k);\r\
    \n    delta = (delta + k) % N;\r\n    FOR_R(k, n - j) { FOR3(i, 1 << k, 2 << k)\
    \ update(k, i); }\r\n  }\r\n\r\n  // [a,b) \u306B\u304A\u3051\u308B difference\
    \ \u306E\u5217\u6319\u3002output sensitive\u3002\r\n  // T \u306E\u30CE\u30FC\u30C9\
    \ i\u3001Q \u306E\u30CE\u30FC\u30C9 j \u304C (x,y) \u3092\u6307\u3059\u3068\u3059\
    \u308B\u3002\r\n  static void find_differences(vc<int>& res, ShiftTree& T, ShiftTree&\
    \ Q, int a,\r\n                               int b, int k, int i, int j, int\
    \ x, int y) {\r\n    if (T.dat[i] == Q.dat[j]) return;\r\n    if (max(a, x) >=\
    \ min(b, y)) return;\r\n    if (y == x + 1) {\r\n      res.eb(x);\r\n      return;\r\
    \n    }\r\n    int z = (x + y) / 2;\r\n    find_differences(res, T, Q, a, b, k\
    \ + 1, T.left(k, i), Q.left(k, j), x, z);\r\n    find_differences(res, T, Q, a,\
    \ b, k + 1, T.right(k, i), Q.right(k, j), z,\r\n                     y);\r\n \
    \ }\r\n\r\n  static vc<int> diff(ShiftTree& T, ShiftTree& Q, int a, int b) {\r\
    \n    assert(T.N == Q.N);\r\n    vc<int> res;\r\n    find_differences(res, T,\
    \ Q, a, b, 0, 1, 1, 0, T.N);\r\n    return res;\r\n  }\r\n};\r\n\r\n/*\r\n\u8A08\
    \u7B97\u91CF\uFF1A(|vals| + mod) * log(mod)\r\n\u30FBcan(x) \u307E\u305F\u306F\
    \ [x] \u3067 bool \u3092\u8FD4\u3059\u3002\r\n\u30FBrestore(x) \u3067\u5FA9\u5143\
    \u3002\r\n\u30B3\u30F3\u30B9\u30C8\u30E9\u30AF\u30BF\u306B\u306F\u3001(mod, vals)\
    \ \u3092\u308F\u305F\u3059\r\n*/\r\ntemplate<typename INT>\r\nstruct Modular_Subset_Sum\
    \ {\r\n  int mod;\r\n  vc<INT>& vals;\r\n  vc<int> par;\r\n\r\n  Modular_Subset_Sum(int\
    \ mod, vc<INT>& vals) : mod(mod), vals(vals) {\r\n    for(auto&& x : vals) assert(0\
    \ <= x && x < mod);\r\n    par.assign(mod, -1);\r\n\r\n    const ll base = RNG(0,\
    \ (1LL << 61) - 1);\r\n\r\n    int k = 1;\r\n    while ((1 << k) < 2 * mod) ++k;\r\
    \n\r\n    int L = 1 << k;\r\n    assert(L >= 2 * mod);\r\n\r\n    ShiftTree T1(L,\
    \ base);\r\n    ShiftTree T2(L, base);\r\n    T1.set(0, 1);\r\n    T2.set(0, 1);\r\
    \n    T2.set(L - mod, 1);\r\n\r\n    auto bit_rev = [&](int i) -> int {\r\n  \
    \    int x = 0;\r\n      FOR(k) {\r\n        x = 2 * x + (i & 1);\r\n        i\
    \ >>= 1;\r\n      }\r\n      return x;\r\n    };\r\n\r\n    vc<vi> IDS(L);\r\n\
    \    FOR(i, len(vals)) { IDS[vals[i]].eb(i); }\r\n\r\n    FOR(i, 1, L) {\r\n \
    \     int x = bit_rev(i);\r\n      if (len(IDS[x]) == 0) continue;\r\n      T2.shift(x\
    \ - T2.delta);\r\n      for (auto&& idx: IDS[x]) {\r\n        auto diff = ShiftTree::diff(T1,\
    \ T2, 0, mod);\r\n        for (auto&& d: diff) {\r\n          if (can(d)) continue;\r\
    \n          par[d] = idx;\r\n          T1.set(d, 1);\r\n          T2.set((d +\
    \ x) % L, 1);\r\n          T2.set((L + d + x - mod) % L, 1);\r\n        }\r\n\
    \      }\r\n    }\r\n  }\r\n\r\n  bool can(int x) { return (x == 0 || par[x] !=\
    \ -1); }\r\n  bool operator[](int x) { return can(x); }\r\n  vc<int> restore(int\
    \ x) {\r\n    vc<int> res;\r\n    while (x) {\r\n      int i = par[x];\r\n   \
    \   res.eb(i);\r\n      x -= vals[i];\r\n      if (x < 0) x += mod;\r\n    }\r\
    \n    reverse(all(res));\r\n    return res;\r\n  }\r\n};\r\n"
  dependsOn: []
  isVerificationFile: false
  path: mod/modular_subset_sum.hpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: mod/modular_subset_sum.hpp
layout: document
redirect_from:
- /library/mod/modular_subset_sum.hpp
- /library/mod/modular_subset_sum.hpp.html
title: mod/modular_subset_sum.hpp
---
