#pragma once

template <typename T, int shift = 4>
struct PersistentArray {
  struct node;
  using np = node*;
  struct node {
    T data;
    np ch[1 << shift] = {};
  };

  static constexpr int mask = (1 << shift) - 1;
  np root = nullptr;
  PersistentArray() {}
  np get_root() { return root; }
  T get(np t, int idx) {
    if (!t) return 0;
    if (idx == 0) {
      return t->data;
    } else {
      return get(t->ch[idx & mask], idx >> shift);
    }
  }

  void destructive_set(np& t, int idx, T val) {
    // 破壊的な値の変更。主に初期化に使う。
    if (!t) t = new node();
    if (idx == 0)
      t->data = val;
    else {
      destructive_set(t->ch[idx & mask], idx >> shift, val);
    }
  }

  np set(const np& t, int idx, T val) {
    // set したあとの永続配列の root node pointer を返す
    np res = new node();
    if (t) {
      memcpy(res->ch, t->ch, sizeof(t->ch));
      res->data = t->data;
    }
    if (idx == 0) {
      res->data = val;
    } else {
      res->ch[idx & mask] = set(res->ch[idx & mask], idx >> shift, val);
    }
    return res;
  }
};
