---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: ds/my_bitset.hpp
    title: ds/my_bitset.hpp
  - icon: ':question:'
    path: mod/mongomery_modint.hpp
    title: mod/mongomery_modint.hpp
  - icon: ':question:'
    path: nt/factor.hpp
    title: nt/factor.hpp
  - icon: ':heavy_check_mark:'
    path: nt/lpf_table.hpp
    title: nt/lpf_table.hpp
  - icon: ':heavy_check_mark:'
    path: nt/primetable.hpp
    title: nt/primetable.hpp
  - icon: ':question:'
    path: nt/primetest.hpp
    title: nt/primetest.hpp
  - icon: ':question:'
    path: random/base.hpp
    title: random/base.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links:
    - https://codeforces.com/contest/1148/problem/G
  bundledCode: "#line 2 \"ds/my_bitset.hpp\"\n\n// https://codeforces.com/contest/914/problem/F\n\
    // https://yukicoder.me/problems/no/142\n// \u308F\u305A\u304B\u306B\u666E\u901A\
    \u306E bitset \u3088\u308A\u9045\u3044\u3068\u304D\u3082\u3042\u308B\u3088\u3046\
    \u3060\u304C\uFF0C\n// \u56FA\u5B9A\u9577\u306B\u3057\u305F\u304F\u306A\u3044\u3068\
    \u304D\u3084 slice \u64CD\u4F5C\u304C\u5FC5\u8981\u306A\u3068\u304D\u306B\u4F7F\
    \u3046\nstruct My_Bitset {\n  using T = My_Bitset;\n  int N;\n  vc<u64> dat;\n\
    \n  // x \u3067\u57CB\u3081\u308B\n  My_Bitset(int N = 0, int x = 0) : N(N) {\n\
    \    assert(x == 0 || x == 1);\n    u64 v = (x == 0 ? 0 : -1);\n    dat.assign((N\
    \ + 63) >> 6, v);\n    if (N) dat.back() >>= (64 * len(dat) - N);\n  }\n\n  int\
    \ size() { return N; }\n\n  void resize(int size) {\n    dat.resize((size + 63)\
    \ >> 6);\n    int remainingBits = size & 63;\n    if (remainingBits != 0) {\n\
    \      u64 mask = (u64(1) << remainingBits) - 1;\n      dat.back() &= mask;\n\
    \    }\n    N = size;\n  }\n\n  void append(int idx, bool b) {\n    assert(N ==\
    \ idx);\n    resize(idx + 1), (*this)[idx] = b;\n  }\n\n  static T from_string(string\
    \ &S) {\n    int N = len(S);\n    T ANS(N);\n    FOR(i, N) ANS[i] = (S[i] == '1');\n\
    \    return ANS;\n  }\n\n  // thanks to chatgpt!\n  class Proxy {\n  public:\n\
    \    Proxy(vc<u64> &d, int i) : dat(d), index(i) {}\n    operator bool() const\
    \ { return (dat[index >> 6] >> (index & 63)) & 1; }\n\n    Proxy &operator=(u64\
    \ value) {\n      dat[index >> 6] &= ~(u64(1) << (index & 63));\n      dat[index\
    \ >> 6] |= (value & 1) << (index & 63);\n      return *this;\n    }\n    void\
    \ flip() {\n      dat[index >> 6] ^= (u64(1) << (index & 63)); // XOR to flip\
    \ the bit\n    }\n\n  private:\n    vc<u64> &dat;\n    int index;\n  };\n\n  Proxy\
    \ operator[](int i) { return Proxy(dat, i); }\n\n  bool operator==(const T &p)\
    \ {\n    assert(N == p.N);\n    FOR(i, len(dat)) if (dat[i] != p.dat[i]) return\
    \ false;\n    return true;\n  }\n\n  T &operator&=(const T &p) {\n    assert(N\
    \ == p.N);\n    FOR(i, len(dat)) dat[i] &= p.dat[i];\n    return *this;\n  }\n\
    \  T &operator|=(const T &p) {\n    assert(N == p.N);\n    FOR(i, len(dat)) dat[i]\
    \ |= p.dat[i];\n    return *this;\n  }\n  T &operator^=(const T &p) {\n    assert(N\
    \ == p.N);\n    FOR(i, len(dat)) dat[i] ^= p.dat[i];\n    return *this;\n  }\n\
    \  T operator&(const T &p) const { return T(*this) &= p; }\n  T operator|(const\
    \ T &p) const { return T(*this) |= p; }\n  T operator^(const T &p) const { return\
    \ T(*this) ^= p; }\n  T operator~() const {\n    T p = (*this);\n    p.flip_range(0,\
    \ N);\n    return p;\n  }\n\n  void set_minus_inplace(T &other) {\n    assert(N\
    \ == other.N);\n    FOR(i, len(dat)) dat[i] = dat[i] & (~other.dat[i]);\n  }\n\
    \n  T set_minus(T other) {\n    assert(N == other.N);\n    FOR(i, len(dat)) other.dat[i]\
    \ = dat[i] & (~other.dat[i]);\n    return other;\n  }\n\n  int count() {\n   \
    \ int ans = 0;\n    for (u64 val: dat) ans += popcnt(val);\n    return ans;\n\
    \  }\n\n  int dot(T &p) {\n    assert(N == p.N);\n    int ans = 0;\n    FOR(i,\
    \ len(dat)) ans += popcnt(dat[i] & p.dat[i]);\n    return ans;\n  }\n\n  int next(int\
    \ i) {\n    chmax(i, 0);\n    if (i >= N) return N;\n    int k = i >> 6;\n   \
    \ {\n      u64 x = dat[k];\n      int s = i & 63;\n      x = (x >> s) << s;\n\
    \      if (x) return (k << 6) | lowbit(x);\n    }\n    FOR(idx, k + 1, len(dat))\
    \ {\n      if (dat[idx] == 0) continue;\n      return (idx << 6) | lowbit(dat[idx]);\n\
    \    }\n    return N;\n  }\n\n  int prev(int i) {\n    chmin(i, N - 1);\n    if\
    \ (i <= -1) return -1;\n    int k = i >> 6;\n    if ((i & 63) < 63) {\n      u64\
    \ x = dat[k];\n      x &= (u64(1) << ((i & 63) + 1)) - 1;\n      if (x) return\
    \ (k << 6) | topbit(x);\n      --k;\n    }\n    FOR_R(idx, k + 1) {\n      if\
    \ (dat[idx] == 0) continue;\n      return (idx << 6) | topbit(dat[idx]);\n   \
    \ }\n    return -1;\n  }\n\n  My_Bitset range(int L, int R) {\n    assert(L <=\
    \ R);\n    My_Bitset p(R - L);\n    int rm = (R - L) & 63;\n    FOR(rm) {\n  \
    \    p[R - L - 1] = bool((*this)[R - 1]);\n      --R;\n    }\n    int n = (R -\
    \ L) >> 6;\n    int hi = L & 63;\n    int lo = 64 - hi;\n    int s = L >> 6;\n\
    \    if (hi == 0) {\n      FOR(i, n) { p.dat[i] ^= dat[s + i]; }\n    } else {\n\
    \      FOR(i, n) { p.dat[i] ^= (dat[s + i] >> hi) ^ (dat[s + i + 1] << lo); }\n\
    \    }\n    return p;\n  }\n\n  My_Bitset slice(int L, int R) { return range(L,\
    \ R); }\n\n  int count_range(int L, int R) {\n    assert(L <= R);\n    int cnt\
    \ = 0;\n    while ((L < R) && (L & 63)) cnt += (*this)[L++];\n    while ((L <\
    \ R) && (R & 63)) cnt += (*this)[--R];\n    int l = L >> 6, r = R >> 6;\n    FOR(i,\
    \ l, r) cnt += popcnt(dat[i]);\n    return cnt;\n  }\n\n  // [L,R) \u306B p \u3092\
    \u4EE3\u5165\n  void assign_to_range(int L, int R, My_Bitset &p) {\n    assert(p.N\
    \ == R - L);\n    int a = 0, b = p.N;\n    while (L < R && (L & 63)) { (*this)[L++]\
    \ = bool(p[a++]); }\n    while (L < R && (R & 63)) { (*this)[--R] = bool(p[--b]);\
    \ }\n    // p[a:b] \u3092 [L:R] \u306B\n    int l = L >> 6, r = R >> 6;\n    int\
    \ s = a >> 6, t = b >> t;\n    int n = r - l;\n    if (!(a & 63)) {\n      FOR(i,\
    \ n) dat[l + i] = p.dat[s + i];\n    } else {\n      int hi = a & 63;\n      int\
    \ lo = 64 - hi;\n      FOR(i, n) dat[l + i] = (p.dat[s + i] >> hi) | (p.dat[1\
    \ + s + i] << lo);\n    }\n  }\n\n  // [L,R) \u306B p \u3092 xor\n  void xor_to_range(int\
    \ L, int R, My_Bitset &p) {\n    assert(p.N == R - L);\n    int a = 0, b = p.N;\n\
    \    while (L < R && (L & 63)) {\n      dat[L >> 6] ^= u64(p[a]) << (L & 63);\n\
    \      ++a, ++L;\n    }\n    while (L < R && (R & 63)) {\n      --b, --R;\n  \
    \    dat[R >> 6] ^= u64(p[b]) << (R & 63);\n    }\n    // p[a:b] \u3092 [L:R]\
    \ \u306B\n    int l = L >> 6, r = R >> 6;\n    int s = a >> 6, t = b >> t;\n \
    \   int n = r - l;\n    if (!(a & 63)) {\n      FOR(i, n) dat[l + i] ^= p.dat[s\
    \ + i];\n    } else {\n      int hi = a & 63;\n      int lo = 64 - hi;\n     \
    \ FOR(i, n) dat[l + i] ^= (p.dat[s + i] >> hi) | (p.dat[1 + s + i] << lo);\n \
    \   }\n  }\n\n  // \u884C\u5217\u57FA\u672C\u5909\u5F62\u3067\u4F7F\u3046\u3084\
    \u3064\n  // p \u306F [i:N) \u306B\u3057\u304B\u306A\u3044\u3068\u3057\u3066 p\
    \ \u3092 xor \u3059\u308B\n  void xor_suffix(int i, My_Bitset &p) {\n    assert(N\
    \ == p.N && 0 <= i && i < N);\n    FOR(k, i / 64, len(dat)) { dat[k] ^= p.dat[k];\
    \ }\n  }\n\n  // [L,R) \u306B p \u3092 and\n  void and_to_range(int L, int R,\
    \ My_Bitset &p) {\n    assert(p.N == R - L);\n    int a = 0, b = p.N;\n    while\
    \ (L < R && (L & 63)) {\n      if (!p[a]) (*this)[L] = 0;\n      a++, L++;\n \
    \   }\n    while (L < R && (R & 63)) {\n      --b, --R;\n      if (!p[b]) (*this)[R]\
    \ = 0;\n    }\n    // p[a:b] \u3092 [L:R] \u306B\n    int l = L >> 6, r = R >>\
    \ 6;\n    int s = a >> 6, t = b >> t;\n    int n = r - l;\n    if (!(a & 63))\
    \ {\n      FOR(i, n) dat[l + i] &= p.dat[s + i];\n    } else {\n      int hi =\
    \ a & 63;\n      int lo = 64 - hi;\n      FOR(i, n) dat[l + i] &= (p.dat[s + i]\
    \ >> hi) | (p.dat[1 + s + i] << lo);\n    }\n  }\n\n  // [L,R) \u306B p \u3092\
    \ or\n  void or_to_range(int L, int R, My_Bitset &p) {\n    assert(p.N == R -\
    \ L);\n    int a = 0, b = p.N;\n    while (L < R && (L & 63)) {\n      dat[L >>\
    \ 6] |= u64(p[a]) << (L & 63);\n      ++a, ++L;\n    }\n    while (L < R && (R\
    \ & 63)) {\n      --b, --R;\n      dat[R >> 6] |= u64(p[b]) << (R & 63);\n   \
    \ }\n    // p[a:b] \u3092 [L:R] \u306B\n    int l = L >> 6, r = R >> 6;\n    int\
    \ s = a >> 6, t = b >> t;\n    int n = r - l;\n    if (!(a & 63)) {\n      FOR(i,\
    \ n) dat[l + i] |= p.dat[s + i];\n    } else {\n      int hi = a & 63;\n     \
    \ int lo = 64 - hi;\n      FOR(i, n) dat[l + i] |= (p.dat[s + i] >> hi) | (p.dat[1\
    \ + s + i] << lo);\n    }\n  }\n  // \u884C\u5217\u57FA\u672C\u5909\u5F62\u3067\
    \u4F7F\u3046\u3084\u3064\n  // p \u306F [i:N) \u306B\u3057\u304B\u306A\u3044\u3068\
    \u3057\u3066 p \u3092 or \u3059\u308B\n  void or_suffix(int i, My_Bitset &p) {\n\
    \    assert(N == p.N && 0 <= i && i < N);\n    FOR(k, i / 64, len(dat)) { dat[k]\
    \ |= p.dat[k]; }\n  }\n\n  // [L,R) \u3092 1 \u306B\u5909\u66F4\n  void set_range(int\
    \ L, int R) {\n    while (L < R && (L & 63)) { set(L++); }\n    while (L < R &&\
    \ (R & 63)) { set(--R); }\n    FOR(i, L >> 6, R >> 6) dat[i] = u64(-1);\n  }\n\
    \n  // [L,R) \u3092 1 \u306B\u5909\u66F4\n  void reset_range(int L, int R) {\n\
    \    while (L < R && (L & 63)) { reset(L++); }\n    while (L < R && (R & 63))\
    \ { reset(--R); }\n    FOR(i, L >> 6, R >> 6) dat[i] = u64(0);\n  }\n\n  // [L,R)\
    \ \u3092 flip\n  void flip_range(int L, int R) {\n    while (L < R && (L & 63))\
    \ { flip(L++); }\n    while (L < R && (R & 63)) { flip(--R); }\n    FOR(i, L >>\
    \ 6, R >> 6) dat[i] ^= u64(-1);\n  }\n\n  // bitset \u306B\u4ED5\u69D8\u3092\u5408\
    \u308F\u305B\u308B\n  void set(int i) { (*this)[i] = 1; }\n  void reset(int i)\
    \ { (*this)[i] = 0; }\n  void flip(int i) { (*this)[i].flip(); }\n  void set()\
    \ {\n    fill(all(dat), u64(-1));\n    resize(N);\n  }\n  void reset() { fill(all(dat),\
    \ 0); }\n  void flip() {\n    FOR(i, len(dat) - 1) { dat[i] = u64(-1) ^ dat[i];\
    \ }\n    int i = len(dat) - 1;\n    FOR(k, 64) {\n      if (64 * i + k >= size())\
    \ break;\n      flip(64 * i + k);\n    }\n  }\n  bool any() {\n    FOR(i, len(dat))\
    \ {\n      if (dat[i]) return true;\n    }\n    return false;\n  }\n\n  bool ALL()\
    \ {\n    dat.resize((N + 63) >> 6);\n    int r = N & 63;\n    if (r != 0) {\n\
    \      u64 mask = (u64(1) << r) - 1;\n      if (dat.back() != mask) return 0;\n\
    \    }\n    for (int i = 0; i < N / 64; ++i)\n      if (dat[i] != u64(-1)) return\
    \ false;\n    return true;\n  }\n  // bs[i]==true \u3067\u3042\u308B\u3088\u3046\
    \u306A i \u5168\u4F53\n  vc<int> collect_idx() {\n    vc<int> I;\n    FOR(i, N)\
    \ if ((*this)[i]) I.eb(i);\n    return I;\n  }\n\n  bool is_subset(T &other) {\n\
    \    assert(len(other) == N);\n    FOR(i, len(dat)) {\n      u64 a = dat[i], b\
    \ = other.dat[i];\n      if ((a & b) != a) return false;\n    }\n    return true;\n\
    \  }\n\n  int _Find_first() { return next(0); }\n  int _Find_next(int p) { return\
    \ next(p + 1); }\n\n  template <typename F>\n  void enumerate(int L, int R, F\
    \ f) {\n    if (L >= size()) return;\n    int p = ((*this)[L] ? L : _Find_next(L));\n\
    \    while (p < R) {\n      f(p);\n      p = _Find_next(p);\n    }\n  }\n\n  static\
    \ string TO_STR[256];\n  string to_string() const {\n    if (TO_STR[0].empty())\
    \ precompute();\n    string S;\n    for (auto &x: dat) { FOR(i, 8) S += TO_STR[(x\
    \ >> (8 * i) & 255)]; }\n    S.resize(N);\n    return S;\n  }\n\n  static void\
    \ precompute() {\n    FOR(s, 256) {\n      string x;\n      FOR(i, 8) x += '0'\
    \ + (s >> i & 1);\n      TO_STR[s] = x;\n    }\n  }\n};\nstring My_Bitset::TO_STR[256];\n\
    #line 2 \"nt/primetable.hpp\"\n\ntemplate <typename T = int>\nvc<T> primetable(int\
    \ LIM) {\n  ++LIM;\n  const int S = 32768;\n  static int done = 2;\n  static vc<T>\
    \ primes = {2}, sieve(S + 1);\n\n  if (done < LIM) {\n    done = LIM;\n\n    primes\
    \ = {2}, sieve.assign(S + 1, 0);\n    const int R = LIM / 2;\n    primes.reserve(int(LIM\
    \ / log(LIM) * 1.1));\n    vc<pair<int, int>> cp;\n    for (int i = 3; i <= S;\
    \ i += 2) {\n      if (!sieve[i]) {\n        cp.eb(i, i * i / 2);\n        for\
    \ (int j = i * i; j <= S; j += 2 * i) sieve[j] = 1;\n      }\n    }\n    for (int\
    \ L = 1; L <= R; L += S) {\n      array<bool, S> block{};\n      for (auto& [p,\
    \ idx]: cp)\n        for (int i = idx; i < S + L; idx = (i += p)) block[i - L]\
    \ = 1;\n      FOR(i, min(S, R - L)) if (!block[i]) primes.eb((L + i) * 2 + 1);\n\
    \    }\n  }\n  int k = LB(primes, LIM + 1);\n  return {primes.begin(), primes.begin()\
    \ + k};\n}\n#line 3 \"nt/lpf_table.hpp\"\n\n// [0, LIM], 0, 1 \u306B\u306F -1\
    \ \u304C\u5165\u308B\u3002\nvc<int> lpf_table(ll LIM) {\n  auto primes = primetable(LIM);\n\
    \  vc<int> res(LIM + 1, -1);\n  FOR_R(i, len(primes)) {\n    auto p = primes[i];\n\
    \    FOR3(j, 1, LIM / p + 1) res[p * j] = p;\n  }\n  return res;\n}\n#line 2 \"\
    nt/factor.hpp\"\n\n#line 2 \"random/base.hpp\"\n\nu64 RNG_64() {\n  static u64\
    \ x_ = u64(chrono::duration_cast<chrono::nanoseconds>(chrono::high_resolution_clock::now().time_since_epoch()).count())\
    \ * 10150724397891781847ULL;\n  x_ ^= x_ << 7;\n  return x_ ^= x_ >> 9;\n}\n\n\
    u64 RNG(u64 lim) { return RNG_64() % lim; }\n\nll RNG(ll l, ll r) { return l +\
    \ RNG_64() % (r - l); }\n#line 2 \"mod/mongomery_modint.hpp\"\n\n// odd mod.\n\
    // x \u306E\u4EE3\u308F\u308A\u306B rx \u3092\u6301\u3064\ntemplate <int id, typename\
    \ U1, typename U2>\nstruct Mongomery_modint {\n  using mint = Mongomery_modint;\n\
    \  inline static U1 m, r, n2;\n  static constexpr int W = numeric_limits<U1>::digits;\n\
    \n  static void set_mod(U1 mod) {\n    assert(mod & 1 && mod <= U1(1) << (W -\
    \ 2));\n    m = mod, n2 = -U2(m) % m, r = m;\n    FOR(5) r *= 2 - m * r;\n   \
    \ r = -r;\n    assert(r * m == U1(-1));\n  }\n  static U1 reduce(U2 b) { return\
    \ (b + U2(U1(b) * r) * m) >> W; }\n\n  U1 x;\n  Mongomery_modint() : x(0) {}\n\
    \  Mongomery_modint(U1 x) : x(reduce(U2(x) * n2)){};\n  U1 val() const {\n   \
    \ U1 y = reduce(x);\n    return y >= m ? y - m : y;\n  }\n  mint &operator+=(mint\
    \ y) {\n    x = ((x += y.x) >= m ? x - m : x);\n    return *this;\n  }\n  mint\
    \ &operator-=(mint y) {\n    x -= (x >= y.x ? y.x : y.x - m);\n    return *this;\n\
    \  }\n  mint &operator*=(mint y) {\n    x = reduce(U2(x) * y.x);\n    return *this;\n\
    \  }\n  mint operator+(mint y) const { return mint(*this) += y; }\n  mint operator-(mint\
    \ y) const { return mint(*this) -= y; }\n  mint operator*(mint y) const { return\
    \ mint(*this) *= y; }\n  bool operator==(mint y) const {\n    return (x >= m ?\
    \ x - m : x) == (y.x >= m ? y.x - m : y.x);\n  }\n  bool operator!=(mint y) const\
    \ { return not operator==(y); }\n  mint pow(ll n) const {\n    assert(n >= 0);\n\
    \    mint y = 1, z = *this;\n    for (; n; n >>= 1, z *= z)\n      if (n & 1)\
    \ y *= z;\n    return y;\n  }\n};\n\ntemplate <int id>\nusing Mongomery_modint_32\
    \ = Mongomery_modint<id, u32, u64>;\ntemplate <int id>\nusing Mongomery_modint_64\
    \ = Mongomery_modint<id, u64, u128>;\n#line 3 \"nt/primetest.hpp\"\n\r\nbool primetest(const\
    \ u64 x) {\r\n  assert(x < u64(1) << 62);\r\n  if (x == 2 or x == 3 or x == 5\
    \ or x == 7) return true;\r\n  if (x % 2 == 0 or x % 3 == 0 or x % 5 == 0 or x\
    \ % 7 == 0) return false;\r\n  if (x < 121) return x > 1;\r\n  const u64 d = (x\
    \ - 1) >> lowbit(x - 1);\r\n\r\n  using mint = Mongomery_modint_64<202311020>;\r\
    \n\r\n  mint::set_mod(x);\r\n  const mint one(u64(1)), minus_one(x - 1);\r\n \
    \ auto ok = [&](u64 a) -> bool {\r\n    auto y = mint(a).pow(d);\r\n    u64 t\
    \ = d;\r\n    while (y != one && y != minus_one && t != x - 1) y *= y, t <<= 1;\r\
    \n    if (y != minus_one && t % 2 == 0) return false;\r\n    return true;\r\n\
    \  };\r\n  if (x < (u64(1) << 32)) {\r\n    for (u64 a: {2, 7, 61})\r\n      if\
    \ (!ok(a)) return false;\r\n  } else {\r\n    for (u64 a: {2, 325, 9375, 28178,\
    \ 450775, 9780504, 1795265022}) {\r\n      if (!ok(a)) return false;\r\n    }\r\
    \n  }\r\n  return true;\r\n}\n#line 5 \"nt/factor.hpp\"\n\ntemplate <typename\
    \ mint>\nll rho(ll n, ll c) {\n  assert(n > 1);\n  const mint cc(c);\n  auto f\
    \ = [&](mint x) { return x * x + cc; };\n  mint x = 1, y = 2, z = 1, q = 1;\n\
    \  ll g = 1;\n  const ll m = 1LL << (__lg(n) / 5);\n  for (ll r = 1; g == 1; r\
    \ <<= 1) {\n    x = y;\n    FOR(r) y = f(y);\n    for (ll k = 0; k < r && g ==\
    \ 1; k += m) {\n      z = y;\n      FOR(min(m, r - k)) y = f(y), q *= x - y;\n\
    \      g = gcd(q.val(), n);\n    }\n  }\n  if (g == n) do {\n      z = f(z);\n\
    \      g = gcd((x - z).val(), n);\n    } while (g == 1);\n  return g;\n}\n\nll\
    \ find_prime_factor(ll n) {\n  assert(n > 1);\n  if (primetest(n)) return n;\n\
    \  FOR(100) {\n    ll m = 0;\n    if (n < (1 << 30)) {\n      using mint = Mongomery_modint_32<20231025>;\n\
    \      mint::set_mod(n);\n      m = rho<mint>(n, RNG(0, n));\n    } else {\n \
    \     using mint = Mongomery_modint_64<20231025>;\n      mint::set_mod(n);\n \
    \     m = rho<mint>(n, RNG(0, n));\n    }\n    if (primetest(m)) return m;\n \
    \   n = m;\n  }\n  assert(0);\n  return -1;\n}\n\n// \u30BD\u30FC\u30C8\u3057\u3066\
    \u304F\u308C\u308B\nvc<pair<ll, int>> factor(ll n) {\n  assert(n >= 1);\n  vc<pair<ll,\
    \ int>> pf;\n  FOR(p, 2, 100) {\n    if (p * p > n) break;\n    if (n % p == 0)\
    \ {\n      ll e = 0;\n      do { n /= p, e += 1; } while (n % p == 0);\n     \
    \ pf.eb(p, e);\n    }\n  }\n  while (n > 1) {\n    ll p = find_prime_factor(n);\n\
    \    ll e = 0;\n    do { n /= p, e += 1; } while (n % p == 0);\n    pf.eb(p, e);\n\
    \  }\n  sort(all(pf));\n  return pf;\n}\n\nvc<pair<ll, int>> factor_by_lpf(ll\
    \ n, vc<int>& lpf) {\n  vc<pair<ll, int>> res;\n  while (n > 1) {\n    int p =\
    \ lpf[n];\n    int e = 0;\n    while (n % p == 0) {\n      n /= p;\n      ++e;\n\
    \    }\n    res.eb(p, e);\n  }\n  return res;\n}\n#line 4 \"nt/find_coprime_pair.hpp\"\
    \n\n// A[i] \u3068\u4E92\u3044\u306B\u7D20\u306A A[j] \u3092\u691C\u51FA / A[i]\
    \ \u306E\u524A\u9664\n// N=1e5,A=1e7 \u9023\u7D50\u6210\u5206\u5206\u89E3 1030ms\n\
    // https://codeforces.com/contest/1148/problem/G\ntemplate <int thresh = 200>\n\
    struct Find_Coprime_Pair {\n  // thresh \u4EE5\u4E0A\u3042\u308B\u7D20\u6570\u3092\
    \ bitset \u7BA1\u7406\n  using BS = My_Bitset;\n  int N;\n  vc<int> A;\n  vc<int>\
    \ lpf;\n  vc<int> S;\n  vc<int> ptr;\n  vc<int> bidx;\n  vc<BS> dat;\n  BS remain;\n\
    \  // 20 \u4EE5\u4E0B\u306E\u7D20\u6570\u306E\u7A4D\n  const int prod = 9699690;\n\
    \n  Find_Coprime_Pair(vc<int> A) : A(A) {\n    N = len(A);\n    int ma = MAX(A);\n\
    \    lpf = lpf_table(ma);\n    vc<int> ptr1(ma + 1);\n    vc<int> ids(N);\n  \
    \  for (auto& x : A) ptr1[x]++;\n    ptr1 = cumsum<int>(ptr1);\n    FOR(i, N)\
    \ { ids[ptr1[A[i]]++] = i; }\n    FOR_R(i, len(ptr1) - 1) ptr1[i + 1] = ptr1[i];\n\
    \n    ptr.resize(ma + 2);\n    FOR(p, 23, ma + 1) {\n      if (lpf[p] != p) continue;\n\
    \      ptr[p] = len(S);\n      for (int n = p; n <= ma; n += p) {\n        FOR(k,\
    \ ptr1[n], ptr1[n + 1]) S.eb(ids[k]);\n      }\n      ptr[p + 1] = len(S);\n \
    \   }\n\n    bidx.assign(ma + 1, -1);\n    {\n      vc<int> prime = {2, 3, 5,\
    \ 7, 11, 13, 17, 19};\n      vc<BS> tmp(1 << 8);\n      tmp[0] = BS(N, 1);\n \
    \     FOR(i, 8) {\n        BS bs(N, 1);\n        FOR(j, N) if (A[j] % prime[i]\
    \ == 0) bs[j] = 0;\n        FOR(s, 1 << i) tmp[s | 1 << i] = tmp[s] & bs;\n  \
    \    }\n      FOR(s, 1 << 8) {\n        int prd = 1;\n        FOR(i, 8) if (s\
    \ >> i & 1) prd *= prime[i];\n        if (prd <= ma) {\n          bidx[prd] =\
    \ len(dat);\n          dat.eb(tmp[s]);\n        }\n      }\n    }\n\n    FOR(p,\
    \ 23, ma + 1) {\n      if (lpf[p] != p) continue;\n      int cnt = ptr[p + 1]\
    \ - ptr[p];\n      if (cnt < thresh) continue;\n      BS bs(N, 1);\n      FOR(i,\
    \ ptr[p], ptr[p + 1]) bs[S[i]] = 0;\n      bidx[p] = len(dat);\n      dat.eb(bs);\n\
    \    }\n    remain = BS(N, 1);\n  }\n\n  void remove(int i) { remain[i] = 0; }\n\
    \n  // \u81EA\u5206\u81EA\u8EAB\u306F\u9664\u3044\u3066\n  template <typename\
    \ F>\n  void enumerate_all(int i, F f) {\n    int d = gcd(A[i], prod);\n    BS\
    \ x = remain & dat[bidx[d]];\n    for (auto& [p, e] : factor_by_lpf(A[i], lpf))\
    \ {\n      if (p < 20) continue;\n      if (bidx[p] == -1) {\n        FOR(k, ptr[p],\
    \ ptr[p + 1]) { x[S[k]] = 0; }\n      } else {\n        x &= dat[bidx[p]];\n \
    \     }\n    }\n    x.enumerate(0, N, f);\n  }\n};\n"
  code: "#include \"ds/my_bitset.hpp\"\n#include \"nt/lpf_table.hpp\"\n#include \"\
    nt/factor.hpp\"\n\n// A[i] \u3068\u4E92\u3044\u306B\u7D20\u306A A[j] \u3092\u691C\
    \u51FA / A[i] \u306E\u524A\u9664\n// N=1e5,A=1e7 \u9023\u7D50\u6210\u5206\u5206\
    \u89E3 1030ms\n// https://codeforces.com/contest/1148/problem/G\ntemplate <int\
    \ thresh = 200>\nstruct Find_Coprime_Pair {\n  // thresh \u4EE5\u4E0A\u3042\u308B\
    \u7D20\u6570\u3092 bitset \u7BA1\u7406\n  using BS = My_Bitset;\n  int N;\n  vc<int>\
    \ A;\n  vc<int> lpf;\n  vc<int> S;\n  vc<int> ptr;\n  vc<int> bidx;\n  vc<BS>\
    \ dat;\n  BS remain;\n  // 20 \u4EE5\u4E0B\u306E\u7D20\u6570\u306E\u7A4D\n  const\
    \ int prod = 9699690;\n\n  Find_Coprime_Pair(vc<int> A) : A(A) {\n    N = len(A);\n\
    \    int ma = MAX(A);\n    lpf = lpf_table(ma);\n    vc<int> ptr1(ma + 1);\n \
    \   vc<int> ids(N);\n    for (auto& x : A) ptr1[x]++;\n    ptr1 = cumsum<int>(ptr1);\n\
    \    FOR(i, N) { ids[ptr1[A[i]]++] = i; }\n    FOR_R(i, len(ptr1) - 1) ptr1[i\
    \ + 1] = ptr1[i];\n\n    ptr.resize(ma + 2);\n    FOR(p, 23, ma + 1) {\n     \
    \ if (lpf[p] != p) continue;\n      ptr[p] = len(S);\n      for (int n = p; n\
    \ <= ma; n += p) {\n        FOR(k, ptr1[n], ptr1[n + 1]) S.eb(ids[k]);\n     \
    \ }\n      ptr[p + 1] = len(S);\n    }\n\n    bidx.assign(ma + 1, -1);\n    {\n\
    \      vc<int> prime = {2, 3, 5, 7, 11, 13, 17, 19};\n      vc<BS> tmp(1 << 8);\n\
    \      tmp[0] = BS(N, 1);\n      FOR(i, 8) {\n        BS bs(N, 1);\n        FOR(j,\
    \ N) if (A[j] % prime[i] == 0) bs[j] = 0;\n        FOR(s, 1 << i) tmp[s | 1 <<\
    \ i] = tmp[s] & bs;\n      }\n      FOR(s, 1 << 8) {\n        int prd = 1;\n \
    \       FOR(i, 8) if (s >> i & 1) prd *= prime[i];\n        if (prd <= ma) {\n\
    \          bidx[prd] = len(dat);\n          dat.eb(tmp[s]);\n        }\n     \
    \ }\n    }\n\n    FOR(p, 23, ma + 1) {\n      if (lpf[p] != p) continue;\n   \
    \   int cnt = ptr[p + 1] - ptr[p];\n      if (cnt < thresh) continue;\n      BS\
    \ bs(N, 1);\n      FOR(i, ptr[p], ptr[p + 1]) bs[S[i]] = 0;\n      bidx[p] = len(dat);\n\
    \      dat.eb(bs);\n    }\n    remain = BS(N, 1);\n  }\n\n  void remove(int i)\
    \ { remain[i] = 0; }\n\n  // \u81EA\u5206\u81EA\u8EAB\u306F\u9664\u3044\u3066\n\
    \  template <typename F>\n  void enumerate_all(int i, F f) {\n    int d = gcd(A[i],\
    \ prod);\n    BS x = remain & dat[bidx[d]];\n    for (auto& [p, e] : factor_by_lpf(A[i],\
    \ lpf)) {\n      if (p < 20) continue;\n      if (bidx[p] == -1) {\n        FOR(k,\
    \ ptr[p], ptr[p + 1]) { x[S[k]] = 0; }\n      } else {\n        x &= dat[bidx[p]];\n\
    \      }\n    }\n    x.enumerate(0, N, f);\n  }\n};\n"
  dependsOn:
  - ds/my_bitset.hpp
  - nt/lpf_table.hpp
  - nt/primetable.hpp
  - nt/factor.hpp
  - random/base.hpp
  - nt/primetest.hpp
  - mod/mongomery_modint.hpp
  isVerificationFile: false
  path: nt/find_coprime_pair.hpp
  requiredBy: []
  timestamp: '2025-07-02 18:15:14+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: nt/find_coprime_pair.hpp
layout: document
redirect_from:
- /library/nt/find_coprime_pair.hpp
- /library/nt/find_coprime_pair.hpp.html
title: nt/find_coprime_pair.hpp
---
