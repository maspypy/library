// とりあえず奇数のみ対応する
vvc<int> magic_square(int N) {
  assert(N % 2 == 1);
  vv(int, A, N, N);
  int x = 0, y = N / 2;
  FOR(i, N * N) {
    A[x][y] = i + 1;
    int nx = (x == 0 ? N - 1 : x - 1);
    int ny = (y == N - 1 ? 0 : y + 1);
    if (A[nx][ny] != 0) { nx = (x == N - 1 ? 0 : x + 1), ny = y; }
    tie(x, y) = mp(nx, ny);
  }
  return A;
}