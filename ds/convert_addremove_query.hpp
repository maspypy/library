/*
・時刻 t に x を追加する
・時刻 t に x を削除する
があるときに、
・時刻 [l, r) に x を追加する
に変換する
*/
template <typename X>
struct Convert_AddRemove_Query {
  map<X, int> MP;
  vc<tuple<int, int, X>> dat;
  void add(int time, X x) {
    assert(!MP.count(x));
    MP[x] = time;
  }

  void remove(int time, X x) {
    auto it = MP.find(x);
    assert(it != MP.end());
    int t = (*it).se;
    MP.erase(it);
    if (t == time) return;
    dat.eb(t, time, x);
  }

  // すべてのクエリが終わった現在時刻を渡す
  vc<tuple<int, int, X>> calc(int time) {
    for (auto&& [x, t]: MP) {
      if (t == time) continue;
      dat.eb(t, time, x);
    }
    return dat;
  }
};
