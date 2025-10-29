
// https://codeforces.com/contest/1423/problem/A
// https://www.sciencedirect.com/science/article/abs/pii/0196677485900331?via%3Dihub
// 選好リストは左にある方優先
// 必要なら INF を入れて長さ N-1 ずつにしておくこと
vc<pair<int, int>> stable_roommate(vvc<int> prefer_list) {
  vvc<int>& A = prefer_list;
  int N = len(A);
  FOR(i, N - 1) assert(len(A[i]) == N - 1);

  FOR(v, N) SHOW(v, A[v]);

  vv(int, rank, N, N);
  FOR(i, N) FOR(j, N - 1) rank[i][A[i][j]] = j;

  vv(bool, exist, N, N, 1);
  FOR(i, N) exist[i][i] = 0;

  vc<int> que(N);  // propose してない人
  FOR(i, N) que[i] = i;
  vc<int> L(N), R(N, N - 1);
  vc<int> TO(N, -1), FRM(N, -1);

  auto clip = [&](int i) -> void {
    while (L[i] < R[i] && !exist[i][A[i][L[i]]]) ++L[i];
    while (L[i] < R[i] && !exist[i][A[i][R[i] - 1]]) --R[i];
  };

  auto nxt = [&](int i) -> int {
    // 2 番目
    clip(i);
    assert(R[i] - L[i] >= 2);
    int a = A[i][L[i]++];
    clip(i);
    A[i][--L[i]] = a;
    return FRM[A[i][L[i] + 1]];
  };

  while (1) {
    while (len(que)) {
      int x = POP(que);
      assert(TO[x] == -1);
      while (1) {
        clip(x);
        if (L[x] == R[x]) return {};
        int y = A[x][L[x]];
        if (FRM[y] != -1 && rank[y][x] > rank[y][FRM[y]]) {
          exist[x][y] = exist[y][x] = 0, ++L[x];
          continue;
        }
        if (FRM[y] != -1) {
          que.eb(FRM[y]), exist[FRM[y]][y] = exist[y][FRM[y]] = 0;
          TO[FRM[y]] = -1, FRM[y] = -1;
        }
        TO[x] = y, FRM[y] = x;
        while (A[y][R[y] - 1] != x) {
          int z = A[y][--R[y]];
          exist[y][z] = exist[z][y] = 0;
        }
        break;
      }
    }
    SHOW(FRM, TO);
    FOR(v, N) SHOW(v, A[v], L[v], R[v]);
    FOR(v, N) SHOW(exist[v]);
    int s = [&]() -> int {
      FOR(s, N) {
        clip(s);
        if (R[s] - L[s] > 1) return s;
      }
      return -1;
    }();
    if (s == -1) break;
    int x = s, y = s;
    do {
      x = nxt(x), y = nxt(nxt(y));
    } while (x != y);
    vc<int> cyc;
    do {
      cyc.eb(y), y = nxt(y);
    } while (x != y);
    for (int x : cyc) {
      int y = TO[x];
      FRM[y] = -1, TO[x] = -1, exist[x][y] = exist[y][x] = 0, que.eb(x);
    }
  }
  vc<pair<int, int>> ANS;
  FOR(i, N) {
    int j = TO[i];
    assert(TO[j] == i);
    if (i < j) ANS.eb(i, j);
  }
  return ANS;
}
