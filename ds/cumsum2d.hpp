#include "alg/monoid/add.hpp"

template <typename Group>
struct Cumsum2D {
  using X = typename Group::value_type;
  int H, W;
  vc<vc<X>> dat;

  Cumsum2D() {}
  Cumsum2D(vc<vc<X>> &A) {
    assert(Group::commute);
    build(A);
  }

  void build(vc<vc<X>> &A) {
    int H = len(A);
    int W = (H == 0 ? 0 : len(A[0]));
    dat.assign(H + 1, vc<X>(W + 1, Group::unit()));
    FOR(x, H) FOR(y, W) dat[x + 1][y + 1] = A[x][y];
    FOR(x, H + 1) FOR(y, W) dat[x][y + 1] = Group::op(dat[x][y + 1], dat[x][y]);
    FOR(x, H) FOR(y, W + 1) dat[x + 1][y] = Group::op(dat[x + 1][y], dat[x][y]);
  }

  X sum(int x1, int x2, int y1, int y2) {
    X a = Group::op(dat[x1][y1], dat[x2][y2]);
    X b = Group::op(dat[x2][y1], dat[x1][y2]);
    return Group::op(a, Group::inverse(b));
  }
};
