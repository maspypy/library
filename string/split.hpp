vc<string> split(string S, string seps = " ,") {
  vc<string> res = {""};
  for (auto&& s : S) {
    if (count(all(seps), s))
      res.eb("");
    else
      res.back() += s;
  }
  return res;
}
