#pragma once

namespace bitwise {

enum class trans_type {
  hadamard,
  superset_zeta,
  superset_mobius,
  subset_zeta,
  subset_mobius,
  ranked_zeta,
  ranked_mobius
};

template <typename ARR>
inline void ranked_add(ARR& a, const ARR& b) {
  for (int d = 0; d < int(a.size()); ++d) a[d] += b[d];
}

template <typename ARR>
inline void ranked_sub(ARR& a, const ARR& b) {
  for (int d = 0; d < int(a.size()); ++d) a[d] -= b[d];
}

template <trans_type type, int N, typename T>
inline void bitwise_transform_fixed(T* a) {
  static_assert(N >= 1 && (N & (N - 1)) == 0);
  if constexpr (N == 1) {
    return;
  } else {
    constexpr int H = N / 2;
    bitwise_transform_fixed<type, H>(a);
    bitwise_transform_fixed<type, H>(a + H);
    if constexpr (type == trans_type::hadamard) {
      for (int i = 0; i < H; ++i) {
        auto x = a[i], y = a[H + i];
        a[i] = x + y, a[H + i] = x - y;
      }
    }
    if constexpr (type == trans_type::superset_zeta) {
      for (int i = 0; i < H; ++i) a[i] += a[H + i];
    }
    if constexpr (type == trans_type::superset_mobius) {
      for (int i = 0; i < H; ++i) a[i] -= a[H + i];
    }
    if constexpr (type == trans_type::subset_zeta) {
      for (int i = 0; i < H; ++i) a[H + i] += a[i];
    }
    if constexpr (type == trans_type::subset_mobius) {
      for (int i = 0; i < H; ++i) a[H + i] -= a[i];
    }
    if constexpr (type == trans_type::ranked_zeta) {
      for (int i = 0; i < H; ++i) ranked_add(a[H + i], a[i]);
    }
    if constexpr (type == trans_type::ranked_mobius) {
      for (int i = 0; i < H; ++i) ranked_sub(a[H + i], a[i]);
    }
  }
}

template <trans_type type, int N, typename T>
inline void bitwise_transform_dispatch(vc<T>& a) {
  if (len(a) == N) {
    return bitwise_transform_fixed<type, N>(a.data());
  }
  if constexpr (N > 1) {
    return bitwise_transform_dispatch<type, N / 2>(a);
  }
}

template <trans_type type, typename T>
inline void bitwise_transform(vc<T>& a) {
  int n = len(a);
  assert(n >= 1);
  assert((n & (n - 1)) == 0);
  assert(n <= (1 << 25));
  bitwise_transform_dispatch<type, 1 << 25>(a);
}
}  // namespace bitwise
