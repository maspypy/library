#pragma once

template <typename T, typename KEY>
struct Monoid_Max2 {
  struct Data {
    T max1, max2;
    KEY key1, key2;
    void add_element(T x, KEY key) {
      if (key1 == key) {
        chmax(max1, x);
        return;
      }
      if (key2 == key) {
        chmax(max2, x);
        if (max1 < max2) swap(max1, max2), swap(key1, key2);
        return;
      }
      if (max1 < x) { max2 = max1, key2 = key1, max1 = x, key1 = key; }
      elif (max2 < x) { max2 = x, key2 = key; }
    }
  };
  using value_type = Data;
  using X = value_type;

  static X op(X x, X y) {
    x.add_element(y.max1, y.key1);
    x.add_element(y.max2, y.key2);
    return x;
  }
  static constexpr X unit() { return {-infty<T>, -infty<T>, 0, 0}; }
  static constexpr bool commute = true;
};