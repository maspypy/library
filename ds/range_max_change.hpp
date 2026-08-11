/*
p をインクリメントしながら
right_change: ANS[i]:=max of [i,p) を管理
left_change: ANS[i]:=max of [p,i) を管理
i は [0,N+1) で空区間には -infty<T> を入れる
*/
template <typename T>
struct Range_Max_Change {
  vc<T> A;
  int N, pl, pr;
  bool prepared;
  Range_Max_Change(vc<T>& A) : A(A), N(len(A)), pl(0), pr(0), prepared(0) {}
  template <typename F>
  Range_Max_Change(int N, F f) : N(len(A)), pl(0), pr(0), prepared(0) {
    A.resize(N);
    FOR(i, N) A[i] = f(i);
  }

  vc<pair<int, T>> st_right;

  // p=i -> p=i+1
  // f(L,R,before,after)
  template <typename F>
  void right_change(int i, F f) {
    assert(pr == i);
    ++pr;
    int R = i;
    f(i, i + 1, -infty<T>, A[i]);
    while (len(st_right) && st_right.back().se <= A[i]) {
      auto [L, x] = POP(st_right);
      if (x != A[i]) f(L, R, x, A[i]);
      R = L;
    }
    st_right.eb(R, A[i]);
  }

  vc<tuple<int, int, int, T, T>> event_left;

  // p=i -> p=i+1
  // f(L,R,before,after)
  template <typename F>
  void left_change(int i, F f) {
    assert(pl == i && prepared);
    ++pl;
    while (len(event_left) && get<0>(event_left.back()) == i) {
      auto [j, L, R, a, b] = POP(event_left);
      f(L, R, b, a);
    }
  }

  // ANS[i]=max of [0,i) for i in [0,N+1)
  // f(L,R,x)
  template <typename F>
  void left_init(F f) {
    assert(!prepared);
    prepared = 1;

    vc<pair<int, T>> st;
    for (int i = N; i--;) {
      int R = i + 2;
      event_left.eb(i, i + 1, R, -infty<T>, A[i]);
      while (len(st) && st.back().se <= A[i]) {
        auto [RR, x] = POP(st);
        if (x != A[i]) event_left.eb(i, R, RR, x, A[i]);
        R = RR;
      }
      st.eb(R, A[i]);
    }

    f(0, 1, -infty<T>);
    int L = 1;
    for (int k = len(st); k--;) {
      auto [R, x] = st[k];
      f(L, R, x);
      L = R;
    }
  }
};