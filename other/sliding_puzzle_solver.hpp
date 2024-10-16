#include "linalg/transpose.hpp"
#include "seq/inversion.hpp"

/*
O(HW(H+W))
空マスは -1 (unique)
同じ値が複数あってもよい
操作回数を K として、長さ K+1 の空マスの座標列をかえす
*/
struct Slinding_Puzzle_Solver {
  using P = pair<int, int>;
  vc<P> solve(vvc<int> A, vvc<int> B) {
    int H = len(A), W = len(A[0]);
    auto find = [&](vvc<int>& A, int k) -> P {
      FOR(x, H) FOR(y, W) if (A[x][y] == k) return {x, y};
      assert(0);
      return {0, 0};
    };
    auto [ax, ay] = find(A, -1);
    auto [bx, by] = find(B, -1);
    vc<P> ANS_1, ANS_2;
    while (ax > 0) { ANS_1.eb(ax, ay), swap(A[ax][ay], A[ax - 1][ay]), --ax; }
    while (ay > 0) { ANS_1.eb(ax, ay), swap(A[ax][ay], A[ax][ay - 1]), --ay; }
    while (bx > 0) { ANS_2.eb(bx, by), swap(B[bx][by], B[bx - 1][by]), --bx; }
    while (by > 0) { ANS_2.eb(bx, by), swap(B[bx][by], B[bx][by - 1]), --by; }
    vc<P> ANS = solve_00(A, B);
    if (ANS.empty()) return {};
    reverse(all(ANS_2));
    return concat(ANS_1, ANS, ANS_2);
  }

private:
  vc<P> solve_00(vvc<int> A, vvc<int> B) {
    assert(A[0][0] == -1 && B[0][0] == -1);
    int H = len(A), W = len(A[0]);
    if (H == 1 || W == 1) {
      if (A != B) return {};
      vc<P> ANS;
      ANS.eb(0, 0);
      return ANS;
    }
    vc<P> XYA, XYB;
    FOR(x, H) FOR(y, W) XYA.eb(x, y), XYB.eb(x, y);
    sort(all(XYA), [&](auto& a, auto& b) -> bool { return A[a.fi][a.se] < A[b.fi][b.se]; });
    sort(all(XYB), [&](auto& a, auto& b) -> bool { return B[a.fi][a.se] < B[b.fi][b.se]; });
    auto check = [&]() -> bool {
      vc<int> S, T;
      FOR(i, H * W) {
        auto [x1, y1] = XYA[i];
        auto [x2, y2] = XYB[i];
        if (A[x1][y1] != B[x2][y2]) return 0;
        S.eb(W * x1 + y1);
        T.eb(W * x2 + y2);
      }
      ll x = inversion_between(S, T);
      return x % 2 == 0;
    };
    if (!check()) {
      FOR(i, H * W - 1) {
        auto [x1, y1] = XYA[i];
        auto [x2, y2] = XYA[i + 1];
        if (A[x1][y1] != A[x2][y2]) continue;
        swap(XYA[i], XYA[i + 1]);
        break;
      }
      if (!check()) return {};
    }
    vv(P, X, H, W);
    FOR(i, H * W) {
      auto [x1, y1] = XYA[i];
      auto [x2, y2] = XYB[i];
      X[x1][y1] = {x2, y2};
    }
    vc<P> ANS;
    ANS.eb(0, 0);
    solve_sort(X, ANS, false);
    return ANS;
  }

