template <typename VAL, typename SM>
struct My_Multiset {
  using T = VAL;
  int sz;
  SM sm_all;
  vvc<T> dat;
  vc<SM> sm;
  static const int BUCKET_RATIO = 50, REBUILD_RATIO = 170;

  My_Multiset() : sz(0), sm_all(0), dat(1), sm(1) {}

  void build(vc<T> vals) {
    sort(all(vals));
    sz = len(vals);
    int b_cnt = sqrt(sz / BUCKET_RATIO) + 1;
    dat.resize(b_cnt);
    FOR(i, b_cnt) {
      int l = sz * i / b_cnt, r = sz * (i + 1) / b_cnt;
      dat[i] = {vals.begin() + l, vals.begin() + r};
    }
    sm.resize(b_cnt);
    FOR(i, b_cnt) sm[i] = SUM<SM>(dat[i]);
    sm_all = SUM<SM>(sm);
  }

  int size() { return sz; }
  vc<T> get_all() {
    vc<T> res;
    for (auto&& x: dat) res.insert(res.end(), all(x));
    return res;
  }

  void rebuild() { build(get_all()); }

  void insert(T x) {
    if (sz == 0) {
      dat[0].eb(x);
      ++sz, sm[0] += x, sm_all += x;
      return;
    }
    FOR(idx, len(dat)) {
      if (dat[idx].back() < x && idx < len(dat) - 1) continue;
      dat[idx].insert(lower_bound(all(dat[idx]), x), x);
      ++sz, sm[idx] += x, sm_all += x;
      if (len(dat[idx]) > len(dat) * REBUILD_RATIO) rebuild();
      break;
    }
  }

  void erase(T x) {
    FOR(idx, len(dat)) {
      if (dat[idx].back() < x && idx < len(dat) - 1) continue;
      dat[idx].erase(lower_bound(all(dat[idx]), x));
      --sz, sm[idx] -= x, sm_all -= x;
      if (len(dat[idx]) == 0 && len(dat) > 0) {
        dat.erase(dat.begin() + idx);
        sm.erase(sm.begin() + idx);
      }
      break;
    }
  }

  int count(T x) {
    int cnt = 0;
    FOR(idx, len(dat)) {
      if (dat[idx].back() < x) continue;
      if (dat[idx][0] > x) break;
      if (dat[idx][0] == dat[idx].back())
        cnt += len(dat[idx]);
      else
        cnt += upper_bound(all(dat[idx]), x) - lower_bound(all(dat[idx]), x);
    }
    return cnt;
  }

  // {value[k], sum[0:k]}
  pair<VAL, SM> get_kth(int k, bool suffix = false) {
    assert(0 <= k && k <= sz);
    if (suffix) {
      if (k == sz) return {-infty<VAL>, sm_all};
      auto [x, s] = get_kth(sz - k - 1);
      return {x, sm_all - s - x};
    }
    SM s = 0;
    FOR(idx, len(dat)) {
      if (k >= len(dat[idx])) {
        k -= len(dat[idx]);
        s += sm[idx];
        continue;
      }
      FOR(j, k) s += dat[idx][j];
      return {dat[idx][k], s};
    }
    return {infty<VAL>, s};
  }

  // [lo, hi) で {cnt, sm}
  pair<int, SM> get_range(T lo, T hi) {
    int cnt = 0;
    SM s = 0;
    FOR(idx, len(dat)) {
      if (dat[idx].back() < lo) continue;
      if (hi <= dat[idx][0]) break;
      if (lo <= dat[idx][0] && dat[idx].back() < hi) {
        cnt += len(dat[idx]), s += sm[idx];
        continue;
      }
      for (auto&& x: dat[idx])
        if (lo <= x && x < hi) ++cnt, s += x;
    }
    return {cnt, s};
  }
};
