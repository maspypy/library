#pragma once
#include "poly/convolution.hpp"

/*
query(i)：a[i], b[i] を与えて ab[i] を得る。
2^{17}：176ms
2^{18}：370ms
2^{19}：800ms
2^{20}：1680ms
*/
template <typename mint>
struct Online_Convolution {
  const int thresh = 3;
  vc<mint> f, g, h;
  vc<vc<mint>> fft_f;
  vc<vc<mint>> fft_g;

  pair<vc<mint>, vc<mint>> calc_fft(int k) {
    // 現時点での末尾 2^k 項に対する fft データを得る
    ll L = 1 << k;
    if (k <= thresh) {
      vc<mint> f_suff(f.end() - L, f.end());
      vc<mint> g_suff(g.end() - L, g.end());
      return {f_suff, g_suff};
    }
    vc<mint> f_suff(2 * L), g_suff(2 * L);
    FOR(i, 1 << k) { f_suff[i] = f[len(f) - L + i]; }
    FOR(i, 1 << k) { g_suff[i] = g[len(g) - L + i]; }
    if (k <= thresh) return {f_suff, g_suff};
    ntt(f_suff, 0);
    ntt(g_suff, 0);
    return {f_suff, g_suff};
  }

  void calc(int k) {
    // suffix の 長さ 2^k まわりの畳み込みを h に加算する
    auto [Ff, Fg] = calc_fft(k);
    vc<mint> Fh(1 << (k + 1));
    bool square = k >= len(fft_f);
    if (square) {
      // 長さ 2^k のはじめての塊。
      fft_f.eb(Ff);
      fft_g.eb(Fg);
    }

    if (k > thresh && square) {
      FOR(i, 1 << (k + 1)) Fh[i] += Ff[i] * Fg[i];
      ntt(Fh, 1);
    }
    elif (k > thresh && !square) {
      FOR(i, 1 << (k + 1)) {
        Fh[i] += Ff[i] * fft_g[k][i];
        Fh[i] += Fg[i] * fft_f[k][i];
      }
      ntt(Fh, 1);
    }
    elif (k <= thresh && square) {
      FOR(i, 1 << k) FOR(j, 1 << k) Fh[i + j] += Ff[i] * Fg[j];
    }
    elif (k <= thresh && !square) {
      FOR(i, 1 << k) FOR(j, 1 << k) Fh[i + j] += Ff[i] * fft_g[k][j];
      FOR(i, 1 << k) FOR(j, 1 << k) Fh[i + j] += Fg[i] * fft_f[k][j];
    }
    // 適切な場所に足しこむ
    int off = len(f) - 1;
    FOR(i, len(Fh) - 1) {
      if (len(h) <= off + i) h.eb(0);
      h[off + i] += Fh[i];
    }
  }

  mint query(int i, mint f_i, mint g_i) {
    assert(i == len(f));
    f.eb(f_i);
    g.eb(g_i);
    FOR(k, 30) {
      // 長さ 2^k の部分を処理するかどうか？
      // i+2 が 2^k の倍数かつ i+2 >= 2^{k+1}
      ll L = 1 << k;
      bool bl = ((i + 2) % L == 0) && (i + 2 >= 2 * L);
      if (!bl) continue;
      calc(k);
    }
    return h[i];
  }
};