#define PROBLEM \
  "https://judge.yosupo.jp/problem/intersection_of_f2_vector_spaces"
#include "my_template.hpp"
#include "other/io.hpp"

#include "linalg/xor/vector_space.hpp"

using SP = Vector_Space<u32, 32>;

void solve() {
  auto get = [&]() -> SP {
    INT(n);
    SP V;
    FOR(n) {
      U32(a);
      V.add_element(a);
    }
    return V;
  };
  auto x = get(), y = get();
  x = SP::intersection(x, y);
  auto basis = x.to_vec();
  print(len(basis), basis);
}

signed main() {
  INT(T);
  FOR(T) solve();
}