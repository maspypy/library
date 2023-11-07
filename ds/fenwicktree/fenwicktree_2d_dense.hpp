#include "alg/monoid/add.hpp"

template <typename Monoid>
struct FenwickTree_2D_Dense {
  using G = Monoid;
  using E = typename G::value_type;
  static_assert(G::commute);
  int H, W;
  vc<E> dat;

  FenwickTree_2D_Dense() {}
  FenwickTree_2D_Dense(int H, int W) : H(H), W(W), dat(H * W, G::unit()) {}
  FenwickTree_2D_Dense(int H, int W, vvc<E>& dat_raw) : H(H), W(W) {
    build(H, W, [&](int x, int y) -> E { return dat_raw[x][y]; });
  }
  template <typename F>
  FenwickTree_2D_Dense(int H, int W, F f) : H(H), W(W) {
    build(H, W, f);
  }

  template <typename F>
  void build(int H0, int W0, F f) {
    H = H0, W = W0;
    dat.assign(H * W, 0);
    FOR(x, H) FOR(y, W) { dat[W * x + y] = f(x, y); }
    FOR(x, 1, H + 1) {
      FOR(y, 1, W + 1) {
        int ny = y + (y & -y);
        if (ny <= W) dat[idx(x, ny)] = G::op(dat[idx(x, ny)], dat[idx(x, y)]);
      }
    }
    FOR(x, 1, H + 1) {
      FOR(y, 1, W + 1) {
        int nx = x + (x & -x);
        if (nx <= H) dat[idx(nx, y)] = G::op(dat[idx(nx, y)], dat[idx(x, y)]);
      }
    }
  }

  void add(int x, int y, E val) {
    ++x;
    while (x <= H) { add_x(x, y, val), x += x & -x; }
  }

  E sum(int lx, int rx, int ly, int ry) { return prod(lx, rx, ly, ry); }
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
