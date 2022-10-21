#define PROBLEM "https://judge.yosupo.jp/problem/aplusb"
#include "my_template.hpp"
#include "other/io.hpp"
#include "random/base.hpp"
#include "nt/stern_brocot_tree.hpp"

void test() {
  using SBT = Stern_Brocot_Tree;
  // get_path
  assert(SBT::get_path({1, 1}) == vi());
  assert(SBT::get_path({1, 2}) == vi({0, 1}));
  assert(SBT::get_path({2, 1}) == vi({1}));
  assert(SBT::get_path({1, 3}) == vi({0, 2}));
  assert(SBT::get_path({2, 3}) == vi({0, 1, 1}));
  assert(SBT::get_path({3, 2}) == vi({1, 1}));
  assert(SBT::get_path({3, 1}) == vi({2}));
  assert(SBT::get_path({1, 4}) == vi({0, 3}));
  assert(SBT::get_path({2, 5}) == vi({0, 2, 1}));
  assert(SBT::get_path({3, 5}) == vi({0, 1, 1, 1}));
  assert(SBT::get_path({3, 4}) == vi({0, 1, 2}));
  assert(SBT::get_path({4, 3}) == vi({1, 2}));
  assert(SBT::get_path({5, 3}) == vi({1, 1, 1}));
  assert(SBT::get_path({5, 2}) == vi({2, 1}));
  assert(SBT::get_path({4, 1}) == vi({3}));
  // range
  assert(SBT::range({1, 1}) == mp(pi{0, 1}, pi{1, 0}));
  assert(SBT::range({1, 2}) == mp(pi{0, 1}, pi{1, 1}));
  assert(SBT::range({2, 1}) == mp(pi{1, 1}, pi{1, 0}));
  assert(SBT::range({1, 3}) == mp(pi{0, 1}, pi{1, 2}));
  assert(SBT::range({2, 3}) == mp(pi{1, 2}, pi{1, 1}));
  assert(SBT::range({3, 2}) == mp(pi{1, 1}, pi{2, 1}));
  assert(SBT::range({3, 1}) == mp(pi{2, 1}, pi{1, 0}));
  assert(SBT::range({1, 4}) == mp(pi{0, 1}, pi{1, 3}));
  assert(SBT::range({2, 5}) == mp(pi{1, 3}, pi{1, 2}));
  assert(SBT::range({3, 5}) == mp(pi{1, 2}, pi{2, 3}));
  assert(SBT::range({3, 4}) == mp(pi{2, 3}, pi{1, 1}));
  assert(SBT::range({4, 3}) == mp(pi{1, 1}, pi{3, 2}));
  assert(SBT::range({5, 3}) == mp(pi{3, 2}, pi{2, 1}));
  assert(SBT::range({5, 2}) == mp(pi{2, 1}, pi{3, 1}));
  assert(SBT::range({4, 1}) == mp(pi{3, 1}, pi{1, 0}));
  // child
  assert(SBT::child({1, 1}) == mp(pi{1, 2}, pi{2, 1}));
  assert(SBT::child({1, 2}) == mp(pi{1, 3}, pi{2, 3}));
  assert(SBT::child({2, 1}) == mp(pi{3, 2}, pi{3, 1}));
  assert(SBT::child({1, 3}) == mp(pi{1, 4}, pi{2, 5}));
  assert(SBT::child({2, 3}) == mp(pi{3, 5}, pi{3, 4}));
  assert(SBT::child({3, 2}) == mp(pi{4, 3}, pi{5, 3}));
  assert(SBT::child({3, 1}) == mp(pi{5, 2}, pi{4, 1}));
  // la
  pi NG = {-1, -1};
  assert(SBT::LA({1, 1}, 0) == pi({1, 1}));
  assert(SBT::LA({1, 1}, 1) == NG);
  assert(SBT::LA({3, 4}, 0) == pi({1, 1}));
  assert(SBT::LA({3, 4}, 1) == pi({1, 2}));
  assert(SBT::LA({3, 4}, 2) == pi({2, 3}));
  assert(SBT::LA({3, 4}, 3) == pi({3, 4}));
  assert(SBT::LA({3, 4}, 4) == NG);
  assert(SBT::LA({3, 5}, 0) == pi({1, 1}));
  assert(SBT::LA({3, 5}, 1) == pi({1, 2}));
  assert(SBT::LA({3, 5}, 2) == pi({2, 3}));
  assert(SBT::LA({3, 5}, 3) == pi({3, 5}));
  assert(SBT::LA({3, 5}, 4) == NG);

  auto get_random = [&]() -> pi {
    while (1) {
      ll x = RNG(1, 1LL << 60);
      ll y = RNG(1, 1LL << 60);
      if (gcd(x, y) > 1) continue;
      return {x, y};
    }
  };

  FOR(10000) {
    pi x = get_random();
    auto [l, r] = SBT::range(x);
    assert(i128(x.fi) * l.se - i128(x.se) * l.fi == 1);
    assert(i128(r.fi) * x.se - i128(r.se) * x.fi == 1);
    assert(l.fi + r.fi == x.fi && l.se + r.se == x.se);
    tie(l, r) = SBT::child(x);
    assert(i128(x.fi) * l.se - i128(x.se) * l.fi == 1);
    assert(i128(r.fi) * x.se - i128(r.se) * x.fi == 1);
    auto P = SBT::get_path(x);
    assert(SBT::from_path<ll>(P) == x);
    pi y = get_random();
    pi z = SBT::LCA(x, y);
    assert(SBT::in_subtree(x, z));
    assert(SBT::in_subtree(y, z));
    tie(l, r) = SBT::child(z);
    assert(!SBT::in_subtree(x, l) || !SBT::in_subtree(y, l));
    assert(!SBT::in_subtree(x, r) || !SBT::in_subtree(y, r));
  }
}

void solve() {
  LL(a, b);
  print(a + b);
}

signed main() {
  test();
  solve();

  return 0;
}