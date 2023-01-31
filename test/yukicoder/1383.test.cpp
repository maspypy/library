#define PROBLEM "https://yukicoder.me/problems/no/1383"
#include "my_template.hpp"
#include "other/io.hpp"
#include "ds/hashmap.hpp"

void solve() {
  LL(N, K, M);

  HashMap<int, 21> MP;
  FOR(A, 1, 1 << 20) {
    vi X;
    ll prod = A;
    FOR(B, 1, 100) {
      prod = min<i128>(N + 1, i128(prod) * (A + K * B));
      if (prod > N) break;
      X.eb(prod);
    }
    if (len(X) <= 1) break;
    FOR(i, 1, len(X)) MP[X[i]]++;
  }

  auto find = [&](ll N) -> ll {
    // x * (x + K) <= N となる最大の x
    auto check = [&](ll x) -> bool {
      i128 a = x;
      i128 b = a + K;
      return a * b <= N;
    };
    return binary_search(check, 0, 1LL << 30);
  };

  ll ANS = 0;
  // B = 1
  if (M == 1) ANS += find(N);
  MP.enumerate_all([&](auto k, auto v) {
    ll x = find(k);
    bool can = (i128(x) * (x + K) == k);
    if (can && M == 1) --ANS;
    if (can) ++v;
    if (v == M) ++ANS;
  });
  print(ANS);
}

signed main() {
  cout << fixed << setprecision(15);

  ll T = 1;
  // LL(T);
  FOR(T) solve();

  return 0;
}