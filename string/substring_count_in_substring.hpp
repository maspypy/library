
#include "ds/fenwicktree/fenwicktree.hpp"
#include "string/basic_substring_structure.hpp"

// pattern S[i,j) を重み w で追加. S[i,j) に含まれる pattern の総和を求める.
// offline で実装している (online 化は易しい)
template <typename WT, bool ONLINE>
struct Substring_Count_in_Substring {
  Basic_Substring_Structure BASS;
  vc<tuple<int, int, WT>> pattern;

  // 各行に対して block を含めず右にあるものの個数
  // 各行に対して block を含めて右にあるものの個数
  vc<WT> R0, R1;
  vc<WT> R0c;
  // 各列の上端に対して, 右下にあるものの個数
  vc<WT> RD;

  Substring_Count_in_Substring(Basic_Substring_Structure& BASS, vc<tuple<int, int, WT>> pattern) : BASS(BASS), pattern(pattern) { build(); }

  void build() {
    for (auto& [i, j, w]: pattern) {
      auto [a, b] = BASS.get_position(i, j);
      i = a, j = b;
    }
    int n = BASS.n_block();
    auto [H, W] = BASS.shape();
    R0.resize(H), R1.resize(H);
    for (auto& [a, b, w]: pattern) { R1[a] += w; }
    FOR(i, H) {
      int k = BASS.right[i];
      if (k != -1) R0[i] = R1[k];
      R1[i] += R0[i];
    }
    R0c = cumsum<WT>(R0);

    RD.resize(W);

    for (auto& [a, b, w]: pattern) RD[b] += w;
    FOR(k, n) {
      FOR_R(y, BASS.Y[k], BASS.Y[k + 1] - 1) { RD[y] += RD[y + 1]; }
    }

    FOR(y, W) {
      int k = BASS.Y_to_block[y];
      int a = BASS.X[k];
      int b = a + BASS.height[y];
      RD[y] += R0c[b] - R0c[a];
      if (BASS.down[y] != -1) RD[y] += RD[BASS.down[y]];
    }
    if (ONLINE) {
      // block 内の矩形クエリ用のデータ構造を構築
    }
  }

  vc<WT> sum_query(vc<pair<int, int>> query) {
    static_assert(!ONLINE);
    int Q = len(query);
    for (auto& [i, j]: query) {
      auto [a, b] = BASS.get_position(i, j);
      i = a, j = b;
    }
    vc<WT> ANS(Q);
    auto [H, W] = BASS.shape();
    vvc<int> PID(H), QID(H);
    FOR(i, len(pattern)) { PID[get<0>(pattern[i])].eb(i); }
    FOR(i, Q) { QID[query[i].fi].eb(i); }

    FenwickTree<Monoid_Add<WT>> bit(W);
    FOR_R(i, H) {
      for (int p: PID[i]) {
        auto [a, b, w] = pattern[p];
        bit.add(b, w);
      }
      int r = BASS.Y[BASS.X_to_block[i]] + BASS.width[i];
      for (int q: QID[i]) {
        auto [a, b] = query[q];
        ANS[q] += bit.sum(b, r);
        int k = BASS.X_to_block[a];
        int d = BASS.X[k] + BASS.height[b];
        ANS[q] += R0c[d] - R0c[a];
        int c = BASS.down[b];
        if (c != -1) ANS[q] += RD[c];
      }
    }
    return ANS;
  }

  WT sum_query(int i, int j) { assert(0); }
};
