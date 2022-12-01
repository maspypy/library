#pragma once

struct has_mod_impl {
  template <class T>
  static auto check(T&& x) -> decltype(x.get_mod(), std::true_type{});

  template <class T>
  static auto check(...) -> std::false_type;
};

template <class T>
class has_mod : public decltype(has_mod_impl::check<T>(std::declval<T>())) {};

template <class T, typename enable_if<has_mod<T>::value>::type* = nullptr>
vc<vc<T>> mat_mul(const vc<vc<T>>& A, const vc<vc<T>>& B) {
  const int mod = T::get_mod();
  auto N = len(A), M = len(B), K = len(B[0]);
  vv(int, b, K, M);
  FOR(i, M) FOR(j, K) b[j][i] = B[i][j].val;
  vv(T, C, N, K);
  FOR(i, N) {
    FOR(j, K) {
      i128 sm = 0;
      FOR(m, M) { sm += ll(A[i][m].val) * b[j][m]; }
      C[i][j] = sm % mod;
    }
  }
  return C;
}

template <class T, typename enable_if<!has_mod<T>::value>::type* = nullptr>
vc<vc<T>> mat_mul(const vc<vc<T>>& A, const vc<vc<T>>& B) {
  auto N = len(A), M = len(B), K = len(B[0]);
  vv(T, C, N, K);
  FOR(n, N) FOR(m, M) FOR(k, K) C[n][k] += A[n][m] * B[m][k];
  return C;
}
