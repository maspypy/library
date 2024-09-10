template <typename Group>
struct Potentialized_UnionFind {
  using E = typename Group::value_type;
  int N;
  int n_comp;
  vc<E> vals;
  vc<int> par;
  vc<int> size;

  Potentialized_UnionFind(int N) : N(N), n_comp(N), vals(N, Group::unit()), size(N, 1) {
    par.resize(N);
    iota(all(par), 0);
  }

  // (root, P[root]^{-1}P[v])
  pair<int, E> get(int v) {
    E res = Group::unit();
    while (v != par[v]) {
      res = Group::op(vals[v], res);
      res = Group::op(vals[par[v]], res);
      vals[v] = Group::op(vals[par[v]], vals[v]);
      v = par[v] = par[par[v]];
    }
    return {v, res};
  }

  pair<int, E> operator[](int v) { return get(v); }

  // is_same / path value
  pair<bool, E> get_path(int u, int v) {
    auto [ru, xu] = get(u);
    auto [rv, xv] = get(v);
    if (ru != rv) return {false, Group::unit()};
    return {true, Group::op(Group::inverse(xu), xv)};
  }

  // if same : do nothing.
  // P[to]==P[frm]x
  bool merge(int frm, int to, E x) {
    auto [v1, x1] = get(frm);
    auto [v2, x2] = get(to);
    if (v1 == v2) return false; // same
    if (size[v1] < size[v2]) {
      swap(v1, v2);
      swap(x1, x2);
      x = Group::inverse(x);
    }
    x = Group::op(x1, x);
    x = Group::op(x, Group::inverse(x2));
    vals[v2] = x;
    par[v2] = v1;
    size[v1] += size[v2];
    --n_comp;
    return true;
  }
};