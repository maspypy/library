#line 1 "main.cpp"
#define PROBLEM "https://judge.yosupo.jp/problem/aplusb"
#line 1 "library/my_template.hpp"
#if defined(LOCAL)
#include <my_template_compiled.hpp>
#else
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")

#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using u32 = unsigned int;
using u64 = unsigned long long;
using i128 = __int128;
using u128 = unsigned __int128;
using f128 = __float128;

template <class T>
constexpr T infty = 0;
template <>
constexpr int infty<int> = 1'000'000'000;
template <>
constexpr ll infty<ll> = ll(infty<int>) * infty<int> * 2;
template <>
constexpr u32 infty<u32> = infty<int>;
template <>
constexpr u64 infty<u64> = infty<ll>;
template <>
constexpr i128 infty<i128> = i128(infty<ll>) * infty<ll>;
template <>
constexpr double infty<double> = infty<ll>;
template <>
constexpr long double infty<long double> = infty<ll>;

using pi = pair<ll, ll>;
using vi = vector<ll>;
template <class T>
using vc = vector<T>;
template <class T>
using vvc = vector<vc<T>>;
template <class T>
using vvvc = vector<vvc<T>>;
template <class T>
using vvvvc = vector<vvvc<T>>;
template <class T>
using vvvvvc = vector<vvvvc<T>>;
template <class T>
using pq = priority_queue<T>;
template <class T>
using pqg = priority_queue<T, vector<T>, greater<T>>;

#define vv(type, name, h, ...) \
  vector<vector<type>> name(h, vector<type>(__VA_ARGS__))
#define vvv(type, name, h, w, ...)   \
  vector<vector<vector<type>>> name( \
      h, vector<vector<type>>(w, vector<type>(__VA_ARGS__)))
#define vvvv(type, name, a, b, c, ...)       \
  vector<vector<vector<vector<type>>>> name( \
      a, vector<vector<vector<type>>>(       \
             b, vector<vector<type>>(c, vector<type>(__VA_ARGS__))))

// https://trap.jp/post/1224/
#define FOR1(a) for (ll _ = 0; _ < ll(a); ++_)
#define FOR2(i, a) for (ll i = 0; i < ll(a); ++i)
#define FOR3(i, a, b) for (ll i = a; i < ll(b); ++i)
#define FOR4(i, a, b, c) for (ll i = a; i < ll(b); i += (c))
#define FOR1_R(a) for (ll i = (a)-1; i >= ll(0); --i)
#define FOR2_R(i, a) for (ll i = (a)-1; i >= ll(0); --i)
#define FOR3_R(i, a, b) for (ll i = (b)-1; i >= ll(a); --i)
#define overload4(a, b, c, d, e, ...) e
#define overload3(a, b, c, d, ...) d
#define FOR(...) overload4(__VA_ARGS__, FOR4, FOR3, FOR2, FOR1)(__VA_ARGS__)
#define FOR_R(...) overload3(__VA_ARGS__, FOR3_R, FOR2_R, FOR1_R)(__VA_ARGS__)

#define FOR_subset(t, s) \
  for (ll t = (s); t >= 0; t = (t == 0 ? -1 : (t - 1) & (s)))
#define all(x) x.begin(), x.end()
#define len(x) ll(x.size())
#define elif else if

#define eb emplace_back
#define mp make_pair
#define mt make_tuple
#define fi first
#define se second

#define stoi stoll

