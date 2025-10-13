
struct Partition_Matroid {
  int N, C;
  vc<int> color, cap, cnt;
  vc<int> IDS, indptr;
  Partition_Matroid(vc<int> color, vc<int> capacity)
      : color(color), cap(capacity) {
    N = len(color);
    C = len(capacity);
    indptr.resize(C + 1);
    FOR(i, N) indptr[color[i] + 1]++;
    FOR(i, C) indptr[i + 1] += indptr[i];
    IDS.resize(N);
    FOR(i, N) IDS[indptr[color[i]]++] = i;
    FOR_R(i, 1, C) indptr[i] = indptr[i - 1];
    indptr[0] = 0;
  }

  int size() { return N; }

  const vc<bool> *I = nullptr;
  void prepare(const vc<bool> &_I) {
    I = &_I;
    cnt.assign(C, 0);
    FOR(i, N) cnt[color[i]] += (*I)[i];
  }

  bool can_add(int i) { return cnt[color[i]] < cap[color[i]]; }

  // i を削除して j を追加
  template <typename F>
  void for_rm_add(int i, F &&f) const {
    assert((*I)[i]);
    int c = color[i];
    if (cnt[c] < cap[c]) return;
    FOR(k, indptr[c], indptr[c + 1]) {
      int j = IDS[k];
      if (!(*I)[j]) f(j);
    }
  }
};
