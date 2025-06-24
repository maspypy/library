#pragma once

template <typename T>
void superset_zeta(vc<T>& a) {
  int n = len(a);
  for (int i = 1; i != n; i <<= 1)
    for (int j = 0; j != n; j += i << 1)
      for (int k = 0; k != i; k++) a[j + k] += a[i + j + k];
}

template <typename T>
void superset_mobius(vc<T>& a) {
  int n = len(a);
  for (int i = 1; i != n; i <<= 1)
    for (int j = 0; j != n; j += i << 1)
      for (int k = 0; k != i; k++) a[j + k] -= a[i + j + k];
}

template <typename T>
void subset_zeta(vc<T>& a) {
  int n = len(a);
  for (int i = 1; i != n; i <<= 1)
    for (int j = 0; j != n; j += i << 1)
      for (int k = 0; k != i; k++) a[i + j + k] += a[j + k];
}

template <typename T>
void subset_mobius(vc<T>& a) {
  int n = len(a);
  for (int i = 1; i != n; i <<= 1)
    for (int j = 0; j != n; j += i << 1)
      for (int k = 0; k != i; k++) a[i + j + k] -= a[j + k];
}