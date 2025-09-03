---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: alg/monoid/min.hpp
    title: alg/monoid/min.hpp
  - icon: ':question:'
    path: ds/hashmap.hpp
    title: ds/hashmap.hpp
  - icon: ':question:'
    path: ds/segtree/segtree.hpp
    title: ds/segtree/segtree.hpp
  - icon: ':x:'
    path: ds/sparse_table/sparse_table.hpp
    title: ds/sparse_table/sparse_table.hpp
  - icon: ':x:'
    path: mod/modint61.hpp
    title: mod/modint61.hpp
  - icon: ':question:'
    path: random/base.hpp
    title: random/base.hpp
  - icon: ':x:'
    path: seq/cartesian_tree.hpp
    title: seq/cartesian_tree.hpp
  - icon: ':x:'
    path: string/rollinghash.hpp
    title: string/rollinghash.hpp
  - icon: ':x:'
    path: string/suffix_array.hpp
    title: string/suffix_array.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links:
    - https://arxiv.org/pdf/2312.11873
    - https://uoj.ac/problem/697
  bundledCode: "#line 2 \"string/basic_substring_structure.hpp\"\n\n#line 2 \"ds/hashmap.hpp\"\
    \n\r\n// u64 -> Val\r\ntemplate <typename Val>\r\nstruct HashMap {\r\n  // n \u306F\
    \u5165\u308C\u305F\u3044\u3082\u306E\u306E\u500B\u6570\u3067 ok\r\n  HashMap(u32\
    \ n = 0) { build(n); }\r\n  void build(u32 n) {\r\n    u32 k = 8;\r\n    while\
    \ (k < n * 2) k *= 2;\r\n    cap = k / 2, mask = k - 1;\r\n    key.resize(k),\
    \ val.resize(k), used.assign(k, 0);\r\n  }\r\n\r\n  // size \u3092\u4FDD\u3063\
    \u305F\u307E\u307E. size=0 \u306B\u3059\u308B\u3068\u304D\u306F build \u3059\u308B\
    \u3053\u3068.\r\n  void clear() {\r\n    used.assign(len(used), 0);\r\n    cap\
    \ = (mask + 1) / 2;\r\n  }\r\n  int size() { return len(used) / 2 - cap; }\r\n\
    \r\n  int index(const u64& k) {\r\n    int i = 0;\r\n    for (i = hash(k); used[i]\
    \ && key[i] != k; i = (i + 1) & mask) {}\r\n    return i;\r\n  }\r\n\r\n  Val&\
    \ operator[](const u64& k) {\r\n    if (cap == 0) extend();\r\n    int i = index(k);\r\
    \n    if (!used[i]) { used[i] = 1, key[i] = k, val[i] = Val{}, --cap; }\r\n  \
    \  return val[i];\r\n  }\r\n\r\n  Val get(const u64& k, Val default_value) {\r\
    \n    int i = index(k);\r\n    return (used[i] ? val[i] : default_value);\r\n\
    \  }\r\n\r\n  bool count(const u64& k) {\r\n    int i = index(k);\r\n    return\
    \ used[i] && key[i] == k;\r\n  }\r\n\r\n  // f(key, val)\r\n  template <typename\
    \ F>\r\n  void enumerate_all(F f) {\r\n    FOR(i, len(used)) if (used[i]) f(key[i],\
    \ val[i]);\r\n  }\r\n\r\nprivate:\r\n  u32 cap, mask;\r\n  vc<u64> key;\r\n  vc<Val>\
    \ val;\r\n  vc<bool> used;\r\n\r\n  u64 hash(u64 x) {\r\n    static const u64\
    \ FIXED_RANDOM = std::chrono::steady_clock::now().time_since_epoch().count();\r\
    \n    x += FIXED_RANDOM;\r\n    x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;\r\n\
    \    x = (x ^ (x >> 27)) * 0x94d049bb133111eb;\r\n    return (x ^ (x >> 31)) &\
    \ mask;\r\n  }\r\n\r\n  void extend() {\r\n    vc<pair<u64, Val>> dat;\r\n   \
    \ dat.reserve(len(used) / 2 - cap);\r\n    FOR(i, len(used)) {\r\n      if (used[i])\
    \ dat.eb(key[i], val[i]);\r\n    }\r\n    build(2 * len(dat));\r\n    for (auto&\
    \ [a, b]: dat) (*this)[a] = b;\r\n  }\r\n};\n#line 2 \"seq/cartesian_tree.hpp\"\
    \n/*\r\n\u8F9E\u66F8\u9806\u3067\u9AD8\u3055\u3092 unique \u3057\u3066\u3001\u6728\
    \u306B\u3057\u3066\u3044\u308B\u3002\r\n\u6975\u5927\u9577\u65B9\u5F62\u30A2\u30EB\
    \u30B4\u30EA\u30BA\u30E0\u3067\u7DDA\u5F62\u6642\u9593\u69CB\u7BC9\u3002\r\n*/\r\
    \ntemplate <typename T, bool IS_MIN>\r\nstruct CartesianTree {\r\n  int n;\r\n\
    \  vc<T>& A;\r\n  vc<pair<int, int>> range;\r\n  vc<int> lch, rch, par;\r\n  int\
    \ root;\r\n\r\n  CartesianTree(vc<T>& A) : n(len(A)), A(A) {\r\n    range.assign(n,\
    \ {-1, -1});\r\n    lch.assign(n, -1);\r\n    rch.assign(n, -1);\r\n    par.assign(n,\
    \ -1);\r\n    if (n == 1) {\r\n      range[0] = {0, 1};\r\n      root = 0;\r\n\
    \      return;\r\n    }\r\n    auto is_sm = [&](int i, int j) -> bool {\r\n  \
    \    if (IS_MIN) return (A[i] < A[j]) || (A[i] == A[j] && i < j);\r\n      return\
    \ (A[i] > A[j]) || (A[i] == A[j] && i < j);\r\n    };\r\n    vc<int> st;\r\n \
    \   FOR(i, n) {\r\n      while (!st.empty() && is_sm(i, st.back())) {\r\n    \
    \    lch[i] = st.back();\r\n        st.pop_back();\r\n      }\r\n      range[i].fi\
    \ = (st.empty() ? 0 : st.back() + 1);\r\n      st.eb(i);\r\n    }\r\n    st.clear();\r\
    \n    FOR_R(i, n) {\r\n      while (!st.empty() && is_sm(i, st.back())) {\r\n\
    \        rch[i] = st.back();\r\n        st.pop_back();\r\n      }\r\n      range[i].se\
    \ = (st.empty() ? n : st.back());\r\n      st.eb(i);\r\n    }\r\n    FOR(i, n)\
    \ if (lch[i] != -1) par[lch[i]] = i;\r\n    FOR(i, n) if (rch[i] != -1) par[rch[i]]\
    \ = i;\r\n    FOR(i, n) if (par[i] == -1) root = i;\r\n  }\r\n\r\n  // (l, r,\
    \ h)\r\n  tuple<int, int, T> maximum_rectangle(int i) {\r\n    auto [l, r] = range[i];\r\
    \n    return {l, r, A[i]};\r\n  }\r\n\r\n  // (l, r, h)\r\n  T max_rectangle_area()\
    \ {\r\n    assert(IS_MIN);\r\n    T res = 0;\r\n    FOR(i, n) {\r\n      auto\
    \ [l, r, h] = maximum_rectangle(i);\r\n      chmax(res, (r - l) * h);\r\n    }\r\
    \n    return res;\r\n  }\r\n\r\n  ll count_subrectangle(bool baseline) {\r\n \
    \   assert(IS_MIN);\r\n    ll res = 0;\r\n    FOR(i, n) {\r\n      auto [l, r,\
    \ h] = maximum_rectangle(i);\r\n      ll x = (baseline ? h : h * (h + 1) / 2);\r\
    \n      res += x * (i - l + 1) * (r - i);\r\n    }\r\n    return res;\r\n  }\r\
    \n};\r\n#line 2 \"random/base.hpp\"\n\nu64 RNG_64() {\n  static u64 x_ = u64(chrono::duration_cast<chrono::nanoseconds>(chrono::high_resolution_clock::now().time_since_epoch()).count())\
    \ * 10150724397891781847ULL;\n  x_ ^= x_ << 7;\n  return x_ ^= x_ >> 9;\n}\n\n\
    u64 RNG(u64 lim) { return RNG_64() % lim; }\n\nll RNG(ll l, ll r) { return l +\
    \ RNG_64() % (r - l); }\n#line 2 \"mod/modint61.hpp\"\n\r\nstruct modint61 {\r\
    \n  static constexpr u64 mod = (1ULL << 61) - 1;\r\n  u64 val;\r\n  constexpr\
    \ modint61() : val(0ULL) {}\r\n  constexpr modint61(u32 x) : val(x) {}\r\n  constexpr\
    \ modint61(u64 x) : val(x % mod) {}\r\n  constexpr modint61(int x) : val((x <\
    \ 0) ? (x + static_cast<ll>(mod)) : x) {}\r\n  constexpr modint61(ll x) : val(((x\
    \ %= static_cast<ll>(mod)) < 0) ? (x + static_cast<ll>(mod)) : x) {}\r\n  static\
    \ constexpr u64 get_mod() { return mod; }\r\n\r\n  modint61 &operator+=(const\
    \ modint61 &a) {\r\n    val = ((val += a.val) >= mod) ? (val - mod) : val;\r\n\
    \    return *this;\r\n  }\r\n  modint61 &operator-=(const modint61 &a) {\r\n \
    \   val = ((val -= a.val) >= mod) ? (val + mod) : val;\r\n    return *this;\r\n\
    \  }\r\n  modint61 &operator*=(const modint61 &a) {\r\n    const unsigned __int128\
    \ y = static_cast<unsigned __int128>(val) * a.val;\r\n    val = (y >> 61) + (y\
    \ & mod);\r\n    val = (val >= mod) ? (val - mod) : val;\r\n    return *this;\r\
    \n  }\r\n  modint61 operator-() const { return modint61(val ? mod - val : u64(0));\
    \ }\r\n  modint61 &operator/=(const modint61 &a) { return (*this *= a.inverse());\
    \ }\r\n  modint61 operator+(const modint61 &p) const { return modint61(*this)\
    \ += p; }\r\n  modint61 operator-(const modint61 &p) const { return modint61(*this)\
    \ -= p; }\r\n  modint61 operator*(const modint61 &p) const { return modint61(*this)\
    \ *= p; }\r\n  modint61 operator/(const modint61 &p) const { return modint61(*this)\
    \ /= p; }\r\n  bool operator<(const modint61 &other) const { return val < other.val;\
    \ }\r\n  bool operator==(const modint61 &p) const { return val == p.val; }\r\n\
    \  bool operator!=(const modint61 &p) const { return val != p.val; }\r\n  modint61\
    \ inverse() const {\r\n    ll a = val, b = mod, u = 1, v = 0, t;\r\n    while\
    \ (b > 0) {\r\n      t = a / b;\r\n      swap(a -= t * b, b), swap(u -= t * v,\
    \ v);\r\n    }\r\n    return modint61(u);\r\n  }\r\n  modint61 pow(ll n) const\
    \ {\r\n    assert(n >= 0);\r\n    modint61 ret(1), mul(val);\r\n    while (n >\
    \ 0) {\r\n      if (n & 1) ret *= mul;\r\n      mul *= mul, n >>= 1;\r\n    }\r\
    \n    return ret;\r\n  }\r\n};\r\n\r\n#ifdef FASTIO\r\nvoid rd(modint61 &x) {\r\
    \n  fastio::rd(x.val);\r\n  assert(0 <= x.val && x.val < modint61::mod);\r\n}\r\
    \n\r\nvoid wt(modint61 x) { fastio::wt(x.val); }\r\n#endif\n#line 4 \"string/rollinghash.hpp\"\
    \n\nstruct RollingHash {\n  using mint = modint61;\n  static constexpr u64 mod\
    \ = mint::get_mod();\n  const mint base;\n  vc<mint> power;\n\n  static inline\
    \ mint generate_base() { return RNG(mod); }\n\n  inline void expand(size_t sz)\
    \ {\n    if (power.size() < sz + 1) {\n      int pre_sz = (int)power.size();\n\
    \      power.resize(sz + 1);\n      FOR(i, pre_sz - 1, sz) power[i + 1] = power[i]\
    \ * base;\n    }\n  }\n\n  explicit RollingHash(mint base = generate_base()) :\
    \ base(base), power{1} {}\n\n  template <typename STRING>\n  vector<mint> build(const\
    \ STRING& s) const {\n    int sz = s.size();\n    vector<mint> hashed(sz + 1,\
    \ mint(0));\n    for (int i = 0; i < sz; i++) { hashed[i + 1] = hashed[i] * base\
    \ + s[i]; }\n    return hashed;\n  }\n\n  template <typename STRING>\n  mint eval(STRING&\
    \ s) {\n    mint x = 0;\n    for (auto& ch: s) x = base * x + ch;\n    return\
    \ x;\n  }\n\n  mint query(const vc<mint>& s, int l, int r) {\n    assert(0 <=\
    \ l && l <= r && r < len(s));\n    expand(r - l);\n    return (s[r] - s[l] * power[r\
    \ - l]);\n  }\n\n  mint combine(mint h1, mint h2, int h2len) {\n    expand(h2len);\n\
    \    return h1 * power[h2len] + h2;\n  }\n\n  mint add_char(mint h, int x) { return\
    \ h * base + mint(x); }\n\n  int lcp(const vc<mint>& a, int l1, int r1, const\
    \ vc<mint>& b, int l2,\n          int r2) {\n    int len = min(r1 - l1, r2 - l2);\n\
    \    int low = 0, high = len + 1;\n    while (high - low > 1) {\n      int mid\
    \ = (low + high) / 2;\n      if (query(a, l1, l1 + mid) == query(b, l2, l2 + mid))\n\
    \        low = mid;\n      else\n        high = mid;\n    }\n    return low;\n\
    \  }\n};\n#line 2 \"string/suffix_array.hpp\"\n\n#line 2 \"alg/monoid/min.hpp\"\
    \n\r\ntemplate <typename E>\r\nstruct Monoid_Min {\r\n  using X = E;\r\n  using\
    \ value_type = X;\r\n  static constexpr X op(const X &x, const X &y) noexcept\
    \ { return min(x, y); }\r\n  static constexpr X unit() { return infty<E>; }\r\n\
    \  static constexpr bool commute = true;\r\n};\r\n#line 2 \"ds/sparse_table/sparse_table.hpp\"\
    \n\n// \u51AA\u7B49\u306A\u30E2\u30CE\u30A4\u30C9\u3067\u3042\u308B\u3053\u3068\
    \u3092\u4EEE\u5B9A\u3002disjoint sparse table \u3088\u308A x \u500D\u9AD8\u901F\
    \ntemplate <class Monoid>\nstruct Sparse_Table {\n  using MX = Monoid;\n  using\
    \ X = typename MX::value_type;\n  int n, log;\n  vvc<X> dat;\n\n  Sparse_Table()\
    \ {}\n  Sparse_Table(int n) { build(n); }\n  template <typename F>\n  Sparse_Table(int\
    \ n, F f) {\n    build(n, f);\n  }\n  Sparse_Table(const vc<X>& v) { build(v);\
    \ }\n\n  void build(int m) {\n    build(m, [](int i) -> X { return MX::unit();\
    \ });\n  }\n  void build(const vc<X>& v) {\n    build(len(v), [&](int i) -> X\
    \ { return v[i]; });\n  }\n  template <typename F>\n  void build(int m, F f) {\n\
    \    n = m, log = 1;\n    while ((1 << log) < n) ++log;\n    dat.resize(log);\n\
    \    dat[0].resize(n);\n    FOR(i, n) dat[0][i] = f(i);\n\n    FOR(i, log - 1)\
    \ {\n      dat[i + 1].resize(len(dat[i]) - (1 << i));\n      FOR(j, len(dat[i])\
    \ - (1 << i)) {\n        dat[i + 1][j] = MX::op(dat[i][j], dat[i][j + (1 << i)]);\n\
    \      }\n    }\n  }\n\n  X prod(int L, int R) {\n    if (L == R) return MX::unit();\n\
    \    if (R == L + 1) return dat[0][L];\n    int k = topbit(R - L - 1);\n    return\
    \ MX::op(dat[k][L], dat[k][R - (1 << k)]);\n  }\n\n  template <class F>\n  int\
    \ max_right(const F check, int L) {\n    assert(0 <= L && L <= n && check(MX::unit()));\n\
    \    if (L == n) return n;\n    int ok = L, ng = n + 1;\n    while (ok + 1 < ng)\
    \ {\n      int k = (ok + ng) / 2;\n      bool bl = check(prod(L, k));\n      if\
    \ (bl) ok = k;\n      if (!bl) ng = k;\n    }\n    return ok;\n  }\n\n  template\
    \ <class F>\n  int min_left(const F check, int R) {\n    assert(0 <= R && R <=\
    \ n && check(MX::unit()));\n    if (R == 0) return 0;\n    int ok = R, ng = -1;\n\
    \    while (ng + 1 < ok) {\n      int k = (ok + ng) / 2;\n      bool bl = check(prod(k,\
    \ R));\n      if (bl) ok = k;\n      if (!bl) ng = k;\n    }\n    return ok;\n\
    \  }\n};\n#line 2 \"ds/segtree/segtree.hpp\"\n\ntemplate <class Monoid>\nstruct\
    \ SegTree {\n  using MX = Monoid;\n  using X = typename MX::value_type;\n  using\
    \ value_type = X;\n  vc<X> dat;\n  int n, log, size;\n\n  SegTree() {}\n  SegTree(int\
    \ n) { build(n); }\n  template <typename F>\n  SegTree(int n, F f) {\n    build(n,\
    \ f);\n  }\n  SegTree(const vc<X>& v) { build(v); }\n\n  void build(int m) {\n\
    \    build(m, [](int i) -> X { return MX::unit(); });\n  }\n  void build(const\
    \ vc<X>& v) {\n    build(len(v), [&](int i) -> X { return v[i]; });\n  }\n  template\
    \ <typename F>\n  void build(int m, F f) {\n    n = m, log = 1;\n    while ((1\
    \ << log) < n) ++log;\n    size = 1 << log;\n    dat.assign(size << 1, MX::unit());\n\
    \    FOR(i, n) dat[size + i] = f(i);\n    FOR_R(i, 1, size) update(i);\n  }\n\n\
    \  X get(int i) { return dat[size + i]; }\n  vc<X> get_all() { return {dat.begin()\
    \ + size, dat.begin() + size + n}; }\n\n  void update(int i) { dat[i] = Monoid::op(dat[2\
    \ * i], dat[2 * i + 1]); }\n  void set(int i, const X& x) {\n    assert(i < n);\n\
    \    dat[i += size] = x;\n    while (i >>= 1) update(i);\n  }\n\n  void multiply(int\
    \ i, const X& x) {\n    assert(i < n);\n    i += size;\n    dat[i] = Monoid::op(dat[i],\
    \ x);\n    while (i >>= 1) update(i);\n  }\n\n  X prod(int L, int R) {\n    assert(0\
    \ <= L && L <= R && R <= n);\n    X vl = Monoid::unit(), vr = Monoid::unit();\n\
    \    L += size, R += size;\n    while (L < R) {\n      if (L & 1) vl = Monoid::op(vl,\
    \ dat[L++]);\n      if (R & 1) vr = Monoid::op(dat[--R], vr);\n      L >>= 1,\
    \ R >>= 1;\n    }\n    return Monoid::op(vl, vr);\n  }\n\n  X prod_all() { return\
    \ dat[1]; }\n\n  template <class F>\n  int max_right(F check, int L) {\n    assert(0\
    \ <= L && L <= n && check(Monoid::unit()));\n    if (L == n) return n;\n    L\
    \ += size;\n    X sm = Monoid::unit();\n    do {\n      while (L % 2 == 0) L >>=\
    \ 1;\n      if (!check(Monoid::op(sm, dat[L]))) {\n        while (L < size) {\n\
    \          L = 2 * L;\n          if (check(Monoid::op(sm, dat[L]))) { sm = Monoid::op(sm,\
    \ dat[L++]); }\n        }\n        return L - size;\n      }\n      sm = Monoid::op(sm,\
    \ dat[L++]);\n    } while ((L & -L) != L);\n    return n;\n  }\n\n  template <class\
    \ F>\n  int min_left(F check, int R) {\n    assert(0 <= R && R <= n && check(Monoid::unit()));\n\
    \    if (R == 0) return 0;\n    R += size;\n    X sm = Monoid::unit();\n    do\
    \ {\n      --R;\n      while (R > 1 && (R % 2)) R >>= 1;\n      if (!check(Monoid::op(dat[R],\
    \ sm))) {\n        while (R < size) {\n          R = 2 * R + 1;\n          if\
    \ (check(Monoid::op(dat[R], sm))) { sm = Monoid::op(dat[R--], sm); }\n       \
    \ }\n        return R + 1 - size;\n      }\n      sm = Monoid::op(dat[R], sm);\n\
    \    } while ((R & -R) != R);\n    return 0;\n  }\n\n  // prod_{l<=i<r} A[i xor\
    \ x]\n  X xor_prod(int l, int r, int xor_val) {\n    static_assert(Monoid::commute);\n\
    \    X x = Monoid::unit();\n    for (int k = 0; k < log + 1; ++k) {\n      if\
    \ (l >= r) break;\n      if (l & 1) { x = Monoid::op(x, dat[(size >> k) + ((l++)\
    \ ^ xor_val)]); }\n      if (r & 1) { x = Monoid::op(x, dat[(size >> k) + ((--r)\
    \ ^ xor_val)]); }\n      l /= 2, r /= 2, xor_val /= 2;\n    }\n    return x;\n\
    \  }\n};\n#line 6 \"string/suffix_array.hpp\"\n\n// \u8F9E\u66F8\u9806 i \u756A\
    \u76EE\u306E suffix \u304C j \u6587\u5B57\u76EE\u59CB\u307E\u308A\u3067\u3042\u308B\
    \u3068\u304D\u3001\n// SA[i] = j, ISA[j] = i\n// |S|>0 \u3092\u524D\u63D0\uFF08\
    \u305D\u3046\u3067\u306A\u3044\u5834\u5408 dummy \u6587\u5B57\u3092\u8FFD\u52A0\
    \u3057\u3066\u5229\u7528\u305B\u3088\uFF09\ntemplate <bool USE_SPARSE_TABLE =\
    \ true>\nstruct Suffix_Array {\n  vc<int> SA;\n  vc<int> ISA;\n  vc<int> LCP;\n\
    \  using Mono = Monoid_Min<int>;\n  using SegType = conditional_t<USE_SPARSE_TABLE,\
    \ Sparse_Table<Mono>, SegTree<Mono> >;\n  SegType seg;\n  bool build_seg;\n\n\
    \  Suffix_Array() {}\n  Suffix_Array(string& s) {\n    build_seg = 0;\n    assert(len(s)\
    \ > 0);\n    char first = 127, last = 0;\n    for (auto&& c: s) {\n      chmin(first,\
    \ c);\n      chmax(last, c);\n    }\n    SA = calc_suffix_array(s, first, last);\n\
    \    calc_LCP(s);\n  }\n\n  Suffix_Array(vc<int> s) {\n    build_seg = 0;\n  \
    \  assert(len(s) > 0);\n    SA = calc_suffix_array(s);\n    calc_LCP(s);\n  }\n\
    \n  // lcp(S[i:], S[j:])\n  int lcp(int i, int j) {\n    if (!build_seg) {\n \
    \     build_seg = true;\n      seg.build(LCP);\n    }\n    int n = len(SA);\n\
    \    if (i == n || j == n) return 0;\n    if (i == j) return n - i;\n    i = ISA[i],\
    \ j = ISA[j];\n    if (i > j) swap(i, j);\n    return seg.prod(i, j);\n  }\n\n\
    \  // S[i:] \u3068\u306E lcp \u304C n \u4EE5\u4E0A\u3067\u3042\u308B\u3088\u3046\
    \u306A\u534A\u958B\u533A\u9593\n  pair<int, int> lcp_range(int i, int n) {\n \
    \   if (!build_seg) {\n      build_seg = true;\n      seg.build(LCP);\n    }\n\
    \    i = ISA[i];\n    int a = seg.min_left([&](auto e) -> bool { return e >= n;\
    \ }, i);\n    int b = seg.max_right([&](auto e) -> bool { return e >= n; }, i);\n\
    \    return {a, b + 1};\n  }\n\n  // -1: S[L1:R1) < S[L2, R2)\n  //  0: S[L1:R1)\
    \ = S[L2, R2)\n  // +1: S[L1:R1) > S[L2, R2)\n  int compare(int L1, int R1, int\
    \ L2, int R2) {\n    int n1 = R1 - L1, n2 = R2 - L2;\n    int n = lcp(L1, L2);\n\
    \    if (n == n1 && n == n2) return 0;\n    if (n == n1) return -1;\n    if (n\
    \ == n2) return 1;\n    return (ISA[L1 + n] > ISA[L2 + n] ? 1 : -1);\n  }\n\n\
    private:\n  void induced_sort(const vc<int>& vect, int val_range, vc<int>& SA,\
    \ const vc<bool>& sl, const vc<int>& lms_idx) {\n    vc<int> l(val_range, 0),\
    \ r(val_range, 0);\n    for (int c: vect) {\n      if (c + 1 < val_range) ++l[c\
    \ + 1];\n      ++r[c];\n    }\n    partial_sum(l.begin(), l.end(), l.begin());\n\
    \    partial_sum(r.begin(), r.end(), r.begin());\n    fill(SA.begin(), SA.end(),\
    \ -1);\n    for (int i = (int)lms_idx.size() - 1; i >= 0; --i) SA[--r[vect[lms_idx[i]]]]\
    \ = lms_idx[i];\n    for (int i: SA)\n      if (i >= 1 && sl[i - 1]) SA[l[vect[i\
    \ - 1]]++] = i - 1;\n    fill(r.begin(), r.end(), 0);\n    for (int c: vect) ++r[c];\n\
    \    partial_sum(r.begin(), r.end(), r.begin());\n    for (int k = (int)SA.size()\
    \ - 1, i = SA[k]; k >= 1; --k, i = SA[k])\n      if (i >= 1 && !sl[i - 1]) { SA[--r[vect[i\
    \ - 1]]] = i - 1; }\n  }\n\n  vc<int> SA_IS(const vc<int>& vect, int val_range)\
    \ {\n    const int n = vect.size();\n    vc<int> SA(n), lms_idx;\n    vc<bool>\
    \ sl(n);\n    sl[n - 1] = false;\n    for (int i = n - 2; i >= 0; --i) {\n   \
    \   sl[i] = (vect[i] > vect[i + 1] || (vect[i] == vect[i + 1] && sl[i + 1]));\n\
    \      if (sl[i] && !sl[i + 1]) lms_idx.push_back(i + 1);\n    }\n    reverse(lms_idx.begin(),\
    \ lms_idx.end());\n    induced_sort(vect, val_range, SA, sl, lms_idx);\n    vc<int>\
    \ new_lms_idx(lms_idx.size()), lms_vec(lms_idx.size());\n    for (int i = 0, k\
    \ = 0; i < n; ++i)\n      if (!sl[SA[i]] && SA[i] >= 1 && sl[SA[i] - 1]) { new_lms_idx[k++]\
    \ = SA[i]; }\n    int cur = 0;\n    SA[n - 1] = cur;\n    for (size_t k = 1; k\
    \ < new_lms_idx.size(); ++k) {\n      int i = new_lms_idx[k - 1], j = new_lms_idx[k];\n\
    \      if (vect[i] != vect[j]) {\n        SA[j] = ++cur;\n        continue;\n\
    \      }\n      bool flag = false;\n      for (int a = i + 1, b = j + 1;; ++a,\
    \ ++b) {\n        if (vect[a] != vect[b]) {\n          flag = true;\n        \
    \  break;\n        }\n        if ((!sl[a] && sl[a - 1]) || (!sl[b] && sl[b - 1]))\
    \ {\n          flag = !((!sl[a] && sl[a - 1]) && (!sl[b] && sl[b - 1]));\n   \
    \       break;\n        }\n      }\n      SA[j] = (flag ? ++cur : cur);\n    }\n\
    \    for (size_t i = 0; i < lms_idx.size(); ++i) lms_vec[i] = SA[lms_idx[i]];\n\
    \    if (cur + 1 < (int)lms_idx.size()) {\n      auto lms_SA = SA_IS(lms_vec,\
    \ cur + 1);\n      for (size_t i = 0; i < lms_idx.size(); ++i) { new_lms_idx[i]\
    \ = lms_idx[lms_SA[i]]; }\n    }\n    induced_sort(vect, val_range, SA, sl, new_lms_idx);\n\
    \    return SA;\n  }\n\n  vc<int> calc_suffix_array(const string& s, const char\
    \ first = 'a', const char last = 'z') {\n    vc<int> vect(s.size() + 1);\n   \
    \ copy(begin(s), end(s), begin(vect));\n    for (auto& x: vect) x -= (int)first\
    \ - 1;\n    vect.back() = 0;\n    auto ret = SA_IS(vect, (int)last - (int)first\
    \ + 2);\n    ret.erase(ret.begin());\n    return ret;\n  }\n\n  vc<int> calc_suffix_array(const\
    \ vc<int>& s) {\n    vc<int> ss = s;\n    UNIQUE(ss);\n\n    vc<int> vect(s.size()\
    \ + 1);\n    copy(all(s), vect.begin());\n    for (auto& x: vect) x = LB(ss, x)\
    \ + 1;\n    vect.back() = 0;\n    auto ret = SA_IS(vect, MAX(vect) + 2);\n   \
    \ ret.erase(ret.begin());\n    return ret;\n  }\n\n  template <typename STRING>\n\
    \  void calc_LCP(const STRING& s) {\n    int n = s.size(), k = 0;\n    ISA.resize(n);\n\
    \    LCP.resize(n);\n    for (int i = 0; i < n; i++) ISA[SA[i]] = i;\n    for\
    \ (int i = 0; i < n; i++, k ? k-- : 0) {\n      if (ISA[i] == n - 1) {\n     \
    \   k = 0;\n        continue;\n      }\n      int j = SA[ISA[i] + 1];\n      while\
    \ (i + k < n && j + k < n && s[i + k] == s[j + k]) k++;\n      LCP[ISA[i]] = k;\n\
    \    }\n    LCP.resize(n - 1);\n  }\n};\n#line 7 \"string/basic_substring_structure.hpp\"\
    \n\n// https://arxiv.org/pdf/2312.11873\n// https://uoj.ac/problem/697\nstruct\
    \ Basic_Substring_Structure {\n  using SA_t = Suffix_Array<false>;\n  int N;\n\
    \  string S, T; // T = rev(S)\n  RollingHash RH;\n  vc<decltype(RH)::mint> SH;\n\
    \  SA_t S_SA, T_SA;\n  HashMap<int> hash_to_col;\n\n  /*\n  block \u3092 diagonal\
    \ \u306B\u914D\u7F6E\u3057\u305F\u9577\u65B9\u5F62\u3092\u4F5C\u308B\u611F\u3058\
    \u306B\u3059\u308B.\n  X, Y: i \u756A\u76EE\u306E block \u304C [X[i],X[i+1]) x\
    \ [Y[i],Y[i+1]) \u306B\u306A\u308B.\n  X_to_block, Y_to_block: \u884C\u756A\u53F7\
    \u3084\u5217\u756A\u53F7\u306B\u5BFE\u5FDC\u3059\u308B block.\n  width, height:\
    \ \u884C\u306E\u5E45, \u5217\u306E\u9AD8\u3055. [X[i],X[i]+width[i]) \u306A\u3069\
    .\n  right: \u884C\u304D\u5148\u306E\u884C\n  down: \u884C\u304D\u5148\u306E\u5217\
    \n  */\n\n  // topological \u9006\u9806 (\u6700\u5F8C\u306B S[0,N) \u304C\u6765\
    \u308B)\n  vc<pair<int, int>> raw_index; // \u5404 block \u306E\u4EE3\u8868\u5143\
    \u306B\u5BFE\u5FDC\u3059\u308B [i,j]\n  vc<int> X, Y;\n  vc<int> X_to_block, Y_to_block;\n\
    \  vc<int> width, height;\n  vc<int> right, down;\n\n  int n_block() { return\
    \ len(raw_index); }\n  pair<int, int> shape() { return {X.back(), Y.back()}; }\n\
    \n  Basic_Substring_Structure(string &S) { build(S); }\n\n  void build(string\
    \ &S_) {\n    S = S_, T = {S_.rbegin(), S_.rend()};\n    SH = RH.build(S);\n \
    \   S_SA = SA_t(S), T_SA = SA_t(T);\n    S_SA.seg.build(S_SA.LCP), S_SA.build_seg\
    \ = true;\n    T_SA.seg.build(T_SA.LCP), T_SA.build_seg = true;\n    N = len(S);\n\
    \    if (N == 1) {\n      raw_index = {{0, 0}}, X = {0, 1}, Y = {0, 1}, X_to_block\
    \ = {0},\n      Y_to_block = {0};\n      width = {1}, height = {1}, right = {-1},\
    \ down = {-1};\n      return;\n    }\n    X_to_block.reserve(2 * N - 1), Y_to_block.reserve(2\
    \ * N - 1);\n    width.reserve(2 * N - 1), height.reserve(2 * N - 1);\n    right.reserve(2\
    \ * N - 1), down.reserve(2 * N - 1);\n    X = {0}, Y = {0};\n\n    CartesianTree<int,\
    \ true> CS(S_SA.LCP);\n    CartesianTree<int, true> CT(T_SA.LCP);\n    hash_to_col.build(N\
    \ - 1);\n    HashMap<int> hash_to_row(N - 1);\n\n    auto is_node = [&](CartesianTree<int,\
    \ true> &CT, int i) -> bool {\n      return (CT.A[i] > 0 && (CT.par[i] == -1 ||\
    \ CT.A[CT.par[i]] != CT.A[i]));\n    };\n\n    // \u5217\u306E\u5148\u982D\u306B\
    \u76F8\u5F53\u3059\u308B\u30CF\u30C3\u30B7\u30E5\u3092\u96C6\u3081\u3066\u304A\
    \u304F\n    HashMap<int> tmp(N - 1);\n    FOR(i, N - 1) {\n      if (!is_node(CS,\
    \ i))\n        continue;\n      int s = S_SA.SA[i], n = S_SA.LCP[i];\n      tmp[RH.query(SH,\
    \ s, s + n).val] = i;\n    }\n\n    // occur \u304C\u5C0F\u3055\u3044\u884C\u304B\
    \u3089\u4F5C\u3063\u3066\u3044\u304F\n    vc<int> ptr(N);\n    FOR(i, N - 1) {\n\
    \      if (is_node(CT, i))\n        ptr[CT.range[i].se - CT.range[i].fi]++;\n\
    \    }\n    ptr = cumsum<int>(ptr);\n    vc<int> I(ptr.back(), -1);\n    FOR(i,\
    \ N - 1) {\n      if (!is_node(CT, i))\n        continue;\n      int occ = CT.range[i].se\
    \ - CT.range[i].fi;\n      I[ptr[occ]++] = i;\n    }\n\n    auto new_block = [&](int\
    \ h, int w, int i, int j) -> int {\n      int bid = len(raw_index);\n      raw_index.eb(i,\
    \ j);\n      X.eb(X.back() + h), Y.eb(Y.back() + w);\n      FOR(h) X_to_block.eb(bid),\
    \ width.eb(-1), right.eb(-1);\n      FOR(w) Y_to_block.eb(bid), height.eb(-1),\
    \ down.eb(-1);\n      return bid;\n    };\n\n    auto get_w = [&](int i) -> int\
    \ {\n      return CT.A[i] - (CT.par[i] == -1 ? 0 : CT.A[CT.par[i]]);\n    };\n\
    \    auto get_h = [&](int i) -> int {\n      return CS.A[i] - (CS.par[i] == -1\
    \ ? 0 : CS.A[CS.par[i]]);\n    };\n\n    reverse(all(I));\n    for (int a0 : I)\
    \ {\n      int j = N - T_SA.SA[a0], n = T_SA.LCP[a0];\n      u64 key = RH.query(SH,\
    \ j - n, j).val;\n      int b0 = tmp.get(key, -1);\n      if (b0 == -1)\n    \
    \    continue;\n      // occur>=2 \u306B\u5BFE\u5FDC\u3059\u308B block \u767A\u898B\
    \n      int h = get_h(b0), w = get_w(a0);\n      int bid = new_block(h, w, j -\
    \ n, j);\n      FOR(x, X[bid], X[bid + 1]) {\n        hash_to_row[RH.query(SH,\
    \ j - n, j - (x - X[bid])).val] = x;\n      }\n      FOR(y, Y[bid], Y[bid + 1])\
    \ {\n        hash_to_col[RH.query(SH, j - n + (y - Y[bid]), j).val] = y;\n   \
    \   }\n    }\n    FOR(i, N - 1) {\n      if (!is_node(CT, i))\n        continue;\n\
    \      int r = N - T_SA.SA[i], n = T_SA.LCP[i];\n      u64 key = RH.query(SH,\
    \ r - n, r).val;\n      int x = hash_to_row[key];\n      width[x] = get_w(i);\n\
    \      right[x] = hash_to_row.get(RH.query(SH, r - n + width[x], r).val, -1);\n\
    \    }\n    FOR(i, N - 1) {\n      if (!is_node(CS, i))\n        continue;\n \
    \     int l = S_SA.SA[i], n = S_SA.LCP[i];\n      u64 key = RH.query(SH, l, l\
    \ + n).val;\n      int y = hash_to_col[key];\n      height[y] = get_h(i);\n  \
    \    down[y] = hash_to_col.get(RH.query(SH, l, l + n - height[y]).val, -1);\n\
    \    }\n\n    // occur==1\n    auto get_w2 = [&](int i) -> int { // [0,i)\n  \
    \    int k = T_SA.ISA[N - i];\n      int n = i, m = 0;\n      if (k > 0)\n   \
    \     chmax(m, T_SA.LCP[k - 1]);\n      if (k < N - 1)\n        chmax(m, T_SA.LCP[k]);\n\
    \      return n - m;\n    };\n    auto get_h2 = [&](int i) -> int { // [i,N)\n\
    \      int k = S_SA.ISA[i];\n      int n = N - i, m = 0;\n      if (k > 0)\n \
    \       chmax(m, S_SA.LCP[k - 1]);\n      if (k < N - 1)\n        chmax(m, S_SA.LCP[k]);\n\
    \      return n - m;\n    };\n    int h = get_h2(0), w = get_w2(N);\n    int bid\
    \ = new_block(h, w, 0, N);\n    FOR(x, X[bid], X[bid + 1]) {\n      int r = N\
    \ - (x - X[bid]);\n      width[x] = get_w2(r);\n      right[x] = hash_to_row.get(RH.query(SH,\
    \ width[x], r).val, -1);\n    }\n    FOR(y, Y[bid], Y[bid + 1]) {\n      int l\
    \ = y - Y[bid];\n      height[y] = get_h2(l);\n      down[y] = hash_to_col.get(RH.query(SH,\
    \ l, N - height[y]).val, -1);\n    }\n  }\n\n  // S[i,j) \u306B\u5BFE\u5FDC\u3059\
    \u308B (x,y).\n  pair<int, int> get_position(int i, int j) {\n    // occur \u3092\
    \u4FDD\u3063\u3066\u9577\u304F\u3059\u308B\n    auto &seg = S_SA.seg;\n    int\
    \ n = j - i, k = S_SA.ISA[i];\n    int m = N - i;\n    auto check = [&](int e)\
    \ -> bool {\n      if (e >= n)\n        chmin(m, e);\n      return e >= n;\n \
    \   };\n    seg.min_left(check, k), seg.max_right(check, k);\n    int y = hash_to_col.get(RH.query(SH,\
    \ i, i + m).val, -1);\n    if (y == -1) {\n      assert(i + m == N);\n      int\
    \ x = X[n_block() - 1] + (N - j), y = Y[n_block() - 1] + i;\n      return {x,\
    \ y};\n    }\n    int bid = Y_to_block[y];\n    auto [l, r] = raw_index[bid];\n\
    \    int x = (X[bid] + Y[bid]) + ((r - l) - (j - i)) - y;\n    return {x, y};\n\
    \  }\n\n  void debug() {\n    auto [H, W] = shape();\n    FOR(x, H) {\n      string\
    \ tmp(W, '.');\n      int k = X_to_block[x];\n      FOR(y, Y[k], Y[k] + width[x])\
    \ tmp[y] = '#';\n      print(tmp);\n    }\n    SHOW(S);\n    SHOW(raw_index);\n\
    \    SHOW(width);\n    SHOW(height);\n    SHOW(right);\n    SHOW(down);\n    print();\n\
    \  }\n};\n"
  code: "#pragma once\n\n#include \"ds/hashmap.hpp\"\n#include \"seq/cartesian_tree.hpp\"\
    \n#include \"string/rollinghash.hpp\"\n#include \"string/suffix_array.hpp\"\n\n\
    // https://arxiv.org/pdf/2312.11873\n// https://uoj.ac/problem/697\nstruct Basic_Substring_Structure\
    \ {\n  using SA_t = Suffix_Array<false>;\n  int N;\n  string S, T; // T = rev(S)\n\
    \  RollingHash RH;\n  vc<decltype(RH)::mint> SH;\n  SA_t S_SA, T_SA;\n  HashMap<int>\
    \ hash_to_col;\n\n  /*\n  block \u3092 diagonal \u306B\u914D\u7F6E\u3057\u305F\
    \u9577\u65B9\u5F62\u3092\u4F5C\u308B\u611F\u3058\u306B\u3059\u308B.\n  X, Y: i\
    \ \u756A\u76EE\u306E block \u304C [X[i],X[i+1]) x [Y[i],Y[i+1]) \u306B\u306A\u308B\
    .\n  X_to_block, Y_to_block: \u884C\u756A\u53F7\u3084\u5217\u756A\u53F7\u306B\u5BFE\
    \u5FDC\u3059\u308B block.\n  width, height: \u884C\u306E\u5E45, \u5217\u306E\u9AD8\
    \u3055. [X[i],X[i]+width[i]) \u306A\u3069.\n  right: \u884C\u304D\u5148\u306E\u884C\
    \n  down: \u884C\u304D\u5148\u306E\u5217\n  */\n\n  // topological \u9006\u9806\
    \ (\u6700\u5F8C\u306B S[0,N) \u304C\u6765\u308B)\n  vc<pair<int, int>> raw_index;\
    \ // \u5404 block \u306E\u4EE3\u8868\u5143\u306B\u5BFE\u5FDC\u3059\u308B [i,j]\n\
    \  vc<int> X, Y;\n  vc<int> X_to_block, Y_to_block;\n  vc<int> width, height;\n\
    \  vc<int> right, down;\n\n  int n_block() { return len(raw_index); }\n  pair<int,\
    \ int> shape() { return {X.back(), Y.back()}; }\n\n  Basic_Substring_Structure(string\
    \ &S) { build(S); }\n\n  void build(string &S_) {\n    S = S_, T = {S_.rbegin(),\
    \ S_.rend()};\n    SH = RH.build(S);\n    S_SA = SA_t(S), T_SA = SA_t(T);\n  \
    \  S_SA.seg.build(S_SA.LCP), S_SA.build_seg = true;\n    T_SA.seg.build(T_SA.LCP),\
    \ T_SA.build_seg = true;\n    N = len(S);\n    if (N == 1) {\n      raw_index\
    \ = {{0, 0}}, X = {0, 1}, Y = {0, 1}, X_to_block = {0},\n      Y_to_block = {0};\n\
    \      width = {1}, height = {1}, right = {-1}, down = {-1};\n      return;\n\
    \    }\n    X_to_block.reserve(2 * N - 1), Y_to_block.reserve(2 * N - 1);\n  \
    \  width.reserve(2 * N - 1), height.reserve(2 * N - 1);\n    right.reserve(2 *\
    \ N - 1), down.reserve(2 * N - 1);\n    X = {0}, Y = {0};\n\n    CartesianTree<int,\
    \ true> CS(S_SA.LCP);\n    CartesianTree<int, true> CT(T_SA.LCP);\n    hash_to_col.build(N\
    \ - 1);\n    HashMap<int> hash_to_row(N - 1);\n\n    auto is_node = [&](CartesianTree<int,\
    \ true> &CT, int i) -> bool {\n      return (CT.A[i] > 0 && (CT.par[i] == -1 ||\
    \ CT.A[CT.par[i]] != CT.A[i]));\n    };\n\n    // \u5217\u306E\u5148\u982D\u306B\
    \u76F8\u5F53\u3059\u308B\u30CF\u30C3\u30B7\u30E5\u3092\u96C6\u3081\u3066\u304A\
    \u304F\n    HashMap<int> tmp(N - 1);\n    FOR(i, N - 1) {\n      if (!is_node(CS,\
    \ i))\n        continue;\n      int s = S_SA.SA[i], n = S_SA.LCP[i];\n      tmp[RH.query(SH,\
    \ s, s + n).val] = i;\n    }\n\n    // occur \u304C\u5C0F\u3055\u3044\u884C\u304B\
    \u3089\u4F5C\u3063\u3066\u3044\u304F\n    vc<int> ptr(N);\n    FOR(i, N - 1) {\n\
    \      if (is_node(CT, i))\n        ptr[CT.range[i].se - CT.range[i].fi]++;\n\
    \    }\n    ptr = cumsum<int>(ptr);\n    vc<int> I(ptr.back(), -1);\n    FOR(i,\
    \ N - 1) {\n      if (!is_node(CT, i))\n        continue;\n      int occ = CT.range[i].se\
    \ - CT.range[i].fi;\n      I[ptr[occ]++] = i;\n    }\n\n    auto new_block = [&](int\
    \ h, int w, int i, int j) -> int {\n      int bid = len(raw_index);\n      raw_index.eb(i,\
    \ j);\n      X.eb(X.back() + h), Y.eb(Y.back() + w);\n      FOR(h) X_to_block.eb(bid),\
    \ width.eb(-1), right.eb(-1);\n      FOR(w) Y_to_block.eb(bid), height.eb(-1),\
    \ down.eb(-1);\n      return bid;\n    };\n\n    auto get_w = [&](int i) -> int\
    \ {\n      return CT.A[i] - (CT.par[i] == -1 ? 0 : CT.A[CT.par[i]]);\n    };\n\
    \    auto get_h = [&](int i) -> int {\n      return CS.A[i] - (CS.par[i] == -1\
    \ ? 0 : CS.A[CS.par[i]]);\n    };\n\n    reverse(all(I));\n    for (int a0 : I)\
    \ {\n      int j = N - T_SA.SA[a0], n = T_SA.LCP[a0];\n      u64 key = RH.query(SH,\
    \ j - n, j).val;\n      int b0 = tmp.get(key, -1);\n      if (b0 == -1)\n    \
    \    continue;\n      // occur>=2 \u306B\u5BFE\u5FDC\u3059\u308B block \u767A\u898B\
    \n      int h = get_h(b0), w = get_w(a0);\n      int bid = new_block(h, w, j -\
    \ n, j);\n      FOR(x, X[bid], X[bid + 1]) {\n        hash_to_row[RH.query(SH,\
    \ j - n, j - (x - X[bid])).val] = x;\n      }\n      FOR(y, Y[bid], Y[bid + 1])\
    \ {\n        hash_to_col[RH.query(SH, j - n + (y - Y[bid]), j).val] = y;\n   \
    \   }\n    }\n    FOR(i, N - 1) {\n      if (!is_node(CT, i))\n        continue;\n\
    \      int r = N - T_SA.SA[i], n = T_SA.LCP[i];\n      u64 key = RH.query(SH,\
    \ r - n, r).val;\n      int x = hash_to_row[key];\n      width[x] = get_w(i);\n\
    \      right[x] = hash_to_row.get(RH.query(SH, r - n + width[x], r).val, -1);\n\
    \    }\n    FOR(i, N - 1) {\n      if (!is_node(CS, i))\n        continue;\n \
    \     int l = S_SA.SA[i], n = S_SA.LCP[i];\n      u64 key = RH.query(SH, l, l\
    \ + n).val;\n      int y = hash_to_col[key];\n      height[y] = get_h(i);\n  \
    \    down[y] = hash_to_col.get(RH.query(SH, l, l + n - height[y]).val, -1);\n\
    \    }\n\n    // occur==1\n    auto get_w2 = [&](int i) -> int { // [0,i)\n  \
    \    int k = T_SA.ISA[N - i];\n      int n = i, m = 0;\n      if (k > 0)\n   \
    \     chmax(m, T_SA.LCP[k - 1]);\n      if (k < N - 1)\n        chmax(m, T_SA.LCP[k]);\n\
    \      return n - m;\n    };\n    auto get_h2 = [&](int i) -> int { // [i,N)\n\
    \      int k = S_SA.ISA[i];\n      int n = N - i, m = 0;\n      if (k > 0)\n \
    \       chmax(m, S_SA.LCP[k - 1]);\n      if (k < N - 1)\n        chmax(m, S_SA.LCP[k]);\n\
    \      return n - m;\n    };\n    int h = get_h2(0), w = get_w2(N);\n    int bid\
    \ = new_block(h, w, 0, N);\n    FOR(x, X[bid], X[bid + 1]) {\n      int r = N\
    \ - (x - X[bid]);\n      width[x] = get_w2(r);\n      right[x] = hash_to_row.get(RH.query(SH,\
    \ width[x], r).val, -1);\n    }\n    FOR(y, Y[bid], Y[bid + 1]) {\n      int l\
    \ = y - Y[bid];\n      height[y] = get_h2(l);\n      down[y] = hash_to_col.get(RH.query(SH,\
    \ l, N - height[y]).val, -1);\n    }\n  }\n\n  // S[i,j) \u306B\u5BFE\u5FDC\u3059\
    \u308B (x,y).\n  pair<int, int> get_position(int i, int j) {\n    // occur \u3092\
    \u4FDD\u3063\u3066\u9577\u304F\u3059\u308B\n    auto &seg = S_SA.seg;\n    int\
    \ n = j - i, k = S_SA.ISA[i];\n    int m = N - i;\n    auto check = [&](int e)\
    \ -> bool {\n      if (e >= n)\n        chmin(m, e);\n      return e >= n;\n \
    \   };\n    seg.min_left(check, k), seg.max_right(check, k);\n    int y = hash_to_col.get(RH.query(SH,\
    \ i, i + m).val, -1);\n    if (y == -1) {\n      assert(i + m == N);\n      int\
    \ x = X[n_block() - 1] + (N - j), y = Y[n_block() - 1] + i;\n      return {x,\
    \ y};\n    }\n    int bid = Y_to_block[y];\n    auto [l, r] = raw_index[bid];\n\
    \    int x = (X[bid] + Y[bid]) + ((r - l) - (j - i)) - y;\n    return {x, y};\n\
    \  }\n\n  void debug() {\n    auto [H, W] = shape();\n    FOR(x, H) {\n      string\
    \ tmp(W, '.');\n      int k = X_to_block[x];\n      FOR(y, Y[k], Y[k] + width[x])\
    \ tmp[y] = '#';\n      print(tmp);\n    }\n    SHOW(S);\n    SHOW(raw_index);\n\
    \    SHOW(width);\n    SHOW(height);\n    SHOW(right);\n    SHOW(down);\n    print();\n\
    \  }\n};\n"
  dependsOn:
  - ds/hashmap.hpp
  - seq/cartesian_tree.hpp
  - string/rollinghash.hpp
  - random/base.hpp
  - mod/modint61.hpp
  - string/suffix_array.hpp
  - alg/monoid/min.hpp
  - ds/sparse_table/sparse_table.hpp
  - ds/segtree/segtree.hpp
  isVerificationFile: false
  path: string/basic_substring_structure.hpp
  requiredBy: []
  timestamp: '2025-06-24 13:26:12+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: string/basic_substring_structure.hpp
layout: document
redirect_from:
- /library/string/basic_substring_structure.hpp
- /library/string/basic_substring_structure.hpp.html
title: string/basic_substring_structure.hpp
---
