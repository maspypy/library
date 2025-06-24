#include "string/suffix_array.hpp"

// 辞書順 k 番目の suffix との LCP. k=0,1,2,... としたときの変化.
// return: {init,change}
// init[i] = lcp(0,i)
// change[k]: k->k+1, (l,r,x)
template <typename SUFFIX>
pair<vc<int>, vvc<tuple<int, int, int>>> suffix_lcp_change(SUFFIX& X) {
  auto& SA = X.SA;
  auto& LCP = X.LCP;
  int N = len(SA);
  vc<int> init(N);
  vvc<tuple<int, int, int>> left(N - 1), right(N - 1);
  {
    vc<tuple<int, int, int>> st;
    st.eb(0, 1, N - SA[0]);
    FOR(i, N - 1) {
      while (len(st)) {
        auto [l, r, x] = st.back();
        if (x <= LCP[i]) break;
        POP(st);
      }
      int s = (st.empty() ? 0 : get<1>(st.back()));
      st.eb(s, i + 1, LCP[i]);
      if (s < i + 1) left[i].eb(s, i + 1, LCP[i]);
      st.eb(i + 1, i + 2, N - SA[i + 1]);
    }
  }
  {
    vc<tuple<int, int, int>> st;
    st.eb(N - 1, N, N - SA[N - 1]);
    FOR_R(i, N - 1) {
      while (len(st)) {
        auto [l, r, x] = st.back();
        if (x <= LCP[i]) break;
        right[i].eb(l, r, x);
        POP(st);
      }
      int t = (st.empty() ? N : get<0>(st.back()));
      st.eb(i + 1, t, LCP[i]);
      st.eb(i, i + 1, N - SA[i]);
    }
    for (auto [l, r, x]: st) { FOR(i, l, r) init[i] = x; }
  }
  vvc<tuple<int, int, int>> change(N - 1);
  FOR(i, N - 1) {
    vc<tuple<int, int, int>> S;
    concat(S, left[i], right[i]);
    for (auto [l, r, x]: S) {
      if (!change[i].empty() && get<2>(change[i].back()) == x) {
        get<1>(change[i].back()) = r;
      } else {
        change[i].eb(l, r, x);
      }
    }
  }
  return {init, change};
}
