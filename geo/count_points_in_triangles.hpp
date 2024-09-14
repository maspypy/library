
#include "geo/angle_sort.hpp"
#include "geo/base.hpp"
#include "random/base.hpp"
#include "ds/fenwicktree/fenwicktree_01.hpp"

// 点群 A, B を入力 （Point<ll>）
// query(i,j,k)：三角形 AiAjAk 内部の Bl の個数（非負）を返す
// 前計算 O(NMlogM)、クエリ O(1)
// https://codeforces.com/contest/13/problem/D
// https://codeforces.com/contest/852/problem/H
struct Count_Points_In_Triangles {
  using P = Point<ll>;
  const int LIM = 1'000'000'000 + 10;
  vc<P> A, B;
  vc<int> new_idx; // O から見た偏角ソート順を管理
  vc<int> point;   // A[i] と一致する B[j] の数え上げ
  vvc<int> seg;    // 線分 A[i]A[j] 内にある B[k] の数え上げ
  vvc<int> tri;    // OA[i]A[j] 内部にある B[k] の数え上げ
  Count_Points_In_Triangles(const vc<P>& A, const vc<P>& B) : A(A), B(B) {
    for (auto&& p: A) assert(max(abs(p.x), abs(p.y)) < LIM);
    for (auto&& p: B) assert(max(abs(p.x), abs(p.y)) < LIM);
    build();
  }

  int count3(int i, int j, int k) {
    i = new_idx[i], j = new_idx[j], k = new_idx[k];
    if (i > j) swap(i, j);
    if (j > k) swap(j, k);
    if (i > j) swap(i, j);
    assert(i <= j && j <= k);
    ll d = (A[j] - A[i]).det(A[k] - A[i]);
    if (d == 0) return 0;
    if (d > 0) { return tri[i][j] + tri[j][k] - tri[i][k] - seg[i][k]; }
    int x = tri[i][k] - tri[i][j] - tri[j][k];
    return x - seg[i][j] - seg[j][k] - point[j];
  }

  // segment
  int count2(int i, int j) {
    i = new_idx[i], j = new_idx[j];
    if (i > j) swap(i, j);
    return seg[i][j];
  }

private:
  P take_origin() {
    // OAiAj, OAiBj が同一直線上にならないようにする
    // fail prob: at most N(N+M)/LIM
    return P{-LIM, RNG(-LIM, LIM)};
  }

  void build() {
    P O = take_origin();
    for (auto&& p: A) p = p - O;
    for (auto&& p: B) p = p - O;
    int N = len(A), M = len(B);
    vc<int> I = angle_sort(A);
    A = rearrange(A, I);
    new_idx.resize(N);
    FOR(i, N) new_idx[I[i]] = i;

    I = angle_sort(B);
    B = rearrange(B, I);

    point.assign(N, 0);
    seg.assign(N, vc<int>(N));
    tri.assign(N, vc<int>(N));

    // point
    FOR(i, N) FOR(j, M) if (A[i] == B[j])++ point[i];

    int m = 0;
    FOR(j, N) {
      // OA[i]A[j], B[k]
      while (m < M && A[j].det(B[m]) < 0) ++m;
      vc<P> C(m);
      FOR(k, m) C[k] = B[k] - A[j];
      vc<int> I(m);
      FOR(i, m) I[i] = i;
      sort(all(I), [&](auto& a, auto& b) -> bool { return C[a].det(C[b]) > 0; });
      C = rearrange(C, I);
      vc<int> rk(m);
      FOR(k, m) rk[I[k]] = k;
      FenwickTree_01 bit(m);

      int k = m;
      FOR_R(i, j) {
        while (k > 0 && A[i].det(B[k - 1]) > 0) { bit.add(rk[--k], 1); }
        P p = A[i] - A[j];
        int lb = binary_search([&](int n) -> bool { return (n == 0 ? true : C[n - 1].det(p) > 0); }, 0, m + 1);
        int ub = binary_search([&](int n) -> bool { return (n == 0 ? true : C[n - 1].det(p) >= 0); }, 0, m + 1);
        seg[i][j] += bit.sum(lb, ub), tri[i][j] += bit.sum(lb);
      }
    }
  }
};