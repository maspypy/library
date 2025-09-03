#define PROBLEM "https://judge.yosupo.jp/problem/aplusb"
#include "my_template.hpp"

#include "ds/my_bitset.hpp"
#include "random/base.hpp"
#include "ds/sum_over_bit_positions.hpp"

void test(int N, int Q, bool check = true) {
  vector<int> A(N);
  My_Bitset bs(N);
  FOR(i, N) A[i] = RNG(0, N), bs[i] = RNG(0, 2);
  Sum_Over_Bit_Positions<int, 100'000> SB(N, [&](int i) -> int { return A[i]; });

  FOR(Q) {
    FOR(100) {
      int i = RNG(0, N);
      bs[i].flip();
    }
    ll ans = SB.query<ll>(bs, 0, N);
    if (check) {
      ll god = 0;
      FOR(i, N) if (bs[i]) god += A[i];
      assert(ans == god);
    }
  }
}

void solve() {
  int a, b;
  cin >> a >> b;
  cout << a + b << "\n";
}

signed main() {
  // test(100'000, 10'000, false);
  FOR(N, 1, 150) FOR(Q, 1, 150) test(N, Q, true);
  solve();
  return 0;
}
