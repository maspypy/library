#include "alg/monoid/add.hpp"

template <typename Monoid>
struct FenwickTree_2D_Dense {
  using G = Monoid;
  using E = typename G::value_type;
  static_assert(G::commute);
  int H, W;
  vc<E> dat;

  FenwickTree_2D_Dense() {}
  FenwickTree_2D_Dense(int H, int W) : H(H), W(W), dat(H * W) {}

  void add(int x, int y, E val) {
    ++x;
    while (x <= H) { add_x(x, y, val), x += x & -x; }
  }

  E sum(int lx, int rx, int ly, int ry) { return prod(lx, ly, rx, ry); }
  E prod(int lx, int rx, int ly, int ry) {
    E pos = G::unit(), neg = G::unit();
    while (lx < rx) { pos = G::op(pos, sum_x(rx, ly, ry)), rx -= rx & -rx; }
    while (rx < lx) { neg = G::op(neg, sum_x(lx, ly, ry)), lx -= lx & -lx; }
    return G::op(pos, G::inverse(neg));
  }

  E prefix_prod(int rx, int ry) { return prod(0, rx, 0, ry); }
  E prefix_sum(int rx, int ry) {
    E pos = G::unit();
    while (rx) { pos = G::op(pos, prefix_sum_x(rx, ry)), rx -= rx & -rx; }
    return pos;
  }

private:
  inline int idx(int x, int y) { return W * (x - 1) + (y - 1); }

  void add_x(int x, int y, E val) {
    ++y;
    while (y <= W) { dat[idx(x, y)] = G::op(dat[idx(x, y)], val), y += y & -y; }
  }
  E sum_x(int x, int ly, int ry) {
    E pos = G::unit(), neg = G::unit();
    while (ly < ry) { pos = G::op(pos, dat[idx(x, ry)]), ry -= ry & -ry; }
    while (ry < ly) { neg = G::op(neg, dat[idx(x, ly)]), ly -= ly & -ly; }
    return G::op(pos, G::inverse(neg));
  }
  E prefix_sum_x(int x, int ry) {
    E pos = G::unit();
    while (ry) { pos = G::op(pos, dat[idx(x, ry)]), ry -= ry & -ry; }
    return pos;
  }
};
