
// SUBTREE : cluster が subtree 情報を持つ場合
template <typename Monoid, bool SUBTREE = false>
struct LCT_Node_Commutative_Monoid {
  static_assert(Monoid::commute);
  static constexpr bool NODE_FOR_SUBTREE = SUBTREE;
  using np = LCT_Node_Commutative_Monoid *;
  // デフォルト
  np l, r, p;
  int idx, size; // size は heavy path の頂点数
  bool rev;
  // 目的ごとに定義する.
  using MX = Monoid;
  using X = MX::value_type;
  using VX = X;
  X x, vx, mid;

  LCT_Node_Commutative_Monoid(int i = 0)
      : l(nullptr),
        r(nullptr),
        p(nullptr),
        idx(i),
        size(1),
        rev(0),
        x(MX::unit()),
        vx(MX::unit()),
        mid(MX::unit()) {}

  void update() {
    size = 1;
    x = vx;
    if constexpr (SUBTREE) x = MX::op(x, mid);
    if (l) { size += l->size, x = Monoid::op(l->x, x); }
    if (r) { size += r->size, x = Monoid::op(x, r->x); }
  }

  void push() {
    if (rev) {
      if (l) l->reverse();
      if (r) r->reverse();
      rev = 0;
    }
  }

  // data の reverse も行う
  void reverse() {
    rev ^= 1;
    swap(l, r);
  }

  // LCT 内で expose, update を行うのでここは変更だけ
  void set(VX x) { vx = x; }

  // c がこの時点では update されていないかもしれないが, x は正常なものが入る
  // c->x 等は使わないように注意する
  // c->idx を持っておくと探索できることがある
  void add_light(np c, X x) {
    if constexpr (SUBTREE) mid = MX::op(mid, x);
  }
  void erase_light(np c, X x) {
    if constexpr (SUBTREE) mid = MX::op(mid, MX::inverse(x));
  }
};
