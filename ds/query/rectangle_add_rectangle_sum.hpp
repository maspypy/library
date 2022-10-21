#pragma once

#include "ds/query/point_add_rectangle_sum.hpp"

template <typename AbelGroup, bool SMALL = false>
struct Rectangle_Add_Rectangle_Sum {
  using WT = typename AbelGroup::value_type;
  using WT4 = tuple<WT, WT, WT, WT>;

  struct G {
    using X = WT4;
    using value_type = X;
    static X op(const X &x, const X &y) {
      auto &[ax, bx, cx, dx] = x;
      auto &[ay, by, cy, dy] = y;
      return {AbelGroup::op(ax, ay), AbelGroup::op(bx, by),
              AbelGroup::op(cx, cy), AbelGroup::op(dx, dy)};
    }
    static X inverse(const X &x) {
      auto &[ax, bx, cx, dx] = x;
      return {AbelGroup::inverse(ax), AbelGroup::inverse(bx),
              AbelGroup::inverse(cx), AbelGroup::inverse(dx)};
    }
    static X power(const X &x, ll n) {
      auto &[ax, bx, cx, dx] = x;
      return {AbelGroup::power(ax, n), AbelGroup::power(bx, n),
              AbelGroup::power(cx, n), AbelGroup::power(dx, n)};
    }
    static constexpr X unit() {
      auto u = AbelGroup::unit();
      return {u, u, u, u};
    }
    static constexpr bool commute = true;
  };

  vector<tuple<ll, ll, ll, ll>> query;
  Point_Add_Rectangle_Sum<G, SMALL> X;
  ll min_x = 0, min_y = 0;

  void add_query(ll xl, ll yl, ll xr, ll yr, WT w) {
    assert(xl <= xr && yl <= yr);
    min_x = min(min_x, xl);
    min_y = min(min_y, yl);
    // (xl,yl) に (x-xl)(y-yl) を加算
    auto nw = AbelGroup::inverse(w);
    X.add_query(xl, yl,
                {w, AbelGroup::power(w, -yl), AbelGroup::power(w, -xl),
                 AbelGroup::power(w, +xl * yl)});
    // (xl,yr) に (x-xl)(y-yr) を減算
    X.add_query(xl, yr,
                {nw, AbelGroup::power(w, +yr), AbelGroup::power(w, +xl),
                 AbelGroup::power(w, -xl * yr)});
    // (xr,yl) に (x-xr)(y-yl) を減算
    X.add_query(xr, yl,
                {nw, AbelGroup::power(w, +yl), AbelGroup::power(w, +xr),
                 AbelGroup::power(w, -xr * yl)});
    // (xr,yr) に (x-xr)(y-yr) を加算
    X.add_query(xr, yr,
                {w, AbelGroup::power(w, -yr), AbelGroup::power(w, -xr),
                 AbelGroup::power(w, +xr * yr)});
  }

  void sum_query(ll xl, ll yl, ll xr, ll yr) {
    assert(xl <= xr && yl <= yr);
    query.emplace_back(xl, yl, xr, yr);
    X.sum_query(min_x, min_y, xl, yl);
    X.sum_query(min_x, min_y, xl, yr);
    X.sum_query(min_x, min_y, xr, yl);
    X.sum_query(min_x, min_y, xr, yr);
  }

  vector<WT> calc() {
    ll Q = query.size();
    vector<WT> ANS(Q);
    auto tmp = X.calc();

    for (int q = 0; q < Q; ++q) {
      auto [xl, yl, xr, yr] = query[q];
      WT p = AbelGroup::unit(), m = AbelGroup::unit();
      {
        auto [a, b, c, d] = tmp[4 * q + 0];
        p = AbelGroup::op(p, AbelGroup::power(a, xl * yl));
        p = AbelGroup::op(p, AbelGroup::power(b, xl));
        p = AbelGroup::op(p, AbelGroup::power(c, yl));
        p = AbelGroup::op(p, d);
      }
      {
        auto [a, b, c, d] = tmp[4 * q + 1];
        m = AbelGroup::op(m, AbelGroup::power(a, xl * yr));
        m = AbelGroup::op(m, AbelGroup::power(b, xl));
        m = AbelGroup::op(m, AbelGroup::power(c, yr));
        m = AbelGroup::op(m, d);
      }
      {
        auto [a, b, c, d] = tmp[4 * q + 2];
        m = AbelGroup::op(m, AbelGroup::power(a, xr * yl));
        m = AbelGroup::op(m, AbelGroup::power(b, xr));
        m = AbelGroup::op(m, AbelGroup::power(c, yl));
        m = AbelGroup::op(m, d);
      }
      {
        auto [a, b, c, d] = tmp[4 * q + 3];
        p = AbelGroup::op(p, AbelGroup::power(a, xr * yr));
        p = AbelGroup::op(p, AbelGroup::power(b, xr));
        p = AbelGroup::op(p, AbelGroup::power(c, yr));
        p = AbelGroup::op(p, d);
      }
      ANS[q] = AbelGroup::op(p, AbelGroup::inverse(m));
    }
    return ANS;
  }
};
