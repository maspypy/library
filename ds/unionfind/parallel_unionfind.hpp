#include "mod/modint61.hpp"
#include "random/base.hpp"

struct Parallel_UnionFind {
  int n, log;
  using mint = modint61;
  vc<mint> seg;
  vc<mint> pow;
  mint base;
  vc<int> dat;
  vc<int> nxt;

  Parallel_UnionFind(int n) : n(n), dat(n, -1), nxt(n, -1) {
    log = 1;
    while ((1 << log) < n) ++log;
    base = RNG(mint::get_mod());
    pow.resize(1 << log);
    pow[0] = 1;
    FOR(i, (1 << log) - 1) pow[i + 1] = pow[i] * base;
    seg.resize(2 << log);
    FOR(i, n) seg[i + (1 << log)] = i;
    FOR_R(i, 1, (1 << log)) update(i);
  }

  int operator[](int x) { return (dat[x] < 0 ? x : dat[x]); }
  int size(int x) {
    assert(dat[x] < 0);
    return -dat[x];
  }

  // unite [a,b) [c,d).
  // f(v, y, x): root(v) = y -> root(v) = x
  template <typename F>
  void merge(
      int a, int b, int c, int d, F f = [](int v, int y, int x) -> void {}) {
    assert(0 <= a && a <= b && b <= n);
    assert(0 <= c && c <= d && d <= n);
    assert(b - a == d - c);
    while (1) {
      if (get(a, b) == get(c, d)) break;
      int n = binary_search(
          [&](int k) -> bool { return get(a, a + k) == get(c, c + k); }, 0,
          b - a, false);
      int x = (*this)[a + n], y = (*this)[c + n];
      a += n, c += n;
      if (size(x) < size(y)) swap(x, y);
      // 成分 y を成分 x にマージ
      while (nxt[y] != -1) {
        int v = nxt[y];
        nxt[y] = nxt[v];
        set(v, x), f(v, y, x);
        dat[v] = x, dat[x] -= 1, nxt[v] = nxt[x], nxt[x] = v;
      }
      set(y, x), f(y, y, x);
      dat[y] = x, dat[x] -= 1, nxt[y] = nxt[x], nxt[x] = y;
    }
  }

  template <typename F>
  void merge(
      int a, int b, F f = [](int v, int y, int x) -> void {}) {
    merge(a, a + 1, b, b + 1, f);
  }

private:
  void update(int i) {
    int sz = 1 << (log - topbit(i) - 1);
    seg[i] = seg[2 * i] * pow[sz] + seg[2 * i + 1];
  }

  void set(int i, mint x) {
    assert(i < n);
    seg[i += (1 << log)] = x;
    while (i >>= 1) update(i);
  }

  mint get(int L, int R) {
    assert(0 <= L && L <= R && R <= n);
    mint xl = 0, xr = 0;
    int sl = 0, sr = 0;
    L += (1 << log), R += (1 << log);
    int s = 1;
    while (L < R) {
      if (L & 1) { xl = xl * pow[s] + seg[L++], sl += s; }
      if (R & 1) { xr = seg[--R] * pow[sr] + xr, sr += s; }
      L >>= 1, R >>= 1, s <<= 1;
    }
    return xl * pow[sr] + xr;
  }
};
