// Wavelet Matrix 上でさらに累積和を管理して、矩形和がとれるようにしたもの
template <typename T>
struct Wavelet_Matrix {
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
  vc<T> key;

  template <typename F>
  Wavelet_Matrix(
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
};
