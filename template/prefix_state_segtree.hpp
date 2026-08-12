// template/prefix_state_segtree.hpp
/*
prefix state を持ちながら左から列を読むタイプの SegTree の骨格
StateMonoid:
  prefix state のモノイド
  init state が単位元で、区間を通ったときの state がモノイドの総積であるとする

AnswerMonoid:
  読んでいる途中で得られる答えのモノイド

内部ノード v=left+right には
  dat[v].state: 区間 v を init state から全部読んだときの finish state
  dat[v].r_ans:
    prefix state が dat[left].state の状態から right を読んだときの答え


次の実装は problem specific である

dfs(v, s):
  prefix state が s の状態から区間 v を読んだときの答えを得る

各高さで高々片方の子にしか再帰しないように書けば
update, query : O(log^2 n)
*/
template <typename StateMonoid, typename AnswerMonoid>
struct Prefix_State_SegTree {
  using MS = StateMonoid;
  using MX = AnswerMonoid;
  using S = typename MS::value_type;
  using X = typename MX::value_type;

  struct Data {
    S state;
    X r_ans;
  };

  int n, size, log;
  vc<Data> dat;

  Prefix_State_SegTree() {}

  template <typename F>
  Prefix_State_SegTree(int n, F f) {
    build(n, f);
  }

  template <typename F>
  void build(int m, F f) {
    n = m, log = 0;
    while ((1 << log) < n) ++log;
    size = 1 << log;

    dat.assign(2 * size, {MS::unit(), MX::unit()});
    FOR(i, n) dat[size + i].state = f(i);
    FOR_R(i, 1, size) update(i);
  }

  void set(int i, S s) {
    i += size;
    dat[i] = {s, MX::unit()};
    while (i > 1) i /= 2, update(i);
  }

  // prefix state = s から [L,R) を読んだときの finish state, ANS
  pair<S, X> prod(int L, int R, S s = MS::unit()) {
    vc<int> suff;
    X ans = MX::unit();

    L += size, R += size;
    while (L < R) {
      if (L & 1) {
        dfs(L, s, ans);
        s = MS::op(s, dat[L].state);
        ++L;
      }
      if (R & 1) suff.eb(--R);
      L /= 2, R /= 2;
    }

    reverse(all(suff));
    for (int v : suff) {
      dfs(v, s, ans);
      s = MS::op(s, dat[v].state);
    }
    return {s, ans};
  }

 private:
  void update(int v) {
    auto& L = dat[2 * v];
    auto& R = dat[2 * v + 1];
    dat[v].state = MS::op(L.state, R.state);
    dat[v].r_ans = MX::unit();
    dfs(2 * v + 1, L.state, dat[v].r_ans);
  }

  // prefix state = s から subtree v を読んだときの答え
  void dfs(int v, S s, X& ans) {
    // TODO: problem specific
    /* typically:
    if (size <= v) {
      // process leaf
      return;
    }

    int l = 2 * v, r = 2 * v + 1;
    auto& L = dat[l];

    // case 1: L での ans 更新が自明
    if (case1) {
      ans = MX::op(ans, left_ans);
      dfs(r, MS::op(s, dat[l].state), ans);
    }
    // case2: L での ans 更新が非自明かつ dat[l].state で終了
    if (case2) {
      dfs(l, s, ans);
      ans = MX::op(ans, dat[v].r_ans);
    }
    */
  }
};
