#include "my_template.hpp"
#include "other/io.hpp"
#include "ds/rmq/suffix_min.hpp"

/*
対象: ds/rmq/suffix_min.hpp の Suffix_Min<T> の set/query/reset。
契約: set(p,x) で末尾に追加し、query(i) は a[i..p) の最小値。
独立オラクル: 現在の vector を後ろから直接走査して min を計算。
狙う不具合: 単調スタックでの >= と重複、極端な単調列、最後の位置、
空区間 query(p)==infty<T>、複数回 reset した後の UF 残存状態。
set は必ず 0 <= p < N で呼び、値は有限かつ infty<T> より小さい。
固定seed=0x5AFF1A20261118ULL、N<=256、8種類の adversarial パターン＋乱択。
*/

[[noreturn]] static void fail(int n, int pattern, int p, int index,
                              int got, int want) {
  cerr << "suffix_min mismatch n=" << n << " pattern=" << pattern
       << " p=" << p << " index=" << index
       << " got=" << got << " want=" << want << '\n';
  abort();
}

static void verify(Suffix_Min<int>& d, const vector<int>& a, int n, int pat) {
  const int p = int(a.size());
  int current = infty<int>;
  // 遅い全区間最小を reverse に更新し、全 i を毎回チェックする。
  for (int i = p; i >= 0; --i) {
    if (i < p) current = min(current, a[i]);
    int got = d.query(i);
    if (got != current) fail(n, pat, p, i, got, current);
  }
}

int main() {
  mt19937_64 rng(0x5AFF1A20261118ULL);
  long long checked = 0;
  for (int n : {0, 1, 2, 3, 4, 7, 8, 9, 15, 16, 17,
                31, 32, 33, 63, 64, 65, 127, 128, 129, 255, 256}) {
    Suffix_Min<int> d(n);
    for (int pat = 0; pat < 10; ++pat) {
      if (pat) d.reset();
      vector<int> a;
      verify(d, a, n, pat); ++checked;
      for (int i = 0; i < n; ++i) {
        int x;
        switch (pat) {
          case 0: x = i; break;
          case 1: x = n - i; break;
          case 2: x = 0; break;
          case 3: x = (i % 2 ? 1000 : -1000); break;
          case 4: x = (i % 2 ? 1000 - i : -1000 + i); break;
          case 5: x = int(rng() % 5) - 2; break;
          case 6: x = int(rng() % 10001) - 5000; break;
          case 7: x = (i % 3 == 0 ? infty<int> - 1 : -infty<int> + 1); break;
          case 8: x = (i % 5) * 100 - (i / 5); break;
          default: x = (i % 7 == 0 ? -100 : int(rng() % 2001) - 1000); break;
        }
        d.set(i, x);
        a.push_back(x);
        verify(d, a, n, pat); ++checked;
      }
      d.reset();
      a.clear();
      verify(d, a, n, pat); ++checked;
      // 同一インスタンスで数回の再利用を検証。
      if (n >= 1) {
        d.set(0, -pat);
        a.push_back(-pat);
        verify(d, a, n, pat); ++checked;
      }
    }
  }
  cerr << "PASS suffix_min " << checked << " snapshots\n";
}
