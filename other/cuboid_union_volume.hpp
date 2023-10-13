#include "ds/incremental_rectangle_union.hpp"

// [0,a] x [0,b] x [0,c] の和集合の体積
// https://codeforces.com/contest/815/problem/D
template <typename XYZ, typename T, bool SMALL_X>
T cuboid_union_volume(vc<tuple<XYZ, XYZ, XYZ>> dat) {
  if constexpr (SMALL_X) {
    int mx_x = 0, mx_z = 0;
    for (auto& [x, y, z]: dat) chmax(mx_x, x), chmax(mx_z, z);
    vc<int> ptr(mx_z + 1);
    for (auto& [x, y, z]: dat) ptr[z]++;
    ptr = cumsum<int>(ptr);
    vc<pair<int, int>> rect(len(dat));
    for (auto& [x, y, z]: dat) { rect[ptr[z]++] = {x, y}; }
    T vol = 0;
    Incremental_Rectangle_Union<XYZ, T, true> I(mx_x);
    FOR_R(z, 1, mx_z + 1) {
      FOR(i, ptr[z - 1], ptr[z]) {
        auto [a, b] = rect[i];
        I.add(a, b);
      }
      vol += I.area;
    }
    return vol;
  } else {
    sort(all(dat),
         [&](auto& a, auto& b) -> bool { return get<2>(a) > get<2>(b); });
    XYZ z = infty<XYZ>;
    T vol = 0, area = 0;
    Incremental_Rectangle_Union<XYZ, T, false> I;
    for (auto& [a, b, c]: dat) {
      vol += T(z - c) * area, area = I.add(a, b), z = c;
    }
    vol += z * I.area;
    return vol;
  }
}
