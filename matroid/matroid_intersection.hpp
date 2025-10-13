
// https://codeforces.com/contest/1556/problem/H
// https://page.math.tu-berlin.de/~felsner/Lehre/SemMatS/Literatur/Schrijver-41:MatIntersection.pdf
// Matroid1: for_rm_add
// Matroid2: for_add_rm
template <class Matroid1, class Matroid2, typename WT>
struct Matroid_Intersection {
  Matroid1 &M1;
  Matroid2 &M2;
  int N;
  vc<WT> weight;

  Matroid_Intersection(Matroid1 &M1, Matroid2 &M2, vc<WT> weight)
      : M1(M1), M2(M2), weight(weight) {
    N = M1.size();
    assert(N == M2.size());
    pot.assign(N, 0);
  }

  // サイズを増やそうとする
  // 各サイズに対してそのサイズでの最大重みになる（入力もそうであることが必要）
  bool step(WT &wt, vc<bool> &I) {
    WT x = augment(I);
    wt += x;
    return x > 0;
  }

 private:
  vc<WT> pot, dist;
  vc<int> par;

  WT augment(vc<bool> &I) {
    assert(len(I) == N);
    M1.prepare(I), M2.prepare(I);
    dist.assign(N, infty<WT>);  // real_dist = pot + dist
    par.assign(N, -1);
    pq_min<pair<WT, int>> que;
    FOR(v, N) if (!I[v] && M1.can_add(v)) {
      dist[v] = -weight[v] - pot[v];
      que.emplace(dist[v], v);
    }
    int t = -1;
    WT best = infty<WT>;
    while (len(que)) {
      auto [pri, v] = POP(que);
      if (pri != dist[v]) continue;
      if (M2.can_add(v) && chmin(best, dist[v] + pot[v])) {
        t = v;
      }
      if (I[v]) {
        M1.for_rm_add(v, [&](int w) -> void {
          WT x = -weight[w] + pot[v] - pot[w];
          assert(x >= 0);
          if (chmin(dist[w], dist[v] + x)) par[w] = v, que.emplace(dist[w], w);
        });
      } else {
        M2.for_add_rm(v, [&](int w) -> void {
          WT x = weight[w] + pot[v] - pot[w];
          assert(x >= 0);
          if (chmin(dist[w], dist[v] + x)) par[w] = v, que.emplace(dist[w], w);
        });
      }
    }
    if (t == -1) return 0;
    WT ans = -(pot[t] + dist[t]);

    FOR(v, N) if (dist[v] < infty<WT>) pot[v] += dist[v];
    vc<WT> w1(N), w2(N);
    FOR(v, N) {
      if (I[v]) w1[v] = pot[v], w2[v] = weight[v] - pot[v];
      if (!I[v]) w1[v] = weight[v] + pot[v], w2[v] = -pot[v];
    }

    for (int v = t; v != -1; v = par[v]) I[v] = !I[v];
    FOR(v, N) { pot[v] = (I[v] ? w1[v] : -w2[v]); }
    return ans;
  }
};