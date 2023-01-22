#include "ds/offline_query/coeffient_query_2d.hpp"

template <typename T, typename XY>
struct Rectangle_Add_Rectangle_Sum {
  Coefficient_Query_2D<2, 2, T, XY> CQ;
  void add_query(XY x1, XY x2, XY y1, XY y2, T w) {
    CQ.add_query(x1, y1, w), CQ.add_query(x1, y2, -w);
    CQ.add_query(x2, y1, -w), CQ.add_query(x2, y2, w);
  }
  void sum_query(XY x1, XY x2, XY y1, XY y2) {
    --x1, --y1, --x2, --y2;
    CQ.sum_query(x1, y1), CQ.sum_query(x1, y2);
    CQ.sum_query(x2, y1), CQ.sum_query(x2, y2);
  }
  vc<T> calc() {
    vc<T> tmp = CQ.calc();
    int Q = len(tmp) / 4;
    vc<T> res(Q);
    FOR(q, Q) {
      res[q] = tmp[4 * q] - tmp[4 * q + 1] - tmp[4 * q + 2] + tmp[4 * q + 3];
    }
    return res;
  }
};