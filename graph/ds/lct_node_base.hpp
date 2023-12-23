// SUBTREE : cluster が subtree 情報を持つ場合
struct LCT_Node_Base {
  using np = LCT_Node_Base*;
  // デフォルト
  np l, r, p;
  int idx, size; // size は heavy path の頂点数
  bool rev;
  using X = int;
  using VX = int;

  LCT_Node_Base(int i = 0)
      : l(nullptr), r(nullptr), p(nullptr), idx(i), size(1), rev(0) {}

  void update() {
    size = 1;
    if (l) { size += l->size; }
    if (r) { size += r->size; }
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
  void set(VX x) {}

  void add_light(np c) {}
  void erase_light(np c) {}

  // b->x に subtree value が入っている.
  void change_light(np a, np b) {}
};
