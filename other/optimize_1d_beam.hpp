
// return: f(x), x
template <typename T, bool MINIMIZE, typename F>
pair<T, ll> optimize_1d_beam(ll x1, ll x2, F f, int beam_width) {
  assert(x1 < x2);

  auto eval = [&](ll x) -> T {
    T v = f(x);
    if (!MINIMIZE) v = -v;
    return v;
  };

  // (value, x, l, r), interval = [l, r)
  using P = tuple<T, ll, ll, ll>;

  auto make = [&](ll l, ll r) -> P {
    ll x = (l + r) / 2;
    return {eval(x), x, l, r};
  };

  vc<P> cand;
  cand.eb(make(x1, x2));

  P best = cand[0];

  while (1) {
    vc<P> nxt;
    bool done = true;

    for (auto [v, x, l, r] : cand) {
      chmin(best, P{v, x, l, r});

      if (r - l == 1) continue;
      done = false;
      if (l < x) nxt.eb(make(l, x));
      if (x + 1 < r) nxt.eb(make(x + 1, r));
    }

    if (done || nxt.empty()) break;

    if (len(nxt) > beam_width) {
      nth_element(nxt.begin(), nxt.begin() + beam_width, nxt.end());
      nxt.resize(beam_width);
    }
    swap(cand, nxt);
  }

  auto [v, x, l, r] = best;
  if (!MINIMIZE) v = -v;
  return {v, x};
}
