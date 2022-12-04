#define PROBLEM "https://yukicoder.me/problems/no/655"
#include "my_template.hpp"
#include "other/io.hpp"
#include "ds/cumsum_2d.hpp"

void solve() {
  LL(N, K, P);
  vv(ll, A, N, N, -1);
  auto isin = [&](ll x, ll y) -> bool {
    return (0 <= x && x < N && 0 <= y && y <= x);
  };
  int dx[] = {1, 1, 0, -1, -1, 0};
  int dy[] = {0, 1, 1, 0, -1, -1};

  deque<pair<int, int>> que;
  auto add = [&](int x, int y, int d) -> void {
    if (A[x][y] != -1) return;
    A[x][y] = d;
    que.eb(x, y);
  };
  FOR(K) {
    LL(x, y);
    add(--x, --y, 0);
  }
  while (len(que)) {
    auto [x, y] = que.front();
    que.pop_front();
    FOR(d, 6) {
      int nx = x + dx[d], ny = y + dy[d];
      if (isin(nx, ny)) add(nx, ny, A[x][y] + 1);
    }
  }
  FOR(x, N) FOR(y, N) if (A[x][y] == -1) A[x][y] = 0;
  // 2 次元累積和
  Cumsum_2D<Monoid_Add<ll>> X(A);
  ll ANS = 0;
  // 超えない最大サイズを求める
  // 対角線ごとに、上から
  FOR(s, N) {
    ll k = 0;
    ll sm = 0;
    FOR(i, s, N) {
      int j = i - s;
      // 上段の k-sm がある。
      // 自分のところの (k-1)-sm がとれる。
      if (k > 0) {
        sm -= X.sum(i - 1, i - 1 + k, j - 1, j);
        --k;
      }
      while (i + k < N) {
        ll add = X.sum(i + k, i + k + 1, j, j + k + 1);
        if (sm + add >= P) break;
        ++k;
        sm += add;
      }
      ANS += (N - i) - k;
    }
  }
  print(ANS);
}

signed main() {
  cout << fixed << setprecision(15);

  ll T = 1;
  // LL(T);
  FOR(T) solve();

  return 0;
}
