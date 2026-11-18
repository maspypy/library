#include "my_template.hpp"
#include "ds/sliding_window_aggregation.hpp"

/*
対象: ds/sliding_window_aggregation.hpp
  Sliding_Window_Aggregation (queue) と Sliding_Window_Aggregation_Deque。

独立オラクル: std::deque<string> に同じ push/pop を適用し、先頭から
  文字列連結した結果を比較する。非可換な連結モノイドを使用するため、
  累積の結合順序や左右スタック再構築時の順序逆転を発見できる。

狙う不具合: 最後の要素を pop するときの空状態、右/左片側が空のときの
  再構築、push_front と push_back の混在、clear 後の累積値残留、
  size/front の同期ずれ、繰り返し pop/再 push したときの古いデータ。

条件: 空の構造から pop/front は行わない。トークン長 1〜3、長さ最大
  80 程度として oracle の連結コストを制御する。乱数 seed は固定。
*/

struct String_Concat_For_Test {
  using value_type = string;
  static string id() { return ""; }
  static string op(const string& a, const string& b) { return a + b; }
};
using M = String_Concat_For_Test;
using Queue = Sliding_Window_Aggregation<M>;
using Deque = Sliding_Window_Aggregation_Deque<M>;

string token(mt19937_64& rng) {
  int k = 1 + int(rng() % 3);
  string s;
  for (int i = 0; i < k; ++i) s += char('a' + rng() % 5);
  return s;
}

string brute_concat(const deque<string>& ref) {
  string s;
  for (const string& t : ref) s += t;
  return s;
}

void check_queue(Queue& ds, const deque<string>& ref, int step) {
  string expected = brute_concat(ref);
  if (ds.size() != int(ref.size()) || ds.prod() != expected ||
      M::op(ds.lprod(), ds.rprod()) != expected) {
    cerr << "SWAG queue mismatch at step=" << step
         << " size=" << ds.size() << " expected_size=" << ref.size()
         << " got=" << ds.prod() << " expected=" << expected << '\n';
    abort();
  }
}

void check_deque(Deque& ds, const deque<string>& ref, int step) {
  string expected = brute_concat(ref);
  if (ds.size() != int(ref.size()) || ds.prod() != expected ||
      ds.prod_all() != expected ||
      M::op(ds.lprod(), ds.rprod()) != expected ||
      (!ref.empty() && ds.front() != ref.front())) {
    cerr << "SWAG deque mismatch at step=" << step
         << " size=" << ds.size() << " expected_size=" << ref.size()
         << " got=" << ds.prod() << " expected=" << expected << '\n';
    abort();
  }
}

void test_queue() {
  mt19937_64 rng(0x5a691e123ULL);
  Queue ds;
  deque<string> ref;
  check_queue(ds, ref, -1);

  // 片側に多数 push してから全 pop する操作を繰り返す。
  for (int rep = 0; rep < 12; ++rep) {
    for (int i = 0; i < 73; ++i) {
      string s = token(rng);
      ds.push(s), ref.push_back(s);
      check_queue(ds, ref, rep * 200 + i);
    }
    for (int i = 0; i < 73; ++i) {
      ds.pop(), ref.pop_front();
      check_queue(ds, ref, rep * 200 + 73 + i);
    }
  }
  for (int step = 0; step < 25000; ++step) {
    if (ref.empty() || (ref.size() < 80 && rng() % 10 < 6)) {
      string s = token(rng);
      ds.push(s), ref.push_back(s);
    } else {
      ds.pop(), ref.pop_front();
    }
    check_queue(ds, ref, 100000 + step);
  }
}

void test_deque() {
  mt19937_64 rng(0xdedea091ULL);
  Deque ds;
  deque<string> ref;
  check_deque(ds, ref, -1);

  // 最初は右側だけに積み、左から取り続けて rebuild を発生させる。
  // 次に左側だけに積み、右から取って逆方向の rebuild を発生させる。
  for (int rep = 0; rep < 8; ++rep) {
    for (int i = 0; i < 79; ++i) {
      string s = token(rng);
      ds.push_back(s), ref.push_back(s);
      check_deque(ds, ref, rep * 400 + i);
    }
    for (int i = 0; i < 79; ++i) {
      ds.pop_front(), ref.pop_front();
      check_deque(ds, ref, rep * 400 + 80 + i);
    }
    for (int i = 0; i < 79; ++i) {
      string s = token(rng);
      ds.push_front(s), ref.push_front(s);
      check_deque(ds, ref, rep * 400 + 160 + i);
    }
    for (int i = 0; i < 79; ++i) {
      ds.pop_back(), ref.pop_back();
      check_deque(ds, ref, rep * 400 + 240 + i);
    }
    ds.clear(), ref.clear();
    check_deque(ds, ref, rep * 400 + 320);
  }

  for (int step = 0; step < 35000; ++step) {
    int op = int(rng() % 12);
    if (ref.empty() || (ref.size() < 80 && op <= 4)) {
      string s = token(rng);
      if (op % 2 == 0) ds.push_front(s), ref.push_front(s);
      else if (op == 3) ds.push(s), ref.push_back(s);
      else ds.push_back(s), ref.push_back(s);
    } else if (op == 11) {
      ds.clear(), ref.clear();
    } else if (op % 2 == 0) {
      ds.pop_front(), ref.pop_front();
    } else if (op == 7) {
      ds.pop(), ref.pop_front();
    } else {
      ds.pop_back(), ref.pop_back();
    }
    check_deque(ds, ref, 100000 + step);
  }
  ds.clear(), ref.clear();
  check_deque(ds, ref, 200000);
}

int main() {
  test_queue();
  test_deque();
  cerr << "PASS sliding_window_aggregation queue+deque\n";
}
