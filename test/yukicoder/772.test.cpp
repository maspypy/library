#line 1 "main.cpp"
#define PROBLEM "https://yukicoder.me/problems/no/772"
#line 1 "/home/maspy/compro/library/my_template.hpp"
#if defined(LOCAL)
#include <my_template_compiled.hpp>
#else
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")

#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using u32 = unsigned int;
using u64 = unsigned long long;
using i128 = __int128;
using u128 = unsigned __int128;
using f128 = __float128;

template <class T>
constexpr T infty = 0;
template <>
constexpr int infty<int> = 1'000'000'000;
template <>
constexpr ll infty<ll> = ll(infty<int>) * infty<int> * 2;
template <>
constexpr u32 infty<u32> = infty<int>;
template <>
constexpr u64 infty<u64> = infty<ll>;
template <>
constexpr i128 infty<i128> = i128(infty<ll>) * infty<ll>;
template <>
constexpr double infty<double> = infty<ll>;
template <>
constexpr long double infty<long double> = infty<ll>;

using pi = pair<ll, ll>;
using vi = vector<ll>;
template <class T>
using vc = vector<T>;
template <class T>
using vvc = vector<vc<T>>;
template <class T>
using vvvc = vector<vvc<T>>;
template <class T>
using vvvvc = vector<vvvc<T>>;
template <class T>
using vvvvvc = vector<vvvvc<T>>;
template <class T>
using pq = priority_queue<T>;
template <class T>
using pqg = priority_queue<T, vector<T>, greater<T>>;

#define vv(type, name, h, ...) \
  vector<vector<type>> name(h, vector<type>(__VA_ARGS__))
#define vvv(type, name, h, w, ...)   \
  vector<vector<vector<type>>> name( \
      h, vector<vector<type>>(w, vector<type>(__VA_ARGS__)))
#define vvvv(type, name, a, b, c, ...)       \
  vector<vector<vector<vector<type>>>> name( \
      a, vector<vector<vector<type>>>(       \
             b, vector<vector<type>>(c, vector<type>(__VA_ARGS__))))

// https://trap.jp/post/1224/
#define FOR1(a) for (ll _ = 0; _ < ll(a); ++_)
#define FOR2(i, a) for (ll i = 0; i < ll(a); ++i)
#define FOR3(i, a, b) for (ll i = a; i < ll(b); ++i)
#define FOR4(i, a, b, c) for (ll i = a; i < ll(b); i += (c))
#define FOR1_R(a) for (ll i = (a)-1; i >= ll(0); --i)
#define FOR2_R(i, a) for (ll i = (a)-1; i >= ll(0); --i)
#define FOR3_R(i, a, b) for (ll i = (b)-1; i >= ll(a); --i)
#define overload4(a, b, c, d, e, ...) e
#define overload3(a, b, c, d, ...) d
#define FOR(...) overload4(__VA_ARGS__, FOR4, FOR3, FOR2, FOR1)(__VA_ARGS__)
#define FOR_R(...) overload3(__VA_ARGS__, FOR3_R, FOR2_R, FOR1_R)(__VA_ARGS__)

#define FOR_subset(t, s) \
  for (ll t = (s); t >= 0; t = (t == 0 ? -1 : (t - 1) & (s)))
#define all(x) x.begin(), x.end()
#define len(x) ll(x.size())
#define elif else if

#define eb emplace_back
#define mp make_pair
#define mt make_tuple
#define fi first
#define se second

#define stoi stoll

