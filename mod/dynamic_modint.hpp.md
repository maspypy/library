---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.12.13/x64/lib/python3.12/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n          \
    \         ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \  File \"/opt/hostedtoolcache/Python/3.12.13/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.12.13/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.12.13/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.12.13/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \                ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n \
    \ File \"/opt/hostedtoolcache/Python/3.12.13/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: nt/primetest.hpp:\
    \ line -1: no such header\n"
  code: "\n#include \"other/bit.hpp\"\n#include \"mod/modint_common.hpp\"\n#include\
    \ \"mod/primitive_root.hpp\"\n#include \"mod/barrett.hpp\"\n\ntemplate <int id>\n\
    struct Dynamic_Modint {\n  static constexpr bool is_modint = true;\n  using mint\
    \ = Dynamic_Modint;\n  u32 val;\n  static Barrett bt;\n  static u32 umod() { return\
    \ bt.umod(); }\n\n  static int get_mod() { return (int)(bt.umod()); }\n  static\
    \ void set_mod(int m) {\n    assert(1 <= m);\n    bt = Barrett(m);\n  }\n\n  static\
    \ Dynamic_Modint raw(u32 v) {\n    Dynamic_Modint x;\n    x.val = v;\n    return\
    \ x;\n  }\n  Dynamic_Modint() : val(0) {}\n  Dynamic_Modint(u32 x) : val(bt.modulo(x))\
    \ {}\n  Dynamic_Modint(u64 x) : val(bt.modulo(x)) {}\n  Dynamic_Modint(int x)\
    \ : val((x %= get_mod()) < 0 ? x + get_mod() : x) {}\n  Dynamic_Modint(ll x) :\
    \ val((x %= get_mod()) < 0 ? x + get_mod() : x) {}\n  Dynamic_Modint(i128 x) :\
    \ val((x %= get_mod()) < 0 ? x + get_mod() : x){};\n\n  bool operator<(const mint&\
    \ other) const { return val < other.val; }\n  mint& operator+=(const mint& rhs)\
    \ {\n    val = (val += rhs.val) < umod() ? val : val - umod();\n    return *this;\n\
    \  }\n  mint& operator-=(const mint& rhs) {\n    val = (val += umod() - rhs.val)\
    \ < umod() ? val : val - umod();\n    return *this;\n  }\n  mint& operator*=(const\
    \ mint& rhs) {\n    val = bt.mul(val, rhs.val);\n    return *this;\n  }\n  mint&\
    \ operator/=(const mint& rhs) { return *this = *this * rhs.inverse(); }\n  mint\
    \ operator-() const { return mint() - *this; }\n  mint pow(ll n) const {\n   \
    \ assert(0 <= n);\n    mint x = *this, r = 1;\n    while (n) {\n      if (n &\
    \ 1) r *= x;\n      x *= x, n >>= 1;\n    }\n    return r;\n  }\n  mint inverse()\
    \ const {\n    int x = val, mod = get_mod();\n    int a = x, b = mod, u = 1, v\
    \ = 0, t;\n    while (b > 0) {\n      t = a / b;\n      swap(a -= t * b, b), swap(u\
    \ -= t * v, v);\n    }\n    if (u < 0) u += mod;\n    return u;\n  }\n\n  friend\
    \ mint operator+(const mint& lhs, const mint& rhs) {\n    return mint(lhs) +=\
    \ rhs;\n  }\n  friend mint operator-(const mint& lhs, const mint& rhs) {\n   \
    \ return mint(lhs) -= rhs;\n  }\n  friend mint operator*(const mint& lhs, const\
    \ mint& rhs) {\n    return mint(lhs) *= rhs;\n  }\n  friend mint operator/(const\
    \ mint& lhs, const mint& rhs) {\n    return mint(lhs) /= rhs;\n  }\n  friend bool\
    \ operator==(const mint& lhs, const mint& rhs) {\n    return lhs.val == rhs.val;\n\
    \  }\n  friend bool operator!=(const mint& lhs, const mint& rhs) {\n    return\
    \ lhs.val != rhs.val;\n  }\n  static pair<int, int>& get_ntt() {\n    static pair<int,\
    \ int> p = {-1, -1};\n    return p;\n  }\n  static void set_ntt_info() {\n   \
    \ int mod = get_mod();\n    int k = lowbit(mod - 1);\n    int r = primitive_root(mod);\n\
    \    r = mod_pow(r, (mod - 1) >> k, mod);\n    get_ntt() = {k, r};\n  }\n  static\
    \ pair<int, int> ntt_info() { return get_ntt(); }\n  static bool can_ntt() { return\
    \ ntt_info().fi != -1; }\n};\n\n#ifdef FASTIO\ntemplate <int id>\nvoid rd(Dynamic_Modint<id>&\
    \ x) {\n  fastio::rd(x.val);\n  x.val %= Dynamic_Modint<id>::umod();\n}\ntemplate\
    \ <int id>\nvoid wt(Dynamic_Modint<id> x) {\n  fastio::wt(x.val);\n}\n#endif\n\
    \nusing dmint = Dynamic_Modint<-1>;\ntemplate <int id>\nBarrett Dynamic_Modint<id>::bt;\n"
  dependsOn: []
  isVerificationFile: false
  path: mod/dynamic_modint.hpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: mod/dynamic_modint.hpp
layout: document
redirect_from:
- /library/mod/dynamic_modint.hpp
- /library/mod/dynamic_modint.hpp.html
title: mod/dynamic_modint.hpp
---
