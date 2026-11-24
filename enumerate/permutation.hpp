// f(A, end)
template <typename F>
void enumerate_partition(int N, F f) {
  bool end = false;
  vc<int> A(N);
  FOR(i, N) A[i] = i;
  do {
    f(A, end);
    if (end) break;
  } while (next_permutation(all(A)));
}