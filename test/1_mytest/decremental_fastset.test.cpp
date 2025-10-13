#define PROBLEM "https://judge.yosupo.jp/problem/aplusb"
#include "my_template.hpp"

#include "ds/unionfind/unionfind.hpp"
#include "random/shuffle.hpp"
#include "other/timer.hpp"
#include "ds/fastset.hpp"
#include "ds/decremental_fastset.hpp"

// ackerman. memory 多め
struct Decremental_FastSet_UF_ONLY {
  int n;
  UnionFind uf;
  vc<int> L, R;
  Decremental_FastSet_UF_ONLY(int n) : n(n), uf(n + 2), L(n + 2), R(n + 2) {
    FOR(i, n + 2) L[i] = i, R[i] = i;
  }
  void erase(int i) {
    assert(0 <= i && i < n);
    ++i;
    int l = L[uf[i - 1]], r = R[uf[i]];
    uf.merge(i, i - 1);
    L[uf[i]] = l, R[uf[i]] = r;
  }
  int prev(int i) {
    assert(-1 <= i);
    chmin(i, n - 1);
    return L[uf[i + 1]] - 1;
  }
  int next(int i) {
    assert(i <= n);
    chmax(i, 0);
    return R[uf[i]];
  }
};

vc<pair<int, int>> sol1(vc<int> A, vc<int> B) {
  int N = len(A);
  FastSet FS(N, [&](int i) -> int { return 1; });
  vc<pair<int, int>> ANS(N);
  FOR(i, N) {
    FS.erase(A[i]);
    ANS[i] = {FS.prev(B[i]), FS.next(B[i])};
  }
  return ANS;
}

vc<pair<int, int>> sol2(vc<int> A, vc<int> B) {
  int N = len(A);
  Decremental_FastSet FS(N);
  vc<pair<int, int>> ANS(N);
  FOR(i, N) {
    FS.erase(A[i]);
    ANS[i] = {FS.prev(B[i]), FS.next(B[i])};
  }
  return ANS;
}

vc<pair<int, int>> sol3(vc<int> A, vc<int> B) {
  int N = len(A);
  Decremental_FastSet_UF_ONLY FS(N);
  vc<pair<int, int>> ANS(N);
  FOR(i, N) {
    FS.erase(A[i]);
    ANS[i] = {FS.prev(B[i]), FS.next(B[i])};
  }
  return ANS;
}

void test() {
  vc<double> X, Y, Z;
  FOR(100) {
    int N = 1 << 20;
    vc<int> A(N);
    FOR(i, N) A[i] = i;
    shuffle(A);
    vc<int> B(N);
    FOR(i, N) B[i] = RNG(0, N);
    vc<pair<int, int>> ANS1, ANS2, ANS3;
    {
      Timer timer;
      timer.start();
      ANS1 = sol1(A, B);
      X.eb(timer());
    }
    {
      Timer timer;
      timer.start();
      ANS2 = sol2(A, B);
      Y.eb(timer());
    }

    {
      Timer timer;
      timer.start();
      ANS3 = sol3(A, B);
      Z.eb(timer());
    }
    // print(X.back(), Y.back(), Z.back());

    assert(ANS1 == ANS2);
    assert(ANS1 == ANS3);
  }
  // print(SUM<double>(X));
  // print(SUM<double>(Y));
  // print(SUM<double>(Z));
}

void solve() {
  int a, b;
  cin >> a >> b;
  cout << a + b << "\n";
}

signed main() {
  test();
  solve();
}
