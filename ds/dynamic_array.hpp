#pragma once

template <typename T, bool PERSISTENT, int NODES>
struct Dynamic_Array {
  struct Node {
    T x;
    Node* ch[16] = {};
  };
  Node* pool;
  int pid;
  using np = Node*;
  const T x0;

  Dynamic_Array(T default_value) : pid(0), x0(default_value) {
    pool = new Node[NODES];
  }

  np new_node() {
    pool[pid].x = x0;
    fill(pool[pid].ch, pool[pid].ch + 16, nullptr);
    return &(pool[pid++]);
  }

  np new_node(vc<T> dat) {
    np root = new_node();
    FOR(i, len(dat)) root = set(root, i, dat[i], false);
    return root;
  }

  T get(np c, int idx) {
    if (!c) return x0;
    if (idx == 0) return c->x;
    return get(c->ch[idx & 15], (idx - 1) >> 4);
  }

  np set(np c, int idx, T x, bool make_copy = true) {
    c = (c ? copy_node(c, make_copy) : new_node());
    if (idx == 0) {
      c->x = x;
      return c;
    }
    return set(c->ch[idx & 15], (idx - 1) >> 4, x);
  }

private:
  np copy_node(np c, bool make_copy) {
    if (!make_copy || !PERSISTENT) return c;
    pool[pid].x = c->x;
    pool[pid].ch = c->ch;
    return &(pool[pid++]);
  }
};
