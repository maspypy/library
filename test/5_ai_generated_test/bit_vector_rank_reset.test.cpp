#include "my_template.hpp"
#include "other/io.hpp"
#include "ds/bit_vector.hpp"

/*
対象: ds/bit_vector.hpp の set, build, reset, operator[],
      count_prefix, count, to_string。
目的: Wavelet Matrix の問題別テストでは直接確認しにくい、64-bit ワード境界と
      0/1 両方の rank、同一 object の reset → build を検証する。
独立 oracle: std::vector<int> を1要素ずつ直接数える（内部のbit演算を使わない）。
境界: n=0, 1, 63, 64, 65, 127, 128, 129, 255, 256, 257など。
乱数seed: 0xB17B172026ULL。set は build 前、問い合わせは build 後のみ行う。
故障時は長さ・パターン・区間・実測値を stderr に出す。
*/
namespace {
void check(bool ok, const string& message) {
  if (!ok) {
    cerr << "Bit_Vector: " << message << '\n';
    abort();
  }
}

void one(int n, int pattern, mt19937_64& rng) {
  Bit_Vector bv(n);
  for (int pass = 0; pass < 3; ++pass) {
    if (pass) bv.reset();
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
      bool b = false;
      if (pattern == 0) b = false;
      if (pattern == 1) b = true;
      if (pattern == 2) b = (i % 2 == 0);
      if (pattern == 3) b = (i % 64 == 0 || i % 64 == 63);
      if (pattern >= 4) b = (rng() % (pattern == 4 ? 2 : 7) == 0);
      if (pass == 1) b = !b;
      if (pass == 2) b = (rng() % 3 == 0);
      a[i] = b;
      if (b) {
        bv.set(i);
        if (i % 13 == 0) bv.set(i); // 同じビットを二度立てても同じ
      }
    }
    bv.build();
    string expected;
    for (int x : a) expected += char('0' + x);
    check(bv.to_string() == expected, "to_string n=" + to_string(n));
    for (int i = 0; i < n; ++i) {
      check(int(bv[i]) == a[i], "index n=" + to_string(n) + " i=" + to_string(i));
    }
    vector<int> pref(n + 1, 0);
    for (int i = 0; i < n; ++i) pref[i + 1] = pref[i] + a[i];
    for (int k = 0; k <= n; ++k) {
      for (int f = 0; f < 2; ++f) {
        int got = bv.count_prefix(k, f);
        int want = f ? pref[k] : k - pref[k];
        check(got == want, "count_prefix n=" + to_string(n) + " pattern=" +
                  to_string(pattern) + " pass=" + to_string(pass) + " k=" +
                  to_string(k) + " f=" + to_string(f) + " got=" +
                  to_string(got) + " expected=" + to_string(want));
      }
    }
    auto range = [&](int l, int r) {
      for (int f = 0; f < 2; ++f) {
        int got = bv.count(l, r, f);
        int want = f ? pref[r] - pref[l] : (r - l) - pref[r] + pref[l];
        check(got == want, "count n=" + to_string(n) + " l=" +
                  to_string(l) + " r=" + to_string(r) + " f=" +
                  to_string(f) + " got=" + to_string(got) +
                  " expected=" + to_string(want));
      }
    };
    range(0, n);
    range(0, 0);
    range(n, n);
    if (n <= 80) {
      for (int l = 0; l <= n; ++l) {
        for (int r = l; r <= n; ++r) range(l, r);
      }
    } else {
      for (int q = 0; q < 250; ++q) {
        int l = int(rng() % (n + 1)), r = int(rng() % (n + 1));
        if (l > r) swap(l, r);
        range(l, r);
      }
      for (int x : {63, 64, 65, 127, 128, 129, 191, 192, 193, 255, 256}) {
        if (x <= n) range(0, x), range(x, n);
      }
    }
  }
}
} // namespace

int main() {
  mt19937_64 rng(0xB17B172026ULL);
  for (int n : {0, 1, 2, 3, 31, 32, 62, 63, 64, 65, 66, 79, 80,
                127, 128, 129, 130, 191, 192, 193, 255, 256, 257, 511, 512, 513}) {
    for (int pattern = 0; pattern < 6; ++pattern) one(n, pattern, rng);
  }
  for (int t = 0; t < 80; ++t) {
    int n = int(rng() % 385);
    one(n, 4 + (t % 2), rng);
  }
  return 0;
}
