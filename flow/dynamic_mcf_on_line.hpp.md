---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: alg/monoid/add.hpp
    title: alg/monoid/add.hpp
  - icon: ':heavy_check_mark:'
    path: ds/segtree/lazy_segtree.hpp
    title: ds/segtree/lazy_segtree.hpp
  - icon: ':heavy_check_mark:'
    path: ds/segtree/segtree.hpp
    title: ds/segtree/segtree.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"alg/monoid/add.hpp\"\n\ntemplate <typename E>\nstruct Monoid_Add\
    \ {\n  using X = E;\n  using value_type = X;\n  static constexpr X op(const X\
    \ &x, const X &y) noexcept { return x + y; }\n  static constexpr X inverse(const\
    \ X &x) noexcept { return -x; }\n  static constexpr X power(const X &x, ll n)\
    \ noexcept { return X(n) * x; }\n  static constexpr X id() { return X(0); }\n\
    \  static constexpr bool commute = true;\n};\n#line 1 \"ds/segtree/lazy_segtree.hpp\"\
    \n\ntemplate <typename ActedMonoid>\nstruct Lazy_SegTree {\n  using AM = ActedMonoid;\n\
    \  using MX = typename AM::Monoid_X;\n  using MA = typename AM::Monoid_A;\n  using\
    \ X = typename MX::value_type;\n  using A = typename MA::value_type;\n  int n,\
    \ log, size;\n  vc<X> dat;\n  vc<A> laz;\n  vc<bool> has_laz;\n\n  Lazy_SegTree()\
    \ {}\n  Lazy_SegTree(int n) { build(n); }\n  template <typename F>\n  Lazy_SegTree(int\
    \ n, F f) {\n    build(n, f);\n  }\n  Lazy_SegTree(const vc<X>& v) { build(v);\
    \ }\n\n  void build(int m) {\n    build(m, [](int i) -> X { return MX::id(); });\n\
    \  }\n  void build(const vc<X>& v) {\n    build(len(v), [&](int i) -> X { return\
    \ v[i]; });\n  }\n  template <typename F>\n  void build(int m, F f) {\n    n =\
    \ m, log = 0;\n    while ((1 << log) < n) ++log;\n    size = 1 << log;\n    dat.assign(size\
    \ << 1, MX::id());\n    laz.assign(size, MA::id());\n    has_laz.assign(size,\
    \ false);\n    FOR(i, n) dat[size + i] = f(i);\n    FOR_R(i, 1, size) update(i);\n\
    \  }\n\n  void update(int k) { dat[k] = MX::op(dat[2 * k], dat[2 * k + 1]); }\n\
    \  void set(int p, X x) {\n    assert(0 <= p && p < n);\n    p += size;\n    for\
    \ (int i = log; i >= 1; i--) push(p >> i);\n    dat[p] = x;\n    for (int i =\
    \ 1; i <= log; i++) update(p >> i);\n  }\n  void multiply(int p, const X& x) {\n\
    \    assert(0 <= p && p < n);\n    p += size;\n    for (int i = log; i >= 1; i--)\
    \ push(p >> i);\n    dat[p] = MX::op(dat[p], x);\n    for (int i = 1; i <= log;\
    \ i++) update(p >> i);\n  }\n\n  X get(int p) {\n    assert(0 <= p && p < n);\n\
    \    p += size;\n    for (int i = log; i >= 1; i--) push(p >> i);\n    return\
    \ dat[p];\n  }\n\n  vc<X> get_all() {\n    FOR(k, 1, size) { push(k); }\n    return\
    \ {dat.begin() + size, dat.begin() + size + n};\n  }\n\n  X prod(int l, int r)\
    \ {\n    assert(0 <= l && l <= r && r <= n);\n    if (l == r) return MX::id();\n\
    \    l += size, r += size;\n    for (int i = log; i >= 1; i--) {\n      if (((l\
    \ >> i) << i) != l) push(l >> i);\n      if (((r >> i) << i) != r) push((r - 1)\
    \ >> i);\n    }\n    X xl = MX::id(), xr = MX::id();\n    while (l < r) {\n  \
    \    if (l & 1) xl = MX::op(xl, dat[l++]);\n      if (r & 1) xr = MX::op(dat[--r],\
    \ xr);\n      l >>= 1, r >>= 1;\n    }\n    return MX::op(xl, xr);\n  }\n\n  X\
    \ prod_all() { return dat[1]; }\n\n  void apply(int l, int r, A a) {\n    assert(0\
    \ <= l && l <= r && r <= n);\n    if (l == r) return;\n    l += size, r += size;\n\
    \    for (int i = log; i >= 1; i--) {\n      if (((l >> i) << i) != l) push(l\
    \ >> i);\n      if (((r >> i) << i) != r) push((r - 1) >> i);\n    }\n    int\
    \ l2 = l, r2 = r;\n    while (l < r) {\n      if (l & 1) apply_at(l++, a);\n \
    \     if (r & 1) apply_at(--r, a);\n      l >>= 1, r >>= 1;\n    }\n    l = l2,\
    \ r = r2;\n    for (int i = 1; i <= log; i++) {\n      if (((l >> i) << i) !=\
    \ l) update(l >> i);\n      if (((r >> i) << i) != r) update((r - 1) >> i);\n\
    \    }\n  }\n\n  template <typename F>\n  int max_right(const F check, int l)\
    \ {\n    assert(0 <= l && l <= n);\n    assert(check(MX::id()));\n    if (l ==\
    \ n) return n;\n    l += size;\n    for (int i = log; i >= 1; i--) push(l >> i);\n\
    \    X sm = MX::id();\n    do {\n      while (l % 2 == 0) l >>= 1;\n      if (!check(MX::op(sm,\
    \ dat[l]))) {\n        while (l < size) {\n          push(l);\n          l = (2\
    \ * l);\n          if (check(MX::op(sm, dat[l]))) {\n            sm = MX::op(sm,\
    \ dat[l++]);\n          }\n        }\n        return l - size;\n      }\n    \
    \  sm = MX::op(sm, dat[l++]);\n    } while ((l & -l) != l);\n    return n;\n \
    \ }\n\n  template <typename F>\n  int min_left(const F check, int r) {\n    assert(0\
    \ <= r && r <= n);\n    assert(check(MX::id()));\n    if (r == 0) return 0;\n\
    \    r += size;\n    for (int i = log; i >= 1; i--) push((r - 1) >> i);\n    X\
    \ sm = MX::id();\n    do {\n      r--;\n      while (r > 1 && (r % 2)) r >>= 1;\n\
    \      if (!check(MX::op(dat[r], sm))) {\n        while (r < size) {\n       \
    \   push(r);\n          r = (2 * r + 1);\n          if (check(MX::op(dat[r], sm)))\
    \ {\n            sm = MX::op(dat[r--], sm);\n          }\n        }\n        return\
    \ r + 1 - size;\n      }\n      sm = MX::op(dat[r], sm);\n    } while ((r & -r)\
    \ != r);\n    return 0;\n  }\n\n  // l <= i xor (xor_val) < r \u3068\u306A\u308B\
    \ i \u5168\u4F53\u306B apply\n  void apply_xor_range(int l, int r, int xor_val,\
    \ A a) {\n    assert(!(n & (n - 1)));\n    assert(0 <= xor_val && xor_val < n);\n\
    \    assert(0 <= l && l <= r && r <= n);\n\n    auto dfs = [&](auto& dfs, int\
    \ idx, int seg_l, int seg_r) -> void {\n      if (l <= seg_l && seg_r <= r) {\n\
    \        return apply_at(idx, a);\n      }\n      if (r <= seg_l || seg_r <= l)\
    \ return;\n      push(idx);\n      int seg_m = (seg_l + seg_r) / 2;\n      int\
    \ bit = (seg_r - seg_l) / 2;\n      int left = 2 * idx + 0, right = 2 * idx +\
    \ 1;\n      if (xor_val & bit) swap(left, right);\n      dfs(dfs, left, seg_l,\
    \ seg_m);\n      dfs(dfs, right, seg_m, seg_r);\n      update(idx);\n    };\n\
    \    dfs(dfs, 1, 0, n);\n  }\n\n private:\n  void apply_at(int k, A a) {\n   \
    \ ll sz = 1 << (log - topbit(k));\n    dat[k] = AM::act(dat[k], a, sz);\n    if\
    \ (k < size) has_laz[k] = 1, laz[k] = MA::op(laz[k], a);\n  }\n  void push(int\
    \ k) {\n    if (!has_laz[k]) return;\n    has_laz[k] = 0;\n    apply_at(2 * k,\
    \ laz[k]), apply_at(2 * k + 1, laz[k]);\n    laz[k] = MA::id();\n  }\n};\n#line\
    \ 1 \"ds/segtree/segtree.hpp\"\n\ntemplate <class Monoid>\nstruct SegTree {\n\
    \  using MX = Monoid;\n  using X = typename MX::value_type;\n  using value_type\
    \ = X;\n  vc<X> dat;\n  int n, log, size;\n\n  SegTree() {}\n  SegTree(int n)\
    \ { build(n); }\n  template <typename F>\n  SegTree(int n, F f) {\n    build(n,\
    \ f);\n  }\n  SegTree(const vc<X>& v) { build(v); }\n\n  void build(int m) {\n\
    \    build(m, [](int i) -> X { return MX::id(); });\n  }\n  void build(const vc<X>&\
    \ v) {\n    build(len(v), [&](int i) -> X { return v[i]; });\n  }\n  template\
    \ <typename F>\n  void build(int m, F f) {\n    n = m, log = 0;\n    while ((1\
    \ << log) < n) ++log;\n    size = 1 << log;\n    dat.assign(size << 1, MX::id());\n\
    \    FOR(i, n) dat[size + i] = f(i);\n    FOR_R(i, 1, size) update(i);\n  }\n\n\
    \  X get(int i) const { return dat[size + i]; }\n  vc<X> get_all() const { return\
    \ {dat.begin() + size, dat.begin() + size + n}; }\n\n  void update(int i) { dat[i]\
    \ = Monoid::op(dat[2 * i], dat[2 * i + 1]); }\n  void set(int i, const X& x) {\n\
    \    assert(i < n);\n    dat[i += size] = x;\n    while (i >>= 1) update(i);\n\
    \  }\n\n  void multiply(int i, const X& x) {\n    assert(i < n);\n    i += size;\n\
    \    dat[i] = Monoid::op(dat[i], x);\n    while (i >>= 1) update(i);\n  }\n\n\
    \  X prod(int L, int R) const {\n    assert(0 <= L && L <= R && R <= n);\n   \
    \ X vl = Monoid::id(), vr = Monoid::id();\n    L += size, R += size;\n    while\
    \ (L < R) {\n      if (L & 1) vl = Monoid::op(vl, dat[L++]);\n      if (R & 1)\
    \ vr = Monoid::op(dat[--R], vr);\n      L >>= 1, R >>= 1;\n    }\n    return Monoid::op(vl,\
    \ vr);\n  }\n\n  vc<int> prod_ids(int L, int R) const {\n    assert(0 <= L &&\
    \ L <= R && R <= n);\n    vc<int> I, J;\n    L += size, R += size;\n    while\
    \ (L < R) {\n      if (L & 1) I.eb(L++);\n      if (R & 1) J.eb(--R);\n      L\
    \ >>= 1, R >>= 1;\n    }\n    reverse(all(J));\n    concat(I, J);\n    return\
    \ I;\n  }\n\n  X prod_all() const { return dat[1]; }\n\n  template <class F>\n\
    \  int max_right(F check, int L) const {\n    assert(0 <= L && L <= n && check(Monoid::id()));\n\
    \    if (L == n) return n;\n    L += size;\n    X sm = Monoid::id();\n    do {\n\
    \      while (L % 2 == 0) L >>= 1;\n      if (!check(Monoid::op(sm, dat[L])))\
    \ {\n        while (L < size) {\n          L = 2 * L;\n          if (check(Monoid::op(sm,\
    \ dat[L]))) {\n            sm = Monoid::op(sm, dat[L++]);\n          }\n     \
    \   }\n        return L - size;\n      }\n      sm = Monoid::op(sm, dat[L++]);\n\
    \    } while ((L & -L) != L);\n    return n;\n  }\n\n  template <class F>\n  int\
    \ min_left(F check, int R) const {\n    assert(0 <= R && R <= n && check(Monoid::id()));\n\
    \    if (R == 0) return 0;\n    R += size;\n    X sm = Monoid::id();\n    do {\n\
    \      --R;\n      while (R > 1 && (R % 2)) R >>= 1;\n      if (!check(Monoid::op(dat[R],\
    \ sm))) {\n        while (R < size) {\n          R = 2 * R + 1;\n          if\
    \ (check(Monoid::op(dat[R], sm))) {\n            sm = Monoid::op(dat[R--], sm);\n\
    \          }\n        }\n        return R + 1 - size;\n      }\n      sm = Monoid::op(dat[R],\
    \ sm);\n    } while ((R & -R) != R);\n    return 0;\n  }\n\n  // prod_{l<=i<r}\
    \ A[i xor x]\n  X xor_prod(int l, int r, int xor_val) const {\n    static_assert(Monoid::commute);\n\
    \    X x = Monoid::id();\n    for (int k = 0; k < log + 1; ++k) {\n      if (l\
    \ >= r) break;\n      if (l & 1) {\n        x = Monoid::op(x, dat[(size >> k)\
    \ + ((l++) ^ xor_val)]);\n      }\n      if (r & 1) {\n        x = Monoid::op(x,\
    \ dat[(size >> k) + ((--r) ^ xor_val)]);\n      }\n      l /= 2, r /= 2, xor_val\
    \ /= 2;\n    }\n    return x;\n  }\n\n  // f(i), i in I\n  // \u8FD1\u3044\u30A4\
    \u30F3\u30C7\u30C3\u30AF\u30B9\u3092\u5927\u91CF\u306B\u540C\u6642\u66F4\u65B0\
    \u3057\u305F\u3044\u3068\u304D\u306B\u52B9\u7387\u304C\u826F\u304F\u306A\u308B\
    \u3068\u3044\u3046\u72D9\u3044\n  template <typename F>\n  void set_many_sorted(vc<int>\
    \ I, F f) {\n    if (I.empty()) return;\n\n    FOR(k, len(I)) {\n      assert(0\
    \ <= I[k] && I[k] < n);\n      if (k) assert(I[k - 1] < I[k]);\n    }\n\n    FOR(k,\
    \ len(I)) {\n      int i = I[k];\n      dat[size + i] = f(i);\n      I[k] += size;\n\
    \    }\n\n    int m = len(I);\n    while (I[0] > 1) {\n      int nxt = 0;\n  \
    \    int last = -1;\n      FOR(k, m) {\n        int p = I[k] >> 1;\n        if\
    \ (p == last) continue;\n        update(p);\n        I[nxt++] = p;\n        last\
    \ = p;\n      }\n      m = nxt;\n    }\n  }\n};\n#line 4 \"flow/dynamic_mcf_on_line.hpp\"\
    \n\n// O(|cap| log N) per operation\ntemplate <typename T>\nstruct Dynamic_MCF_on_Line\
    \ {\n  int N;\n  T ANS;\n\n  using P = pair<T, int>;\n  struct Mono {\n    struct\
    \ X {\n      P from, to;\n    };\n    using value_type = X;\n    static X op(const\
    \ X& a, const X& b) {\n      return {min(a.from, b.from), min(a.to, b.to)};\n\
    \    }\n    static constexpr X id() { return {{infty<T>, -1}, {infty<T>, -1}};\
    \ }\n    static constexpr bool commute = true;\n  };\n\n  vc<map<T, int>> S_remain,\
    \ S_used;\n  vc<map<T, int>> T_remain, T_used;\n\n  SegTree<Mono> seg_terminal;\n\
    \n  struct Mono_Line {\n    struct X {\n      int left, right;\n    };\n    using\
    \ value_type = X;\n    static X op(const X& a, const X& b) {\n      return {min(a.left,\
    \ b.left), min(a.right, b.right)};\n    }\n    static constexpr X id() { return\
    \ {infty<int>, infty<int>}; }\n    static constexpr bool commute = true;\n  };\n\
    \n  struct AM {\n    using Monoid_X = Mono_Line;\n    using Monoid_A = Monoid_Add<int>;\n\
    \    using X = typename Monoid_X::value_type;\n    using A = typename Monoid_A::value_type;\n\
    \    static X act(X x, const A& a, const ll&) {\n      x.left += a, x.right -=\
    \ a;\n      return x;\n    }\n  };\n\n  using X = typename Mono_Line::value_type;\n\
    \  Lazy_SegTree<AM> seg_flow;\n\n  Dynamic_MCF_on_Line(int N, const vc<int>& right_cap,\
    \ const vc<int>& left_cap)\n      : N(N),\n        ANS(0),\n        S_remain(N),\n\
    \        S_used(N),\n        T_remain(N),\n        T_used(N),\n        seg_terminal(N)\
    \ {\n    assert(N > 0);\n    assert(len(right_cap) == N - 1);\n    assert(len(left_cap)\
    \ == N - 1);\n    FOR(i, N - 1) {\n      assert(right_cap[i] >= 0);\n      assert(left_cap[i]\
    \ >= 0);\n    }\n    seg_flow.build(\n        N - 1, [&](int i) -> X { return\
    \ {left_cap[i], right_cap[i]}; });\n  }\n\n  void add_source(int v, T cost, int\
    \ cap = 1) {\n    assert(0 <= v && v < N);\n    assert(cap >= 0);\n    mp_add(S_remain[v],\
    \ cost, cap);\n    update_terminal(v);\n\n    FOR(cap) {\n      auto [l, r] =\
    \ reachable_from(v);\n      // v -> ... -> w -> hub\n      auto [c, w] = seg_terminal.prod(l,\
    \ r + 1).to;\n      if (w == -1 || cost + c >= 0) break;\n      move_mp(S_remain[v],\
    \ S_used[v], cost, 1);\n      ANS += cost;\n      update_terminal(v);\n      push_line(v,\
    \ w, 1);\n      push_to_hub(w, c);\n    }\n  }\n\n  void add_sink(int v, T cost,\
    \ int cap = 1) {\n    assert(0 <= v && v < N);\n    assert(cap >= 0);\n\n    mp_add(T_remain[v],\
    \ cost, cap);\n    update_terminal(v);\n\n    FOR(cap) {\n      auto [l, r] =\
    \ reachable_to(v);\n      // hub -> w -> ... -> v\n      auto [c, w] = seg_terminal.prod(l,\
    \ r + 1).from;\n      if (w == -1 || c + cost >= 0) break;\n      push_from_hub(w,\
    \ c);\n      push_line(w, v, 1);\n      move_mp(T_remain[v], T_used[v], cost,\
    \ 1);\n      ANS += cost;\n      update_terminal(v);\n    }\n  }\n\n  void rm_source(int\
    \ v, T cost, int cap = 1) {\n    assert(0 <= v && v < N);\n    assert(cap >= 0);\n\
    \    int a = mp_count(S_remain[v], cost);\n    int b = mp_count(S_used[v], cost);\n\
    \    assert(a + b >= cap);\n\n    int k = min(cap, a);\n    mp_sub(S_remain[v],\
    \ cost, k);\n    cap -= k;\n    update_terminal(v);\n\n    FOR(cap) {\n      mp_sub(S_used[v],\
    \ cost, 1);\n      ANS -= cost;\n      update_terminal(v);\n      auto [l, r]\
    \ = reachable_to(v);\n      auto [c, w] = seg_terminal.prod(l, r + 1).from;\n\
    \      assert(w != -1);\n      push_from_hub(w, c);\n      push_line(w, v, 1);\n\
    \    }\n  }\n\n  void rm_sink(int v, T cost, int cap = 1) {\n    assert(0 <= v\
    \ && v < N);\n    assert(cap >= 0);\n    int a = mp_count(T_remain[v], cost);\n\
    \    int b = mp_count(T_used[v], cost);\n    assert(a + b >= cap);\n    int k\
    \ = min(cap, a);\n    mp_sub(T_remain[v], cost, k);\n    cap -= k;\n    update_terminal(v);\n\
    \    FOR(cap) {\n      mp_sub(T_used[v], cost, 1);\n      ANS -= cost;\n     \
    \ update_terminal(v);\n      auto [l, r] = reachable_from(v);\n      auto [c,\
    \ w] = seg_terminal.prod(l, r + 1).to;\n      assert(w != -1);\n      push_line(v,\
    \ w, 1);\n      push_to_hub(w, c);\n    }\n  }\n\n private:\n  static int mp_count(const\
    \ map<T, int>& mp, const T& x) {\n    auto it = mp.find(x);\n    return (it ==\
    \ mp.end() ? 0 : it->second);\n  }\n\n  static void mp_add(map<T, int>& mp, const\
    \ T& x, int k) {\n    assert(k >= 0);\n    if (k == 0) return;\n    mp[x] += k;\n\
    \  }\n\n  static void mp_sub(map<T, int>& mp, const T& x, int k) {\n    assert(k\
    \ >= 0);\n    if (k == 0) return;\n    auto it = mp.find(x);\n    assert(it !=\
    \ mp.end() && it->second >= k);\n    it->second -= k;\n    if (it->second == 0)\
    \ mp.erase(it);\n  }\n\n  static void move_mp(map<T, int>& A, map<T, int>& B,\
    \ const T& x, int k) {\n    mp_sub(A, x, k), mp_add(B, x, k);\n  }\n\n  void update_terminal(int\
    \ v) {\n    auto x = Mono::id();\n    if (!S_remain[v].empty()) chmin(x.from,\
    \ P{S_remain[v].begin()->first, v});\n    if (!T_used[v].empty()) chmin(x.from,\
    \ P{-T_used[v].rbegin()->first, v});\n    if (!T_remain[v].empty()) chmin(x.to,\
    \ P{T_remain[v].begin()->first, v});\n    if (!S_used[v].empty()) chmin(x.to,\
    \ P{-S_used[v].rbegin()->first, v});\n\n    seg_terminal.set(v, x);\n  }\n\n \
    \ void push_from_hub(int v, T cost) {\n    if (!S_remain[v].empty() && S_remain[v].begin()->first\
    \ == cost) {\n      move_mp(S_remain[v], S_used[v], cost, 1);\n      ANS += cost;\n\
    \      update_terminal(v);\n      return;\n    }\n\n    assert(!T_used[v].empty());\n\
    \    T c = T_used[v].rbegin()->first;\n    assert(-c == cost);\n\n    move_mp(T_used[v],\
    \ T_remain[v], c, 1);\n    ANS -= c;\n    update_terminal(v);\n  }\n\n  void push_to_hub(int\
    \ v, T cost) {\n    if (!T_remain[v].empty() && T_remain[v].begin()->first ==\
    \ cost) {\n      move_mp(T_remain[v], T_used[v], cost, 1);\n      ANS += cost;\n\
    \      update_terminal(v);\n      return;\n    }\n\n    assert(!S_used[v].empty());\n\
    \    T c = S_used[v].rbegin()->first;\n    assert(-c == cost);\n\n    move_mp(S_used[v],\
    \ S_remain[v], c, 1);\n    ANS -= c;\n    update_terminal(v);\n  }\n\n  // v \u304B\
    \u3089\u5230\u9054\u53EF\u80FD\u306A vertex interval [l, r]\n  pair<int, int>\
    \ reachable_from(int v) {\n    int l =\n        seg_flow.min_left([&](const X&\
    \ x) -> bool { return x.left > 0; }, v);\n    int r =\n        seg_flow.max_right([&](const\
    \ X& x) -> bool { return x.right > 0; }, v);\n    return {l, r};\n  }\n\n  //\
    \ v \u306B\u5230\u9054\u53EF\u80FD\u306A vertex interval [l, r]\n  pair<int, int>\
    \ reachable_to(int v) {\n    int l =\n        seg_flow.min_left([&](const X& x)\
    \ -> bool { return x.right > 0; }, v);\n    int r =\n        seg_flow.max_right([&](const\
    \ X& x) -> bool { return x.left > 0; }, v);\n    return {l, r};\n  }\n\n  void\
    \ push_line(int s, int t, int f) {\n    assert(f >= 0);\n    if (s == t || f ==\
    \ 0) return;\n\n    if (s < t) {\n      assert(seg_flow.prod(s, t).right >= f);\n\
    \      seg_flow.apply(s, t, +f);\n    } else {\n      assert(seg_flow.prod(t,\
    \ s).left >= f);\n      seg_flow.apply(t, s, -f);\n    }\n  }\n};\n"
  code: "#include \"alg/monoid/add.hpp\"\n#include \"ds/segtree/lazy_segtree.hpp\"\
    \n#include \"ds/segtree/segtree.hpp\"\n\n// O(|cap| log N) per operation\ntemplate\
    \ <typename T>\nstruct Dynamic_MCF_on_Line {\n  int N;\n  T ANS;\n\n  using P\
    \ = pair<T, int>;\n  struct Mono {\n    struct X {\n      P from, to;\n    };\n\
    \    using value_type = X;\n    static X op(const X& a, const X& b) {\n      return\
    \ {min(a.from, b.from), min(a.to, b.to)};\n    }\n    static constexpr X id()\
    \ { return {{infty<T>, -1}, {infty<T>, -1}}; }\n    static constexpr bool commute\
    \ = true;\n  };\n\n  vc<map<T, int>> S_remain, S_used;\n  vc<map<T, int>> T_remain,\
    \ T_used;\n\n  SegTree<Mono> seg_terminal;\n\n  struct Mono_Line {\n    struct\
    \ X {\n      int left, right;\n    };\n    using value_type = X;\n    static X\
    \ op(const X& a, const X& b) {\n      return {min(a.left, b.left), min(a.right,\
    \ b.right)};\n    }\n    static constexpr X id() { return {infty<int>, infty<int>};\
    \ }\n    static constexpr bool commute = true;\n  };\n\n  struct AM {\n    using\
    \ Monoid_X = Mono_Line;\n    using Monoid_A = Monoid_Add<int>;\n    using X =\
    \ typename Monoid_X::value_type;\n    using A = typename Monoid_A::value_type;\n\
    \    static X act(X x, const A& a, const ll&) {\n      x.left += a, x.right -=\
    \ a;\n      return x;\n    }\n  };\n\n  using X = typename Mono_Line::value_type;\n\
    \  Lazy_SegTree<AM> seg_flow;\n\n  Dynamic_MCF_on_Line(int N, const vc<int>& right_cap,\
    \ const vc<int>& left_cap)\n      : N(N),\n        ANS(0),\n        S_remain(N),\n\
    \        S_used(N),\n        T_remain(N),\n        T_used(N),\n        seg_terminal(N)\
    \ {\n    assert(N > 0);\n    assert(len(right_cap) == N - 1);\n    assert(len(left_cap)\
    \ == N - 1);\n    FOR(i, N - 1) {\n      assert(right_cap[i] >= 0);\n      assert(left_cap[i]\
    \ >= 0);\n    }\n    seg_flow.build(\n        N - 1, [&](int i) -> X { return\
    \ {left_cap[i], right_cap[i]}; });\n  }\n\n  void add_source(int v, T cost, int\
    \ cap = 1) {\n    assert(0 <= v && v < N);\n    assert(cap >= 0);\n    mp_add(S_remain[v],\
    \ cost, cap);\n    update_terminal(v);\n\n    FOR(cap) {\n      auto [l, r] =\
    \ reachable_from(v);\n      // v -> ... -> w -> hub\n      auto [c, w] = seg_terminal.prod(l,\
    \ r + 1).to;\n      if (w == -1 || cost + c >= 0) break;\n      move_mp(S_remain[v],\
    \ S_used[v], cost, 1);\n      ANS += cost;\n      update_terminal(v);\n      push_line(v,\
    \ w, 1);\n      push_to_hub(w, c);\n    }\n  }\n\n  void add_sink(int v, T cost,\
    \ int cap = 1) {\n    assert(0 <= v && v < N);\n    assert(cap >= 0);\n\n    mp_add(T_remain[v],\
    \ cost, cap);\n    update_terminal(v);\n\n    FOR(cap) {\n      auto [l, r] =\
    \ reachable_to(v);\n      // hub -> w -> ... -> v\n      auto [c, w] = seg_terminal.prod(l,\
    \ r + 1).from;\n      if (w == -1 || c + cost >= 0) break;\n      push_from_hub(w,\
    \ c);\n      push_line(w, v, 1);\n      move_mp(T_remain[v], T_used[v], cost,\
    \ 1);\n      ANS += cost;\n      update_terminal(v);\n    }\n  }\n\n  void rm_source(int\
    \ v, T cost, int cap = 1) {\n    assert(0 <= v && v < N);\n    assert(cap >= 0);\n\
    \    int a = mp_count(S_remain[v], cost);\n    int b = mp_count(S_used[v], cost);\n\
    \    assert(a + b >= cap);\n\n    int k = min(cap, a);\n    mp_sub(S_remain[v],\
    \ cost, k);\n    cap -= k;\n    update_terminal(v);\n\n    FOR(cap) {\n      mp_sub(S_used[v],\
    \ cost, 1);\n      ANS -= cost;\n      update_terminal(v);\n      auto [l, r]\
    \ = reachable_to(v);\n      auto [c, w] = seg_terminal.prod(l, r + 1).from;\n\
    \      assert(w != -1);\n      push_from_hub(w, c);\n      push_line(w, v, 1);\n\
    \    }\n  }\n\n  void rm_sink(int v, T cost, int cap = 1) {\n    assert(0 <= v\
    \ && v < N);\n    assert(cap >= 0);\n    int a = mp_count(T_remain[v], cost);\n\
    \    int b = mp_count(T_used[v], cost);\n    assert(a + b >= cap);\n    int k\
    \ = min(cap, a);\n    mp_sub(T_remain[v], cost, k);\n    cap -= k;\n    update_terminal(v);\n\
    \    FOR(cap) {\n      mp_sub(T_used[v], cost, 1);\n      ANS -= cost;\n     \
    \ update_terminal(v);\n      auto [l, r] = reachable_from(v);\n      auto [c,\
    \ w] = seg_terminal.prod(l, r + 1).to;\n      assert(w != -1);\n      push_line(v,\
    \ w, 1);\n      push_to_hub(w, c);\n    }\n  }\n\n private:\n  static int mp_count(const\
    \ map<T, int>& mp, const T& x) {\n    auto it = mp.find(x);\n    return (it ==\
    \ mp.end() ? 0 : it->second);\n  }\n\n  static void mp_add(map<T, int>& mp, const\
    \ T& x, int k) {\n    assert(k >= 0);\n    if (k == 0) return;\n    mp[x] += k;\n\
    \  }\n\n  static void mp_sub(map<T, int>& mp, const T& x, int k) {\n    assert(k\
    \ >= 0);\n    if (k == 0) return;\n    auto it = mp.find(x);\n    assert(it !=\
    \ mp.end() && it->second >= k);\n    it->second -= k;\n    if (it->second == 0)\
    \ mp.erase(it);\n  }\n\n  static void move_mp(map<T, int>& A, map<T, int>& B,\
    \ const T& x, int k) {\n    mp_sub(A, x, k), mp_add(B, x, k);\n  }\n\n  void update_terminal(int\
    \ v) {\n    auto x = Mono::id();\n    if (!S_remain[v].empty()) chmin(x.from,\
    \ P{S_remain[v].begin()->first, v});\n    if (!T_used[v].empty()) chmin(x.from,\
    \ P{-T_used[v].rbegin()->first, v});\n    if (!T_remain[v].empty()) chmin(x.to,\
    \ P{T_remain[v].begin()->first, v});\n    if (!S_used[v].empty()) chmin(x.to,\
    \ P{-S_used[v].rbegin()->first, v});\n\n    seg_terminal.set(v, x);\n  }\n\n \
    \ void push_from_hub(int v, T cost) {\n    if (!S_remain[v].empty() && S_remain[v].begin()->first\
    \ == cost) {\n      move_mp(S_remain[v], S_used[v], cost, 1);\n      ANS += cost;\n\
    \      update_terminal(v);\n      return;\n    }\n\n    assert(!T_used[v].empty());\n\
    \    T c = T_used[v].rbegin()->first;\n    assert(-c == cost);\n\n    move_mp(T_used[v],\
    \ T_remain[v], c, 1);\n    ANS -= c;\n    update_terminal(v);\n  }\n\n  void push_to_hub(int\
    \ v, T cost) {\n    if (!T_remain[v].empty() && T_remain[v].begin()->first ==\
    \ cost) {\n      move_mp(T_remain[v], T_used[v], cost, 1);\n      ANS += cost;\n\
    \      update_terminal(v);\n      return;\n    }\n\n    assert(!S_used[v].empty());\n\
    \    T c = S_used[v].rbegin()->first;\n    assert(-c == cost);\n\n    move_mp(S_used[v],\
    \ S_remain[v], c, 1);\n    ANS -= c;\n    update_terminal(v);\n  }\n\n  // v \u304B\
    \u3089\u5230\u9054\u53EF\u80FD\u306A vertex interval [l, r]\n  pair<int, int>\
    \ reachable_from(int v) {\n    int l =\n        seg_flow.min_left([&](const X&\
    \ x) -> bool { return x.left > 0; }, v);\n    int r =\n        seg_flow.max_right([&](const\
    \ X& x) -> bool { return x.right > 0; }, v);\n    return {l, r};\n  }\n\n  //\
    \ v \u306B\u5230\u9054\u53EF\u80FD\u306A vertex interval [l, r]\n  pair<int, int>\
    \ reachable_to(int v) {\n    int l =\n        seg_flow.min_left([&](const X& x)\
    \ -> bool { return x.right > 0; }, v);\n    int r =\n        seg_flow.max_right([&](const\
    \ X& x) -> bool { return x.left > 0; }, v);\n    return {l, r};\n  }\n\n  void\
    \ push_line(int s, int t, int f) {\n    assert(f >= 0);\n    if (s == t || f ==\
    \ 0) return;\n\n    if (s < t) {\n      assert(seg_flow.prod(s, t).right >= f);\n\
    \      seg_flow.apply(s, t, +f);\n    } else {\n      assert(seg_flow.prod(t,\
    \ s).left >= f);\n      seg_flow.apply(t, s, -f);\n    }\n  }\n};"
  dependsOn:
  - alg/monoid/add.hpp
  - ds/segtree/lazy_segtree.hpp
  - ds/segtree/segtree.hpp
  isVerificationFile: false
  path: flow/dynamic_mcf_on_line.hpp
  requiredBy: []
  timestamp: '2026-10-07 13:37:42+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: flow/dynamic_mcf_on_line.hpp
layout: document
redirect_from:
- /library/flow/dynamic_mcf_on_line.hpp
- /library/flow/dynamic_mcf_on_line.hpp.html
title: flow/dynamic_mcf_on_line.hpp
---
