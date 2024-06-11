// https://codeforces.com/gym/102331/problem/E
template <typename UINT, int LIM, typename WT>
struct Maximum_Weighted_Basis {
  array<int, LIM> idx;
  array<UINT, LIM> basis; // 簡約化された基底
  array<WT, LIM> wt;
  WT wt_sum;
  int dim, nxt_idx;

  Maximum_Weighted_Basis() {
    fill(all(idx), -1);
    fill(all(basis), 0);
    fill(all(wt), 0);
    wt_sum = 0, dim = 0, nxt_idx = 0;
  }

  int topbit(UINT x) {
    if constexpr (is_same_v<UINT, u128>) {
      return (x <= -1ull ? ::topbit(static_cast<u64>(x))
                         : 64 + ::topbit(static_cast<u64>(x >> 64)));
    } else {
      return ::topbit(x);
    }
  }

  // 消えるものの番号
  int add(UINT x, WT w) {
    int p = nxt_idx++;
    while (x) {
      int k = topbit(x);
      if (idx[k] == -1) {
        idx[k] = p, wt[k] = w, dim++, basis[k] = x, wt_sum += w;
        return -1;
      }
      if (wt[k] < w) {
        wt_sum = wt_sum - wt[k] + w;
        swap(idx[k], p), swap(wt[k], w), swap(basis[k], x);
      }
      x ^= basis[k];
    }
    return p;
  }
};