int popcnt(int x) { return __builtin_popcount(x); }
int popcnt(u32 x) { return __builtin_popcount(x); }
int popcnt(ll x) { return __builtin_popcountll(x); }
int popcnt(u64 x) { return __builtin_popcountll(x); }
int popcnt_mod_2(int x) { return __builtin_parity(x); }
int popcnt_mod_2(u32 x) { return __builtin_parity(x); }
int popcnt_mod_2(ll x) { return __builtin_parityll(x); }
int popcnt_mod_2(u64 x) { return __builtin_parityll(x); }
// (0, 1, 2, 3, 4) -> (-1, 0, 1, 1, 2)
int topbit(int x) { return (x == 0 ? -1 : 31 - __builtin_clz(x)); }
int topbit(u32 x) { return (x == 0 ? -1 : 31 - __builtin_clz(x)); }
int topbit(ll x) { return (x == 0 ? -1 : 63 - __builtin_clzll(x)); }
int topbit(u64 x) { return (x == 0 ? -1 : 63 - __builtin_clzll(x)); }
// (0, 1, 2, 3, 4) -> (-1, 0, 1, 0, 2)
int lowbit(int x) { return (x == 0 ? -1 : __builtin_ctz(x)); }
int lowbit(u32 x) { return (x == 0 ? -1 : __builtin_ctz(x)); }
int lowbit(ll x) { return (x == 0 ? -1 : __builtin_ctzll(x)); }
int lowbit(u64 x) { return (x == 0 ? -1 : __builtin_ctzll(x)); }

template <typename T>
T floor(T a, T b) {
  return a / b - (a % b && (a ^ b) < 0);
}
template <typename T>
T ceil(T x, T y) {
  return floor(x + y - 1, y);
}
template <typename T>
T bmod(T x, T y) {
  return x - y * floor(x, y);
}
template <typename T>
pair<T, T> divmod(T x, T y) {
  T q = floor(x, y);
  return {q, x - q * y};
}

template <typename T, typename U>
T SUM(const vector<U>& A) {
  T sm = 0;
  for (auto&& a: A) sm += a;
  return sm;
}

#define MIN(v) *min_element(all(v))
#define MAX(v) *max_element(all(v))
#define LB(c, x) distance((c).begin(), lower_bound(all(c), (x)))
#define UB(c, x) distance((c).begin(), upper_bound(all(c), (x)))
#define UNIQUE(x) \
  sort(all(x)), x.erase(unique(all(x)), x.end()), x.shrink_to_fit()

template <typename T>
T POP(deque<T>& que) {
  T a = que.front();
  que.pop_front();
  return a;
}
template <typename T>
T POP(pq<T>& que) {
  T a = que.top();
  que.pop();
  return a;
}
template <typename T>
T POP(pqg<T>& que) {
  T a = que.top();
  que.pop();
  return a;
}
template <typename T>
T POP(vc<T>& que) {
  T a = que.back();
  que.pop_back();
  return a;
}

template <typename F>
ll binary_search(F check, ll ok, ll ng, bool check_ok = true) {
  if (check_ok) assert(check(ok));
  while (abs(ok - ng) > 1) {
    auto x = (ng + ok) / 2;
    (check(x) ? ok : ng) = x;
  }
  return ok;
}
template <typename F>
double binary_search_real(F check, double ok, double ng, int iter = 100) {
  FOR(iter) {
    double x = (ok + ng) / 2;
    (check(x) ? ok : ng) = x;
  }
  return (ok + ng) / 2;
}

template <class T, class S>
inline bool chmax(T& a, const S& b) {
  return (a < b ? a = b, 1 : 0);
}
template <class T, class S>
inline bool chmin(T& a, const S& b) {
  return (a > b ? a = b, 1 : 0);
}

// ? は -1
vc<int> s_to_vi(const string& S, char first_char) {
  vc<int> A(S.size());
  FOR(i, S.size()) { A[i] = (S[i] != '?' ? S[i] - first_char : -1); }
  return A;
}

template <typename T, typename U>
vector<T> cumsum(vector<U>& A, int off = 1) {
  int N = A.size();
  vector<T> B(N + 1);
  FOR(i, N) { B[i + 1] = B[i] + A[i]; }
  if (off == 0) B.erase(B.begin());
  return B;
}

// stable sort
template <typename T>
vector<int> argsort(const vector<T>& A) {
  vector<int> ids(len(A));
  iota(all(ids), 0);
  sort(all(ids),
       [&](int i, int j) { return (A[i] == A[j] ? i < j : A[i] < A[j]); });
  return ids;
}

// A[I[0]], A[I[1]], ...
template <typename T>
vc<T> rearrange(const vc<T>& A, const vc<int>& I) {
  vc<T> B(len(I));
  FOR(i, len(I)) B[i] = A[I[i]];
  return B;
}
#endif
#line 3 "main.cpp"

