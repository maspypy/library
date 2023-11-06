#define FASTIO
#include <unistd.h>

namespace fastio {
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

template <typename T>
struct has_read_method {
  template <typename U>
  static std::true_type test(decltype(&U::read) *);
  template <typename>
  static std::false_type test(...);
  using type = decltype(test<T>(nullptr));
  static constexpr bool value = type::value;
};

template <typename T>
struct has_print_method {
  template <typename U>
  static std::true_type test(decltype(&U::print) *);
  template <typename>
  static std::false_type test(...);
  using type = decltype(test<T>(nullptr));
  static constexpr bool value = type::value;
};

struct Scanner {
  FILE *fp;
  char line[(1 << 15) + 1];
  size_t st = 0, ed = 0;
  void reread() {
    memmove(line, line + st, ed - st);
    ed -= st;
    st = 0;
    ed += fread(line + ed, 1, (1 << 15) - ed, fp);
    line[ed] = '\0';
  }
  void succ() {
    while (true) {
      if (st == ed) {
        reread();
        if (st == ed) return;
      }
      while (st != ed && isspace(line[st])) st++;
      if (st != ed) break;
    }
    if (ed - st <= 100) {
      bool sep = false;
      for (size_t i = st; i < ed; i++) {
        if (isspace(line[i])) {
          sep = true;
          break;
        }
      }
      if (!sep) reread();
    }
    return;
  }

  void rd(char &c) {
    succ();
    c = line[st++];
  }

  void rd(string &x) {
    x.clear();
    succ();
    while (true) {
      size_t sz = 0;
      while (st + sz < ed && !isspace(line[st + sz])) sz++;
      x.append(line + st, sz);
      st += sz;
      if (!sz || st != ed) break;
      reread();
    }
  }

  template <typename T>
  void rd_integer(T &x) {
    succ();
    bool minus = 0;
    char c = line[st++];
    if constexpr (is_signed<T>::value || is_same_v<T, i128>) {
      if (c == '-') { minus = 1, c = line[st++]; }
    }
    x = 0;
    while (c >= '0') { x = x * 10 + (c & 15), c = line[st++]; }
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

  template <typename T>
  typename enable_if<has_read_method<T>::value, void>::type rd(T &x) {
    x.read();
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
  template <class T, class U>
  void rd(pair<T, U> &p) {
    return rd(p.first), rd(p.second);
  }
  template <size_t N = 0, typename T>
  void rd_tuple(T &t) {
    if constexpr (N < std::tuple_size<T>::value) {
      auto &x = std::get<N>(t);
      rd(x);
      rd_tuple<N + 1>(t);
    }
  }
  template <class... T>
  void rd(tuple<T...> &tpl) {
    rd_tuple(tpl);
  }
  template <class T>
  void rd(vc<T> &x) {
    for (auto &d: x) rd(d);
  }
  template <size_t N = 0, typename T>
  void rd(array<T, N> &x) {
    for (auto &d: x) rd(d);
  }
  Scanner(FILE *fp) : fp(fp) {}
};

struct Printer {
  Printer(FILE *_fp) : fp(_fp) {}
  ~Printer() { flush(); }

  static constexpr size_t SIZE = 1 << 15;
  FILE *fp;
  char line[SIZE], out[100];
  size_t pos = 0;
  void flush() {
    fwrite(line, 1, pos, fp);
    pos = 0;
  }

  void wt(const char val) {
    if (pos == SIZE) flush();
    line[pos++] = val;
  }
  void wt(const string &s) {
    for (char c: s) wt(c);
  }
  void wt(const char *s) {
    size_t len = strlen(s);
    for (size_t i = 0; i < len; i++) wt(s[i]);
  }

  template <typename T>
  void wt_integer(T x) {
    if (pos > SIZE - 100) flush();
    if (x < 0) { line[pos++] = '-', x = -x; }
    int outi;
    for (outi = 96; x >= 10000; outi -= 4) {
      memcpy(out + outi, pre.num[x % 10000], 4);
      x /= 10000;
    }
    if (x >= 1000) {
      memcpy(line + pos, pre.num[x], 4), pos += 4;
    } else if (x >= 100) {
      memcpy(line + pos, pre.num[x] + 1, 3), pos += 3;
    } else if (x >= 10) {
      int q = (x * 103) >> 10;
      line[pos] = q | '0';
      line[pos + 1] = (x - q * 10) | '0';
      pos += 2;
    } else
      line[pos++] = x | '0';
    memcpy(line + pos, out + outi + 4, 96 - outi);
    pos += 96 - outi;
  }

  template <typename T>
  void wt_real(T x) {
    ostringstream oss;
    oss << fixed << setprecision(15) << double(x);
    string s = oss.str();
    wt(s);
  }

  template <typename T>
  typename enable_if<has_print_method<T>::value, void>::type wt(T x) {
    x.print();
  }

  void wt(bool x) { wt_integer(int(x)); }
  void wt(int x) { wt_integer(x); }
  void wt(ll x) { wt_integer(x); }
  void wt(i128 x) { wt_integer(x); }
  void wt(u32 x) { wt_integer(x); }
  void wt(u64 x) { wt_integer(x); }
  void wt(u128 x) { wt_integer(x); }
  void wt(double x) { wt_real(x); }
  void wt(long double x) { wt_real(x); }
  void wt(f128 x) { wt_real(x); }

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
  template <class T>
  void wt(const vector<T> val) {
    auto n = val.size();
    for (size_t i = 0; i < n; i++) {
      if (i) wt(' ');
      wt(val[i]);
    }
  }
};
Scanner scanner = Scanner(stdin);
Printer printer = Printer(stdout);
void flush() { printer.flush(); }
void print() { printer.wt('\n'); }
template <class Head, class... Tail>
void print(Head &&head, Tail &&... tail) {
  printer.wt(head);
  if (sizeof...(Tail)) printer.wt(' ');
  print(forward<Tail>(tail)...);
}

void read() {}
template <class Head, class... Tail>
void read(Head &head, Tail &... tail) {
  scanner.rd(head);
  read(tail...);
}
} // namespace fastio
using fastio::print;
using fastio::flush;
using fastio::read;

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
