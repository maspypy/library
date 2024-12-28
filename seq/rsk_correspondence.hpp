
pair<vvc<int>, vvc<int>> RSK_correspondence_prefix(vc<int> A, int nrow = -1) {
  int N = len(A);
  if (nrow == -1) nrow = N;
  vvc<int> X(nrow), Y(nrow);
  FOR(i, len(A)) {
    int a = A[i];
    int col = i;
    FOR(row, nrow) {
      // 指数探索
      int r = min<int>(col + 1, len(X[row]));
      // [r] > a
      int l = r - 1;
      while (0 <= l && X[row][l] > a) { tie(l, r) = mp(3 * l - 2 * r, l); }
      // [l] < a, [r] > a
      while (l + 1 < r) {
        int m = (l + r) / 2;
        (m < 0 || X[row][m] < a ? l : r) = m;
      }
      col = r;
      if (col == len(X[row])) {
        X[row].eb(a), Y[row].eb(i);
        break;
      } else {
        swap(X[row][col], a);
      }
    }
  }
  while (len(X) && X.back().empty()) POP(X);
  return {X, Y};
}

// 指数探索と転置の利用により worst(N^1.5) になっている.
// ランダムケースだと普通にやる方が速い.
pair<vvc<int>, vvc<int>> RSK_correspondence(vc<int> A) {
  int N = len(A);
  if (N == 0) return {};
  int M = 1;
  while (M * M < N) ++M;
  auto [X1, Y1] = RSK_correspondence_prefix(A, M);
  reverse(all(A));
  int m = len(X1);
  auto [X2, Y2] = RSK_correspondence_prefix(A, m);
  reverse(all(A));
  for (auto& x: A) x = N - 1 - x;
  auto [X3, Y3] = RSK_correspondence_prefix(A, m);
  X1.resize(len(X2[0]));
  Y1.resize(len(X2[0]));
  FOR(i, len(X2)) {
    FOR(j, M, len(X2[i])) {
      X1[j].eb(X2[i][j]);
      Y1[j].eb(Y3[i][j]);
    }
  }
  return {X1, Y1};
}
