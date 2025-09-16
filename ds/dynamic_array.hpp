#pragma once
#include "ds/node_pool.hpp"

template <typename T, bool PERSISTENT>
struct Dynamic_Array {
  static constexpr int LOG = 4;
  static constexpr int MASK = (1 << LOG) - 1;
  struct Node {
    T x;
    Node* ch[1 << LOG] = {};
  };
  Node_Pool<Node> pool;
  using np = Node*;
  const T x0;

  Dynamic_Array(int NODES, T default_value) : x0(default_value) {}
  np new_root() {
    np c = pool.create();
    c->x = x0;
    fill(c->ch, c->ch + (1 << LOG), nullptr);
    return c;
  }

  np new_node(vc<T> dat) {
    np root = new_root();
    FOR(i, len(dat)) root = set(root, i, dat[i], false);
    return root;
  }

  T get(np c, int idx) {
    if (!c) return x0;
    if (idx == 0) return c->x;
    return get(c->ch[idx & MASK], (idx - 1) >> LOG);
  }

  np set(np c, int idx, T x, bool make_copy = true) {
    c = (c ? clone(c, make_copy) : new_root());
    if (idx == 0) {
      c->x = x;
      return c;
    }
    c->ch[idx & MASK] = set(c->ch[idx & MASK], (idx - 1) >> LOG, x);
    return c;
  }

 private:
  np clone(np c, bool make_copy) {
    if (!make_copy || !PERSISTENT) return c;
    return pool.clone(c);
  }
};
