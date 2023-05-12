#include "poly/convolution.hpp"
#include "poly/middle_product.hpp"

// i 行目に A[i] 個のセルがある. (0,0) -> (n-1,m-1) のパスを数える
// O((n+m)log^2(n+m))
template <typename mint>
mint count_grid_path(vc<int> A) {
  int N = len(A);
  assert(N >= 1);
  FOR(i, N - 1) assert(A[i] <= A[i + 1]);

  string S;
  FOR(i, N) {
    ll pre = (i == 0 ? 0 : A[i - 1]);
    FOR(A[i] - pre) S += 'Y';
    S += 'X';
  }

  using poly = vc<mint>;

  auto calc_rect = [&](poly FX, poly FY) -> pair<poly, poly> {
    if (len(FX) == 0 || len(FY) == 0) return {FX, FY};
    int NX = len(FX), NY = len(FY);
    vc<mint> GX(NX), GY(NY);
    {
      vc<mint> f(NX);
      FOR(i, NX) f[i] = C<mint>(NY - 1 + i, i);
      f = convolution(f, FX);
      FOR(i, NX) GX[i] += f[i];
    }
    {
      vc<mint> f(NY);
      FOR(i, NY) f[i] = C<mint>(NX - 1 + i, i);
      f = convolution(f, FY);
      FOR(i, NY) GY[i] += f[i];
    }
    {
      reverse(all(FX));
      FOR(i, NX) FX[i] *= fact_inv<mint>(i);
      vc<mint> f(NX + NY - 1);
      FOR(i, NX + NY - 1) f[i] = fact<mint>(i);
      f = middle_product(f, FX);
      FOR(j, NY) GY[j] += f[j] * fact_inv<mint>(j);
    }
    {
      reverse(all(FY));
      FOR(i, NY) FY[i] *= fact_inv<mint>(i);
      vc<mint> f(NX + NY - 1);
      FOR(i, NX + NY - 1) f[i] = fact<mint>(i);
      f = middle_product(f, FY);
      FOR(j, NX) GX[j] += f[j] * fact_inv<mint>(j);
    }
    return {GX, GY};
  };

  auto dfs = [&](auto& dfs, string S, poly FX, poly FY) -> pair<poly, poly> {
    if (len(S) == 1) return {FX, FY};
    int n = len(S);
    string S1 = {S.begin(), S.begin() + n / 2};
    string S2 = {S.begin() + n / 2, S.end()};
    int x1 = count(all(S1), 'X');
    int y1 = count(all(S1), 'Y');
    int x2 = count(all(S2), 'X');
    int y2 = count(all(S2), 'Y');
    assert(len(FX) == x1 + x2 && len(FY) == y1 + y2);
    vc<mint> FX1 = {FX.begin(), FX.begin() + x1};
    vc<mint> FX2 = {FX.begin() + x1, FX.end()};
    vc<mint> FY1 = {FY.begin(), FY.begin() + y1};
    vc<mint> FY2 = {FY.begin() + y1, FY.end()};
    tie(FX1, FY1) = dfs(dfs, S1, FX1, FY1);
    tie(FX2, FY1) = calc_rect(FX2, FY1);
    tie(FX2, FY2) = dfs(dfs, S2, FX2, FY2);
    FX1.insert(FX1.end(), all(FX2));
    FY1.insert(FY1.end(), all(FY2));
    return {FX1, FY1};
  };

  poly FX(count(all(S), 'X'));
  poly FY(count(all(S), 'Y'));
  FY[0] = 1;
  tie(FX, FY) = dfs(dfs, S, FX, FY);
  return FY.back();
}