  // 移動先の座標の列を並べたグリッドを与える.
  // (0,0) が空マス
  void solve_sort(vvc<pair<int, int>>& A, vc<P>& ANS, bool tr) {
    int H = len(A), W = len(A[0]);
    vv(P, pos, H, W);
    FOR(x, H) FOR(y, W) {
      P p = A[x][y];
      pos[p.fi][p.se] = {x, y};
    }

    auto [px, py] = pos[0][0];

    auto ope = [&](int x, int y) -> void {
      assert(abs(px - x) + abs(py - y) == 1);
      swap(A[px][py], A[x][y]);
      if (!tr) ANS.eb(x, y);
      if (tr) ANS.eb(y, x);
      pos[A[px][py].fi][A[px][py].se] = {px, py};
      px = x, py = y;
      pos[A[px][py].fi][A[px][py].se] = {px, py};
    };
    if (H == 2 && W == 2) {
      auto check = [&]() -> bool {
        FOR(x, H) FOR(y, W) if (A[x][y].fi != x || A[x][y].se != y) return 0;
        return 1;
      };
      while (!check()) {
        if (px == 0 && py == 0) ope(1, 0);
        if (px == 1 && py == 0) ope(1, 1);
        if (px == 1 && py == 1) ope(0, 1);
        if (px == 0 && py == 1) ope(0, 0);
      }
      return;
    }
    if (H < W) {
      FOR(x, H) FOR(y, W) { swap(A[x][y].fi, A[x][y].se); }
      A = transpose(A, H, W);
      solve_sort(A, ANS, !tr);
      return;
    }
    assert(H >= 3 && W >= 2);
    // 最後の行をそろえる
    FOR_R(y, 1, W) {
      auto& [tx, ty] = pos[H - 1][y];
      if (px == H - 1) ope(px - 1, py);
      while (px - 1 > tx) ope(px - 1, py), tie(tx, ty) = pos[H - 1][y];
      while (px + 1 < tx) ope(px + 1, py), tie(tx, ty) = pos[H - 1][y];
      if (px == tx) {
        if (px == 0)
          ope(px + 1, py);
        else
          ope(px - 1, py);
      }
      assert(abs(px - tx) == 1);
      while (py < ty) ope(px, py + 1);
      while (py > ty) ope(px, py - 1);
      if (px == tx + 1) ope(px - 1, py), tie(tx, ty) = pos[H - 1][y];
      assert(px == tx - 1 && py == ty);
      while (ty < y) { ope(px, py + 1), ope(px + 1, py), ope(px, py - 1), ope(px - 1, py), ope(px, py + 1); }
      while (ty > y) { ope(px, py - 1), ope(px + 1, py), ope(px, py + 1), ope(px - 1, py), ope(px, py - 1); }
      tie(tx, ty) = pos[H - 1][y];
      while (tx < H - 1) {
        ope(px, py - 1), ope(px + 1, py), ope(px + 1, py), ope(px, py + 1), ope(px - 1, py);
        tie(tx, ty) = pos[H - 1][y];
      }
      assert(A[H - 1][y] == (pair<int, int>{H - 1, y}));
    }
    auto& [tx, ty] = pos[H - 1][0];
    if (px == H - 1) ope(px - 1, py);
    while (px - 1 > tx) ope(px - 1, py), tie(tx, ty) = pos[H - 1][0];
    while (px + 1 < tx) ope(px + 1, py), tie(tx, ty) = pos[H - 1][0];
    if (px == tx) {
      if (px == 0)
        ope(px + 1, py);
      else
        ope(px - 1, py);
    }
    tie(tx, ty) = pos[H - 1][0];
    assert(abs(px - tx) == 1);
    while (py < ty) ope(px, py + 1);
    while (py > ty) ope(px, py - 1);
    if (px == tx + 1) ope(px - 1, py);
    tie(tx, ty) = pos[H - 1][0];
    if (tx < H - 1) {
      assert(px == tx - 1 && py == ty);
      while (ty > 0) { ope(px, py - 1), ope(px + 1, py), ope(px, py + 1), ope(px - 1, py), ope(px, py - 1); }
      tie(tx, ty) = pos[H - 1][0];
      while (tx < H - 2) { ope(px, py + 1), ope(px + 1, py), ope(px + 1, py), ope(px, py - 1), ope(px - 1, py); }
      ope(px + 1, py), ope(px + 1, py), ope(px, py + 1);
      ope(px - 1, py), ope(px, py - 1), ope(px - 1, py);
      ope(px, py + 1), ope(px + 1, py), ope(px + 1, py);
      ope(px, py - 1), ope(px - 1, py);
    }
    FOR(y, W) assert(A[H - 1][y] == (pair<int, int>{H - 1, y}));
    POP(A);
    solve_sort(A, ANS, tr);
  }
};
