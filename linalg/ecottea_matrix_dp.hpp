#include "mod/modint.hpp"
#include "string/split.hpp"

// https://maspypy.com/ecottea_dp_estimate_method
// https://atcoder.jp/contests/agc022/tasks/agc022_e
// https://atcoder.jp/contests/toyota2023spring-final/tasks/toyota2023spring_final_f
template <typename mint, int d>
struct ecottea_matrix_dp {
  using MAT = array<array<mint, d>, d>;
  string alphabet;
  map<char, MAT> matrix;
  array<mint, d> X;
  int rank;

  // naive(n): map<string,mint>
  template <typename F>
  void build(string alphabet_, F naive, int max_append = -1) {
    alphabet = alphabet_;
    vc<string> lst;
    if (max_append == -1) max_append = d - 1;
    lst.eb("");
    for (int p = 0; p < len(lst); ++p) {
      string S = lst[p];
      if (max_append < len(S)) break;
      for (auto& a : alphabet) lst.eb(S + a);
    }
    int n = len(lst);

    auto get = [&](string S) -> vc<mint> {
      vc<mint> ANS(n);
      FOR(j, n) ANS[j] = naive(lst[j] + S);
      return ANS;
    };

    vv(mint, mat, d, n);
    vc<string> basis;
    vc<int> pivot(d, infty<int>);
    vv(mint, way, d, d);
    deque<string> que;
    que.eb("");

    auto reduce = [&](vc<mint>& A) -> vc<mint> {
      vc<mint> cf(d);
      FOR(i, len(basis)) {
        mint x = A[pivot[i]];
        FOR(j, pivot[i], n) { A[j] -= x * mat[i][j]; }
        FOR(j, len(basis)) { cf[j] -= x * way[i][j]; }
      }
      return cf;
    };

    while (len(que)) {
      int p = len(basis);
      string S = POP(que);
      vc<mint> row = get(S);
      vc<mint> cf = reduce(row);
      int k = n;
      FOR_R(j, n) if (row[j] != 0) k = j;
      if (k == n) continue;
      if (p == d) {
        print("dim>d");
        assert(0);
      }
      cf[p] += 1;
      mint c = mint(1) / row[k];
      FOR(j, n) row[j] *= c;
      FOR(j, p + 1) cf[j] *= c;
      basis.eb(S);
      pivot[p] = k, mat[p] = row, way[p] = cf;
      ++p;

      auto I = argsort(pivot);
      way = rearrange(way, I);
      mat = rearrange(mat, I);
      pivot = rearrange(pivot, I);
      for (auto& ch : alphabet) {
        que.eb(ch + S);
      }
    }
    rank = len(basis);

    for (auto& ch : alphabet) {
      MAT ans{};
      FOR(i, len(basis)) {
        vc<mint> row = get(ch + basis[i]);
        vc<mint> cf = reduce(row);
        FOR(j, n) assert(row[j] == 0);
        FOR(j, len(cf)) ans[i][j] = -cf[j];
      }
      matrix[ch] = ans;
    }
    FOR(i, len(basis)) X[i] = naive(basis[i]);
    return;
  }

  string to_string(mint x) {
    int a = x.val;
    int b = a - (mint::get_mod());
    return ::to_string(abs(a) <= abs(b) ? a : b);
  }
  string to_string() {
    string out;
    out += alphabet + ".";
    FOR(i, d) out += to_string(X[i].val) + ".";
    for (auto& ch : alphabet) {
      FOR(i, d) FOR(j, d) { out += to_string(matrix[ch][i][j].val) + "."; }
    }
    out.pop_back();
    return out;
  }
  void build_from_string(string S) {
    auto dat = split(S, '.');
    alphabet = dat[0];
    int p = 1;
    FOR(i, d) X[i] = stoi(dat[p++]);
    for (auto& ch : alphabet) {
      FOR(i, d) FOR(j, d) { matrix[ch][i][j] = stoi(dat[p++]); }
    }
  }

  // ? は全部の重ね合わせとして
  mint solve(string S) {
    // 行ベクトルに行列をかけていって第0成分をとる
    MAT ques{};
    for (auto& [ch, A] : matrix) {
      FOR(i, d) FOR(j, d) ques[i][j] += A[i][j];
    }
    matrix['?'] = ques;
    array<mint, d> dp = X;
    for (auto& ch : S) {
      array<mint, d> newdp{};
      assert(matrix.count(ch));
      MAT& mat = matrix[ch];
      FOR(i, d) FOR(j, d) newdp[i] += mat[i][j] * dp[j];
      swap(dp, newdp);
    }
    return dp[0];
  }
};