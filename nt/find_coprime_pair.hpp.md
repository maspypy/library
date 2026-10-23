---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: ds/bit_array.hpp
    title: ds/bit_array.hpp
  - icon: ':question:'
    path: mod/montgomery_modint.hpp
    title: mod/montgomery_modint.hpp
  - icon: ':heavy_check_mark:'
    path: nt/factor.hpp
    title: nt/factor.hpp
  - icon: ':heavy_check_mark:'
    path: nt/is_prime.hpp
    title: nt/is_prime.hpp
  - icon: ':heavy_check_mark:'
    path: nt/prime_table.hpp
    title: nt/prime_table.hpp
  - icon: ':heavy_check_mark:'
    path: nt/spf_table.hpp
    title: nt/spf_table.hpp
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
    - https://github.com/maspypy/library/blob/main/nt/find_coprime_pair.hpp
  bundledCode: "#line 1 \"nt/find_coprime_pair.hpp\"\n// Source: https://github.com/maspypy/library/blob/main/nt/find_coprime_pair.hpp\n\
    #line 1 \"ds/bit_array.hpp\"\n// Source: https://github.com/maspypy/library/blob/main/ds/bit_array.hpp\n\
    /*\n01 \u5217\u3092\u7BA1\u7406\u3059\u308B\uFF0E\u5185\u90E8\u3067\u306F 64 bit\
    \ \u3054\u3068\u306B\u307E\u3068\u3081\u3066\u4FDD\u6301\u3059\u308B\uFF0E\u4E3B\
    \u306A\u7528\u9014\u3068\u3057\u3066\uFF0C\n- \u53EF\u5909\u9577\u3067\u30B9\u30E9\
    \u30A4\u30B9\u64CD\u4F5C\u304C\u53EF\u80FD\u306A bitset\n- F_2 \u4E0A\u306E\u591A\
    \u9805\u5F0F\n\u306A\u3069\u3092\u60F3\u5B9A\u3057\u3066\u3044\u308B\uFF0E\n*/\n\
    struct Bit_Array {\n  using T = Bit_Array;\n  int N;\n  vc<u64> dat;\n\n  // x\
    \ \u3067\u57CB\u3081\u308B\n  Bit_Array(int N = 0, int x = 0) : N(N) {\n    assert(0\
    \ <= N && N <= INT_MAX - 63);\n    assert(x == 0 || x == 1);\n    u64 v = (x ==\
    \ 0 ? 0 : -1);\n    dat.assign((N + 63) >> 6, v);\n    resize(N);\n  }\n\n  int\
    \ size() const { return N; }\n\n  void resize(int n) {\n    assert(0 <= n && n\
    \ <= INT_MAX - 63);\n    dat.resize((n + 63) >> 6);\n    int r = n & 63;\n   \
    \ if (r) dat.back() &= full_mask(r);\n    N = n;\n  }\n\n  void fill0() { fill(all(dat),\
    \ u64(0)); }\n  void fill1() {\n    fill(all(dat), u64(-1));\n    resize(N);\n\
    \  }\n\n  void push_back(bool b) {\n    resize(N + 1);\n    (*this)[N - 1] = b;\n\
    \  }\n\n  static T from_string(const string &S) {\n    int N = len(S);\n    T\
    \ ANS(N);\n    FOR(i, N) ANS[i] = (S[i] == '1');\n    return ANS;\n  }\n\n  class\
    \ Proxy {\n   public:\n    Proxy(vc<u64> &d, int i) : dat(d), index(i) {}\n  \
    \  operator bool() const { return (dat[index >> 6] >> (index & 63)) & 1; }\n \
    \   Proxy &operator=(bool value) {\n      u64 mask = u64(1) << (index & 63);\n\
    \      if (value)\n        dat[index >> 6] |= mask;\n      else\n        dat[index\
    \ >> 6] &= ~mask;\n      return *this;\n    }\n    Proxy &operator=(const Proxy\
    \ &p) { return *this = bool(p); }\n\n    // bit operations\n    Proxy &operator^=(bool\
    \ x) {\n      if (x) dat[index >> 6] ^= u64(1) << (index & 63);\n      return\
    \ *this;\n    }\n    Proxy &operator|=(bool x) {\n      if (x) dat[index >> 6]\
    \ |= u64(1) << (index & 63);\n      return *this;\n    }\n    Proxy &operator&=(bool\
    \ x) {\n      if (!x) dat[index >> 6] &= ~(u64(1) << (index & 63));\n      return\
    \ *this;\n    }\n    // finite field F_2\n    Proxy &operator+=(bool x) { return\
    \ *this ^= x; }\n    Proxy &operator-=(bool x) { return *this ^= x; }\n    Proxy\
    \ &operator*=(bool x) { return *this &= x; }\n    Proxy &operator/=(bool x) {\n\
    \      assert(x);\n      return *this;\n    }\n    bool inverse() const {\n  \
    \    assert(bool(*this));\n      return true;\n    }\n    void flip() { *this\
    \ ^= true; }\n\n   private:\n    vc<u64> &dat;\n    int index;\n  };\n\n  Proxy\
    \ operator[](int i) {\n    assert(0 <= i && i < N);\n    return Proxy(dat, i);\n\
    \  }\n  bool operator[](int i) const {\n    assert(0 <= i && i < N);\n    return\
    \ (dat[i >> 6] >> (i & 63)) & 1;\n  }\n\n  bool operator==(const T &p) const {\n\
    \    if (N != p.N) return false;\n    FOR(i, len(dat)) if (dat[i] != p.dat[i])\
    \ return false;\n    return true;\n  }\n\n  T &operator&=(const T &p) {\n    assert(N\
    \ == p.N);\n    FOR(i, len(dat)) dat[i] &= p.dat[i];\n    return *this;\n  }\n\
    \  T &operator|=(const T &p) {\n    assert(N == p.N);\n    FOR(i, len(dat)) dat[i]\
    \ |= p.dat[i];\n    return *this;\n  }\n  T &operator^=(const T &p) {\n    assert(N\
    \ == p.N);\n    FOR(i, len(dat)) dat[i] ^= p.dat[i];\n    return *this;\n  }\n\
    \  T operator&(const T &p) const { return T(*this) &= p; }\n  T operator|(const\
    \ T &p) const { return T(*this) |= p; }\n  T operator^(const T &p) const { return\
    \ T(*this) ^= p; }\n  T operator~() const {\n    T p = (*this);\n    p.flip_range(0,\
    \ N);\n    return p;\n  }\n\n  void set_minus_inplace(const T &other) {\n    assert(N\
    \ == other.N);\n    FOR(i, len(dat)) dat[i] = dat[i] & (~other.dat[i]);\n  }\n\
    \n  T set_minus(T other) const {\n    assert(N == other.N);\n    FOR(i, len(dat))\
    \ other.dat[i] = dat[i] & ~other.dat[i];\n    return other;\n  }\n\n  int count()\
    \ const {\n    int ans = 0;\n    for (u64 val : dat) ans += popcnt(val);\n   \
    \ return ans;\n  }\n\n  // size of set intersection, not modulo 2\n  int dot(const\
    \ T &p) const {\n    assert(N == p.N);\n    int ans = 0;\n    FOR(i, len(dat))\
    \ ans += popcnt(dat[i] & p.dat[i]);\n    return ans;\n  }\n\n  // minimum j >=\
    \ i with (*this)[j] = 1, or N if none\n  int next(int i) const {\n    chmax(i,\
    \ 0);\n    if (i >= N) return N;\n    int k = i >> 6;\n    {\n      u64 x = dat[k];\n\
    \      int s = i & 63;\n      x = (x >> s) << s;\n      if (x) return (k << 6)\
    \ | lowbit(x);\n    }\n    FOR(idx, k + 1, len(dat)) {\n      if (dat[idx] ==\
    \ 0) continue;\n      return (idx << 6) | lowbit(dat[idx]);\n    }\n    return\
    \ N;\n  }\n\n  // maximum j <= i with (*this)[j] = 1, or -1 if none\n  int prev(int\
    \ i) const {\n    chmin(i, N - 1);\n    if (i <= -1) return -1;\n    int k = i\
    \ >> 6;\n    if ((i & 63) < 63) {\n      u64 x = dat[k];\n      x &= (u64(1) <<\
    \ ((i & 63) + 1)) - 1;\n      if (x) return (k << 6) | topbit(x);\n      --k;\n\
    \    }\n    FOR_R(idx, k + 1) {\n      if (dat[idx] == 0) continue;\n      return\
    \ (idx << 6) | topbit(dat[idx]);\n    }\n    return -1;\n  }\n\n  Bit_Array slice(int\
    \ L, int R) const {\n    assert(0 <= L && L <= R && R <= N);\n    Bit_Array p(R\
    \ - L);\n    int rm = (R - L) & 63;\n    FOR(rm) {\n      int j = R - L - 1;\n\
    \      p.dat[j >> 6] |= u64((dat[(R - 1) >> 6] >> ((R - 1) & 63)) & 1)\n     \
    \                  << (j & 63);\n      --R;\n    }\n    int n = (R - L) >> 6;\n\
    \    int hi = L & 63;\n    int lo = 64 - hi;\n    int s = L >> 6;\n    if (hi\
    \ == 0) {\n      FOR(i, n) { p.dat[i] = dat[s + i]; }\n    } else {\n      FOR(i,\
    \ n) { p.dat[i] = (dat[s + i] >> hi) | (dat[s + i + 1] << lo); }\n    }\n    return\
    \ p;\n  }\n\n  int count_range(int L, int R) const {\n    assert(0 <= L && L <=\
    \ R && R <= N);\n    int cnt = 0;\n    while ((L < R) && (L & 63)) cnt += (*this)[L++];\n\
    \    while ((L < R) && (R & 63)) cnt += (*this)[--R];\n    int l = L >> 6, r =\
    \ R >> 6;\n    FOR(i, l, r) cnt += popcnt(dat[i]);\n    return cnt;\n  }\n\n \
    \ /*\n  OP = 0: assign, 1: or, 2: xor, 3: and.\n  \u81EA\u5DF1\u53C2\u7167\u304B\
    \u3064\u91CD\u8907\u3059\u308B\u533A\u9593\u3060\u3051\u3092\u9000\u907F\u3059\
    \u308B\u3002\u975E\u91CD\u8907\u306E\u5834\u5408\u306F\u5165\u529B\u30FB\u51FA\
    \u529B\u3092\u76F4\u63A5\n  \u6271\u3044\u3001\u901A\u5E38\u30B1\u30FC\u30B9\u306E\
    \ word loop \u3092\u5358\u7D14\u306B\u4FDD\u3064\u3002\n  */\n  template <int\
    \ OP>\n  void apply_to_range(\n      int L, int R, const Bit_Array &other, int\
    \ L1 = -1, int R1 = -1) {\n    static_assert(0 <= OP && OP < 4);\n    assert(0\
    \ <= L && L <= R && R <= N);\n    if (L1 == -1) L1 = 0, R1 = other.N;\n    assert(0\
    \ <= L1 && L1 <= R1 && R1 <= other.N);\n    assert(R - L == R1 - L1);\n\n    if\
    \ (&other == this && max(L, L1) < min(R, R1)) {\n      Bit_Array tmp = other.slice(L1,\
    \ R1);\n      apply_to_range<OP>(L, R, tmp);\n      return;\n    }\n\n    auto\
    \ apply_bit = [&](int i, bool x) {\n      u64 bit = u64(x) << (i & 63);\n    \
    \  if constexpr (OP == 0)\n        dat[i >> 6] = (dat[i >> 6] & ~(u64(1) << (i\
    \ & 63))) | bit;\n      if constexpr (OP == 1) dat[i >> 6] |= bit;\n      if constexpr\
    \ (OP == 2) dat[i >> 6] ^= bit;\n      if constexpr (OP == 3) dat[i >> 6] &= ~(u64(!x)\
    \ << (i & 63));\n    };\n    auto apply_word = [&](int i, u64 x) {\n      if constexpr\
    \ (OP == 0) dat[i] = x;\n      if constexpr (OP == 1) dat[i] |= x;\n      if constexpr\
    \ (OP == 2) dat[i] ^= x;\n      if constexpr (OP == 3) dat[i] &= x;\n    };\n\
    \    auto get_bit = [&](int i) -> bool {\n      return (other.dat[i >> 6] >> (i\
    \ & 63)) & 1;\n    };\n\n    while (L < R && (L & 63)) apply_bit(L++, get_bit(L1++));\n\
    \    int n = (R - L) >> 6;\n    int l = L >> 6, s = L1 >> 6, sh = L1 & 63;\n \
    \   if (sh == 0) {\n      FOR(i, n) apply_word(l + i, other.dat[s + i]);\n   \
    \ } else {\n      int lo = 64 - sh;\n      FOR(i, n) {\n        apply_word(\n\
    \            l + i, (other.dat[s + i] >> sh) | (other.dat[s + i + 1] << lo));\n\
    \      }\n    }\n    L += 64 * n, L1 += 64 * n;\n    while (L < R) apply_bit(L++,\
    \ get_bit(L1++));\n  }\n\n  void assign_to_range(\n      int L, int R, const Bit_Array\
    \ &other, int L1 = -1, int R1 = -1) {\n    apply_to_range<0>(L, R, other, L1,\
    \ R1);\n  }\n  void or_to_range(\n      int L, int R, const Bit_Array &other,\
    \ int L1 = -1, int R1 = -1) {\n    apply_to_range<1>(L, R, other, L1, R1);\n \
    \ }\n  void xor_to_range(\n      int L, int R, const Bit_Array &other, int L1\
    \ = -1, int R1 = -1) {\n    apply_to_range<2>(L, R, other, L1, R1);\n  }\n  void\
    \ and_to_range(\n      int L, int R, const Bit_Array &other, int L1 = -1, int\
    \ R1 = -1) {\n    apply_to_range<3>(L, R, other, L1, R1);\n  }\n\n  // p \u306F\
    \ [i:N) \u306B\u3057\u304B\u306A\u3044\u3068\u3057\u3066 p \u3092 xor \u3059\u308B\
    \n  // \u884C\u5217\u57FA\u672C\u5909\u5F62\u306A\u3069\u3067\u5229\u7528\u53EF\
    \u80FD\n  void xor_suffix(int i, const Bit_Array &p) {\n    assert(N == p.N &&\
    \ 0 <= i && i < N);\n    FOR(k, i / 64, len(dat)) { dat[k] ^= p.dat[k]; }\n  }\n\
    \n  // [L,R) \u3092 1 \u306B\u5909\u66F4\n  void set_range(int L, int R) {\n \
    \   assert(0 <= L && L <= R && R <= N);\n    while (L < R && (L & 63)) set(L++);\n\
    \    while (L < R && (R & 63)) set(--R);\n    FOR(i, L >> 6, R >> 6) dat[i] =\
    \ u64(-1);\n  }\n\n  // [L,R) \u3092 0 \u306B\u5909\u66F4\n  void reset_range(int\
    \ L, int R) {\n    assert(0 <= L && L <= R && R <= N);\n    while (L < R && (L\
    \ & 63)) reset(L++);\n    while (L < R && (R & 63)) reset(--R);\n    FOR(i, L\
    \ >> 6, R >> 6) dat[i] = u64(0);\n  }\n\n  // [L,R) \u3092 flip\n  void flip_range(int\
    \ L, int R) {\n    assert(0 <= L && L <= R && R <= N);\n    while (L < R && (L\
    \ & 63)) flip(L++);\n    while (L < R && (R & 63)) flip(--R);\n    FOR(i, L >>\
    \ 6, R >> 6) dat[i] ^= u64(-1);\n  }\n\n  // bitset \u306B\u4ED5\u69D8\u3092\u5408\
    \u308F\u305B\u308B\n  void set(int i) { (*this)[i] = 1; }\n  void reset(int i)\
    \ { (*this)[i] = 0; }\n  void flip(int i) { (*this)[i].flip(); }\n  void set()\
    \ { set_range(0, N); }\n  void reset() { reset_range(0, N); }\n  void flip() {\
    \ flip_range(0, N); }\n  bool any() const {\n    FOR(i, len(dat)) {\n      if\
    \ (dat[i]) return true;\n    }\n    return false;\n  }\n\n  bool has_intersection(const\
    \ T &other) const {\n    assert(N == other.N);\n    FOR(i, len(dat)) if (dat[i]\
    \ & other.dat[i]) return true;\n    return false;\n  }\n\n  template <typename\
    \ F>\n  void enumerate_intersection(const T &other, F f) const {\n    assert(N\
    \ == other.N);\n    bool end = false;\n    FOR(i, len(dat)) {\n      u64 x = dat[i]\
    \ & other.dat[i];\n      while (x) {\n        int k = lowbit(x);\n        f(64\
    \ * i + k, end);\n        if (end) return;\n        x &= x - 1;\n      }\n   \
    \ }\n  }\n\n  bool ALL() const {\n    int r = N & 63;\n    if (r != 0 && dat.back()\
    \ != full_mask(r)) return 0;\n    for (int i = 0; i < N / 64; ++i)\n      if (dat[i]\
    \ != u64(-1)) return false;\n    return true;\n  }\n\n  Bit_Array reversed() const\
    \ {\n    int M = ceil(N, 64) * 64;\n    Bit_Array a = *this;\n    a.resize(M);\n\
    \    reverse(all(a.dat));\n    for (u64 &x : a.dat) x = bit_reverse(x);\n    return\
    \ a.slice(M - N, M);\n  }\n\n  // bs[i]==true \u3067\u3042\u308B\u3088\u3046\u306A\
    \ i \u5168\u4F53\n  vc<int> collect_idx() const {\n    vc<int> I;\n    FOR(i,\
    \ N) if ((*this)[i]) I.eb(i);\n    return I;\n  }\n\n  bool is_subset(const T\
    \ &other) const {\n    assert(other.N == N);\n    FOR(i, len(dat)) {\n      u64\
    \ a = dat[i], b = other.dat[i];\n      if ((a & b) != a) return false;\n    }\n\
    \    return true;\n  }\n\n  int _Find_first() const { return next(0); }\n  int\
    \ _Find_next(int p) const { return next(p + 1); }\n\n  template <typename F>\n\
    \  void enumerate(int L, int R, F f) const {\n    assert(0 <= L && L <= R && R\
    \ <= N);\n    if (L == R) return;\n    int p = ((*this)[L] ? L : _Find_next(L));\n\
    \    while (p < R) {\n      f(p);\n      p = _Find_next(p);\n    }\n  }\n\n  inline\
    \ static string TO_STR[256];\n  string to_string() const {\n    if (TO_STR[0].empty())\
    \ precompute();\n    string S;\n    for (u64 x : dat) {\n      FOR(i, 8) S +=\
    \ TO_STR[(x >> (8 * i) & 255)];\n    }\n    S.resize(N);\n    return S;\n  }\n\
    \n  static void precompute() {\n    FOR(s, 256) {\n      string x;\n      FOR(i,\
    \ 8) x += '0' + (s >> i & 1);\n      TO_STR[s] = x;\n    }\n  }\n\n  void prefix_xor_sum()\
    \ {\n    int carry = 0;\n    for (u64 &a : dat) {\n      a ^= carry;\n      carry\
    \ = __builtin_parityll(a);\n      a ^= a << (1 << 0);\n      a ^= a << (1 << 1);\n\
    \      a ^= a << (1 << 2);\n      a ^= a << (1 << 3);\n      a ^= a << (1 << 4);\n\
    \      a ^= a << (1 << 5);\n    }\n    resize(N);\n  }\n};\n#line 1 \"nt/spf_table.hpp\"\
    \n// Source: https://github.com/maspypy/library/blob/main/nt/spf_table.hpp\n#line\
    \ 1 \"nt/prime_table.hpp\"\n// Source: https://github.com/maspypy/library/blob/main/nt/prime_table.hpp\n\
    \ntemplate <typename T = int>\nvc<T> prime_table(int LIM) {\n  ++LIM;\n  const\
    \ int S = 32768;\n  static int done = 2;\n  static vc<T> primes = {2}, sieve(S\
    \ + 1);\n\n  if (done < LIM) {\n    done = LIM;\n\n    primes = {2}, sieve.assign(S\
    \ + 1, 0);\n    const int R = LIM / 2;\n    primes.reserve(int(LIM / log(LIM)\
    \ * 1.1));\n    vc<pair<int, int>> cp;\n    for (int i = 3; i <= S; i += 2) {\n\
    \      if (!sieve[i]) {\n        cp.eb(i, i * i / 2);\n        for (int j = i\
    \ * i; j <= S; j += 2 * i) sieve[j] = 1;\n      }\n    }\n    for (int L = 1;\
    \ L <= R; L += S) {\n      array<bool, S> block{};\n      for (auto& [p, idx]\
    \ : cp)\n        for (int i = idx; i < S + L; idx = (i += p)) block[i - L] = 1;\n\
    \      FOR(i, min(S, R - L)) if (!block[i]) primes.eb((L + i) * 2 + 1);\n    }\n\
    \  }\n  int k = LB(primes, LIM);\n  return {primes.begin(), primes.begin() + k};\n\
    }\n#line 3 \"nt/spf_table.hpp\"\n\n// [0, LIM], 0, 1 \u306B\u306F -1 \u304C\u5165\
    \u308B\u3002\nvc<int> spf_table(int LIM) {\n  auto primes = prime_table(LIM);\n\
    \  vc<int> spf(LIM + 1, -1);\n  int sq = sqrt(LIM);\n  for (int i = 2; i <= LIM;\
    \ i += 2) spf[i] = 2;\n  FOR_R(i, len(primes)) {\n    auto p = primes[i];\n  \
    \  spf[p] = p;\n    if (sq < p) continue;\n    for (int k = p * p; k <= LIM; k\
    \ += 2 * p) spf[k] = p;\n  }\n  return spf;\n}\n#line 1 \"nt/factor.hpp\"\n//\
    \ Source: https://github.com/maspypy/library/blob/main/nt/factor.hpp\n\n#line\
    \ 1 \"random/base.hpp\"\n// Source: https://github.com/maspypy/library/blob/main/random/base.hpp\n\
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
    \ return res;\n}\n#line 5 \"nt/find_coprime_pair.hpp\"\n\n// A[i] \u3068\u4E92\
    \u3044\u306B\u7D20\u306A A[j] \u3092\u691C\u51FA / A[i] \u306E\u524A\u9664\n//\
    \ N=1e5,A=1e7 \u9023\u7D50\u6210\u5206\u5206\u89E3 1030ms\n// https://codeforces.com/contest/1148/problem/G\n\
    template <int thresh = 200>\nstruct Find_Coprime_Pair {\n  // thresh \u4EE5\u4E0A\
    \u3042\u308B\u7D20\u6570\u3092 bitset \u7BA1\u7406\n  using BS = Bit_Array;\n\
    \  int N;\n  vc<int> A;\n  vc<int> spf;\n  vc<int> S;\n  vc<int> ptr;\n  vc<int>\
    \ bidx;\n  vc<BS> dat;\n  BS remain;\n  // 20 \u4EE5\u4E0B\u306E\u7D20\u6570\u306E\
    \u7A4D\n  const int prod = 9699690;\n\n  Find_Coprime_Pair(vc<int> A) : A(A) {\n\
    \    N = len(A);\n    int ma = MAX(A);\n    spf = spf_table(ma);\n    vc<int>\
    \ ptr1(ma + 1);\n    vc<int> ids(N);\n    for (auto& x : A) ptr1[x]++;\n    ptr1\
    \ = cumsum<int>(ptr1);\n    FOR(i, N) { ids[ptr1[A[i]]++] = i; }\n    FOR_R(i,\
    \ len(ptr1) - 1) ptr1[i + 1] = ptr1[i];\n\n    ptr.resize(ma + 2);\n    FOR(p,\
    \ 23, ma + 1) {\n      if (spf[p] != p) continue;\n      ptr[p] = len(S);\n  \
    \    for (int n = p; n <= ma; n += p) {\n        FOR(k, ptr1[n], ptr1[n + 1])\
    \ S.eb(ids[k]);\n      }\n      ptr[p + 1] = len(S);\n    }\n\n    bidx.assign(ma\
    \ + 1, -1);\n    {\n      vc<int> prime = {2, 3, 5, 7, 11, 13, 17, 19};\n    \
    \  vc<BS> tmp(1 << 8);\n      tmp[0] = BS(N, 1);\n      FOR(i, 8) {\n        BS\
    \ bs(N, 1);\n        FOR(j, N) if (A[j] % prime[i] == 0) bs[j] = 0;\n        FOR(s,\
    \ 1 << i) tmp[s | 1 << i] = tmp[s] & bs;\n      }\n      FOR(s, 1 << 8) {\n  \
    \      int prd = 1;\n        FOR(i, 8) if (s >> i & 1) prd *= prime[i];\n    \
    \    if (prd <= ma) {\n          bidx[prd] = len(dat);\n          dat.eb(tmp[s]);\n\
    \        }\n      }\n    }\n\n    FOR(p, 23, ma + 1) {\n      if (spf[p] != p)\
    \ continue;\n      int cnt = ptr[p + 1] - ptr[p];\n      if (cnt < thresh) continue;\n\
    \      BS bs(N, 1);\n      FOR(i, ptr[p], ptr[p + 1]) bs[S[i]] = 0;\n      bidx[p]\
    \ = len(dat);\n      dat.eb(bs);\n    }\n    remain = BS(N, 1);\n  }\n\n  void\
    \ remove(int i) { remain[i] = 0; }\n\n  // \u81EA\u5206\u81EA\u8EAB\u306F\u9664\
    \u3044\u3066\n  template <typename F>\n  void enumerate_all(int i, F f) {\n  \
    \  int d = gcd(A[i], prod);\n    BS x = remain & dat[bidx[d]];\n    for (auto&\
    \ [p, e] : factor_by_spf(A[i], spf)) {\n      if (p < 20) continue;\n      if\
    \ (bidx[p] == -1) {\n        FOR(k, ptr[p], ptr[p + 1]) { x[S[k]] = 0; }\n   \
    \   } else {\n        x &= dat[bidx[p]];\n      }\n    }\n    x.enumerate(0, N,\
    \ f);\n  }\n};\n"
  code: "// Source: https://github.com/maspypy/library/blob/main/nt/find_coprime_pair.hpp\n\
    #include \"ds/bit_array.hpp\"\n#include \"nt/spf_table.hpp\"\n#include \"nt/factor.hpp\"\
    \n\n// A[i] \u3068\u4E92\u3044\u306B\u7D20\u306A A[j] \u3092\u691C\u51FA / A[i]\
    \ \u306E\u524A\u9664\n// N=1e5,A=1e7 \u9023\u7D50\u6210\u5206\u5206\u89E3 1030ms\n\
    // https://codeforces.com/contest/1148/problem/G\ntemplate <int thresh = 200>\n\
    struct Find_Coprime_Pair {\n  // thresh \u4EE5\u4E0A\u3042\u308B\u7D20\u6570\u3092\
    \ bitset \u7BA1\u7406\n  using BS = Bit_Array;\n  int N;\n  vc<int> A;\n  vc<int>\
    \ spf;\n  vc<int> S;\n  vc<int> ptr;\n  vc<int> bidx;\n  vc<BS> dat;\n  BS remain;\n\
    \  // 20 \u4EE5\u4E0B\u306E\u7D20\u6570\u306E\u7A4D\n  const int prod = 9699690;\n\
    \n  Find_Coprime_Pair(vc<int> A) : A(A) {\n    N = len(A);\n    int ma = MAX(A);\n\
    \    spf = spf_table(ma);\n    vc<int> ptr1(ma + 1);\n    vc<int> ids(N);\n  \
    \  for (auto& x : A) ptr1[x]++;\n    ptr1 = cumsum<int>(ptr1);\n    FOR(i, N)\
    \ { ids[ptr1[A[i]]++] = i; }\n    FOR_R(i, len(ptr1) - 1) ptr1[i + 1] = ptr1[i];\n\
    \n    ptr.resize(ma + 2);\n    FOR(p, 23, ma + 1) {\n      if (spf[p] != p) continue;\n\
    \      ptr[p] = len(S);\n      for (int n = p; n <= ma; n += p) {\n        FOR(k,\
    \ ptr1[n], ptr1[n + 1]) S.eb(ids[k]);\n      }\n      ptr[p + 1] = len(S);\n \
    \   }\n\n    bidx.assign(ma + 1, -1);\n    {\n      vc<int> prime = {2, 3, 5,\
    \ 7, 11, 13, 17, 19};\n      vc<BS> tmp(1 << 8);\n      tmp[0] = BS(N, 1);\n \
    \     FOR(i, 8) {\n        BS bs(N, 1);\n        FOR(j, N) if (A[j] % prime[i]\
    \ == 0) bs[j] = 0;\n        FOR(s, 1 << i) tmp[s | 1 << i] = tmp[s] & bs;\n  \
    \    }\n      FOR(s, 1 << 8) {\n        int prd = 1;\n        FOR(i, 8) if (s\
    \ >> i & 1) prd *= prime[i];\n        if (prd <= ma) {\n          bidx[prd] =\
    \ len(dat);\n          dat.eb(tmp[s]);\n        }\n      }\n    }\n\n    FOR(p,\
    \ 23, ma + 1) {\n      if (spf[p] != p) continue;\n      int cnt = ptr[p + 1]\
    \ - ptr[p];\n      if (cnt < thresh) continue;\n      BS bs(N, 1);\n      FOR(i,\
    \ ptr[p], ptr[p + 1]) bs[S[i]] = 0;\n      bidx[p] = len(dat);\n      dat.eb(bs);\n\
    \    }\n    remain = BS(N, 1);\n  }\n\n  void remove(int i) { remain[i] = 0; }\n\
    \n  // \u81EA\u5206\u81EA\u8EAB\u306F\u9664\u3044\u3066\n  template <typename\
    \ F>\n  void enumerate_all(int i, F f) {\n    int d = gcd(A[i], prod);\n    BS\
    \ x = remain & dat[bidx[d]];\n    for (auto& [p, e] : factor_by_spf(A[i], spf))\
    \ {\n      if (p < 20) continue;\n      if (bidx[p] == -1) {\n        FOR(k, ptr[p],\
    \ ptr[p + 1]) { x[S[k]] = 0; }\n      } else {\n        x &= dat[bidx[p]];\n \
    \     }\n    }\n    x.enumerate(0, N, f);\n  }\n};\n"
  dependsOn:
  - ds/bit_array.hpp
  - nt/spf_table.hpp
  - nt/prime_table.hpp
  - nt/factor.hpp
  - random/base.hpp
  - nt/is_prime.hpp
  - mod/montgomery_modint.hpp
  isVerificationFile: false
  path: nt/find_coprime_pair.hpp
  requiredBy: []
  timestamp: '2026-10-23 11:03:42+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: nt/find_coprime_pair.hpp
layout: document
redirect_from:
- /library/nt/find_coprime_pair.hpp
- /library/nt/find_coprime_pair.hpp.html
title: nt/find_coprime_pair.hpp
---