int popcnt(int x) { return __builtin_popcount(x); }
int popcnt(u32 x) { return __builtin_popcount(x); }
int popcnt(ll x) { return __builtin_popcountll(x); }
int popcnt(u64 x) { return __builtin_popcountll(x); }
int popcnt_mod_2(int x) { return __builtin_parity(x); }
int popcnt_mod_2(u32 x) { return __builtin_parity(x); }
int popcnt_mod_2(ll x) { return __builtin_parityll(x); }
int popcnt_mod_2(u64 x) { return __builtin_parityll(x); }
// (0, 1, 2, 3, 4) -> (-1, 0, 1, 1, 2)
int topbit(int x) { return (x == 0 ? -1 : 31 - __builtin_clz(x)); }
int topbit(u32 x) { return (x == 0 ? -1 : 31 - __builtin_clz(x)); }
int topbit(ll x) { return (x == 0 ? -1 : 63 - __builtin_clzll(x)); }
int topbit(u64 x) { return (x == 0 ? -1 : 63 - __builtin_clzll(x)); }
// (0, 1, 2, 3, 4) -> (-1, 0, 1, 0, 2)
int lowbit(int x) { return (x == 0 ? -1 : __builtin_ctz(x)); }
int lowbit(u32 x) { return (x == 0 ? -1 : __builtin_ctz(x)); }
int lowbit(ll x) { return (x == 0 ? -1 : __builtin_ctzll(x)); }
int lowbit(u64 x) { return (x == 0 ? -1 : __builtin_ctzll(x)); }

template <typename T>
T floor(T a, T b) {
  return a / b - (a % b && (a ^ b) < 0);
}
template <typename T>
T ceil(T x, T y) {
  return floor(x + y - 1, y);
}
template <typename T>
T bmod(T x, T y) {
  return x - y * floor(x, y);
}
template <typename T>
pair<T, T> divmod(T x, T y) {
  T q = floor(x, y);
  return {q, x - q * y};
}

template <typename T, typename U>
T SUM(const vector<U> &A) {
  T sm = 0;
  for (auto &&a: A) sm += a;
  return sm;
}

#define MIN(v) *min_element(all(v))
#define MAX(v) *max_element(all(v))
#define LB(c, x) distance((c).begin(), lower_bound(all(c), (x)))
#define UB(c, x) distance((c).begin(), upper_bound(all(c), (x)))
#define UNIQUE(x) \
  sort(all(x)), x.erase(unique(all(x)), x.end()), x.shrink_to_fit()

template <typename T>
T POP(deque<T> &que) {
  T a = que.front();
  que.pop_front();
  return a;
}
template <typename T>
T POP(pq<T> &que) {
  T a = que.top();
  que.pop();
  return a;
}
template <typename T>
T POP(pqg<T> &que) {
  T a = que.top();
  que.pop();
  return a;
}
template <typename T>
T POP(vc<T> &que) {
  T a = que.back();
  que.pop_back();
  return a;
}

template <typename F>
ll binary_search(F check, ll ok, ll ng, bool check_ok = true) {
  if (check_ok) assert(check(ok));
  while (abs(ok - ng) > 1) {
    auto x = (ng + ok) / 2;
    (check(x) ? ok : ng) = x;
  }
  return ok;
}
template <typename F>
double binary_search_real(F check, double ok, double ng, int iter = 100) {
  FOR(iter) {
    double x = (ok + ng) / 2;
    (check(x) ? ok : ng) = x;
  }
  return (ok + ng) / 2;
}

template <class T, class S>
inline bool chmax(T &a, const S &b) {
  return (a < b ? a = b, 1 : 0);
}
template <class T, class S>
inline bool chmin(T &a, const S &b) {
  return (a > b ? a = b, 1 : 0);
}

// ? は -1
vc<int> s_to_vi(const string &S, char first_char) {
  vc<int> A(S.size());
  FOR(i, S.size()) { A[i] = (S[i] != '?' ? S[i] - first_char : -1); }
  return A;
}

template <typename T, typename U>
vector<T> cumsum(vector<U> &A, int off = 1) {
  int N = A.size();
  vector<T> B(N + 1);
  FOR(i, N) { B[i + 1] = B[i] + A[i]; }
  if (off == 0) B.erase(B.begin());
  return B;
}

// stable sort
template <typename T>
vector<int> argsort(const vector<T> &A) {
  vector<int> ids(len(A));
  iota(all(ids), 0);
  sort(all(ids),
       [&](int i, int j) { return (A[i] == A[j] ? i < j : A[i] < A[j]); });
  return ids;
}

