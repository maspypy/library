// B, blocks
template <typename BLOCK>
pair<int, vc<BLOCK>> SQRT_Decomposition(int N, int b_sz = -1) {
  int BS, BN; // block size, num
  vc<BLOCK> blocks;
  if (b_sz == -1) b_sz = sqrt(N);
  BS = b_sz, BN = ceil(N, BS);
  blocks.reserve(BN);
  FOR(i, BN) {
    int L = BS * i, R = BS * (i + 1);
    blocks.eb(BLOCK(L, min(R, N)));
  }
  return {BS, blocks};
}

// B, blocks
template <typename BLOCK, typename X>
pair<int, vc<BLOCK>> SQRT_Decomposition(vc<X>& A, int b_sz = -1) {
  int N = len(A);
  int BS, BN; // block size, num
  vc<BLOCK> blocks;
  if (b_sz == -1) b_sz = sqrt(N);
  BS = b_sz, BN = ceil(N, BS);
  blocks.reserve(BN);
  FOR(i, BN) {
    int L = BS * i, R = BS * (i + 1);
    chmin(R, N);
    blocks.eb(BLOCK(A, L, R));
  }
  return {BS, blocks};
}

/*
struct Block {
  // 作用素
  using A = ;
  const A unit = ;
  static A op(const A& a, const A& b) {
    // 実装
  }

  // 列のデータ
  using X = ;
  static X act(const X& x, const A& a) {
    // 実装
  }

  //
  int N, off;
  A lazy;
  vc<X> dat;

  // クエリに答える用のデータを追加で持つ
  // 実装

  Block(int L, int R) : N(R - L), off(L), lazy(unit), dat(N) { build(); }
  Block(vc<X>& xs, int L, int R)
      : N(R - L), off(L), lazy(unit), dat(xs.begin() + L, xs.begin() + R) {
    build();
  }

  // 全要素に lazy を反映し、lazy を単位元に戻す
  void push() {
    if (lazy == unit) return;
    for (auto&& x: dat) { x = act(x, lazy); }
    lazy = unit;
  }

  // クエリに答える用のデータを正しくする
  // これが呼ばれた時点で、lazy == unit が保証される
  void build() {
    assert(lazy == unit);
    // 実装
  }

  void set(int i, X x) {
    i -= off;
    assert(0 <= i && i < N);
    push();
    dat[i] = x;
    build();
  }

  void apply(int l, int r, A a) {
    l = max(0, l - off), r = min(N, r - off);
    if (l >= r) return;
    if (r - l == N) {
      lazy = op(lazy, a);
      return;
    }
    a = op(lazy, a);
    FOR(i, l) dat[i] = act(dat[i], lazy);
    FOR(i, l, r) dat[i] = act(dat[i], a);
    FOR(i, r, N) dat[i] = act(dat[i], lazy);
    lazy = unit;
    build();
  }

  int query(int l, int r) {
    l = max(0, l - off), r = min(N, r - off);
    if (l >= r) return 0;
    if (r - l == N) {
      // lazy と追加データを使ってクエリに答える
      // 実装
    }
    // 要素ごとに見ることでクエリに答える
    int ans = 0;
    FOR(i, l, r) {
      X x = act(dat[i], lazy);
      // 実装
    }
    return ans;
  }
};
*/