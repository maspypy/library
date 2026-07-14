
// N 元集合の分割の列挙
// f({s0,s1,...})
template <typename F>
void set_partition(int N, F f) {
  vc<int> S;
  auto dfs = [&](auto &dfs, u32 rest) -> void {
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