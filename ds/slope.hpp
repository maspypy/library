
template <typename T>
struct Slope_Trick_1 {
  static constexpr T LMIN = numeric_limits<T>::lowest();
  static constexpr T RMAX = numeric_limits<T>::max();
  pq<T> que_l;
  pqg<T> que_r;
  T add_l, add_r;
  T min_f;

  Slope_Trick_1() : add_l(0), add_r(0), min_f(0) {}
  Slope_Trick_1(vc<T> left, vc<T> right)
      : que_l(all(left)), que_r(all(right)), add_l(0), add_r(0), min_f(0) {}

  int size() { return len(que_l) + len(que_r); }
  tuple<T, T, T> get_min() { return {top_L(), top_R(), min_f}; }

  void add_const(T a) { min_f += a; }

  // (a-x)+
  void add_a_minus_x(T a) {
    min_f += max(T(0), a - top_R());
    push_R(a), push_L(pop_R());
  }
  // (x-a)+
  void add_x_minus_a(T a) {
    min_f += max(T(0), top_L() - a);
    push_L(a), push_R(pop_L());
  }
  // |x-a|
  void add_abs(T a) {
    add_a_minus_x(a);
    add_x_minus_a(a);
  }

  // 増加側を消して、減少側のみにする
  void clear_inc() { que_r = pqg<T>(); }
  // 減少側を消して、増加側のみにする
  void clear_dec() { que_l = pq<T>(); }
  void shift(const T &a) { add_l += a, add_r += a; }

  // g(x) = min_{x-b <= y <= x-a} f(y)
  void sliding_window_minimum(const T &a, const T &b) {
    add_l += a, add_r += b;
  }

  // O(size)
  T eval(T x) {
    T y = min_f;
    for (auto &&l: que_l) { y += max<T>(0, (l + add_l) - x); }
    for (auto &&r: que_r) { y += max<T>(0, x - (r + add_r)); }
  }

  void push_R(const T &x) {
    if (x != RMAX) que_r.emplace(x - add_r);
  }
  void push_L(const T &x) {
    if (x != LMIN) que_l.emplace(x - add_l);
  }
  T top_R() { return (len(que_r) ? que_r.top() + add_r : RMAX); }
  T top_L() { return (len(que_l) ? que_l.top() + add_l : LMIN); }
  T pop_R() {
    T res = top_R();
    if (len(que_r)) que_r.pop();
    return res;
  }
  T pop_L() {
    T res = top_L();
    if (len(que_l)) que_l.pop();
    return res;
  }
};