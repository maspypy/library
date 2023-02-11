#include "ds/hashmap.hpp"
#include "ds/segtree/dual_segtree.hpp"
#include "alg/monoid/min.hpp"

// 点群 {p_i | i in [l, r)} に対する最近点対の計算を行うクエリ
// O(KNlogKN + QlogN)
// https://qoj.ac/problem/5463
// https://codeforces.com/gym/104172/attachments/download/18933/Hong_Kong_Tutorial.pdf
struct Range_Closest_Pair_Query {
  /*
  ・R を増やしながら、L ごとの答を管理する
  ・2^{k-1} <= ANS[L:R] < 2^{k} となる L ：レベル k （レベル 0：距離 0）
  ・レベル 0, 1, 2, ..., 29 のグリッドを用意する
  　・幅は 2^k
　  ・一辺 1.99 の正方形内で点対距離が 1 以上 → 8 個までありうる
  ・レベル 29, 28, ..., 0 の順に探索する：9 近傍
  　・答が見つかったらレベルを下げる。左向きに伝搬。
  　・レベルの減少は 30N 回までしか起きない
  */
  const int LOG = 30;
  vc<pair<int, int>> point;
  vc<pair<int, int>> query;
  void add_point(int x, int y) {
    assert(0 <= x && x < (1 << LOG));
    assert(0 <= y && y < (1 << LOG));
    point.eb(x, y);
  }
  void add_query(int L, int R) {
    assert(R - L >= 2);
    query.eb(L, R);
  }
  ll dist(int i, int j) {
    ll dx = point[i].fi - point[j].fi;
    ll dy = point[i].se - point[j].se;
    return dx * dx + dy * dy;
  }

  vc<ll> calc() {
    static HashMap<int> MP;
    const int K = LOG;
    const int N = len(point), Q = len(query);
    using A9 = array<int, 9>;
    // それぞれのレベルのときのセル番号
    vv(int, IDX, K, N, -1);
    // 各セル番号に対する近傍
    vc<A9> nbd;
    FOR(k, 1, K) {
      auto to_ll = [&](int x, int y) -> ll { return ll(x) << 30 | y; };
      int off = len(nbd);
      int p = off;
      MP.reset();
      FOR(i, N) {
        int x = point[i].fi >> (k);
        int y = point[i].se >> (k);
        ll key = to_ll(x, y);
        if (!MP.count(key)) MP[key] = p++;
        IDX[k][i] = MP[key];
      }
      nbd.resize(p);
      FOR(i, N) {
        int x = point[i].fi >> (k);
        int y = point[i].se >> (k);
        int me = MP[to_ll(x, y)];
        int s = 0;
        FOR(dx, -1, 2) FOR(dy, -1, 2) {
          ll key = to_ll(x + dx, y + dy);
          nbd[me][s++] = (MP.count(key) ? MP[key] : -1);
        }
      }
    }

    vc<array<int, 8>> dat(len(nbd), {-1, -1, -1, -1, -1, -1, -1, -1});
    auto add = [&](int k, int i) -> void {
      int idx = IDX[k][i];
      for (auto&& j: dat[idx]) {
        if (j == -1) {
          j = i;
          return;
        }
      }
    };
    auto rm = [&](int k, int i) -> void {
      int idx = IDX[k][i];
      for (auto&& j: dat[idx]) {
        if (j == i) {
          j = -1;
          return;
        }
      }
    };

    auto solve_level = [&](int k, int i) -> vc<pair<int, ll>> {
      // レベル k の点群に対する答の計算
      vc<pair<int, ll>> res;
      int me = IDX[k][i];
      for (auto&& idx: nbd[me]) {
        if (idx == -1) continue;
        for (auto&& j: dat[idx]) {
          if (j == -1) continue;
          res.eb(j, dist(i, j));
        }
      }
      return res;
    };
    Dual_SegTree<Monoid_Min<ll>> seg(N);
    vc<int> LEVEL(N, -1);
    auto get_lv = [&](ll d) -> int {
      if (d == 0) return 0;
      return topbit(d) / 2 + 1;
    };

    vc<int> left(Q);
    vvc<int> query_at(N);
    FOR(qid, Q) {
      auto [L, R] = query[qid];
      left[qid] = L;
      query_at[--R].eb(qid);
    }

    vi ANS(Q);

    FOR(R, N) {
      // R 番目の点を用いた答の更新
      vc<pair<int, ll>> upd;
      FOR(k, 1, K) {
        auto res = solve_level(k, R);
        upd.insert(upd.end(), all(res));
      }

      for (auto [i, d]: upd) {
        int lv = get_lv(d);
        if (seg.get(i) < d) continue;
        // 答えの更新
        seg.apply(0, i + 1, d);
        // レベルの更新
        while (i >= 0 && LEVEL[i] > lv) {
          rm(LEVEL[i], i);
          LEVEL[i] = lv;
          if (lv) add(lv, i);
          --i;
        }
      }
      LEVEL[R] = K - 1;
      add(K - 1, R);
      for (auto&& qid: query_at[R]) { ANS[qid] = seg.get(left[qid]); }
    }
    return ANS;
  }
};
