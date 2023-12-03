
template <typename Monoid>
struct LCT_Node_Monoid {
  using np = LCT_Node_Monoid *;
  // デフォルト
  np l, r, p;
  int idx, size; // size は heavy path の頂点数
  bool rev;
  // 目的ごとに定義する.
  using MX = Monoid;
  using X = typename MX::value_type;
  using VX = X;

  X x, rx, vx;

  LCT_Node_Monoid(int i = 0)
      : l(nullptr),
        r(nullptr),
        p(nullptr),
        idx(i),
        size(1),
        rev(0),
        x(MX::unit()),
        rx(MX::unit()),
        vx(MX::unit()) {}

  void update() {
    size = 1;
    x = vx, rx = vx;
    if (l) {
      size += l->size, x = Monoid::op(l->x, x), rx = Monoid::op(rx, l->rx);
    }
    if (r) {
      size += r->size, x = Monoid::op(x, r->x), rx = Monoid::op(r->rx, rx);
    }
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
    swap(x, rx);
  }

  // LCT 内で expose, update を行うのでここは変更だけ
  void set(VX x) { vx = x; }

  void add_light(np c) {}
  void erase_light(np c) {}
  void change_light(np a, np b) {}
};
