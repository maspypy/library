#include "ds/csr.hpp"
#include "ds/to_small_key.hpp"

// given set S[0],...,S[N-1]
// Q query: calc |S[i] cap S[j]|
// M:=sum of size
// complexity: M sqrt{Q}/8
//
// https://codeforces.com/contest/2155/problem/F
// N,M,Q=300000, 300ms 程度
struct Offline_Set_Intersection {
  int N;
  To_Small_Key TSK;
  bool calculated;
  vc<pair<int, int>> dat;
  HashMap<int> query_id;
  vc<pair<int, int>> unique_query;
  vc<int> ids;

  // N: 集合の個数, K: 要素の種類数
  Offline_Set_Intersection(int N) : N(N), calculated(0) {}

  // x in S[i]
  // 同じ要素を 2 回登録すると壊れる（検査しない）
  void add(int i, int x) {
    assert(!calculated && 0 <= i && i < N);
    int k = TSK.query(x, true);
    dat.eb(i, k);
  }

  int get_qid(int i, int j) {
    if (i > j) swap(i, j);
    u64 k = u64(i) << 32 | u64(j);
    if (!query_id.count(k)) {
      query_id[k] = len(unique_query);
      unique_query.eb(i, j);
    }
    return query_id[k];
  }

  void query(int i, int j) {
    assert(!calculated && 0 <= i && i < N && 0 <= j && j < N);
    ids.eb(get_qid(i, j));
  }

  vc<int> calc() {
    assert(!calculated);
    calculated = true;
    int K = TSK.kind;
    int Q = len(unique_query);
    int B = sqrt(Q) / 8;
    vc<int> F(K);
    for (auto &[i, k] : dat) F[k]++;
    vc<int> heavy;
    FOR(k, K) if (F[k] >= B) heavy.eb(k);

    // StoX は light only
    CSR<int> StoX(N), XtoS(K), StoQ(N);
    for (auto &[i, k] : dat) {
      XtoS.add(k, i);
      if (F[k] < B) StoX.add(i, k);
    }
    FOR(q, Q) {
      auto [i, j] = unique_query[q];
      StoQ.add(i, q);
    }
    StoX.build(), XtoS.build(), StoQ.build();

    vc<int> ANS(Q);

    // heavy
    {
      vc<u64> A(N);
      vc<int> vis;
      for (int p = 0; p < len(heavy); p += 64) {
        vis.clear();
        // item [p,p+64)
        for (int idx = p; idx < p + 64; ++idx) {
          if (len(heavy) <= idx) break;
          for (auto &i : XtoS[heavy[idx]]) {
            A[i] ^= u64(1) << (idx - p);
            vis.eb(i);
          }
        }
        for (int q = 0; q < Q; ++q) {
          auto [i, j] = unique_query[q];
          ANS[q] += popcnt(A[i] & A[j]);
        }
        for (int i : vis) A[i] = 0;
      }
    }
    // light
    vc<int> A(N);
    FOR(i, N) {
      if (StoX[i].empty() || StoQ[i].empty()) continue;
      for (int x : StoX[i]) {
        for (int j : XtoS[x]) {
          A[j]++;
        }
      }
      for (int q : StoQ[i]) {
        int j = unique_query[q].se;
        ANS[q] += A[j];
      }
      for (int x : StoX[i]) {
        for (int j : XtoS[x]) {
          A[j]--;
        }
      }
    }
    ANS = rearrange(ANS, ids);
    return ANS;
  }
};