#line 2 "library/mod/dynamic_modint.hpp"

#line 2 "library/mod/modint_common.hpp"

struct has_mod_impl {
  template <class T>
  static auto check(T&& x) -> decltype(x.get_mod(), std::true_type{});
  template <class T>
  static auto check(...) -> std::false_type;
};

template <class T>
class has_mod : public decltype(has_mod_impl::check<T>(std::declval<T>())) {};

template <typename mint>
mint inv(int n) {
  static const int mod = mint::get_mod();
  static vector<mint> dat = {0, 1};
  assert(0 <= n);
  if (n >= mod) n %= mod;
  while (len(dat) <= n) {
    int k = len(dat);
    int q = (mod + k - 1) / k;
    dat.eb(dat[k * q - mod] * mint::raw(q));
  }
  return dat[n];
}

template <typename mint>
mint fact(int n) {
  static const int mod = mint::get_mod();
  assert(0 <= n && n < mod);
  static vector<mint> dat = {1, 1};
  while (len(dat) <= n) dat.eb(dat[len(dat) - 1] * mint::raw(len(dat)));
  return dat[n];
}

template <typename mint>
mint fact_inv(int n) {
  static vector<mint> dat = {1, 1};
  if (n < 0) return mint(0);
  while (len(dat) <= n) dat.eb(dat[len(dat) - 1] * inv<mint>(len(dat)));
  return dat[n];
}

template <class mint, class... Ts>
mint fact_invs(Ts... xs) {
  return (mint(1) * ... * fact_inv<mint>(xs));
}

template <typename mint, class Head, class... Tail>
mint multinomial(Head&& head, Tail&&... tail) {
  return fact<mint>(head) * fact_invs<mint>(std::forward<Tail>(tail)...);
}

template <typename mint>
mint C_dense(int n, int k) {
  static vvc<mint> C;
  static int H = 0, W = 0;
  auto calc = [&](int i, int j) -> mint {
    if (i == 0) return (j == 0 ? mint(1) : mint(0));
    return C[i - 1][j] + (j ? C[i - 1][j - 1] : 0);
  };
  if (W <= k) {
    FOR(i, H) {
      C[i].resize(k + 1);
      FOR(j, W, k + 1) { C[i][j] = calc(i, j); }
    }
    W = k + 1;
  }
  if (H <= n) {
    C.resize(n + 1);
    FOR(i, H, n + 1) {
      C[i].resize(W);
      FOR(j, W) { C[i][j] = calc(i, j); }
    }
    H = n + 1;
  }
  return C[n][k];
}

template <typename mint, bool large = false, bool dense = false>
mint C(ll n, ll k) {
  assert(n >= 0);
  if (k < 0 || n < k) return 0;
  if constexpr (dense) return C_dense<mint>(n, k);
  if constexpr (!large) return multinomial<mint>(n, k, n - k);
  k = min(k, n - k);
  mint x(1);
  FOR(i, k) x *= mint(n - i);
  return x * fact_inv<mint>(k);
}

template <typename mint, bool large = false>
mint C_inv(ll n, ll k) {
  assert(n >= 0);
  assert(0 <= k && k <= n);
  if (!large) return fact_inv<mint>(n) * fact<mint>(k) * fact<mint>(n - k);
  return mint(1) / C<mint, 1>(n, k);
}

// [x^d](1-x)^{-n}
template <typename mint, bool large = false, bool dense = false>
mint C_negative(ll n, ll d) {
  assert(n >= 0);
  if (d < 0) return mint(0);
  if (n == 0) { return (d == 0 ? mint(1) : mint(0)); }
  return C<mint, large, dense>(n + d - 1, d);
}
#line 2 "library/mod/primitive_root.hpp"

#line 2 "library/nt/factor.hpp"

#line 2 "library/random/base.hpp"

u64 RNG_64() {
  static uint64_t x_
      = uint64_t(chrono::duration_cast<chrono::nanoseconds>(
                     chrono::high_resolution_clock::now().time_since_epoch())
                     .count())
        * 10150724397891781847ULL;
  x_ ^= x_ << 7;
  return x_ ^= x_ >> 9;
}

