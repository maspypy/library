#include "nt/primesum.hpp"
#include "nt/primetable.hpp"

template <typename T>
struct PrimeSum_Mod_6 {
  ll N;
  ll sqN;

  PrimeSum<T> A, B;
  PrimeSum_Mod_6(ll N) : N(N), sqN(sqrtl(N)), A(N), B(N) {}

  pair<T, T> operator[](ll x) {
    T a = A[x], b = B[x];
    return {(a + b) / T(2), (a - b) / T(2)};
  }

  void calc_count() {
    A.calc([](ll x) -> T { return ((x + 2) / 3 - (x % 6 == 4)); });
    B.calc([](ll x) -> T { return ((x + 5) % 6 <= 3 ? 1 : 0); });
  }

  void calc_sum() {
    A.calc([](ll x) -> T {
      ll n = (x + 2) / 3 - (x % 6 == 4);
      ll k = n / 2;
      if (n % 2 == 0) { return T(6 * k) * T(k); }
      return T(6 * k) * T(k) + T(6 * k + 1);
    });
    B.calc([](ll x) -> T {
      ll n = (x + 2) / 3 - (x % 6 == 4);
      ll k = n / 2;
      if (n % 2 == 0) { return T(-4 * k); }
      return T(-4 * k + 6 * k + 1);
    });
  }
};
