/*
・時刻 t に x を追加する
・時刻 t に x を削除する
があるときに、
・時刻 [l, r) に x を追加する
に変換する
*/
template <typename X>
struct AddRemove_Query {
  map<X, vc<int>> ADD;
  map<X, vc<int>> RM;

  void add(int time, X x) { ADD[x].eb(time); }
  void remove(int time, X x) { RM[x].eb(time); }

  // すべてのクエリが終わった現在時刻を渡す
  vc<tuple<int, int, X>> calc(int time) {
    vc<tuple<int, int, X>> dat;
    for (auto&& [x, A]: ADD) {
      vc<int> B;
      if (RM.count(x)) {
        B = RM[x];
        RM.erase(x);
      }
      if (len(B) < len(A)) B.eb(time);
      assert(len(A) == len(B));

      sort(all(A));
      sort(all(B));
      FOR(i, len(A)) {
        assert(A[i] <= B[i]);
        if (A[i] < B[i]) dat.eb(A[i], B[i], x);
      }
    }
    assert(len(RM) == 0);
    return dat;
  }
};
