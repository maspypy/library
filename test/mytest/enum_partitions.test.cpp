#define PROBLEM "https://judge.yosupo.jp/problem/aplusb"
#include "my_template.hpp"
#include "other/io.hpp"
#include "random/base.hpp"

#include "enumerate/partition.hpp"
#include "seq/famous/partition_number.hpp"

using mint = modint998;

void test() {
  FOR(N, 1, 10) {
    vc<mint> P = partition_number<mint>(N);
    set<vc<int>> ss;
    auto f = [&](vc<int>& P) -> void {
      assert(SUM<int>(P) == N);
      assert(!ss.count(P));
      ss.insert(P);
    };
    enumerate_partition<decltype(f)>(N, f);
    assert(P[N] == len(ss));
  }
  FOR(N, 1, 10) {
    FOR(LIM_len, 10) FOR(LIM_val, 10) {
      int a = 0;
      auto f = [&](vc<int>& P) -> void {
        if (len(P) <= LIM_len && MAX(P) <= LIM_val) ++a;
      };
      int b = 0;
      auto g = [&](vc<int>& P) -> void {
        assert(len(P) <= LIM_len && MAX(P) <= LIM_val);
        ++b;
      };
      enumerate_partition<decltype(f)>(N, f);
      enumerate_partition<decltype(g)>(N, g, LIM_len, LIM_val);
      assert(a == b);
    }
  }
}

void solve() {
  LL(a, b);
  print(a + b);
}

signed main() {
  cout << fixed << setprecision(15);

  test();
  solve();

  return 0;
}
