#define PROBLEM "https://yukicoder.me/problems/no/1234"

#include "my_template.hpp"
#include "other/io.hpp"
#include "ds/sqrt_decompotision.hpp"

struct Block {
  // 作用素
  using A = ll;
  const A unit = 0;
  static A op(const A& a, const A& b) { return a + b; }

  // 列のデータ
  using X = ll;
  static X act(const X& x, const A& a) { return x + a; }

  //
  int N, off;
  A lazy;
  vc<X> dat;

  // クエリに答える用のデータを追加で持つ
  X mi;

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
    mi = MIN(dat);
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

  ll query(int l, int r) {
    l = max(0, l - off), r = min(N, r - off);
    if (l >= r) return infty<ll>;
    if (r - l == N) {
      // lazy と追加データを使ってクエリに答える
      return lazy + mi;
    }
    // 要素ごとに見ることでクエリに答える
    ll ans = infty<ll>;
    FOR(i, l, r) {
      X x = act(dat[i], lazy);
      chmin(ans, x);
    }
    return ans;
  }
};

void solve() {
  LL(N);
  VEC(ll, A, N);
  auto [B, BLK] = SQRT_Decomposition<Block>(A);
  LL(Q);
  FOR(Q) {
    LL(t, l, r, x);
    --l;
    if (t == 1) {
      for (auto&& blk: BLK) blk.apply(l, r, x);
    }
    if (t == 2) {
      ll mi = infty<ll>;
      for (auto&& blk: BLK) chmin(mi, blk.query(l, r));
      print(mi);
    }
  }
}

signed main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  cout << setprecision(15);

  ll T = 1;
  // LL(T);
  FOR(T) solve();

  return 0;
}
