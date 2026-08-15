
// 各行の最適列を求める
// better(i,j,k): 行 i において列 k が列 j より良いとき true
// 適用条件：better によって選ばれる最適列 opt[i] が i について広義単調増加
template <typename F>
vc<int> monotone_minima(int H, int W, F better) {
  if (H == 0) return {};
  assert(H > 0 && W > 0);

  vc<int> idx(H + 1);
  idx[0] = 0;
  FOR(y, 1, W) {
    if (better(0, idx[0], y)) idx[0] = y;
  }
  idx[H] = W - 1;

  int d = 1;
  while (d < H) d <<= 1;
  for (int q = d >> 1; q > 0; q >>= 1) {
    for (int h = q; h < H; h += q << 1) {
      int l = h - q;
      int r = min(h + q, H);
      int best = idx[l];
      for (int y = idx[l] + 1; y <= idx[r]; ++y) {
        if (better(h, best, y)) best = y;
      }
      idx[h] = best;
    }
  }
  idx.pop_back();
  return idx;
}