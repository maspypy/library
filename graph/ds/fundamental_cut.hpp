
// 木および, 2 点組 M 個を与える.
// set_on, set_off: M 個の組のオンオフができる.
// query(v): v, par[v] で分離される組の番号のひとつを出力
// https://codeforces.com/contest/1889/problem/E
template <typename TREE>
struct Fundamental_Cut {
  TREE& tree;

  int N, M;
  vc<int> A, B, on;
  vc<int> IA, IB, rk_A, rk_B, FA, FB;
  SegTree<Monoid_Max_Idx<int>> seg_AB;
  SegTree<Monoid_Min_Idx<int>> seg_BA;

  // f(i) = a, b, bool(on,off)
  template <typename F>
  Fundamental_Cut(TREE& tree, int M, F f) : tree(tree), N(tree.N), M(M) {
    FOR(i, M) {
      auto [a, b, t] = f(i);
      a = tree.LID[a], b = tree.LID[b];
      if (a > b) swap(a, b);
      A.eb(a), B.eb(b), on.eb(t);
    }
    IA = argsort(A), IB = argsort(B);
    rk_A = argsort(IA), rk_B = argsort(IB);
    seg_AB.build(M, [&](int i) -> pair<int, int> {
      if (!on[i]) return {-infty<int>, -1};
      return {B[IA[i]], IA[i]};
    });
    seg_BA.build(M, [&](int i) -> pair<int, int> {
      if (!on[i]) return {infty<int>, -1};
      return {A[IB[i]], IB[i]};
    });
    FA.resize(N + 1), FB.resize(N + 1);
    for (auto x : A) FA[1 + x]++;
    for (auto x : B) FB[1 + x]++;
    FOR(i, N) FA[i + 1] += FA[i], FB[i + 1] += FB[i];
  }

  void set_on(int i) {
    if (on[i]) return;
    on[i] = 1;
    seg_AB.set(rk_A[i], {B[i], i}), seg_BA.set(rk_B[i], {A[i], i});
  }

  void set_off(int i) {
    if (!on[i]) return;
    on[i] = 0;
    seg_AB.set(rk_A[i], {-infty<int>, -1}),
        seg_BA.set(rk_B[i], {infty<int>, -1});
  }

  int query(int v) {
    int L = tree.LID[v], R = tree.RID[v];
    int i = seg_AB.prod(FA[L], FA[R]).se;
    if (i != -1 && R <= B[i]) return i;
    i = seg_BA.prod(FB[L], FB[R]).se;
    if (i != -1 && A[i] < L) return i;
    return -1;
  }
};
