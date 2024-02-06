
// 折角なので作ってみたが，使わなさそう
template <typename Monoid>
struct SQRT_Tree {
  using MX = Monoid;
  using X = typename MX::value_type;

  static constexpr int K = 3;
  static constexpr u32 SZ[] = {8, 64, 4096};
  static constexpr u32 MASK[] = {7, 63, 4095};

  int N;
  // 元となる静的な列
  vc<X> A;
  // 各階層に対して，ブロック先頭からある要素まで [s,i]
  // 各階層に対して，ある要素からブロック末尾まで [i,t]
  vvc<X> PREF, SUFF;
  // 各階層に対して，あるブロックからあるブロックまで
  vvc<X> BETWEEN;

  SQRT_Tree() {}
  template <typename F>
  SQRT_Tree(int n, F f) {
    build(n, f);
  }
  SQRT_Tree(const vc<X>& v) {
    build(len(v), [&](int i) -> X { return v[i]; });
  }

  template <typename F>
  void build(int n_, F f) {
    N = n_;
    assert(N <= (1 << 24));
    A.reserve(N);
    FOR(i, N) A.eb(f(i));
    // まず prefix, suffix の構築
    PREF.assign(K, A), SUFF.assign(K, A);
    FOR(k, K) {
      FOR(i, N) {
        if (i & MASK[k]) PREF[k][i] = MX::op(PREF[k][i - 1], A[i]);
      }
      FOR_R(i, N) {
        if (i & MASK[k]) SUFF[k][i - 1] = MX::op(A[i - 1], SUFF[k][i]);
      }
    }
    // between の構築
    BETWEEN.resize(K);
    FOR(k, K) {
      // n : 全体の小ブロックの個数
      auto get = [&](int i) -> X { return SUFF[k][SZ[k] * i]; };
      int n = N / SZ[k];
      int s = 0;
      FOR(r, n) {
        if (r % SZ[k] == 0) s = r;
        BETWEEN[k].eb(get(r));
        FOR_R(l, s, r) { BETWEEN[k].eb(MX::op(get(l), BETWEEN[k].back())); }
      }
    }
  }

  static constexpr int BIT_TO_LAYER[] = {0, 0, 0, 1, 1, 1, 2, 2, 2, 2, 2, 2,
                                         3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3};

  X prod(int L, int R) {
    assert(0 <= L && L <= R && R <= N);
    if (L == R) return MX::unit();
    if (L + 1 == R) return A[L];
    --R;
    int k = BIT_TO_LAYER[topbit(L ^ R)];
    if (k == 0) {
      // 長さ SZ[0] のブロックにクエリが収まっている. 愚直に.
      X x = A[L];
      FOR(i, L + 1, R + 1) x = MX::op(x, A[i]);
      return x;
    }
    --k;
    // 同じ長さ SZ[k+1] のブロック内にある. 違う SZ[k] ブロック内にある.
    u32 a = L / SZ[k], b = R / SZ[k];
    assert(a < b);
    X &x1 = SUFF[k][L], &x2 = PREF[k][R];
    if (a + 1 == b) return MX::op(x1, x2);
    ++a, --b;
    // [a,b] 番目の SZ[k]-block の間を取得する
    // BETWEEN のどこにデータが置いてあるか調べる
    u32 m = a / SZ[k];
    a &= MASK[k], b &= MASK[k];
    u32 idx = m * (SZ[k] / 2) * (SZ[k] + 1);
    idx += (b + 1) * (b + 2) / 2 - 1 - a;
    return MX::op(x1, MX::op(BETWEEN[k][idx], x2));
  }
};