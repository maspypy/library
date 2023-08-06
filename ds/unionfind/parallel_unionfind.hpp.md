---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: mod/modint61.hpp
    title: mod/modint61.hpp
  - icon: ':heavy_check_mark:'
    path: random/base.hpp
    title: random/base.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"mod/modint61.hpp\"\n\r\nstruct modint61 {\r\n  static constexpr\
    \ u64 mod = (1ULL << 61) - 1;\r\n  u64 val;\r\n  constexpr modint61() : val(0ULL)\
    \ {}\r\n  constexpr modint61(u32 x) : val(x) {}\r\n  constexpr modint61(u64 x)\
    \ : val(x % mod) {}\r\n  constexpr modint61(int x) : val((x < 0) ? (x + static_cast<ll>(mod))\
    \ : x) {}\r\n  constexpr modint61(ll x)\r\n      : val(((x %= static_cast<ll>(mod))\
    \ < 0) ? (x + static_cast<ll>(mod))\r\n                                      \
    \        : x) {}\r\n  static constexpr u64 get_mod() { return mod; }\r\n  modint61\
    \ &operator+=(const modint61 &a) {\r\n    val = ((val += a.val) >= mod) ? (val\
    \ - mod) : val;\r\n    return *this;\r\n  }\r\n  modint61 &operator-=(const modint61\
    \ &a) {\r\n    val = ((val -= a.val) >= mod) ? (val + mod) : val;\r\n    return\
    \ *this;\r\n  }\r\n  modint61 &operator*=(const modint61 &a) {\r\n    const unsigned\
    \ __int128 y = static_cast<unsigned __int128>(val) * a.val;\r\n    val = (y >>\
    \ 61) + (y & mod);\r\n    val = (val >= mod) ? (val - mod) : val;\r\n    return\
    \ *this;\r\n  }\r\n  modint61 &operator/=(const modint61 &a) { return (*this *=\
    \ a.inverse()); }\r\n  modint61 operator+(const modint61 &p) const { return modint61(*this)\
    \ += p; }\r\n  modint61 operator-(const modint61 &p) const { return modint61(*this)\
    \ -= p; }\r\n  modint61 operator*(const modint61 &p) const { return modint61(*this)\
    \ *= p; }\r\n  modint61 operator/(const modint61 &p) const { return modint61(*this)\
    \ /= p; }\r\n  bool operator==(const modint61 &p) const { return val == p.val;\
    \ }\r\n  bool operator!=(const modint61 &p) const { return val != p.val; }\r\n\
    \  modint61 inverse() const {\r\n    ll a = val, b = mod, u = 1, v = 0, t;\r\n\
    \    while (b > 0) {\r\n      t = a / b;\r\n      swap(a -= t * b, b), swap(u\
    \ -= t * v, v);\r\n    }\r\n    return modint61(u);\r\n  }\r\n  modint61 pow(ll\
    \ n) const {\r\n    assert(n >= 0);\r\n    modint61 ret(1), mul(val);\r\n    while\
    \ (n > 0) {\r\n      if (n & 1) ret *= mul;\r\n      mul *= mul, n >>= 1;\r\n\
    \    }\r\n    return ret;\r\n  }\r\n#ifdef FASTIO\r\n  void write() { fastio::printer.write(val);\
    \ }\r\n  void read() {\r\n    ll x;\r\n    fastio::scanner.read(x);\r\n    val\
    \ = (val >= 0 ? val % mod : (mod - (-val) % mod) % mod);\r\n  }\r\n#endif\r\n\
    };\n#line 2 \"random/base.hpp\"\n\nu64 RNG_64() {\n  static uint64_t x_\n    \
    \  = uint64_t(chrono::duration_cast<chrono::nanoseconds>(\n                  \
    \   chrono::high_resolution_clock::now().time_since_epoch())\n               \
    \      .count())\n        * 10150724397891781847ULL;\n  x_ ^= x_ << 7;\n  return\
    \ x_ ^= x_ >> 9;\n}\n\nu64 RNG(u64 lim) { return RNG_64() % lim; }\n\nll RNG(ll\
    \ l, ll r) { return l + RNG_64() % (r - l); }\n#line 3 \"ds/unionfind/parallel_unionfind.hpp\"\
    \n\nstruct Parallel_UnionFind {\n  int n, log;\n  using mint = modint61;\n  vc<mint>\
    \ seg;\n  vc<mint> pow;\n  mint base;\n  vc<int> dat;\n  vc<int> nxt;\n\n  Parallel_UnionFind(int\
    \ n) : n(n), dat(n, -1), nxt(n, -1) {\n    log = 1;\n    while ((1 << log) < n)\
    \ ++log;\n    base = RNG(mint::get_mod());\n    pow.resize(1 << log);\n    pow[0]\
    \ = 1;\n    FOR(i, (1 << log) - 1) pow[i + 1] = pow[i] * base;\n    seg.resize(2\
    \ << log);\n    FOR(i, n) seg[i + (1 << log)] = i;\n    FOR_R(i, 1, (1 << log))\
    \ update(i);\n  }\n\n  int operator[](int x) { return (dat[x] < 0 ? x : dat[x]);\
    \ }\n  int size(int x) {\n    assert(dat[x] < 0);\n    return -dat[x];\n  }\n\n\
    \  // unite [a,b) [c,d).\n  // f(v, y, x): root(v) = y -> root(v) = x\n  template\
    \ <typename F>\n  void merge(\n      int a, int b, int c, int d, F f = [](int\
    \ v, int y, int x) -> void {}) {\n    assert(0 <= a && a <= b && b <= n);\n  \
    \  assert(0 <= c && c <= d && d <= n);\n    assert(b - a == d - c);\n    while\
    \ (1) {\n      if (get(a, b) == get(c, d)) break;\n      int n = binary_search(\n\
    \          [&](int k) -> bool { return get(a, a + k) == get(c, c + k); }, 0,\n\
    \          b - a, false);\n      int x = (*this)[a + n], y = (*this)[c + n];\n\
    \      a += n, c += n;\n      if (size(x) < size(y)) swap(x, y);\n      // \u6210\
    \u5206 y \u3092\u6210\u5206 x \u306B\u30DE\u30FC\u30B8\n      while (nxt[y] !=\
    \ -1) {\n        int v = nxt[y];\n        nxt[y] = nxt[v];\n        set(v, x),\
    \ f(v, y, x);\n        dat[v] = x, dat[x] -= 1, nxt[v] = nxt[x], nxt[x] = v;\n\
    \      }\n      set(y, x), f(y, y, x);\n      dat[y] = x, dat[x] -= 1, nxt[y]\
    \ = nxt[x], nxt[x] = y;\n    }\n  }\n\n  template <typename F>\n  void merge(\n\
    \      int a, int b, F f = [](int v, int y, int x) -> void {}) {\n    merge(a,\
    \ a + 1, b, b + 1, f);\n  }\n\nprivate:\n  void update(int i) {\n    int sz =\
    \ 1 << (log - topbit(i) - 1);\n    seg[i] = seg[2 * i] * pow[sz] + seg[2 * i +\
    \ 1];\n  }\n\n  void set(int i, mint x) {\n    assert(i < n);\n    seg[i += (1\
    \ << log)] = x;\n    while (i >>= 1) update(i);\n  }\n\n  mint get(int L, int\
    \ R) {\n    assert(0 <= L && L <= R && R <= n);\n    mint xl = 0, xr = 0;\n  \
    \  int sl = 0, sr = 0;\n    L += (1 << log), R += (1 << log);\n    int s = 1;\n\
    \    while (L < R) {\n      if (L & 1) { xl = xl * pow[s] + seg[L++], sl += s;\
    \ }\n      if (R & 1) { xr = seg[--R] * pow[sr] + xr, sr += s; }\n      L >>=\
    \ 1, R >>= 1, s <<= 1;\n    }\n    return xl * pow[sr] + xr;\n  }\n};\n"
  code: "#include \"mod/modint61.hpp\"\n#include \"random/base.hpp\"\n\nstruct Parallel_UnionFind\
    \ {\n  int n, log;\n  using mint = modint61;\n  vc<mint> seg;\n  vc<mint> pow;\n\
    \  mint base;\n  vc<int> dat;\n  vc<int> nxt;\n\n  Parallel_UnionFind(int n) :\
    \ n(n), dat(n, -1), nxt(n, -1) {\n    log = 1;\n    while ((1 << log) < n) ++log;\n\
    \    base = RNG(mint::get_mod());\n    pow.resize(1 << log);\n    pow[0] = 1;\n\
    \    FOR(i, (1 << log) - 1) pow[i + 1] = pow[i] * base;\n    seg.resize(2 << log);\n\
    \    FOR(i, n) seg[i + (1 << log)] = i;\n    FOR_R(i, 1, (1 << log)) update(i);\n\
    \  }\n\n  int operator[](int x) { return (dat[x] < 0 ? x : dat[x]); }\n  int size(int\
    \ x) {\n    assert(dat[x] < 0);\n    return -dat[x];\n  }\n\n  // unite [a,b)\
    \ [c,d).\n  // f(v, y, x): root(v) = y -> root(v) = x\n  template <typename F>\n\
    \  void merge(\n      int a, int b, int c, int d, F f = [](int v, int y, int x)\
    \ -> void {}) {\n    assert(0 <= a && a <= b && b <= n);\n    assert(0 <= c &&\
    \ c <= d && d <= n);\n    assert(b - a == d - c);\n    while (1) {\n      if (get(a,\
    \ b) == get(c, d)) break;\n      int n = binary_search(\n          [&](int k)\
    \ -> bool { return get(a, a + k) == get(c, c + k); }, 0,\n          b - a, false);\n\
    \      int x = (*this)[a + n], y = (*this)[c + n];\n      a += n, c += n;\n  \
    \    if (size(x) < size(y)) swap(x, y);\n      // \u6210\u5206 y \u3092\u6210\u5206\
    \ x \u306B\u30DE\u30FC\u30B8\n      while (nxt[y] != -1) {\n        int v = nxt[y];\n\
    \        nxt[y] = nxt[v];\n        set(v, x), f(v, y, x);\n        dat[v] = x,\
    \ dat[x] -= 1, nxt[v] = nxt[x], nxt[x] = v;\n      }\n      set(y, x), f(y, y,\
    \ x);\n      dat[y] = x, dat[x] -= 1, nxt[y] = nxt[x], nxt[x] = y;\n    }\n  }\n\
    \n  template <typename F>\n  void merge(\n      int a, int b, F f = [](int v,\
    \ int y, int x) -> void {}) {\n    merge(a, a + 1, b, b + 1, f);\n  }\n\nprivate:\n\
    \  void update(int i) {\n    int sz = 1 << (log - topbit(i) - 1);\n    seg[i]\
    \ = seg[2 * i] * pow[sz] + seg[2 * i + 1];\n  }\n\n  void set(int i, mint x) {\n\
    \    assert(i < n);\n    seg[i += (1 << log)] = x;\n    while (i >>= 1) update(i);\n\
    \  }\n\n  mint get(int L, int R) {\n    assert(0 <= L && L <= R && R <= n);\n\
    \    mint xl = 0, xr = 0;\n    int sl = 0, sr = 0;\n    L += (1 << log), R +=\
    \ (1 << log);\n    int s = 1;\n    while (L < R) {\n      if (L & 1) { xl = xl\
    \ * pow[s] + seg[L++], sl += s; }\n      if (R & 1) { xr = seg[--R] * pow[sr]\
    \ + xr, sr += s; }\n      L >>= 1, R >>= 1, s <<= 1;\n    }\n    return xl * pow[sr]\
    \ + xr;\n  }\n};\n"
  dependsOn:
  - mod/modint61.hpp
  - random/base.hpp
  isVerificationFile: false
  path: ds/unionfind/parallel_unionfind.hpp
  requiredBy: []
  timestamp: '2023-07-28 03:32:38+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: ds/unionfind/parallel_unionfind.hpp
layout: document
redirect_from:
- /library/ds/unionfind/parallel_unionfind.hpp
- /library/ds/unionfind/parallel_unionfind.hpp.html
title: ds/unionfind/parallel_unionfind.hpp
---
