#include "random/base.hpp"
#include "mod/modint61.hpp"

// Faster Deterministic Modular Subset Sum. arXiv preprint arXiv:2012.06062.
// modular subset sum のための、シフト付きセグ木
// shift には 2^(N-k) 時間かかる
struct ShiftTree {
  using M61 = modint61;
  int delta;
  int N, n;
  M61 base;
  vc<M61> dat;
  vc<M61> base_pow;

  ShiftTree(int N, ll base) : delta(0), N(N), n(topbit(N)), base(base) {
    assert(N == (1 << n));
    dat.assign(2 * N, 0);

    base_pow.assign(n, 1);
    base_pow[n - 1] = base;
    FOR_R(i, n - 1) base_pow[i] = base_pow[i + 1] * base_pow[i + 1];
  }

  inline int skew(int k) { return (delta >> (n - k)) & 1; }

  inline int left(int k, int i) {
    int mask = (1 << (k + 1)) - 1;
    return ((2 * i + 0 - skew(k + 1)) & mask) + (1 << (k + 1));
  }

  inline int right(int k, int i) {
    int mask = (1 << (k + 1)) - 1;
    return ((2 * i + 1 - skew(k + 1)) & mask) + (1 << (k + 1));
  }

  inline int parent(int k, int i) {
    int mask = (1 << k) - 1;
    return (((i + skew(k)) & mask) + (1 << k)) / 2;
  }

  inline void update(int k, int i) {
    M61 b = base_pow[k];
    dat[i] = b * dat[left(k, i)] + dat[right(k, i)];
  }

  inline void set(int i, ll x) {
    i = (i + N - delta) % N + N;
    dat[i] = x;
    int k = n;
    while (i != 1) {
      i = parent(k, i);
      --k;
      update(k, i);
    }
  }

  void shift(int k) {
    k %= N;
    if (k < 0) k += N;
    if (k == 0) return;
    int j = lowbit(k);
    delta = (delta + k) % N;
    FOR_R(k, n - j) { FOR3(i, 1 << k, 2 << k) update(k, i); }
  }

  // [a,b) における difference の列挙。output sensitive。
  // T のノード i、Q のノード j が (x,y) を指すとする。
  static void find_differences(vc<int>& res, ShiftTree& T, ShiftTree& Q, int a,
                               int b, int k, int i, int j, int x, int y) {
    if (T.dat[i] == Q.dat[j]) return;
    if (max(a, x) >= min(b, y)) return;
    if (y == x + 1) {
      res.eb(x);
      return;
    }
    int z = (x + y) / 2;
    find_differences(res, T, Q, a, b, k + 1, T.left(k, i), Q.left(k, j), x, z);
    find_differences(res, T, Q, a, b, k + 1, T.right(k, i), Q.right(k, j), z,
                     y);
  }

  static vc<int> diff(ShiftTree& T, ShiftTree& Q, int a, int b) {
    assert(T.N == Q.N);
    vc<int> res;
    find_differences(res, T, Q, a, b, 0, 1, 1, 0, T.N);
    return res;
  }
};

/*
計算量：(|vals| + mod) * log(mod)
・can(x) または [x] で bool を返す。
・restore(x) で復元。
コンストラクタには、(mod, vals) をわたす
*/
template <typename INT>
struct Modular_Subset_Sum {
  int mod;
  vc<INT>& vals;
  vc<int> par;

  Modular_Subset_Sum(int mod, vc<INT>& vals) : mod(mod), vals(vals) {
    for (auto&& x: vals) assert(0 <= x && x < mod);
    par.assign(mod, -1);

    const ll base = RNG(0, (1LL << 61) - 1);

    int k = 1;
    while ((1 << k) < 2 * mod) ++k;

    int L = 1 << k;
    assert(L >= 2 * mod);

    ShiftTree T1(L, base);
    ShiftTree T2(L, base);
    T1.set(0, 1);
    T2.set(0, 1);
    T2.set(L - mod, 1);

    auto bit_rev = [&](int i) -> int {
      int x = 0;
      FOR(k) {
        x = 2 * x + (i & 1);
        i >>= 1;
      }
      return x;
    };

    vc<vi> IDS(L);
    FOR(i, len(vals)) { IDS[vals[i]].eb(i); }

    FOR(i, 1, L) {
      int x = bit_rev(i);
      if (len(IDS[x]) == 0) continue;
      T2.shift(x - T2.delta);
      for (auto&& idx: IDS[x]) {
        auto diff = ShiftTree::diff(T1, T2, 0, mod);
        for (auto&& d: diff) {
          if (can(d)) continue;
          par[d] = idx;
          T1.set(d, 1);
          T2.set((d + x) % L, 1);
          T2.set((L + d + x - mod) % L, 1);
        }
      }
    }
  }

  bool can(int x) {
    if (x >= mod) return false;
    return (x == 0 || par[x] != -1);
  }

  bool operator[](int x) { return can(x); }
  vc<int> restore(int x) {
    assert(can(x));
    vc<int> res;
    while (x) {
      int i = par[x];
      res.eb(i);
      x -= vals[i];
      if (x < 0) x += mod;
    }
    reverse(all(res));
    return res;
  }
};
