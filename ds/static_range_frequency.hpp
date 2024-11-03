
#include "ds/to_small_key.hpp"

struct Static_Range_Frequency {
  vc<int> pos, indptr;
  To_Small_Key S;

  template <typename T>
  Static_Range_Frequency(vc<T>& A) {
    build(len(A), [&](int i) -> u64 { return A[i]; });
  }

  template <typename F>
  Static_Range_Frequency(int N, F f) {
    build(N, f);
  }

  template <typename F>
  void build(int N, F f) {
    S.reserve(N);
    pos.resize(N);
    vc<int> cnt(N + 1), dat(N);
    FOR(i, N) {
      u64 x = f(i);
      int k = S.query(x, true);
      cnt[1 + k]++, dat[i] = k;
    }
    FOR(k, N) cnt[1 + k] += cnt[k];
    indptr = cnt;
    FOR(i, N) pos[cnt[dat[i]]++] = i;
  }

  int query(int L, int R, u64 x) {
    int k = S.query(x, false);
    if (k == -1) return 0;
    int a = indptr[k], b = indptr[k + 1];
    auto nl = lower_bound(pos.begin() + a, pos.begin() + b, L);
    auto nr = lower_bound(pos.begin() + a, pos.begin() + b, R);
    return nr - nl;
  }
};