u64 RNG(u64 lim) { return RNG_64() % lim; }

ll RNG(ll l, ll r) { return l + RNG_64() % (r - l); }
#line 2 "library/mod/mongomery_modint.hpp"

// odd mod.
// x の代わりに rx を持つ
template <int id, typename U1, typename U2>
struct Mongomery_modint {
  using mint = Mongomery_modint;
  inline static U1 m, r, n2;
  static constexpr int W = numeric_limits<U1>::digits;

  static void set_mod(U1 mod) {
    assert(mod & 1 && mod <= U1(1) << (W - 2));
    m = mod, n2 = -U2(m) % m, r = m;
    FOR(5) r *= 2 - m * r;
    r = -r;
    assert(r * m == U1(-1));
  }
  static U1 reduce(U2 b) { return (b + U2(U1(b) * r) * m) >> W; }

  U1 x;
  Mongomery_modint() : x(0) {}
  Mongomery_modint(U1 x) : x(reduce(U2(x) * n2)){};
  U1 val() const {
    U1 y = reduce(x);
    return y >= m ? y - m : y;
  }
  mint& operator+=(mint y) {
    x = ((x += y.x) >= m ? x - m : x);
    return *this;
  }
  mint& operator-=(mint y) {
    x -= (x >= y.x ? y.x : y.x - m);
    return *this;
  }
  mint& operator*=(mint y) {
    x = reduce(U2(x) * y.x);
    return *this;
  }
  mint operator+(mint y) const { return mint(*this) += y; }
  mint operator-(mint y) const { return mint(*this) -= y; }
  mint operator*(mint y) const { return mint(*this) *= y; }
  bool operator==(mint y) const {
    return (x >= m ? x - m : x) == (y.x >= m ? y.x - m : y.x);
  }
  bool operator!=(mint y) const { return not operator==(y); }
  mint pow(ll n) const {
    assert(n >= 0);
    mint y = 1, z = *this;
    for (; n; n >>= 1, z *= z)
      if (n & 1) y *= z;
    return y;
  }
};

template <int id>
using Mongomery_modint_32 = Mongomery_modint<id, u32, u64>;
template <int id>
using Mongomery_modint_64 = Mongomery_modint<id, u64, u128>;
#line 3 "library/nt/primetest.hpp"

bool primetest(const u64 x) {
  assert(x < u64(1) << 62);
  if (x == 2 or x == 3 or x == 5 or x == 7) return true;
  if (x % 2 == 0 or x % 3 == 0 or x % 5 == 0 or x % 7 == 0) return false;
  if (x < 121) return x > 1;
  const u64 d = (x - 1) >> lowbit(x - 1);

  using mint = Mongomery_modint_64<202311020>;

  mint::set_mod(x);
  const mint one(u64(1)), minus_one(x - 1);
  auto ok = [&](u64 a) -> bool {
    auto y = mint(a).pow(d);
    u64 t = d;
    while (y != one && y != minus_one && t != x - 1) y *= y, t <<= 1;
    if (y != minus_one && t % 2 == 0) return false;
    return true;
  };
  if (x < (u64(1) << 32)) {
    for (u64 a: {2, 7, 61})
      if (!ok(a)) return false;
  } else {
    for (u64 a: {2, 325, 9375, 28178, 450775, 9780504, 1795265022}) {
      if (!ok(a)) return false;
    }
  }
  return true;
}
#line 5 "library/nt/factor.hpp"

template <typename mint>
ll rho(ll n, ll c) {
  assert(n > 1);
  const mint cc(c);
  auto f = [&](mint x) { return x * x + cc; };
  mint x = 1, y = 2, z = 1, q = 1;
  ll g = 1;
  const ll m = 1LL << (__lg(n) / 5);
  for (ll r = 1; g == 1; r <<= 1) {
    x = y;
    FOR(r) y = f(y);
    for (ll k = 0; k < r && g == 1; k += m) {
      z = y;
      FOR(min(m, r - k)) y = f(y), q *= x - y;
      g = gcd(q.val(), n);
    }
  }
  if (g == n) do {
      z = f(z);
      g = gcd((x - z).val(), n);
    } while (g == 1);
  return g;
}

