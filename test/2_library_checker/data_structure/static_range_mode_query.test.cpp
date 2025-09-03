#define PROBLEM "https://judge.yosupo.jp/problem/static_range_mode_query"

#include "my_template.hpp"
#include "other/io.hpp"

#include "ds/offline_query/rollback_mo.hpp"
#include "ds/to_small_key.hpp"

void solve() {
  INT(N, Q);
  VEC(int, A, N);
  vc<int> key = A;
  UNIQUE(key);
  for (auto& x: A) x = LB(key, x);

  Rollback_Mo mo;
  FOR(Q) {
    LL(L, R);
    mo.add(L, R);
  }
  vc<pair<int, int>> ANS(Q);

  vc<int> CNT(N);
  int max_cnt = 0;
  int max_key = 0;
  vc<int> history;

  auto add = [&](int i) -> void {
    int x = A[i];
    history.eb(x);
    CNT[x]++;
    if (chmax(max_cnt, CNT[x])) max_key = x;
  };

  auto reset = [&]() -> void {
    for (auto& x: history) CNT[x] = 0;
    history.clear();
    max_cnt = 0, max_key = 0;
  };

  int save_cnt = 0, save_key = 0;
  int save_time = 0;
  auto save = [&]() -> void {
    save_time = len(history);
    save_cnt = max_cnt, save_key = max_key;
  };

  auto rb = [&]() -> void {
    while (len(history) > save_time) {
      int x = POP(history);
      CNT[x]--;
    }
    max_cnt = save_cnt, max_key = save_key;
  };

  auto query = [&](int q) -> void { ANS[q] = {key[max_key], max_cnt}; };

  mo.calc(add, add, reset, save, rb, query);
  for (auto& x: ANS) print(x);
}

signed main() {
  solve();
  return 0;
}