// Source: https://github.com/maspypy/library/blob/main/ds/segtree/dynamic_lazy_segtree_sparse.hpp
#include "ds/node_pool.hpp"

template <typename AM>
struct Dynamic_Lazy_SegTree_Sparse_Default_Prod {
  using MX = typename AM::Monoid_X;
  using X = typename AM::X;
  X operator()(ll, ll) const { return MX::id(); }
};

// 区間の左端をキーとして、Dynamic_SegTree_Sparse と同様に挿入する
// PERSISTENT=false として
// set, multiply, apply: 高々 2 ノード
// prod, max_right, min_left: ノードを追加しない
template <typename ActedMonoid, bool PERSISTENT,
    typename DefaultProd =
        Dynamic_Lazy_SegTree_Sparse_Default_Prod<ActedMonoid>>
struct Dynamic_Lazy_SegTree_Sparse {
  using AM = ActedMonoid;
  using MX = typename AM::Monoid_X;
  using MA = typename AM::Monoid_A;
  using X = typename AM::X;
  using A = typename AM::A;
  using F = DefaultProd;
  // 自身の区間とその区間積、累積作用
  struct Piece {
    ll l, r;
    X x;
    A own;
  };
  struct Node {
    Node *l, *r;
    Piece d;
    ll lo, hi;  // 部分木全体の座標範囲
    X x;        // 部分木全体の区間積
    A lazy;     // 子への未伝播の作用
  };
  using np = Node *;
  F default_prod;
  Node_Pool<Node> pool;
  const ll L0, R0;

  Dynamic_Lazy_SegTree_Sparse(ll L0, ll R0, F default_prod = F{})
      : default_prod(std::move(default_prod)), L0(L0), R0(R0) {
    assert(-infty<ll> <= L0 && L0 <= R0 && R0 <= infty<ll>);
  }

  np new_root() { return L0 == R0 ? nullptr : make(piece(L0, R0, MA::id())); }
  np new_node() { return new_root(); }
  np new_node(const vc<X> &dat) {
    assert(L0 == 0 && R0 == ll(dat.size()));
    auto dfs = [&](auto &dfs, ll l, ll r, ll a, ll b) -> np {
      if (a == b) return nullptr;
      ll m = l + (r - l) / 2;
      ll k = min(max(m, a), b - 1);
      np c = make(Piece{k, k + 1, dat[k], MA::id()});
      c->l = dfs(dfs, l, m, a, k);
      c->r = dfs(dfs, m, r, k + 1, b);
      pull(c);
      return c;
    };
    return dfs(dfs, L0, R0, L0, R0);
  }
  void reset() { pool.reset(); }

  X prod(np root, ll l, ll r) {
    assert(L0 <= l && l <= r && r <= R0);
    X x = MX::id();
    if (root && l < r) prod_rec(root, l, r, MA::id(), x);
    return x;
  }
  X prod_all(np root) { return root ? root->x : MX::id(); }
  X get(np root, ll i) { return prod(root, i, i + 1); }

  np apply(np root, ll l, ll r, const A &a) {
    assert(L0 <= l && l <= r && r <= R0);
    if (l == r) return root;
    assert(root);
    root = ensure(root, L0, R0, l);
    root = ensure(root, L0, R0, r);
    root = clone(root);
    apply_rec(root, l, r, a);
    return root;
  }
  np set(np root, ll i, const X &x) {
    assert(root && L0 <= i && i < R0);
    root = ensure(root, L0, R0, i);
    root = ensure(root, L0, R0, i + 1);
    root = clone(root);
    point_rec<false>(root, i, x);
    return root;
  }
  np multiply(np root, ll i, const X &x) {
    assert(root && L0 <= i && i < R0);
    root = ensure(root, L0, R0, i);
    root = ensure(root, L0, R0, i + 1);
    root = clone(root);
    point_rec<true>(root, i, x);
    return root;
  }

  template <typename F>
  ll max_right(np root, F check, ll L) {
    assert(L0 <= L && L <= R0 && check(MX::id()));
    X x = MX::id();
    return max_right_rec(root, check, L, MA::id(), x);
  }
  template <typename F>
  ll min_left(np root, F check, ll R) {
    assert(L0 <= R && R <= R0 && check(MX::id()));
    X x = MX::id();
    return min_left_rec(root, check, R, MA::id(), x);
  }

