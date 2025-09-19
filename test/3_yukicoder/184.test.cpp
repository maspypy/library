#define PROBLEM "https://yukicoder.me/problems/no/184"
#include "my_template.hpp"
#include "other/io.hpp"

#include "linalg/xor/vector_space.hpp"

void solve() {
  LL(N);
  VEC(ll, A, N);
  using SP = Vector_Space<u64, 60>;
  SP X;
  for (auto&& a : A) {
    X.add_element(a);
  }
  print(u64(1) << len(X));
}

signed main() {
  solve();
  return 0;
}
