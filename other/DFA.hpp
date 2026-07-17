// https://qoj.ac/contest/1323/problem/7083
struct DFA {
  // state, alphabet, initial state
  int n, sigma, q0;
  vvc<int> nxt;    // nxt[state][alphabet]
  vc<int> output;  // 各状態に対応する出力ラベル

  DFA() = default;

  DFA(int n, int sigma, int q0, vvc<int> nxt, vc<int> output)
      : n(n), sigma(sigma), q0(q0), nxt(nxt), output(output) {
    assert(n >= 1);
    assert(sigma >= 1);
    assert(0 <= q0 && q0 < n);
    assert(len(nxt) == n);
    assert(len(output) == n);
    FOR(q, n) {
      assert(len(nxt[q]) == sigma);
      FOR(c, sigma) { assert(0 <= nxt[q][c] && nxt[q][c] < n); }
    }
  }

  int calc(const vc<int>& word) const {
    int q = q0;
    for (int c : word) {
      assert(0 <= c && c < sigma);
      q = nxt[q][c];
    }
    return output[q];
  }

  // Hopcroft minimization.
  DFA minimize_DFA() const {
    vvv(int, rev, sigma, n, 0);
    FOR(u, n) FOR(c, sigma) { rev[c][nxt[u][c]].eb(u); }

    map<int, vc<int>> mp;
    FOR(q, n) mp[output[q]].eb(q);

    vvc<int> block;
    vc<int> cls(n, -1);
    for (auto& [_, V] : mp) {
      int id = len(block);
      for (int q : V) cls[q] = id;
      block.eb(V);
    }

    // Hopcroft refinement.
    vc<int> que;

    FOR(b, len(block) - 1) que.eb(b);

    vc<bool> vis(n);
    vc<int> cnt(len(block), 0);

    vc<int> V, B;
    while (!que.empty()) {
      int b = POP(que);
      vc<int> A = block[b];

      FOR(c, sigma) {
        V.clear(), B.clear();
        for (int v : A) {
          for (int u : rev[c][v]) {
            if (vis[u]) continue;
            vis[u] = 1, V.eb(u);
            int b = cls[u];
            if (cnt[b] == 0) B.eb(b);
            cnt[b]++;
          }
        }

        for (int b : B) {
          int x = cnt[b];
          int sz = len(block[b]);
          if (x == sz) {
            continue;
          }
          // split b
          vc<int> X, Y;
          X.reserve(x), Y.reserve(sz - x);

          for (int q : block[b]) {
            (vis[q] ? X : Y).eb(q);
          }
          if (len(X) < len(Y)) swap(X, Y);

          block[b] = move(X);

          int nb = len(block);
          for (int q : Y) cls[q] = nb;
          block.eb(move(Y));

          cnt.eb(0), que.eb(nb);
        }
        for (int b : B) cnt[b] = 0;
        for (int u : V) vis[u] = 0;
      }
    }

    int M = len(block);
    vvc<int> new_nxt(M, vc<int>(sigma));
    vc<int> new_output(M);

    FOR(b, M) {
      int rep = block[b][0];
      new_output[b] = output[rep];
      FOR(c, sigma) { new_nxt[b][c] = cls[nxt[rep][c]]; }
    }

    int new_q0 = cls[q0];
    return DFA(M, sigma, new_q0, new_nxt, new_output);
  }
};

// https://qoj.ac/problem/12010
// out[0], ..., out[A+B+1]
// |out[i]|=sigma^i, 辞書順にすべての結果を入れておく
// A, B が推測のために用いる長さ
DFA infer_DFA(int sigma, int A, int B, const vvc<int>& out, bool check = true) {
  vc<int> pw(A + B + 2, 1);
  FOR(i, len(pw) - 1) pw[i + 1] = pw[i] * sigma;

  assert(len(out) == A + B + 2);
  FOR(i, A + B + 2) assert(len(out[i]) == pw[i]);

  vc<pair<int, int>> prefix, test;

  FOR(n, A + 1) {
    FOR(code, pw[n]) { prefix.eb(n, code); }
  }

  FOR(n, B + 1) {
    FOR(code, pw[n]) { test.eb(n, code); }
  }

  vc<u64> hash_base(len(test));
  FOR(i, len(test)) { hash_base[i] = RNG_64(); }

  auto fingerprint = [&](int lx, u64 x) -> u64 {
    u64 h = 0;
    FOR(i, len(test)) {
      auto [lt, t] = test[i];
      int y = out[lx + lt][x * pw[lt] + t];
      h += hash_base[i] * u64(y + 1);
    }
    return h;
  };

  map<u64, int> id;
  vc<pair<int, u64>> rep;

  auto get_state = [&](u64 h) -> int {
    auto it = id.find(h);
    if (it != id.end()) return it->se;
    int s = len(rep);
    id[h] = s;
    rep.eb(-1, 0);
    return s;
  };

  for (auto [lx, x] : prefix) {
    u64 h = fingerprint(lx, x);
    int s = get_state(h);
    if (rep[s].fi == -1) rep[s] = {lx, x};
  }

  int N = len(rep);
  vvc<int> nxt(N, vc<int>(sigma, -1));
  vc<int> output(N);

  FOR(s, N) {
    auto [lx, x] = rep[s];
    output[s] = out[lx][x];
    FOR(c, sigma) {
      int ly = lx + 1;
      u64 y = x * u64(sigma) + u64(c);
      u64 h = fingerprint(ly, y);
      if (!id.count(h)) {
        print("A is too small");
        assert(false);
      }
      nxt[s][c] = id[h];
    }
  }

  int q0 = id[fingerprint(0, 0)];

  DFA X(N, sigma, q0, nxt, output);
  X = X.minimize_DFA();

  vc<int> word;
  auto dfs = [&](auto& dfs, u64 k) -> void {
    if (X.calc(word) != out[len(word)][k]) {
      print("failed");
      assert(0);
    }
    if (len(word) == A + B + 1) return;
    FOR(i, sigma) {
      word.eb(i);
      dfs(dfs, k * sigma + i);
      word.pop_back();
    }
  };
  if (check) dfs(dfs, 0);
  return X;
}