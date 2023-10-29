#include "ds/my_bitset.hpp"

// mo + 最頻値クエリで使える
// most_freq_key：O(sqrt(N)+KEY_MAX/w)
// それ以外は O(1)
template <int USE_MAX_FREQ_KEY>
struct Counter {
  int N;
  int thresh;
  int ma;
  vc<int> freq;
  vc<int> freq_cnt;
  vc<My_Bitset> freq_to_key;

  // key が [0, N), 要素数が常に [0, N]
  Counter(int N) : N(N) {
    thresh = sqrtl(N);
    ma = 0;
    freq.assign(N, 0);
    freq_cnt.assign(N + 1, 0);
    freq_cnt[0] = N;
    if constexpr (USE_MAX_FREQ_KEY) {
      freq_to_key.assign(thresh + 1, My_Bitset(N));
    }
  }

  void insert(int k) {
    assert(0 <= k && k < N);
    if (ma == freq[k]) ++ma;
    if constexpr (USE_MAX_FREQ_KEY) {
      freq_to_key[min(thresh, freq[k])][k] = 0;
    }
    freq_cnt[freq[k]]--, freq[k]++, freq_cnt[freq[k]]++;
    if constexpr (USE_MAX_FREQ_KEY) {
      freq_to_key[min(thresh, freq[k])][k] = 1;
    }
  }
  void add(int k) { insert(k); }

  void erase(int k) {
    assert(0 <= k && k < N);
    if (ma == freq[k] && freq_cnt[freq[k]] == 1) --ma;
    if constexpr (USE_MAX_FREQ_KEY) {
      freq_to_key[min(thresh, freq[k])][k] = 0;
    }
    freq_cnt[freq[k]]--, freq[k]--, freq_cnt[freq[k]]++;
    if constexpr (USE_MAX_FREQ_KEY) {
      freq_to_key[min(thresh, freq[k])][k] = 1;
    }
  }
  void remove(int k) { erase(k); }

  int operator[](int x) { return freq[x]; }

  int max_freq() { return ma; }
  int max_freq_key() {
    static_assert(USE_MAX_FREQ_KEY);
    if (ma < thresh) return freq_to_key[mx]._Find_first();
    My_Bitset& b = freq_to_key[thresh];
    int p = b._Find_first();
    while (1) {
      if (freq[p] == mx) return p;
      p = b._Find_next(p);
    }
    assert(0);
    return -1;
  }
};