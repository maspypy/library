#include "ds/decremental_fastset.hpp"

// 未知の木の euler tour の頂点列が -1 込みで与えられる
// https://codeforces.com/problemset/problem/1053/E
// 始点が 0 とは限りません
vc<int> restore_euler_tour(int N, vc<int> A) {
  if (N == 1) return {0};
  assert(len(A) == N + N - 1);
  if (A[0] == -1) A[0] = A.back();
  if (A.back() == -1) A.back() = A[0];
  if (A[0] != -1 && A.back() != -1 && A[0] != A.back()) return {};

  vc<int> exist(N);
  for (auto& x : A)
    if (0 <= x) exist[x] = 1;
  vc<int> other;
  FOR(x, N) if (!exist[x]) other.eb(x);
  FOR(N + N - 1) other.eb(N);
  reverse(all(other));

  vc<int> nxt(N + N - 1, -1), pre(N + N - 1, -1);
  {
    vc<int> pos(N, -1);
    FOR(i, N + N - 1) {
      int x = A[i];
      if (x == -1) continue;
      if (pos[x] != -1) nxt[pos[x]] = i, pre[i] = pos[x];
      pos[x] = i;
    }
  }

  pq_min<tuple<int, int, int>> que;
  FOR(i, N + N - 1) if (nxt[i] != -1) que.emplace(nxt[i] - i, i, nxt[i]);
  Decremental_FastSet FS(N + N - 1);

  auto rm = [&](int i) -> void {
    assert(FS[i]);
    FS.erase(i);
    int a = pre[i], b = nxt[i];
    if (a != -1) nxt[a] = b;
    if (b != -1) pre[b] = a;
    if (a != -1 && b != -1) que.emplace(b - a, a, b);
  };

  auto solve_local = [&](vc<int>& A) -> void {
    int N = len(A);
    assert(N >= 3 && A[0] == A[N - 1] && N % 2 == 1);
    // r.....r
    // 間は distinct で種類数は少ないとしてよい
    int n = 0;
    FOR(i, 1, N - 1) n += (A[i] != -1);
    if (n > N / 2) return;
    FOR(i, 1, N - 1) {
      if (A[i] == -1 && n < N / 2) A[i] = POP(other), ++n;
    }

    vc<int> I;
    FOR(i, 1, N - 1) {
      I.eb(i);
      while (len(I) >= 3) {
        int a = I[len(I) - 3];
        int b = I[len(I) - 2];
        int c = I[len(I) - 1];
        if (A[a] == -1 && A[b] != -1 && A[c] != -1) {
          A[a] = A[c];
          POP(I), POP(I);
        }
        elif (A[a] != -1 && A[b] != -1 && A[c] == -1) {
          A[c] = A[a];
          POP(I), POP(I);
        }
        else break;
      }
    }
    if (MIN(A) >= 0) return;
    for (auto& x : A)
      if (x == -1) x = A[0];
  };

  while (len(que)) {
    auto [pri, L, R] = POP(que);
    if (!FS[L] || !FS[R]) continue;
    vc<int> I;
    I.eb(L);
    FS.enumerate(L + 1, R, [&](int i) -> void { I.eb(i); });
    I.eb(R);
    vc<int> B = rearrange(A, I);
    if (len(B) % 2 == 0) return {};
    solve_local(B);
    FOR(i, len(B)) A[I[i]] = B[i];
    FS.enumerate(L, R, [&](int i) -> void { rm(i); });
  }

  auto solve_local_2 = [&](vc<int>& A) -> void {
    int N = len(A);
    assert(N >= 3 && A[0] == A[N - 1] && N % 2 == 1 && A[0] == -1);
    if (N == 3) {
      A[0] = A[N - 1] = POP(other);
      solve_local(A);
      return;
    }
    // ?.....?
    // 間は distinct で種類数は少ないとしてよい
    int n = 0;
    FOR(i, 1, N - 1) n += (A[i] != -1);
    if (n > 1 + N / 2) return;
    if (n <= N / 2) {
      A[0] = A[N - 1] = POP(other);
      solve_local(A);
      return;
    }
    // .23.10. 全種類登場はしている
    // やっぱりだいたい同じことをやればよい

    vc<int> I;
    FOR(i, 1, N - 1) {
      I.eb(i);
      while (len(I) >= 3) {
        int a = I[len(I) - 3];
        int b = I[len(I) - 2];
        int c = I[len(I) - 1];
        if (A[a] == -1 && A[b] != -1 && A[c] != -1) {
          A[a] = A[c];
          POP(I), POP(I);
        }
        elif (A[a] != -1 && A[b] != -1 && A[c] == -1) {
          A[c] = A[a];
          POP(I), POP(I);
        }
        else break;
      }
    }
    assert(len(I) == 3);
    A[0] = A[N - 1] = A[I[1]];
  };

  if (A[0] == -1) {
    vc<int> I;
    FS.enumerate(0, len(A), [&](int i) -> void { I.eb(i); });
    vc<int> B = rearrange(A, I);
    solve_local_2(B);
    FOR(i, len(I)) A[I[i]] = B[i];
  }

  // check
  if (MAX(A) >= N) return {};
  if (MIN(A) == -1) return {};
  vc<int> vis(N);
  vc<int> path = {A[0]};
  FOR(i, 1, len(A)) {
    int v = A[i];
    if (len(path) >= 2 && path[len(path) - 2] == v) {
      POP(path);
    } else {
      if (vis[v]) return {};
      path.eb(v);
      vis[v] = 1;
    }
  }
  if (len(path) != 1) return {};
  return A;
}
