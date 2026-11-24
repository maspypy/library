#include "ds/node_pool.hpp"

template <int LOG, bool PERSISTENT, typename UINT = u64,
    typename SIZE_TYPE = u32>
struct Binary_Trie {
  using T = SIZE_TYPE;
  static_assert(is_same_v<T, u32> || is_same_v<T, u64>);
  static_assert(0 < LOG && LOG <= numeric_limits<UINT>::digits);

  struct Node {
    T cnt;
    Node *l, *r;
  };

  Node_Pool<Node> pool;
  using np = Node*;

  void reset() { pool.reset(); }

  np new_root() { return nullptr; }

  np add(np root, UINT val, T cnt = 1) {
    if constexpr (LOG < numeric_limits<UINT>::digits) {
      assert((val >> LOG) == 0);
    }
    return add_rec(root, LOG, val, cnt);
  }

  // f(val, cnt, end)
  template <typename F>
  void enumerate(np root, F f) {
    bool end = false;
    auto dfs = [&](auto& dfs, np root, UINT val, int ht) -> void {
      if (!root || end) return;
      if (ht == 0) {
        f(val, root->cnt, end);
        return;
      }
      dfs(dfs, root->l, 2 * val + 0, ht - 1);
      dfs(dfs, root->r, 2 * val + 1, ht - 1);
    };
    dfs(dfs, root, 0, LOG);
  }

  // xor_val したあとの値で昇順 k 番目
  UINT kth(np root, T k, UINT xor_val) {
    assert(root && k < root->cnt);
    UINT val = 0;
    for (int d = LOG - 1; d >= 0; --d) {
      bool b = (xor_val >> d) & 1;
      np c = (b ? root->r : root->l);
      T sl = (c ? c->cnt : 0);
      if (k >= sl) {
        k -= sl;
        b = !b;
      }
      val = 2 * val + b;
      root = (b ? root->r : root->l);
    }
    return val ^ xor_val;
  }

  // xor_val したあとの値で最小値
  UINT min(np root, UINT xor_val) {
    assert(root && root->cnt);
    return kth(root, 0, xor_val);
  }

  // xor_val したあとの値で最大値
  UINT max(np root, UINT xor_val) {
    assert(root && root->cnt);
    return kth(root, root->cnt - 1, xor_val);
  }

  // xor_val したあとの値で [0, upper) 内に入るものの個数
  T prefix_count(np root, UINT upper, UINT xor_val) {
    if (!root) return 0;
    if constexpr (LOG < numeric_limits<UINT>::digits) {
      UINT a = upper >> LOG, b = xor_val >> LOG;
      if (a != b) return (a > b ? root->cnt : 0);
    }
    T res = 0;
    for (int d = LOG - 1; d >= 0 && root; --d) {
      np l = root->l, r = root->r;
      if ((xor_val >> d) & 1) swap(l, r);
      if ((upper >> d) & 1) {
        if (l) res += l->cnt;
        root = r;
      } else {
        root = l;
      }
    }
    return res;
  }

  // xor_val したあとの値で [lo, hi) 内に入るものの個数
  T count(np root, UINT lo, UINT hi, UINT xor_val) {
    return prefix_count(root, hi, xor_val) - prefix_count(root, lo, xor_val);
  }

 private:
  np new_node() {
    np c = pool.create();
    c->l = c->r = nullptr;
    c->cnt = 0;
    return c;
  }

  np clone(np c) {
    if (!c || !PERSISTENT) return c;
    return pool.clone(c);
  }

  np add_rec(np root, int ht, UINT val, T cnt) {
    root = (root ? clone(root) : new_node());
    root->cnt += cnt;
    if (ht == 0) return root;
    bool b = (val >> (ht - 1)) & 1;
    np& c = (b ? root->r : root->l);
    c = add_rec(c, ht - 1, val, cnt);
    return root;
  }
};