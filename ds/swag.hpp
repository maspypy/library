template <class Monoid>
struct SWAG {
  using X = typename Monoid::value_type;
  using value_type = X;
  int sz = 0;
  vc<X> dat;
  vc<X> cum_l;
  X cum_r;

  SWAG() : cum_l({Monoid::unit()}), cum_r(Monoid::unit()) {}

  int size() { return sz; }

  void push(X x) {
    ++sz;
    cum_r = Monoid::op(cum_r, x);
    dat.eb(x);
  }

  void pop() {
    --sz;
    cum_l.pop_back();
    if (len(cum_l) == 0) {
      cum_l = {Monoid::unit()};
      cum_r = Monoid::unit();
      while (len(dat) > 1) {
        cum_l.eb(Monoid::op(dat.back(), cum_l.back()));
        dat.pop_back();
      }
      dat.pop_back();
    }
  }

  X prod() { return Monoid::op(cum_l.back(), cum_r); }

  void debug() {
    print("swag");
    print("dat", dat);
    print("cum_l", cum_l);
    print("cum_r", cum_r);
  }
};
