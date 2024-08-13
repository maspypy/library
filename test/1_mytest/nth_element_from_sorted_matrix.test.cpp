#define PROBLEM "https://judge.yosupo.jp/problem/aplusb"
#include "my_template.hpp"

#include "random/base.hpp"
#include "random/shuffle.hpp"
#include "convex/nth_element_from_sorted_matrix.hpp"

void test() {
  ll N = RNG(1, 20);
  ll M = RNG(1, 20);
  vv(int, A, N, M);
  vc<pair<int, int>> IJ;
  FOR(i, N) FOR(j, M) IJ.eb(i, j);
  shuffle(IJ);
  FOR(k, len(IJ)) {
    auto [i, j] = IJ[k];
    A[i][j] = k;
  }

  FOR(i, N) sort(all(A[i]));
  FOR(j, M) {
    vc<int> col(N);
    FOR(i, N) col[i] = A[i][j];
    sort(all(col));
    FOR(i, N) A[i][j] = col[i];
  }
  if (RNG(0, 2)) {
    vv(int, B, M, N);
    FOR(i, N) FOR(j, M) B[j][i] = A[i][j];
    swap(A, B);
    swap(N, M);
  }

  int K = RNG(0, N * M + 1);
  auto f = [&](int i, int j) -> int { return A[i][j]; };

  vi L = nth_element_from_sorted_matrix<int>(N, M, K, f);

  FOR(i, N) {
    FOR(j, L[i]) { assert(A[i][j] < K); }
    FOR(j, L[i], M) { assert(A[i][j] >= K); }
  }
}

void test2() {
  ll N = RNG(1, 20);
  ll M = N;
  vv(int, A, N, M);
  vc<pair<int, int>> IJ;
  FOR(i, N) FOR(j, M) IJ.eb(i, j);
  shuffle(IJ);
  FOR(k, len(IJ)) {
    auto [i, j] = IJ[k];
    A[i][j] = k;
  }

  FOR(i, N) sort(all(A[i]));
  FOR(j, M) {
    vc<int> col(N);
    FOR(i, N) col[i] = A[i][j];
    sort(all(col));
    FOR(i, N) A[i][j] = col[i];
  }
  if (RNG(0, 2)) {
    vv(int, B, M, N);
    FOR(i, N) FOR(j, M) B[j][i] = A[i][j];
    swap(A, B);
    swap(N, M);
  }

  int K = RNG(0, N * M + 1);
  set<pair<int, int>> st;
  auto f = [&](int i, int j) -> int {
    st.insert(mp(i, j));
    return A[i][j];
  };

  nth_element_from_sorted_matrix<int>(N, M, K, f);
  int QLE = len(st);
  assert(QLE <= 5 * N);
}

void solve() {
  int a, b;
  cin >> a >> b;
  cout << a + b << "\n";
}

signed main() {
  FOR(50000) test();
  FOR(50000) test2();
  solve();
  return 0;
}