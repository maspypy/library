
// basis[i]: i 番目に追加成功したもの. 別のラベルがあるなら外で管理する.
// array<UINT, MAX_DIM> rbasis: 上三角化された基底. [i][i]==1.
// way<UINT,UINT> rbasis[i] を basis[j] で作る方法
template <int MAX_DIM>
struct Basis {
  static_assert(MAX_DIM <= 128);
  using UINT = conditional_t<(MAX_DIM <= 32), u32, conditional_t<(MAX_DIM <= 64), u64, u128>>;
  int rank;
  array<UINT, MAX_DIM> basis;
  array<UINT, MAX_DIM> rbasis;
  array<UINT, MAX_DIM> way;
  Basis() : rank(0), basis{}, rbasis{}, way{} {}

  // return : (sum==x にできるか, その方法)
  pair<bool, UINT> solve(UINT x) {
    UINT c = 0;
    FOR(i, MAX_DIM) {
      if ((x >> i & 1) && (rbasis[i] != 0)) { c ^= way[i], x ^= rbasis[i]; }
    }
    if (x == 0) return {true, c};
    return {false, 0};
  }

  // return : (sum==x にできるか, その方法). false の場合には追加する
  pair<bool, UINT> solve_or_add(UINT x) {
    UINT y = x, c = 0;
    FOR(i, MAX_DIM) {
      if ((x >> i & 1) && (rbasis[i] != 0)) { c ^= way[i], x ^= rbasis[i]; }
    }
    if (x == 0) return {true, c};
    int k = lowbit(x);
    basis[rank] = y, rbasis[k] = x, way[k] = c | UINT(1) << rank, ++rank;
    return {false, 0};
  }
};
