#include "nt/primesum.hpp"
#include "nt/primetable.hpp"

template <typename T>
struct PrimeSum_Mod_4 {
  ll N;
  ll sqN;

  PrimeSum<T> A, B;
  PrimeSum_Mod_4(ll N) : N(N), sqN(sqrtl(N)), A(N), B(N) {}

  pair<T, T> operator[](ll x) {
    T a = A[x], b = B[x];
    return {(a + b) / T(2), (a - b) / T(2)};
  }

  void calc_count() {
    A.calc([](ll x) -> T { return (x + 1) / 2; });
    B.calc([](ll x) -> T { return ((x + 3) % 4 <= 1 ? 1 : 0); });
  }

  void calc_sum() {
    A.calc([](ll x) -> T {
      ll n = (x + 1) / 2;
      return T(n) * T(n);
    });
    B.calc([](ll x) -> T {
      ll n = (x + 1) / 2;
      return (n % 2 == 0 ? T(-n) : T(n));
    });
  }
};
