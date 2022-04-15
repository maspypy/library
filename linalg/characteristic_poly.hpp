template <typename T>
void to_Hessenberg_matrix(vc<vc<T>>& A) {
  /*
  P^{-1}AP の形の変換で、Hessenberg 行列に変形する。
  特定多項式の計算に用いることができる。
  */
  int n = len(A);
  FOR(k, n - 2) {
    FOR3(i, k + 1, n) if (A[i][k] != 0) {
      if (i != k + 1) {
        swap(A[i], A[k + 1]);
        FOR(j, n) swap(A[j][i], A[j][k + 1]);
      }
      break;
    }
    if (A[k + 1][k] == 0) continue;
    FOR3(i, k + 2, n) {
      T c = A[i][k] / A[k + 1][k];
      // i 行目 -= k+1 行目 * c
      FOR(j, n) A[i][j] -= A[k + 1][j] * c;
      // k+1 列目 += i 列目 * c
      FOR(j, n) A[j][k + 1] += A[j][i] * c;
    }
  }
}

template <typename T>
vc<T> characteristic_poly(vc<vc<T>> A) {
  /*
  ・Hessenberg 行列に変形
  ・Hessenberg 行列の行列式は、最後の列で場合分けすれば dp できる
  */
  int n = len(A);
  to_Hessenberg_matrix(A);
  vc<vc<T>> DP(n + 1);
  DP[0] = {1};
  FOR(k, n) {
    DP[k + 1].resize(k + 2);
    auto& dp = DP[k + 1];
    // (k, k) 成分を使う場合
    FOR(i, len(DP[k])) dp[i + 1] += DP[k][i];
    FOR(i, len(DP[k])) dp[i] -= DP[k][i] * A[k][k];
    // 下側対角の総積を管理
    T prod = 1;
    FOR_R(i, k) {
      // (i, k) 成分を使う場合
      prod *= A[i + 1][i];
      T c = prod * A[i][k];
      // DP[i] の c 倍を加算
      FOR(j, len(DP[i])) dp[j] -= DP[i][j] * c;
    }
  }
  return DP[n];
}
