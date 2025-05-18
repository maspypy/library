#pragma once

template <typename CHAR>
struct Incremental_Lyndon_Factorization {
  vc<CHAR> S;
  int i = 0, j = 0, k = 0;
  vc<int> minimum_suffix_len = {0};

  int add(CHAR c) {
    S.eb(c);
    // [j, j+(i-k)) simple
    while (i < len(S)) {
      if (k == i) {
        assert(j == k);
        ++i;
      }
      elif (S[k] == S[i]) { ++k, ++i; }
      elif (S[k] < S[i]) { k = j, ++i; }
      else {
        j += (i - j) / (i - k) * (i - k);
        i = k = j;
      }
    }
    if ((i - j) % (i - k) == 0) {
      minimum_suffix_len.eb(i - k);
    } else {
      minimum_suffix_len.eb(minimum_suffix_len[k]);
    }
    return minimum_suffix_len[i];
  }

  vc<int> factorize() {
    int i = len(S);
    vc<int> I;
    while (i) {
      I.eb(i);
      i -= minimum_suffix_len[i];
    }
    I.eb(0);
    reverse(all(I));
    return I;
  }
};
