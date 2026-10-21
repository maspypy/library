---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: mod/barrett.hpp
    title: mod/barrett.hpp
  - icon: ':question:'
    path: mod/mod_pow.hpp
    title: mod/mod_pow.hpp
  - icon: ':question:'
    path: mod/montgomery_modint.hpp
    title: mod/montgomery_modint.hpp
  - icon: ':question:'
    path: nt/factor.hpp
    title: nt/factor.hpp
  - icon: ':question:'
    path: nt/is_prime.hpp
    title: nt/is_prime.hpp
  - icon: ':question:'
    path: random/base.hpp
    title: random/base.hpp
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: nt/four_square.hpp
    title: nt/four_square.hpp
  - icon: ':heavy_check_mark:'
    path: nt/three_square.hpp
    title: nt/three_square.hpp
  - icon: ':heavy_check_mark:'
    path: nt/three_triangular.hpp
    title: nt/three_triangular.hpp
  - icon: ':heavy_check_mark:'
    path: nt/two_square.hpp
    title: nt/two_square.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/1_mytest/four_square.test.cpp
    title: test/1_mytest/four_square.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/1_mytest/three_square.test.cpp
    title: test/1_mytest/three_square.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/1_mytest/three_triangular.test.cpp
    title: test/1_mytest/three_triangular.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/2_library_checker/number_theory/gaussian_integers.test.cpp
    title: test/2_library_checker/number_theory/gaussian_integers.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/2_library_checker/number_theory/two_square.test.cpp
    title: test/2_library_checker/number_theory/two_square.test.cpp
  - icon: ':x:'
    path: test/3_yukicoder/1593.test.cpp
    title: test/3_yukicoder/1593.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
  attributes:
    links:
    - https://github.com/maspypy/library/blob/main/nt/gaussian_integers.hpp
  bundledCode: "#line 1 \"nt/gaussian_integers.hpp\"\n// Source: https://github.com/maspypy/library/blob/main/nt/gaussian_integers.hpp\n\
    #line 1 \"nt/factor.hpp\"\n// Source: https://github.com/maspypy/library/blob/main/nt/factor.hpp\n\
    \n#line 1 \"random/base.hpp\"\n// Source: https://github.com/maspypy/library/blob/main/random/base.hpp\n\
    \nu64 RNG_64() {\n  static u64 x_ = u64(chrono::duration_cast<chrono::nanoseconds>(\n\
    \                      chrono::high_resolution_clock::now().time_since_epoch())\n\
    \                          .count()) *\n                  10150724397891781847ULL;\n\
    \  x_ ^= x_ << 7;\n  return x_ ^= x_ >> 9;\n}\n\nu64 RNG(u64 lim) {\n  assert(lim\
    \ > 0);\n  return RNG_64() % lim;\n}\n\nll RNG(ll l, ll r) {\n  assert(l < r);\n\
    \  return l + RNG_64() % (r - l);\n}\n#line 1 \"nt/is_prime.hpp\"\n// Source:\
    \ https://github.com/maspypy/library/blob/main/nt/is_prime.hpp\n#line 1 \"mod/montgomery_modint.hpp\"\
    \n// Source: https://github.com/maspypy/library/blob/main/mod/montgomery_modint.hpp\n\
    \n// odd mod.\n// x \u306E\u4EE3\u308F\u308A\u306B rx \u3092\u6301\u3064\ntemplate\
    \ <int id, typename U1, typename U2>\nstruct Montgomery_modint {\n  using mint\
    \ = Montgomery_modint;\n  inline static U1 m, r, n2;\n  static constexpr int W\
    \ = numeric_limits<U1>::digits;\n\n  static void set_mod(U1 mod) {\n    assert(mod\
    \ & 1 && mod <= U1(1) << (W - 2));\n    m = mod, n2 = -U2(m) % m, r = m;\n   \
    \ FOR(6) r *= 2 - m * r;\n    r = -r;\n    assert(r * m == U1(-1));\n  }\n  static\
    \ U1 reduce(U2 b) { return (b + U2(U1(b) * r) * m) >> W; }\n\n  U1 x;\n  Montgomery_modint()\
    \ : x(0) {}\n  Montgomery_modint(U1 x) : x(reduce(U2(x) * n2)){};\n  U1 val()\
    \ const {\n    U1 y = reduce(x);\n    return y >= m ? y - m : y;\n  }\n  mint\
    \ &operator+=(mint y) {\n    x = ((x += y.x) >= m ? x - m : x);\n    return *this;\n\
    \  }\n  mint &operator-=(mint y) {\n    x -= (x >= y.x ? y.x : y.x - m);\n   \
    \ return *this;\n  }\n  mint &operator*=(mint y) {\n    x = reduce(U2(x) * y.x);\n\
    \    return *this;\n  }\n  mint operator+(mint y) const { return mint(*this) +=\
    \ y; }\n  mint operator-(mint y) const { return mint(*this) -= y; }\n  mint operator*(mint\
    \ y) const { return mint(*this) *= y; }\n  bool operator==(mint y) const {\n \
    \   return (x >= m ? x - m : x) == (y.x >= m ? y.x - m : y.x);\n  }\n  bool operator!=(mint\
    \ y) const { return not operator==(y); }\n  mint pow(ll n) const {\n    assert(n\
    \ >= 0);\n    mint y = 1, z = *this;\n    for (; n; n >>= 1, z *= z)\n      if\
    \ (n & 1) y *= z;\n    return y;\n  }\n};\n\ntemplate <int id>\nusing Montgomery_modint_32\
    \ = Montgomery_modint<id, u32, u64>;\ntemplate <int id>\nusing Montgomery_modint_64\
    \ = Montgomery_modint<id, u64, u128>;\n#line 3 \"nt/is_prime.hpp\"\n\nbool is_prime(const\
    \ u64 x) {\n  assert(x < u64(1) << 62);\n  if (x == 2 or x == 3 or x == 5 or x\
    \ == 7) return true;\n  if (x % 2 == 0 or x % 3 == 0 or x % 5 == 0 or x % 7 ==\
    \ 0) return false;\n  if (x < 121) return x > 1;\n  const u64 d = (x - 1) >> lowbit(x\
    \ - 1);\n\n  using mint = Montgomery_modint_64<202311020>;\n\n  mint::set_mod(x);\n\
    \  const mint one(u64(1)), minus_one(x - 1);\n  auto ok = [&](u64 a) -> bool {\n\
    \    auto y = mint(a).pow(d);\n    u64 t = d;\n    while (y != one && y != minus_one\
    \ && t != x - 1) y *= y, t <<= 1;\n    if (y != minus_one && t % 2 == 0) return\
    \ false;\n    return true;\n  };\n  if (x < (u64(1) << 32)) {\n    for (u64 a\
    \ : {2, 7, 61})\n      if (!ok(a)) return false;\n  } else {\n    for (u64 a :\
    \ {2, 325, 9375, 28178, 450775, 9780504, 1795265022}) {\n      if (!ok(a)) return\
    \ false;\n    }\n  }\n  return true;\n}\n#line 5 \"nt/factor.hpp\"\n\ntemplate\
    \ <typename mint>\nll rho(ll n, ll c) {\n  assert(n > 1);\n  const mint cc(c);\n\
    \  auto f = [&](mint x) { return x * x + cc; };\n  mint x = 1, y = 2, z = 1, q\
    \ = 1;\n  ll g = 1;\n  const ll m = 1LL << (__lg(n) / 5);\n  for (ll r = 1; g\
    \ == 1; r <<= 1) {\n    x = y;\n    FOR(r) y = f(y);\n    for (ll k = 0; k < r\
    \ && g == 1; k += m) {\n      z = y;\n      FOR(min(m, r - k)) y = f(y), q *=\
    \ x - y;\n      g = gcd(q.val(), n);\n    }\n  }\n  if (g == n) do {\n      z\
    \ = f(z);\n      g = gcd((x - z).val(), n);\n    } while (g == 1);\n  return g;\n\
    }\n\nll find_prime_factor(ll n) {\n  assert(1 < n && n < (1LL << 62));\n  if (n\
    \ % 2 == 0) return 2;\n  if (is_prime(n)) return n;\n  FOR(100) {\n    ll m =\
    \ 0;\n    if (n < (1 << 30)) {\n      using mint = Montgomery_modint_32<20231025>;\n\
    \      mint::set_mod(n);\n      m = rho<mint>(n, RNG(0, n));\n    } else {\n \
    \     using mint = Montgomery_modint_64<20231025>;\n      mint::set_mod(n);\n\
    \      m = rho<mint>(n, RNG(0, n));\n    }\n    if (is_prime(m)) return m;\n \
    \   n = m;\n  }\n  assert(0);\n  return -1;\n}\n\n// \u30BD\u30FC\u30C8\u3057\u3066\
    \u304F\u308C\u308B\nvc<pair<ll, int>> factor(ll n) {\n  assert(1 <= n && n < (1LL\
    \ << 62));\n  vc<pair<ll, int>> pf;\n  FOR(p, 2, 100) {\n    if (p * p > n) break;\n\
    \    if (n % p == 0) {\n      ll e = 0;\n      do {\n        n /= p, e += 1;\n\
    \      } while (n % p == 0);\n      pf.eb(p, e);\n    }\n  }\n  while (n > 1)\
    \ {\n    ll p = find_prime_factor(n);\n    ll e = 0;\n    do {\n      n /= p,\
    \ e += 1;\n    } while (n % p == 0);\n    pf.eb(p, e);\n  }\n  sort(all(pf));\n\
    \  return pf;\n}\n\nvc<pair<ll, int>> factor_by_spf(ll n, vc<int>& spf) {\n  vc<pair<ll,\
    \ int>> res;\n  while (n > 1) {\n    int p = spf[n];\n    int e = 0;\n    while\
    \ (n % p == 0) {\n      n /= p;\n      ++e;\n    }\n    res.eb(p, e);\n  }\n \
    \ return res;\n}\n#line 1 \"mod/mod_pow.hpp\"\n// Source: https://github.com/maspypy/library/blob/main/mod/mod_pow.hpp\n\
    \n#line 1 \"mod/montgomery_modint.hpp\"\n// Source: https://github.com/maspypy/library/blob/main/mod/montgomery_modint.hpp\n\
    \n// odd mod.\n// x \u306E\u4EE3\u308F\u308A\u306B rx \u3092\u6301\u3064\ntemplate\
    \ <int id, typename U1, typename U2>\nstruct Montgomery_modint {\n  using mint\
    \ = Montgomery_modint;\n  inline static U1 m, r, n2;\n  static constexpr int W\
    \ = numeric_limits<U1>::digits;\n\n  static void set_mod(U1 mod) {\n    assert(mod\
    \ & 1 && mod <= U1(1) << (W - 2));\n    m = mod, n2 = -U2(m) % m, r = m;\n   \
    \ FOR(6) r *= 2 - m * r;\n    r = -r;\n    assert(r * m == U1(-1));\n  }\n  static\
    \ U1 reduce(U2 b) { return (b + U2(U1(b) * r) * m) >> W; }\n\n  U1 x;\n  Montgomery_modint()\
    \ : x(0) {}\n  Montgomery_modint(U1 x) : x(reduce(U2(x) * n2)){};\n  U1 val()\
    \ const {\n    U1 y = reduce(x);\n    return y >= m ? y - m : y;\n  }\n  mint\
    \ &operator+=(mint y) {\n    x = ((x += y.x) >= m ? x - m : x);\n    return *this;\n\
    \  }\n  mint &operator-=(mint y) {\n    x -= (x >= y.x ? y.x : y.x - m);\n   \
    \ return *this;\n  }\n  mint &operator*=(mint y) {\n    x = reduce(U2(x) * y.x);\n\
    \    return *this;\n  }\n  mint operator+(mint y) const { return mint(*this) +=\
    \ y; }\n  mint operator-(mint y) const { return mint(*this) -= y; }\n  mint operator*(mint\
    \ y) const { return mint(*this) *= y; }\n  bool operator==(mint y) const {\n \
    \   return (x >= m ? x - m : x) == (y.x >= m ? y.x - m : y.x);\n  }\n  bool operator!=(mint\
    \ y) const { return not operator==(y); }\n  mint pow(ll n) const {\n    assert(n\
    \ >= 0);\n    mint y = 1, z = *this;\n    for (; n; n >>= 1, z *= z)\n      if\
    \ (n & 1) y *= z;\n    return y;\n  }\n};\n\ntemplate <int id>\nusing Montgomery_modint_32\
    \ = Montgomery_modint<id, u32, u64>;\ntemplate <int id>\nusing Montgomery_modint_64\
    \ = Montgomery_modint<id, u64, u128>;\n#line 1 \"mod/barrett.hpp\"\n// Source:\
    \ https://github.com/maspypy/library/blob/main/mod/barrett.hpp\n\n// https://github.com/atcoder/ac-library/blob/master/atcoder/internal_math.hpp\n\
    struct Barrett {\n  u32 m;\n  u64 im;\n  explicit Barrett(u32 m = 1) : m(m), im(u64(-1)\
    \ / m + 1) {}\n  u32 umod() const { return m; }\n  u32 modulo(u64 z) {\n    if\
    \ (m == 1) return 0;\n    u64 x = (u64)(((unsigned __int128)(z)*im) >> 64);\n\
    \    u64 y = x * m;\n    return (z - y + (z < y ? m : 0));\n  }\n  u64 floor(u64\
    \ z) {\n    if (m == 1) return z;\n    u64 x = (u64)(((unsigned __int128)(z)*im)\
    \ >> 64);\n    u64 y = x * m;\n    return (z < y ? x - 1 : x);\n  }\n  pair<u64,\
    \ u32> divmod(u64 z) {\n    if (m == 1) return {z, 0};\n    u64 x = (u64)(((unsigned\
    \ __int128)(z)*im) >> 64);\n    u64 y = x * m;\n    if (z < y) return {x - 1,\
    \ z - y + m};\n    return {x, z - y};\n  }\n  u32 mul(u32 a, u32 b) { return modulo(u64(a)\
    \ * b); }\n};\n\nstruct Barrett_64 {\n  u128 mod, mh, ml;\n\n  explicit Barrett_64(u64\
    \ mod = 1) : mod(mod) {\n    u128 m = u128(-1) / mod;\n    if (m * mod + mod ==\
    \ u128(0)) ++m;\n    mh = m >> 64;\n    ml = m & u64(-1);\n  }\n\n  u64 umod()\
    \ const { return mod; }\n\n  u64 modulo(u128 x) {\n    u128 z = (x & u64(-1))\
    \ * ml;\n    z = (x & u64(-1)) * mh + (x >> 64) * ml + (z >> 64);\n    z = (x\
    \ >> 64) * mh + (z >> 64);\n    x -= z * mod;\n    return x < mod ? x : x - mod;\n\
    \  }\n\n  u64 mul(u64 a, u64 b) { return modulo(u128(a) * b); }\n};\n#line 5 \"\
    mod/mod_pow.hpp\"\n\nu32 mod_pow(int a, ll n, int mod) {\n  assert(n >= 0);\n\
    \  if (mod == 1) return 0;\n  a = ((a %= mod) < 0 ? a + mod : a);\n  if ((mod\
    \ & 1) && (mod < (1 << 30))) {\n    using mint = Montgomery_modint_32<202311021>;\n\
    \    mint::set_mod(mod);\n    return mint(a).pow(n).val();\n  }\n  Barrett bt(mod);\n\
    \  int r = 1;\n  while (n) {\n    if (n & 1) r = bt.mul(r, a);\n    a = bt.mul(a,\
    \ a), n >>= 1;\n  }\n  return r;\n}\n\nu64 mod_pow_64(ll a, ll n, u64 mod) {\n\
    \  assert(n >= 0);\n  if (mod == 1) return 0;\n  a = ((a %= mod) < 0 ? a + mod\
    \ : a);\n  if ((mod & 1) && (mod < (u64(1) << 62))) {\n    using mint = Montgomery_modint_64<202311021>;\n\
    \    mint::set_mod(mod);\n    return mint(a).pow(n).val();\n  }\n  Barrett_64\
    \ bt(mod);\n  ll r = 1;\n  while (n) {\n    if (n & 1) r = bt.mul(r, a);\n   \
    \ a = bt.mul(a, a), n >>= 1;\n  }\n  return r;\n}\n#line 4 \"nt/gaussian_integers.hpp\"\
    \n\ntemplate <typename T>\nstruct Gaussian_Integer {\n  T x, y;\n  using G = Gaussian_Integer;\n\
    \n  Gaussian_Integer(T x = 0, T y = 0) : x(x), y(y) {}\n  Gaussian_Integer(pair<T,\
    \ T> p) : x(p.fi), y(p.se) {}\n\n  T norm() const { return x * x + y * y; }\n\
    \  G conjugate() const { return G(x, -y); }\n\n  // \u66AB\u5B9A\u7684\u306B\n\
    \  bool operator<(const G &other) const {\n    if (x != other.x) return x < other.x;\n\
    \    return y < other.y;\n  }\n\n  G &operator+=(const G &g) {\n    x += g.x,\
    \ y += g.y;\n    return *this;\n  }\n  G &operator-=(const G &g) {\n    x -= g.x,\
    \ y -= g.y;\n    return *this;\n  }\n  G &operator*=(const G &g) {\n    tie(x,\
    \ y) = mp(x * g.x - y * g.y, x * g.y + y * g.x);\n    return *this;\n  }\n  G\
    \ &operator/=(const G &g) {\n    *this *= g.conjugate();\n    T n = g.norm();\n\
    \    x = floor(x + n / 2, n);\n    y = floor(y + n / 2, n);\n    return *this;\n\
    \  }\n  G &operator%=(const G &g) {\n    auto q = G(*this) / g;\n    q *= g;\n\
    \    (*this) -= q;\n    return *this;\n  }\n  G operator-() { return G(-x, -y);\
    \ }\n  G operator+(const G &g) const { return G(*this) += g; }\n  G operator-(const\
    \ G &g) const { return G(*this) -= g; }\n  G operator*(const G &g) const { return\
    \ G(*this) *= g; }\n  G operator/(const G &g) const { return G(*this) /= g; }\n\
    \  G operator%(const G &g) const { return G(*this) %= g; }\n  bool operator==(const\
    \ G &g) { return (x == g.x && y == g.y); }\n\n  static G gcd(G a, G b) {\n   \
    \ while (b.x != 0 || b.y != 0) {\n      a %= b;\n      swap(a, b);\n    }\n  \
    \  return a;\n  }\n\n  G pow(ll n) const {\n    assert(n >= 0);\n    G ret(1),\
    \ mul(*this);\n    while (n > 0) {\n      if (n & 1) ret *= mul;\n      mul *=\
    \ mul;\n      n >>= 1;\n    }\n    return ret;\n  }\n\n  // (g,x,y) s.t ax+by=g\n\
    \  static tuple<G, G, G> ext_gcd(G a, G b) {\n    if (b.x != 0 || b.y != 0) {\n\
    \      G q = a / b;\n      auto [g, x, y] = ext_gcd(b, a - q * b);\n      return\
    \ {g, y, x - q * y};\n    }\n    return {a, G{1, 0}, G{0, 0}};\n  }\n};\n\npair<ll,\
    \ ll> solve_norm_equation_prime(ll p) {\n  using G = Gaussian_Integer<i128>;\n\
    \  assert(p == 2 || p % 4 == 1);\n  if (p == 2) return {1, 1};\n  ll x = [&]()\
    \ -> ll {\n    ll x = 1;\n    while (1) {\n      ++x;\n      ll pow_x = 1;\n \
    \     if (p < (1 << 30)) {\n        pow_x = mod_pow(x, (p - 1) / 4, p);\n    \
    \    if (pow_x * pow_x % p == p - 1) return pow_x;\n      } else {\n        pow_x\
    \ = mod_pow_64(x, (p - 1) / 4, p);\n        if (i128(pow_x) * pow_x % p == p -\
    \ 1) return pow_x;\n      }\n    }\n    return -1;\n  }();\n  G a(p, 0), b(x,\
    \ 1);\n  a = G::gcd(a, b);\n  assert(a.norm() == p);\n  return {a.x, a.y};\n}\n\
    \ntemplate <typename T>\nvc<Gaussian_Integer<T>> solve_norm_equation_factor(vc<pair<ll,\
    \ int>> pfs) {\n  using G = Gaussian_Integer<T>;\n  vc<G> res;\n  for (auto &&[p,\
    \ e] : pfs) {\n    if (p % 4 == 3 && e % 2 == 1) return {};\n  }\n\n  res.eb(G(1,\
    \ 0));\n  for (auto &&[p, e] : pfs) {\n    if (p % 4 == 3) {\n      T pp = 1;\n\
    \      FOR(e / 2) pp *= p;\n      for (auto &&g : res) {\n        g.x *= pp;\n\
    \        g.y *= pp;\n      }\n      continue;\n    }\n    auto [pix, piy] = solve_norm_equation_prime(p);\n\
    \    G pi(pix, piy);\n    vc<G> pows(e + 1);\n    pows[0] = G(1, 0);\n    FOR(i,\
    \ e) pows[i + 1] = pows[i] * pi;\n    if (p == 2) {\n      for (auto &&g : res)\
    \ g *= pows[e];\n      continue;\n    }\n    vc<G> pis(e + 1);\n    FOR(j, e +\
    \ 1) { pis[j] = pows[j] * (pows[e - j].conjugate()); }\n    vc<G> new_res;\n \
    \   new_res.reserve(len(res) * (e + 1));\n    for (auto &&g : res) {\n      for\
    \ (auto &&a : pis) {\n        new_res.eb(g * a);\n      }\n    }\n    swap(res,\
    \ new_res);\n  }\n\n  for (auto &&g : res) {\n    while (g.x <= 0 || g.y < 0)\
    \ {\n      g = G(-g.y, g.x);\n    }\n  }\n  return res;\n}\n\n// i128 \u3092\u4F7F\
    \u3046\u3068 N <= 10^{18} \u3082\u3067\u304D\u308B\n// \u30CE\u30EB\u30E0\u304C\
    \u3068\u308C\u308B\u3088\u3046\u306B\u30012 \u4E57\u3057\u3066\u3082\u30AA\u30FC\
    \u30D0\u30FC\u30D5\u30ED\u30FC\u3057\u306A\u3044\u578B\u3092\u4F7F\u304A\u3046\
    \n// 0 <= arg < 90 \u3068\u306A\u308B\u3082\u306E\u306E\u307F\u8FD4\u3059\u3002\
    \n// \u5358\u6570\u500D\u306F\u4F5C\u3089\u306A\u3044\u306E\u3067\u3001\u4F7F\u3046\
    \u3068\u304D\u306B\u6C17\u3092\u4ED8\u3051\u308B\u3002\ntemplate <typename T>\n\
    vc<Gaussian_Integer<T>> solve_norm_equation(T N) {\n  using G = Gaussian_Integer<T>;\n\
    \  vc<G> res;\n  if (N < 0) return {};\n  if (N == 0) {\n    res.eb(G(0, 0));\n\
    \    return res;\n  }\n  auto pfs = factor(N);\n  return solve_norm_equation_factor<T>(pfs);\n\
    }\n"
  code: "// Source: https://github.com/maspypy/library/blob/main/nt/gaussian_integers.hpp\n\
    #include \"nt/factor.hpp\"\n#include \"mod/mod_pow.hpp\"\n\ntemplate <typename\
    \ T>\nstruct Gaussian_Integer {\n  T x, y;\n  using G = Gaussian_Integer;\n\n\
    \  Gaussian_Integer(T x = 0, T y = 0) : x(x), y(y) {}\n  Gaussian_Integer(pair<T,\
    \ T> p) : x(p.fi), y(p.se) {}\n\n  T norm() const { return x * x + y * y; }\n\
    \  G conjugate() const { return G(x, -y); }\n\n  // \u66AB\u5B9A\u7684\u306B\n\
    \  bool operator<(const G &other) const {\n    if (x != other.x) return x < other.x;\n\
    \    return y < other.y;\n  }\n\n  G &operator+=(const G &g) {\n    x += g.x,\
    \ y += g.y;\n    return *this;\n  }\n  G &operator-=(const G &g) {\n    x -= g.x,\
    \ y -= g.y;\n    return *this;\n  }\n  G &operator*=(const G &g) {\n    tie(x,\
    \ y) = mp(x * g.x - y * g.y, x * g.y + y * g.x);\n    return *this;\n  }\n  G\
    \ &operator/=(const G &g) {\n    *this *= g.conjugate();\n    T n = g.norm();\n\
    \    x = floor(x + n / 2, n);\n    y = floor(y + n / 2, n);\n    return *this;\n\
    \  }\n  G &operator%=(const G &g) {\n    auto q = G(*this) / g;\n    q *= g;\n\
    \    (*this) -= q;\n    return *this;\n  }\n  G operator-() { return G(-x, -y);\
    \ }\n  G operator+(const G &g) const { return G(*this) += g; }\n  G operator-(const\
    \ G &g) const { return G(*this) -= g; }\n  G operator*(const G &g) const { return\
    \ G(*this) *= g; }\n  G operator/(const G &g) const { return G(*this) /= g; }\n\
    \  G operator%(const G &g) const { return G(*this) %= g; }\n  bool operator==(const\
    \ G &g) { return (x == g.x && y == g.y); }\n\n  static G gcd(G a, G b) {\n   \
    \ while (b.x != 0 || b.y != 0) {\n      a %= b;\n      swap(a, b);\n    }\n  \
    \  return a;\n  }\n\n  G pow(ll n) const {\n    assert(n >= 0);\n    G ret(1),\
    \ mul(*this);\n    while (n > 0) {\n      if (n & 1) ret *= mul;\n      mul *=\
    \ mul;\n      n >>= 1;\n    }\n    return ret;\n  }\n\n  // (g,x,y) s.t ax+by=g\n\
    \  static tuple<G, G, G> ext_gcd(G a, G b) {\n    if (b.x != 0 || b.y != 0) {\n\
    \      G q = a / b;\n      auto [g, x, y] = ext_gcd(b, a - q * b);\n      return\
    \ {g, y, x - q * y};\n    }\n    return {a, G{1, 0}, G{0, 0}};\n  }\n};\n\npair<ll,\
    \ ll> solve_norm_equation_prime(ll p) {\n  using G = Gaussian_Integer<i128>;\n\
    \  assert(p == 2 || p % 4 == 1);\n  if (p == 2) return {1, 1};\n  ll x = [&]()\
    \ -> ll {\n    ll x = 1;\n    while (1) {\n      ++x;\n      ll pow_x = 1;\n \
    \     if (p < (1 << 30)) {\n        pow_x = mod_pow(x, (p - 1) / 4, p);\n    \
    \    if (pow_x * pow_x % p == p - 1) return pow_x;\n      } else {\n        pow_x\
    \ = mod_pow_64(x, (p - 1) / 4, p);\n        if (i128(pow_x) * pow_x % p == p -\
    \ 1) return pow_x;\n      }\n    }\n    return -1;\n  }();\n  G a(p, 0), b(x,\
    \ 1);\n  a = G::gcd(a, b);\n  assert(a.norm() == p);\n  return {a.x, a.y};\n}\n\
    \ntemplate <typename T>\nvc<Gaussian_Integer<T>> solve_norm_equation_factor(vc<pair<ll,\
    \ int>> pfs) {\n  using G = Gaussian_Integer<T>;\n  vc<G> res;\n  for (auto &&[p,\
    \ e] : pfs) {\n    if (p % 4 == 3 && e % 2 == 1) return {};\n  }\n\n  res.eb(G(1,\
    \ 0));\n  for (auto &&[p, e] : pfs) {\n    if (p % 4 == 3) {\n      T pp = 1;\n\
    \      FOR(e / 2) pp *= p;\n      for (auto &&g : res) {\n        g.x *= pp;\n\
    \        g.y *= pp;\n      }\n      continue;\n    }\n    auto [pix, piy] = solve_norm_equation_prime(p);\n\
    \    G pi(pix, piy);\n    vc<G> pows(e + 1);\n    pows[0] = G(1, 0);\n    FOR(i,\
    \ e) pows[i + 1] = pows[i] * pi;\n    if (p == 2) {\n      for (auto &&g : res)\
    \ g *= pows[e];\n      continue;\n    }\n    vc<G> pis(e + 1);\n    FOR(j, e +\
    \ 1) { pis[j] = pows[j] * (pows[e - j].conjugate()); }\n    vc<G> new_res;\n \
    \   new_res.reserve(len(res) * (e + 1));\n    for (auto &&g : res) {\n      for\
    \ (auto &&a : pis) {\n        new_res.eb(g * a);\n      }\n    }\n    swap(res,\
    \ new_res);\n  }\n\n  for (auto &&g : res) {\n    while (g.x <= 0 || g.y < 0)\
    \ {\n      g = G(-g.y, g.x);\n    }\n  }\n  return res;\n}\n\n// i128 \u3092\u4F7F\
    \u3046\u3068 N <= 10^{18} \u3082\u3067\u304D\u308B\n// \u30CE\u30EB\u30E0\u304C\
    \u3068\u308C\u308B\u3088\u3046\u306B\u30012 \u4E57\u3057\u3066\u3082\u30AA\u30FC\
    \u30D0\u30FC\u30D5\u30ED\u30FC\u3057\u306A\u3044\u578B\u3092\u4F7F\u304A\u3046\
    \n// 0 <= arg < 90 \u3068\u306A\u308B\u3082\u306E\u306E\u307F\u8FD4\u3059\u3002\
    \n// \u5358\u6570\u500D\u306F\u4F5C\u3089\u306A\u3044\u306E\u3067\u3001\u4F7F\u3046\
    \u3068\u304D\u306B\u6C17\u3092\u4ED8\u3051\u308B\u3002\ntemplate <typename T>\n\
    vc<Gaussian_Integer<T>> solve_norm_equation(T N) {\n  using G = Gaussian_Integer<T>;\n\
    \  vc<G> res;\n  if (N < 0) return {};\n  if (N == 0) {\n    res.eb(G(0, 0));\n\
    \    return res;\n  }\n  auto pfs = factor(N);\n  return solve_norm_equation_factor<T>(pfs);\n\
    }\n"
  dependsOn:
  - nt/factor.hpp
  - random/base.hpp
  - nt/is_prime.hpp
  - mod/montgomery_modint.hpp
  - mod/mod_pow.hpp
  - mod/barrett.hpp
  isVerificationFile: false
  path: nt/gaussian_integers.hpp
  requiredBy:
  - nt/four_square.hpp
  - nt/three_square.hpp
  - nt/two_square.hpp
  - nt/three_triangular.hpp
  timestamp: '2026-10-15 19:54:56+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - test/3_yukicoder/1593.test.cpp
  - test/1_mytest/four_square.test.cpp
  - test/1_mytest/three_triangular.test.cpp
  - test/1_mytest/three_square.test.cpp
  - test/2_library_checker/number_theory/gaussian_integers.test.cpp
  - test/2_library_checker/number_theory/two_square.test.cpp
documentation_of: nt/gaussian_integers.hpp
layout: document
redirect_from:
- /library/nt/gaussian_integers.hpp
- /library/nt/gaussian_integers.hpp.html
title: nt/gaussian_integers.hpp
---
