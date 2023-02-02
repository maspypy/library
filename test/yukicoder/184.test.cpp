#define PROBLEM "https://yukicoder.me/problems/no/184"
#include "my_template.hpp"
#include "other/io.hpp"
#include "alg/monoid/merge_vector_space.hpp"

void solve() {
  LL(N);
  VEC(ll, A, N);
  using Mono = Merge_Vector_Space<u64>;
  using SP = typename Mono::value_type;
  SP X;
  for (auto&& a: A) { X.add_element(a); }
  print(1LL << len(X));
}

signed main() {
  solve();
  return 0;
}
