#include "alg/monoid/add.hpp"
template <typename AbelGroup>
struct Fenwick2D_dense {
  using E = typename AbelGroup::value_type;
  int H, W;
  vc<vc<E>> dat;

  Fenwick2D_dense() {}
  Fenwick2D_dense(int H, int W) : H(H), W(W), dat(H + 1, vc<E>(W + 1)) {}

  void add_x(int x, int y, E val) {
    ++y;
    while (y <= W) {
      dat[x][y] = AbelGroup::op(dat[x][y], val);
      y += y & -y;
    }
  }

  void add(int x, int y, E val) {
    ++x;
    while (x <= H) {
      add_x(x, y, val);
      x += x & -x;
    }
  }

  E sum_x(int x, int ly, int ry) {
    E pos = AbelGroup::unit();
    E neg = AbelGroup::unit();
    while (ly < ry) {
      pos = AbelGroup::op(pos, dat[x][ry]);
      ry -= ry & -ry;
    }
    while (ry < ly) {
      neg = AbelGroup::op(neg, dat[x][ly]);
      ly -= ly & -ly;
    }
    return AbelGroup::op(pos, AbelGroup::inverse(neg));
  }

  E prod(int lx, int rx, int ly, int ry) {
    E pos = AbelGroup::unit();
    E neg = AbelGroup::unit();
    while (lx < rx) {
      pos = AbelGroup::op(pos, sum_x(rx, ly, ry));
      rx -= rx & -rx;
    }
    while (rx < lx) {
      neg = AbelGroup::op(neg, sum_x(lx, ly, ry));
      lx -= lx & -lx;
    }
    return AbelGroup::op(pos, AbelGroup::inverse(neg));
  }

  E sum(int lx, int rx, int ly, int ry) { return prod(lx, ly, rx, ry); }

  E prefix_prod(int rx, int ry) { return prod(0, rx, 0, ry); }
  E prefix_sum(int rx, int ry) { return prod(0, rx, 0, ry); }

  void debug() {
    print("Fenwick2d dat");
    FOR(x, H + 1) print(dat[x]);
  }
};
