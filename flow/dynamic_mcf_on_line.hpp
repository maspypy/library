#include "alg/monoid/add.hpp"
#include "ds/segtree/lazy_segtree.hpp"
#include "ds/segtree/segtree.hpp"

// O(|cap| log N) per operation
template <typename T>
struct Dynamic_MCF_on_Line {
  int N;
  T ANS;

  using P = pair<T, int>;
  struct Mono {
    struct X {
      P from, to;
    };
    using value_type = X;
    static X op(const X& a, const X& b) {
      return {min(a.from, b.from), min(a.to, b.to)};
    }
    static constexpr X id() { return {{infty<T>, -1}, {infty<T>, -1}}; }
    static constexpr bool commute = true;
  };

  vc<map<T, int>> S_remain, S_used;
  vc<map<T, int>> T_remain, T_used;

  SegTree<Mono> seg_terminal;

  struct Mono_Line {
    struct X {
      int left, right;
    };
    using value_type = X;
    static X op(const X& a, const X& b) {
      return {min(a.left, b.left), min(a.right, b.right)};
    }
    static constexpr X id() { return {infty<int>, infty<int>}; }
    static constexpr bool commute = true;
  };

  struct AM {
    using Monoid_X = Mono_Line;
    using Monoid_A = Monoid_Add<int>;
    using X = typename Monoid_X::value_type;
    using A = typename Monoid_A::value_type;
    static X act(X x, const A& a, const ll&) {
      x.left += a, x.right -= a;
      return x;
    }
  };

  using X = typename Mono_Line::value_type;
  Lazy_SegTree<AM> seg_flow;

  Dynamic_MCF_on_Line(int N, const vc<int>& right_cap, const vc<int>& left_cap)
      : N(N),
        ANS(0),
        S_remain(N),
        S_used(N),
        T_remain(N),
        T_used(N),
        seg_terminal(N) {
    assert(N > 0);
    assert(len(right_cap) == N - 1);
    assert(len(left_cap) == N - 1);
    FOR(i, N - 1) {
      assert(right_cap[i] >= 0);
      assert(left_cap[i] >= 0);
    }
    seg_flow.build(
        N - 1, [&](int i) -> X { return {left_cap[i], right_cap[i]}; });
  }

  void add_source(int v, T cost, int cap = 1) {
    assert(0 <= v && v < N);
    assert(cap >= 0);
    mp_add(S_remain[v], cost, cap);
    update_terminal(v);

    FOR(cap) {
      auto [l, r] = reachable_from(v);
      // v -> ... -> w -> hub
      auto [c, w] = seg_terminal.prod(l, r + 1).to;
      if (w == -1 || cost + c >= 0) break;
      move_mp(S_remain[v], S_used[v], cost, 1);
      ANS += cost;
      update_terminal(v);
      push_line(v, w, 1);
      push_to_hub(w, c);
    }
  }

  void add_sink(int v, T cost, int cap = 1) {
    assert(0 <= v && v < N);
    assert(cap >= 0);

    mp_add(T_remain[v], cost, cap);
    update_terminal(v);

    FOR(cap) {
      auto [l, r] = reachable_to(v);
      // hub -> w -> ... -> v
      auto [c, w] = seg_terminal.prod(l, r + 1).from;
      if (w == -1 || c + cost >= 0) break;
      push_from_hub(w, c);
      push_line(w, v, 1);
      move_mp(T_remain[v], T_used[v], cost, 1);
      ANS += cost;
      update_terminal(v);
    }
  }

  void rm_source(int v, T cost, int cap = 1) {
    assert(0 <= v && v < N);
    assert(cap >= 0);
    int a = mp_count(S_remain[v], cost);
    int b = mp_count(S_used[v], cost);
    assert(a + b >= cap);

    int k = min(cap, a);
    mp_sub(S_remain[v], cost, k);
    cap -= k;
    update_terminal(v);

    FOR(cap) {
      mp_sub(S_used[v], cost, 1);
      ANS -= cost;
      update_terminal(v);
      auto [l, r] = reachable_to(v);
      auto [c, w] = seg_terminal.prod(l, r + 1).from;
      assert(w != -1);
      push_from_hub(w, c);
      push_line(w, v, 1);
    }
  }

