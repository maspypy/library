#include "ds/hashmap.hpp"
#include "random/base.hpp"

// どのくらい使えることがあるのか不明
// https://atcoder.jp/contests/ajo2025-final/submissions/71727945
// return: f(x,y),x,y
template <typename T, bool MINIMIZE, typename F>
tuple<T, ll, ll> optimize_2d(ll x1, ll x2, ll y1, ll y2, F f, int beam_width) {
  assert(x1 < x2 && y1 < y2);

  HashMap<T> MP;
  u64 rnd = RNG_64();
  auto eval = [&](ll x, ll y) -> T {
    T ans = f(x1 + x, y1 + y);
    if (!MINIMIZE) ans = -ans;
    return ans;
  };

  vc<tuple<T, ll, ll>> cand;
  cand.eb(eval(0, 0), 0, 0);

  ll X = x2 - x1, Y = y2 - y1;

  // スケールが全然違うときの対策のつもり
  ll KX = topbit(X) + 1;
  ll KY = topbit(Y) + 1;

  while (KX > 0 || KY > 0) {
    vc<tuple<T, ll, ll>> nxt = cand;
    auto upd = [&](ll x, ll y) -> void {
      if (0 <= x && x < X && 0 <= y && y < Y) {
        u64 key = rnd * x + y;
        if (MP.count(key)) return;
        T z = eval(x, y);
        MP[key] = z;
        nxt.eb(z, x, y);
      }
    };
    ll dx = 0, dy = 0;
    if (KX < KY) {
      --KY, dy = 1LL << KY;
    } else {
      --KX, dx = 1LL << KX;
    }
    for (auto& [v, x, y] : cand) {
      upd(x - dx, y - dy), upd(x + dx, y + dy);
    }
    swap(cand, nxt);
    // UNIQUE(cand);
    if (len(cand) > beam_width) {
      nth_element(cand.begin(), cand.begin() + beam_width, cand.end());
      cand.resize(beam_width);
    }
  }
  auto [v, x, y] = *(min_element(all(cand)));
  if (!MINIMIZE) v = -v;
  return {v, x1 + x, y1 + y};
}