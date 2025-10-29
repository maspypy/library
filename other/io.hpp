#define FASTIO

// https://judge.yosupo.jp/submission/21623
namespace fastio {
static constexpr uint32_t SZ = 1 << 17;
char ibuf[SZ];
char obuf[SZ];
char out[100];
// pointer of ibuf, obuf
uint32_t pil = 0, pir = 0, por = 0;

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

inline void load() {
  memmove(ibuf, ibuf + pil, pir - pil);
  pir = pir - pil + fread(ibuf + pir - pil, 1, SZ - pir + pil, stdin);
  pil = 0;
  if (pir < SZ) ibuf[pir++] = '\n';
}

inline void flush() {
  fwrite(obuf, 1, por, stdout);
  por = 0;
}

void rd(char &c) {
  do {
    if (pil + 1 > pir) load();
    c = ibuf[pil++];
  } while (isspace(c));
}

void rd(string &x) {
  x.clear();
  char c;
  do {
    if (pil + 1 > pir) load();
    c = ibuf[pil++];
  } while (isspace(c));
  do {
    x += c;
    if (pil == pir) load();
    c = ibuf[pil++];
  } while (!isspace(c));
}

template <typename T>
void rd_real(T &x) {
  string s;
  rd(s);
  x = stod(s);
}

template <typename T>
void rd_integer(T &x) {
  if (pil + 100 > pir) load();
  char c;
  do c = ibuf[pil++];
  while (c < '-');
  bool minus = 0;
  if constexpr (is_signed<T>::value || is_same_v<T, i128>) {
    if (c == '-') {
      minus = 1, c = ibuf[pil++];
    }
  }
  x = 0;
  while ('0' <= c) {
    x = x * 10 + (c & 15), c = ibuf[pil++];
  }
  if constexpr (is_signed<T>::value || is_same_v<T, i128>) {
    if (minus) x = -x;
  }
}

template <class T>
enable_if_t<is_integral_v<T> || is_same_v<T, i128> || is_same_v<T, u128>> rd(
    T &x) {
  rd_integer(x);
}

template <class T>
enable_if_t<is_floating_point_v<T> || is_same_v<T, f128>> rd(T &x) {
  rd_real(x);
}

template <class T, class U>
void rd(pair<T, U> &p) {
  rd(p.first), rd(p.second);
}
template <size_t N = 0, typename T>
void rd_tuple(T &t) {
  if constexpr (N < tuple_size<T>::value) {
    auto &x = get<N>(t);
    rd(x);
    rd_tuple<N + 1>(t);
  }
}
template <class... T>
void rd(tuple<T...> &tpl) {
  rd_tuple(tpl);
}

template <size_t N = 0, typename T>
void rd(array<T, N> &x) {
  for (auto &d : x) rd(d);
}
template <class T>
void rd(vc<T> &x) {
  for (auto &d : x) rd(d);
}

void read() {}
template <class H, class... T>
void read(H &h, T &...t) {
  rd(h), read(t...);
}

inline void wt_range(const char *s, size_t n) {
  size_t i = 0;
  while (i < n) {
    if (por == SZ) flush();
    size_t chunk = min(n - i, (size_t)(SZ - por));
    memcpy(obuf + por, s + i, chunk);
    por += chunk;
    i += chunk;
  }
}

void wt(const char c) {
  if (por == SZ) flush();
  obuf[por++] = c;
}
void wt(const char *s) { wt_range(s, strlen(s)); }
void wt(const string &s) { wt_range(s.data(), s.size()); }

template <typename T>
void wt_integer(T x) {
  if (por > SZ - 100) flush();
  if (x < 0) {
    obuf[por++] = '-', x = -x;
  }
  int outi;
  for (outi = 96; x >= 10000; outi -= 4) {
    memcpy(out + outi, pre.num[x % 10000], 4);
    x /= 10000;
  }
  if (x >= 1000) {
    memcpy(obuf + por, pre.num[x], 4);
    por += 4;
  } else if (x >= 100) {
    memcpy(obuf + por, pre.num[x] + 1, 3);
    por += 3;
  } else if (x >= 10) {
    int q = (x * 103) >> 10;
    obuf[por] = q | '0';
    obuf[por + 1] = (x - q * 10) | '0';
    por += 2;
  } else
    obuf[por++] = x | '0';
  memcpy(obuf + por, out + outi + 4, 96 - outi);
  por += 96 - outi;
}

template <typename T>
inline void wt_real(T x) {
  char buf[64];
  int n = std::snprintf(buf, sizeof(buf), "%.15g", (double)x);

  if (n == 2 && buf[0] == '-' && buf[1] == '0') {
    buf[0] = '0';
    n = 1;
  }
  wt_range(buf, (size_t)n);
}

template <class T>
enable_if_t<is_integral_v<T> || is_same_v<T, i128> || is_same_v<T, u128>> wt(
    T x) {
  wt_integer(x);
}

template <class T>
enable_if_t<is_floating_point_v<T> || is_same_v<T, f128>> wt(T x) {
  wt_real(x);
}

inline void wt(bool b) { wt(static_cast<char>('0' + (b ? 1 : 0))); }

template <class T, class U>
void wt(const pair<T, U> &val) {
  wt(val.first);
  wt(' ');
  wt(val.second);
}
template <size_t N = 0, typename T>
void wt_tuple(const T &t) {
  if constexpr (N < tuple_size<T>::value) {
    if constexpr (N > 0) wt(' ');
    wt(get<N>(t));
    wt_tuple<N + 1>(t);
  }
}
template <class... T>
void wt(const tuple<T...> &tpl) {
  wt_tuple(tpl);
}
template <class T, size_t S>
void wt(const array<T, S> &val) {
  auto n = val.size();
  for (size_t i = 0; i < n; i++) {
    if (i) wt(' ');
    wt(val[i]);
  }
}
template <class T>
void wt(const vector<T> &val) {
  auto n = val.size();
  for (size_t i = 0; i < n; i++) {
    if (i) wt(' ');
    wt(val[i]);
  }
}

void print() { wt('\n'); }
template <class Head, class... Tail>
void print(Head &&head, Tail &&...tail) {
  wt(head);
  if (sizeof...(Tail)) wt(' ');
  print(forward<Tail>(tail)...);
}

// gcc expansion. called automaticall after main.
void __attribute__((destructor)) _d() { flush(); }
}  // namespace fastio
using fastio::flush;
using fastio::print;
using fastio::read;

