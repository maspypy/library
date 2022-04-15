#include "nt/primetest.hpp"
#include "mod/primitive_root.hpp"
#include "mod/mod_inv.hpp"

int mod_kth_root(ll k, ll a, int mod) {
  assert(primetest(mod) && 0 <= a && a < mod);
  if (k == 0) return (a == 1 ? 1 : -1);
  if (a == 0) return 0;
  if (mod == 2) return a;
  k %= mod - 1;
  fast_div fd(mod);

  ll g = gcd(k, mod - 1);
  if (mod_pow(a, (mod - 1) / g, mod) != 1) return -1;

  ll c = mod_inv(k / g, (mod - 1) / g);
  a = mod_pow(a, c, mod);
  k = (k * c) % (mod - 1);
  if (k == 0) return 1;

  g = primitive_root(mod);

  auto solve_pp = [&](ll p, int e, ll a) -> ll {
    int f = 0;
    ll pf = 1;
    while ((mod - 1) % (pf * p) == 0) ++f, pf *= p;
    ll m = (mod - 1) / pf;
    /*
    ・位数 Qm の巡回群
    ・a の p^e 乗根をとりたい。持つことは分かっている
    ・a / x^{p^e} = b を維持する。まずは、b が p で割れる回数を増やしていく。
    */
    ll x = 1, b = a, c = f - e; // b ^ {mp^c} = 1
    int pc = 1;
    FOR_(c) pc *= p;
    int pe = 1;
    FOR_(e) pe *= p;
    // 必要ならば原始 p 乗根に関する離散対数問題のセットアップ
    ll G = mod_pow(g, (mod - 1) / p, mod);
    int M = 0;
    unordered_map<ll, int> MP;
    ll GM_inv = -1;
    if (c) {
      while (M * M < p) ++M;
      MP.reserve(M + 1);
      ll Gpow = 1;
      FOR(m, M) {
        MP[Gpow] = m;
        Gpow = Gpow * G % fd;
      }
      GM_inv = mod_pow(Gpow, mod - 2, mod);
    }

    while (c) {
      /*
      b^{mp^c} = 1 が分かっている。(b/x^{p^e}})^{mp^{c-1}} = 1 にしたい。
      x = g^{p^{f-c-e}*k} として探す。原始 p 乗根 B, G に対する B = G^k に帰着。
      */
      ll B = mod_pow(b, m * pc / p, mod);
      int k = [&](ll B) -> int {
        FOR(m, M + 1) {
          if (MP.count(B)) return m * M + MP[B];
          B = B * GM_inv % fd;
        }
        return -1;
      }(B);
      x = x * mod_pow(g, pf / pc / pe * k, mod) % fd;
      ll exp = pf / pc * k % (mod - 1);
      b = b * mod_pow(g, mod - 1 - exp, mod) % fd;
      --c;
      pc /= p;
    }
    int k = pe - mod_inv(m, pe);
    k = (k * m + 1) / pe;
    ll y = mod_pow(b, k, mod);
    x = x * y % fd;
    return x;
  };

  auto pf = factor(k);
  for (auto&& [p, e]: pf) a = solve_pp(p, e, a);
  return a;
}
