#include "alg/monoid/add.hpp"

// Wavelet Matrix 上でさらに累積和を管理して、矩形和がとれるようにしたもの
// 和は、変換関数 f を渡して、f(x) の可換群に関する和
template <typename T, typename Monoid = Monoid_Add<T>>
struct Wavelet_Matrix_Sum {
  using G = Monoid;
  using GT = typename G::value_type;
  static_assert(G::commute);
  struct BitVector {
    vector<u64> buf;
    vector<int> sum;
    BitVector(const vector<char>& a = {}) {
      int n = a.size();
      buf.assign((n + 63) >> 6, 0);
      sum.assign(buf.size() + 1, 0);
      FOR(i, n) if (a[i]) {
        buf[i >> 6] |= 1ull << (i & 63);
        sum[(i >> 6) + 1]++;
      }
      FOR(i, buf.size()) sum[i + 1] += sum[i];
    }
    int rank(int k, bool f = 1) {
      int ret = sum[k >> 6]
                + __builtin_popcountll(buf[k >> 6] & ((1ull << (k & 63)) - 1));
      if (!f)
        return k - ret;
      else
        return ret;
    }
  };

  int N, lg;
  vector<int> mid;
  vector<BitVector> bv;
  vector<vector<GT>> cumsum;
  vc<T> key;

  template <typename F>
  Wavelet_Matrix_Sum(
      vector<T>& dat, F f = [](T x) -> GT { return x; })
      : N(dat.size()) {
    key = dat;
    UNIQUE(key);
    vc<int> A(N);
    FOR(i, N) A[i] = LB(key, dat[i]);
    lg = __lg(max(MAX(A), 1)) + 1;

    mid.resize(lg);
    bv.resize(lg);
    cumsum.resize(lg);
    for (int d = lg - 1; d >= 0; d--) {
      vector<char> add;
      vector nxt(2, vector<int>());
      for (auto& x: A) {
        add.push_back(x >> d & 1);
        nxt[x >> d & 1].push_back(x);
      }
      mid[d] = (int)nxt[0].size();
      bv[d] = BitVector(add);
      swap(A, nxt[0]);
      A.insert(A.end(), all(nxt[1]));
      vc<GT> cs(N + 1);
      cs[0] = G::unit();
      FOR(i, N) cs[i + 1] = G::op(cs[i], f(key[A[i]]));
      cumsum[d] = cs;
    }
  }

  // [L, R) 内にある [a, b) を数える
  int freq(int L, int R, T a, T b) {
    return freq_upper(L, R, b) - freq_upper(L, R, a);
  }
  int freq_upper(int L, int R, T t) {
    int x = LB(key, t);
    if (x >= (1 << lg)) return R - L;
    int ret = 0;
    for (int h = lg - 1; h >= 0; --h) {
      bool f = (x >> h) & 1;
      if (f) ret += bv[h].rank(R, 0) - bv[h].rank(L, 0);
      L = bv[h].rank(L, f) + (f ? mid[h] : 0);
      R = bv[h].rank(R, f) + (f ? mid[h] : 0);
    }
    return ret;
  }

  // [L, R) の中で k>=0 番目
  T kth(int L, int R, int k) {
    assert(0 <= k && k < R - L);
    int ret = 0;
    for (int h = lg - 1; h >= 0; h--) {
      int l0 = bv[h].rank(L, 0), r0 = bv[h].rank(R, 0);
      if (k < r0 - l0)
        L = l0, R = r0;
      else {
        k -= r0 - l0;
        ret |= 1 << h;
        L += mid[h] - l0, R += mid[h] - r0;
      }
    }
    return key[ret];
  }

  // [L, R) の中で小さい方から k 個の総和
  T sum_by_count(int L, int R, int k) {
    assert(0 <= k && k <= R - L);
    T pos = G::unit(), neg = G::unit();
    for (int h = lg - 1; h >= 0; h--) {
      int l0 = bv[h].rank(L, 0), r0 = bv[h].rank(R, 0);
      if (k < r0 - l0) {
        L = l0, R = r0;
      } else {
        k -= r0 - l0;
        pos = G::op(pos, cumsum[h][r0]);
        neg = G::op(neg, cumsum[h][l0]);
        L += mid[h] - l0, R += mid[h] - r0;
      }
    }
    if (k) {
      pos = G::op(pos, cumsum[0][L + k]);
      neg = G::op(neg, cumsum[0][L]);
    }
    return G::op(pos, G::inverse(neg));
  }

  // [L, R) の中で value 未満のものの和
  T sum_by_value(int L, int R, T value) {
    int x = LB(key, value);
    T pos = G::unit(), neg = G::unit();
    for (int h = lg - 1; h >= 0; h--) {
      bool f = (x >> h) & 1;
      int l0 = bv[h].rank(L, 0), r0 = bv[h].rank(R, 0);
      if (f) {
        pos = G::op(pos, cumsum[h][r0]);
        neg = G::op(neg, cumsum[h][l0]);
      }
      L = bv[h].rank(L, f) + (f ? mid[h] : 0);
      R = bv[h].rank(R, f) + (f ? mid[h] : 0);
    }
    return G::op(pos, G::inverse(neg));
  }
};
