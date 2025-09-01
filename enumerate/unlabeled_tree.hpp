
// unlabeled unrooted trees を同型を除いて列挙. vc<pair<int, int>>.
// https://oeis.org/A000055
// N=15: 7741, 0.005sec
// N=20: 823065, 0.401sec
// N=25: 104636890, 52.368sec
template <typename F>
void enumerate_unlabeled_tree(int n, F f) {
  assert(0 <= n && n <= 32);
  if (n == 0) return;
  /*
  n/2 以下の rooted tree を列挙する
  rooted tree -> bracket sequence -> 1,0 の列 -> 32bit 整数
  */
  int m = floor<int>(n, 2);
  vvc<u32> dat(m + 1);
  if (1 <= m) dat[1].eb(0);

  FOR(n, 2, m + 1) {
    auto dfs = [&](auto& dfs, int m, int k, u32 now, int now_e) -> void {
      if (now_e == n - 1) {
        dat[n].eb(now);
        return;
      }
      if (now_e + m >= n) {
        m = n - 1 - now_e;
        k = 0;
      }
      if (m == 0) return;
      FOR(i, k, len(dat[m])) {
        u32 x = dat[m][i];
        x = (x << 1) | 1;
        dfs(dfs, m, i, now | x << (2 * now_e), now_e + m);
      }
      dfs(dfs, m - 1, 0, now, now_e);
    };
    dfs(dfs, n - 1, 0, 0, 0);
  }

  // m 以下の rooted tree が列挙できたのでこれを利用して
  // n 頂点の unrooted tree を列挙
  auto decode = [&](u64 x) -> vc<pair<int, int>> {
    vc<pair<int, int>> edge;
    vc<int> path = {0};
    int p = 0;
    FOR(i, 2 * n - 2) {
      if (x >> i & 1) {
        edge.eb(path.back(), p + 1);
        path.eb(p + 1), p++;
      } else {
        path.pop_back();
      }
    }
    return edge;
  };

  auto dfs = [&](auto& dfs, int m, int k, u64 now, int now_e) -> void {
    if (now_e == n - 1) {
      f(decode(now));
      return;
    }
    if (now_e + m >= n) {
      m = n - 1 - now_e;
      k = 0;
    }
    if (m == 0) return;
    FOR(i, k, len(dat[m])) {
      u64 x = dat[m][i];
      x = (x << 1) | 1;
      dfs(dfs, m, i, now | x << (2 * now_e), now_e + m);
    }
    dfs(dfs, m - 1, 0, now, now_e);
  };
  dfs(dfs, floor<int>(n - 1, 2), 0, 0, 0);

  // 重心が 2 つの場合
  if (2 * m == n) {
    FOR(i, len(dat[m])) {
      FOR(j, i + 1) {
        u64 x = dat[m][i], y = dat[m][j];
        y = (y << 1) | 1;
        f(decode(x | (y << (2 * (m - 1)))));
      }
    }
  }
}

template <typename F>
void enumerate_unlabeled_rooted_tree(int n, F f) {
  assert(0 <= n && n <= 32);
  if (n == 0) return;
  /*
  n/2 以下の rooted tree を列挙する
  rooted tree -> bracket sequence -> 1,0 の列 -> 32bit 整数
  */
  int m = n;
  vvc<u32> dat(n + 1);
  if (1 <= m) dat[1].eb(0);

  FOR(n, 2, m + 1) {
    auto dfs = [&](auto& dfs, int m, int k, u32 now, int now_e) -> void {
      if (now_e == n - 1) {
        dat[n].eb(now);
        return;
      }
      if (now_e + m >= n) {
        m = n - 1 - now_e;
        k = 0;
      }
      if (m == 0) return;
      FOR(i, k, len(dat[m])) {
        u32 x = dat[m][i];
        x = (x << 1) | 1;
        dfs(dfs, m, i, now | x << (2 * now_e), now_e + m);
      }
      dfs(dfs, m - 1, 0, now, now_e);
    };
    dfs(dfs, n - 1, 0, 0, 0);
  }

  // m 以下の rooted tree が列挙できたのでこれを利用して
  // n 頂点の unrooted tree を列挙
  auto decode = [&](u64 x) -> vc<pair<int, int>> {
    vc<pair<int, int>> edge;
    vc<int> path = {0};
    int p = 0;
    FOR(i, 2 * n - 2) {
      if (x >> i & 1) {
        edge.eb(path.back(), p + 1);
        path.eb(p + 1), p++;
      } else {
        path.pop_back();
      }
    }
    return edge;
  };

  for (auto& x : dat[n]) f(decode(x));
}