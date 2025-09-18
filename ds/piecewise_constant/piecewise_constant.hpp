#include "ds/splaytree/splaytree.hpp"

enum Border_Type { inc, dec, l, r };

// https://atcoder.jp/contests/cf16-tournament-round3-open/tasks/asaporo_b
// https://atcoder.jp/contests/arc174/tasks/arc174_f
template <typename Node>
struct Piecewise_Constant {
  using Y = typename Node::Y_type;
  SplayTree<Node>& ST;
  using np = Node*;
  using S = typename Node::value_type;
  using App = typename Node::operator_type;
  using BT = Border_Type;
  np root;
  using QUE = pq_min<pair<ll, np>>;
  QUE que_lo, que_hi;
  array<ll, 4> add;
  array<ll, 2> domain;

  vc<np> my_pool;
  np new_node(S x) {
    np c = ST.new_node(x);
    my_pool.eb(c);
    return c;
  }
  ~Piecewise_Constant() {
    for (auto c : my_pool) {
      ST.pool.destroy(c);
    }
  }

  void swap(Piecewise_Constant& other) noexcept {
    ::swap(root, other.root);
    ::swap(que_lo, other.que_lo);
    ::swap(que_hi, other.que_hi);
    ::swap(add, other.add);
    ::swap(domain, other.domain);
    ::swap(my_pool, other.my_pool);
  }

  int size() { return len(my_pool); }

  // f(i) = (x1,x2,y)
  template <typename F>
  Piecewise_Constant(SplayTree<Node>& ST, int n, F f)
      : ST(ST), root(nullptr), add{}, domain{} {
    assert(n > 0);
    vc<S> dat;
    FOR(i, n) {
      auto [x1, x2, y] = f(i);
      if (i == 0) {
        dat.eb(S{x1, x2, y, BT::l, BT::r});
        continue;
      }
      assert(dat.back().x2 == x1);
      if (dat.back().y == y) {
        dat.back().x2 = x2;
        continue;
      }
      BT c = (dat.back().y < y ? BT::inc : BT::dec);
      dat.back().c2 = c;
      dat.eb(S{x1, x2, y, c, BT::r});
    }
    root = nullptr;
    FOR(i, len(dat)) {
      np c = new_node(dat[i]);
      add_que(c);
      root = ST.merge(root, c);
    }
    domain[0] = dat[0].x1, domain[1] = dat.back().x2;
  }

  void shift(ll a) {
    add[0] += a, add[1] += a, add[2] += a, add[3] += a;
    if (domain[0] != -infty<ll>) domain[0] += a;
    if (domain[1] != infty<ll>) domain[1] += a;
  }

  // f(x) を g(x) に変更. g(x)=min_{x+a<=t<=x+b} f(x).
  void slide_min(ll a, ll b) { slide(BT::inc, BT::dec, a, b, que_hi); }

  // f(x) を g(x) に変更. g(x)=max_{x+a<=t<=x+b} f(x).
  void slide_max(ll a, ll b) { slide(BT::dec, BT::inc, a, b, que_lo); }

  vc<tuple<ll, ll, Y>> get_all() {
    vc<tuple<ll, ll, Y>> ANS;
    auto dfs = [&](auto& dfs, np c) -> void {
      auto [x1, x2] = position(c);
      c->push();
      if (c->l) dfs(dfs, c->l);
      ANS.eb(x1, x2, c->y());
      if (c->r) dfs(dfs, c->r);
    };
    dfs(dfs, root);
    return ANS;
  }

  // 定義域の左端が x になるように拡張, y で埋める
  void extend_domain_left(ll x, Y y) {
    if (x == domain[0]) return;
    assert(x < domain[0]);
    ST.splay_kth(root, 0);
    BT color = (y < root->y() ? BT::inc : BT::dec);
    np c = new_node(S{x - add[BT::l], domain[0] - add[color], y, BT::l, color});
    root->c1() = color, root->x1() = domain[0] - add[color];
    add_que(root);
    root = ST.merge(c, root);
    domain[0] = x;
  }

  void apply(ll L, ll R, App app) {
    if (L == R) return;
    auto [A, tmp] = split(root, L, domain[0], domain[1]);
    auto [B, C] = split(tmp, R, L, domain[1]);
    ST.apply(B, app);
    if (A) {
      ST.splay_kth(A, A->size - 1);
      ST.splay_kth(B, 0);
      assert(position(A).se == L && position(B).fi == L);
      BT color = (A->y() < B->y() ? BT::inc : BT::dec);
      A->c2() = color, A->x2() = L - add[color];
      B->c1() = color, B->x1() = L - add[color];
      add_que(A), add_que(B);
    } else {
      ST.splay_kth(B, 0);
      assert(position(B).fi == L);
      B->c1() = BT::l, B->x1() = L - add[BT::l];
    }
    if (C) {
      ST.splay_kth(B, B->size - 1);
      ST.splay_kth(C, 0);
      assert(position(B).se == R && position(C).fi == R);
      BT color = (B->y() < C->y() ? BT::inc : BT::dec);
      B->c2() = color, B->x2() = R - add[color];
      C->c1() = color, C->x1() = R - add[color];
      add_que(B), add_que(C);
    } else {
      ST.splay_kth(B, B->size - 1);
      assert(position(B).se == R);
      B->c2() = BT::r, B->x2() = R - add[BT::r];
    }
    root = ST.merge3(A, B, C);
  }

