// Source: https://github.com/maspypy/library/blob/main/convex/path_independent_set.hpp

// https://info.atcoder.jp/entry/algorithm_lectures/matching_on_path
// return: (val,i,j), 頂点重みの和と 2 点
template <typename T, bool MINIMIZE>
vc<tuple<T, int, int>> path_matching(vc<T> A) {
  vc<tuple<T, int, int>> dat;
  if constexpr (!MINIMIZE) {
    for (auto& x : A) x = -x;
  }
  dat.clear();
  vc<int> st;
  FOR(i, len(A)) {
    st.eb(i);
    while (len(st) >= 3) {
      int a = st[len(st) - 3], b = st[len(st) - 2], c = st[len(st) - 1];
      if (A[a] > A[c]) break;
      if (len(st) >= 4 && A[st[len(st) - 4]] < A[b]) break;
      dat.eb(A[a] + A[b], a, b);
      st[len(st) - 3] = c;
      st.pop_back(), st.pop_back();
    }
  }
  while (len(st) >= 2) {
    int b = POP(st);
    int a = POP(st);
    dat.eb(A[a] + A[b], a, b);
  }
  sort(all(dat));
  if (!MINIMIZE) {
    for (auto& [x, a, b] : dat) x = -x;
  }
  return dat;
}
