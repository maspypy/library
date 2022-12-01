namespace fastio {
// https://nyaannyaan.github.io/library/misc/fastio.hpp を元に改造

// クラスが read(), print() を持っているかを判定するメタ関数
struct has_print_impl {
  template <class T>
  static auto check(T &&x) -> decltype(x.print(), std::true_type{});

  template <class T>
  static auto check(...) -> std::false_type;
};

template <class T>
class has_print : public decltype(has_print_impl::check<T>(std::declval<T>())) {
};

struct has_read_impl {
  template <class T>
  static auto check(T &&x) -> decltype(x.read(), std::true_type{});

  template <class T>
  static auto check(...) -> std::false_type;
};

template <class T>
class has_read : public decltype(has_read_impl::check<T>(std::declval<T>())) {};

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

inline void read_single(char &c) {
  if (in_left + 32 > in_right) load();
  c = inbuf[in_left++];
}

template <class T, enable_if_t<is_same<T, string>::value, int> = 0>
inline void read_single(T &x) {
  char c = ' ';
  do {
    if (in_left + 32 > in_right) load();
    c = inbuf[in_left++];
  } while (c == ' ' || c == '\n');
  x += c;
  while (1) {
    if (in_left + 32 > in_right) load();
    c = inbuf[in_left++];
    if (c == ' ' || c == '\n') break;
    x += c;
  }
}

template <class T, enable_if_t<is_integral<T>::value, int> = 0>
inline void read_single(T &x) {
  if (in_left + 32 > in_right) load();
  char c;
  do
    c = inbuf[in_left++];
  while (c < '-');
  bool minus = false;
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

template <typename T, typename enable_if<has_read<T>::value>::type * = nullptr>
inline void read_single(T x) {
  x.read();
}
template <class T, class U>
inline void read_single(pair<T, U> &p) {
  read_single(p.first), read_single(p.second);
}
template <class... T>
inline void read(tuple<T...> &tpl) {
  apply([&](auto... t) { (read(t), ...); }, tpl);
}
template <class T>
inline void read_single(vector<T> &ref) {
  for (auto &d: ref) read_single(d);
}
template <class T, int N>
inline void read_single(array<T, N> &ref) {
  for (auto &d: ref) read_single(d);
}

inline void read() {}
template <typename Head, typename... Tail>
inline void read(Head &head, Tail &... tail) {
  read_single(head);
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
template <class T, enable_if_t<is_integral<T>::value, int> = 0>
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
inline void write(const double &x) {
  ostringstream oss;
  oss << fixed << setprecision(15) << x;
  string s = oss.str();
  write(s);
}
inline void write(const long double &x) {
  ostringstream oss;
  oss << fixed << setprecision(15) << x;
  string s = oss.str();
  write(s);
}
template <typename T, typename enable_if<has_print<T>::value>::type * = nullptr>
inline void write(T x) {
  x.print();
}
template <class T>
void write(const vector<T> &val) {
  auto n = val.size();
  for (size_t i = 0; i < n; i++) {
    if (i) write(' ');
    write(val[i]);
  }
}
template <class T, class U>
void write(const pair<T, U> &val) {
  write(val.first);
  write(' ');
  write(val.second);
}
template <class T, size_t S>
inline void write(const array<T, S> &val) {
  auto n = val.size();
  for (size_t i = 0; i < n; i++) {
    if (i) write(' ');
    write(val[i]);
  }
}
inline void write(i128 val) {
  string s;
  bool negative = 0;
  if (val < 0) {
    negative = 1;
    val = -val;
  }
  while (val) {
    s += '0' + int(val % 10);
    val /= 10;
  }
  if (negative) s += "-";
  reverse(all(s));
  if (len(s) == 0) s = "0";
  write(s);
}
struct Dummy {
  Dummy() { atexit(flush); }
} dummy;

void print() { fastio::write('\n'); }
template <class Head, class... Tail>
void print(Head &&head, Tail &&... tail) {
  fastio::write(head);
  if (sizeof...(Tail)) fastio::write(' ');
  print(forward<Tail>(tail)...);
}
} // namespace fastio
using fastio::read;
using fastio::print;

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
