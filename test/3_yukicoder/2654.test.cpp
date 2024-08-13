#define PROBLEM "https://yukicoder.me/problems/no/2654"
#include "my_template.hpp"
#include "other/io.hpp"

#include "ds/slide_split_sum.hpp"
#include "graph/base.hpp"

void solve() {
  LL(N);
  ++N;
  VEC(ll, A, N);
  Graph<int, 0> G(N);
  G.read_tree(0, 0);

  Removable_Queue<pqg<ll>> que1;
  Removable_Queue<pq<ll>> que2;

  Slide_Split_Sum<ll> X;

  auto F = [&]() -> ll {
    ll n = len(X);
    if (n <= 2) return -1;
    ll mi = que1.top();
    ll ma = que2.top();

    ll ANS = infty<ll>;

    if (n % 2 == 0) {
      ll k = (n - 2) / 2;
      {
        ll a = X.query_l(k);
        ll b = X.query_l(k + 1) - a;
        ll c = X.query_r(k + 1) - ma;
        ll ans = (b * k - a) + (c - b * k);
        if (b == ma) ++ans;
        chmin(ANS, ans);
      }
      {
        ll a = X.query_l(k + 1) - mi;
        ll c = X.query_r(k);
        ll b = X.query_r(k + 1) - c;
        ll ans = (b * k - a) + (c - b * k);
        if (b == mi) ++ans;
        chmin(ANS, ans);
      }
      return ANS;
    }
    assert(n % 2 == 1);
    ll k = (n - 3) / 2;
    {
      ll a = X.query_l(k + 1) - mi;
      ll c = X.query_r(k + 1);
      ll b = X.query_r(k + 2) - c;
      ll ans = (b * k - a) + (c - b * (k + 1));
      if (b == mi) ++ans;
      chmin(ANS, ans);
    }
    {
      ll a = X.query_l(k);
      ll b = X.query_l(k + 1) - a;
      ll c = X.query_r(k + 2) - ma;
      ll ans = (b * k - a) + (c - b * (k + 1));
      if (b == ma) ++ans;
      chmin(ANS, ans);
    }
    return ANS;
  };

  vi ANS(N);
  auto dfs = [&](auto& dfs, int v, int p) -> void {
    X.insert(A[v]);
    que1.push(A[v]);
    que2.push(A[v]);
    for (auto& e: G[v]) {
      if (e.to == p) continue;
      dfs(dfs, e.to, v);
    }
    ANS[v] = F();
    X.erase(A[v]);
    que1.remove(A[v]);
    que2.remove(A[v]);
  };
  dfs(dfs, 0, -1);

  FOR(v, 1, N) { print(ANS[v]); }
}

signed main() {
  int T = 1;
  // INT(T);
  FOR(T) solve();
  return 0;
}
