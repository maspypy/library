
template <int KEY_MAX, int CNT_MAX, bool BS = false>
struct Counter {
  static constexpr int thresh = (BS ? sqrt(CNT_MAX) : 0);
  int mx;
  vc<int> freq;
  vc<int> freq_cnt;
  vc<bitset<KEY_MAX>> key; // freq -> key

  Counter() : mx(0), freq(KEY_MAX), freq_cnt(CNT_MAX + 1), key(thresh + 1) {
    freq_cnt[0] = KEY_MAX;
    key[0].set();
  }

  void insert(int k) {
    if (mx == freq[k]) ++mx;
    key[min(thresh, freq[k])][k] = 0;
    freq_cnt[freq[k]]--, freq[k]++, freq_cnt[freq[k]]++;
    key[min(thresh, freq[k])][k] = 1;
  }
  void add(int k) { insert(k); }

  void erase(int k) {
    if (mx == freq[k] && freq_cnt[freq[k]] == 1) --mx;
    key[min(thresh, freq[k])][k] = 0;
    freq_cnt[freq[k]]--, freq[k]--, freq_cnt[freq[k]]++;
    key[min(thresh, freq[k])][k] = 1;
  }
  void remove(int k) { erase(k); }

  int operator[](int x) { return freq[x]; }

  int max_freq() { return mx; }
  int max_freq_key() {
    static_assert(BS);
    if (mx < thresh) return key[mx]._Find_first();
    bitset<KEY_MAX>& b = key[thresh];
    int p = b._Find_first();
    while (1) {
      if (freq[p] == mx) return p;
      p = b._Find_next(p);
    }
    assert(0);
    return -1;
  }
};