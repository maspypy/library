/*
a は 01 行列、b は long long
XOR = b を解く。
解なし：empty、解あり：そのひとつ
・解空間の詳しい構造が欲しい場合には、桁ごとに F2 線形代数すること！
*/
template <typename INTEGER>
vc<INTEGER> solve_linear_xor(vc<vc<INTEGER>> a, vc<INTEGER> b) {
  auto n = len(a), m = len(a[0]);
  int rk = 0;
  FOR(j, m) {
    if (a[rk][j] == 0) {
      FOR3(i, rk + 1, n) if (a[i][j] != 0) {
        swap(a[rk], a[i]);
        swap(b[rk], b[i]);
        break;
      }
    }
    if (a[rk][j] == 0) continue;
    FOR(i, n) if (i != rk) {
      if (!a[i][j]) continue;
      b[i] ^= b[rk];
      FOR3(k, j, m) { a[i][k] ^= a[rk][k]; }
    }
    ++rk;
    if (rk == n) break;
  }
  FOR3(i, rk, n) if (b[i] != 0) return {};
  vc<INTEGER> x(m);
  int p = 0;
  FOR(i, rk) {
    while (a[i][p] == 0) ++p;
    x[p] = b[i];
  }
  return x;
}