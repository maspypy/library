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
    path: mod/mongomery_modint.hpp
    title: mod/mongomery_modint.hpp
  - icon: ':question:'
    path: nt/factor.hpp
    title: nt/factor.hpp
  - icon: ':heavy_check_mark:'
    path: nt/gaussian_integers.hpp
    title: nt/gaussian_integers.hpp
  - icon: ':question:'
    path: nt/primetest.hpp
    title: nt/primetest.hpp
  - icon: ':heavy_check_mark:'
    path: nt/three_square.hpp
    title: nt/three_square.hpp
  - icon: ':question:'
    path: random/base.hpp
    title: random/base.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/mytest/three_triangular.test.cpp
    title: test/mytest/three_triangular.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"mod/mongomery_modint.hpp\"\n\n// odd mod.\n// x \u306E\u4EE3\
    \u308F\u308A\u306B rx \u3092\u6301\u3064\ntemplate <int id, typename U1, typename\
    \ U2>\nstruct Mongomery_modint {\n  using mint = Mongomery_modint;\n  inline static\
    \ U1 m, r, n2;\n  static constexpr int W = numeric_limits<U1>::digits;\n\n  static\
    \ void set_mod(U1 mod) {\n    assert(mod & 1 && mod <= U1(1) << (W - 2));\n  \
    \  m = mod, n2 = -U2(m) % m, r = m;\n    FOR(5) r *= 2 - m * r;\n    r = -r;\n\
    \    assert(r * m == U1(-1));\n  }\n  static U1 reduce(U2 b) { return (b + U2(U1(b)\
    \ * r) * m) >> W; }\n\n  U1 x;\n  Mongomery_modint() : x(0) {}\n  Mongomery_modint(U1\
    \ x) : x(reduce(U2(x) * n2)){};\n  U1 val() const {\n    U1 y = reduce(x);\n \
    \   return y >= m ? y - m : y;\n  }\n  mint &operator+=(mint y) {\n    x = ((x\
    \ += y.x) >= m ? x - m : x);\n    return *this;\n  }\n  mint &operator-=(mint\
    \ y) {\n    x -= (x >= y.x ? y.x : y.x - m);\n    return *this;\n  }\n  mint &operator*=(mint\
    \ y) {\n    x = reduce(U2(x) * y.x);\n    return *this;\n  }\n  mint operator+(mint\
    \ y) const { return mint(*this) += y; }\n  mint operator-(mint y) const { return\
    \ mint(*this) -= y; }\n  mint operator*(mint y) const { return mint(*this) *=\
    \ y; }\n  bool operator==(mint y) const {\n    return (x >= m ? x - m : x) ==\
    \ (y.x >= m ? y.x - m : y.x);\n  }\n  bool operator!=(mint y) const { return not\
    \ operator==(y); }\n  mint pow(ll n) const {\n    assert(n >= 0);\n    mint y\
    \ = 1, z = *this;\n    for (; n; n >>= 1, z *= z)\n      if (n & 1) y *= z;\n\
    \    return y;\n  }\n};\n\ntemplate <int id>\nusing Mongomery_modint_32 = Mongomery_modint<id,\
    \ u32, u64>;\ntemplate <int id>\nusing Mongomery_modint_64 = Mongomery_modint<id,\
    \ u64, u128>;\n#line 3 \"nt/primetest.hpp\"\n\r\nbool primetest(const u64 x) {\r\
    \n  assert(x < u64(1) << 62);\r\n  if (x == 2 or x == 3 or x == 5 or x == 7) return\
    \ true;\r\n  if (x % 2 == 0 or x % 3 == 0 or x % 5 == 0 or x % 7 == 0) return\
    \ false;\r\n  if (x < 121) return x > 1;\r\n  const u64 d = (x - 1) >> lowbit(x\
    \ - 1);\r\n\r\n  using mint = Mongomery_modint_64<202311020>;\r\n\r\n  mint::set_mod(x);\r\
    \n  const mint one(u64(1)), minus_one(x - 1);\r\n  auto ok = [&](u64 a) -> bool\
    \ {\r\n    auto y = mint(a).pow(d);\r\n    u64 t = d;\r\n    while (y != one &&\
    \ y != minus_one && t != x - 1) y *= y, t <<= 1;\r\n    if (y != minus_one &&\
    \ t % 2 == 0) return false;\r\n    return true;\r\n  };\r\n  if (x < (u64(1) <<\
    \ 32)) {\r\n    for (u64 a: {2, 7, 61})\r\n      if (!ok(a)) return false;\r\n\
    \  } else {\r\n    for (u64 a: {2, 325, 9375, 28178, 450775, 9780504, 1795265022})\
    \ {\r\n      if (!ok(a)) return false;\r\n    }\r\n  }\r\n  return true;\r\n}\n\
    #line 2 \"nt/factor.hpp\"\n\n#line 2 \"random/base.hpp\"\n\nu64 RNG_64() {\n \
    \ static uint64_t x_\n      = uint64_t(chrono::duration_cast<chrono::nanoseconds>(\n\
    \                     chrono::high_resolution_clock::now().time_since_epoch())\n\
    \                     .count())\n        * 10150724397891781847ULL;\n  x_ ^= x_\
    \ << 7;\n  return x_ ^= x_ >> 9;\n}\n\nu64 RNG(u64 lim) { return RNG_64() % lim;\
    \ }\n\nll RNG(ll l, ll r) { return l + RNG_64() % (r - l); }\n#line 5 \"nt/factor.hpp\"\
    \n\ntemplate <typename mint>\nll rho(ll n, ll c) {\n  assert(n > 1);\n  const\
    \ mint cc(c);\n  auto f = [&](mint x) { return x * x + cc; };\n  mint x = 1, y\
    \ = 2, z = 1, q = 1;\n  ll g = 1;\n  const ll m = 1LL << (__lg(n) / 5);\n  for\
    \ (ll r = 1; g == 1; r <<= 1) {\n    x = y;\n    FOR(r) y = f(y);\n    for (ll\
    \ k = 0; k < r && g == 1; k += m) {\n      z = y;\n      FOR(min(m, r - k)) y\
    \ = f(y), q *= x - y;\n      g = gcd(q.val(), n);\n    }\n  }\n  if (g == n) do\
    \ {\n      z = f(z);\n      g = gcd((x - z).val(), n);\n    } while (g == 1);\n\
    \  return g;\n}\n\nll find_prime_factor(ll n) {\n  assert(n > 1);\n  if (primetest(n))\
    \ return n;\n  FOR(100) {\n    ll m = 0;\n    if (n < (1 << 30)) {\n      using\
    \ mint = Mongomery_modint_32<20231025>;\n      mint::set_mod(n);\n      m = rho<mint>(n,\
    \ RNG(0, n));\n    } else {\n      using mint = Mongomery_modint_64<20231025>;\n\
    \      mint::set_mod(n);\n      m = rho<mint>(n, RNG(0, n));\n    }\n    if (primetest(m))\
    \ return m;\n    n = m;\n  }\n  assert(0);\n  return -1;\n}\n\n// \u30BD\u30FC\
    \u30C8\u3057\u3066\u304F\u308C\u308B\nvc<pair<ll, int>> factor(ll n) {\n  assert(n\
    \ >= 1);\n  vc<pair<ll, int>> pf;\n  FOR(p, 2, 100) {\n    if (p * p > n) break;\n\
    \    if (n % p == 0) {\n      ll e = 0;\n      do { n /= p, e += 1; } while (n\
    \ % p == 0);\n      pf.eb(p, e);\n    }\n  }\n  while (n > 1) {\n    ll p = find_prime_factor(n);\n\
    \    ll e = 0;\n    do { n /= p, e += 1; } while (n % p == 0);\n    pf.eb(p, e);\n\
    \  }\n  sort(all(pf));\n  return pf;\n}\n\nvc<pair<ll, int>> factor_by_lpf(ll\
    \ n, vc<int>& lpf) {\n  vc<pair<ll, int>> res;\n  while (n > 1) {\n    int p =\
    \ lpf[n];\n    int e = 0;\n    while (n % p == 0) {\n      n /= p;\n      ++e;\n\
    \    }\n    res.eb(p, e);\n  }\n  return res;\n}\n#line 2 \"mod/mod_pow.hpp\"\n\
    \r\n#line 2 \"mod/barrett.hpp\"\n\n// https://github.com/atcoder/ac-library/blob/master/atcoder/internal_math.hpp\n\
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
    mod/mod_pow.hpp\"\n\r\nu32 mod_pow(int a, ll n, int mod) {\r\n  assert(n >= 0);\r\
    \n  a = ((a %= mod) < 0 ? a + mod : a);\r\n  if ((mod & 1) && (mod < (1 << 30)))\
    \ {\r\n    using mint = Mongomery_modint_32<202311021>;\r\n    mint::set_mod(mod);\r\
    \n    return mint(a).pow(n).val();\r\n  }\r\n  Barrett bt(mod);\r\n  int r = 1;\r\
    \n  while (n) {\r\n    if (n & 1) r = bt.mul(r, a);\r\n    a = bt.mul(a, a), n\
    \ >>= 1;\r\n  }\r\n  return r;\r\n}\r\n\r\nu64 mod_pow_64(ll a, ll n, u64 mod)\
    \ {\r\n  assert(n >= 0);\r\n  a = ((a %= mod) < 0 ? a + mod : a);\r\n  if ((mod\
    \ & 1) && (mod < (u64(1) << 62))) {\r\n    using mint = Mongomery_modint_64<202311021>;\r\
    \n    mint::set_mod(mod);\r\n    return mint(a).pow(n).val();\r\n  }\r\n  Barrett_64\
    \ bt(mod);\r\n  ll r = 1;\r\n  while (n) {\r\n    if (n & 1) r = bt.mul(r, a);\r\
    \n    a = bt.mul(a, a), n >>= 1;\r\n  }\r\n  return r;\r\n}\n#line 3 \"nt/gaussian_integers.hpp\"\
    \n\r\ntemplate <typename T>\r\nstruct Gaussian_Integer {\r\n  T x, y;\r\n  using\
    \ G = Gaussian_Integer;\r\n\r\n  Gaussian_Integer(T x = 0, T y = 0) : x(x), y(y)\
    \ {}\r\n  Gaussian_Integer(pair<T, T> p) : x(p.fi), y(p.se) {}\r\n\r\n  T norm()\
    \ const { return x * x + y * y; }\r\n  G conjugate() const { return G(x, -y);\
    \ }\r\n\r\n  G &operator+=(const G &g) {\r\n    x += g.x, y += g.y;\r\n    return\
    \ *this;\r\n  }\r\n  G &operator-=(const G &g) {\r\n    x -= g.x, y -= g.y;\r\n\
    \    return *this;\r\n  }\r\n  G &operator*=(const G &g) {\r\n    tie(x, y) =\
    \ mp(x * g.x - y * g.y, x * g.y + y * g.x);\r\n    return *this;\r\n  }\r\n  G\
    \ &operator/=(const G &g) {\r\n    *this *= g.conjugate();\r\n    T n = g.norm();\r\
    \n    x = floor(x + n / 2, n);\r\n    y = floor(y + n / 2, n);\r\n    return *this;\r\
    \n  }\r\n  G &operator%=(const G &g) {\r\n    auto q = G(*this) / g;\r\n    q\
    \ *= g;\r\n    (*this) -= q;\r\n    return *this;\r\n  }\r\n  G operator-() {\
    \ return G(-x, -y); }\r\n  G operator+(const G &g) { return G(*this) += g; }\r\
    \n  G operator-(const G &g) { return G(*this) -= g; }\r\n  G operator*(const G\
    \ &g) { return G(*this) *= g; }\r\n  G operator/(const G &g) { return G(*this)\
    \ /= g; }\r\n  G operator%(const G &g) { return G(*this) %= g; }\r\n  bool operator==(const\
    \ G &g) { return (x == g.x && y == g.y); }\r\n\r\n  static G gcd(G a, G b) {\r\
    \n    while (b.x != 0 || b.y != 0) {\r\n      a %= b;\r\n      swap(a, b);\r\n\
    \    }\r\n    return a;\r\n  }\r\n\r\n  // (g,x,y) s.t ax+by=g\r\n  static tuple<G,\
    \ G, G> extgcd(G a, G b) {\r\n    if (b.x != 0 || b.y != 0) {\r\n      G q = a\
    \ / b;\r\n      auto [g, x, y] = extgcd(b, a - q * b);\r\n      return {g, y,\
    \ x - q * y};\r\n    }\r\n    return {a, G{1, 0}, G{0, 0}};\r\n  }\r\n};\r\n\r\
    \npair<ll, ll> solve_norm_equation_prime(ll p) {\r\n  using G = Gaussian_Integer<i128>;\r\
    \n  assert(p == 2 || p % 4 == 1);\r\n  if (p == 2) return {1, 1};\r\n  ll x =\
    \ [&]() -> ll {\r\n    ll x = 1;\r\n    while (1) {\r\n      ++x;\r\n      ll\
    \ pow_x = 1;\r\n      if (p < (1 << 30)) {\r\n        pow_x = mod_pow(x, (p -\
    \ 1) / 4, p);\r\n        if (pow_x * pow_x % p == p - 1) return pow_x;\r\n   \
    \   } else {\r\n        pow_x = mod_pow_64(x, (p - 1) / 4, p);\r\n        if (i128(pow_x)\
    \ * pow_x % p == p - 1) return pow_x;\r\n      }\r\n    }\r\n    return -1;\r\n\
    \  }();\r\n  G a(p, 0), b(x, 1);\r\n  a = G::gcd(a, b);\r\n  assert(a.norm() ==\
    \ p);\r\n  return {a.x, a.y};\r\n}\r\n\r\ntemplate <typename T>\r\nvc<Gaussian_Integer<T>>\
    \ solve_norm_equation_factor(vc<pair<ll, int>> pfs) {\r\n  using G = Gaussian_Integer<T>;\r\
    \n  vc<G> res;\r\n  for (auto &&[p, e]: pfs) {\r\n    if (p % 4 == 3 && e % 2\
    \ == 1) return {};\r\n  }\r\n\r\n  res.eb(G(1, 0));\r\n  for (auto &&[p, e]: pfs)\
    \ {\r\n    if (p % 4 == 3) {\r\n      T pp = 1;\r\n      FOR(e / 2) pp *= p;\r\
    \n      for (auto &&g: res) {\r\n        g.x *= pp;\r\n        g.y *= pp;\r\n\
    \      }\r\n      continue;\r\n    }\r\n    G pi = solve_norm_equation_prime(p);\r\
    \n    vc<G> pows(e + 1);\r\n    pows[0] = G(1, 0);\r\n    FOR(i, e) pows[i + 1]\
    \ = pows[i] * pi;\r\n    if (p == 2) {\r\n      for (auto &&g: res) g *= pows[e];\r\
    \n      continue;\r\n    }\r\n    vc<G> pis(e + 1);\r\n    FOR(j, e + 1) { pis[j]\
    \ = pows[j] * (pows[e - j].conjugate()); }\r\n    vc<G> new_res;\r\n    new_res.reserve(len(res)\
    \ * (e + 1));\r\n    for (auto &&g: res) {\r\n      for (auto &&a: pis) { new_res.eb(g\
    \ * a); }\r\n    }\r\n    swap(res, new_res);\r\n  }\r\n\r\n  for (auto &&g: res)\
    \ {\r\n    while (g.x <= 0 || g.y < 0) { g = G(-g.y, g.x); }\r\n  }\r\n  return\
    \ res;\r\n}\r\n\r\n// i128 \u3092\u4F7F\u3046\u3068 N <= 10^{18} \u3082\u3067\u304D\
    \u308B\r\n// \u30CE\u30EB\u30E0\u304C\u3068\u308C\u308B\u3088\u3046\u306B\u3001\
    2 \u4E57\u3057\u3066\u3082\u30AA\u30FC\u30D0\u30FC\u30D5\u30ED\u30FC\u3057\u306A\
    \u3044\u578B\u3092\u4F7F\u304A\u3046\r\n// 0 <= arg < 90 \u3068\u306A\u308B\u3082\
    \u306E\u306E\u307F\u8FD4\u3059\u3002\r\n// \u5358\u6570\u500D\u306F\u4F5C\u3089\
    \u306A\u3044\u306E\u3067\u3001\u4F7F\u3046\u3068\u304D\u306B\u6C17\u3092\u4ED8\
    \u3051\u308B\u3002\r\ntemplate <typename T>\r\nvc<Gaussian_Integer<T>> solve_norm_equation(T\
    \ N) {\r\n  using G = Gaussian_Integer<T>;\r\n  vc<G> res;\r\n  if (N < 0) return\
    \ {};\r\n  if (N == 0) {\r\n    res.eb(G(0, 0));\r\n    return res;\r\n  }\r\n\
    \  auto pfs = factor(N);\r\n  return solve_norm_equation_factor<T>(pfs);\r\n}\r\
    \n#line 3 \"nt/three_square.hpp\"\n\n// https://math.stackexchange.com/questions/483101/rabin-and-shallit-algorithm\n\
    // ERH \u306E\u3082\u3068 O(log^2N) \uFF1F\ntuple<ll, ll, ll> three_square(ll\
    \ N) {\n  if (N == 0) return {0, 0, 0};\n  auto F = [&](ll n) -> tuple<ll, ll,\
    \ ll> {\n    if (N == 2) return {1, 1, 0};\n    if (N == 3) return {1, 1, 1};\n\
    \    if (N == 10) return {3, 1, 0};\n    if (N == 34) return {5, 3, 0};\n    if\
    \ (N == 58) return {7, 3, 0};\n    if (N == 85) return {9, 2, 0};\n    if (N ==\
    \ 130) return {11, 3, 0};\n    if (N == 214) return {14, 3, 3};\n    if (N ==\
    \ 226) return {15, 1, 0};\n    if (N == 370) return {19, 3, 0};\n    if (N ==\
    \ 526) return {21, 9, 2};\n    if (N == 706) return {25, 9, 0};\n    if (N ==\
    \ 730) return {27, 1, 0};\n    if (N == 1414) return {33, 18, 1};\n    if (N ==\
    \ 1906) return {41, 15, 0};\n    if (N == 2986) return {45, 31, 0};\n    if (N\
    \ == 9634) return {97, 15, 0};\n    ll x = sqrtl(N);\n    if (N == x * x) return\
    \ {x, 0, 0};\n    if (N % 4 != 1 && x % 2 == 0) --x;\n    if (N % 4 == 1 && x\
    \ % 2 == 1) --x;\n    x += 2;\n    while (1) {\n      x -= 2;\n      ll k = N\
    \ - x * x;\n      if (k < 0) break;\n      if (k % 2 == 1 && primetest(k)) {\n\
    \        auto [a, b] = solve_norm_equation_prime(k);\n        a = abs(a), b =\
    \ abs(b);\n        return {a, b, x};\n      }\n      if (k % 2 == 0 && primetest(k\
    \ / 2)) {\n        auto [a, b] = solve_norm_equation_prime(k / 2);\n        tie(a,\
    \ b) = mp(a + b, a - b);\n        a = abs(a), b = abs(b);\n        return {a,\
    \ b, x};\n      }\n    }\n    return {-1, -1, -1};\n    assert(0);\n  };\n  ll\
    \ e = 0;\n  while (N % 4 == 0) N /= 4, ++e;\n  if (N % 8 == 7) return {-1, -1,\
    \ -1};\n  auto [a, b, c] = F(N);\n  return {a << e, b << e, c << e};\n}\n#line\
    \ 2 \"nt/three_triangular.hpp\"\n\n// 3 \u3064\u306E x(x-1)/2 \u306E\u548C\u306B\
    \u3059\u308B\ntuple<ll, ll, ll> three_triangular(ll N) {\n  auto [a, b, c] = three_square(8\
    \ * N + 3);\n  a = (a + 1) / 2;\n  b = (b + 1) / 2;\n  c = (c + 1) / 2;\n  return\
    \ {a, b, c};\n}\n"
  code: "#include \"nt/three_square.hpp\"\n\n// 3 \u3064\u306E x(x-1)/2 \u306E\u548C\
    \u306B\u3059\u308B\ntuple<ll, ll, ll> three_triangular(ll N) {\n  auto [a, b,\
    \ c] = three_square(8 * N + 3);\n  a = (a + 1) / 2;\n  b = (b + 1) / 2;\n  c =\
    \ (c + 1) / 2;\n  return {a, b, c};\n}\n"
  dependsOn:
  - nt/three_square.hpp
  - nt/primetest.hpp
  - mod/mongomery_modint.hpp
  - nt/gaussian_integers.hpp
  - nt/factor.hpp
  - random/base.hpp
  - mod/mod_pow.hpp
  - mod/barrett.hpp
  isVerificationFile: false
  path: nt/three_triangular.hpp
  requiredBy: []
  timestamp: '2023-11-02 05:38:57+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/mytest/three_triangular.test.cpp
documentation_of: nt/three_triangular.hpp
layout: document
redirect_from:
- /library/nt/three_triangular.hpp
- /library/nt/three_triangular.hpp.html
title: nt/three_triangular.hpp
---
