#define PROBLEM \
  "https://judge.yosupo.jp/problem/intersection_of_f2_vector_spaces"
#include "my_template.hpp"
#include "other/io.hpp"

#include "linalg/xor/vector_space.hpp"

using SP = Vector_Space<u32>;

void solve() {
  auto get = [&]() -> SP {
    INT(n);
    VEC(u32, a, n);
    return SP(a, 0);
  };
  auto x = get(), y = get();
  x = SP::intersection(x, y);
  print(x.dim(), x.dat);
}

signed main() {
  INT(T);
  FOR(T) solve();
}