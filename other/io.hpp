namespace fastio { // https://nyaannyaan.github.io/library/misc/fastio.hpp
static constexpr int SZ = 1 << 17;
char inbuf[SZ], outbuf[SZ];
int in_left = 0, in_right = 0, out_right = 0;

struct Pre {
  char num[40000];
  constexpr Pre() : num() {
    for (int i = 0; i < 10000; i++) {
      int n = i;
      for (int j = 3; j >= 0; j--) {
        num[i * 4 + j] = n % 10 + '0';
        n /= 10;
      }
    }
  }
} constexpr pre;

inline void load() {
  int len = in_right - in_left;
  memmove(inbuf, inbuf + in_left, len);
  in_right = len + fread(inbuf + len, 1, SZ - len, stdin);
  in_left = 0;
}

inline void flush() {
  fwrite(outbuf, 1, out_right, stdout);
  out_right = 0;
}

inline void skip_space() {
  if (in_left + 32 > in_right) load();
  while (inbuf[in_left] <= ' ') in_left++;
}

inline void read(char &c) {
  if (in_left + 32 > in_right) load();
  c = inbuf[in_left++];
}
template <typename T>
inline void read(T &x) {
  if (in_left + 32 > in_right) load();
  char c;
  do
    c = inbuf[in_left++];
  while (c < '-');
  [[maybe_unused]] bool minus = false;
  if constexpr (is_signed<T>::value == true) {
    if (c == '-') minus = true, c = inbuf[in_left++];
  }
  x = 0;
  while (c >= '0') {
    x = x * 10 + (c & 15);
    c = inbuf[in_left++];
  }
  if constexpr (is_signed<T>::value == true) {
    if (minus) x = -x;
  }
}
inline void read() {}
template <typename Head, typename... Tail>
inline void read(Head &head, Tail &... tail) {
  read(head);
  read(tail...);
}

inline void write(char c) {
  if (out_right > SZ - 32) flush();
  outbuf[out_right++] = c;
}
inline void write(bool b) {
  if (out_right > SZ - 32) flush();
  outbuf[out_right++] = b ? '1' : '0';
}
inline void write(const string &s) {
  if (out_right + s.size() > SZ - 32) flush();
  memcpy(outbuf + out_right, s.data(), sizeof(char) * s.size());
  out_right += s.size();
}
template <typename T>
inline void write(T x) {
  if (out_right > SZ - 32) flush();
  if (!x) {
    outbuf[out_right++] = '0';
    return;
  }
  if constexpr (is_signed<T>::value == true) {
    if (x < 0) outbuf[out_right++] = '-', x = -x;
  }
  int i = 12;
  char buf[16];
  while (x >= 10000) {
    memcpy(buf + i, pre.num + (x % 10000) * 4, 4);
    x /= 10000;
    i -= 4;
  }
  if (x < 100) {
    if (x < 10) {
      outbuf[out_right] = '0' + x;
      ++out_right;
    } else {
      uint32_t q = (uint32_t(x) * 205) >> 11;
      uint32_t r = uint32_t(x) - q * 10;
      outbuf[out_right] = '0' + q;
      outbuf[out_right + 1] = '0' + r;
      out_right += 2;
    }
  } else {
    if (x < 1000) {
      memcpy(outbuf + out_right, pre.num + (x << 2) + 1, 3);
      out_right += 3;
    } else {
      memcpy(outbuf + out_right, pre.num + (x << 2), 4);
      out_right += 4;
    }
  }
  memcpy(outbuf + out_right, buf + i + 4, 12 - i);
  out_right += 12 - i;
}
inline void write() {}
template <typename Head, typename... Tail>
inline void write(Head &&head, Tail &&... tail) {
  write(head);
  write(forward<Tail>(tail)...);
}
template <typename... Args>
inline void writen(Args &&... x) {
  write(forward<Args>(x)...);
  write('\n');
}

struct Dummy {
  Dummy() { atexit(flush); }
} dummy;
} // namespace fastio

void print() { fastio::write('\n'); }
template <class Head, class... Tail>
void print(Head &&head, Tail &&... tail) {
  fastio::write(head);
  if (sizeof...(Tail)) fastio::write(' ');
  print(forward<Tail>(tail)...);
}

void read() {}
template <class Head, class... Tail>
void read(Head &head, Tail &... tail) {
  fastio::read(head);
  read(tail...);
}

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

void YES(bool t = 1) { print<string>(t ? "YES" : "NO"); }
void NO(bool t = 1) { YES(!t); }
void Yes(bool t = 1) { print<string>(t ? "Yes" : "No"); }
void No(bool t = 1) { Yes(!t); }
void yes(bool t = 1) { print<string>(t ? "yes" : "no"); }
void no(bool t = 1) { yes(!t); }