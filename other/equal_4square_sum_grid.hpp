
// https://atcoder.jp/contests/tupc2023/tasks/tupc2023_k
// [0,HW-1]の順列ですべての(2,2)正方形の和がS, 解いた場合.
// 一般に解いたわけではない. mod HW では解けている.
// (even,even) は S が確定. 他は微調整はできるという感じ.
vvc<int> equal_4square_sum_grid(int H, int W, int S) {
  assert(H >= 2 && W >= 2);
  int S0 = (H * W - 1) * 2;
  if (H % 2 == 1 && W % 2 == 0) {
    vvc<int> A = equal_4square_sum_grid(W, H, S);
    A = transpose(A);
    return A;
  }
  // 解いていない場合
  if (H % 2 == 0 && W % 2 == 0) assert(S0 - 3 <= S && S <= S0 + 3);
  if (W % 2 == 1 && H % 4 == 2) { assert(S0 - 1 <= S && S <= S0 + 1); }
  if (W % 2 == 1 && H % 4 == 0) { assert(S0 - 2 <= S && S <= S0 + 2); }

  if (S == S0 + 1 || S == S0 - 2) {
    vvc<int> A = equal_4square_sum_grid(H, W, 2 * S0 - S);
    FOR(x, H) FOR(y, W) A[x][y] = H * W - 1 - A[x][y];
    return A;
  }

  if (S == S0) {
    vv(int, A, H, W);
    FOR(j, W) A[j % 2][j] = j, A[(j + 1) % 2][j] = H * W - 1 - j;
    FOR(i, 2, H) FOR(j, W) {
      if ((i + j) % 2 == 0) A[i][j] = A[i - 2][j] + W;
      if ((i + j) % 2 == 1) A[i][j] = A[i - 2][j] - W;
    }
    return A;
  }
  if (H % 2 == 0 && W % 2 == 0) return {}; // 解なし
  if (S == S0 - 1) {
    vv(int, A, H, W);
    auto nxt = [&](int p) -> int { return (p >= H * W / 2 ? H * W - 1 - p : H * W - 2 - p); };
    int p = H * W - 1;
    FOR(x, H) FOR(y, W) { A[x][y] = p, p = nxt(p); }
    return A;
  }
  assert(W % 2 == 1 && H % 4 == 0 && S == S0 + 2);
  int n = H / 4;
  vc<int> tmp;
  FOR(i, 2 * n * W) {
    if (i % 2 == 0) tmp.eb(2 * i);
    if (i % 2 == 1) tmp.eb(H * W - 2 * i);
  }
  FOR(i, n * W) {
    if (i % 2 == 0) tmp.eb(2 * i + 1);
    if (i % 2 == 1) tmp.eb(H * W - 2 * i - 1);
  }
  FOR(i, 3 * n * W, 4 * n * W) { tmp.eb(H * W - tmp[i - n * W]); }
  int p = 0;
  vv(int, A, H, W);
  FOR(x, H) FOR(y, W) A[x][y] = tmp[p++];
  if (n % 2 == 0) { FOR(x, 3 * n, 4 * n) reverse(all(A[x])); }
  return A;
}
