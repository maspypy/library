// template/rollback_dfs.hpp
auto upd = X.calc(len(query));
vi ANS(len(query));
vc<int> I(len(upd));
iota(all(I), 0);
auto dfs = [&](auto& dfs, vc<int>& upd_query_I, int begin, int end) -> void {
  if (begin == end) return;
  // snapshot
  ;
  vc<int> IL, IR;
  int mid = (begin + end) / 2;
  for (auto&& i : upd_query_I) {
    auto [a, b, X] = upd[i];
    if (a <= begin && end <= b) {
      // X で表される update query を処理する
      ;
      ;
    } else {
      if (a < mid) IL.eb(i);
      if (mid < b) IR.eb(i);
    }
  }
  if (begin + 1 == end) {
    // 求値クエリ
    int qid = begin;
    ;
    ;  // ここで出力してしまってもよい
  } else {
    dfs(dfs, IL, begin, mid);
    dfs(dfs, IR, mid, end);
  }
  // rollback
  ;
};
dfs(dfs, I, 0, len(query));