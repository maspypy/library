vector<int> restore_path(vector<int> par, int t){
  vector<int> pth = {t};
  while (par[pth.back()] != -1) pth.eb(par[pth.back()]);
  reverse(all(pth));
  return pth;
}