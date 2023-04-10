#pragma once

#include "ds/hashmap.hpp"

template <typename GT>
vc<int> vs_to_es(GT& G, vc<int>& vs, bool allow_use_twice = false) {
  assert(!vs.empty());

  static HashMap<int> MP;
  MP.reset();
  vc<int> nxt(G.M, -1);

  auto get = [&](ll a, ll b) -> u64 {
    if (!G.is_directed() && a > b) swap(a, b);
    return a * G.N + b;
  };

  FOR(eid, G.M) {
    u64 k = get(G.edges[eid].frm, G.edges[eid].to);
    int x = MP[k];
    nxt[eid] = x, MP[k] = eid;
  }
  int n = len(vs);
  vc<int> es(n - 1);
  FOR(i, n - 1) {
    u64 k = get(vs[i], vs[i + 1]);
    int eid = MP.get(k, -1);
    assert(eid != -1);
    es[i] = eid;
    if (!allow_use_twice) { MP[k] = nxt[eid]; }
  }
  return es;
}