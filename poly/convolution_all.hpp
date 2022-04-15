#include "poly/convolution.hpp"

template<typename T>
vc<T> convolution_all(vc<vc<T>>& polys){
  auto deq = deque<vc<T>>(all(polys));
  while (len(deq) > 1) {
    auto f = deq.front();
    deq.pop_front();
    auto g = deq.front();
    deq.pop_front();
    deq.eb(convolution(f, g));
  }
  return deq.front();
}