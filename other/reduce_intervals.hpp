
// rm_included = true : I < J となる J が存在すれば I を消す
// rm_included = false : I > J となる J が存在すれば I を消す
// 残す区間のインデックスを区間の順序についてソートして返す
// 完全に同じ区間は任意に選んだひとつだけ残す
template <typename T>
vc<int> reduce_intervals(vc<T> L, vc<T> R, bool rm_included) {
  int N = len(L);
  vc<int> ANS;
  vc<int> I(N);
  FOR(i, N) I[i] = i;
  if (rm_included) {
    sort(all(I), [&](auto &a, auto &b) -> bool {
      if (L[a] != L[b])
        return L[a] < L[b];
      return R[a] > R[b];
    });
    for (auto &j : I) {
      if (!ANS.empty()) {
        int i = ANS.back();
        if (R[j] <= R[i] && R[j] - L[j] <= R[i] - L[i])
          continue;
      }
      ANS.eb(j);
    }
  } else {
    sort(all(I), [&](auto &a, auto &b) -> bool {
      if (R[a] != R[b])
        return R[a] < R[b];
      return L[a] > L[b];
    });
    for (auto &j : I) {
      if (!ANS.empty()) {
        int i = ANS.back();
        if (R[j] <= R[i] && R[j] - L[j] == R[i] - L[i])
          continue;
      }
      ANS.eb(j);
    }
  }
  return ANS;
}
