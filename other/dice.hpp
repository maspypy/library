#include "graph/base.hpp"

// 次の番号付けるに従う：UFRLBD
// i, 5-i が反対の面になっている
// https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_11_A
// https://atcoder.jp/contests/tenka1-2012-final/tasks/tenka1_2012_final_e
template <typename X>
struct Dice {
  using ARR = array<X, 6>;
  ARR A;

  Dice(ARR A) : A(A) {}

  X U() { return A[0]; }
  X F() { return A[1]; }
  X R() { return A[2]; }
  X L() { return A[3]; }
  X B() { return A[4]; }
  X D() { return A[5]; }

  // U のうつる先となる FRLB を指定する or 方角 NWES を指定する
  void rotate(char c) {
    if (c == 'F' || c == 'S') A = {A[4], A[0], A[2], A[3], A[5], A[1]};
    elif (c == 'R' || c == 'E') A = {A[3], A[1], A[0], A[5], A[4], A[2]};
    elif (c == 'L' || c == 'W') A = {A[2], A[1], A[5], A[0], A[4], A[3]};
    elif (c == 'B' || c == 'N') A = {A[1], A[5], A[2], A[3], A[0], A[4]};
    elif (c == 'U') A = {A[0], A[2], A[4], A[1], A[3], A[5]};
    elif (c == 'D') A = {A[0], A[3], A[1], A[4], A[2], A[5]};
    else {
      assert(false);
    }
  }

  vc<ARR> gen_all() {
    vc<ARR> res(24);
    vc<tuple<int, int, int>> tmp(24);
    tmp[0] = {0, 1, 2};
    tmp[1] = {0, 4, 3};
    tmp[2] = {5, 1, 3};
    tmp[3] = {5, 4, 2};

    FOR(i, 4) {
      auto [a, b, c] = tmp[i];
      tmp[4 + i] = {b, c, a};
      tmp[8 + i] = {c, a, b};
    }

    FOR(i, 12) {
      auto [a, b, c] = tmp[i];
      tmp[12 + i] = {5 - b, a, c};
    }

    FOR(i, 24) {
      auto [a, b, c] = tmp[i];
      res[i] = {A[a], A[b], A[c], A[5 - c], A[5 - b], A[5 - a]};
    }
    return res;
  }

  // 24 頂点 6 遷移のグラフを作る
  Graph<int, 0> to_graph() {
    int N = 24;
    Graph<int, 0> G(N);
    auto dat = gen_all();
    FOR(i, N) {
      array<X, 6> A = dat[i];
      for (char ch: {'U', 'F', 'R', 'L', 'B', 'D'}) {
        Dice<X> d(A);
        d.rotate(ch);
        int idx = -1;
        FOR(j, N) if (dat[j] == d.A) idx = j;
        assert(idx != -1);
        if (i < idx) G.add(i, idx);
      }
    }
    G.build();
    return G;
  }
};
