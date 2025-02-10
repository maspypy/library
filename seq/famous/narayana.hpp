
// https://atcoder.jp/contests/agc070/tasks/agc070_c
// a>=b のとき, (0,0) から (a,b) へのパスでちょうど k 回曲がる.
// 普通の narayana number は (n,n,2k-1)
template <typename mint>
mint narayana_number(int a, int b, int k) {
  assert(0 <= a && 0 <= b && 0 <= k);
  if (a < b) return 0;
  if (b == 0) return (k == 0 ? 1 : 0);

  if (k % 2 == 1) {
    k = (k - 1) / 2;
    return C<mint>(a - 1, k) * C<mint>(b - 1, k) - C<mint>(a - 1, k - 1) * C<mint>(b - 1, k + 1);
  }
  k /= 2;
  return C<mint>(a - 1, k) * C<mint>(b - 1, k - 1) - C<mint>(a - 1, k - 1) * C<mint>(b - 1, k);
}
