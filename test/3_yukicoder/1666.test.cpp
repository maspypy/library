#define PROBLEM "https://yukicoder.me/problems/no/1666"
#include "my_template.hpp"
#include "other/io.hpp"
#include "nt/integer_kth_root.hpp"
#include "nt/zeta.hpp"

void solve() {
  LL(K);
  auto check = [&](ll LIM) -> bool {
    // LIM 以下の累乗数が K 個以上
    auto f = [&](ll n) -> ll {
      ll x = integer_kth_root(n, LIM);
      return x - 1;
    };
    vi A(100);
    FOR3(i, 1, 100) A[i] = f(i);
    multiplier_mobius(A);
    ll cnt = 0;
    FOR3(i, 2, 100) cnt += A[i];
    if (1 <= LIM) ++cnt;
    return cnt >= K;
  };

  ll ANS = binary_search(check, 1e18, 0);
  print(ANS);
}

signed main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  cout << setprecision(15);

  LL(T);
  FOR(_, T) solve();

  return 0;
}
