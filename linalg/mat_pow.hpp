#include "linalg/mat_mul.hpp"
template<typename T>
vc<vc<T>> mat_pow(vc<vc<T>> A, ll n){
  int N = len(A);
  vv(T, ret, N, N);
  FOR(i, N) ret[i][i] = T(1);
  while(n){
    if(n & 1) ret = mat_mul(ret, A);
    n /= 2;
    if(n) A = mat_mul(A, A);
  }
  return ret;
}