template <typename T>
struct CartesianTree {
  /*
  辞書順で高さを unique して、木にしている。
  極大長方形アルゴリズムで線形時間構築。
  */
  int n;
  vc<T>& A;
  vc<pair<int, int>> range;
  vc<int> lch, rch, par;

  CartesianTree(vc<T> A) : n(len(A)), A(A) {
    range.assign(n, {-1, -1});
    lch.assign(n, -1);
    rch.assign(n, -1);
    par.assign(n, -1);
    auto is_sm = [&](int i, int j) -> bool {
      return (A[i] < A[j]) || (A[i] == A[j] && i < j);
    };
    vc<int> st;
    FOR(i, n) {
      while (!st.empty() && is_sm(i, st.back())) {
        lch[i] = st.back();
        st.pop_back();
      }
      range[i].fi = (st.empty() ? 0 : st.back() + 1);
      st.eb(i);
    }
    st.clear();
    FOR_R(i, n) {
      while (!st.empty() && is_sm(i, st.back())) {
        rch[i] = st.back();
        st.pop_back();
      }
      range[i].se = (st.empty() ? n : st.back());
      st.eb(i);
    }
    FOR(i, n) if (lch[i] != -1) par[lch[i]] = i;
    FOR(i, n) if (rch[i] != -1) par[rch[i]] = i;
  }
};
