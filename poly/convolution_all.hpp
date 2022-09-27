#pragma once

#include "poly/convolution.hpp"

template <typename T>
vc<T> convolution_all(vc<vc<T>>& polys) {
  if (len(polys) == 0) return {T(1)};
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