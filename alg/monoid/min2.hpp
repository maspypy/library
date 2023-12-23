#pragma once

template <typename T, typename KEY>
struct Monoid_Min2 {
  struct Data {
    T min1, min2;
    KEY key1, key2;
    bool add_element(T x, KEY key) {
      if (key1 == key) { return chmin(min1, x); }
      if (key2 == key) {
        bool upd = chmin(min2, x);
        if (min1 > min2) swap(min1, min2), swap(key1, key2);
        return upd;
      }
      if (min1 > x) {
        min2 = min1, key2 = key1, min1 = x, key1 = key;
        return 1;
      }
      elif (min2 > x) {
        min2 = x, key2 = key;
        return 1;
      }
      return 0;
    }
  };
  using value_type = Data;
  using X = value_type;

  static X op(X x, X y) {
    x.add_element(y.min1, y.key1);
    x.add_element(y.min2, y.key2);
    return x;
  }
  static constexpr X unit() { return {infty<T>, infty<T>, -1, -1}; }
  static constexpr bool commute = true;
};