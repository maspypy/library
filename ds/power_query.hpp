#include "alg/monoid/mul.hpp"

// 定数をべき乗するクエリ。 B 乗分ずつ前計算。
template <typename Mono, int B = 1024>
struct Power_Query {
  using X = typename Mono::value_type;
  vvc<X> dat;

  Power_Query(X a) { dat.eb(make_pow(a)); }

  X operator()(ll n) {
    X res = Mono::unit();
    int k = 0;
    while (n) {
      int r = n % B;
      n /= B;
      if (len(dat) == k) { dat.eb(make_pow(dat[k - 1].back())); }
      res = Mono::op(res, dat[k][r]);
      ++k;
    }
    return res;
  }

  X operator[](ll n) { return (*this)(n); }

private:
  vc<X> make_pow(X a) {
    vc<X> res = {Mono::unit()};
    FOR(B) { res.eb(Mono::op(res.back(), a)); }
    return res;
  }
};