ll find_prime_factor(ll n) {
  assert(n > 1);
  if (primetest(n)) return n;
  FOR(100) {
    ll m = 0;
    if (n < (1 << 30)) {
      using mint = Mongomery_modint_32<20231025>;
      mint::set_mod(n);
      m = rho<mint>(n, RNG(0, n));
    } else {
      using mint = Mongomery_modint_64<20231025>;
      mint::set_mod(n);
      m = rho<mint>(n, RNG(0, n));
    }
    if (primetest(m)) return m;
    n = m;
  }
  assert(0);
  return -1;
}

// ソートしてくれる
vc<pair<ll, int>> factor(ll n) {
  assert(n >= 1);
  vc<pair<ll, int>> pf;
  FOR(p, 2, 100) {
    if (p * p > n) break;
    if (n % p == 0) {
      ll e = 0;
      do { n /= p, e += 1; } while (n % p == 0);
      pf.eb(p, e);
    }
  }
  while (n > 1) {
    ll p = find_prime_factor(n);
    ll e = 0;
    do { n /= p, e += 1; } while (n % p == 0);
    pf.eb(p, e);
  }
  sort(all(pf));
  return pf;
}

vc<pair<ll, int>> factor_by_lpf(ll n, vc<int>& lpf) {
  vc<pair<ll, int>> res;
  while (n > 1) {
    int p = lpf[n];
    int e = 0;
    while (n % p == 0) {
      n /= p;
      ++e;
    }
    res.eb(p, e);
  }
  return res;
}
#line 2 "library/mod/mod_pow.hpp"

#line 2 "library/mod/barrett.hpp"

// https://github.com/atcoder/ac-library/blob/master/atcoder/internal_math.hpp
struct Barrett {
  u32 m;
  u64 im;
  explicit Barrett(u32 m = 1) : m(m), im(u64(-1) / m + 1) {}
  u32 umod() const { return m; }
  u32 modulo(u64 z) {
    if (m == 1) return 0;
    u64 x = (u64)(((unsigned __int128)(z)*im) >> 64);
    u64 y = x * m;
    return (z - y + (z < y ? m : 0));
  }
  u64 floor(u64 z) {
    if (m == 1) return z;
    u64 x = (u64)(((unsigned __int128)(z)*im) >> 64);
    u64 y = x * m;
    return (z < y ? x - 1 : x);
  }
  pair<u64, u32> divmod(u64 z) {
    if (m == 1) return {z, 0};
    u64 x = (u64)(((unsigned __int128)(z)*im) >> 64);
    u64 y = x * m;
    if (z < y) return {x - 1, z - y + m};
    return {x, z - y};
  }
  u32 mul(u32 a, u32 b) { return modulo(u64(a) * b); }
};

struct Barrett_64 {
  u128 mod, mh, ml;

  explicit Barrett_64(u64 mod = 1) : mod(mod) {
    u128 m = u128(-1) / mod;
    if (m * mod + mod == u128(0)) ++m;
    mh = m >> 64;
    ml = m & u64(-1);
  }

  u64 umod() const { return mod; }

  u64 modulo(u128 x) {
    u128 z = (x & u64(-1)) * ml;
    z = (x & u64(-1)) * mh + (x >> 64) * ml + (z >> 64);
    z = (x >> 64) * mh + (z >> 64);
    x -= z * mod;
    return x < mod ? x : x - mod;
  }

  u64 mul(u64 a, u64 b) { return modulo(u128(a) * b); }
};
#line 5 "library/mod/mod_pow.hpp"

u32 mod_pow(int a, ll n, int mod) {
  assert(n >= 0);
  a = ((a %= mod) < 0 ? a + mod : a);
  if ((mod & 1) && (mod < (1 << 30))) {
    using mint = Mongomery_modint_32<202311021>;
    mint::set_mod(mod);
    return mint(a).pow(n).val();
  }
  Barrett bt(mod);
  int r = 1;
  while (n) {
    if (n & 1) r = bt.mul(r, a);
    a = bt.mul(a, a), n >>= 1;
  }
  return r;
}

