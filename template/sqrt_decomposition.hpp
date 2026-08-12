// template/sqrt_decomposition.hpp
struct Block {
  int N, off;
  vc<int> A;

  Block(vc<int>& B, int L, int R) : N(R - L), off(L) {
    A = {B.begin() + L, B.begin() + R};
  }

  void apply(int l, int r, int x) {
    l -= off, r -= off;
    chmax(l, 0), chmin(r, N);
    if (l >= r) return;  // l==r としないように
    if (r - l != N) {
    }
    assert(r - l == N);
  }

  int query(int l, int r) {
    l -= off, r -= off;
    chmax(l, 0), chmin(r, N);
    if (l >= r) return 0;  // l==r としないように
    if (r - l == N) {
    }
    FOR(i, l, r) {}
  }
};

// void solve() {
//   int b_sz = sqrt(N);
//   int b_num = ceil<int>(N, b_sz);
//   vc<Block> BLOCK;
//   FOR(b, b_num) {
//     int L = b_sz * b;
//     int R = min<int>(L + b_sz, N);
//     BLOCK.eb(Block(A, L, R));
//   }
// }
