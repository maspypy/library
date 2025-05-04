namespace CHT {
template <typename T>
struct Line {
  mutable T k, m, p;
  bool operator<(const Line& o) const { return k < o.k; }
  bool operator<(T x) const { return p < x; }
};

template <typename T>
T lc_inf() {
  return numeric_limits<T>::max();
}
template <>
long double lc_inf<long double>() {
  return 1 / .0;
}

template <typename T>
T lc_div(T a, T b) {
  return a / b - ((a ^ b) < 0 and a % b);
}
template <>
long double lc_div(long double a, long double b) {
  return a / b;
};
template <>
double lc_div(double a, double b) {
  return a / b;
};

template <typename T, bool MINIMIZE = true>
struct LineContainer : multiset<Line<T>, less<>> {
  using super = multiset<Line<T>, less<>>;
  using super::begin, super::end, super::insert, super::erase;
  using super::empty, super::lower_bound;
  T inf = lc_inf<T>();
  bool insect(typename super::iterator x, typename super::iterator y) {
    if (y == end()) return x->p = inf, false;
    if (x->k == y->k)
      x->p = (x->m > y->m ? inf : -inf);
    else
      x->p = lc_div(y->m - x->m, x->k - y->k);
    return x->p >= y->p;
  }
  void add(T k, T m) {
    if (MINIMIZE) { k = -k, m = -m; }
    auto z = insert({k, m, 0}), y = z++, x = y;
    while (insect(y, z)) z = erase(z);
    if (x != begin() and insect(--x, y)) insect(x, y = erase(y));
    while ((y = x) != begin() and (--x)->p >= y->p) insect(x, erase(y));
  }
  T query(T x) {
    assert(!empty());
    auto l = *lower_bound(x);
    T v = (l.k * x + l.m);
    return (MINIMIZE ? -v : v);
  }
};
}; // namespace CHT

using namespace CHT;
template <typename T>
using CHT_min = LineContainer<T, true>;
template <typename T>
using CHT_max = LineContainer<T, false>;

/*
long long / double で動くと思う。クエリあたり O(log N)
・add(a, b, i=-1)：ax + by の追加 (index=i)
・get_max(x,y)：(ax + by,i)
・get_min(x,y)：(ax + by,i)
*/
template <typename T>
struct CHT_xy {
  static_assert(is_same_v<T, ll> || std::is_floating_point_v<T>);
  using ld = long double;
  CHT_min<ld> cht_min;
  CHT_max<ld> cht_max;
  T amax = -infty<T>, amin = infty<T>;
  T bmax = -infty<T>, bmin = infty<T>;
  int amax_idx = -1, amin_idx = -1;
  int bmax_idx = -1, bmin_idx = -1;
  bool empty = true;
  map<pair<T, T>, int> MP;

  void clear() {
    empty = true;
    cht_min.clear();
    cht_max.clear();
  }
  void add(T a, T b, int i = -1) {
    empty = false;
    cht_min.add(b, a);
    cht_max.add(b, a);
    pair<T, T> p = {a, b};
    MP[p] = i;

    if (chmax(amax, a)) amax_idx = i;
    if (chmin(amin, a)) amin_idx = i;
    if (chmax(bmax, b)) bmax_idx = i;
    if (chmin(bmin, b)) bmin_idx = i;
  }

  // max, idx
  pair<T, int> get_max(T x, T y) {
    if (cht_min.empty()) return {-infty<T>, -1};

    if (x == 0) {
      if (bmax * y > bmin * y) { return {bmax * y, bmax_idx}; }
      return {bmin * y, bmin_idx};
    }
    ld z = ld(y) / x;
    if (x > 0) {
      auto l = cht_max.lower_bound(z);
      T a = l->m, b = l->k;
      pair<T, T> p = {a, b};
      int idx = MP[p];
      return {a * x + b * y, idx};
    }
    auto l = cht_min.lower_bound(z);
    T a = -(l->m), b = -(l->k);
    pair<T, T> p = {a, b};
    int idx = MP[p];
    return {a * x + b * y, idx};
  }

  // min, idx
  pair<T, int> get_min(T x, T y) {
    auto [f, i] = get_max(-x, -y);
    return {-f, i};
  }
};
