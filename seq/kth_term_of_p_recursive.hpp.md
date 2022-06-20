---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: alg/group_mul.hpp
    title: alg/group_mul.hpp
  - icon: ':question:'
    path: ds/swag.hpp
    title: ds/swag.hpp
  - icon: ':x:'
    path: linalg/mat_mul.hpp
    title: linalg/mat_mul.hpp
  - icon: ':question:'
    path: mod/mod_inv.hpp
    title: mod/mod_inv.hpp
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
    path: poly/fft.hpp
    title: poly/fft.hpp
  - icon: ':x:'
    path: poly/lagrange_interpolate_iota.hpp
    title: poly/lagrange_interpolate_iota.hpp
  - icon: ':question:'
    path: poly/ntt.hpp
    title: poly/ntt.hpp
  - icon: ':x:'
    path: poly/prefix_product_of_poly.hpp
    title: poly/prefix_product_of_poly.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/yukicoder/502_p_rec.test.cpp
    title: test/yukicoder/502_p_rec.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 2 \"linalg/mat_mul.hpp\"\n\r\ntemplate <class T, is_modint_t<T>*\
    \ = nullptr>\r\nvc<vc<T>> mat_mul(const vc<vc<T>>& A, const vc<vc<T>>& B) {\r\n\
    \  // mod \u3092\u3068\u308B\u56DE\u6570\u3092\u6E1B\u3089\u3057\u3066\u307F\u308B\
    \r\n  auto N = len(A), M = len(B), K = len(B[0]);\r\n  vv(T, C, N, K);\r\n  const\
    \ u64 MOD2 = 8ull * T::get_mod() * T::get_mod();\r\n  FOR(n, N) {\r\n    vc<u64>\
    \ tmp(K);\r\n    FOR(m, M) FOR(k, K) {\r\n      tmp[k] += u64(A[n][m].val) * B[m][k].val;\r\
    \n      if (tmp[k] >= MOD2) tmp[k] -= MOD2;\r\n    }\r\n    FOR(k, K) C[n][k]\
    \ = tmp[k];\r\n  }\r\n  return C;\r\n}\r\n\r\ntemplate <class T, is_not_modint_t<T>*\
    \ = nullptr>\r\nvc<vc<T>> mat_mul(const vc<vc<T>>& A, const vc<vc<T>>& B) {\r\n\
    \  auto N = len(A), M = len(B), K = len(B[0]);\r\n  vv(T, C, N, K);\r\n  FOR(n,\
    \ N) FOR(m, M) FOR(k, K) C[n][k] += A[n][m] * B[m][k];\r\n  return C;\r\n}\r\n\
    #line 1 \"alg/group_mul.hpp\"\ntemplate <class T>\r\nstruct Group_Mul {\r\n  using\
    \ value_type = T;\r\n  using X = T;\r\n  static constexpr X op(const X &x, const\
    \ X &y) noexcept { return x * y; }\r\n  static constexpr X inverse(const X &x)\
    \ noexcept { return X(1) / x; }\r\n  static constexpr X unit() { return X(1);\
    \ }\r\n  static constexpr bool commute = true;\r\n};\r\n#line 1 \"ds/swag.hpp\"\
    \ntemplate <class Monoid>\nstruct SWAG {\n  using X = typename Monoid::value_type;\n\
    \  using value_type = X;\n  int sz = 0;\n  vc<X> dat;\n  vc<X> cum_l;\n  X cum_r;\n\
    \n  SWAG() : cum_l({Monoid::unit()}), cum_r(Monoid::unit()) {}\n\n  int size()\
    \ { return sz; }\n\n  void push(X x) {\n    ++sz;\n    cum_r = Monoid::op(cum_r,\
    \ x);\n    dat.eb(x);\n  }\n\n  void pop() {\n    --sz;\n    cum_l.pop_back();\n\
    \    if (len(cum_l) == 0) {\n      cum_l = {Monoid::unit()};\n      cum_r = Monoid::unit();\n\
    \      while (len(dat) > 1) {\n        cum_l.eb(Monoid::op(dat.back(), cum_l.back()));\n\
    \        dat.pop_back();\n      }\n      dat.pop_back();\n    }\n  }\n\n  X lprod()\
    \ { return cum_l.back(); }\n  X rprod() { return cum_r; }\n\n  X prod() { return\
    \ Monoid::op(cum_l.back(), cum_r); }\n\n  void debug() {\n    print(\"swag\");\n\
    \    print(\"dat\", dat);\n    print(\"cum_l\", cum_l);\n    print(\"cum_r\",\
    \ cum_r);\n  }\n};\n#line 2 \"mod/modint.hpp\"\ntemplate <u32 mod>\nstruct modint\
    \ {\n  static constexpr bool is_modint = true;\n  u32 val;\n  constexpr modint(const\
    \ ll val = 0) noexcept\n      : val(val >= 0 ? val % mod : (mod - (-val) % mod)\
    \ % mod) {}\n  bool operator<(const modint &other) const {\n    return val < other.val;\n\
    \  } // To use std::map\n  modint &operator+=(const modint &p) {\n    if ((val\
    \ += p.val) >= mod) val -= mod;\n    return *this;\n  }\n  modint &operator-=(const\
    \ modint &p) {\n    if ((val += mod - p.val) >= mod) val -= mod;\n    return *this;\n\
    \  }\n  modint &operator*=(const modint &p) {\n    val = (u32)(1LL * val * p.val\
    \ % mod);\n    return *this;\n  }\n  modint &operator/=(const modint &p) {\n \
    \   *this *= p.inverse();\n    return *this;\n  }\n  modint operator-() const\
    \ { return modint(get_mod() - val); }\n  modint operator+(const modint &p) const\
    \ { return modint(*this) += p; }\n  modint operator-(const modint &p) const {\
    \ return modint(*this) -= p; }\n  modint operator*(const modint &p) const { return\
    \ modint(*this) *= p; }\n  modint operator/(const modint &p) const { return modint(*this)\
    \ /= p; }\n  bool operator==(const modint &p) const { return val == p.val; }\n\
    \  bool operator!=(const modint &p) const { return val != p.val; }\n  modint inverse()\
    \ const {\n    int a = val, b = mod, u = 1, v = 0, t;\n    while (b > 0) {\n \
    \     t = a / b;\n      swap(a -= t * b, b), swap(u -= t * v, v);\n    }\n   \
    \ return modint(u);\n  }\n  modint pow(int64_t n) const {\n    modint ret(1),\
    \ mul(val);\n    while (n > 0) {\n      if (n & 1) ret *= mul;\n      mul *= mul;\n\
    \      n >>= 1;\n    }\n    return ret;\n  }\n  static constexpr u32 get_mod()\
    \ { return mod; }\n};\n\nstruct ArbitraryModInt {\n  static constexpr bool is_modint\
    \ = true;\n  u32 val;\n  ArbitraryModInt() : val(0) {}\n  ArbitraryModInt(int64_t\
    \ y)\n      : val(y >= 0 ? y % get_mod()\n                   : (get_mod() - (-y)\
    \ % get_mod()) % get_mod()) {}\n  bool operator<(const ArbitraryModInt &other)\
    \ const {\n    return val < other.val;\n  } // To use std::map<ArbitraryModInt,\
    \ T>\n  static u32 &get_mod() {\n    static u32 mod = 0;\n    return mod;\n  }\n\
    \  static void set_mod(int md) { get_mod() = md; }\n  ArbitraryModInt &operator+=(const\
    \ ArbitraryModInt &p) {\n    if ((val += p.val) >= get_mod()) val -= get_mod();\n\
    \    return *this;\n  }\n  ArbitraryModInt &operator-=(const ArbitraryModInt &p)\
    \ {\n    if ((val += get_mod() - p.val) >= get_mod()) val -= get_mod();\n    return\
    \ *this;\n  }\n  ArbitraryModInt &operator*=(const ArbitraryModInt &p) {\n   \
    \ unsigned long long a = (unsigned long long)val * p.val;\n    unsigned xh = (unsigned)(a\
    \ >> 32), xl = (unsigned)a, d, m;\n    asm(\"divl %4; \\n\\t\" : \"=a\"(d), \"\
    =d\"(m) : \"d\"(xh), \"a\"(xl), \"r\"(get_mod()));\n    val = m;\n    return *this;\n\
    \  }\n  ArbitraryModInt &operator/=(const ArbitraryModInt &p) {\n    *this *=\
    \ p.inverse();\n    return *this;\n  }\n  ArbitraryModInt operator-() const {\
    \ return ArbitraryModInt(get_mod() - val); }\n  ArbitraryModInt operator+(const\
    \ ArbitraryModInt &p) const {\n    return ArbitraryModInt(*this) += p;\n  }\n\
    \  ArbitraryModInt operator-(const ArbitraryModInt &p) const {\n    return ArbitraryModInt(*this)\
    \ -= p;\n  }\n  ArbitraryModInt operator*(const ArbitraryModInt &p) const {\n\
    \    return ArbitraryModInt(*this) *= p;\n  }\n  ArbitraryModInt operator/(const\
    \ ArbitraryModInt &p) const {\n    return ArbitraryModInt(*this) /= p;\n  }\n\
    \  bool operator==(const ArbitraryModInt &p) const { return val == p.val; }\n\
    \  bool operator!=(const ArbitraryModInt &p) const { return val != p.val; }\n\
    \  ArbitraryModInt inverse() const {\n    int a = val, b = get_mod(), u = 1, v\
    \ = 0, t;\n    while (b > 0) {\n      t = a / b;\n      swap(a -= t * b, b), swap(u\
    \ -= t * v, v);\n    }\n    return ArbitraryModInt(u);\n  }\n  ArbitraryModInt\
    \ pow(int64_t n) const {\n    ArbitraryModInt ret(1), mul(val);\n    while (n\
    \ > 0) {\n      if (n & 1) ret *= mul;\n      mul *= mul;\n      n >>= 1;\n  \
    \  }\n    return ret;\n  }\n};\n\ntemplate <typename mint>\nmint inv(int n) {\n\
    \  static const int mod = mint::get_mod();\n  static vector<mint> dat = {0, 1};\n\
    \  assert(0 <= n);\n  if (n >= mod) n %= mod;\n  while (int(dat.size()) <= n)\
    \ {\n    int k = dat.size();\n    auto q = (mod + k - 1) / k;\n    int r = k *\
    \ q - mod;\n    dat.emplace_back(dat[r] * mint(q));\n  }\n  return dat[n];\n}\n\
    \ntemplate <typename mint>\nmint fact(int n) {\n  static const int mod = mint::get_mod();\n\
    \  static vector<mint> dat = {1, 1};\n  assert(0 <= n);\n  if (n >= mod) return\
    \ 0;\n  while (int(dat.size()) <= n) {\n    int k = dat.size();\n    dat.emplace_back(dat[k\
    \ - 1] * mint(k));\n  }\n  return dat[n];\n}\n\ntemplate <typename mint>\nmint\
    \ fact_inv(int n) {\n  static const int mod = mint::get_mod();\n  static vector<mint>\
    \ dat = {1, 1};\n  assert(0 <= n && n < mod);\n  while (int(dat.size()) <= n)\
    \ {\n    int k = dat.size();\n    dat.emplace_back(dat[k - 1] * inv<mint>(k));\n\
    \  }\n  return dat[n];\n}\n\ntemplate <typename mint, bool large = false>\nmint\
    \ C(ll n, ll k) {\n  assert(n >= 0);\n  if (k < 0 || n < k) return 0;\n  if (!large)\
    \ return fact<mint>(n) * fact_inv<mint>(k) * fact_inv<mint>(n - k);\n  k = min(k,\
    \ n - k);\n  mint x(1);\n  FOR(i, k) { x *= mint(n - i); }\n  x *= fact_inv<mint>(k);\n\
    \  return x;\n}\n\ntemplate <typename mint, bool large = false>\nmint C_inv(ll\
    \ n, ll k) {\n  assert(n >= 0);\n  assert(0 <= k && k <= n);\n  if (!large) return\
    \ fact_inv<mint>(n) * fact<mint>(k) * fact<mint>(n - k);\n  return mint(1) / C<mint,\
    \ 1>(n, k);\n}\n\nusing modint107 = modint<1000000007>;\nusing modint998 = modint<998244353>;\n\
    using amint = ArbitraryModInt;\n#line 2 \"mod/mod_inv.hpp\"\n// long \u3067\u3082\
    \u5927\u4E08\u592B\r\nll mod_inv(ll val, ll mod) {\r\n  ll a = val, b = mod, u\
    \ = 1, v = 0, t;\r\n  while (b > 0) {\r\n    t = a / b;\r\n    swap(a -= t * b,\
    \ b), swap(u -= t * v, v);\r\n  }\r\n  if(u < 0) u += mod;\r\n  return u;\r\n\
    }\r\n#line 1 \"poly/convolution_naive.hpp\"\ntemplate <class T>\r\nvector<T> convolution_naive(const\
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
    \ 880803841) return 26;\r\n    if (m == 998244353) return 3;\r\n    return -1;\r\
    \n  }\r\n};\r\n\r\ntemplate <class mint>\r\nvoid ntt(vector<mint>& a, bool inverse)\
    \ {\r\n  int n = int(a.size());\r\n  int h = topbit(n);\r\n  assert(n == 1 <<\
    \ h);\r\n  static const ntt_info<mint> info;\r\n  if (!inverse) {\r\n    int len\
    \ = 0; // a[i, i+(n>>len), i+2*(n>>len), ..] is transformed\r\n    while (len\
    \ < h) {\r\n      if (h - len == 1) {\r\n        int p = 1 << (h - len - 1);\r\
    \n        mint rot = 1;\r\n        FOR(s, 1 << len) {\r\n          int offset\
    \ = s << (h - len);\r\n          FOR(i, p) {\r\n            auto l = a[i + offset];\r\
    \n            auto r = a[i + offset + p] * rot;\r\n            a[i + offset] =\
    \ l + r;\r\n            a[i + offset + p] = l - r;\r\n          }\r\n        \
    \  rot *= info.rate2[topbit(~s & -~s)];\r\n        }\r\n        len++;\r\n   \
    \   } else {\r\n        int p = 1 << (h - len - 2);\r\n        mint rot = 1, imag\
    \ = info.root[2];\r\n        for (int s = 0; s < (1 << len); s++) {\r\n      \
    \    mint rot2 = rot * rot;\r\n          mint rot3 = rot2 * rot;\r\n         \
    \ int offset = s << (h - len);\r\n          for (int i = 0; i < p; i++) {\r\n\
    \            auto mod2 = 1ULL * mint::get_mod() * mint::get_mod();\r\n       \
    \     auto a0 = 1ULL * a[i + offset].val;\r\n            auto a1 = 1ULL * a[i\
    \ + offset + p].val * rot.val;\r\n            auto a2 = 1ULL * a[i + offset +\
    \ 2 * p].val * rot2.val;\r\n            auto a3 = 1ULL * a[i + offset + 3 * p].val\
    \ * rot3.val;\r\n            auto a1na3imag = 1ULL * mint(a1 + mod2 - a3).val\
    \ * imag.val;\r\n            auto na2 = mod2 - a2;\r\n            a[i + offset]\
    \ = a0 + a2 + a1 + a3;\r\n            a[i + offset + 1 * p] = a0 + a2 + (2 * mod2\
    \ - (a1 + a3));\r\n            a[i + offset + 2 * p] = a0 + na2 + a1na3imag;\r\
    \n            a[i + offset + 3 * p] = a0 + na2 + (mod2 - a1na3imag);\r\n     \
    \     }\r\n          rot *= info.rate3[topbit(~s & -~s)];\r\n        }\r\n   \
    \     len += 2;\r\n      }\r\n    }\r\n  } else {\r\n    mint coef = mint(1) /\
    \ mint(len(a));\r\n    FOR(i, len(a)) a[i] *= coef;\r\n    int len = h;\r\n  \
    \  while (len) {\r\n      if (len == 1) {\r\n        int p = 1 << (h - len);\r\
    \n        mint irot = 1;\r\n        FOR(s, 1 << (len - 1)) {\r\n          int\
    \ offset = s << (h - len + 1);\r\n          FOR(i, p) {\r\n            auto l\
    \ = a[i + offset];\r\n            auto r = a[i + offset + p];\r\n            a[i\
    \ + offset] = l + r;\r\n            a[i + offset + p]\r\n                = (unsigned\
    \ long long)(mint::get_mod() + l.val - r.val)\r\n                  * irot.val;\r\
    \n            ;\r\n          }\r\n          irot *= info.irate2[topbit(~s & -~s)];\r\
    \n        }\r\n        len--;\r\n      } else {\r\n        int p = 1 << (h - len);\r\
    \n        mint irot = 1, iimag = info.iroot[2];\r\n        FOR(s, (1 << (len -\
    \ 2))) {\r\n          mint irot2 = irot * irot;\r\n          mint irot3 = irot2\
    \ * irot;\r\n          int offset = s << (h - len + 2);\r\n          for (int\
    \ i = 0; i < p; i++) {\r\n            auto a0 = 1ULL * a[i + offset + 0 * p].val;\r\
    \n            auto a1 = 1ULL * a[i + offset + 1 * p].val;\r\n            auto\
    \ a2 = 1ULL * a[i + offset + 2 * p].val;\r\n            auto a3 = 1ULL * a[i +\
    \ offset + 3 * p].val;\r\n\r\n            auto a2na3iimag\r\n                =\
    \ 1ULL * mint((mint::get_mod() + a2 - a3) * iimag.val).val;\r\n\r\n          \
    \  a[i + offset] = a0 + a1 + a2 + a3;\r\n            a[i + offset + 1 * p]\r\n\
    \                = (a0 + (mint::get_mod() - a1) + a2na3iimag) * irot.val;\r\n\
    \            a[i + offset + 2 * p]\r\n                = (a0 + a1 + (mint::get_mod()\
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
    \n    auto c = convolution(a, b);\r\n    c.eb(0);\r\n    c.eb(0);\r\n    c.back()\
    \ = a_last * b_last;\r\n    FOR(i, len(a)) c[i + len(b)] += a[i] * b_last;\r\n\
    \    FOR(i, len(b)) c[i + len(a)] += b[i] * a_last;\r\n    return c;\r\n  }\r\n\
    \r\n  a.resize(sz), b.resize(sz);\r\n  bool same = a == b;\r\n  ntt(a, 0);\r\n\
    \  if (same) {\r\n    b = a;\r\n  } else {\r\n    ntt(b, 0);\r\n  }\r\n  FOR(i,\
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
    \  }\r\n  return ret;\r\n}\r\n\r\n// atcoder library\r\nvector<ll> convolution(const\
    \ vector<ll>& a, const vector<ll>& b) {\r\n  int n = len(a), m = len(b);\r\n \
    \ if (!n || !m) return {};\r\n  // if (min(n, m) <= 60) return convolution_naive(a,\
    \ b);\r\n\r\n  static constexpr unsigned long long MOD1 = 754974721; // 2^24\r\
    \n  static constexpr unsigned long long MOD2 = 167772161; // 2^25\r\n  static\
    \ constexpr unsigned long long MOD3 = 469762049; // 2^26\r\n  static constexpr\
    \ unsigned long long M2M3 = MOD2 * MOD3;\r\n  static constexpr unsigned long long\
    \ M1M3 = MOD1 * MOD3;\r\n  static constexpr unsigned long long M1M2 = MOD1 * MOD2;\r\
    \n  static constexpr unsigned long long M1M2M3 = MOD1 * MOD2 * MOD3;\r\n\r\n \
    \ static const unsigned long long i1 = mod_inv(MOD2 * MOD3, MOD1);\r\n  static\
    \ const unsigned long long i2 = mod_inv(MOD1 * MOD3, MOD2);\r\n  static const\
    \ unsigned long long i3 = mod_inv(MOD1 * MOD2, MOD3);\r\n\r\n  using mint1 = modint<MOD1>;\r\
    \n  using mint2 = modint<MOD2>;\r\n  using mint3 = modint<MOD3>;\r\n\r\n  vc<mint1>\
    \ a1(n), b1(m);\r\n  vc<mint2> a2(n), b2(m);\r\n  vc<mint3> a3(n), b3(m);\r\n\
    \  FOR(i, n) a1[i] = a[i], a2[i] = a[i], a3[i] = a[i];\r\n  FOR(i, m) b1[i] =\
    \ b[i], b2[i] = b[i], b3[i] = b[i];\r\n\r\n  auto c1 = convolution_ntt<mint1>(a1,\
    \ b1);\r\n  auto c2 = convolution_ntt<mint2>(a2, b2);\r\n  auto c3 = convolution_ntt<mint3>(a3,\
    \ b3);\r\n\r\n  vc<ll> c(n + m - 1);\r\n  FOR(i, n + m - 1) {\r\n    u64 x = 0;\r\
    \n    x += (c1[i].val * i1) % MOD1 * M2M3;\r\n    x += (c2[i].val * i2) % MOD2\
    \ * M1M3;\r\n    x += (c3[i].val * i3) % MOD3 * M1M2;\r\n    ll diff = c1[i].val\
    \ - ((long long)(x) % (long long)(MOD1));\r\n    if (diff < 0) diff += MOD1;\r\
    \n    static constexpr unsigned long long offset[5]\r\n        = {0, 0, M1M2M3,\
    \ 2 * M1M2M3, 3 * M1M2M3};\r\n    x -= offset[diff % 5];\r\n    c[i] = x;\r\n\
    \  }\r\n  return c;\r\n}\r\n\r\ntemplate <typename mint>\r\nenable_if_t<is_same<mint,\
    \ modint998>::value, vc<mint>> convolution(\r\n    const vc<mint>& a, const vc<mint>&\
    \ b) {\r\n  int n = len(a), m = len(b);\r\n  if (!n || !m) return {};\r\n  if\
    \ (min(n, m) <= 60) return convolution_naive(a, b);\r\n  return convolution_ntt(a,\
    \ b);\r\n}\r\n\r\ntemplate <typename mint>\r\nenable_if_t<!is_same<mint, modint998>::value,\
    \ vc<mint>> convolution(\r\n    const vc<mint>& a, const vc<mint>& b) {\r\n  int\
    \ n = len(a), m = len(b);\r\n  if (!n || !m) return {};\r\n  if (min(n, m) <=\
    \ 60) return convolution_naive(a, b);\r\n  return convolution_garner(a, b);\r\n\
    }\r\n#line 5 \"poly/lagrange_interpolate_iota.hpp\"\n\r\ntemplate <typename mint>\r\
    \nvc<mint> lagrange_interpolate_iota(vc<mint> &f, mint c, int m) {\r\n  /*\r\n\
    \  Input: f(0), ..., f(n-1) and c, m (1 default)\r\n  Return: f(c), f(c+1), ...,\
    \ f(c+m-1)\r\n  Complexity: M(n, n + m)\r\n  \u2192 m \u304C\u3068\u3066\u3082\
    \u5C0F\u3055\u3044\u306A\u3089\u3070 O(n) \u3092 m \u56DE\u3084\u308B\u65B9\u304C\
    \u901F\u3044\u306E\u304B\r\n  */\r\n  if(m <= 60){\r\n    vc<mint> ANS(m);\r\n\
    \    FOR(i, m) ANS[i] = lagrange_interpolate_iota(f, c + mint(i));\r\n    return\
    \ ANS;\r\n  }\r\n  ll n = len(f);\r\n  auto a = f;\r\n  FOR(i, n) {\r\n    a[i]\
    \ = a[i] * fact_inv<mint>(i) * fact_inv<mint>(n - 1 - i);\r\n    if ((n - 1 -\
    \ i) & 1) a[i] = -a[i];\r\n  }\r\n  // x = c, c+1, ... \u306B\u5BFE\u3057\u3066\
    \ a0/x + a1/(x-1) + ... \u3092\u6C42\u3081\u3066\u304A\u304F\r\n  vc<mint> b(n\
    \ + m - 1);\r\n  FOR(i, n + m - 1) b[i] = mint(1) / (c + mint(i - n + 1));\r\n\
    \  a = convolution(a, b);\r\n\r\n  SWAG<Group_Mul<mint>> swag;\r\n  vc<mint> ANS(m);\r\
    \n  ll L = 0, R = 0;\r\n  FOR(i, m) {\r\n    while (L < i) { swag.pop(), ++L;\
    \ }\r\n    while (R - L < n) { swag.push(c + mint((R++) - n + 1)); }\r\n    auto\
    \ coef = swag.prod();\r\n    if (coef == 0) {\r\n      ANS[i] = f[(c + i).val];\r\
    \n    } else {\r\n      ANS[i] = a[i + n - 1] * coef;\r\n    }\r\n  }\r\n  return\
    \ ANS;\r\n}\r\n\r\ntemplate <typename mint>\r\nmint lagrange_interpolate_iota(vc<mint>\
    \ &f, mint c) {\r\n  /*\r\n  Input: f(0), ..., f(n-1) and c\r\n  Return: f(c)\r\
    \n  Complexity: O(n)\r\n  */\r\n  int n = len(f);\r\n  if(c.val < n) return f[c.val];\r\
    \n  auto a = f;\r\n  FOR(i, n) {\r\n    a[i] = a[i] * fact_inv<mint>(i) * fact_inv<mint>(n\
    \ - 1 - i);\r\n    if ((n - 1 - i) & 1) a[i] = -a[i];\r\n  }\r\n  vc<mint> lp(n+1),\
    \ rp(n+1);\r\n  lp[0] = rp[n] = 1;\r\n  FOR(i, n) lp[i+1] = lp[i] * (c - i);\r\
    \n  FOR_R(i, n) rp[i] = rp[i+1] * (c - i);\r\n  mint ANS = 0;\r\n  FOR(i, n) ANS\
    \ += a[i] * lp[i] * rp[i + 1];\r\n  return ANS;\r\n}\r\n#line 4 \"poly/prefix_product_of_poly.hpp\"\
    \n\n// A[k-1]...A[0]\n// \u30A2\u30EB\u30B4\u30EA\u30BA\u30E0\u53C2\u8003\uFF1A\
    https://github.com/noshi91/n91lib_rs/blob/master/src/algorithm/polynomial_matrix_prod.rs\n\
    // \u5B9F\u88C5\u53C2\u8003\uFF1Ahttps://nyaannyaan.github.io/library/matrix/polynomial-matrix-prefix-prod.hpp\n\
    template <typename T>\nvc<vc<T>> prefix_product_of_poly_matrix(vc<vc<vc<T>>>&\
    \ A, ll k) {\n  int n = len(A);\n\n  using MAT = vc<vc<T>>;\n  auto shift = [&](vc<MAT>&\
    \ G, T x) -> vc<MAT> {\n    int d = len(G);\n    vvv(T, H, d, n, n);\n    FOR(i,\
    \ n) FOR(j, n) {\n      vc<T> g(d);\n      FOR(l, d) g[l] = G[l][i][j];\n    \
    \  auto h = lagrange_interpolate_iota(g, x, d);\n      FOR(l, d) H[l][i][j] =\
    \ h[l];\n    }\n    return H;\n  };\n\n  auto evaluate = [&](vc<T>& f, T x) ->\
    \ T {\n    T res = 0;\n    T p = 1;\n    FOR(i, len(f)) {\n      res += f[i] *\
    \ p;\n      p *= x;\n    }\n    return res;\n  };\n\n  ll deg = 1;\n  FOR(i, n)\
    \ FOR(j, n) chmax(deg, len(A[i][j]) - 1);\n\n  vc<MAT> G(deg + 1);\n  ll v = 1;\n\
    \  while (deg * v * v < k) v *= 2;\n  T iv = T(1) / T(v);\n\n  FOR(i, len(G))\
    \ {\n    T x = T(v) * T(i);\n    vv(T, mat, n, n);\n    FOR(j, n) FOR(k, n) mat[j][k]\
    \ = evaluate(A[j][k], x);\n    G[i] = mat;\n  }\n\n  for (ll w = 1; w != v; w\
    \ *= 2) {\n    T W = w;\n    auto G1 = shift(G, W * iv);\n    auto G2 = shift(G,\
    \ (W * T(deg) * T(v) + T(v)) * iv);\n    auto G3 = shift(G, (W * T(deg) * T(v)\
    \ + T(v) + W) * iv);\n    FOR(i, w * deg + 1) {\n      G[i] = mat_mul(G1[i], G[i]);\n\
    \      G2[i] = mat_mul(G3[i], G2[i]);\n    }\n    copy(G2.begin(), G2.end() -\
    \ 1, back_inserter(G));\n  }\n\n  vv(T, res, n, n);\n  FOR(i, n) res[i][i] = 1;\n\
    \  ll i = 0;\n  while (i + v <= k) res = mat_mul(G[i / v], res), i += v;\n  while\
    \ (i < k) {\n    vv(T, mat, n, n);\n    FOR(j, n) FOR(k, n) mat[j][k] = evaluate(A[j][k],\
    \ i);\n    res = mat_mul(mat, res);\n    ++i;\n  }\n  return res;\n}\n\n// A[k-1]...A[0]\n\
    template <typename T>\nT prefix_product_of_poly(vc<T>& f, ll k) {\n  vc<vc<vc<T>>>\
    \ A(1);\n  A[0].resize(1);\n  A[0][0] = f;\n  auto res = prefix_product_of_poly_matrix(A,\
    \ k);\n  return res[0][0];\n}\n#line 2 \"seq/kth_term_of_p_recursive.hpp\"\n\n\
    // a0, ..., a_{r-1} \u304A\u3088\u3073 f_0, ..., f_r \u3092\u4E0E\u3048\u308B\n\
    // a_r f_0(0) + a_{r-1}f_1(0) + ... = 0\n// a_{r+1} f_0(1) + a_{r}f_1(1) + ...\
    \ = 0\ntemplate <typename T>\nT kth_term_of_p_recursive(vc<T> a, vc<vc<T>>& fs,\
    \ ll k) {\n  int r = len(a);\n  assert(len(fs) == r + 1);\n  if (k < r) return\
    \ a[k];\n\n  vc<vc<vc<T>>> A;\n  A.resize(r);\n  FOR(i, r) A[i].resize(r);\n \
    \ FOR(i, r) {\n    // A[0][i] = -fs[i + 1];\n    for (auto&& x: fs[i + 1]) A[0][i].eb(-x);\n\
    \  }\n  FOR3(i, 1, r) A[i][i - 1] = fs[0];\n  vc<T> den = fs[0];\n  auto res =\
    \ prefix_product_of_poly_matrix(A, k - r + 1);\n  reverse(all(a));\n  T ANS =\
    \ 0;\n  FOR(j, r) ANS += res[0][j] * a[j];\n  ANS /= prefix_product_of_poly(den,\
    \ k - r + 1);\n  return ANS;\n}\n"
  code: "#include \"poly/prefix_product_of_poly.hpp\"\n\n// a0, ..., a_{r-1} \u304A\
    \u3088\u3073 f_0, ..., f_r \u3092\u4E0E\u3048\u308B\n// a_r f_0(0) + a_{r-1}f_1(0)\
    \ + ... = 0\n// a_{r+1} f_0(1) + a_{r}f_1(1) + ... = 0\ntemplate <typename T>\n\
    T kth_term_of_p_recursive(vc<T> a, vc<vc<T>>& fs, ll k) {\n  int r = len(a);\n\
    \  assert(len(fs) == r + 1);\n  if (k < r) return a[k];\n\n  vc<vc<vc<T>>> A;\n\
    \  A.resize(r);\n  FOR(i, r) A[i].resize(r);\n  FOR(i, r) {\n    // A[0][i] =\
    \ -fs[i + 1];\n    for (auto&& x: fs[i + 1]) A[0][i].eb(-x);\n  }\n  FOR3(i, 1,\
    \ r) A[i][i - 1] = fs[0];\n  vc<T> den = fs[0];\n  auto res = prefix_product_of_poly_matrix(A,\
    \ k - r + 1);\n  reverse(all(a));\n  T ANS = 0;\n  FOR(j, r) ANS += res[0][j]\
    \ * a[j];\n  ANS /= prefix_product_of_poly(den, k - r + 1);\n  return ANS;\n}\n"
  dependsOn:
  - poly/prefix_product_of_poly.hpp
  - linalg/mat_mul.hpp
  - poly/lagrange_interpolate_iota.hpp
  - alg/group_mul.hpp
  - ds/swag.hpp
  - poly/convolution.hpp
  - mod/modint.hpp
  - mod/mod_inv.hpp
  - poly/convolution_naive.hpp
  - poly/ntt.hpp
  - poly/fft.hpp
  isVerificationFile: false
  path: seq/kth_term_of_p_recursive.hpp
  requiredBy: []
  timestamp: '2022-06-20 21:16:12+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/yukicoder/502_p_rec.test.cpp
documentation_of: seq/kth_term_of_p_recursive.hpp
layout: document
redirect_from:
- /library/seq/kth_term_of_p_recursive.hpp
- /library/seq/kth_term_of_p_recursive.hpp.html
title: seq/kth_term_of_p_recursive.hpp
---
