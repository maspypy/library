int mex(const vc<int>& A) {
  int n = len(A);
  vc<bool> aru(n + 1);
  for (auto& x: A)
    if (x < n) aru[x] = 1;
  int mex = 0;
  while (aru[mex]) ++mex;
  return mex;
}
