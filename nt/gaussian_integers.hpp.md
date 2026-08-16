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
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.12.13/x64/lib/python3.12/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n          \
    \         ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \  File \"/opt/hostedtoolcache/Python/3.12.13/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.12.13/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.12.13/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \                ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n \
    \ File \"/opt/hostedtoolcache/Python/3.12.13/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: nt/primetest.hpp:\
    \ line -1: no such header\n"
  code: "#include \"nt/factor.hpp\"\r\n#include \"mod/mod_pow.hpp\"\r\n\r\ntemplate\
    \ <typename T>\r\nstruct Gaussian_Integer {\r\n  T x, y;\r\n  using G = Gaussian_Integer;\r\
    \n\r\n  Gaussian_Integer(T x = 0, T y = 0) : x(x), y(y) {}\r\n  Gaussian_Integer(pair<T,\
    \ T> p) : x(p.fi), y(p.se) {}\r\n\r\n  T norm() const { return x * x + y * y;\
    \ }\r\n  G conjugate() const { return G(x, -y); }\r\n\r\n  // \u66AB\u5B9A\u7684\
    \u306B\r\n  bool operator<(const G &other) const {\r\n    if (x != other.x) return\
    \ x < other.x;\r\n    return y < other.y;\r\n  }\r\n\r\n  G &operator+=(const\
    \ G &g) {\r\n    x += g.x, y += g.y;\r\n    return *this;\r\n  }\r\n  G &operator-=(const\
    \ G &g) {\r\n    x -= g.x, y -= g.y;\r\n    return *this;\r\n  }\r\n  G &operator*=(const\
    \ G &g) {\r\n    tie(x, y) = mp(x * g.x - y * g.y, x * g.y + y * g.x);\r\n   \
    \ return *this;\r\n  }\r\n  G &operator/=(const G &g) {\r\n    *this *= g.conjugate();\r\
    \n    T n = g.norm();\r\n    x = floor(x + n / 2, n);\r\n    y = floor(y + n /\
    \ 2, n);\r\n    return *this;\r\n  }\r\n  G &operator%=(const G &g) {\r\n    auto\
    \ q = G(*this) / g;\r\n    q *= g;\r\n    (*this) -= q;\r\n    return *this;\r\
    \n  }\r\n  G operator-() { return G(-x, -y); }\r\n  G operator+(const G &g) const\
    \ { return G(*this) += g; }\r\n  G operator-(const G &g) const { return G(*this)\
    \ -= g; }\r\n  G operator*(const G &g) const { return G(*this) *= g; }\r\n  G\
    \ operator/(const G &g) const { return G(*this) /= g; }\r\n  G operator%(const\
    \ G &g) const { return G(*this) %= g; }\r\n  bool operator==(const G &g) { return\
    \ (x == g.x && y == g.y); }\r\n\r\n  static G gcd(G a, G b) {\r\n    while (b.x\
    \ != 0 || b.y != 0) {\r\n      a %= b;\r\n      swap(a, b);\r\n    }\r\n    return\
    \ a;\r\n  }\r\n\r\n  G pow(ll n) const {\r\n    assert(n >= 0);\r\n    G ret(1),\
    \ mul(*this);\r\n    while (n > 0) {\r\n      if (n & 1) ret *= mul;\r\n     \
    \ mul *= mul;\r\n      n >>= 1;\r\n    }\r\n    return ret;\r\n  }\r\n\r\n  //\
    \ (g,x,y) s.t ax+by=g\r\n  static tuple<G, G, G> extgcd(G a, G b) {\r\n    if\
    \ (b.x != 0 || b.y != 0) {\r\n      G q = a / b;\r\n      auto [g, x, y] = extgcd(b,\
    \ a - q * b);\r\n      return {g, y, x - q * y};\r\n    }\r\n    return {a, G{1,\
    \ 0}, G{0, 0}};\r\n  }\r\n};\r\n\r\npair<ll, ll> solve_norm_equation_prime(ll\
    \ p) {\r\n  using G = Gaussian_Integer<i128>;\r\n  assert(p == 2 || p % 4 == 1);\r\
    \n  if (p == 2) return {1, 1};\r\n  ll x = [&]() -> ll {\r\n    ll x = 1;\r\n\
    \    while (1) {\r\n      ++x;\r\n      ll pow_x = 1;\r\n      if (p < (1 << 30))\
    \ {\r\n        pow_x = mod_pow(x, (p - 1) / 4, p);\r\n        if (pow_x * pow_x\
    \ % p == p - 1) return pow_x;\r\n      } else {\r\n        pow_x = mod_pow_64(x,\
    \ (p - 1) / 4, p);\r\n        if (i128(pow_x) * pow_x % p == p - 1) return pow_x;\r\
    \n      }\r\n    }\r\n    return -1;\r\n  }();\r\n  G a(p, 0), b(x, 1);\r\n  a\
    \ = G::gcd(a, b);\r\n  assert(a.norm() == p);\r\n  return {a.x, a.y};\r\n}\r\n\
    \r\ntemplate <typename T>\r\nvc<Gaussian_Integer<T>> solve_norm_equation_factor(vc<pair<ll,\
    \ int>> pfs) {\r\n  using G = Gaussian_Integer<T>;\r\n  vc<G> res;\r\n  for (auto\
    \ &&[p, e] : pfs) {\r\n    if (p % 4 == 3 && e % 2 == 1) return {};\r\n  }\r\n\
    \r\n  res.eb(G(1, 0));\r\n  for (auto &&[p, e] : pfs) {\r\n    if (p % 4 == 3)\
    \ {\r\n      T pp = 1;\r\n      FOR(e / 2) pp *= p;\r\n      for (auto &&g : res)\
    \ {\r\n        g.x *= pp;\r\n        g.y *= pp;\r\n      }\r\n      continue;\r\
    \n    }\r\n    auto [pix, piy] = solve_norm_equation_prime(p);\r\n    G pi(pix,\
    \ piy);\r\n    vc<G> pows(e + 1);\r\n    pows[0] = G(1, 0);\r\n    FOR(i, e) pows[i\
    \ + 1] = pows[i] * pi;\r\n    if (p == 2) {\r\n      for (auto &&g : res) g *=\
    \ pows[e];\r\n      continue;\r\n    }\r\n    vc<G> pis(e + 1);\r\n    FOR(j,\
    \ e + 1) { pis[j] = pows[j] * (pows[e - j].conjugate()); }\r\n    vc<G> new_res;\r\
    \n    new_res.reserve(len(res) * (e + 1));\r\n    for (auto &&g : res) {\r\n \
    \     for (auto &&a : pis) {\r\n        new_res.eb(g * a);\r\n      }\r\n    }\r\
    \n    swap(res, new_res);\r\n  }\r\n\r\n  for (auto &&g : res) {\r\n    while\
    \ (g.x <= 0 || g.y < 0) {\r\n      g = G(-g.y, g.x);\r\n    }\r\n  }\r\n  return\
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
    \n"
  dependsOn: []
  isVerificationFile: false
  path: nt/gaussian_integers.hpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: nt/gaussian_integers.hpp
layout: document
redirect_from:
- /library/nt/gaussian_integers.hpp
- /library/nt/gaussian_integers.hpp.html
title: nt/gaussian_integers.hpp
---
