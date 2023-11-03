#define PROBLEM "https://atcoder.jp/contests/abc220/tasks/abc220_g"
#include "my_template.hpp"
#include "other/io.hpp"

#include "geo/base.hpp"
#include "geo/perpendicular_bisector.hpp"
#include "random/base.hpp"
#include "ds/hashmap.hpp"
#include "alg/monoid/max2.hpp"

using P = Point<ll>;

void solve() {
  LL(N);
  vc<P> point(N);
  vi C(N);
  FOR(i, N) read(point[i], C[i]);

  u64 aa = RNG_64(), bb = RNG_64(), cc = RNG_64();

  using Mono = Monoid_Max2<ll, ll>;
  using Data = typename Mono::Data;
  HashMap<Data> MP;

  FOR(j, N) FOR(i, j) {
    Line<ll> L = perpendicular_bisector(point[i], point[j]);
    L.normalize();
    u64 key = 0;
    key += u64(L.a + infty<ll>) * aa;
    key += u64(L.b + infty<ll>) * bb;
    key += u64(L.c + infty<ll>) * cc;
    if (!MP.count(key)) MP[key] = Mono::unit();
    ll g = gcd(L.a, L.b);
    Point<ll> normal = {L.b / g, -L.a / g};
    ll t = normal.dot(point[i]);
    MP[key].add_element(C[i] + C[j], t);
  }

  ll ANS = -1;
  MP.enumerate_all([&](auto key, auto dat) -> void {
    ll ans = dat.max1 + dat.max2;
    chmax(ANS, ans);
  });
  print(ANS);
}

signed main() {
  solve();
  return 0;
}