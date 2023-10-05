
/*
c <= LIM, (a,b,c) と (b,a,c) は同一視, O(LIM) 時間
・LIM = 10^8：互いに素 1.59*10^7 個, 0.13sec
・LIM = 10^8：全部 2.71*10^8 個, 0.53sec
https://codeforces.com/contest/60/problem/D
*/
template <bool coprime_only, typename F>
void enumerate_pytagorean_triple(int LIM, F f) {
  vc<tuple<int, int, int>> que;
  auto add = [&](int a, int b, int c) -> void {
    if (c <= LIM) que.eb(a, b, c);
  };
  add(3, 4, 5);
  while (len(que)) {
    auto [a, b, c] = POP(que);
    add(a - 2 * b + 2 * c, 2 * a - b + 2 * c, 2 * a - 2 * b + 3 * c);
    add(a + 2 * b + 2 * c, 2 * a + b + 2 * c, 2 * a + 2 * b + 3 * c);
    add(-a + 2 * b + 2 * c, -2 * a + b + 2 * c, -2 * a + 2 * b + 3 * c);
    if constexpr (coprime_only) {
      f(a, b, c);
    } else {
      int x = a, y = b, z = c;
      while (z <= LIM) {
        f(x, y, z);
        x += a, y += b, z += c;
      }
    }
  }
}