  void rm_sink(int v, T cost, int cap = 1) {
    assert(0 <= v && v < N);
    assert(cap >= 0);
    int a = mp_count(T_remain[v], cost);
    int b = mp_count(T_used[v], cost);
    assert(a + b >= cap);
    int k = min(cap, a);
    mp_sub(T_remain[v], cost, k);
    cap -= k;
    update_terminal(v);
    FOR(cap) {
      mp_sub(T_used[v], cost, 1);
      ANS -= cost;
      update_terminal(v);
      auto [l, r] = reachable_from(v);
      auto [c, w] = seg_terminal.prod(l, r + 1).to;
      assert(w != -1);
      push_line(v, w, 1);
      push_to_hub(w, c);
    }
  }

 private:
  static int mp_count(const map<T, int>& mp, const T& x) {
    auto it = mp.find(x);
    return (it == mp.end() ? 0 : it->second);
  }

  static void mp_add(map<T, int>& mp, const T& x, int k) {
    assert(k >= 0);
    if (k == 0) return;
    mp[x] += k;
  }

  static void mp_sub(map<T, int>& mp, const T& x, int k) {
    assert(k >= 0);
    if (k == 0) return;
    auto it = mp.find(x);
    assert(it != mp.end() && it->second >= k);
    it->second -= k;
    if (it->second == 0) mp.erase(it);
  }

  static void move_mp(map<T, int>& A, map<T, int>& B, const T& x, int k) {
    mp_sub(A, x, k), mp_add(B, x, k);
  }

  void update_terminal(int v) {
    auto x = Mono::id();
    if (!S_remain[v].empty()) chmin(x.from, P{S_remain[v].begin()->first, v});
    if (!T_used[v].empty()) chmin(x.from, P{-T_used[v].rbegin()->first, v});
    if (!T_remain[v].empty()) chmin(x.to, P{T_remain[v].begin()->first, v});
    if (!S_used[v].empty()) chmin(x.to, P{-S_used[v].rbegin()->first, v});

    seg_terminal.set(v, x);
  }

  void push_from_hub(int v, T cost) {
    if (!S_remain[v].empty() && S_remain[v].begin()->first == cost) {
      move_mp(S_remain[v], S_used[v], cost, 1);
      ANS += cost;
      update_terminal(v);
      return;
    }

    assert(!T_used[v].empty());
    T c = T_used[v].rbegin()->first;
    assert(-c == cost);

    move_mp(T_used[v], T_remain[v], c, 1);
    ANS -= c;
    update_terminal(v);
  }

  void push_to_hub(int v, T cost) {
    if (!T_remain[v].empty() && T_remain[v].begin()->first == cost) {
      move_mp(T_remain[v], T_used[v], cost, 1);
      ANS += cost;
      update_terminal(v);
      return;
    }

    assert(!S_used[v].empty());
    T c = S_used[v].rbegin()->first;
    assert(-c == cost);

    move_mp(S_used[v], S_remain[v], c, 1);
    ANS -= c;
    update_terminal(v);
  }

  // v から到達可能な vertex interval [l, r]
  pair<int, int> reachable_from(int v) {
    int l =
        seg_flow.min_left([&](const X& x) -> bool { return x.left > 0; }, v);
    int r =
        seg_flow.max_right([&](const X& x) -> bool { return x.right > 0; }, v);
    return {l, r};
  }

  // v に到達可能な vertex interval [l, r]
  pair<int, int> reachable_to(int v) {
    int l =
        seg_flow.min_left([&](const X& x) -> bool { return x.right > 0; }, v);
    int r =
        seg_flow.max_right([&](const X& x) -> bool { return x.left > 0; }, v);
    return {l, r};
  }

  void push_line(int s, int t, int f) {
    assert(f >= 0);
    if (s == t || f == 0) return;

    if (s < t) {
      assert(seg_flow.prod(s, t).right >= f);
      seg_flow.apply(s, t, +f);
    } else {
      assert(seg_flow.prod(t, s).left >= f);
      seg_flow.apply(t, s, -f);
    }
  }
};