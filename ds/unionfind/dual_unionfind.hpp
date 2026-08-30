// component apply, point get, O(log N)
template <typename Monoid>
struct Dual_UnionFind {
  using MA = Monoid;
  using A = typename MA::value_type;

  int N, n_comp;
  vc<int> dat;  // parent or (-size)
  vc<A> val;

  Dual_UnionFind(int N = 0) { build(N); }

  void build(int n) {
    N = n;
    n_comp = N;
    dat.assign(N, -1);
    val.assign(N, MA::id());
    dat.reserve(2 * N);
    val.reserve(2 * N);
  }

  vc<int> buf;
  int root(int x) {
    buf.clear();
    int r = x;
    while (dat[r] >= 0) {
      buf.eb(r);
      r = dat[r];
    }

    A prod = MA::id();
    FOR_R(i, len(buf)) {
      int v = buf[i];
      prod = val[v] = MA::op(val[v], prod);
      dat[v] = r;
    }
    return r;
  }

  int operator[](int x) { return root(x); }

  bool same(int x, int y) { return root(x) == root(y); }

  int size(int x) {
    x = root(x);
    return -dat[x];
  }

  bool merge(int x, int y) {
    x = root(x), y = root(y);
    if (x == y) return false;

    int z = len(dat);
    int sz = -dat[x] - dat[y];

    dat[x] = z, dat[y] = z;
    dat.eb(-sz);
    val.eb(MA::id());
    --n_comp;
    return true;
  }

  void apply(int x, const A& a) {
    x = root(x);
    val[x] = MA::op(val[x], a);
  }

  A get(int x) {
    int r = root(x);
    if (x == r) return val[r];
    return MA::op(val[x], val[r]);
  }
};