 private:
  np clone(np c) {
    if constexpr (PERSISTENT) {
      if (c) return pool.clone(c);
    }
    return c;
  }
  Piece piece(ll l, ll r, const A &a) {
    return {l, r, AM::act(default_prod(l, r), a, r - l), a};
  }
  np make(const Piece &d) {
    np c = pool.create();
    c->l = c->r = nullptr;
    c->d = d;
    c->lo = d.l, c->hi = d.r;
    c->x = d.x, c->lazy = MA::id();
    return c;
  }
  void tag_own(np c, const A &a) {
    Piece &d = c->d;
    d.x = AM::act(d.x, a, d.r - d.l);
    d.own = MA::op(d.own, a);
  }
  void tag(np c, const A &a) {
    c->x = AM::act(c->x, a, c->hi - c->lo);
    tag_own(c, a);
    c->lazy = MA::op(c->lazy, a);
  }
  bool push(np c) {
    if (c->lazy == MA::id()) return false;
    if (c->l) {
      c->l = clone(c->l);
      tag(c->l, c->lazy);
    }
    if (c->r) {
      c->r = clone(c->r);
      tag(c->r, c->lazy);
    }
    c->lazy = MA::id();
    return true;
  }
  void pull(np c) {
    c->lo = c->l ? c->l->lo : c->d.l;
    c->hi = c->r ? c->r->hi : c->d.r;
    c->x = c->d.x;
    if (c->l) c->x = MX::op(c->l->x, c->x);
    if (c->r) c->x = MX::op(c->x, c->r->x);
  }
  // 区間の左端をキーとして挿入する（Dynamic_SegTree_Sparse と同様）
  np insert(np c, ll l, ll r, Piece d, bool owned) {
    if (!c) return make(d);
    if (!owned) c = clone(c);
    bool pushed = push(c);
    insert_here(c, l, r, std::move(d), pushed);
    pull(c);
    return c;
  }
  void insert_here(np c, ll l, ll r, Piece d, bool pushed) {
    ll m = l + (r - l) / 2;
    assert(l <= d.l && d.l < r && d.l != c->d.l);
    if (d.l < m) {
      if (c->d.l < d.l) swap(c->d, d);
      c->l = insert(c->l, l, m, std::move(d), pushed);
    } else {
      if (d.l < c->d.l) swap(c->d, d);
      c->r = insert(c->r, m, r, std::move(d), pushed);
    }
  }
  Piece split_own(np c, ll k) {
    assert(c->d.l < k && k < c->d.r);
    Piece d = piece(k, c->d.r, c->d.own);
    c->d = piece(c->d.l, k, c->d.own);
    return d;
  }
  // k を含む区間を分割し、右側の区間を out に取り出す
  // 取り出した区間は insert_here によって戻す
  np cut(np c, ll l, ll r, ll k, optional<Piece> &out, bool owned) {
    assert(c);
    if (k == c->lo || k == c->hi || k == c->d.l || k == c->d.r) return c;
    if (!owned) c = clone(c);
    bool pushed = push(c);
    ll m = l + (r - l) / 2;
    if (k < c->d.l)
      c->l = cut(c->l, l, m, k, out, pushed);
    else if (c->d.r < k)
      c->r = cut(c->r, m, r, k, out, pushed);
    else
      out = split_own(c, k);
    pull(c);
    return c;
  }
  // k を区間の境界にする。cut と insert の共通する経路は一度だけたどる
  // キーの二分位置と、k を含む区間の位置は一致するとは限らない
  np ensure(np c, ll l, ll r, ll k, bool owned = false) {
    assert(c);
    if (k == c->lo || k == c->hi || k == c->d.l || k == c->d.r) return c;
    if (!owned) c = clone(c);
    bool pushed = push(c);
    ll m = l + (r - l) / 2;
    if (k < c->d.l) {
      if (k < m)
        c->l = ensure(c->l, l, m, k, pushed);
      else {
        optional<Piece> d;
        c->l = cut(c->l, l, m, k, d, pushed);
        if (d) insert_here(c, l, r, std::move(*d), pushed);
      }
    } else if (c->d.r < k) {
      if (m <= k)
        c->r = ensure(c->r, m, r, k, pushed);
      else {
        optional<Piece> d;
        c->r = cut(c->r, m, r, k, d, pushed);
        if (d) insert_here(c, l, r, std::move(*d), pushed);
      }
    } else {
      Piece d = split_own(c, k);
      insert_here(c, l, r, std::move(d), pushed);
    }
    pull(c);
    return c;
  }
  void apply_rec(np c, ll l, ll r, const A &a) {
    if (l <= c->lo && c->hi <= r) {
      tag(c, a);
      return;
    }
    bool pushed = push(c);
    if (c->l && l < c->l->hi && c->l->lo < r) {
      if (!pushed) c->l = clone(c->l);
      apply_rec(c->l, l, r, a);
    }
    if (l < c->d.r && c->d.l < r) {
      assert(l <= c->d.l && c->d.r <= r);
      tag_own(c, a);
    }
    if (c->r && l < c->r->hi && c->r->lo < r) {
      if (!pushed) c->r = clone(c->r);
      apply_rec(c->r, l, r, a);
    }
    pull(c);
  }
  template <bool MULTIPLY>
  void point_rec(np c, ll i, const X &x) {
    bool pushed = push(c);
    if (i < c->d.l) {
      if (!pushed) c->l = clone(c->l);
      point_rec<MULTIPLY>(c->l, i, x);
    } else if (c->d.r <= i) {
      if (!pushed) c->r = clone(c->r);
      point_rec<MULTIPLY>(c->r, i, x);
    } else {
      assert(c->d.l == i && c->d.r == i + 1);
      if constexpr (MULTIPLY)
        c->d.x = MX::op(c->d.x, x);
      else
        c->d.x = x;
      // 長さ 1 の区間は分割されないので、own は不要
      c->d.own = MA::id();
    }
    pull(c);
  }
  X piece_prod(const Piece &d, ll l, ll r, const A &a) {
    if (l == d.l && r == d.r) return AM::act(d.x, a, r - l);
    return AM::act(default_prod(l, r), MA::op(d.own, a), r - l);
  }
  void prod_rec(np c, ll l, ll r, A a, X &x) {
    if (!c || r <= c->lo || c->hi <= l) return;
    if (l <= c->lo && c->hi <= r) {
      x = MX::op(x, AM::act(c->x, a, c->hi - c->lo));
      return;
    }
    A b = MA::op(c->lazy, a);
    prod_rec(c->l, l, r, b, x);
    ll L = max(l, c->d.l), R = min(r, c->d.r);
    if (L < R) x = MX::op(x, piece_prod(c->d, L, R, a));
    prod_rec(c->r, l, r, b, x);
  }
  template <typename F>
  ll max_right_rec(np c, const F &check, ll l, A a, X &x) {
    if (!c || c->hi <= l) return R0;
    if (l <= c->lo) {
      X y = MX::op(x, AM::act(c->x, a, c->hi - c->lo));
      if (check(y)) {
        x = y;
        return R0;
      }
    }
    A b = MA::op(c->lazy, a);
    ll k = max_right_rec(c->l, check, l, b, x);
    if (k != R0) return k;
    if (l < c->d.r) {
      ll L = max(l, c->d.l), R = c->d.r;
      X y = MX::op(x, piece_prod(c->d, L, R, a));
      if (!check(y)) {
        ll ok = L, ng = R;
        while (ng - ok > 1) {
          ll m = ok + (ng - ok) / 2;
          if (check(MX::op(x, piece_prod(c->d, L, m, a))))
            ok = m;
          else
            ng = m;
        }
        return ok;
      }
      x = y;
    }
    return max_right_rec(c->r, check, l, b, x);
  }
  template <typename F>
  ll min_left_rec(np c, const F &check, ll r, A a, X &x) {
    if (!c || r <= c->lo) return L0;
    if (c->hi <= r) {
      X y = MX::op(AM::act(c->x, a, c->hi - c->lo), x);
      if (check(y)) {
        x = y;
        return L0;
      }
    }
    A b = MA::op(c->lazy, a);
    ll k = min_left_rec(c->r, check, r, b, x);
    if (k != L0) return k;
    if (c->d.l < r) {
      ll L = c->d.l, R = min(r, c->d.r);
      X y = MX::op(piece_prod(c->d, L, R, a), x);
      if (!check(y)) {
        ll ng = L, ok = R;
        while (ok - ng > 1) {
          ll m = ng + (ok - ng) / 2;
          if (check(MX::op(piece_prod(c->d, m, R, a), x)))
            ok = m;
          else
            ng = m;
        }
        return ok;
      }
      x = y;
    }
    return min_left_rec(c->l, check, r, b, x);
  }
};
