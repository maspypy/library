/*
partition は、「減少列」として辞書式の降順に列挙する。
N = 50（204226）：12 ms
N = 60（966467）：60 ms
N = 70（4087968）：270 ms
N = 80（15796476）：1100 ms
N = 90（56634173）：4800 ms
N = 100 (190569292) : 15600 ms
*/
template <typename F>
void enumerate_partition(int N, F query, int LIM_len = -1, int LIM_val = -1) {
  assert(N >= 0);
  auto dfs = [&](auto self, vc<int> &p, int sum) -> void {
    if (sum == N) {
      query(p);
      return;
    }
    if (LIM_len != -1 && len(p) == LIM_len)
      return;
    int nxt = (len(p) == 0 ? N : p.back());
    if (LIM_val != -1)
      chmin(nxt, LIM_val);
    chmin(nxt, N - sum);
    p.eb(0);
    FOR3_R(x, 1, nxt + 1) {
      p.back() = x;
      self(self, p, sum + x);
    }
    p.pop_back();
  };
  vc<int> p;
  dfs(dfs, p, 0);
}

// N 元集合の分割の列挙 (Bell number)
// f({s0,s1,...}), f(vc<int>)
// https://atcoder.jp/contests/abc390/tasks/abc390_d
// N = 11（678570）：29 ms
// N = 12（4213597）：208 ms
// N = 13（27644437）：2084 ms
template <typename F> void enumerate_set_partition(int N, F f) {
  vc<int> S;
  auto dfs = [&](auto &dfs, int rest) -> void {
    if (rest == 0) {
      return f(S);
    }
    int a = lowbit(rest);
    rest -= u32(1) << a;
    for (int s : all_subset<u32>(rest)) {
      S.eb(s | 1 << a);
      dfs(dfs, rest - s);
      POP(S);
    }
  };
  dfs(dfs, (u32(1) << N) - 1);
}
