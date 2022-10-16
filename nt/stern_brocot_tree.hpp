
struct Stern_Brocot_Tree {
  using PATH = vi; // はじめは R

  static tuple<PATH, pi, pi> get_path_and_range(pi x) {
    PATH path;
    pi l = {0, 1}, r = {1, 0};
    pi m = {1, 1};
    ll det_l = l.fi * x.se - l.se * x.fi;
    ll det_r = r.fi * x.se - r.se * x.fi;
    ll det_m = det_l + det_r;
    while (1) {
      if (det_m == 0) break;
      ll k = ceil(-det_m, det_r);
      path.eb(k);
      l = {l.fi + k * r.fi, l.se + k * r.se};
      m = {l.fi + r.fi, l.se + r.se};
      det_l += k * det_r;
      det_m += k * det_r;
      if (det_m == 0) break;
      k = ceil(det_m, -det_l);
      path.eb(k);
      r = {r.fi + k * l.fi, r.se + k * l.se};
      m = {l.fi + r.fi, l.se + r.se};
      det_r += k * det_l;
      det_m += k * det_l;
    }
    return {path, l, r};
  }

  static PATH get_path(pi x) {
    auto [path, l, r] = get_path_and_range(x);
    return path;
  }

  static pair<pi, pi> range(pi x) {
    auto [path, l, r] = get_path_and_range(x);
    return {l, r};
  }

  // x in range(y)
  static bool in_subtree(pi x, pi y) {
    auto [l, r] = range(y);
    bool ok_l = i128(x.fi) * l.se - i128(x.se) * l.fi > 0;
    bool ok_r = i128(r.fi) * x.se - i128(r.se) * x.fi > 0;
    return ok_l && ok_r;
  }

  template <typename T = ll>
  static pair<T, T> from_path(PATH& p) {
    using P = pair<T, T>;
    P l = {0, 1}, r = {1, 0};
    FOR(i, len(p)) {
      ll k = p[i];
      if (i % 2 == 0) {
        l.fi += T(k) * r.fi;
        l.se += T(k) * r.se;
      }
      if (i % 2 == 1) {
        r.fi += T(k) * l.fi;
        r.se += T(k) * l.se;
      }
    }
    return {l.fi + r.fi, l.se + r.se};
  }

  static pair<pi, pi> child(pi x) {
    auto [l, r] = range(x);
    pi lc = {l.fi + x.fi, l.se + x.se};
    pi rc = {x.fi + r.fi, x.se + r.se};
    return {lc, rc};
  }

  static pi LCA(pi x, pi y) {
    auto Px = get_path(x);
    auto Py = get_path(y);
    vi P;
    FOR(i, min(len(Px), len(Py))) {
      ll k = min(Px[i], Py[i]);
      P.eb(k);
      if (k < Px[i] || k < Py[i]) break;
    }
    return from_path(P);
  }

  static pi LA(pi x, ll dep) {
    pi l = {0, 1}, r = {1, 0};
    pi m = {1, 1};
    ll det_l = l.fi * x.se - l.se * x.fi;
    ll det_r = r.fi * x.se - r.se * x.fi;
    ll det_m = det_l + det_r;
    while (1) {
      if (det_m == 0 || dep == 0) break;
      ll k = min(dep, ceil(-det_m, det_r));
      l = {l.fi + k * r.fi, l.se + k * r.se};
      m = {l.fi + r.fi, l.se + r.se};
      det_l += k * det_r;
      det_m += k * det_r;
      dep -= k;
      if (det_m == 0 || dep == 0) break;
      k = min(dep, ceil(det_m, -det_l));
      r = {r.fi + k * l.fi, r.se + k * l.se};
      m = {l.fi + r.fi, l.se + r.se};
      det_r += k * det_l;
      det_m += k * det_l;
      dep -= k;
    }
    if (dep == 0) return m;
    return {-1, -1};
  }

  static string to_string(PATH& p) {
    string res;
    char c = 'L';
    for (auto&& x: p) {
      c = 'L' + 'R' - c;
      if (x == 0) continue;
      res += c;
      res += " " + std::to_string(x);
    }
    return res;
  }
};
