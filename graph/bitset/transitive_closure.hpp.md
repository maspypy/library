---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: ds/bit_array.hpp
    title: ds/bit_array.hpp
  - icon: ':question:'
    path: ds/hashmap.hpp
    title: ds/hashmap.hpp
  - icon: ':question:'
    path: graph/base.hpp
    title: graph/base.hpp
  - icon: ':heavy_check_mark:'
    path: graph/strongly_connected_component.hpp
    title: graph/strongly_connected_component.hpp
  _extendedRequiredBy:
  - icon: ':warning:'
    path: graph/bitset/transitive_reduction.hpp
    title: graph/bitset/transitive_reduction.hpp
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links:
    - https://atcoder.jp/contests/pakencamp-2023-day2/tasks/pakencamp_2023_day2_e
    - https://codeforces.com/contest/641/problem/F
    - https://github.com/maspypy/library/blob/main/graph/bitset/transitive_closure.hpp
  bundledCode: "#line 1 \"graph/bitset/transitive_closure.hpp\"\n// Source: https://github.com/maspypy/library/blob/main/graph/bitset/transitive_closure.hpp\n\
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
    \    bool end = false;\n    while (p < R) {\n      f(p, end);\n      if (end)\
    \ return;\n      p = _Find_next(p);\n    }\n  }\n\n  inline static string TO_STR[256];\n\
    \  string to_string() const {\n    if (TO_STR[0].empty()) precompute();\n    string\
    \ S;\n    for (u64 x : dat) {\n      FOR(i, 8) S += TO_STR[(x >> (8 * i) & 255)];\n\
    \    }\n    S.resize(N);\n    return S;\n  }\n\n  static void precompute() {\n\
    \    FOR(s, 256) {\n      string x;\n      FOR(i, 8) x += '0' + (s >> i & 1);\n\
    \      TO_STR[s] = x;\n    }\n  }\n\n  void prefix_xor_sum() {\n    int carry\
    \ = 0;\n    for (u64 &a : dat) {\n      a ^= carry;\n      carry = __builtin_parityll(a);\n\
    \      a ^= a << (1 << 0);\n      a ^= a << (1 << 1);\n      a ^= a << (1 << 2);\n\
    \      a ^= a << (1 << 3);\n      a ^= a << (1 << 4);\n      a ^= a << (1 << 5);\n\
    \    }\n    resize(N);\n  }\n};\n#line 1 \"graph/strongly_connected_component.hpp\"\
    \n// Source: https://github.com/maspypy/library/blob/main/graph/strongly_connected_component.hpp\n\
    #line 1 \"graph/base.hpp\"\n// Source: https://github.com/maspypy/library/blob/main/graph/base.hpp\n\
    #line 1 \"ds/hashmap.hpp\"\n// Source: https://github.com/maspypy/library/blob/main/ds/hashmap.hpp\n\
    \n// u64 -> Val\ntemplate <typename Val>\nstruct HashMap {\n  // n \u306F\u5165\
    \u308C\u305F\u3044\u3082\u306E\u306E\u500B\u6570\u3067 ok\n  HashMap(u32 n = 0)\
    \ { build(n); }\n  void build(u32 n) {\n    u32 k = 8;\n    while (k < n * 2)\
    \ k *= 2;\n    cap = k / 2, mask = k - 1;\n    key.resize(k), val.resize(k), used.assign(k,\
    \ 0);\n  }\n\n  // size \u3092\u4FDD\u3063\u305F\u307E\u307E. size=0 \u306B\u3059\
    \u308B\u3068\u304D\u306F build \u3059\u308B\u3053\u3068.\n  void clear() {\n \
    \   used.assign(len(used), 0);\n    cap = (mask + 1) / 2;\n  }\n  int size() {\
    \ return len(used) / 2 - cap; }\n\n  int index(const u64& k) {\n    int i = 0;\n\
    \    for (i = hash(k); used[i] && key[i] != k; i = (i + 1) & mask) {\n    }\n\
    \    return i;\n  }\n\n  Val& operator[](const u64& k) {\n    int i = index(k);\n\
    \    if (used[i]) return val[i];\n    if (cap == 0) extend(), i = index(k);\n\
    \    used[i] = 1, key[i] = k, val[i] = Val{}, --cap;\n    return val[i];\n  }\n\
    \n  Val get(const u64& k, Val default_value) {\n    int i = index(k);\n    return\
    \ (used[i] ? val[i] : default_value);\n  }\n\n  bool count(const u64& k) {\n \
    \   int i = index(k);\n    return used[i] && key[i] == k;\n  }\n\n  // f(key,\
    \ val)\n  template <typename F>\n  void enumerate_all(F f) {\n    bool end = false;\n\
    \    FOR(i, len(used)) {\n      if (used[i]) f(key[i], val[i], end);\n      if\
    \ (end) break;\n    }\n  }\n\n private:\n  u32 cap, mask;\n  vc<u64> key;\n  vc<Val>\
    \ val;\n  vc<bool> used;\n\n  u64 hash(u64 x) {\n    static const u64 FIXED_RANDOM\
    \ =\n        std::chrono::steady_clock::now().time_since_epoch().count();\n  \
    \  x += FIXED_RANDOM;\n    x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;\n    x =\
    \ (x ^ (x >> 27)) * 0x94d049bb133111eb;\n    return (x ^ (x >> 31)) & mask;\n\
    \  }\n\n  void extend() {\n    vc<pair<u64, Val>> dat;\n    dat.reserve(len(used)\
    \ / 2 - cap);\n    FOR(i, len(used)) {\n      if (used[i]) dat.eb(key[i], val[i]);\n\
    \    }\n    build(2 * len(dat));\n    for (auto& [a, b] : dat) (*this)[a] = b;\n\
    \  }\n};\n#line 3 \"graph/base.hpp\"\n\ntemplate <typename T>\nstruct Edge {\n\
    \  int frm, to;\n  T cost;\n  int id;\n};\n\ntemplate <typename T = int, bool\
    \ directed = false>\nstruct Graph {\n  static constexpr bool is_directed = directed;\n\
    \  int N, M;\n  using cost_type = T;\n  using edge_type = Edge<T>;\n  vector<edge_type>\
    \ edges;\n  vector<int> indptr;\n  vector<edge_type> csr_edges;\n  mutable vc<int>\
    \ vc_deg, vc_indeg, vc_outdeg;\n  mutable HashMap<int> MP_FOR_EID;\n  bool prepared;\n\
    \n  class OutgoingEdges {\n   public:\n    OutgoingEdges(const Graph* G, int l,\
    \ int r) : G(G), l(l), r(r) {}\n\n    const edge_type* begin() const {\n     \
    \ if (l == r) {\n        return 0;\n      }\n      return &G->csr_edges[l];\n\
    \    }\n\n    const edge_type* end() const {\n      if (l == r) {\n        return\
    \ 0;\n      }\n      return &G->csr_edges[r];\n    }\n\n   private:\n    const\
    \ Graph* G;\n    int l, r;\n  };\n\n  bool is_prepared() const { return prepared;\
    \ }\n\n  Graph() : N(0), M(0), prepared(0) {}\n  Graph(int N) : N(N), M(0), prepared(0)\
    \ {}\n\n  void build(int n) {\n    N = n, M = 0;\n    prepared = 0;\n    edges.clear();\n\
    \    indptr.clear();\n    csr_edges.clear();\n    vc_deg.clear();\n    vc_indeg.clear();\n\
    \    vc_outdeg.clear();\n    MP_FOR_EID.clear();\n  }\n\n  void add(int frm, int\
    \ to, T cost = 1, int i = -1) {\n    assert(!prepared);\n    assert(0 <= frm &&\
    \ frm < N && 0 <= to && to < N);\n    if (i == -1) i = M;\n    auto e = edge_type({frm,\
    \ to, cost, i});\n    edges.eb(e);\n    ++M;\n  }\n\n#ifdef FASTIO\n  // wt, off\n\
    \  void read_tree(bool wt = false, int off = 1) { read_graph(N - 1, wt, off);\
    \ }\n\n  void read_graph(int M, bool wt = false, int off = 1) {\n    for (int\
    \ m = 0; m < M; ++m) {\n      INT(a, b);\n      a -= off, b -= off;\n      if\
    \ (!wt) {\n        add(a, b);\n      } else {\n        T c;\n        read(c);\n\
    \        add(a, b, c);\n      }\n    }\n    build();\n  }\n#endif\n\n  void build()\
    \ {\n    assert(!prepared);\n    prepared = true;\n    indptr.assign(N + 1, 0);\n\
    \    for (auto&& e : edges) {\n      indptr[e.frm + 1]++;\n      if (!directed)\
    \ indptr[e.to + 1]++;\n    }\n    for (int v = 0; v < N; ++v) {\n      indptr[v\
    \ + 1] += indptr[v];\n    }\n    auto counter = indptr;\n    csr_edges.resize(indptr.back()\
    \ + 1);\n    for (auto&& e : edges) {\n      csr_edges[counter[e.frm]++] = e;\n\
    \      if (!directed)\n        csr_edges[counter[e.to]++] = edge_type({e.to, e.frm,\
    \ e.cost, e.id});\n    }\n  }\n\n  OutgoingEdges operator[](int v) const {\n \
    \   assert(prepared);\n    return {this, indptr[v], indptr[v + 1]};\n  }\n\n \
    \ vc<int> deg_array() const {\n    if (vc_deg.empty()) calc_deg();\n    return\
    \ vc_deg;\n  }\n\n  pair<vc<int>, vc<int>> deg_array_inout() const {\n    if (vc_indeg.empty())\
    \ calc_deg_inout();\n    return {vc_indeg, vc_outdeg};\n  }\n\n  int deg(int v)\
    \ const {\n    if (vc_deg.empty()) calc_deg();\n    return vc_deg[v];\n  }\n\n\
    \  int in_deg(int v) const {\n    if (vc_indeg.empty()) calc_deg_inout();\n  \
    \  return vc_indeg[v];\n  }\n\n  int out_deg(int v) const {\n    if (vc_outdeg.empty())\
    \ calc_deg_inout();\n    return vc_outdeg[v];\n  }\n\n#ifdef FASTIO\n  void debug()\
    \ {\n#ifdef LOCAL\n    print(\"Graph\");\n    if (!prepared) {\n      print(\"\
    frm to cost id\");\n      for (auto&& e : edges) print(e.frm, e.to, e.cost, e.id);\n\
    \    } else {\n      print(\"indptr\", indptr);\n      print(\"frm to cost id\"\
    );\n      FOR(v, N) for (auto&& e : (*this)[v]) print(e.frm, e.to, e.cost, e.id);\n\
    \    }\n    flush();\n#endif\n  }\n#endif\n\n  mutable vc<int> new_idx;\n  mutable\
    \ vc<bool> used_e;\n\n  // G \u306B\u304A\u3051\u308B\u9802\u70B9 V[i] \u304C\u3001\
    \u65B0\u3057\u3044\u30B0\u30E9\u30D5\u3067 i \u306B\u306A\u308B\u3088\u3046\u306B\
    \u3059\u308B\n  // {G, es}\n  // sum(deg(v)) \u306E\u8A08\u7B97\u91CF\u306B\u306A\
    \u3063\u3066\u3044\u3066\u3001\n  // \u65B0\u3057\u3044\u30B0\u30E9\u30D5\u306E\
    \ n+m \u3088\u308A\u5927\u304D\u3044\u53EF\u80FD\u6027\u304C\u3042\u308B\u306E\
    \u3067\u6CE8\u610F\n  Graph<T, directed> rearrange(const vc<int>& V, bool keep_eid\
    \ = 0) const {\n    if (len(new_idx) != N) new_idx.assign(N, -1);\n    int n =\
    \ len(V);\n    FOR(i, n) new_idx[V[i]] = i;\n    Graph<T, directed> G(n);\n  \
    \  vc<int> history;\n    FOR(i, n) {\n      for (auto&& e : (*this)[V[i]]) {\n\
    \        if (len(used_e) <= e.id) used_e.resize(e.id + 1);\n        if (used_e[e.id])\
    \ continue;\n        int a = e.frm, b = e.to;\n        if (new_idx[a] != -1 &&\
    \ new_idx[b] != -1) {\n          history.eb(e.id);\n          used_e[e.id] = 1;\n\
    \          int eid = (keep_eid ? e.id : -1);\n          G.add(new_idx[a], new_idx[b],\
    \ e.cost, eid);\n        }\n      }\n    }\n    FOR(i, n) new_idx[V[i]] = -1;\n\
    \    for (auto&& eid : history) used_e[eid] = 0;\n    G.build();\n    return G;\n\
    \  }\n\n  Graph<T, true> to_directed_tree(int root = -1) const {\n    if (root\
    \ == -1) root = 0;\n    assert(!is_directed && prepared && M == N - 1);\n    Graph<T,\
    \ true> G1(N);\n    vc<int> par(N, -1);\n    auto dfs = [&](auto& dfs, int v)\
    \ -> void {\n      for (auto& e : (*this)[v]) {\n        if (e.to == par[v]) continue;\n\
    \        par[e.to] = v, dfs(dfs, e.to);\n      }\n    };\n    dfs(dfs, root);\n\
    \    for (auto& e : edges) {\n      int a = e.frm, b = e.to;\n      if (par[a]\
    \ == b) swap(a, b);\n      assert(par[b] == a);\n      G1.add(a, b, e.cost);\n\
    \    }\n    G1.build();\n    return G1;\n  }\n\n  int get_eid(u64 a, u64 b) const\
    \ {\n    if (len(MP_FOR_EID) == 0) {\n      MP_FOR_EID.build(N - 1);\n      for\
    \ (auto& e : edges) {\n        u64 a = e.frm, b = e.to;\n        u64 k = to_eid_key(a,\
    \ b);\n        MP_FOR_EID[k] = e.id;\n      }\n    }\n    return MP_FOR_EID.get(to_eid_key(a,\
    \ b), -1);\n  }\n\n  u64 to_eid_key(u64 a, u64 b) const {\n    if (!directed &&\
    \ a > b) swap(a, b);\n    return N * a + b;\n  }\n\n private:\n  void calc_deg()\
    \ const {\n    assert(vc_deg.empty());\n    vc_deg.resize(N);\n    for (auto&&\
    \ e : edges) vc_deg[e.frm]++, vc_deg[e.to]++;\n  }\n\n  void calc_deg_inout()\
    \ const {\n    assert(vc_indeg.empty());\n    vc_indeg.resize(N);\n    vc_outdeg.resize(N);\n\
    \    for (auto&& e : edges) {\n      vc_indeg[e.to]++, vc_outdeg[e.frm]++;\n \
    \   }\n  }\n};\n#line 3 \"graph/strongly_connected_component.hpp\"\n\ntemplate\
    \ <typename GT>\npair<int, vc<int>> strongly_connected_component(const GT& G)\
    \ {\n  static_assert(GT::is_directed);\n  assert(G.is_prepared());\n  int N =\
    \ G.N;\n  int nc = 0;\n  vc<int> comp(N), low(N), ord(N, -1), path;\n  vc<int>\
    \ par(N, -1), it = G.indptr;\n  int now = 0;\n\n  FOR(s, N) {\n    if (ord[s]\
    \ != -1) continue;\n    int v = s;\n    low[v] = ord[v] = now++;\n    path.eb(v);\n\
    \n    while (v != -1) {\n      if (it[v] < G.indptr[v + 1]) {\n        int to\
    \ = G.csr_edges[it[v]++].to;\n        if (ord[to] == -1) {\n          par[to]\
    \ = v;\n          v = to;\n          low[v] = ord[v] = now++;\n          path.eb(v);\n\
    \        } else {\n          chmin(low[v], ord[to]);\n        }\n      } else\
    \ {\n        if (low[v] == ord[v]) {\n          while (1) {\n            int u\
    \ = POP(path);\n            ord[u] = N, comp[u] = nc;\n            if (u == v)\
    \ break;\n          }\n          ++nc;\n        }\n        int p = par[v];\n \
    \       if (p != -1) chmin(low[p], low[v]);\n        v = p;\n      }\n    }\n\
    \  }\n  FOR(v, N) comp[v] = nc - 1 - comp[v];\n  return {nc, comp};\n}\n\ntemplate\
    \ <typename GT>\nGraph<int, 1> scc_dag(const GT& G, int nc, const vc<int>& comp)\
    \ {\n  Graph<int, 1> DAG(nc);\n  vvc<int> edges(nc);\n  for (auto&& e : G.edges)\
    \ {\n    int x = comp[e.frm], y = comp[e.to];\n    if (x == y) continue;\n   \
    \ edges[x].eb(y);\n  }\n  FOR(c, nc) {\n    UNIQUE(edges[c]);\n    for (auto&&\
    \ to : edges[c]) DAG.add(c, to);\n  }\n  DAG.build();\n  return DAG;\n}\n#line\
    \ 4 \"graph/bitset/transitive_closure.hpp\"\n\n// https://codeforces.com/contest/641/problem/F\n\
    // https://atcoder.jp/contests/pakencamp-2023-day2/tasks/pakencamp_2023_day2_e\n\
    // reachability \u95A2\u4FC2\u306B\u3059\u3079\u3066\u8FBA\u3092\u5F35\u308B\n\
    vc<Bit_Array> transitive_closure(vc<Bit_Array> G) {\n  int N = len(G);\n  FOR(i,\
    \ N) G[i][i] = 0;\n\n  FOR(k, N) {\n    // G[i][k] and G[k][j]\n    FOR(i, N)\
    \ {\n      if (!G[i][k]) continue;\n      G[i] |= G[k];\n    }\n  }\n  return\
    \ G;\n}\n"
  code: "// Source: https://github.com/maspypy/library/blob/main/graph/bitset/transitive_closure.hpp\n\
    #include \"ds/bit_array.hpp\"\n#include \"graph/strongly_connected_component.hpp\"\
    \n\n// https://codeforces.com/contest/641/problem/F\n// https://atcoder.jp/contests/pakencamp-2023-day2/tasks/pakencamp_2023_day2_e\n\
    // reachability \u95A2\u4FC2\u306B\u3059\u3079\u3066\u8FBA\u3092\u5F35\u308B\n\
    vc<Bit_Array> transitive_closure(vc<Bit_Array> G) {\n  int N = len(G);\n  FOR(i,\
    \ N) G[i][i] = 0;\n\n  FOR(k, N) {\n    // G[i][k] and G[k][j]\n    FOR(i, N)\
    \ {\n      if (!G[i][k]) continue;\n      G[i] |= G[k];\n    }\n  }\n  return\
    \ G;\n}\n"
  dependsOn:
  - ds/bit_array.hpp
  - graph/strongly_connected_component.hpp
  - graph/base.hpp
  - ds/hashmap.hpp
  isVerificationFile: false
  path: graph/bitset/transitive_closure.hpp
  requiredBy:
  - graph/bitset/transitive_reduction.hpp
  timestamp: '2026-11-24 17:55:07+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: graph/bitset/transitive_closure.hpp
layout: document
redirect_from:
- /library/graph/bitset/transitive_closure.hpp
- /library/graph/bitset/transitive_closure.hpp.html
title: graph/bitset/transitive_closure.hpp
---
