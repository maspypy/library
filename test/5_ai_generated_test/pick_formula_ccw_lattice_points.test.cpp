#include "my_template.hpp"
#include "geo/base.hpp"
#include "geo/pick_formula.hpp"

// 反時計回りの単純な格子多角形だけを渡す。境界点は線分上判定、
// 内点は水平半直線との交差の偶奇で数え、Pick の公式や gcd は使わない。
// 面積は生成元の三角形・長方形・欠けた長方形の面積と変換の行列式で求める。
// 凹頂点、水平辺、同一直線上の連続辺、斜めの格子辺、巨大な平行移動も確認する。

namespace {
using P = Point<ll>;

tuple<i128, i128, i128> enumerate_points(const vc<P>& a, i128 area2) {
  ll xmin = a[0].x, xmax = xmin, ymin = a[0].y, ymax = ymin;
  for (P p : a) {
    xmin = min(xmin, p.x), xmax = max(xmax, p.x);
    ymin = min(ymin, p.y), ymax = max(ymax, p.y);
  }

  i128 inner = 0, boundary = 0;
  for (ll x = xmin; x <= xmax; ++x) {
    for (ll y = ymin; y <= ymax; ++y) {
      bool inside = false, on_edge = false;
      for (size_t i = 0; i < a.size(); ++i) {
        P p = a[i], q = a[(i + 1) % a.size()];
        if (p.y > q.y) swap(p, q);
        i128 side = (i128(q.x) - p.x) * (i128(y) - p.y)
                  - (i128(q.y) - p.y) * (i128(x) - p.x);
        if (side == 0 && min(p.x, q.x) <= x && x <= max(p.x, q.x)
                      && p.y <= y && y <= q.y) {
          on_edge = true;
          break;
        }
        // 上側端点を除外し、頂点を通る半直線での二重カウントを防ぐ。
        if (p.y <= y && y < q.y && side > 0) inside = !inside;
      }
      boundary += on_edge;
      inner += !on_edge && inside;
    }
  }
  return {area2, inner, boundary};
}

void test_polygon(vc<P> points, tuple<i128, i128, i128> want, int id) {
  auto got = pick_formula(points);
  if (got == want) return;
  cerr << "pick_formula mismatch at case " << id << ':';
  for (P p : points) cerr << " (" << p.x << ',' << p.y << ')';
  cerr << "; area2/inner/boundary agreement = "
       << (get<0>(got) == get<0>(want)) << '/'
       << (get<1>(got) == get<1>(want)) << '/'
       << (get<2>(got) == get<2>(want)) << '\n';
  abort();
}
}  // namespace

int main() {
  int id = 0;
  const array<array<ll, 4>, 4> matrices{{
      {1, 0, 0, 1}, {1, 2, -1, 1}, {0, -2, 1, 1}, {-2, 1, -1, -1}
  }};
  constexpr ll big = 4'000'000'000'000'000'000LL;
  auto check = [&](const vc<P>& shape, ll base_area2) {
    for (auto [a, b, c, d] : matrices) {
      for (auto [sx, sy] : {pair<ll, ll>{-13, 11}, {big, -big}, {-big, big}}) {
        vc<P> poly;
        for (P p : shape) poly.emplace_back(a * p.x + b * p.y + sx,
                                             c * p.x + d * p.y + sy);
        rotate(poly.begin(), poly.begin() + (id % poly.size()), poly.end());
        test_polygon(poly, enumerate_points(poly, base_area2 * (a*d - b*c)), id++);
      }
    }
  };

  for (ll w = 1; w <= 5; ++w) {
    for (ll h = 1; h <= 5; ++h) {
      check({{0, 0}, {w, 0}, {0, h}}, w*h);
      for (ll cut_x = 1; cut_x < w; ++cut_x) {
        check({{0, 0}, {cut_x, 0}, {w, 0}, {w, h}, {0, h}}, 2*w*h);
        for (ll cut_y = 1; cut_y < h; ++cut_y) {
          check({{0, 0}, {w, 0}, {w, cut_y}, {cut_x, cut_y}, {cut_x, h}, {0, h}},
                2*(w*h - (w-cut_x)*(h-cut_y)));
        }
      }
    }
  }

  // 内点数と面積が 64 bit に収まらないケース。長方形だけは閉形式で検査する。
  constexpr ll w = 4'000'000'001LL, h = 4'000'000'003LL;
  test_polygon({{-big, big}, {-big+w, big}, {-big+w, big+h}, {-big, big+h}},
               {2*i128(w)*h, i128(w-1)*(h-1), 2*i128(w+h)}, id++);
  cout << "pick_formula: " << id << " cases passed\n";
}
