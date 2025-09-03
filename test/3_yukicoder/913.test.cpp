#define PROBLEM "https://yukicoder.me/problems/no/913"
#include "my_template.hpp"
#include "other/io.hpp"
#include "ds/segtree/dual_segtree.hpp"
#include "alg/monoid/min.hpp"
#include "convex/cht_monotone.hpp"

void solve() {
  LL(N);
  VEC(ll, A, N);
  Dual_SegTree<Monoid_Min<ll>> seg(N);

  auto f = [&](ll L, ll M, ll R) -> void {
    {
      // 右について、含む場合
      // まずは、左をデータに挿入
      CHT_monotone<ll, 1> cht;
      ll a = 0, b = 0;
      cht.add(2 * a, a * a + b);
      FOR3_R(i, L, M) {
        ++a;
        b += A[i];
        cht.add(2 * a, a * a + b);
      }

      ll c = 0, s = 0;
      FOR3(i, M, R) {
        ++c;
        s += A[i];
        ll y = cht.query_monotone_inc(c).fi + c * c + s;
        seg.apply(M, i + 1, y);
      }
    }
    {
      CHT_monotone<ll, 1> cht;
      ll a = 0, b = 0;
      cht.add(2 * a, a * a + b);
      FOR3(i, M + 1, R) {
        ++a;
        b += A[i];
        cht.add(2 * a, a * a + b);
      }

      ll c = 0, s = 0;
      FOR3_R(i, L, M + 1) {
        ++c;
        s += A[i];
        ll y = cht.query_monotone_inc(c).fi + c * c + s;
        seg.apply(i, M + 1, y);
      }
    }
  };

  auto dfs = [&](auto self, ll L, ll R) -> void {
    if (L == R) return;
    ll M = (L + R) / 2;
    f(L, M, R);
    self(self, L, M);
    self(self, M + 1, R);
  };
  dfs(dfs, 0, N);
  vi ANS = seg.get_all();
  for (auto&& x: ANS) print(x);
}

signed main() {
  solve();
  return 0;
}