#include "nt/prime_table.hpp"

template <typename T>
void divisor_zeta(vc<T>& A) {
  assert(A[0] == 0);
  int N = len(A) - 1;
  auto P = prime_table(N);
  for (auto&& p : P) {
    FOR3(x, 1, N / p + 1) A[p * x] += A[x];
  }
}

template <typename T>
void divisor_mobius(vc<T>& A) {
  assert(A[0] == 0);
  int N = len(A) - 1;
  auto P = prime_table(N);
  for (auto&& p : P) {
    FOR3_R(x, 1, N / p + 1) A[p * x] -= A[x];
  }
}

template <typename T>
void multiple_zeta(vc<T>& A) {
  assert(A[0] == 0);
  int N = len(A) - 1;
  auto P = prime_table(N);
  for (auto&& p : P) {
    FOR3_R(x, 1, N / p + 1) A[x] += A[p * x];
  }
}

template <typename T>
void multiple_mobius(vc<T>& A) {
  assert(A[0] == 0);
  int N = len(A) - 1;
  auto P = prime_table(N);
  for (auto&& p : P) {
    FOR3(x, 1, N / p + 1) A[x] -= A[p * x];
  }
}
