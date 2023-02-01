#include "ds/fenwicktree/fenwicktree.hpp"

template <typename AbelGroup, typename XY, bool SMALL_X = false>
struct Rectangle_Add_Point_Sum {
  using G = typename AbelGroup::value_type;
  vector<tuple<XY, XY, XY, G>> rect;
  vector<tuple<int, XY, XY>> point;

  Rectangle_Add_Point_Sum() {}

  void add_query(XY x1, XY x2, XY y1, XY y2, G g) {
    rect.eb(y1, x1, x2, g), rect.eb(y2, x2, x1, g);
  }
  void sum_query(XY x, XY y) { point.eb(len(point), x, y); }

  vector<G> calc() {
    int N = rect.size(), Q = point.size();
    if (N == 0 || Q == 0) return vector<G>(Q, AbelGroup::unit());
    // X 方向の座圧
    int NX = 0;
    if (!SMALL_X) {
      sort(all(point),
           [&](auto &x, auto &y) -> bool { return get<1>(x) < get<1>(y); });
      vc<XY> keyX;
      keyX.reserve(Q);
      for (auto &&[i, a, b]: point) {
        if (len(keyX) == 0 || keyX.back() != a) { keyX.eb(a); }
        a = len(keyX) - 1;
      }
      for (auto &&[y, x1, x2, g]: rect) x1 = LB(keyX, x1), x2 = LB(keyX, x2);
      NX = len(keyX);
    }
    if (SMALL_X) {
      XY mx = INF<XY>;
      for (auto &&[i, x, y]: point) chmin(mx, x);
      for (auto &&[i, x, y]: point) x -= mx, chmax(NX, x + 1);
      for (auto &&[y, x1, x2, g]: rect) {
        x1 -= mx, x2 -= mx;
        x1 = max(0, min<int>(x1, NX)), x2 = max(0, min<int>(x2, NX));
      }
    }

    sort(all(point),
         [&](auto &x, auto &y) -> bool { return get<2>(x) < get<2>(y); });
    sort(all(rect),
         [&](auto &x, auto &y) -> bool { return get<0>(x) < get<0>(y); });
    FenwickTree<AbelGroup> bit(NX);
    vc<G> res(Q, AbelGroup::unit());
    int j = 0;
    FOR(i, Q) {
      auto [q, x, y] = point[i];
      while (j < N && get<0>(rect[j]) <= y) {
        auto [yy, x1, x2, g] = rect[j++];
        bit.add(x1, g), bit.add(x2, AbelGroup::inverse(g));
      }
      res[q] = bit.sum(x + 1);
    }
    return res;
  }
};