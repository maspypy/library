#include "enumerate/product.hpp"
#include "graph/prufer_code.hpp"

template <typename F>
void enumerate_labeled_tree(int N, F f) {
  if (N == 1) {
    Graph<int, 0> G(N);
    f(G);
    return;
  }
  enumerate_product(vc<int>(N - 2, N), [&](vc<int> A) -> void {
    Graph<int, 0> G = from_prufer_code(A);
    f(G);
  });
}
