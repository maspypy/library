// Source: https://github.com/maspypy/library/blob/main/enumerate/permutation.hpp
// f(A, end)
template <typename F>
void enumerate_permutation(int N, F f) {
  bool end = false;
  vc<int> A(N);
  FOR(i, N) A[i] = i;
  do {
    f(A, end);
    if (end) break;
  } while (next_permutation(all(A)));
}