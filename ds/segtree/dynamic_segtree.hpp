#include "alg/default_prod.hpp"

/*
要素数の管理が面倒なので, vector<int> を使うようにした.
参照を持っているときに eb が入ると破壊されることに気を付ける必要がある！
*/
template <typename Monoid, bool PERSISTENT,
          class DefaultProd = DefaultUnitProd<Monoid>>
struct Dynamic_SegTree {
  using MX = Monoid;
  using X = typename MX::value_type;
  struct Node {
    int ch[2];
    X x;
  };

  const ll L0, R0;
  DefaultProd default_prod;
  vc<Node> node;
  static constexpr int NIL = 0;

  Dynamic_SegTree(ll L0_, ll R0_, DefaultProd func = DefaultProd{})
      : L0(L0_), R0(L0_ == R0_ ? R0_ + 1 : R0_), default_prod(std::move(func)) {
    reset();
  }

  void reserve(int n) { node.reserve(n + 1); }
  void reset() { node.clear(), node.eb(Node{NIL, NIL, MX::unit()}); }

  inline X get_prod(int i, ll l, ll r) {
    if constexpr (kUnitOnly) {
      return node[i].x;
    } else {
      return (i == NIL ? default_prod(l, r) : node[i].x);
    }
  }
  void update(int i, ll l, ll r) {
    assert(l + 1 < r);
    ll m = (l + r) / 2;
    int L = node[i].ch[0], R = node[i].ch[1];
    node[i].x = MX::op(get_prod(L, l, m), get_prod(R, m, r));
  }

  inline int new_root() { return new_node(L0, R0); }

  inline int new_node(const X &x) {
    node.emplace_back(Node{NIL, NIL, x});
    return int(node.size()) - 1;
  }

  inline int new_node(ll l, ll r) { return new_node(default_prod(l, r)); }
  inline int new_node() { return new_node(L0, R0); }
  inline Node operator[](int i) const { return node[i]; }

  int new_node_from_vector(const vc<X> &dat) {
    assert(L0 == 0 && R0 == len(dat));
    auto dfs = [&](auto &dfs, ll l, ll r) -> int {
      if (r == l + 1) return new_node(dat[l]);
      ll m = (l + r) / 2;
      int l_root = dfs(dfs, l, m), r_root = dfs(dfs, m, r);
      X x = MX::op(node[l_root].x, node[r_root].x);
      node.eb(Node{l_root, r_root, x});
      return int(node.size()) - 1;
    };
    return dfs(dfs, 0, len(dat));
  }

  X prod(int root, ll l, ll r) {
    assert(root != NIL && L0 <= l && l <= r && r <= R0);
    if (l == r) return MX::unit();
    X x = MX::unit();
    prod_rec(root, L0, R0, l, r, x);
    return x;
  }

  X prod_all(int root) { return node[root].x; }

  int set(int root, ll i, const X &x) {
    assert(root != NIL && L0 <= i && i < R0);
    root = copy_node(root);
    set_rec(root, L0, R0, i, x);
    return root;
  }

  int multiply(int root, ll i, const X &x) {
    assert(root != NIL && L0 <= i && i < R0);
    root = copy_node(root);
    multiply_rec(root, L0, R0, i, x);
    return root;
  }

  template <typename F>
  ll max_right(int root, F check, ll L) {
    assert(root != NIL && L0 <= L && L <= R0 && check(MX::unit()));
    X x = MX::unit();
    return max_right_rec(root, check, L0, R0, L, x);
  }

  template <typename F>
  ll min_left(int root, F check, ll R) {
    assert(root != NIL && L0 <= R && R <= R0 && check(MX::unit()));
    X x = MX::unit();
    return min_left_rec(root, check, L0, R0, R, x);
  }

  // (idx, val)
  template <typename F>
  void enumerate(int root, F f) {
    assert(root != NIL);
    auto dfs = [&](auto &dfs, int c, ll l, ll r) -> void {
      if (c == NIL) return;
      if (r - l == 1) {
        f(l, node[c].x);
        return;
      }
      ll m = (l + r) / 2;
      dfs(dfs, node[c].ch[0], l, m), dfs(dfs, node[c].ch[1], m, r);
    };
    dfs(dfs, root, L0, R0);
  }

 private:
  static constexpr bool kUnitOnly =
      std::is_same_v<DefaultProd, DefaultUnitProd<Monoid>>;
  int copy_node(int c) {
    if constexpr (!PERSISTENT) return c;
    if (c == NIL) return c;
    node.eb(node[c]);
    return int(node.size()) - 1;
  }

  int touch_child(int c, ll l, ll r) {
    if constexpr (!PERSISTENT) {
      return (c == NIL ? new_node(l, r) : c);
    } else {
      return (c == NIL ? new_node(l, r) : copy_node(c));
    }
  }

  void set_rec(int c, ll l, ll r, ll i, const X &x) {
    assert(c != NIL);
    // もう c は新しくしてある
    if (r == l + 1) {
      node[c].x = x;
      return;
    }
    ll m = (l + r) / 2;
    int b = (m <= i);
    ll nl = (b ? m : l), nr = (b ? r : m);
    node[c].ch[b] = touch_child(node[c].ch[b], nl, nr);
    set_rec(node[c].ch[b], nl, nr, i, x);
    update(c, l, r);
  }

  void multiply_rec(int c, ll l, ll r, ll i, const X &x) {
    assert(c != NIL);
    // もう c は新しくしてある
    if (r == l + 1) {
      node[c].x = MX::op(node[c].x, x);
      return;
    }
    ll m = (l + r) / 2;
    int b = (m <= i);
    ll nl = (b ? m : l), nr = (b ? r : m);
    node[c].ch[b] = touch_child(node[c].ch[b], nl, nr);
    multiply_rec(node[c].ch[b], nl, nr, i, x);
    update(c, l, r);
  }

  void prod_rec(int c, ll l, ll r, ll ql, ll qr, X &x) {
    chmax(ql, l), chmin(qr, r);
    if (ql >= qr) return;
    if (c == NIL || (l == ql && r == qr)) {
      x = MX::op(x, get_prod(c, ql, qr));
      return;
    }
    ll m = (l + r) / 2;
    prod_rec(node[c].ch[0], l, m, ql, qr, x);
    prod_rec(node[c].ch[1], m, r, ql, qr, x);
  }

  template <typename F>
  ll max_right_rec(int c, const F &check, ll l, ll r, ll ql, X &x) {
    if (r <= ql) return R0;
    X myprod = get_prod(c, l, r);
    if (ql <= l && check(MX::op(x, myprod))) {
      x = MX::op(x, myprod);
      return R0;
    }
    if (r == l + 1) return l;
    ll m = (l + r) / 2;
    ll k = max_right_rec(node[c].ch[0], check, l, m, ql, x);
    if (k != R0) return k;
    return max_right_rec(node[c].ch[1], check, m, r, ql, x);
  }

  // これ new node 作ってるのはさぼり
  template <typename F>
  ll min_left_rec(int c, const F &check, ll l, ll r, ll qr, X &x) {
    if (qr <= l) return L0;
    X myprod = get_prod(c, l, r);
    if (r <= qr && check(MX::op(myprod, x))) {
      x = MX::op(x, myprod);
      return L0;
    }
    if (r == l + 1) return r;
    ll m = (l + r) / 2;
    ll k = min_left_rec(node[c].ch[1], check, m, r, qr, x);
    if (k != L0) return k;
    return min_left_rec(node[c].ch[0], check, l, m, qr, x);
  }
};
