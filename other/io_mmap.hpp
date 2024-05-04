
#include <unistd.h>
#include <sys/mman.h>
#include <sys/stat.h>

namespace fastio {
// https://judge.yosupo.jp/submission/21623
// https://judge.yosupo.jp/submission/70667

struct Pre {
  char num[10000][4];
  constexpr Pre() : num() {
    for (int i = 0; i < 10000; i++) {
      int n = i;
      for (int j = 3; j >= 0; j--) {
        num[i][j] = n % 10 | '0';
        n /= 10;
      }
    }
  }
} constexpr pre;

constexpr int BSZ = 1 << 19;
char *ibuf, obuf[BSZ], out[100];
int outi, obufi;

// gcc expansion. called automaticall before main.
void __attribute__((constructor)) _c() {
  struct stat sb;
  fstat(0, &sb);
  ibuf
      = (char *)mmap(0, sb.st_size, PROT_READ, MAP_SHARED | MAP_POPULATE, 0, 0);
}

void flush() { write(1, obuf, obufi), obufi = 0; }

void rd(char &c) { c = *ibuf++; }
void rd(string &x) {
  x.clear();
  char c;
  do { rd(c); } while (isspace(c));
  do { x += c, rd(c); } while (!isspace(c));
}

template <typename T>
void rd_integer(T &x) {
  char c;
  do
    rd(c);
  while (c < '-');
  bool minus = 0;
  if constexpr (is_signed<T>::value || is_same_v<T, i128>) {
    if (c == '-') { minus = 1, rd(c); }
  }
  x = 0;
  while (c >= '0') { x = x * 10 + (c & 15), rd(c); }
  if constexpr (is_signed<T>::value || is_same_v<T, i128>) {
    if (minus) x = -x;
  }
}

template <typename T>
void rd_real(T &x) {
  string s;
  rd(s);
  x = stod(s);
}

void rd(int &x) { rd_integer(x); }
void rd(ll &x) { rd_integer(x); }
void rd(i128 &x) { rd_integer(x); }
void rd(u32 &x) { rd_integer(x); }
void rd(u64 &x) { rd_integer(x); }
void rd(u128 &x) { rd_integer(x); }
void rd(double &x) { rd_real(x); }
void rd(long double &x) { rd_real(x); }
void rd(f128 &x) { rd_real(x); }
template <class T>
void rd(vc<T> &x) {
  for (auto &d: x) rd(d);
}
template <size_t N = 0, typename T>
void rd(array<T, N> &x) {
  for (auto &d: x) rd(d);
}
template <class T, class U>
void rd(pair<T, U> &p) {
  return rd(p.first), rd(p.second);
}
template <size_t N = 0, typename T>
void rd(T &t) {
  if constexpr (N < std::tuple_size<T>::value) {
    auto &x = std::get<N>(t);
    rd(x);
    rd<N + 1>(t);
  }
}
template <class... T>
void rd(tuple<T...> &tpl) {
  rd(tpl);
}

void read() {}
template <class H, class... T>
void read(H &h, T &... t) {
  rd(h), read(t...);
}

void wt(const char c) {
  if (obufi == BSZ) flush();
  obuf[obufi++] = c;
}
void wt(const string &s) {
  for (char c: s) wt(c);
}

template <typename T>
void wt_integer(T x) {
  if (obufi > BSZ - 100) flush();
  if (x < 0) { obuf[obufi++] = '-', x = -x; }
  for (outi = 96; x >= 10000; outi -= 4) {
    memcpy(out + outi, pre.num[x % 10000], 4);
    x /= 10000;
  }
  if (x >= 1000) {
    memcpy(obuf + obufi, pre.num[x], 4);
    obufi += 4;
  } else if (x >= 100) {
    memcpy(obuf + obufi, pre.num[x] + 1, 3);
    obufi += 3;
  } else if (x >= 10) {
    int q = (x * 103) >> 10;
    obuf[obufi] = q | '0';
    obuf[obufi + 1] = (x - q * 10) | '0';
    obufi += 2;
  } else
    obuf[obufi++] = x | '0';
  memcpy(obuf + obufi, out + outi + 4, 96 - outi);
  obufi += 96 - outi;
}

template <typename T>
void wt_real(T x) {
  ostringstream oss;
  oss << fixed << setprecision(15) << double(x);
  string s = oss.str();
  wt(s);
}

void wt(int x) { wt_integer(x); }
void wt(ll x) { wt_integer(x); }
void wt(i128 x) { wt_integer(x); }
void wt(u32 x) { wt_integer(x); }
void wt(u64 x) { wt_integer(x); }
void wt(u128 x) { wt_integer(x); }
void wt(double x) { wt_real(x); }
void wt(long double x) { wt_real(x); }
void wt(f128 x) { wt_real(x); }

template <class T>
void wt(const vector<T> val) {
  auto n = val.size();
  for (size_t i = 0; i < n; i++) {
    if (i) wt(' ');
    wt(val[i]);
  }
}
template <class T, class U>
void wt(const pair<T, U> val) {
  wt(val.first);
  wt(' ');
  wt(val.second);
}
template <size_t N = 0, typename T>
void wt_tuple(const T t) {
  if constexpr (N < std::tuple_size<T>::value) {
    if constexpr (N > 0) { wt(' '); }
    const auto x = std::get<N>(t);
    wt(x);
    wt_tuple<N + 1>(t);
  }
}
template <class... T>
void wt(tuple<T...> tpl) {
  wt_tuple(tpl);
}
template <class T, size_t S>
void wt(const array<T, S> val) {
  auto n = val.size();
  for (size_t i = 0; i < n; i++) {
    if (i) wt(' ');
    wt(val[i]);
  }
}

void print() { wt('\n'); }
template <class Head, class... Tail>
void print(Head &&head, Tail &&... tail) {
  wt(head);
  if (sizeof...(Tail)) wt(' ');
  print(forward<Tail>(tail)...);
}

// gcc expansion. called automaticall after main.
void __attribute__((destructor)) _d() { flush(); }
} // namespace fastio

using fastio::read;
using fastio::print;
using fastio::flush;

#define INT(...)   \
  int __VA_ARGS__; \
  read(__VA_ARGS__)
#define LL(...)   \
  ll __VA_ARGS__; \
  read(__VA_ARGS__)
#define STR(...)      \
  string __VA_ARGS__; \
  read(__VA_ARGS__)
#define CHAR(...)   \
  char __VA_ARGS__; \
  read(__VA_ARGS__)
#define DBL(...)      \
  double __VA_ARGS__; \
  read(__VA_ARGS__)

#define VEC(type, name, size) \
  vector<type> name(size);    \
  read(name)
#define VV(type, name, h, w)                     \
  vector<vector<type>> name(h, vector<type>(w)); \
  read(name)

void YES(bool t = 1) { print(t ? "YES" : "NO"); }
void NO(bool t = 1) { YES(!t); }
void Yes(bool t = 1) { print(t ? "Yes" : "No"); }
void No(bool t = 1) { Yes(!t); }
void yes(bool t = 1) { print(t ? "yes" : "no"); }
void no(bool t = 1) { yes(!t); }