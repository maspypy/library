#define PROBLEM "https://judge.yosupo.jp/problem/double_ended_priority_queue"
#include "my_template.hpp"
#include "other/io.hpp"

#include "ds/double_end_queue.hpp"

void solve() {
  LL(N, Q);
  VEC(int, A, N);
  Double_End_Queue<int> que(A);
  FOR(Q) {
    INT(t);
    if (t == 0) {
      INT(x);
      que.push(x);
    }
    if (t == 1) print(que.pop_min());
    if (t == 2) print(que.pop_max());
  }
}

signed main() { solve(); }