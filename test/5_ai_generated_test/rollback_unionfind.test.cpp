#include "my_template.hpp"
#include "ds/unionfind/rollback_unionfind.hpp"

/*
対象: ds/unionfind/rollback_unionfind.hpp と依存先 ds/rollback_array.hpp。
  merge、operator[]、size、time、rollback、reset、get_all を検証する。

独立オラクル: 各頂点の連結成分ラベルを vector<int> として直接管理する。
  マージは片方のラベルを全頂点について置換し、スナップショットは
  ラベル配列そのものをコピーする。UF 木や rollback 履歴は模倣しない。
  ラベルの数値そのものは任意なので、全頂点対の同値関係で比較する。

狙う不具合: マージ成功/失敗時の時刻更新、連結成分サイズ、同じ成分の
  再マージ、rollback 時に子だけ/親だけが復元される不整合、異なる
  スナップショットへ戻って枝分かれした後の古い状態、reset 後の残留。

条件: 頂点は 0 <= v < n、rollback は現在の時刻以下に取得した
  スナップショットに対してのみ行う。n=0 では頂点操作を行わない。
  n<=32、固定 seed 0x6117dabc による再現可能な乱択操作を用いる。
*/

struct Reference_Partition {
  vector<int> label;
  explicit Reference_Partition(int n) : label(n) {
    iota(label.begin(), label.end(), 0);
  }
  bool merge(int a, int b) {
    int x = label[a], y = label[b];
    if (x == y) return false;
    for (int& z : label) if (z == y) z = x;
    return true;
  }
  int size(int v) const {
    return int(count(label.begin(), label.end(), label[v]));
  }
};

struct Snapshot {
  int t;
  vector<int> label;
};

void check(Rollback_UnionFind& uf, const Reference_Partition& ref,
           int n, int step) {
  if (uf.time() < 0) abort();
  vector<int> roots = uf.get_all();
  if (int(roots.size()) != n) abort();
  for (int i = 0; i < n; ++i) {
    int root = uf[i];
    if (root != roots[i] || root < 0 || root >= n ||
        uf[root] != root || uf.size(i) != ref.size(i)) {
      cerr << "Rollback_UnionFind root/size mismatch n=" << n
           << " step=" << step << " v=" << i << '\n';
      abort();
    }
    for (int j = 0; j < n; ++j) {
      bool got = (roots[i] == roots[j]);
      bool expected = (ref.label[i] == ref.label[j]);
      if (got != expected) {
        cerr << "Rollback_UnionFind connectivity mismatch n=" << n
             << " step=" << step << " pair=(" << i << ',' << j << ")\n";
        abort();
      }
    }
  }
}

void run(int n, uint64_t seed) {
  Rollback_UnionFind uf(n);
  Reference_Partition ref(n);
  vector<Snapshot> snapshots{{uf.time(), ref.label}};
  mt19937_64 rng(seed ^ (uint64_t(n) * 0x9e3779b97f4a7c15ULL));
  if (uf.time() != 0) abort();
  check(uf, ref, n, -1);

  for (int step = 0; step < 4400; ++step) {
    int op = int(rng() % 16);
    if (n && op < 10) {
      int a = int(rng() % uint64_t(n));
      int b = (op == 0 ? a : int(rng() % uint64_t(n)));
      int before = uf.time();
      bool expected = ref.merge(a, b);
      bool got = uf.merge(a, b);
      if (got != expected || (got && uf.time() <= before) ||
          (!got && uf.time() != before)) {
        cerr << "Rollback_UnionFind merge/time mismatch n=" << n
             << " step=" << step << " a=" << a << " b=" << b << '\n';
        abort();
      }
    } else if (op < 12 && !snapshots.empty()) {
      // 過去の任意の祖先へ戻り、以後その時刻より未来の履歴は破棄する。
      int k = int(rng() % uint64_t(snapshots.size()));
      Snapshot s = snapshots[k];
      uf.rollback(s.t);
      ref.label = s.label;
      if (uf.time() != s.t) abort();
      snapshots.erase(remove_if(snapshots.begin(), snapshots.end(),
                                [&](const Snapshot& x) { return x.t > s.t; }),
                      snapshots.end());
    } else if (op == 12) {
      uf.reset();
      ref = Reference_Partition(n);
      snapshots = {{0, ref.label}};
      if (uf.time() != 0) abort();
    } else {
      snapshots.push_back({uf.time(), ref.label});
    }
    check(uf, ref, n, step);
  }

  // 任意の分岐の最終状態から初期状態まで戻す。
  uf.reset();
  ref = Reference_Partition(n);
  if (uf.time() != 0) abort();
  check(uf, ref, n, 5000);
  if (n >= 2) {
    int t = uf.time();
    uf.merge(0, 1);
    ref.merge(0, 1);
    check(uf, ref, n, 5001);
    uf.rollback(t);
    ref = Reference_Partition(n);
    check(uf, ref, n, 5002);
    // 同じ時刻から、別のマージを繰り返して履歴の使い回しを確認する。
    uf.merge(n - 1, 0);
    ref.merge(n - 1, 0);
    check(uf, ref, n, 5003);
    uf.rollback(t);
    ref = Reference_Partition(n);
    check(uf, ref, n, 5004);
  }
  cerr << "PASS rollback_unionfind n=" << n << '\n';
}

int main() {
  for (int n : {0, 1, 2, 3, 4, 7, 8, 16, 24, 32})
    run(n, 0x6117dabcULL);
}
