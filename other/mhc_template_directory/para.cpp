#include "my_template.hpp"
#include "other/io.hpp"

using TestCase = tuple<ll, ll, ll, vvc<int>>;
using Result = ll;

// テストケースの入力を読み込む関数
TestCase read_input(int i) {}

Result solve(const TestCase& tc) {}

signed main() {
  INT(T);

  std::vector<TestCase> cases;
  std::vector<std::future<Result>> futures; // 並列処理用のfutureベクター
  std::vector<Result> results;              // 結果を格納するベクター

  // 入力を読み込んでcasesに格納
  for (int t = 0; t < T; ++t) { cases.push_back(read_input(t)); }

  // 並列処理の実行
  for (int t = 0; t < T; ++t) {
    // 非同期タスクを生成し、solve関数を並列に実行
    futures.push_back(std::async(std::launch::async, solve, cases[t]));
  }

  // 各非同期タスクの結果を取得
  for (int t = 0; t < T; ++t) {
    results.push_back(futures[t].get()); // `futures[t]`から結果を取得して`results[t]`に格納
  }

  // 結果の出力
  for (int t = 0; t < T; ++t) {
    string off = "Case #";
    off += to_string(t + 1);
    off += ":";
    print(off, results[t]);
  }
  return 0;
}