u64 mod_pow_64(ll a, ll n, u64 mod) {
  assert(n >= 0);
  a = ((a %= mod) < 0 ? a + mod : a);
  if ((mod & 1) && (mod < (u64(1) << 62))) {
    using mint = Mongomery_modint_64<202311021>;
    mint::set_mod(mod);
    return mint(a).pow(n).val();
  }
  Barrett_64 bt(mod);
  ll r = 1;
  while (n) {
    if (n & 1) r = bt.mul(r, a);
    a = bt.mul(a, a), n >>= 1;
  }
  return r;
}
#line 6 "library/mod/primitive_root.hpp"

// int
int primitive_root(int p) {
  auto pf = factor(p - 1);
  auto is_ok = [&](int g) -> bool {
    for (auto&& [q, e]: pf)
      if (mod_pow(g, (p - 1) / q, p) == 1) return false;
    return true;
  };
  while (1) {
    int x = RNG(1, p);
    if (is_ok(x)) return x;
  }
  return -1;
}

ll primitive_root_64(ll p) {
  auto pf = factor(p - 1);
  auto is_ok = [&](ll g) -> bool {
    for (auto&& [q, e]: pf)
      if (mod_pow_64(g, (p - 1) / q, p) == 1) return false;
    return true;
  };
  while (1) {
    ll x = RNG(1, p);
    if (is_ok(x)) return x;
  }
  return -1;
}
#line 6 "library/mod/dynamic_modint.hpp"

template <int id>
struct Dynamic_Modint {
  static constexpr bool is_modint = true;
  using mint = Dynamic_Modint;
  u32 val;
  static Barrett bt;
  static u32 umod() { return bt.umod(); }

  static int get_mod() { return (int)(bt.umod()); }
  static void set_mod(int m) {
    assert(1 <= m);
    bt = Barrett(m);
  }

  static Dynamic_Modint raw(u32 v) {
    Dynamic_Modint x;
    x.val = v;
    return x;
  }
  Dynamic_Modint() : val(0) {}
  Dynamic_Modint(u32 x) : val(bt.modulo(x)) {}
  Dynamic_Modint(u64 x) : val(bt.modulo(x)) {}
  Dynamic_Modint(int x) : val((x %= get_mod()) < 0 ? x + get_mod() : x) {}
  Dynamic_Modint(ll x) : val((x %= get_mod()) < 0 ? x + get_mod() : x) {}

  mint& operator+=(const mint& rhs) {
    val = (val += rhs.val) < umod() ? val : val - umod();
    return *this;
  }
  mint& operator-=(const mint& rhs) {
    val = (val += umod() - rhs.val) < umod() ? val : val - umod();
    return *this;
  }
  mint& operator*=(const mint& rhs) {
    val = bt.mul(val, rhs.val);
    return *this;
  }
  mint& operator/=(const mint& rhs) { return *this = *this * rhs.inverse(); }
  mint operator-() const { return mint() - *this; }
  mint pow(ll n) const {
    assert(0 <= n);
    mint x = *this, r = 1;
    while (n) {
      if (n & 1) r *= x;
      x *= x, n >>= 1;
    }
    return r;
  }
  mint inverse() const {
    int x = val, mod = get_mod();
    int a = x, b = mod, u = 1, v = 0, t;
    while (b > 0) {
      t = a / b;
      swap(a -= t * b, b), swap(u -= t * v, v);
    }
    if (u < 0) u += mod;
    return u;
  }

  friend mint operator+(const mint& lhs, const mint& rhs) {
    return mint(lhs) += rhs;
  }
  friend mint operator-(const mint& lhs, const mint& rhs) {
    return mint(lhs) -= rhs;
  }
  friend mint operator*(const mint& lhs, const mint& rhs) {
    return mint(lhs) *= rhs;
  }
  friend mint operator/(const mint& lhs, const mint& rhs) {
    return mint(lhs) /= rhs;
  }
  friend bool operator==(const mint& lhs, const mint& rhs) {
    return lhs.val == rhs.val;
  }
  friend bool operator!=(const mint& lhs, const mint& rhs) {
    return lhs.val != rhs.val;
  }
  static pair<int, int>& get_ntt() {
    static pair<int, int> p = {-1, -1};
    return p;
  }
  static void set_ntt_info() {
    int mod = get_mod();
    int k = lowbit(mod - 1);
    int r = primitive_root(mod);
    r = mod_pow(r, (mod - 1) >> k, mod);
    get_ntt() = {k, r};
  }
  static pair<int, int> ntt_info() { return get_ntt(); }
  static bool can_ntt() { return ntt_info().fi != -1; }
};

