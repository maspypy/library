// 64-ary tree
// space: (N/63) * u64
struct FastSet {
  static constexpr u32 B = 64;
  int n = 0, log = 0;
  vvc<u64> seg;

  FastSet() {}
  FastSet(int n) { build(n); }

  int size() { return n; }

  void fill_one() {
    int cur = n;
    for (auto& vs : seg) {
      int p = cur / B, q = cur % B;
      FOR(i, p) vs[i] = -1ull;
      if (q) vs[p] = full_mask(q);
      cur = (cur + B - 1) / B;
    }
  }

  template <typename F>
  FastSet(int n, F f) {
    build(n, f);
  }

  void build(int m) {
    seg.clear();
    n = m;
    do {
      seg.push_back(vc<u64>((m + B - 1) / B));
      m = (m + B - 1) / B;
    } while (m > 1);
    log = len(seg);
  }
  template <typename F>
  void build(int n, F f) {
    build(n);
    FOR(i, n) { seg[0][i / B] |= u64(bool(f(i))) << (i % B); }
    FOR(h, log - 1) {
      FOR(i, len(seg[h])) {
        seg[h + 1][i / B] |= u64(bool(seg[h][i])) << (i % B);
      }
    }
  }

  bool operator[](int i) const {
    assert(0 <= i && i < n);
    return seg[0][i / B] >> (i % B) & 1;
  }
  void insert(int i) {
    assert(0 <= i && i < n);
    for (int h = 0; h < log; h++) {
      u64& x = seg[h][i / B];
      u64 mask = u64(1) << (i % B);
      if (x & mask) return;
      x |= mask;
      i /= B;
    }
  }
  void add(int i) { insert(i); }
  void erase(int i) {
    assert(0 <= i && i < n);
    for (int h = 0; h < log; h++) {
      u64& x = seg[h][i / B];
      u64 mask = u64(1) << (i % B);
      if (!(x & mask)) return;
      x ^= mask;
      if (x) return;
      i /= B;
    }
  }
  void remove(int i) { erase(i); }

  // min[x,n) or n
  int next(int i) {
    assert(i <= n);
    chmax(i, 0);
    for (int h = 0; h < log; h++) {
      if (i / B == seg[h].size()) break;
      u64 d = seg[h][i / B] >> (i % B);
      if (!d) {
        i = i / B + 1;
        continue;
      }
      i += lowbit(d);
      for (int g = h - 1; g >= 0; g--) {
        i *= B;
        i += lowbit(seg[g][i / B]);
      }
      return i;
    }
    return n;
  }

  // max [0,x], or -1
  int prev(int i) {
    assert(i >= -1);
    if (i >= n) i = n - 1;
    for (int h = 0; h < log; h++) {
      if (i == -1) break;
      u64 d = seg[h][i / B] << (63 - i % B);
      if (!d) {
        i = i / B - 1;
        continue;
      }
      i -= __builtin_clzll(d);
      for (int g = h - 1; g >= 0; g--) {
        i *= B;
        i += topbit(seg[g][i / B]);
      }
      return i;
    }
    return -1;
  }

  bool any(int l, int r) {
    assert(0 <= l && l <= r && r <= n);
    return next(l) < r;
  }

  // [l, r). erase=true のとき、callback 内から this を変更してはいけない。
  template <typename F>
  void enumerate(int l, int r, F f, bool erase = false) {
    assert(0 <= l && l <= r && r <= n);
    if (!erase) {
      for (int x = next(l); x < r; x = next(x + 1)) f(x);
      return;
    }
    for (int x = next(l); x < r;) {
      int w = x / B;
      int lo = max(l, w * int(B)) - w * int(B);
      int hi = min(r, (w + 1) * int(B)) - w * int(B);
      u64 erase_bits = seg[0][w] & (full_mask(hi) & ~full_mask(lo));
      u64 bits = erase_bits;
      while (bits) {
        int k = lowbit(bits);
        f(w * int(B) + k);
        bits ^= u64(1) << k;
      }
      seg[0][w] ^= erase_bits;
      if (!seg[0][w]) propagate_empty_word(w);
      x = next(min(r, (w + 1) * int(B)));
    }
  }

  void reset() {
    int x = next(0);
    while (x < n) {
      int w = x / B;
      seg[0][w] = 0;
      propagate_empty_word(w);
      x = next(min(n, (w + 1) * int(B)));
    }
  }

  string to_string() {
    string s(n, '?');
    for (int i = 0; i < n; ++i) s[i] = ((*this)[i] ? '1' : '0');
    return s;
  }

 private:
  // seg[0][w] が 0 になった後に呼ぶ。
  void propagate_empty_word(int i) {
    for (int h = 1; h < log; ++h) {
      u64& y = seg[h][i / B];
      u64 mask = u64(1) << (i % B);
      y ^= mask;
      if (y) break;
      i /= B;
    }
  }
};