// A[I[0]], A[I[1]], ...
template <typename T>
vc<T> rearrange(const vc<T> &A, const vc<int> &I) {
  vc<T> B(len(I));
  FOR(i, len(I)) B[i] = A[I[i]];
  return B;
}
#endif
#line 1 "/home/maspy/compro/library/other/io.hpp"
#define FASTIO
#include <unistd.h>

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
  memcpy(ibuf, ibuf + pil, pir - pil);
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
  do
    c = ibuf[pil++];
  while (c < '-');
  bool minus = 0;
  if constexpr (is_signed<T>::value || is_same_v<T, i128>) {
    if (c == '-') { minus = 1, c = ibuf[pil++]; }
  }
  x = 0;
  while ('0' <= c) { x = x * 10 + (c & 15), c = ibuf[pil++]; }
  if constexpr (is_signed<T>::value || is_same_v<T, i128>) {
    if (minus) x = -x;
  }
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

template <size_t N = 0, typename T>
void rd(array<T, N> &x) {
  for (auto &d: x) rd(d);
}
template <class T>
void rd(vc<T> &x) {
  for (auto &d: x) rd(d);
}

void read() {}
template <class H, class... T>
void read(H &h, T &... t) {
  rd(h), read(t...);
}

void wt(const char c) {
  if (por == SZ) flush();
  obuf[por++] = c;
}
void wt(const string s) {
  for (char c: s) wt(c);
}
void wt(const char *s) {
  size_t len = strlen(s);
  for (size_t i = 0; i < len; i++) wt(s[i]);
}

