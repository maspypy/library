#pragma once

#include "alg/monoid/min.hpp"
#include "ds/sparse_table/sparse_table.hpp"

// 辞書順 i 番目の suffix が j 文字目始まりであるとき、
// SA[i] = j, ISA[j] = i
struct Suffix_Array {
  vector<int> SA;
  vector<int> ISA;
  vector<int> LCP;
  Sparse_Table<Monoid_Min<int>> seg;
  // DisjointSparse<Monoid_Min<int>> seg;

  Suffix_Array(string& s, bool lcp_query = false) {
    char first = 127, last = 0;
    for (auto&& c: s) {
      chmin(first, c);
      chmax(last, c);
    }
    SA = calc_suffix_array(s, first, last);
    calc_LCP(s);
    if (lcp_query) seg.build(LCP);
  }

  Suffix_Array(vector<int>& s, bool lcp_query = false) {
    SA = calc_suffix_array(s);
    calc_LCP(s);
    if (lcp_query) seg.build(LCP);
  }

  // lcp(S[i:], S[j:])
  int lcp(int i, int j) {
    int n = len(SA);
    if (i == n || j == n) return 0;
    if (i == j) return n - i;
    i = ISA[i], j = ISA[j];
    if (i > j) swap(i, j);
    return seg.prod(i, j);
  }

private:
  void induced_sort(const std::vector<int>& vect, int val_range,
                    std::vector<int>& SA, const std::vector<bool>& sl,
                    const std::vector<int>& lms_idx) {
    std::vector<int> l(val_range, 0), r(val_range, 0);
    for (int c: vect) {
      if (c + 1 < val_range) ++l[c + 1];
      ++r[c];
    }
    std::partial_sum(l.begin(), l.end(), l.begin());
    std::partial_sum(r.begin(), r.end(), r.begin());
    std::fill(SA.begin(), SA.end(), -1);
    for (int i = (int)lms_idx.size() - 1; i >= 0; --i)
      SA[--r[vect[lms_idx[i]]]] = lms_idx[i];
    for (int i: SA)
      if (i >= 1 && sl[i - 1]) SA[l[vect[i - 1]]++] = i - 1;
    std::fill(r.begin(), r.end(), 0);
    for (int c: vect) ++r[c];
    std::partial_sum(r.begin(), r.end(), r.begin());
    for (int k = (int)SA.size() - 1, i = SA[k]; k >= 1; --k, i = SA[k])
      if (i >= 1 && !sl[i - 1]) { SA[--r[vect[i - 1]]] = i - 1; }
  }

  std::vector<int> SA_IS(const std::vector<int>& vect, int val_range) {
    const int n = vect.size();
    std::vector<int> SA(n), lms_idx;
    std::vector<bool> sl(n);
    sl[n - 1] = false;
    for (int i = n - 2; i >= 0; --i) {
      sl[i] = (vect[i] > vect[i + 1] || (vect[i] == vect[i + 1] && sl[i + 1]));
      if (sl[i] && !sl[i + 1]) lms_idx.push_back(i + 1);
    }
    std::reverse(lms_idx.begin(), lms_idx.end());
    induced_sort(vect, val_range, SA, sl, lms_idx);
    std::vector<int> new_lms_idx(lms_idx.size()), lms_vec(lms_idx.size());
    for (int i = 0, k = 0; i < n; ++i)
      if (!sl[SA[i]] && SA[i] >= 1 && sl[SA[i] - 1]) {
        new_lms_idx[k++] = SA[i];
      }
    int cur = 0;
    SA[n - 1] = cur;
    for (size_t k = 1; k < new_lms_idx.size(); ++k) {
      int i = new_lms_idx[k - 1], j = new_lms_idx[k];
      if (vect[i] != vect[j]) {
        SA[j] = ++cur;
        continue;
      }
      bool flag = false;
      for (int a = i + 1, b = j + 1;; ++a, ++b) {
        if (vect[a] != vect[b]) {
          flag = true;
          break;
        }
        if ((!sl[a] && sl[a - 1]) || (!sl[b] && sl[b - 1])) {
          flag = !((!sl[a] && sl[a - 1]) && (!sl[b] && sl[b - 1]));
          break;
        }
      }
      SA[j] = (flag ? ++cur : cur);
    }
    for (size_t i = 0; i < lms_idx.size(); ++i) lms_vec[i] = SA[lms_idx[i]];
    if (cur + 1 < (int)lms_idx.size()) {
      auto lms_SA = SA_IS(lms_vec, cur + 1);
      for (size_t i = 0; i < lms_idx.size(); ++i) {
        new_lms_idx[i] = lms_idx[lms_SA[i]];
      }
    }
    induced_sort(vect, val_range, SA, sl, new_lms_idx);
    return SA;
  }

  std::vector<int> calc_suffix_array(const std::string& s,
                                     const char first = 'a',
                                     const char last = 'z') {
    std::vector<int> vect(s.size() + 1);
    std::copy(std::begin(s), std::end(s), std::begin(vect));
    for (auto& x: vect) x -= (int)first - 1;
    vect.back() = 0;
    auto ret = SA_IS(vect, (int)last - (int)first + 2);
    ret.erase(ret.begin());
    return ret;
  }

  std::vector<int> calc_suffix_array(const vector<int>& s) {
    vector<int> ss = s;
    sort(ss.begin(), ss.end());
    ss.erase(unique(ss.begin(), ss.end()), ss.end());

    std::vector<int> vect(s.size() + 1);
    std::copy(std::begin(s), std::end(s), std::begin(vect));
    for (auto& x: vect)
      x = lower_bound(ss.begin(), ss.end(), x) - ss.begin() + 1;
    vect.back() = 0;
    auto ret = SA_IS(vect, *max_element(vect.begin(), vect.end()) + 2);
    ret.erase(ret.begin());
    return ret;
  }

  template <typename STRING>
  void calc_LCP(const STRING& s) {
    int n = s.size(), k = 0;
    ISA.resize(n);
    LCP.resize(n);
    for (int i = 0; i < n; i++) ISA[SA[i]] = i;
    for (int i = 0; i < n; i++, k ? k-- : 0) {
      if (ISA[i] == n - 1) {
        k = 0;
        continue;
      }
      int j = SA[ISA[i] + 1];
      while (i + k < n && j + k < n && s[i + k] == s[j + k]) k++;
      LCP[ISA[i]] = k;
    }
    LCP.resize(n - 1);
  }
};