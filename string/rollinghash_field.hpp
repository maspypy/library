// +, -, * が定義された構造体を渡す
template <typename Field>
struct RollingHash_Field {
  using F = Field;
  const F base;
  vector<F> power;

  static inline F generate_base() { return RNG(1LL << 60); }

  inline void expand(int sz) {
    if (int(power.size()) < sz + 1) {
      int pre_sz = (int)power.size();
      power.resize(sz + 1);
      for (int i = pre_sz - 1; i < sz; i++) { power[i + 1] = power[i] * base; }
    }
  }

  explicit RollingHash_Field(F base = generate_base()) : base(base), power{1} {}

  template <typename STRING>
  vector<F> build(const STRING &s) const {
    int sz = s.size();
    vector<F> hashed(sz + 1);
    for (int i = 0; i < sz; i++) {
      hashed[i + 1] = (hashed[i] * base) + F(s[i]);
    }
    return hashed;
  }

  F query(const vector<F> &s, int l, int r) {
    expand(r - l);
    return s[r] - s[l] * power[r - l];
  }

  F combine(F h1, F h2, size_t h2len) {
    expand(h2len);
    return add(mul(h1, power[h2len]), h2);
  }

  int lcp(const vector<F> &a, int l1, int r1, const vector<F> &b, int l2,
          int r2) {
    int len = min(r1 - l1, r2 - l2);
    int low = 0, high = len + 1;
    while (high - low > 1) {
      int mid = (low + high) / 2;
      if (query(a, l1, l1 + mid) == query(b, l2, l2 + mid))
        low = mid;
      else
        high = mid;
    }
    return low;
  }
};