template <typename T>
void wt_integer(T x) {
  if (por > SZ - 100) flush();
  if (x < 0) { obuf[por++] = '-', x = -x; }
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
#line 4 "main.cpp"

#line 1 "/home/maspy/compro/library/graph/ds/link_cut_tree.hpp"
/*
各 heavy path を head が左, tail が右となるように splay tree で持つ.
ユーザーが直接呼ぶ可能性があるものだけ int でも実装.
LCT 外で探索するときなど，push を忘れないように注意.
*/

template <typename Node>
struct Link_Cut_Tree {
  using np = Node *;
  int n;
  vc<Node> nodes;

  Link_Cut_Tree(int n = 0) : n(n), nodes(n) { FOR(i, n) nodes[i] = Node(i); }

  Node *operator[](int v) { return &nodes[v]; }

  // underlying tree の根
  Node *get_root(Node *c) {
    expose(c);
    c->push();
    while (c->l) {
      c = c->l;
      c->push();
    }
    splay(c);
    return c;
  }

  // underlying tree の根
  int get_root(int c) { return get_root(&nodes[c])->idx; }

  // parent(c)==p となるように link.
  void link(Node *c, Node *p) {
    evert(c);
    expose(p);
    p->push();
    // no edge -> heavy edge
    assert(!(c->p));
    assert(!(p->r));
    c->p = p;
    p->r = c;
    p->update();
  }

  // parent(c)==p となるように link.
  void link(int c, int p) { return link(&nodes[c], &nodes[p]); }

  void cut(Node *a, Node *b) {
    evert(a);
    expose(b);
    assert(!b->p);
    assert((b->l) == a);
    // heavy edge -> no edge
    b->l->p = nullptr;
    b->l = nullptr;
    b->update();
  }

  void cut(int a, int b) { return cut(&nodes[a], &nodes[b]); }

  // c を underlying tree の根とする.
  // c は splay tree の根にもなる.
  // c は push 済になる
  void evert(Node *c) {
    expose(c);
    c->reverse();
    c->push();
  }

  // c を underlying tree の根とする.
  // c は splay tree の根にもなる.
  void evert(int c) { evert(&nodes[c]); }

  Node *lca(Node *u, Node *v) {
    assert(get_root(u) == get_root(v));
    expose(u);
    return expose(v);
  }

  int lca(int u, int v) { return lca(&nodes[u], &nodes[v])->idx; }

  Node *jump(Node *u, Node *v, int k) {
    evert(v);
    expose(u);
    assert(0 <= k && k < (u->size));
    while (1) {
      u->push();
      int rs = (u->r ? u->r->size : 0);
      if (k < rs) {
        u = u->r;
        continue;
      }
      if (k == rs) { break; }
      k -= rs + 1;
      u = u->l;
    }
    splay(u);
    return u;
  }

  int jump(int u, int v, int k) {
    auto c = jump((*this)[u], (*this)[v], k);
    return c->idx;
  }

  // [root, c] がひとつの splay tree になるように変更する.
  // c が右端で splay tree の根という状態になる.
  // path query はこの状態で c の data を見る.
  // c は push 済になる
  virtual Node *expose(Node *c) {
    Node *now = c;
    Node *rp = nullptr; // 今まで作ったパス
    while (now) {
      splay(now);
      // heavy -> light, light -> heavy.
      if (now->r) { now->add_light(now->r); }
      if (rp) { now->erase_light(rp); }
      now->r = rp;
      now->update();
      rp = now;
      now = now->p;
    }
    splay(c);
    return rp;
  }

  // [root, c] がひとつの splay tree になるように変更する.
  // c が右端で splay tree の根という状態になる.
  // path query はこの状態で c の data を見る.
  int expose(int c) {
    Node *x = expose(&nodes[c]);
    if (!x) return -1;
    return x->idx;
  }

  Node *get_parent(Node *x) {
    expose(x);
    if (!x->l) return nullptr;
    x = x->l;
    while (x->r) x = x->r;
    return x;
  }

  int get_parent(int x) {
    Node *p = get_parent((*this)[x]);
    return (p ? p->idx : -1);
  }

  void set(Node *c, typename Node::VX x) {
    evert(c);
    c->set(x);
  }

  void set(int c, typename Node::VX x) { set((*this)[c], x); }

  typename Node::X prod_path(int a, int b) {
    evert(a), expose(b);
    return (*this)[b]->x;
  }

  // subtree 用の node を使う
  typename Node::X prod_subtree(int v, int root) {
    static_assert(Node::NODE_FOR_SUBTREE);
    if (v == root) {
      evert(root);
      return (*this)[root]->x;
    }
    root = jump(v, root, 1);
    cut(v, root);
    typename Node::X res = (*this)[v]->x;
    link(v, root);
    return res;
  }

  vc<int> collect_heavy_path(int v) {
    np c = (*this)[v];
    while (!is_root(c)) c = c->p;
    vc<int> res;
    auto dfs = [&](auto &dfs, np c, bool rev) -> void {
      if (!rev) {
        if (c->l) dfs(dfs, c->l, rev ^ c->rev);
        res.eb(c->idx);
        if (c->r) dfs(dfs, c->r, rev ^ c->rev);
      } else {
        if (c->r) dfs(dfs, c->r, rev ^ c->rev);
        res.eb(c->idx);
        if (c->l) dfs(dfs, c->l, rev ^ c->rev);
      }
    };
    dfs(dfs, c, false);
    return res;
  }

  void debug() {
    print("p, l, r, rev");
    auto f = [&](np c) -> int { return (c ? c->idx : -1); };
    FOR(i, len(nodes)) {
      print(i, ",", f((*this)[i]->p), f((*this)[i]->l), f((*this)[i]->r),
            (*this)[i]->rev);
    }
    FOR(i, len(nodes)) {
      np c = (*this)[i];
      if (c->l) assert(c->l->p == c);
      if (c->r) assert(c->r->p == c);
    }
  }

private:
  // splay tree 内で完結する操作. 特に heavy, light 構造は変わらない.
  // light pointer は rotate 内でケア
  // c は push 済になる
  void splay(Node *c) {
    c->push();
    while (!is_root(c)) {
      Node *p = c->p;
      Node *pp = (p ? p->p : nullptr);
      if (state(p) == 0) {
        p->push(), c->push();
        rotate(c);
      }
      elif (state(c) == state(p)) {
        pp->push(), p->push(), c->push();
        rotate(p);
        rotate(c);
      }
      else {
        pp->push(), p->push(), c->push();
        rotate(c);
        rotate(c);
      }
    }
  }

  // パスを表す splay tree の根になっているかどうか
  // underlying tree ではない
  bool is_root(Node *c) { return state(c) == 0; }

  // splay tree 内で完結する操作. 特に heavy, light 構造は変わらない.
  // light edge のポインタは変更されうる
  void rotate(Node *n) {
    // n を根に近づける
    Node *pp, *p, *c;
    p = n->p;
    pp = p->p;
    if (p->l == n) {
      c = n->r;
      n->r = p;
      p->l = c;
    } else {
      c = n->l;
      n->l = p;
      p->r = c;
    }
    p->update(), n->update();

    if (pp) {
      if (pp->l == p) pp->l = n;
      elif (pp->r == p) pp->r = n;
      else {
        // light edge pointer が (pp-p) から (pp-n) に変わる
        pp->change_light(p, n);
      }
    }
    n->p = pp;
    p->p = n;
    if (c) c->p = p;
  }

  inline int state(Node *n) {
    if (!n->p) return 0;
    if (n->p->l == n) return 1;
    if (n->p->r == n) return -1;
    return 0;
  }
};
#line 6 "main.cpp"

#line 1 "/home/maspy/compro/library/ds/removable_queue.hpp"
template <typename QUE_TYPE>
struct Removable_Queue {
  using QUE = QUE_TYPE;
  using T = typename QUE::value_type;

  QUE que, rm_que;

  Removable_Queue() {}
  Removable_Queue(vc<T>& dat) : que(all(dat)) {}

  void push(T x) { que.push(x); }
  int size() { return len(que) - len(rm_que); }
  bool empty() { return size() == 0; }

  T pop() {
    refresh();
    return POP(que);
  }
  T top() {
    refresh();
    return que.top();
  }

  void remove(T x) { rm_que.push(x); }

private:
  void refresh() {
    while (len(rm_que) && rm_que.top() == que.top()) {
      rm_que.pop(), que.pop();
    }
  }
};
#line 8 "main.cpp"

struct Node {
  using np = Node *;
  struct VX {
    bool is_edge = false;
    ll x = 0; // 頂点なら X[v], 辺なら長さ
  };
  // (wt, light edge の接続先)
  struct MX {
    Removable_Queue<pq<pair<ll, int>>> que;
    ll sm = 0;
    ll dist_sum = 0;
  };

  struct X {
    ll wt_sum;
    ll length;     // heavy path len
    ll sum1, sum2; // heavy path の端点からの dist sum
  };

  Node *l, *r, *p;
  int idx, size; // size は heavy path の頂点数
  bool rev;
  VX vx;
  MX mx;
  X x;

  Node(int i = 0)
      : l(nullptr), r(nullptr), p(nullptr), idx(i), size(1), rev(0) {}

  void update() {
    size = 1;
    x.wt_sum = (vx.is_edge ? 0 : vx.x);
    x.wt_sum += mx.sm;
    if (l) {
      size += l->size;
      x.wt_sum += l->x.wt_sum;
    }
    if (r) {
      size += r->size;
      x.wt_sum += r->x.wt_sum;
    }

    ll l_len = (l ? l->x.length : 0);
    ll m_len = (vx.is_edge ? vx.x : 0);
    ll r_len = (r ? r->x.length : 0);
    x.length = l_len + m_len + r_len;
    x.sum1 = 0, x.sum2 = 0;
    x.sum1 += mx.sm * (l_len + m_len) + mx.dist_sum;
    x.sum2 += mx.sm * (r_len + m_len) + mx.dist_sum;
    x.sum1 += (vx.is_edge ? 0 : vx.x * l_len);
    x.sum2 += (vx.is_edge ? 0 : vx.x * r_len);
    if (l) {
      x.sum1 += l->x.sum1;
      x.sum2 += l->x.sum2 + (m_len + r_len) * l->x.wt_sum;
    }
    if (r) {
      x.sum2 += r->x.sum2;
      x.sum1 += r->x.sum1 + (m_len + l_len) * r->x.wt_sum;
    }
  }

  void push() {
    if (rev) {
      if (l) l->reverse();
      if (r) r->reverse();
      rev = 0;
    }
  }

  // data の reverse も行う
  void reverse() {
    rev ^= 1;
    swap(l, r);
    swap(x.sum1, x.sum2);
  }

  // LCT 内で expose, update を行うのでここは変更だけ
  void set(VX x) { vx = x; }

  // c がこの時点では update されていないかもしれないが, x は正常なものが入る
  // c->x 等は使わないように注意する
  // c->idx を持っておくと探索できることがある
  void add_light(Node *c) {
    auto x = c->x;
    mx.sm += x.wt_sum;
    mx.que.push(mp(x.wt_sum, c->idx));
    mx.dist_sum += x.sum1;
  }
  void erase_light(Node *c) {
    auto x = c->x;
    mx.sm -= x.wt_sum;
    mx.que.remove(mp(x.wt_sum, c->idx));
    mx.dist_sum -= x.sum1;
  }
  void change_light(np a, np b) {
    auto sm = b->x.wt_sum;
    mx.que.remove(mp(sm, a->idx));
    mx.que.push(mp(sm, b->idx));
  }
};

void solve() {
  LL(N, Q);
  Link_Cut_Tree<Node> LCT(N + Q);
  vi X(N, 1);
  FOR(i, N) { LCT.set(i, {false, 1}); }

  int pid = N;

  ll SUM_ANS = 0;
  auto read_vertex = [&]() -> ll {
    LL(x);
    return (x - 1 + SUM_ANS) % N;
  };

  auto solve_1 = [&](int a, int b, int c) -> void {
    int idx = pid++;
    LCT.set(idx, {true, c});
    LCT.link(a, idx), LCT.link(b, idx);
  };
  auto solve_2 = [&](int a, int b) -> void {
    int c = LCT.jump(a, b, 1);
    LCT.cut(a, c), LCT.cut(b, c);
  };
  auto solve_3 = [&](int a) -> ll {
    X[a] ^= 1;
    LCT.set(a, {false, X[a]});
    LCT.evert(a);
    ll total = LCT[a]->x.wt_sum;
    if (total == 0) return 0;
    ll half = ceil<ll>(total, 2);
    // half 以上の重みを持つ subtree で topological 順で極大なところ

    using np = typename decltype(LCT)::np;
    auto dfs = [&](auto &dfs, np c, ll need) -> np {
      c->push();
      assert(c->x.wt_sum >= need);
      // ll a = (c->l ? c->l->x.wt_sum : 0);
      ll b = (c->r ? c->r->x.wt_sum : 0);
      ll me = (c->vx.is_edge ? 0 : c->vx.x);
      ll mid = c->mx.sm;
      if (me + mid + b >= need) {
        if (b >= need) { return dfs(dfs, c->r, need); }
        if (mid >= half) {
          auto [val, idx] = c->mx.que.top();
          if (val >= half) return dfs(dfs, LCT[idx], half);
        }
        return c;
      }
      return dfs(dfs, c->l, need - (me + mid + b));
    };
    np c = dfs(dfs, LCT[a], half);
    LCT.evert(c);
    return c->x.sum1;
  };

  FOR(q, Q) {
    INT(t);
    if (t == 1) {
      ll a = read_vertex();
      ll b = read_vertex();
      LL(c);
      solve_1(a, b, c);
    }
    if (t == 2) {
      ll a = read_vertex();
      ll b = read_vertex();
      solve_2(a, b);
    }
    if (t == 3) {
      ll a = read_vertex();
      ll ans = solve_3(a);
      print(ans);
      SUM_ANS += ans;
      SUM_ANS %= N;
    }
  }
}

signed main() {
  solve();
  return 0;
}
