
// https://heno239.hatenablog.com/entry/2020/07/07/140651
// S[i] を追加すると，S[j:i] が lcp であるような j 全体の vector がかえる.
// https://codeforces.com/problemset/problem/1286/E
template <typename CHAR = char>
struct Online_Z_Algorithm {
  vc<CHAR> S;
  vc<int> Z;
  vvc<int> memo;
  int p;

  Online_Z_Algorithm() : p(1){};

  vc<int> add(int i, CHAR c) {
    assert(i == len(S));
    S.push_back(c);
    int len = S.size();
    Z.eb(-1);
    memo.resize(1 + i);
    vc<int> end;

    if (len == 1) return end;
    if (S[0] != c) Z[i] = 0, end.eb(i);

    auto del = [&](int j) -> void { Z[j] = i - j, memo[i].eb(j), end.eb(j); };

    while (p <= i) {
      if (Z[p] != -1) { ++p; }
      elif (S[i - p] != S[i]) { del(p++); }
      else {
        break;
      }
    }
    if (p < i) {
      for (int j: memo[i - p]) { del(j + p); }
    }
    return end;
  }
  int query(int i) { return (Z[i] == -1 ? len(S) - i : Z[i]); }
};
