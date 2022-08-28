struct DateTime {
  int year, month, day;
  DateTime(int y, int m, int d) : year(y), month(m), day(d) {}

  // 1年1月1日が 0 となるように変換
  // https://atcoder.jp/contests/arc023/tasks/arc023_1
  int to_int() {
    int y = (month <= 2 ? year - 1 : year);
    int m = (month <= 2 ? month + 12 : month);
    int d = day;
    return 365 * y + y / 4 - y / 100 + y / 400 + 306 * (m + 1) / 10 + d - 429;
  }

  // 日曜日が 0 として、曜日を [0, 7) で返す
  int weekday() { return (to_int() + 1) % 7; }
};