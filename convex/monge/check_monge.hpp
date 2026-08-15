
// check Monge property on [0, N]:
// f(a,d) + f(b,c) >= f(a,c) + f(b,d) for a < b < c < d
template <typename T, typename F>
bool check_monge(int N, F f) {
  FOR(d, N + 1) FOR(c, d) FOR(b, c) FOR(a, b) {
    T lhs = f(a, d) + f(b, c);
    T rhs = f(a, c) + f(b, d);
    if (lhs < rhs) {
      print("monge ng");
      print("a,b,c,d = ", a, b, c, d);
      print("f(a, d)=", f(a, d));
      print("f(b, c)=", f(b, c));
      print("f(a, c)=", f(a, c));
      print("f(b, d)=", f(b, d));
      return false;
    }
  }
  return true;
}