#if defined(LOCAL)
#define HDR "[DEBUG:", __func__, __LINE__, "]"
#define SHOW(...)                                                         \
  SHOW_IMPL(__VA_ARGS__, SHOW8, SHOW7, SHOW6, SHOW5, SHOW4, SHOW3, SHOW2, \
            SHOW1)                                                        \
  (__VA_ARGS__)
#define SHOW_IMPL(_1, _2, _3, _4, _5, _6, _7, _8, NAME, ...) NAME
#define SHOW1(x) print(HDR, #x, "=", (x)), flush()
#define SHOW2(x, y) print(HDR, #x, "=", (x), #y, "=", (y)), flush()
#define SHOW3(x, y, z) \
  print(HDR, #x, "=", (x), #y, "=", (y), #z, "=", (z)), flush()
#define SHOW4(x, y, z, w) \
  print(HDR, #x, "=", (x), #y, "=", (y), #z, "=", (z), #w, "=", (w)), flush()
#define SHOW5(x, y, z, w, v)                                                  \
  print(HDR, #x, "=", (x), #y, "=", (y), #z, "=", (z), #w, "=", (w), #v, "=", \
        (v)),                                                                 \
      flush()
#define SHOW6(x, y, z, w, v, u)                                               \
  print(HDR, #x, "=", (x), #y, "=", (y), #z, "=", (z), #w, "=", (w), #v, "=", \
        (v), #u, "=", (u)),                                                   \
      flush()
#define SHOW7(x, y, z, w, v, u, t)                                            \
  print(HDR, #x, "=", (x), #y, "=", (y), #z, "=", (z), #w, "=", (w), #v, "=", \
        (v), #u, "=", (u), #t, "=", (t)),                                     \
      flush()
#define SHOW8(x, y, z, w, v, u, t, s)                                         \
  print(HDR, #x, "=", (x), #y, "=", (y), #z, "=", (z), #w, "=", (w), #v, "=", \
        (v), #u, "=", (u), #t, "=", (t), #s, "=", (s)),                       \
      flush()
#else
#define SHOW(...)
#endif

#define INT(...)   \
  int __VA_ARGS__; \
  read(__VA_ARGS__)
#define LL(...)   \
  ll __VA_ARGS__; \
  read(__VA_ARGS__)
#define U32(...)   \
  u32 __VA_ARGS__; \
  read(__VA_ARGS__)
#define U64(...)   \
  u64 __VA_ARGS__; \
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
void YA(bool t = 1) { print(t ? "YA" : "TIDAK"); }
void TIDAK(bool t = 1) { YA(!t); }
