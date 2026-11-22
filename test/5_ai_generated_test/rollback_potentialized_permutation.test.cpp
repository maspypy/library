#include "my_template.hpp"
#include "other/io.hpp"

#include "ds/unionfind/rollback_potentialized_unionfind.hpp"

// 対象: Rollback_Potentialized_UnionFind<noncommutative Group>。
// S3 (3 点の置換) の積を使い、併合時の向き・逆元・重み付きunion-by-sizeと
// rollback の完全復元を検査する。既存の XOR 群による問題テストとは異なり、
// op(a,b)!=op(b,a) が頻繁に成立する。
// 独立オラクル: 採用した制約 P[v]=P[u]*w を有向辺として保存し、
// 毎回 DFS/BFS で全頂点の相対ポテンシャルを再構築する。
// 固定seed: 0x51A76B19。小さい森・連続併合・失敗併合・時刻巻き戻しを混在。
struct S3 {
  using value_type = array<int, 3>;
  static value_type id() { return {0, 1, 2}; }
  static value_type op(const value_type& a, const value_type& b) {
    value_type c;
    for (int i = 0; i < 3; ++i) c[i] = a[b[i]];
    return c;
  }
  static value_type inverse(const value_type& a) {
    value_type b;
    for (int i = 0; i < 3; ++i) b[a[i]] = i;
    return b;
  }
};

using Perm = S3::value_type;
struct Constraint {
  int a, b;
  Perm w;
};
struct Snapshot {
  int time;
  vector<Constraint> constraints;
};

[[noreturn]] void fail(int n, int trial, int step, int a, int b, const string& reason) {
  cerr << "rollback_potentialized: n=" << n << " trial=" << trial
       << " step=" << step << " pair=" << a << "," << b
       << " : " << reason << '\n';
  abort();
}

struct Oracle {
  vector<int> comp, sz;
  vector<Perm> val;
  explicit Oracle(int n, const vector<Constraint>& edges)
      : comp(n, -1), sz(n, 0), val(n, S3::id()) {
    vector<vector<pair<int, Perm>>> adj(n);
    for (auto [a, b, w] : edges) {
      adj[a].push_back({b, w});
      adj[b].push_back({a, S3::inverse(w)});
    }
    for (int r = 0; r < n; ++r) if (comp[r] == -1) {
      queue<int> q;
      comp[r] = r;
      q.push(r);
      while (!q.empty()) {
        int v = q.front(); q.pop();
        ++sz[r];
        for (auto [to, w] : adj[v]) {
          Perm next = S3::op(val[v], w);
          if (comp[to] == -1) {
            comp[to] = r;
            val[to] = next;
            q.push(to);
          } else if (val[to] != next) {
            cerr << "inconsistent oracle forest\n";
            abort();
          }
        }
      }
    }
  }
  bool same(int a, int b) const { return comp[a] == comp[b]; }
  Perm path(int a, int b) const { return S3::op(S3::inverse(val[a]), val[b]); }
  int size(int v) const { return sz[comp[v]]; }
};

void verify(Rollback_Potentialized_UnionFind<S3>& uf,
            int n, const vector<Constraint>& constraints,
            int trial, int step, mt19937& rng, bool exhaustive) {
  Oracle ref(n, constraints);
  vector<pair<int, Perm>> got(n);
  for (int v = 0; v < n; ++v) {
    got[v] = uf.get(v);
    if (got[v].first < 0 || got[v].first >= n)
      fail(n, trial, step, v, v, "invalid representative");
    if (uf.get(got[v].first).first != got[v].first)
      fail(n, trial, step, v, v, "nonroot representative");
    if (-uf.dat.get(got[v].first).first != ref.size(v))
      fail(n, trial, step, v, v, "incorrect component size");
  }
  int limit = exhaustive ? n * n : 15;
  for (int k = 0; k < limit; ++k) {
    int a = exhaustive ? (k / n) : int(rng() % n);
    int b = exhaustive ? (k % n) : int(rng() % n);
    if ((got[a].first == got[b].first) != ref.same(a, b))
      fail(n, trial, step, a, b, "incorrect connectivity");
    if (ref.same(a, b)) {
      Perm got_path = S3::op(S3::inverse(got[a].second), got[b].second);
      if (got_path != ref.path(a, b))
        fail(n, trial, step, a, b, "noncommutative potential mismatch");
    }
  }
}

int main() {
  mt19937 rng(0x51A76B19);
  vector<Perm> perms;
  Perm p = {0, 1, 2};
  do { perms.push_back(p); } while (next_permutation(p.begin(), p.end()));
  assert(perms.size() == 6);
  for (int n : {1, 2, 3, 6, 11, 24}) {
    for (int trial = 0; trial < 24; ++trial) {
      Rollback_Potentialized_UnionFind<S3> uf(n);
      vector<Constraint> edges;
      vector<Snapshot> hist = {{uf.time(), edges}};
      for (int step = 0; step < 450; ++step) {
        int action = int(rng() % 10);
        if (action == 0 && hist.size() > 1) {
          int k = int(rng() % hist.size());
          uf.rollback(hist[k].time);
          edges = hist[k].constraints;
          hist.resize(k + 1);
        } else {
          int a = int(rng() % n), b = int(rng() % n);
          Perm w = perms[rng() % 6];
          Oracle before(n, edges);
          int old_time = uf.time();
          bool joined = uf.merge(a, b, w);
          if (joined != !before.same(a, b))
            fail(n, trial, step, a, b, "merge result mismatch");
          if (joined) {
            edges.push_back({a, b, w});
            if (uf.time() != old_time + 2)
              fail(n, trial, step, a, b, "successful merge history length");
          } else if (uf.time() != old_time) {
            fail(n, trial, step, a, b, "failed merge changed history");
          }
        }
        verify(uf, n, edges, trial, step, rng, (step % 9 == 0));
        hist.push_back({uf.time(), edges});
      }
      uf.rollback(hist[0].time);
      verify(uf, n, {}, trial, 451, rng, true);
    }
  }
  return 0;
}
