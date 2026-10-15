// Source: https://github.com/maspypy/library/blob/main/graph/shortest_path/restore_path.hpp
vector<int> restore_path(const vector<int>& par, int t) {
  vector<int> pth = {t};
  while (par[pth.back()] != -1) pth.eb(par[pth.back()]);
  reverse(all(pth));
  return pth;
}