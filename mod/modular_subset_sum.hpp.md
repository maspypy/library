---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: alg/monoid_rollinghash.hpp
    title: alg/monoid_rollinghash.hpp
  - icon: ':question:'
    path: ds/segtree.hpp
    title: ds/segtree.hpp
  - icon: ':heavy_check_mark:'
    path: mod/modint61.hpp
    title: mod/modint61.hpp
  - icon: ':question:'
    path: other/random.hpp
    title: other/random.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/4_modular_subset_sum.test.cpp
    title: test/yukicoder/4_modular_subset_sum.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"mod/modint61.hpp\"\nstruct modint61 {\r\n  static constexpr\
    \ bool is_modint = true;\r\n  static constexpr ll mod = (1LL << 61) - 1;\r\n \
    \ ll val;\r\n  constexpr modint61(const ll val = 0) : val(val) {}\r\n  bool operator<(const\
    \ modint61 &other) const {\r\n    return val < other.val;\r\n  } // To use std::map\r\
    \n  bool operator==(const modint61 &p) const { return val == p.val; }\r\n  bool\
    \ operator!=(const modint61 &p) const { return val != p.val; }\r\n  modint61 &operator+=(const\
    \ modint61 &p) {\r\n    if ((val += p.val) >= mod) val -= mod;\r\n    return *this;\r\
    \n  }\r\n  modint61 &operator-=(const modint61 &p) {\r\n    if ((val += mod -\
    \ p.val) >= mod) val -= mod;\r\n    return *this;\r\n  }\r\n  modint61 &operator*=(const\
    \ modint61 &p) {\r\n    ll a = val, b = p.val;\r\n    const ll MASK30 = (1LL <<\
    \ 30) - 1;\r\n    const ll MASK31 = (1LL << 31) - 1;\r\n    const ll MASK61 =\
    \ (1LL << 61) - 1;\r\n    ll au = a >> 31, ad = a & MASK31;\r\n    ll bu = b >>\
    \ 31, bd = b & MASK31;\r\n    ll x = ad * bu + au * bd;\r\n    ll xu = x >> 30,\
    \ xd = x & MASK30;\r\n    x = au * bu * 2 + xu + (xd << 31) + ad * bd;\r\n   \
    \ xu = x >> 61, xd = x & MASK61;\r\n    x = xu + xd;\r\n    if (x >= MASK61) x\
    \ -= MASK61;\r\n    val = x;\r\n    return *this;\r\n  }\r\n  modint61 &operator/=(const\
    \ modint61 &p) {\r\n    *this *= p.inverse();\r\n    return *this;\r\n  }\r\n\
    \  modint61 operator+(const modint61 &p) const { return modint61(*this) += p;\
    \ }\r\n  modint61 operator-(const modint61 &p) const { return modint61(*this)\
    \ -= p; }\r\n  modint61 operator*(const modint61 &p) const { return modint61(*this)\
    \ *= p; }\r\n  modint61 operator/(const modint61 &p) const { return modint61(*this)\
    \ /= p; }\r\n\r\n  modint61 inverse() const {\r\n    ll a = val, b = mod, u =\
    \ 1, v = 0, t;\r\n    while (b > 0) {\r\n      t = a / b;\r\n      swap(a -= t\
    \ * b, b), swap(u -= t * v, v);\r\n    }\r\n    return modint61(u);\r\n  }\r\n\
    \  modint61 pow(int64_t n) const {\r\n    modint61 ret(1), mul(val);\r\n    while\
    \ (n > 0) {\r\n      if (n & 1) ret = ret * mul;\r\n      mul = mul * mul;\r\n\
    \      n >>= 1;\r\n    }\r\n    return ret;\r\n  }\r\n  static constexpr ll get_mod()\
    \ { return mod; }\r\n};\r\n#line 3 \"alg/monoid_rollinghash.hpp\"\n\r\nstruct\
    \ Monoid_Rolling_Hash {\r\n  using value_type = pair<modint61, modint61>; // pow\
    \ of base, val\r\n  using X = value_type;\r\n  static X op(X x, X y) { return\
    \ {x.fi * y.fi, x.se * y.fi + y.se}; }\r\n  static constexpr X unit() { return\
    \ {1, 0}; }\r\n  static constexpr bool commute = false;\r\n};\n#line 1 \"other/random.hpp\"\
    \nstruct RandomNumberGenerator {\n  mt19937 mt;\n\n  RandomNumberGenerator() :\
    \ mt(chrono::steady_clock::now().time_since_epoch().count()) {}\n\n  ll operator()(ll\
    \ a, ll b) {  // [a, b)\n    uniform_int_distribution<ll> dist(a, b - 1);\n  \
    \  return dist(mt);\n  }\n\n  ll operator()(ll b) {  // [0, b)\n    return (*this)(0,\
    \ b);\n  }\n};\n#line 2 \"ds/segtree.hpp\"\ntemplate <class Monoid>\nstruct SegTree\
    \ {\n  using X = typename Monoid::value_type;\n  using value_type = X;\n  vc<X>\
    \ dat;\n  int n, log, size;\n\n  SegTree() : SegTree(0) {}\n  SegTree(int n) :\
    \ SegTree(vc<X>(n, Monoid::unit())) {}\n  SegTree(vc<X> v) : n(len(v)) {\n   \
    \ log = 1;\n    while ((1 << log) < n) ++log;\n    size = 1 << log;\n    dat.assign(size\
    \ << 1, Monoid::unit());\n    FOR(i, n) dat[size + i] = v[i];\n    FOR3_R(i, 1,\
    \ size) update(i);\n  }\n\n  X operator[](int i) { return dat[size + i]; }\n\n\
    \  void update(int i) { dat[i] = Monoid::op(dat[2 * i], dat[2 * i + 1]); }\n\n\
    \  void set(int i, X x) {\n    assert(i < n);\n    dat[i += size] = x;\n    while\
    \ (i >>= 1) update(i);\n  }\n\n  X prod(int L, int R) {\n    assert(L <= R);\n\
    \    assert(R <= n);\n    X vl = Monoid::unit(), vr = Monoid::unit();\n    L +=\
    \ size, R += size;\n    while (L < R) {\n      if (L & 1) vl = Monoid::op(vl,\
    \ dat[L++]);\n      if (R & 1) vr = Monoid::op(dat[--R], vr);\n      L >>= 1,\
    \ R >>= 1;\n    }\n    return Monoid::op(vl, vr);\n  }\n\n  X prod_all() { return\
    \ dat[1]; }\n\n  template <class F>\n  int max_right(F &check, int L) {\n    assert(0\
    \ <= L && L <= n && check(Monoid::unit()));\n    if (L == n) return n;\n    L\
    \ += size;\n    X sm = Monoid::unit();\n    do {\n      while (L % 2 == 0) L >>=\
    \ 1;\n      if (!check(Monoid::op(sm, dat[L]))) {\n        while (L < size) {\n\
    \          L = 2 * L;\n          if (check(Monoid::op(sm, dat[L]))) {\n      \
    \      sm = Monoid::op(sm, dat[L]);\n            L++;\n          }\n        }\n\
    \        return L - size;\n      }\n      sm = Monoid::op(sm, dat[L]);\n     \
    \ L++;\n    } while ((L & -L) != L);\n    return n;\n  }\n\n  template <class\
    \ F>\n  int min_left(F &check, int R) {\n    assert(0 <= R && R <= n && check(Monoid::unit()));\n\
    \    if (R == 0) return 0;\n    R += size;\n    X sm = Monoid::unit();\n    do\
    \ {\n      --R;\n      while (R > 1 && (R % 2)) R >>= 1;\n      if (!check(Monoid::op(dat[R],\
    \ sm))) {\n        while (R < size) {\n          R = 2 * R + 1;\n          if\
    \ (check(Monoid::op(dat[R], sm))) {\n            sm = Monoid::op(dat[R], sm);\n\
    \            R--;\n          }\n        }\n        return R + 1 - size;\n    \
    \  }\n      sm = Monoid::op(dat[R], sm);\n    } while ((R & -R) != R);\n    return\
    \ 0;\n  }\n\n  void debug() { print(\"segtree\", dat); }\n};\n#line 4 \"mod/modular_subset_sum.hpp\"\
    \n\r\n/*\r\n\u8A08\u7B97\u91CF\uFF1A(|vals| + mod) * log^2(mod)\r\n\u30FBcan(x)\
    \ \u307E\u305F\u306F [x] \u3067 bool \u3092\u8FD4\u3059\u3002\r\n\u30FBrestore(x)\
    \ \u3067\u5FA9\u5143\u3002\r\n*/\r\nstruct Modular_Subset_Sum {\r\n  int mod;\r\
    \n  vc<int>& vals;\r\n  vc<int> par;\r\n\r\n  Modular_Subset_Sum(int mod, vc<int>&\
    \ vals) : mod(mod), vals(vals) {\r\n    par.assign(mod, -1);\r\n\r\n    using\
    \ Mono = Monoid_Rolling_Hash;\r\n    RandomNumberGenerator RNG;\r\n    const ll\
    \ base = RNG(0, (1LL << 61) - 1);\r\n    vc<pair<modint61, modint61>> seg_raw(mod\
    \ + mod);\r\n    FOR(i, mod + mod) seg_raw[i] = {base, 0};\r\n    SegTree<Mono>\
    \ seg(seg_raw);\r\n\r\n    auto add = [&](int x, int i) -> void {\r\n      par[x]\
    \ = i;\r\n      seg.set(x, {base, 1});\r\n      seg.set(x + mod, {base, 1});\r\
    \n    };\r\n\r\n    add(0, -1);\r\n\r\n    FOR(i, len(vals)) {\r\n      ll val\
    \ = vals[i];\r\n      val %= mod;\r\n      vc<pair<int, int>> LR;\r\n      LR.eb(0,\
    \ mod);\r\n      vc<int> ADD;\r\n      while (len(LR)) {\r\n        auto [L, R]\
    \ = LR.back();\r\n        LR.pop_back();\r\n        if (L == R) continue;\r\n\
    \        modint61 x1 = seg.prod(L, R).se;\r\n        modint61 x2 = seg.prod(mod\
    \ + L - val, mod + R - val).se;\r\n        if (x1 == x2) continue;\r\n       \
    \ if (R == L + 1) {\r\n          // \u5BFE\u79F0\u5DEE L \u304C\u898B\u3064\u304B\
    \u3063\u305F\r\n          if (!can(L)) ADD.eb(L);\r\n          continue;\r\n \
    \       }\r\n        ll M = (L + R) / 2;\r\n        LR.eb(L, M);\r\n        LR.eb(M,\
    \ R);\r\n      }\r\n      for (auto&& a: ADD) add(a, i);\r\n    }\r\n  }\r\n\r\
    \n  bool can(int x) { return (x == 0 || par[x] != -1); }\r\n  bool operator[](int\
    \ x) { return can(x); }\r\n  vc<int> restore(int x) {\r\n    vc<int> res;\r\n\
    \    while (x) {\r\n      int i = par[x];\r\n      res.eb(i);\r\n      x -= vals[i];\r\
    \n      if (x < 0) x += mod;\r\n    }\r\n    reverse(all(res));\r\n    return\
    \ res;\r\n  }\r\n};\r\n"
  code: "#include \"alg/monoid_rollinghash.hpp\"\r\n#include \"other/random.hpp\"\r\
    \n#include \"ds/segtree.hpp\"\r\n\r\n/*\r\n\u8A08\u7B97\u91CF\uFF1A(|vals| + mod)\
    \ * log^2(mod)\r\n\u30FBcan(x) \u307E\u305F\u306F [x] \u3067 bool \u3092\u8FD4\
    \u3059\u3002\r\n\u30FBrestore(x) \u3067\u5FA9\u5143\u3002\r\n*/\r\nstruct Modular_Subset_Sum\
    \ {\r\n  int mod;\r\n  vc<int>& vals;\r\n  vc<int> par;\r\n\r\n  Modular_Subset_Sum(int\
    \ mod, vc<int>& vals) : mod(mod), vals(vals) {\r\n    par.assign(mod, -1);\r\n\
    \r\n    using Mono = Monoid_Rolling_Hash;\r\n    RandomNumberGenerator RNG;\r\n\
    \    const ll base = RNG(0, (1LL << 61) - 1);\r\n    vc<pair<modint61, modint61>>\
    \ seg_raw(mod + mod);\r\n    FOR(i, mod + mod) seg_raw[i] = {base, 0};\r\n   \
    \ SegTree<Mono> seg(seg_raw);\r\n\r\n    auto add = [&](int x, int i) -> void\
    \ {\r\n      par[x] = i;\r\n      seg.set(x, {base, 1});\r\n      seg.set(x +\
    \ mod, {base, 1});\r\n    };\r\n\r\n    add(0, -1);\r\n\r\n    FOR(i, len(vals))\
    \ {\r\n      ll val = vals[i];\r\n      val %= mod;\r\n      vc<pair<int, int>>\
    \ LR;\r\n      LR.eb(0, mod);\r\n      vc<int> ADD;\r\n      while (len(LR)) {\r\
    \n        auto [L, R] = LR.back();\r\n        LR.pop_back();\r\n        if (L\
    \ == R) continue;\r\n        modint61 x1 = seg.prod(L, R).se;\r\n        modint61\
    \ x2 = seg.prod(mod + L - val, mod + R - val).se;\r\n        if (x1 == x2) continue;\r\
    \n        if (R == L + 1) {\r\n          // \u5BFE\u79F0\u5DEE L \u304C\u898B\u3064\
    \u304B\u3063\u305F\r\n          if (!can(L)) ADD.eb(L);\r\n          continue;\r\
    \n        }\r\n        ll M = (L + R) / 2;\r\n        LR.eb(L, M);\r\n       \
    \ LR.eb(M, R);\r\n      }\r\n      for (auto&& a: ADD) add(a, i);\r\n    }\r\n\
    \  }\r\n\r\n  bool can(int x) { return (x == 0 || par[x] != -1); }\r\n  bool operator[](int\
    \ x) { return can(x); }\r\n  vc<int> restore(int x) {\r\n    vc<int> res;\r\n\
    \    while (x) {\r\n      int i = par[x];\r\n      res.eb(i);\r\n      x -= vals[i];\r\
    \n      if (x < 0) x += mod;\r\n    }\r\n    reverse(all(res));\r\n    return\
    \ res;\r\n  }\r\n};\r\n"
  dependsOn:
  - alg/monoid_rollinghash.hpp
  - mod/modint61.hpp
  - other/random.hpp
  - ds/segtree.hpp
  isVerificationFile: false
  path: mod/modular_subset_sum.hpp
  requiredBy: []
  timestamp: '2022-04-16 04:26:49+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yukicoder/4_modular_subset_sum.test.cpp
documentation_of: mod/modular_subset_sum.hpp
layout: document
redirect_from:
- /library/mod/modular_subset_sum.hpp
- /library/mod/modular_subset_sum.hpp.html
title: mod/modular_subset_sum.hpp
---
