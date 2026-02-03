#include "my_template.hpp"
#include "other/io.hpp"

using TestCase = tuple<ll, ll, ll, vvc<int>>;
using Result = ll;

// テストケースの入力を読み込む関数
TestCase read_input(int i) {}

Result solve(const TestCase& tc) {}

signed main() {
  INT(T);

  std::vector<TestCase> cases(T);
  for (int t = 0; t < T; ++t) {
    cases[t] = read_input(t);
  }

  const int MAX_PAR =
      8;  // ここで並列数を制限（適当に決める or 引数で受けるなど）

  std::vector<std::future<Result>> futures(T);
  std::vector<Result> results(T);

  int next_launch = 0;   // 次に投げるテストケースの index
  int next_collect = 0;  // 次に結果を回収する index
  int running = 0;       // 現在走っているタスク数

  // 最初に MAX_PAR 個まで投げる
  while (next_launch < T && running < MAX_PAR) {
    futures[next_launch] =
        std::async(std::launch::async, solve, cases[next_launch]);
    ++next_launch;
    ++running;
  }

  // 結果を回収しながら、新しいタスクを順次投げる
  while (next_collect < T) {
    // next_collect 番目のタスクが終わるのを待つ（終わるまでブロック）
    results[next_collect] = futures[next_collect].get();
    ++next_collect;
    --running;

    // 枠が空いたぶんだけ新しいタスクを投げる
    while (next_launch < T && running < MAX_PAR) {
      futures[next_launch] =
          std::async(std::launch::async, solve, cases[next_launch]);
      ++next_launch;
      ++running;
    }
  }

  // 出力
  for (int t = 0; t < T; ++t) {
    std::string off = "Case #";
    off += std::to_string(t + 1);
    off += ":";
    print(off, results[t]);
  }
  return 0;
}
