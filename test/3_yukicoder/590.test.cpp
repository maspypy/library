#define PROBLEM "https://yukicoder.me/problems/no/590"
#include "my_template.hpp"
#include "other/io.hpp"
#include "graph/functional.hpp"
#include "nt/crt.hpp"
#include "mod/modint.hpp"

using mint = modint107;

void solve() {
  LL(N);
  auto get = [&]() -> pair<vvc<int>, vc<pair<int, int>>> {
    // サイクル
    // どのサイクル、何番目
    vvc<int> C;
    vc<pair<int, int>> pos(N, {-1, -1});
    VEC(ll, TO, N);
    for (auto&& x: TO) --x;
    FOR(r, N) {
      if (pos[r].fi != -1) continue;
      vc<int> cyc = {int(r)};
      while (1) {
        ll nxt = TO[cyc.back()];
        if (nxt == r) break;
        cyc.eb(nxt);
      }
      FOR(j, len(cyc)) pos[cyc[j]] = {len(C), j};
      C.eb(cyc);
    }
    return {C, pos};
  };

  auto [CA, posA] = get();
  auto [CB, posB] = get();

  /*
  ・サイクル番号1、サイクル番号2、mod gcd(len) 1, 2
  */
  using T = tuple<int, int, int>;
  map<T, vc<int>> MP;
  FOR(v, N) {
    auto [i1, j1] = posA[v];
    auto [i2, j2] = posB[v];
    ll n1 = len(CA[i1]);
    ll n2 = len(CB[i2]);
    ll g = gcd(n1, n2);
    ll x = (j1 - j2) % g;
    if (x < 0) x += g;
    T t = {i1, i2, x};
    MP[t].eb(v);
  }

  mint ANS = 0;

  for (auto&& [key, I]: MP) {
    auto r = I[0];
    // t=0 で (r,r) にいるとする。(v,v) にいる時刻
    vi X;
    auto [i1, i2, ___] = key;
    ll n1 = len(CA[i1]);
    ll n2 = len(CB[i2]);
    ll s1 = posA[r].se;
    ll s2 = posB[r].se;
    for (auto&& v: I) {
      ll t1 = posA[v].se;
      ll t2 = posB[v].se;
      t1 -= s1;
      t2 -= s2;
      if (t1 < 0) t1 += n1;
      if (t2 < 0) t2 += n2;
      vc<int> vals = {int(t1), int(t2)};
      vc<int> mods = {int(n1), int(n2)};
      ll x = CRT(vals, mods);
      X.eb(x);
    }
    X.eb(n1 / gcd(n1, n2) * n2);
    sort(all(X));
    FOR(k, len(X) - 1) {
      mint dx = X[k + 1] - X[k];
      ANS += (dx) * (dx - 1);
    }
  }
  ANS /= mint(2);
  print(ANS);
}

signed main() {
  solve();
  return 0;
}