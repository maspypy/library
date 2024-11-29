#include "mod/modint61.hpp"

// 特に pop はテストされてない
template <typename CHAR>
struct Deque_Rolling_Hash {
  using mint = modint61;
  // prefix hash(n) = dat[n]+a*pow[n]
  mint a;
  mint base, ibase;
  vc<mint> pow_table;
  deque<CHAR> S;
  deque<mint> dat;
  Deque_Rolling_Hash() : a(0) { dat.eb(0); }

  void set_base(mint _base, mint _ibase) {
    base = _base, ibase = _ibase;
    assert(base * ibase == 1);
    pow_table = {mint(1), base};
  }
  int size() { return S.size(); }

  CHAR pop_l() {
    dat.pop_front();
    CHAR ch = S.front();
    S.pop_front();
    a = a * base - ch;
    return ch;
  }
  CHAR pop_r() {
    dat.pop_back();
    CHAR ch = S.back();
    S.pop_back();
    return ch;
  }

  void add_l(CHAR ch) {
    assert(len(pow_table) >= 2); // set base?
    S.emplace_front(ch);
    a = (a + ch) * ibase;
    dat.emplace_front(-a);
    assert(get(0, 1) != 0);
  }
  void add_r(CHAR ch) {
    assert(len(pow_table) >= 2); // set base?
    S.eb(ch), dat.eb(dat.back() * base + ch);
    assert(get(0, 1) != 0);
  }

  mint get(int l, int r) {
    assert(0 <= l && l <= r && r <= len(S));
    return dat[r] - dat[l] * pow(r - l);
  }

  mint pow(int i) {
    while (i >= len(pow_table)) pow_table.eb(pow_table.back() * pow_table[1]);
    return pow_table[i];
  }
};
