// 0, ..., 2^{LOG}-1 の順列であって、1 bit ずつ変化するものを返す
vc<int> gray_code(int LOG) {
  vc<int> res(1 << LOG);
  FOR(v, 1 << LOG) res[v] = v ^ (v >> 1);
  return res;
}
