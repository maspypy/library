
// array B[l] := min of B[l,r), or default
// dat[k]: change of B, when r=k -> r=k+1
template <typename T>
vvc<tuple<int, int, T, T>> range_min_change(vc<T> A, T default_val = infty<T>) {
  int N = len(A);
  vvc<tuple<int, int, T, T>> res(N);
  vc<tuple<int, int, T>> stack;
  FOR(i, N) {
    T a = A[i];
    res[i].eb(i, i + 1, default_val, a);
    int p = i;
    while (len(stack)) {
      auto [l, r, x] = stack.back();
      if (x <= a)
        break;
      res[i].eb(l, r, x, a);
      p = l;
      POP(stack);
    }
    stack.eb(p, i + 1, a);
    reverse(all(res[i]));
  }
  return res;
}
