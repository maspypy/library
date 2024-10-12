#include "ds/fastset.hpp"

// 2^i を足したり引いたり. k-th digit の取得.
// fastset 使用版.
// https://qoj.ac/problem/382
struct Redundant_Binary_Number_Fast {
  const int n;
  vc<char> dat;
  FastSet S;
  Redundant_Binary_Number_Fast(int n) : n(n), dat(n), S(n) {}

  int sgn() {
    int k = S.prev(n - 1);
    return (k == -1 ? 0 : dat[k]);
  }

  // k-th bit in [0,1]
  int kth(int k) {
    int j = S.prev(k - 1);
    int x = dat[k];
    int y = (j == -1 ? 0 : dat[j]);
    if (x == 0) return (y >= 0 ? 0 : 1);
    return (y >= 0 ? 1 : 0);
  }

  // 2^k * x を足す
  void add(int k, ll x) {
    while (x) {
      x += dat[k];
      dat[k] = x % 2;
      if (dat[k] == 0) {
        S.erase(k);
      } else {
        S.insert(k);
      }
      ++k, x /= 2;
    }
  }

  // 2^k を足す
  void add(int k) { add(k, 1); }
  void sub(int k) { add(k, -1); }

  string to_string() {
    string ANS;
    for (auto& x: dat) { ANS += (x == 0 ? '0' : (x == 1 ? '+' : '-')); }
    return ANS;
  }
};

// 2^i を足したり引いたり. k-th digit の取得.
template <typename KETA_TYPE = int>
struct Redundant_Binary_Number {
  using T = KETA_TYPE;
  map<T, char> dat;
  Redundant_Binary_Number() {}

  int sgn() {
    auto [k, x] = prev(infty<T>);
    return x;
  }

  // k-th bit in [0,1]
  int kth(T k) {
    int x = (dat.count(k) ? dat[k] : 0);
    int y = prev(k - 1).se;
    if (x == 0) return (y >= 0 ? 0 : 1);
    return (y >= 0 ? 1 : 0);
  }

  // 2^k * x を足す
  void add(T k, ll x) {
    while (x) {
      x += dat[k];
      if (x % 2 == 0) {
        dat.erase(k);
      } else {
        dat[k] = x % 2;
      }
      ++k, x /= 2;
    }
  }

  // 2^k を足す
  void add(T k) { add_inner(k, 1); }
  void sub(T k) { add_inner(k, -1); }

private:
  pair<T, char> prev(T k) {
    while (1) {
      auto it = dat.upper_bound(k);
      if (it == dat.begin()) return {-1, 0};
      it = ::prev(it);
      return *it;
    }
  }
};
