template <typename Monoid, typename X = typename Monoid::value_type>
vector<X> all_but_one_products(const vc<X>& A) {
  int N = len(A);
  vc<X> res(N, Monoid::unit());
  FOR(i, N - 1) res[i + 1] = Monoid::op(res[i], A[i]);
  X x = Monoid::unit();
  FOR_R(i, N) {
    res[i] = Monoid::op(res[i], x);
    x = Monoid::op(A[i], x);
  }
  return res;
}
