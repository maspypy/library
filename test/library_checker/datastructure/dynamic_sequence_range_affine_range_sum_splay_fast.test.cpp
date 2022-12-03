#define PROBLEM \
  "https://judge.yosupo.jp/problem/dynamic_sequence_range_affine_range_sum"
#include "my_template.hpp"
#include "other/io.hpp"

#include "ds/splaytree/splaytree.hpp"

const int mod = 998244353;

struct Node {
  using value_type = int;
  using operator_type = pair<int, int>;
  using X = value_type;
  using A = operator_type;
  using np = Node *;

  np p, l, r;
  X x, prod;
  A lazy;
  u32 size;
  bool rev;

  static void new_node(np n, const X &x) {
    n->p = n->l = n->r = nullptr;
    n->x = n->prod = x;
    n->lazy = {1, 0};
    n->size = 1;
    n->rev = 0;
  }

  void update() {
    size = 1;
    prod = x;
    if (l) {
      size += l->size;
      prod += l->prod;
      if (prod >= mod) prod -= mod;
    }
    if (r) {
      size += r->size;
      prod += r->prod;
      if (prod >= mod) prod -= mod;
    }
  }

  void prop() {
    if (lazy != A{1, 0}) {
      ll a = lazy.fi, b = lazy.se;
      if (l) {
        l->x = (a * (l->x) + b) % mod;
        l->prod = (a * l->prod + b * l->size) % mod;
        l->lazy = {a * l->lazy.fi % mod, (a * l->lazy.se + b) % mod};
      }
      if (r) {
        r->x = (a * (r->x) + b) % mod;
        r->prod = (a * r->prod + b * r->size) % mod;
        r->lazy = {a * r->lazy.fi % mod, (a * r->lazy.se + b) % mod};
      }
      lazy = {1, 0};
    }
    if (rev) {
      if (l) {
        l->rev ^= 1;
        swap(l->l, l->r);
      }
      if (r) {
        r->rev ^= 1;
        swap(r->l, r->r);
      }
      rev = 0;
    }
  }

  // update, prop 以外で呼ばれるものは、splay 後であることが想定されている。
  // したがってその時点で update, prop 済であることを仮定してよい。
  void apply(const A &aa) {
    ll a = aa.fi, b = aa.se;
    x = (a * x + b) % mod;
    prod = (a * prod + b * size) % mod;
    lazy = {a * lazy.fi % mod, (a * lazy.se + b) % mod};
  }
  void reverse() {
    swap(l, r);
    rev ^= 1;
  }
};

void solve() {
  // size を 2 重に持たせているのを解除する
  SplayTree<Node, 1'000'000> X;

  INT(N, Q);
  VEC(int, dat, N);

  auto root = X.new_node(dat);

  FOR(Q) {
    INT(t);
    if (t == 0) {
      INT(i, x);
      auto [a, b] = X.split(root, i);
      root = X.merge3(a, X.new_node(x), b);
    }
    if (t == 1) {
      INT(i);
      auto [a, b, c] = X.split3(root, i, i + 1);
      root = X.merge(a, c);
    }
    if (t == 2) {
      INT(L, R);
      X.reverse(root, L, R);
    }
    if (t == 3) {
      INT(L, R, b, c);
      X.apply(root, L, R, {b, c});
    }
    if (t == 4) {
      INT(L, R);
      print(X.prod(root, L, R));
    }
  }
}

signed main() {
  solve();
  return 0;
}