  Y get(ll x) {
    assert(domain[0] <= x && x < domain[1]);
    root = ST.find_max_right(
        root, [&](S s) -> bool { return (s.x1 + add[s.c1] <= x); });
    ST.splay(root, true);
    return root->y();
  }

  pair<np, np> split(np c, ll x, ll a, ll b) {
    // c の定義域が [a,b)
    assert(a <= x && x <= b);
    if (a == x) return {nullptr, c};
    if (b == x) return {c, nullptr};
    c = ST.find_max_right(c,
                          [&](S s) -> bool { return (s.x1 + add[s.c1] <= x); });
    ST.splay(c, true);
    auto [x1, x2] = position(c);
    if (x1 == x) {
      np l = c->l;
      if (l) l->p = nullptr, c->l = nullptr;
      c->update();
      return {l, c};
    }
    assert(x1 < x && x < x2);
    np cr = new_node(S{x - add[BT::l], c->x2(), c->y(), BT::l, c->c2()});
    c->c2() = BT::r, c->x2() = x - add[BT::r];
    np r = c->r;
    if (!r) {
      c->update(), cr->update();
      return {c, cr};
    }
    c->r = nullptr, cr->r = r, r->p = cr;
    c->update(), cr->update();
    return {c, cr};
  }

 private:
  inline bool active(np c) { return (c->p != nullptr || c == root); }

  pi position(np c) {
    ll x1 = c->x1(), x2 = c->x2();
    if (x1 != -infty<ll>) x1 += add[c->c1()];
    if (x2 != infty<ll>) x2 += add[c->c2()];
    return {x1, x2};
  }

  void slide(BT stay, BT move, ll a, ll b, QUE& que) {
    assert(domain[0] < domain[1]);
    shift(-a);
    b -= a;
    if (domain[1] != infty<ll>) domain[1] -= b;
    while (1) {
      while (len(que)) {
        auto [pri, c] = que.top();
        if (pri + add[move] - add[stay] > b) {
          break;
        }
        elif (!active(c)) { que.pop(); }
        elif (c->c1() != stay || c->c2() != move) { que.pop(); }
        elif (c->x2() - c->x1() != pri) { que.pop(); }
        else {
          auto [x1, x2] = position(c);
          assert(x2 - x1 <= b);
          que.pop();
          ST.splay(c, false);
          // c is deleted
          auto [A, mid, B] = ST.split3(c, c->lsize(), c->lsize() + 1);
          assert(mid == c);

          ST.splay_kth(A, A->size - 1), ST.splay_kth(B, 0);
          BT color = (A->y() < B->y() ? BT::inc : BT::dec);
          if (color == stay) {
            B->c1() = stay, B->x1() = x1 - add[stay];
            add_que(B);
          } else {
            A->c2() = move, A->x2() = x2 - add[move];
            add_que(A);
          }
          root = ST.merge(A, B);
        }
      }
      ST.splay_kth(root, 0);
      auto [x1, x2] = position(root);
      if (x2 - x1 <= b && root->c2() == move) {
        auto [left, B] = ST.split(root, 1);
        ST.splay_kth(B, 0);
        assert(left == root);
        B->c1() = BT::l, B->x1() = x1 - add[BT::l];
        root = B;
        continue;
      }
      ST.splay_kth(root, root->size - 1);
      tie(x1, x2) = position(root);
      if (x2 - x1 <= b && root->c1() == stay) {
        auto [A, right] = ST.split(root, root->size - 1);
        ST.splay_kth(A, A->size - 1);
        assert(right == root);
        A->c2() = BT::r, A->x2() = x2 - add[BT::r];
        root = A;
        continue;
      }
      break;
    }
    add[move] -= b, add[BT::r] -= b;
  }

  void add_que(np c) {
    ll d = c->x2() - c->x1();
    if (c->c1() == BT::inc && c->c2() == BT::dec) {
      que_hi.emplace(d, c);
    }
    if (c->c1() == BT::dec && c->c2() == BT::inc) {
      que_lo.emplace(d, c);
    }
  }
};
