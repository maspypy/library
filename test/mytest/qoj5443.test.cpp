#define PROBLEM "https://judge.yosupo.jp/problem/aplusb"
#include "my_template.hpp"
#include "other/io.hpp"

#include "mod/modint.hpp"
#include "geo/base.hpp"
#include "geo/inside_polygon.hpp"
#include "geo/angle_sort.hpp"
#include "mod/powertable.hpp"

using P = Point<ll>;
using mint = modint998;

mint solve_QOJ5443(int N, vc<P> dat) {
  vv(bool, CAN, N, N);
  vv(int, CNT, N, N);

  FOR(a, N) FOR(b, N) {
    if (a == b) continue;
    P A = dat[a], B = dat[b];
    Segment<ll> AB(A, B);

    vc<bool> ON(N);
    FOR(c, N) {
      if (AB.contain(dat[c])) ON[c] = 1;
    }
    CNT[a][b] = SUM<int>(ON) - 2;
    CAN[a][b] = inside_polygon(AB, dat);
  }

  FOR(a, N) FOR(b, N) assert(CAN[a][b] == CAN[b][a]);
  FOR(a, N) FOR(b, N) assert(CNT[a][b] == CNT[b][a]);

  mint ANS = 0;
  vc<mint> POW = powertable_1<mint>(2, N);
  // 凸包が線分
  FOR(a, N) FOR(b, a) {
    if (CAN[a][b]) ANS += POW[CNT[a][b]];
  }

  // angle sort
  vc<pi> edge;
  vc<P> dir;
  FOR(a, N) FOR(b, N) {
    if (CAN[a][b]) {
      edge.eb(a, b);
      dir.eb(dat[b] - dat[a]);
    }
  }
  auto I = angle_argsort(dir);
  edge = rearrange(edge, I);
  dir = rearrange(dir, I);

  FOR(s, N) {
    // s スタート
    // [0][v]：1 回だけ進んだ
    // [1][v]：2 回以上進んだ
    vv(mint, dp, 2, N);
    // 同じ向きの線分での遷移をまとめて更新するようにする
    auto SAME = [&](int i, int j) -> bool {
      return (dir[i].det(dir[j]) == 0 && dir[i].dot(dir[j]) > 0);
    };
    int L = 0;
    while (L < len(edge)) {
      int R = L;
      while (R < len(edge) && SAME(L, R)) ++R;
      vc<tuple<int, int, mint>> upd;
      FOR(e, L, R) {
        auto [frm, to] = edge[e];
        mint cf = POW[CNT[frm][to]];
        if (frm == s) {
          upd.eb(0, to, cf);
        } else {
          if (to != s) upd.eb(1, to, dp[0][frm] * cf);
          upd.eb(1, to, dp[1][frm] * cf);
        }
      }
      L = R;
      for (auto&& [a, b, c]: upd) dp[a][b] += c;
    }
    ANS += dp[1][s];
  }
  return ANS;
}

void test_QOJ5443_1() {
  int N = 7;
  vc<P> dat(N);
  dat[0] = {0, 2};
  dat[1] = {4, 0};
  dat[2] = {4, 2};
  dat[3] = {7, 5};
  dat[4] = {5, 7};
  dat[5] = {3, 5};
  dat[6] = {0, 5};
  mint ANS = solve_QOJ5443(N, dat);
  assert(ANS.val == 56);
}

void test_QOJ5443_2() {
  int N = 12;
  vc<P> dat(N);
  dat[0] = {0, 0};
  dat[1] = {4, 0};
  dat[2] = {4, 5};
  dat[3] = {0, 5};
  dat[4] = {0, 2};
  dat[5] = {2, 2};
  dat[6] = {2, 3};
  dat[7] = {1, 3};
  dat[8] = {1, 4};
  dat[9] = {3, 4};
  dat[10] = {3, 1};
  dat[11] = {0, 1};
  mint ANS = solve_QOJ5443(N, dat);
  assert(ANS.val == 51);
}

void solve() {
  LL(a, b);
  print(a + b);
}

signed main() {
  test_QOJ5443_1();
  test_QOJ5443_2();
  solve();
  return 0;
}