#ifdef FASTIO
template <int id>
void rd(Dynamic_Modint<id>& x) {
  fastio::rd(x.val);
  x.val %= Dynamic_Modint<id>::umod();
}
template <int id>
void wt(Dynamic_Modint<id> x) {
  fastio::wt(x.val);
}
#endif

using dmint = Dynamic_Modint<-1>;
template <int id>
Barrett Dynamic_Modint<id>::bt;
#line 1 "library/seq/geometric_sequence_sum.hpp"

// sum_{i=0}^{n-1}r^i
template <typename T>
T geometic_sequence_sum(T r, ll n) {
  if (n == 0) return T(0);
  // (r^n, 1+...+r^{n-1})
  auto dfs = [&](auto& dfs, ll n) -> pair<T, T> {
    if (n == 1) return {r, 1};
    auto [x, y] = dfs(dfs, n / 2);
    tie(x, y) = mp(x * x, x * y + y);
    if (n % 2 == 0) return {x, y};
    return {x * r, y + x};
  };
  return dfs(dfs, n).se;
}

// sum_{i=0}^{n-1}i^kr^i を k=0,1,...,K
template <typename T, int K>
array<T, K + 1> geometic_sequence_sum_K(T r, ll n) {
  array<array<T, K + 1>, K + 1> comb{};
  comb[0][0] = 1;
  FOR(i, K) {
    FOR(j, i + 1) {
      comb[i + 1][j] += comb[i][j], comb[i + 1][j + 1] += comb[i][j];
    }
  }

  // (n, r^n, sum i^kr^i)
  using X = tuple<T, T, array<T, K + 1>>;
  auto mul = [&](X& l, X& r) -> X {
    auto& [n1, r1, A] = l;
    auto& [n2, r2, B] = r;
    array<T, K + 1> C;
    FOR(k, K + 1) {
      C[k] = A[k];
      T c = r1;
      FOR(j, k + 1) { C[k] += comb[k][j] * c * B[k - j], c *= n1; }
    }
    return {n1 + n2, r1 * r2, C};
  };

  X res = {T(0), T(1), array<T, K + 1>{}};
  X a = {T(1), T(r), array<T, K + 1>{}};
  get<2>(a)[0] = 1;

  while (n) {
    if (n & 1) res = mul(res, a);
    a = mul(a, a), n /= 2;
  }
  return get<2>(res);
}
#line 6 "main.cpp"

template <int K>
void test() {
  using mint = dmint;
  FOR(p, 1, 50) {
    FOR(r, 50) {
      FOR(n, 50) {
        mint::set_mod(p);
        auto A = geometic_sequence_sum_K<mint, K>(r, n);
        FOR(k, K + 1) {
          mint ans = 0;
          mint pow = 1;
          FOR(i, n) { ans += pow * mint(i).pow(k), pow *= mint(r); }
          assert(A[k] == ans);
        }
      }
    }
  }
}

void test_sum() {
  using mint = dmint;
  FOR(p, 1, 50) {
    FOR(r, 50) {
      FOR(n, 50) {
        mint::set_mod(p);
        mint ans = 0;
        mint pow = 1;
        FOR(i, n) { ans += pow, pow *= mint(r); }
        mint me = geometic_sequence_sum<mint>(r, n);
        assert(ans == me);
      }
    }
  }
}

void solve() {
  int a, b;
  cin >> a >> b;
  cout << a + b << "\n";
}

signed main() {
  test<0>();
  test<1>();
  test<2>();
  test<3>();
  test<4>();
  test_sum();
  solve();
  return 0;
}
