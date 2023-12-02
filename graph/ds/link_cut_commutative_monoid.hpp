
template <typename Monoid>
struct LCT_Node_Commutative_Monoid {
  using np = LCT_Node_Commutative_Monoid *;
  // デフォルト
  np l, r, p;
  int idx, size; // size は heavy path の頂点数
  bool rev;
  // 目的ごとに定義する.
  using MX = Monoid;
  using X = MX::value_type;
  using VX = X;

  X x, vx;

  LCT_Node_Commutative_Monoid(int i = 0)
      : l(nullptr), r(nullptr), p(nullptr), idx(i), size(1), rev(0) {}

  void update() {
    size = 1;
    x = vx;
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
  void set_vdata(VX x) { vx = x; }

  // c がこの時点では update されていないかもしれないが, x は正常なものが入る
  // c->x 等は使わないように注意する
  // c->idx を持っておくと探索できることがある
  void add_light(np c, X x) {}
  void erase_light(np c, X x) {}
};
