---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: mod/mod_inv.hpp
    title: mod/mod_inv.hpp
  - icon: ':x:'
    path: mod/mod_sqrt.hpp
    title: mod/mod_sqrt.hpp
  - icon: ':question:'
    path: mod/modint.hpp
    title: mod/modint.hpp
  - icon: ':question:'
    path: poly/convolution.hpp
    title: poly/convolution.hpp
  - icon: ':question:'
    path: poly/convolution_naive.hpp
    title: poly/convolution_naive.hpp
  - icon: ':question:'
    path: poly/count_terms.hpp
    title: poly/count_terms.hpp
  - icon: ':x:'
    path: poly/differentiate.hpp
    title: poly/differentiate.hpp
  - icon: ':question:'
    path: poly/fft.hpp
    title: poly/fft.hpp
  - icon: ':x:'
    path: poly/fps_exp.hpp
    title: poly/fps_exp.hpp
  - icon: ':question:'
    path: poly/fps_inv.hpp
    title: poly/fps_inv.hpp
  - icon: ':x:'
    path: poly/fps_log.hpp
    title: poly/fps_log.hpp
  - icon: ':x:'
    path: poly/fps_pow.hpp
    title: poly/fps_pow.hpp
  - icon: ':x:'
    path: poly/integrate.hpp
    title: poly/integrate.hpp
  - icon: ':question:'
    path: poly/ntt.hpp
    title: poly/ntt.hpp
  - icon: ':question:'
    path: random/base.hpp
    title: random/base.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/library_checker/polynomial/sqrt_of_fps.test.cpp
    title: test/library_checker/polynomial/sqrt_of_fps.test.cpp
  - icon: ':x:'
    path: test/library_checker/polynomial/sqrt_of_fps_sparse.test.cpp
    title: test/library_checker/polynomial/sqrt_of_fps_sparse.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 2 \"poly/count_terms.hpp\"\ntemplate<typename mint>\r\nint count_terms(const\
    \ vc<mint>& f){\r\n  int t = 0;\r\n  FOR(i, len(f)) if(f[i] != mint(0)) ++t;\r\
    \n  return t;\r\n}\n#line 2 \"mod/modint.hpp\"\n\ntemplate <int mod>\nstruct modint\
    \ {\n  int val;\n  constexpr modint(ll x = 0) noexcept {\n    if (0 <= x && x\
    \ < mod)\n      val = x;\n    else {\n      x %= mod;\n      val = (x < 0 ? x\
    \ + mod : x);\n    }\n  }\n  bool operator<(const modint &other) const {\n   \
    \ return val < other.val;\n  } // To use std::map\n  modint &operator+=(const\
    \ modint &p) {\n    if ((val += p.val) >= mod) val -= mod;\n    return *this;\n\
    \  }\n  modint &operator-=(const modint &p) {\n    if ((val += mod - p.val) >=\
    \ mod) val -= mod;\n    return *this;\n  }\n  modint &operator*=(const modint\
    \ &p) {\n    val = (int)(1LL * val * p.val % mod);\n    return *this;\n  }\n \
    \ modint &operator/=(const modint &p) {\n    *this *= p.inverse();\n    return\
    \ *this;\n  }\n  modint operator-() const { return modint(-val); }\n  modint operator+(const\
    \ modint &p) const { return modint(*this) += p; }\n  modint operator-(const modint\
    \ &p) const { return modint(*this) -= p; }\n  modint operator*(const modint &p)\
    \ const { return modint(*this) *= p; }\n  modint operator/(const modint &p) const\
    \ { return modint(*this) /= p; }\n  bool operator==(const modint &p) const { return\
    \ val == p.val; }\n  bool operator!=(const modint &p) const { return val != p.val;\
    \ }\n  modint inverse() const {\n    int a = val, b = mod, u = 1, v = 0, t;\n\
    \    while (b > 0) {\n      t = a / b;\n      swap(a -= t * b, b), swap(u -= t\
    \ * v, v);\n    }\n    return modint(u);\n  }\n  modint pow(int64_t n) const {\n\
    \    modint ret(1), mul(val);\n    while (n > 0) {\n      if (n & 1) ret *= mul;\n\
    \      mul *= mul;\n      n >>= 1;\n    }\n    return ret;\n  }\n#ifdef FASTIO\n\
    \  void write() { fastio::printer.write(val); }\n  void read() {\n    ll x;\n\
    \    fastio::scanner.read(x);\n    if (x < 0 || x >= mod) x %= mod;\n    if (x\
    \ < 0) x += mod;\n    val += x;\n  }\n#endif\n  static constexpr int get_mod()\
    \ { return mod; }\n};\n\nstruct ArbitraryModInt {\n  static constexpr bool is_modint\
    \ = true;\n  int val;\n  ArbitraryModInt() : val(0) {}\n  ArbitraryModInt(int64_t\
    \ y)\n      : val(y >= 0 ? y % get_mod()\n                   : (get_mod() - (-y)\
    \ % get_mod()) % get_mod()) {}\n  bool operator<(const ArbitraryModInt &other)\
    \ const {\n    return val < other.val;\n  } // To use std::map<ArbitraryModInt,\
    \ T>\n  static int &get_mod() {\n    static int mod = 0;\n    return mod;\n  }\n\
    \  static void set_mod(int md) { get_mod() = md; }\n  ArbitraryModInt &operator+=(const\
    \ ArbitraryModInt &p) {\n    if ((val += p.val) >= get_mod()) val -= get_mod();\n\
    \    return *this;\n  }\n  ArbitraryModInt &operator-=(const ArbitraryModInt &p)\
    \ {\n    if ((val += get_mod() - p.val) >= get_mod()) val -= get_mod();\n    return\
    \ *this;\n  }\n  ArbitraryModInt &operator*=(const ArbitraryModInt &p) {\n   \
    \ long long a = (long long)val * p.val;\n    int xh = (int)(a >> 32), xl = (int)a,\
    \ d, m;\n    asm(\"divl %4; \\n\\t\" : \"=a\"(d), \"=d\"(m) : \"d\"(xh), \"a\"\
    (xl), \"r\"(get_mod()));\n    val = m;\n    return *this;\n  }\n  ArbitraryModInt\
    \ &operator/=(const ArbitraryModInt &p) {\n    *this *= p.inverse();\n    return\
    \ *this;\n  }\n  ArbitraryModInt operator-() const { return ArbitraryModInt(get_mod()\
    \ - val); }\n  ArbitraryModInt operator+(const ArbitraryModInt &p) const {\n \
    \   return ArbitraryModInt(*this) += p;\n  }\n  ArbitraryModInt operator-(const\
    \ ArbitraryModInt &p) const {\n    return ArbitraryModInt(*this) -= p;\n  }\n\
    \  ArbitraryModInt operator*(const ArbitraryModInt &p) const {\n    return ArbitraryModInt(*this)\
    \ *= p;\n  }\n  ArbitraryModInt operator/(const ArbitraryModInt &p) const {\n\
    \    return ArbitraryModInt(*this) /= p;\n  }\n  bool operator==(const ArbitraryModInt\
    \ &p) const { return val == p.val; }\n  bool operator!=(const ArbitraryModInt\
    \ &p) const { return val != p.val; }\n  ArbitraryModInt inverse() const {\n  \
    \  int a = val, b = get_mod(), u = 1, v = 0, t;\n    while (b > 0) {\n      t\
    \ = a / b;\n      swap(a -= t * b, b), swap(u -= t * v, v);\n    }\n    return\
    \ ArbitraryModInt(u);\n  }\n  ArbitraryModInt pow(int64_t n) const {\n    ArbitraryModInt\
    \ ret(1), mul(val);\n    while (n > 0) {\n      if (n & 1) ret *= mul;\n     \
    \ mul *= mul;\n      n >>= 1;\n    }\n    return ret;\n  }\n#ifdef FASTIO\n  void\
    \ write() { fastio::printer.write(val); }\n  void read() { fastio::scanner.read(val);\
    \ }\n#endif\n};\n\ntemplate <typename mint>\nmint inv(int n) {\n  static const\
    \ int mod = mint::get_mod();\n  static vector<mint> dat = {0, 1};\n  assert(0\
    \ <= n);\n  if (n >= mod) n %= mod;\n  while (int(dat.size()) <= n) {\n    int\
    \ k = dat.size();\n    auto q = (mod + k - 1) / k;\n    int r = k * q - mod;\n\
    \    dat.emplace_back(dat[r] * mint(q));\n  }\n  return dat[n];\n}\n\ntemplate\
    \ <typename mint>\nmint fact(int n) {\n  static const int mod = mint::get_mod();\n\
    \  static vector<mint> dat = {1, 1};\n  assert(0 <= n);\n  if (n >= mod) return\
    \ 0;\n  while (int(dat.size()) <= n) {\n    int k = dat.size();\n    dat.emplace_back(dat[k\
    \ - 1] * mint(k));\n  }\n  return dat[n];\n}\n\ntemplate <typename mint>\nmint\
    \ fact_inv(int n) {\n  static const int mod = mint::get_mod();\n  static vector<mint>\
    \ dat = {1, 1};\n  assert(-1 <= n && n < mod);\n  if (n == -1) return mint(0);\n\
    \  while (int(dat.size()) <= n) {\n    int k = dat.size();\n    dat.emplace_back(dat[k\
    \ - 1] * inv<mint>(k));\n  }\n  return dat[n];\n}\n\ntemplate <class mint, class...\
    \ Ts>\nmint fact_invs(Ts... xs) {\n  return (mint(1) * ... * fact_inv<mint>(xs));\n\
    }\n\ntemplate <typename mint, class Head, class... Tail>\nmint multinomial(Head\
    \ &&head, Tail &&... tail) {\n  return fact<mint>(head) * fact_invs<mint>(std::forward<Tail>(tail)...);\n\
    }\n\ntemplate <typename mint>\nmint C_dense(int n, int k) {\n  static vvc<mint>\
    \ C;\n  static int H = 0, W = 0;\n\n  auto calc = [&](int i, int j) -> mint {\n\
    \    if (i == 0) return (j == 0 ? mint(1) : mint(0));\n    return C[i - 1][j]\
    \ + (j ? C[i - 1][j - 1] : 0);\n  };\n\n  if (W <= k) {\n    FOR(i, H) {\n   \
    \   C[i].resize(k + 1);\n      FOR(j, W, k + 1) { C[i][j] = calc(i, j); }\n  \
    \  }\n    W = k + 1;\n  }\n  if (H <= n) {\n    C.resize(n + 1);\n    FOR(i, H,\
    \ n + 1) {\n      C[i].resize(W);\n      FOR(j, W) { C[i][j] = calc(i, j); }\n\
    \    }\n    H = n + 1;\n  }\n  return C[n][k];\n}\n\ntemplate <typename mint,\
    \ bool large = false, bool dense = false>\nmint C(ll n, ll k) {\n  assert(n >=\
    \ 0);\n  if (k < 0 || n < k) return 0;\n  if (dense) return C_dense<mint>(n, k);\n\
    \  if (!large) return fact<mint>(n) * fact_inv<mint>(k) * fact_inv<mint>(n - k);\n\
    \  k = min(k, n - k);\n  mint x(1);\n  FOR(i, k) { x *= mint(n - i); }\n  x *=\
    \ fact_inv<mint>(k);\n  return x;\n}\n\ntemplate <typename mint, bool large =\
    \ false>\nmint C_inv(ll n, ll k) {\n  assert(n >= 0);\n  assert(0 <= k && k <=\
    \ n);\n  if (!large) return fact_inv<mint>(n) * fact<mint>(k) * fact<mint>(n -\
    \ k);\n  return mint(1) / C<mint, 1>(n, k);\n}\n\n// [x^d] (1-x) ^ {-n} \u306E\
    \u8A08\u7B97\ntemplate <typename mint, bool large = false, bool dense = false>\n\
    mint C_negative(ll n, ll d) {\n  assert(n >= 0);\n  if (d < 0) return mint(0);\n\
    \  if (n == 0) { return (d == 0 ? mint(1) : mint(0)); }\n  return C<mint, large,\
    \ dense>(n + d - 1, d);\n}\n\nusing modint107 = modint<1000000007>;\nusing modint998\
    \ = modint<998244353>;\nusing amint = ArbitraryModInt;\n#line 2 \"mod/mod_inv.hpp\"\
    \n// long \u3067\u3082\u5927\u4E08\u592B\r\nll mod_inv(ll val, ll mod) {\r\n \
    \ val %= mod;\r\n  if (val < 0) val += mod;\r\n  ll a = val, b = mod, u = 1, v\
    \ = 0, t;\r\n  while (b > 0) {\r\n    t = a / b;\r\n    swap(a -= t * b, b), swap(u\
    \ -= t * v, v);\r\n  }\r\n  if (u < 0) u += mod;\r\n  return u;\r\n}\r\n#line\
    \ 1 \"poly/convolution_naive.hpp\"\ntemplate <class T>\r\nvector<T> convolution_naive(const\
    \ vector<T>& a, const vector<T>& b) {\r\n  int n = int(a.size()), m = int(b.size());\r\
    \n  vector<T> ans(n + m - 1);\r\n  if (n < m) {\r\n    FOR(j, m) FOR(i, n) ans[i\
    \ + j] += a[i] * b[j];\r\n  } else {\r\n    FOR(i, n) FOR(j, m) ans[i + j] +=\
    \ a[i] * b[j];\r\n  }\r\n  return ans;\r\n}\r\n#line 2 \"poly/ntt.hpp\"\n\r\n\
    template <class mint>\r\nstruct ntt_info {\r\n  static constexpr int bsf_constexpr(unsigned\
    \ int n) {\r\n    int x = 0;\r\n    while (!(n & (1 << x))) x++;\r\n    return\
    \ x;\r\n  }\r\n\r\n  static constexpr int rank2 = bsf_constexpr(mint::get_mod()\
    \ - 1);\r\n  array<mint, rank2 + 1> root;\r\n  array<mint, rank2 + 1> iroot;\r\
    \n  array<mint, max(0, rank2 - 1)> rate2;\r\n  array<mint, max(0, rank2 - 1)>\
    \ irate2;\r\n  array<mint, max(0, rank2 - 2)> rate3;\r\n  array<mint, max(0, rank2\
    \ - 2)> irate3;\r\n\r\n  ntt_info() {\r\n    int g = primitive_root(mint::get_mod());\r\
    \n    root[rank2] = mint(g).pow((mint::get_mod() - 1) >> rank2);\r\n    iroot[rank2]\
    \ = mint(1) / root[rank2];\r\n    FOR_R(i, rank2) {\r\n      root[i] = root[i\
    \ + 1] * root[i + 1];\r\n      iroot[i] = iroot[i + 1] * iroot[i + 1];\r\n   \
    \ }\r\n\r\n    {\r\n      mint prod = 1, iprod = 1;\r\n      for (int i = 0; i\
    \ <= rank2 - 2; i++) {\r\n        rate2[i] = root[i + 2] * prod;\r\n        irate2[i]\
    \ = iroot[i + 2] * iprod;\r\n        prod *= iroot[i + 2];\r\n        iprod *=\
    \ root[i + 2];\r\n      }\r\n    }\r\n    {\r\n      mint prod = 1, iprod = 1;\r\
    \n      for (int i = 0; i <= rank2 - 3; i++) {\r\n        rate3[i] = root[i +\
    \ 3] * prod;\r\n        irate3[i] = iroot[i + 3] * iprod;\r\n        prod *= iroot[i\
    \ + 3];\r\n        iprod *= root[i + 3];\r\n      }\r\n    }\r\n  }\r\n\r\n  constexpr\
    \ int primitive_root(int m) {\r\n    if (m == 167772161) return 3;\r\n    if (m\
    \ == 469762049) return 3;\r\n    if (m == 754974721) return 11;\r\n    if (m ==\
    \ 880803841) return 26;\r\n    if (m == 998244353) return 3;\r\n    if (m == 924844053)\
    \ return 5;\r\n    return -1;\r\n  }\r\n};\r\n\r\ntemplate <class mint>\r\nvoid\
    \ ntt(vector<mint>& a, bool inverse) {\r\n  int n = int(a.size());\r\n  int h\
    \ = topbit(n);\r\n  assert(n == 1 << h);\r\n  static const ntt_info<mint> info;\r\
    \n  if (!inverse) {\r\n    int len = 0; // a[i, i+(n>>len), i+2*(n>>len), ..]\
    \ is transformed\r\n    while (len < h) {\r\n      if (h - len == 1) {\r\n   \
    \     int p = 1 << (h - len - 1);\r\n        mint rot = 1;\r\n        FOR(s, 1\
    \ << len) {\r\n          int offset = s << (h - len);\r\n          FOR(i, p) {\r\
    \n            auto l = a[i + offset];\r\n            auto r = a[i + offset + p]\
    \ * rot;\r\n            a[i + offset] = l + r;\r\n            a[i + offset + p]\
    \ = l - r;\r\n          }\r\n          rot *= info.rate2[topbit(~s & -~s)];\r\n\
    \        }\r\n        len++;\r\n      } else {\r\n        int p = 1 << (h - len\
    \ - 2);\r\n        mint rot = 1, imag = info.root[2];\r\n        for (int s =\
    \ 0; s < (1 << len); s++) {\r\n          mint rot2 = rot * rot;\r\n          mint\
    \ rot3 = rot2 * rot;\r\n          int offset = s << (h - len);\r\n          for\
    \ (int i = 0; i < p; i++) {\r\n            auto mod2 = 1ULL * mint::get_mod()\
    \ * mint::get_mod();\r\n            auto a0 = 1ULL * a[i + offset].val;\r\n  \
    \          auto a1 = 1ULL * a[i + offset + p].val * rot.val;\r\n            auto\
    \ a2 = 1ULL * a[i + offset + 2 * p].val * rot2.val;\r\n            auto a3 = 1ULL\
    \ * a[i + offset + 3 * p].val * rot3.val;\r\n            auto a1na3imag = 1ULL\
    \ * mint(a1 + mod2 - a3).val * imag.val;\r\n            auto na2 = mod2 - a2;\r\
    \n            a[i + offset] = a0 + a2 + a1 + a3;\r\n            a[i + offset +\
    \ 1 * p] = a0 + a2 + (2 * mod2 - (a1 + a3));\r\n            a[i + offset + 2 *\
    \ p] = a0 + na2 + a1na3imag;\r\n            a[i + offset + 3 * p] = a0 + na2 +\
    \ (mod2 - a1na3imag);\r\n          }\r\n          rot *= info.rate3[topbit(~s\
    \ & -~s)];\r\n        }\r\n        len += 2;\r\n      }\r\n    }\r\n  } else {\r\
    \n    mint coef = mint(1) / mint(len(a));\r\n    FOR(i, len(a)) a[i] *= coef;\r\
    \n    int len = h;\r\n    while (len) {\r\n      if (len == 1) {\r\n        int\
    \ p = 1 << (h - len);\r\n        mint irot = 1;\r\n        FOR(s, 1 << (len -\
    \ 1)) {\r\n          int offset = s << (h - len + 1);\r\n          FOR(i, p) {\r\
    \n            auto l = a[i + offset];\r\n            auto r = a[i + offset + p];\r\
    \n            a[i + offset] = l + r;\r\n            a[i + offset + p]\r\n    \
    \            = (unsigned long long)(mint::get_mod() + l.val - r.val)\r\n     \
    \             * irot.val;\r\n            ;\r\n          }\r\n          irot *=\
    \ info.irate2[topbit(~s & -~s)];\r\n        }\r\n        len--;\r\n      } else\
    \ {\r\n        int p = 1 << (h - len);\r\n        mint irot = 1, iimag = info.iroot[2];\r\
    \n        FOR(s, (1 << (len - 2))) {\r\n          mint irot2 = irot * irot;\r\n\
    \          mint irot3 = irot2 * irot;\r\n          int offset = s << (h - len\
    \ + 2);\r\n          for (int i = 0; i < p; i++) {\r\n            auto a0 = 1ULL\
    \ * a[i + offset + 0 * p].val;\r\n            auto a1 = 1ULL * a[i + offset +\
    \ 1 * p].val;\r\n            auto a2 = 1ULL * a[i + offset + 2 * p].val;\r\n \
    \           auto a3 = 1ULL * a[i + offset + 3 * p].val;\r\n\r\n            auto\
    \ a2na3iimag\r\n                = 1ULL * mint((mint::get_mod() + a2 - a3) * iimag.val).val;\r\
    \n\r\n            a[i + offset] = a0 + a1 + a2 + a3;\r\n            a[i + offset\
    \ + 1 * p]\r\n                = (a0 + (mint::get_mod() - a1) + a2na3iimag) * irot.val;\r\
    \n            a[i + offset + 2 * p]\r\n                = (a0 + a1 + (mint::get_mod()\
    \ - a2) + (mint::get_mod() - a3))\r\n                  * irot2.val;\r\n      \
    \      a[i + offset + 3 * p]\r\n                = (a0 + (mint::get_mod() - a1)\
    \ + (mint::get_mod() - a2na3iimag))\r\n                  * irot3.val;\r\n    \
    \      }\r\n          irot *= info.irate3[topbit(~s & -~s)];\r\n        }\r\n\
    \        len -= 2;\r\n      }\r\n    }\r\n  }\r\n}\r\n#line 1 \"poly/fft.hpp\"\
    \nnamespace CFFT {\r\nusing real = double;\r\n\r\nstruct C {\r\n  real x, y;\r\
    \n\r\n  C() : x(0), y(0) {}\r\n\r\n  C(real x, real y) : x(x), y(y) {}\r\n  inline\
    \ C operator+(const C& c) const { return C(x + c.x, y + c.y); }\r\n  inline C\
    \ operator-(const C& c) const { return C(x - c.x, y - c.y); }\r\n  inline C operator*(const\
    \ C& c) const {\r\n    return C(x * c.x - y * c.y, x * c.y + y * c.x);\r\n  }\r\
    \n\r\n  inline C conj() const { return C(x, -y); }\r\n};\r\n\r\nconst real PI\
    \ = acosl(-1);\r\nint base = 1;\r\nvector<C> rts = {{0, 0}, {1, 0}};\r\nvector<int>\
    \ rev = {0, 1};\r\n\r\nvoid ensure_base(int nbase) {\r\n  if (nbase <= base) return;\r\
    \n  rev.resize(1 << nbase);\r\n  rts.resize(1 << nbase);\r\n  for (int i = 0;\
    \ i < (1 << nbase); i++) {\r\n    rev[i] = (rev[i >> 1] >> 1) + ((i & 1) << (nbase\
    \ - 1));\r\n  }\r\n  while (base < nbase) {\r\n    real angle = PI * 2.0 / (1\
    \ << (base + 1));\r\n    for (int i = 1 << (base - 1); i < (1 << base); i++) {\r\
    \n      rts[i << 1] = rts[i];\r\n      real angle_i = angle * (2 * i + 1 - (1\
    \ << base));\r\n      rts[(i << 1) + 1] = C(cos(angle_i), sin(angle_i));\r\n \
    \   }\r\n    ++base;\r\n  }\r\n}\r\n\r\nvoid fft(vector<C>& a, int n) {\r\n  assert((n\
    \ & (n - 1)) == 0);\r\n  int zeros = __builtin_ctz(n);\r\n  ensure_base(zeros);\r\
    \n  int shift = base - zeros;\r\n  for (int i = 0; i < n; i++) {\r\n    if (i\
    \ < (rev[i] >> shift)) { swap(a[i], a[rev[i] >> shift]); }\r\n  }\r\n  for (int\
    \ k = 1; k < n; k <<= 1) {\r\n    for (int i = 0; i < n; i += 2 * k) {\r\n   \
    \   for (int j = 0; j < k; j++) {\r\n        C z = a[i + j + k] * rts[j + k];\r\
    \n        a[i + j + k] = a[i + j] - z;\r\n        a[i + j] = a[i + j] + z;\r\n\
    \      }\r\n    }\r\n  }\r\n}\r\n} // namespace CFFT\n#line 7 \"poly/convolution.hpp\"\
    \n\r\ntemplate <class mint>\r\nvector<mint> convolution_ntt(vector<mint> a, vector<mint>\
    \ b) {\r\n  int n = int(a.size()), m = int(b.size());\r\n  int sz = 1;\r\n  while\
    \ (sz < n + m - 1) sz *= 2;\r\n\r\n  // sz = 2^k \u306E\u3068\u304D\u306E\u9AD8\
    \u901F\u5316\u3002\u5206\u5272\u7D71\u6CBB\u7684\u306A\u3084\u3064\u3067\u640D\
    \u3057\u307E\u304F\u308B\u306E\u3067\u3002\r\n  if ((n + m - 3) <= sz / 2) {\r\
    \n    auto a_last = a.back(), b_last = b.back();\r\n    a.pop_back(), b.pop_back();\r\
    \n    auto c = convolution(a, b);\r\n    c.resize(n + m - 1);\r\n    c[n + m -\
    \ 2] = a_last * b_last;\r\n    FOR(i, len(a)) c[i + len(b)] += a[i] * b_last;\r\
    \n    FOR(i, len(b)) c[i + len(a)] += b[i] * a_last;\r\n    return c;\r\n  }\r\
    \n\r\n  a.resize(sz), b.resize(sz);\r\n  bool same = a == b;\r\n  ntt(a, 0);\r\
    \n  if (same) {\r\n    b = a;\r\n  } else {\r\n    ntt(b, 0);\r\n  }\r\n  FOR(i,\
    \ sz) a[i] *= b[i];\r\n  ntt(a, 1);\r\n  a.resize(n + m - 1);\r\n  return a;\r\
    \n}\r\n\r\ntemplate <typename mint>\r\nvector<mint> convolution_garner(const vector<mint>&\
    \ a, const vector<mint>& b) {\r\n  int n = len(a), m = len(b);\r\n  if (!n ||\
    \ !m) return {};\r\n  static const long long nttprimes[] = {754974721, 167772161,\
    \ 469762049};\r\n  using mint0 = modint<754974721>;\r\n  using mint1 = modint<167772161>;\r\
    \n  using mint2 = modint<469762049>;\r\n  vc<mint0> a0(n), b0(m);\r\n  vc<mint1>\
    \ a1(n), b1(m);\r\n  vc<mint2> a2(n), b2(m);\r\n  FOR(i, n) a0[i] = a[i].val,\
    \ a1[i] = a[i].val, a2[i] = a[i].val;\r\n  FOR(i, m) b0[i] = b[i].val, b1[i] =\
    \ b[i].val, b2[i] = b[i].val;\r\n  auto c0 = convolution_ntt<mint0>(a0, b0);\r\
    \n  auto c1 = convolution_ntt<mint1>(a1, b1);\r\n  auto c2 = convolution_ntt<mint2>(a2,\
    \ b2);\r\n  static const long long m01 = 1LL * nttprimes[0] * nttprimes[1];\r\n\
    \  static const long long m0_inv_m1 = mint1(nttprimes[0]).inverse().val;\r\n \
    \ static const long long m01_inv_m2 = mint2(m01).inverse().val;\r\n  static const\
    \ int mod = mint::get_mod();\r\n  auto garner = [&](mint0 x0, mint1 x1, mint2\
    \ x2) -> mint {\r\n    int r0 = x0.val, r1 = x1.val, r2 = x2.val;\r\n    int v1\
    \ = (m0_inv_m1 * (r1 + nttprimes[1] - r0)) % nttprimes[1];\r\n    auto v2 = (mint2(r2)\
    \ - r0 - mint2(nttprimes[0]) * v1) * mint2(m01_inv_m2);\r\n    return mint(r0\
    \ + 1LL * nttprimes[0] * v1 + m01 % mod * v2.val);\r\n  };\r\n  vc<mint> c(len(c0));\r\
    \n  FOR(i, len(c)) c[i] = garner(c0[i], c1[i], c2[i]);\r\n  return c;\r\n}\r\n\
    \r\ntemplate <typename R>\r\nvc<double> convolution_fft(const vc<R>& a, const\
    \ vc<R>& b) {\r\n  using C = CFFT::C;\r\n  int need = (int)a.size() + (int)b.size()\
    \ - 1;\r\n  int nbase = 1;\r\n  while ((1 << nbase) < need) nbase++;\r\n  CFFT::ensure_base(nbase);\r\
    \n  int sz = 1 << nbase;\r\n  vector<C> fa(sz);\r\n  for (int i = 0; i < sz; i++)\
    \ {\r\n    int x = (i < (int)a.size() ? a[i] : 0);\r\n    int y = (i < (int)b.size()\
    \ ? b[i] : 0);\r\n    fa[i] = C(x, y);\r\n  }\r\n  CFFT::fft(fa, sz);\r\n  C r(0,\
    \ -0.25 / (sz >> 1)), s(0, 1), t(0.5, 0);\r\n  for (int i = 0; i <= (sz >> 1);\
    \ i++) {\r\n    int j = (sz - i) & (sz - 1);\r\n    C z = (fa[j] * fa[j] - (fa[i]\
    \ * fa[i]).conj()) * r;\r\n    fa[j] = (fa[i] * fa[i] - (fa[j] * fa[j]).conj())\
    \ * r;\r\n    fa[i] = z;\r\n  }\r\n  for (int i = 0; i < (sz >> 1); i++) {\r\n\
    \    C A0 = (fa[i] + fa[i + (sz >> 1)]) * t;\r\n    C A1 = (fa[i] - fa[i + (sz\
    \ >> 1)]) * t * CFFT::rts[(sz >> 1) + i];\r\n    fa[i] = A0 + A1 * s;\r\n  }\r\
    \n  CFFT::fft(fa, sz >> 1);\r\n  vector<double> ret(need);\r\n  for (int i = 0;\
    \ i < need; i++) {\r\n    ret[i] = (i & 1 ? fa[i >> 1].y : fa[i >> 1].x);\r\n\
    \  }\r\n  return ret;\r\n}\r\n\r\nvector<ll> convolution(const vector<ll>& a,\
    \ const vector<ll>& b) {\r\n  int n = len(a), m = len(b);\r\n  if (!n || !m) return\
    \ {};\r\n  if (min(n, m) <= 60) return convolution_naive(a, b);\r\n  ll abs_sum_a\
    \ = 0, abs_sum_b = 0;\r\n  ll LIM = 1e15;\r\n  FOR(i, n) abs_sum_a = min(LIM,\
    \ abs_sum_a + abs(a[i]));\r\n  FOR(i, n) abs_sum_b = min(LIM, abs_sum_b + abs(b[i]));\r\
    \n  if (i128(abs_sum_a) * abs_sum_b < 1e15) {\r\n    vc<double> c = convolution_fft<ll>(a,\
    \ b);\r\n    vc<ll> res(len(c));\r\n    FOR(i, len(c)) res[i] = ll(floor(c[i]\
    \ + .5));\r\n    return res;\r\n  }\r\n\r\n  static constexpr unsigned long long\
    \ MOD1 = 754974721; // 2^24\r\n  static constexpr unsigned long long MOD2 = 167772161;\
    \ // 2^25\r\n  static constexpr unsigned long long MOD3 = 469762049; // 2^26\r\
    \n  static constexpr unsigned long long M2M3 = MOD2 * MOD3;\r\n  static constexpr\
    \ unsigned long long M1M3 = MOD1 * MOD3;\r\n  static constexpr unsigned long long\
    \ M1M2 = MOD1 * MOD2;\r\n  static constexpr unsigned long long M1M2M3 = MOD1 *\
    \ MOD2 * MOD3;\r\n\r\n  static const unsigned long long i1 = mod_inv(MOD2 * MOD3,\
    \ MOD1);\r\n  static const unsigned long long i2 = mod_inv(MOD1 * MOD3, MOD2);\r\
    \n  static const unsigned long long i3 = mod_inv(MOD1 * MOD2, MOD3);\r\n\r\n \
    \ using mint1 = modint<MOD1>;\r\n  using mint2 = modint<MOD2>;\r\n  using mint3\
    \ = modint<MOD3>;\r\n\r\n  vc<mint1> a1(n), b1(m);\r\n  vc<mint2> a2(n), b2(m);\r\
    \n  vc<mint3> a3(n), b3(m);\r\n  FOR(i, n) a1[i] = a[i], a2[i] = a[i], a3[i] =\
    \ a[i];\r\n  FOR(i, m) b1[i] = b[i], b2[i] = b[i], b3[i] = b[i];\r\n\r\n  auto\
    \ c1 = convolution_ntt<mint1>(a1, b1);\r\n  auto c2 = convolution_ntt<mint2>(a2,\
    \ b2);\r\n  auto c3 = convolution_ntt<mint3>(a3, b3);\r\n\r\n  vc<ll> c(n + m\
    \ - 1);\r\n  FOR(i, n + m - 1) {\r\n    u64 x = 0;\r\n    x += (c1[i].val * i1)\
    \ % MOD1 * M2M3;\r\n    x += (c2[i].val * i2) % MOD2 * M1M3;\r\n    x += (c3[i].val\
    \ * i3) % MOD3 * M1M2;\r\n    ll diff = c1[i].val - ((long long)(x) % (long long)(MOD1));\r\
    \n    if (diff < 0) diff += MOD1;\r\n    static constexpr unsigned long long offset[5]\r\
    \n        = {0, 0, M1M2M3, 2 * M1M2M3, 3 * M1M2M3};\r\n    x -= offset[diff %\
    \ 5];\r\n    c[i] = x;\r\n  }\r\n  return c;\r\n}\r\n\r\ntemplate <typename mint>\r\
    \nenable_if_t<is_same<mint, modint998>::value, vc<mint>> convolution(\r\n    const\
    \ vc<mint>& a, const vc<mint>& b) {\r\n  int n = len(a), m = len(b);\r\n  if (!n\
    \ || !m) return {};\r\n  if (min(n, m) <= 60) return convolution_naive(a, b);\r\
    \n  return convolution_ntt(a, b);\r\n}\r\n\r\ntemplate <typename mint>\r\nenable_if_t<!is_same<mint,\
    \ modint998>::value, vc<mint>> convolution(\r\n    const vc<mint>& a, const vc<mint>&\
    \ b) {\r\n  int n = len(a), m = len(b);\r\n  if (!n || !m) return {};\r\n  if\
    \ (min(n, m) <= 60) return convolution_naive(a, b);\r\n  return convolution_garner(a,\
    \ b);\r\n}\r\n#line 4 \"poly/fps_inv.hpp\"\n\r\ntemplate <typename mint>\r\nvc<mint>\
    \ fps_inv_sparse(const vc<mint>& f) {\r\n  assert(f[0] != mint(0));\r\n  int N\
    \ = len(f);\r\n  vc<pair<int, mint>> dat;\r\n  FOR3(i, 1, N) if (f[i] != mint(0))\
    \ dat.eb(i, f[i]);\r\n  vc<mint> g(N);\r\n  mint g0 = mint(1) / f[0];\r\n  g[0]\
    \ = g0;\r\n  FOR3(n, 1, N) {\r\n    mint rhs = 0;\r\n    for (auto&& [k, fk]:\
    \ dat) {\r\n      if (k > n) break;\r\n      rhs -= fk * g[n - k];\r\n    }\r\n\
    \    g[n] = rhs * g0;\r\n  }\r\n  return g;\r\n}\r\n\r\ntemplate <typename mint>\r\
    \nenable_if_t<is_same<mint, modint998>::value, vc<mint>> fps_inv_dense(\r\n  \
    \  const vc<mint>& F) {\r\n  assert(F[0] != mint(0));\r\n  vc<mint> G = {mint(1)\
    \ / F[0]};\r\n  G.reserve(len(F));\r\n  ll N = len(F), n = 1;\r\n  while (n <\
    \ N) {\r\n    vc<mint> f(2 * n), g(2 * n);\r\n    FOR(i, min(N, 2 * n)) f[i] =\
    \ F[i];\r\n    FOR(i, n) g[i] = G[i];\r\n    ntt(f, false);\r\n    ntt(g, false);\r\
    \n    FOR(i, 2 * n) f[i] *= g[i];\r\n    ntt(f, true);\r\n    FOR(i, n) f[i] =\
    \ 0;\r\n    ntt(f, false);\r\n    FOR(i, 2 * n) f[i] *= g[i];\r\n    ntt(f, true);\r\
    \n    FOR3(i, n, 2 * n) G.eb(f[i] * mint(-1));\r\n    n *= 2;\r\n  }\r\n  G.resize(N);\r\
    \n  return G;\r\n}\r\n\r\ntemplate <typename mint>\r\nenable_if_t<!is_same<mint,\
    \ modint998>::value, vc<mint>> fps_inv_dense(\r\n    const vc<mint>& F) {\r\n\
    \  int N = len(F);\r\n  assert(F[0] != mint(0));\r\n  vc<mint> R = {mint(1) /\
    \ F[0]};\r\n  vc<mint> p;\r\n  int m = 1;\r\n  while (m < N) {\r\n    p = convolution(R,\
    \ R);\r\n    p.resize(m + m);\r\n    vc<mint> f = {F.begin(), F.begin() + min(m\
    \ + m, N)};\r\n    p = convolution(p, f);\r\n    R.resize(m + m);\r\n    FOR(i,\
    \ m + m) R[i] = R[i] + R[i] - p[i];\r\n    m += m;\r\n  }\r\n  R.resize(N);\r\n\
    \  return R;\r\n}\r\n\r\n\r\ntemplate <typename mint>\r\nenable_if_t<is_same<mint,\
    \ modint998>::value, vc<mint>> fps_inv(\r\n    const vc<mint>& f) {\r\n  if (count_terms(f)\
    \ <= 200) return fps_inv_sparse<mint>(f);\r\n  return fps_inv_dense<mint>(f);\r\
    \n}\r\n\r\ntemplate <typename mint>\r\nenable_if_t<!is_same<mint, modint998>::value,\
    \ vc<mint>> fps_inv(\r\n    const vc<mint>& f) {\r\n  if (count_terms(f) <= 700)\
    \ return fps_inv_sparse<mint>(f);\r\n  return fps_inv_dense<mint>(f);\r\n}\r\n\
    #line 2 \"poly/integrate.hpp\"\n\ntemplate <typename mint>\nvc<mint> integrate(const\
    \ vc<mint>& f) {\n  vc<mint> g(len(f) + 1);\n  FOR3(i, 1, len(g)) g[i] = f[i -\
    \ 1] * inv<mint>(i);\n  return g;\n}\n#line 2 \"poly/differentiate.hpp\"\n\ntemplate\
    \ <typename mint>\nvc<mint> differentiate(const vc<mint>& f) {\n  if (len(f) <=\
    \ 1) return {};\n  vc<mint> g(len(f) - 1);\n  FOR(i, len(g)) g[i] = f[i + 1] *\
    \ mint(i + 1);\n  return g;\n}\n#line 6 \"poly/fps_exp.hpp\"\n\r\ntemplate <typename\
    \ mint>\r\nenable_if_t<is_same<mint, modint998>::value, vc<mint>> fps_exp(vc<mint>&\
    \ f) {\r\n  if (count_terms(f) <= 300) return fps_exp_sparse(f);\r\n  return fps_exp_dense(f);\r\
    \n}\r\n\r\ntemplate <typename mint>\r\nenable_if_t<!is_same<mint, modint998>::value,\
    \ vc<mint>> fps_exp(vc<mint>& f) {\r\n  if (count_terms(f) <= 1000) return fps_exp_sparse(f);\r\
    \n  return fps_exp_dense(f);\r\n}\r\n\r\ntemplate <typename mint>\r\nvc<mint>\
    \ fps_exp_sparse(vc<mint>& f) {\r\n  if (len(f) == 0) return {mint(1)};\r\n  assert(f[0]\
    \ == 0);\r\n  int N = len(f);\r\n  // df \u3092\u6301\u305F\u305B\u308B\r\n  vc<pair<int,\
    \ mint>> dat;\r\n  FOR(i, 1, N) if (f[i] != mint(0)) dat.eb(i - 1, mint(i) * f[i]);\r\
    \n  vc<mint> F(N);\r\n  F[0] = 1;\r\n  FOR(n, 1, N) {\r\n    mint rhs = 0;\r\n\
    \    for (auto&& [k, fk]: dat) {\r\n      if (k > n - 1) break;\r\n      rhs +=\
    \ fk * F[n - 1 - k];\r\n    }\r\n    F[n] = rhs * inv<mint>(n);\r\n  }\r\n  return\
    \ F;\r\n}\r\n\r\ntemplate <typename mint>\r\nenable_if_t<!is_same<mint, modint998>::value,\
    \ vc<mint>> fps_exp_dense(\r\n    vc<mint> h) {\r\n  const int L = len(h);\r\n\
    \  assert(L > 0 && h[0] == mint(0));\r\n  int LOG = 0;\r\n  while (1 << LOG <\
    \ L) ++LOG;\r\n  h.resize(1 << LOG);\r\n  auto dh = differentiate(h);\r\n  vc<mint>\
    \ f = {1}, g = {1};\r\n  int m = 1;\r\n\r\n  vc<mint> p;\r\n\r\n  FOR(LOG) {\r\
    \n    p = convolution(f, g);\r\n    p.resize(m);\r\n    p = convolution(p, g);\r\
    \n    p.resize(m);\r\n    g.resize(m);\r\n    FOR(i, m) g[i] += g[i] - p[i];\r\
    \n    p = {dh.begin(), dh.begin() + m - 1};\r\n    p = convolution(f, p);\r\n\
    \    p.resize(m + m - 1);\r\n    FOR(i, m + m - 1) p[i] = -p[i];\r\n    FOR(i,\
    \ m - 1) p[i] += mint(i + 1) * f[i + 1];\r\n    p = convolution(p, g);\r\n\r\n\
    \    p.resize(m + m - 1);\r\n    FOR(i, m - 1) p[i] += dh[i];\r\n    p = integrate(p);\r\
    \n    FOR(i, m + m) p[i] = h[i] - p[i];\r\n    p[0] += mint(1);\r\n    f = convolution(f,\
    \ p);\r\n    f.resize(m + m);\r\n    m += m;\r\n  }\r\n  f.resize(L);\r\n  return\
    \ f;\r\n}\r\n\r\n// ntt \u7D20\u6570\u5C02\u7528\u5B9F\u88C5\u3002\u9577\u3055\
    \ n \u306E FFT \u3092\u5229\u7528\u3057\u3066 2n \u306E FFT\r\n// \u3092\u884C\
    \u3046\u306A\u3069\u306E\u9AD8\u901F\u5316\u3092\u3057\u3066\u3044\u308B\u3002\
    \r\ntemplate <typename mint>\r\nenable_if_t<is_same<mint, modint998>::value, vc<mint>>\
    \ fps_exp_dense(\r\n    vc<mint>& f) {\r\n  const int n = len(f);\r\n  assert(n\
    \ > 0 && f[0] == mint(0));\r\n  vc<mint> b = {1, (1 < n ? f[1] : 0)};\r\n  vc<mint>\
    \ c = {1}, z1, z2 = {1, 1};\r\n  while (len(b) < n) {\r\n    int m = len(b);\r\
    \n    auto y = b;\r\n    y.resize(2 * m);\r\n    ntt(y, 0);\r\n    z1 = z2;\r\n\
    \    vc<mint> z(m);\r\n    FOR(i, m) z[i] = y[i] * z1[i];\r\n    ntt(z, 1);\r\n\
    \    FOR(i, m / 2) z[i] = 0;\r\n    ntt(z, 0);\r\n    FOR(i, m) z[i] *= -z1[i];\r\
    \n    ntt(z, 1);\r\n    c.insert(c.end(), z.begin() + m / 2, z.end());\r\n   \
    \ z2 = c;\r\n    z2.resize(2 * m);\r\n    ntt(z2, 0);\r\n\r\n    vc<mint> x(f.begin(),\
    \ f.begin() + m);\r\n    FOR(i, len(x) - 1) x[i] = x[i + 1] * mint(i + 1);\r\n\
    \    x.back() = 0;\r\n    ntt(x, 0);\r\n    FOR(i, m) x[i] *= y[i];\r\n    ntt(x,\
    \ 1);\r\n\r\n    FOR(i, m - 1) x[i] -= b[i + 1] * mint(i + 1);\r\n\r\n    x.resize(m\
    \ + m);\r\n    FOR(i, m - 1) x[m + i] = x[i], x[i] = 0;\r\n    ntt(x, 0);\r\n\
    \    FOR(i, m + m) x[i] *= z2[i];\r\n    ntt(x, 1);\r\n    FOR_R(i, len(x) - 1)\
    \ x[i + 1] = x[i] * inv<mint>(i + 1);\r\n    x[0] = 0;\r\n\r\n    FOR3(i, m, min(n,\
    \ m + m)) x[i] += f[i];\r\n    FOR(i, m) x[i] = 0;\r\n    ntt(x, 0);\r\n    FOR(i,\
    \ m + m) x[i] *= y[i];\r\n    ntt(x, 1);\r\n    b.insert(b.end(), x.begin() +\
    \ m, x.end());\r\n  }\r\n  b.resize(n);\r\n  return b;\r\n}\r\n#line 2 \"poly/fps_log.hpp\"\
    \n\r\n#line 5 \"poly/fps_log.hpp\"\n\r\ntemplate <typename mint>\r\nvc<mint> fps_log_dense(const\
    \ vc<mint>& f) {\r\n  assert(f[0] == mint(1));\r\n  ll N = len(f);\r\n  vc<mint>\
    \ df = f;\r\n  FOR(i, N) df[i] *= mint(i);\r\n  df.erase(df.begin());\r\n  auto\
    \ f_inv = fps_inv(f);\r\n  auto g = convolution(df, f_inv);\r\n  g.resize(N -\
    \ 1);\r\n  g.insert(g.begin(), 0);\r\n  FOR(i, N) g[i] *= inv<mint>(i);\r\n  return\
    \ g;\r\n}\r\n\r\ntemplate<typename mint>\r\nvc<mint> fps_log_sparse(const vc<mint>&\
    \ f){\r\n  int N = f.size();\r\n  vc<pair<int, mint>> dat;\r\n  FOR(i, 1, N) if(f[i]\
    \ != mint(0)) dat.eb(i, f[i]);\r\n\r\n  vc<mint> F(N);\r\n  vc<mint> g(N - 1);\r\
    \n  for (int n = 0; n < N - 1; ++n) {\r\n    mint rhs = mint(n + 1) * f[n + 1];\r\
    \n    for (auto &&[i, fi]: dat) {\r\n      if (i > n) break;\r\n      rhs -= fi\
    \ * g[n - i];\r\n    }\r\n    g[n] = rhs;\r\n    F[n + 1] = rhs * inv<mint>(n\
    \ + 1);\r\n  }\r\n  return F;\r\n}\r\n\r\ntemplate<typename mint>\r\nvc<mint>\
    \ fps_log(const vc<mint>& f){\r\n  assert(f[0] == mint(1));\r\n  if(count_terms(f)\
    \ <= 200) return fps_log_sparse(f);\r\n  return fps_log_dense(f);\r\n}\r\n#line\
    \ 5 \"poly/fps_pow.hpp\"\n\r\n// fps \u306E k \u4E57\u3092\u6C42\u3081\u308B\u3002\
    k >= 0 \u306E\u524D\u63D0\u3067\u3042\u308B\u3002\r\n// \u5B9A\u6570\u9805\u304C\
    \ 1 \u3067\u3001k \u304C mint \u306E\u5834\u5408\u306B\u306F\u3001fps_pow_1 \u3092\
    \u4F7F\u3046\u3053\u3068\u3002\r\n// \u30FBdense \u306A\u5834\u5408\uFF1A log,\
    \ exp \u3092\u4F7F\u3046 O(NlogN)\r\n// \u30FBsparse \u306A\u5834\u5408\uFF1A\
    \ O(NK)\r\ntemplate <typename mint>\r\nvc<mint> fps_pow(const vc<mint>& f, ll\
    \ k) {\r\n  assert(0 <= k);\r\n  int n = len(f);\r\n  if(k==0){\r\n    vc<mint>\
    \ g(n);\r\n    g[0] = mint(1);\r\n    return g;\r\n  }\r\n  int d = n;\r\n  FOR_R(i,\
    \ n) if (f[i] != 0) d = i;\r\n  // d * k >= n\r\n  if(d >= ceil(n,k)){\r\n   \
    \ vc<mint> g(n);\r\n    return g;\r\n  }\r\n  ll off = d * k;\r\n  mint c = f[d];\r\
    \n  mint c_inv = mint(1) / mint(c);\r\n  vc<mint> g(n - off);\r\n  FOR(i, n -\
    \ off) g[i] = f[d + i] * c_inv;\r\n  g = fps_pow_1(g, mint(k));\r\n  vc<mint>\
    \ h(n);\r\n  c = c.pow(k);\r\n  FOR(i, len(g)) h[off + i] = g[i] * c;\r\n  return\
    \ h;\r\n}\r\n\r\ntemplate <typename mint>\r\nvc<mint> fps_pow_1_sparse(const vc<mint>&\
    \ f, mint K) {\r\n  int N = len(f);\r\n  vc<pair<int, mint>> dat;\r\n  FOR3(i,\
    \ 1, N) if (f[i] != mint(0)) dat.eb(i, f[i]);\r\n  vc<mint> g(N);\r\n  g[0] =\
    \ 1;\r\n  FOR(n, N - 1) {\r\n    mint& x = g[n + 1];\r\n    for (auto&& [d, cf]:\
    \ dat) {\r\n      if (d > n + 1) break;\r\n      mint t = cf * g[n - d + 1];\r\
    \n      x += t * (K * mint(d) - mint(n - d + 1));\r\n    }\r\n    x *= inv<mint>(n\
    \ + 1);\r\n  }\r\n  return g;\r\n}\r\n\r\ntemplate <typename mint>\r\nvc<mint>\
    \ fps_pow_1_dense(const vc<mint>& f, mint K) {\r\n  assert(f[0] == mint(1));\r\
    \n  auto log_f = fps_log(f);\r\n  FOR(i, len(f)) log_f[i] *= K;\r\n  return fps_exp(log_f);\r\
    \n}\r\n\r\ntemplate <typename mint>\r\nvc<mint> fps_pow_1(const vc<mint>& f, mint\
    \ K) {\r\n  if (count_terms(f) <= 100) return fps_pow_1_sparse(f, K);\r\n  return\
    \ fps_pow_1_dense(f, K);\r\n}\r\n#line 2 \"random/base.hpp\"\n\nu64 RNG_64() {\n\
    \  static uint64_t x_\n      = uint64_t(chrono::duration_cast<chrono::nanoseconds>(\n\
    \                     chrono::high_resolution_clock::now().time_since_epoch())\n\
    \                     .count())\n        * 10150724397891781847ULL;\n  x_ ^= x_\
    \ << 7;\n  return x_ ^= x_ >> 9;\n}\n\nu64 RNG(u64 lim) { return RNG_64() % lim;\
    \ }\n\nll RNG(ll l, ll r) { return l + RNG_64() % (r - l); }\n#line 3 \"mod/mod_sqrt.hpp\"\
    \n\r\ntemplate <typename mint>\r\nmint mod_sqrt(mint a) {\r\n  int p = mint::get_mod();\r\
    \n  if (p == 2) return a;\r\n  if (a == 0) return 0;\r\n  int k = (p - 1) / 2;\r\
    \n  if (a.pow(k) != 1) return 0;\r\n  auto find = [&]() -> pair<mint, mint> {\r\
    \n    while (1) {\r\n      mint b = RNG(2, p);\r\n      mint D = b * b - a;\r\n\
    \      if (D == 0) return {b, D};\r\n      if (D.pow(k) != mint(1)) return {b,\
    \ D};\r\n    }\r\n  };\r\n  auto [b, D] = find();\r\n  if (D == 0) return b;\r\
    \n  ++k;\r\n  // (b + sqrt(D))^k\r\n  mint f0 = b, f1 = 1;\r\n  mint g0 = 1, g1\
    \ = 0;\r\n  while (k) {\r\n    if (k & 1) { tie(g0, g1) = mp(f0 * g0 + D * f1\
    \ * g1, f1 * g0 + f0 * g1); }\r\n    tie(f0, f1) = mp(f0 * f0 + D * f1 * f1, mint(2)\
    \ * f0 * f1);\r\n    k >>= 1;\r\n  }\r\n  return g0;\r\n}\r\n#line 5 \"poly/fps_sqrt.hpp\"\
    \n\r\ntemplate <typename mint>\r\nvc<mint> fps_sqrt_dense(vc<mint>& f) {\r\n \
    \ assert(f[0] == mint(1));\r\n  int n = len(f);\r\n  vc<mint> R = {1};\r\n  while\
    \ (len(R) < n) {\r\n    int m = min(2 * int(len(R)), n);\r\n    R.resize(m);\r\
    \n    vc<mint> tmp = {f.begin(), f.begin() + m};\r\n    tmp = convolution(tmp,\
    \ fps_inv(R));\r\n    tmp.resize(m);\r\n    FOR(i, m) R[i] += tmp[i];\r\n    mint\
    \ c = mint(1) / mint(2);\r\n    FOR(i, len(R)) R[i] *= c;\r\n  }\r\n  R.resize(n);\r\
    \n  return R;\r\n}\r\n\r\ntemplate <typename mint>\r\nvc<mint> fps_sqrt_sparse(vc<mint>&\
    \ f) {\r\n  return fps_pow_1_sparse(f, inv<mint>(2));\r\n}\r\n\r\ntemplate <typename\
    \ mint>\r\nvc<mint> fps_sqrt(vc<mint>& f) {\r\n  if (count_terms(f) <= 200) return\
    \ fps_sqrt_sparse(f);\r\n  return fps_sqrt_dense(f);\r\n}\r\n\r\ntemplate <typename\
    \ mint>\r\nvc<mint> fps_sqrt_any(vc<mint>& f) {\r\n  int n = len(f);\r\n  int\
    \ d = n;\r\n  FOR_R(i, n) if (f[i] != 0) d = i;\r\n  if (d == n) return f;\r\n\
    \  if (d & 1) return {};\r\n  mint y = f[d];\r\n  mint x = mod_sqrt(y);\r\n  if\
    \ (x * x != y) return {};\r\n  mint c = mint(1) / y;\r\n  vc<mint> g(n - d);\r\
    \n  FOR(i, n - d) g[i] = f[d + i] * c;\r\n  g = fps_sqrt(g);\r\n  FOR(i, len(g))\
    \ g[i] *= x;\r\n  g.resize(n);\r\n  FOR_R(i, n) {\r\n    if (i >= d / 2)\r\n \
    \     g[i] = g[i - d / 2];\r\n    else\r\n      g[i] = 0;\r\n  }\r\n  return g;\r\
    \n}\r\n"
  code: "#include \"poly/fps_inv.hpp\"\r\n#include \"poly/fps_pow.hpp\"\r\n#include\
    \ \"poly/count_terms.hpp\"\r\n#include \"mod/mod_sqrt.hpp\"\r\n\r\ntemplate <typename\
    \ mint>\r\nvc<mint> fps_sqrt_dense(vc<mint>& f) {\r\n  assert(f[0] == mint(1));\r\
    \n  int n = len(f);\r\n  vc<mint> R = {1};\r\n  while (len(R) < n) {\r\n    int\
    \ m = min(2 * int(len(R)), n);\r\n    R.resize(m);\r\n    vc<mint> tmp = {f.begin(),\
    \ f.begin() + m};\r\n    tmp = convolution(tmp, fps_inv(R));\r\n    tmp.resize(m);\r\
    \n    FOR(i, m) R[i] += tmp[i];\r\n    mint c = mint(1) / mint(2);\r\n    FOR(i,\
    \ len(R)) R[i] *= c;\r\n  }\r\n  R.resize(n);\r\n  return R;\r\n}\r\n\r\ntemplate\
    \ <typename mint>\r\nvc<mint> fps_sqrt_sparse(vc<mint>& f) {\r\n  return fps_pow_1_sparse(f,\
    \ inv<mint>(2));\r\n}\r\n\r\ntemplate <typename mint>\r\nvc<mint> fps_sqrt(vc<mint>&\
    \ f) {\r\n  if (count_terms(f) <= 200) return fps_sqrt_sparse(f);\r\n  return\
    \ fps_sqrt_dense(f);\r\n}\r\n\r\ntemplate <typename mint>\r\nvc<mint> fps_sqrt_any(vc<mint>&\
    \ f) {\r\n  int n = len(f);\r\n  int d = n;\r\n  FOR_R(i, n) if (f[i] != 0) d\
    \ = i;\r\n  if (d == n) return f;\r\n  if (d & 1) return {};\r\n  mint y = f[d];\r\
    \n  mint x = mod_sqrt(y);\r\n  if (x * x != y) return {};\r\n  mint c = mint(1)\
    \ / y;\r\n  vc<mint> g(n - d);\r\n  FOR(i, n - d) g[i] = f[d + i] * c;\r\n  g\
    \ = fps_sqrt(g);\r\n  FOR(i, len(g)) g[i] *= x;\r\n  g.resize(n);\r\n  FOR_R(i,\
    \ n) {\r\n    if (i >= d / 2)\r\n      g[i] = g[i - d / 2];\r\n    else\r\n  \
    \    g[i] = 0;\r\n  }\r\n  return g;\r\n}\r\n"
  dependsOn:
  - poly/fps_inv.hpp
  - poly/count_terms.hpp
  - poly/convolution.hpp
  - mod/modint.hpp
  - mod/mod_inv.hpp
  - poly/convolution_naive.hpp
  - poly/ntt.hpp
  - poly/fft.hpp
  - poly/fps_pow.hpp
  - poly/fps_exp.hpp
  - poly/integrate.hpp
  - poly/differentiate.hpp
  - poly/fps_log.hpp
  - mod/mod_sqrt.hpp
  - random/base.hpp
  isVerificationFile: false
  path: poly/fps_sqrt.hpp
  requiredBy: []
  timestamp: '2023-01-19 00:36:40+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/library_checker/polynomial/sqrt_of_fps.test.cpp
  - test/library_checker/polynomial/sqrt_of_fps_sparse.test.cpp
documentation_of: poly/fps_sqrt.hpp
layout: document
redirect_from:
- /library/poly/fps_sqrt.hpp
- /library/poly/fps_sqrt.hpp.html
title: poly/fps_sqrt.hpp
---
