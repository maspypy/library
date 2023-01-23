#define PROBLEM "https://yukicoder.me/problems/no/1881"
#include "my_template.hpp"
#include "other/io.hpp"
#include "random/hash_vector.hpp"
#include "ds/hashmap.hpp"
#include "nt/lpf_table.hpp"
#include "nt/factor.hpp"
#include "enumerate/partition.hpp"

void solve() {
  LL(N);
  VEC(ll, A, N);
  auto lpf = lpf_table(MAX(A));

  // 指数の減少列とその遷移
  HashMap<int, 15> MP1;
  vvc<int> TO1;

  auto get = [&](vc<int> B) -> ll {
    while (len(B) && B.back() == 0) B.pop_back();
    return hash_vector(B);
  };

  FOR(x, 18) {
    auto f = [&](vc<int> A) -> void {
      ll me = get(A);
      MP1[me] = len(TO1);
      TO1.eb(vc<int>());
      vc<int> B(len(A));
      A.eb(0);
      vc<int>& nxt = TO1.back();
      auto dfs = [&](auto& dfs, int s) -> void {
        if (s == len(A) - 1) {
          ll h = get(B);
          assert(MP1.count(h));
          nxt.eb(MP1[h]);
          return;
        }
        FOR(x, A[s + 1], A[s] + 1) {
          B[s] = x;
          dfs(dfs, s + 1);
        }
      };
      dfs(dfs, 0);
      A.pop_back();
    };
    enumerate_partition(x, f);
  }

  // node の組
  HashMap<int, 15> MP2;

  auto dfs = [&](auto& dfs, vc<int> A) -> int {
    // 全部を一斉に遷移させる。自己ループは除く。
    sort(all(A));
    ll h = hash_vector(A);
    if (MP2.count(h)) return MP2[h];

    int n = len(A);
    vc<int> B(n);
    vc<int> nxt;
    auto gen = [&](auto& gen, int p, bool same) -> void {
      if (p == n) {
        if (same) return;
        nxt.eb(dfs(dfs, B));
        return;
      }
      for (auto&& x: TO1[A[p]]) {
        B[p] = x;
        gen(gen, p + 1, same && (x == A[p]));
      }
    };
    gen(gen, 0, true);
    vc<bool> used((nxt.empty() ? 0 : MAX(nxt)) + 2);
    for (auto&& x: nxt) used[x] = 1;
    int mex = 0;
    while (used[mex]) ++mex;
    return (MP2[h] = mex);
  };

  ll g = 0;
  for (auto&& a: A) {
    map<int, vc<int>> G;
    for (auto&& [p, e]: factor_by_lpf(a, lpf)) {
      if (p == 2) {
        if (e == 1) continue;
        G[2].eb(1);
        G[2].eb(e - 2);
      } else {
        // (p-1)p^{e-1}
        G[p].eb(e - 1);
        for (auto&& [q, f]: factor_by_lpf(p - 1, lpf)) { G[q].eb(f); }
      }
    }
    vc<int> B;
    for (auto&& [p, E]: G) {
      sort(all(E));
      reverse(all(E));
      B.eb(MP1[get(E)]);
    }
    g ^= dfs(dfs, B);
  }
  print(g == 0 ? "X" : "Y");
}

signed main() {
  cout << fixed << setprecision(15);

  ll T = 1;
  // LL(T);
  FOR(T) solve();

  return 0;
}
