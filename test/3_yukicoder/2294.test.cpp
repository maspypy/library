#define PROBLEM "https://yukicoder.me/problems/no/2294"

#include "my_template.hpp"
#include "other/io.hpp"

#include "ds/unionfind/potentialized_unionfind.hpp"
#include "alg/monoid/xor.hpp"
#include "mod/modint.hpp"

using mint = modint998;

void solve() {
  LL(N, v0, Q);
  const int K = 30;
  using ARR = array<array<int, 2>, 30>;
  vc<ARR> dat(N);
  FOR(v, N) { FOR(k, K) dat[v][k][0] = 1, dat[v][k][1] = 0; }

  Potentialized_UnionFind<Monoid_Xor<int>> uf(N);

  auto query_1 = [&](ll v, ll val) -> void {
    int a = v0, b = v;
    auto [ra, xa] = uf.get(a);
    auto [rb, xb] = uf.get(b);
    int x = xa ^ xb ^ val;
    assert(ra != rb);
    uf.merge(a, b, val);
    int r = uf.get(a).fi;
    for (int c: {ra, rb}) {
      if (c == r) continue;
      FOR(k, K) {
        if (x >> k & 1) {
          dat[r][k][0] += dat[c][k][1], dat[r][k][1] += dat[c][k][0];
        } else {
          dat[r][k][0] += dat[c][k][0], dat[r][k][1] += dat[c][k][1];
        }
      }
    }
  };

  auto query_2 = [&](ll a, ll b) -> void {
    auto [ra, xa] = uf.get(a);
    auto [rb, xb] = uf.get(b);
    if (ra != rb) return print(-1);
    int d = xa ^ xb;
    print(d);
    v0 = (v0 + d) % N;
  };

  auto query_3 = [&](ll v) -> void {
    auto A = dat[uf.get(v).fi];
    // print("A", A[0], A[1]);
    mint ANS = 0;
    mint pow = 1;
    FOR(k, 30) {
      ll a = A[k][0], b = A[k][1];
      ANS += mint(a * b) * pow;
      pow += pow;
    }
    print(ANS);
  };

  FOR(Q) {
    LL(t);
    if (t == 1) {
      LL(v, val);
      query_1(v, val);
    }
    if (t == 2) {
      LL(a, b);
      query_2(a, b);
    }
    if (t == 3) {
      LL(v);
      query_3(v);
    }
    if (t == 4) {
      LL(add);
      v0 += add;
      v0 %= N;
    }
  }
}

signed main() {
  int T = 1;
  // INT(T);
  FOR(T) solve();
  return 0;
}