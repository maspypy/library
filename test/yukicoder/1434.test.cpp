#define PROBLEM "https://yukicoder.me/problems/no/1434"
#include "my_template.hpp"
#include "other/io.hpp"
#include "ds/unionfind.hpp"
#include "other/transpose.hpp"

void solve() {
  LL(H1, W1);
  ll H = ceil(H1, 2);
  ll W = ceil(W1, 2);

  auto ng = [&]() -> void { print(-1); };

  LL(X);
  if (X % 2 == 1) return ng();
  X /= 2;
  if ((X + H + W) % 2) return ng();

  bool sw = 0;
  if (H % 2 == 0 && W % 2 == 1) {
    swap(H, W);
    swap(H1, W1);
    sw = 1;
  }

  vv(int, A, H, W, -10);

  auto out = [&]() -> void {
    vc<string> ANS(H1, string(W1, '#'));
    FOR(x, H) FOR(y, W) ANS[2 * x][2 * y] = '.';
    auto idx = [&](int x, int y) -> int { return W * x + y; };
    UnionFind uf(H * W);
    auto ope = [&](int x, int y, int x1, int y1) -> void {
      int a = idx(x, y), b = idx(x1, y1);
      assert(uf[a] != uf[b]);
      uf.merge(a, b);
      FOR(i, 2 * x, 2 * x1 + 1) FOR(j, 2 * y, 2 * y1 + 1) ANS[i][j] = '.';
    };

    FOR(x, H) FOR(y, W) {
      if (x + 1 < H && abs(A[x][y] - A[x + 1][y]) == 1) ope(x, y, x + 1, y);
      if (y + 1 < W && abs(A[x][y] - A[x][y + 1]) == 1) ope(x, y, x, y + 1);
    }
    FOR(x, H) FOR(y, W) {
      if (x + 1 < H && uf[idx(x, y)] != uf[idx(x + 1, y)]) ope(x, y, x + 1, y);
      if (y + 1 < W && uf[idx(x, y)] != uf[idx(x, y + 1)]) ope(x, y, x, y + 1);
    }

    if (sw) { ANS = transpose(ANS); }
    FOR(x, len(ANS)) print(ANS[x]);
  };

  if (H % 2 == 1) {
    ll h = H / 2;
    vi B(h);
    ll add = X - (H + W - 2);
    add /= 2;
    FOR(i, h) {
      ll k = min(add, W - 1);
      B[i] = k;
      add -= k;
    }
    ll nxt = 0;
    FOR(i, h) {
      FOR(j, B[i] + 1) A[2 * i][j] = nxt++;
      FOR_R(j, B[i] + 1) A[2 * i + 1][j] = nxt++;
    }
    FOR(y, W) A[H - 1][y] = nxt++;
    if (add) return ng();
    return out();
  }

  assert(H % 2 == 0 && W % 2 == 0);
  ll h = H / 2 - 1;
  ll add = X - (H + W - 2);
  add /= 2;
  vi B(h);
  FOR(i, h) {
    ll k = min(add, W - 1);
    B[i] = k;
    add -= k;
  }
  ll nxt = 0;
  FOR(i, h) {
    FOR(j, B[i] + 1) A[2 * i][j] = nxt++;
    FOR_R(j, B[i] + 1) A[2 * i + 1][j] = nxt++;
  }
  FOR(j, W / 2 - 1) {
    A[H - 2][2 * j] = nxt++;
    if (add) {
      A[H - 1][2 * j] = nxt++;
      A[H - 1][2 * j + 1] = nxt++;
      --add;
    }
    A[H - 2][2 * j + 1] = nxt++;
  }
  A[H - 2][W - 2] = nxt++;
  A[H - 1][W - 2] = nxt++;
  A[H - 1][W - 1] = nxt++;
  if (add) return ng();
  return out();
}

signed main() {
  cout << fixed << setprecision(15);

  ll T = 1;
  // LL(T);
  FOR(T) solve();

  return 0;
}
