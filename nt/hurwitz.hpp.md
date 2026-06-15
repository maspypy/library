---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links:
    - https://codeforces.com/contest/1375/problem/I
  bundledCode: "#line 1 \"nt/hurwitz.hpp\"\n\n/*\nhttps://codeforces.com/contest/1375/problem/I\n\
    Hurwitz integers\nq=a+bi+cj+dk, a,b,c,d \u306F\u5168\u90E8\u6574\u6570\u307E\u305F\
    \u306F\u5168\u90E8\u534A\u6574\u6570\n\u5B9F\u88C5\u5185\u90E8\u3067\u306F q=(a+bi+cj+dk)/2\
    \ \u3068\u3044\u3046 a,b,c,d \u3092\u6301\u3064\n\n\u7ACB\u65B9\u4F53\u683C\u5B50\
    \u306E\u7279\u5FB4\u3065\u3051\nq: Hurwitz \u3092\u7528\u3044\u3066 q (Zi+Zj+Zk)\
    \ conjugate(q) \u3068\u66F8\u3051\u308B\n*/\ntemplate <typename T>\nstruct Hurwitz\
    \ {\n  static_assert(is_same_v<T, ll> || is_same_v<T, i128>);\n  T a, b, c, d;\n\
    \  Hurwitz(T a, T b, T c, T d) : a(a), b(b), c(c), d(d) { validate(); }\n  Hurwitz(T\
    \ x = 0) : a(2 * x), b(0), c(0), d(0) {}\n\n  inline void validate() {\n    assert((a\
    \ + b) % 2 == 0 && (a + c) % 2 == 0 && (a + d) % 2 == 0);\n  }\n\n  Hurwitz conjugate()\
    \ { return Hurwitz(a, -b, -c, -d); }\n  bool is_real() { return (b == 0 && c ==\
    \ 0 && d == 0); }\n  bool is_pure_imaginary() { return (a == 0); }\n  bool is_zero()\
    \ { return (a == 0 && b == 0 && c == 0 && d == 0); }\n\n  Hurwitz &operator+=(const\
    \ Hurwitz &p) {\n    a += p.a, b += p.b, c += p.c, d += p.d;\n    return *this;\n\
    \  }\n  Hurwitz &operator-=(const Hurwitz &p) {\n    a -= p.a, b -= p.b, c -=\
    \ p.c, d -= p.d;\n    return *this;\n  }\n  Hurwitz &operator*=(const Hurwitz\
    \ &p) {\n    T a1 = (a * p.a - b * p.b - c * p.c - d * p.d) / 2;\n    T b1 = (a\
    \ * p.b + b * p.a + c * p.d - d * p.c) / 2;\n    T c1 = (a * p.c - b * p.d + c\
    \ * p.a + d * p.b) / 2;\n    T d1 = (a * p.d + b * p.c - c * p.b + d * p.a) /\
    \ 2;\n    a = a1, b = b1, c = c1, d = d1;\n    return *this;\n  }\n  Hurwitz operator-()\
    \ const { return Hurwitz(-a, -b, -c, -d); }\n  Hurwitz operator+(const Hurwitz\
    \ &p) const { return Hurwitz(*this) += p; }\n  Hurwitz operator-(const Hurwitz\
    \ &p) const { return Hurwitz(*this) -= p; }\n  Hurwitz operator*(const Hurwitz\
    \ &p) const { return Hurwitz(*this) *= p; }\n  bool operator==(const Hurwitz &p)\
    \ const {\n    return (a == p.a && b == p.b && c == p.c && d == p.d);\n  }\n \
    \ bool operator!=(const Hurwitz &p) const { return !(*(this) == p); }\n  T norm()\
    \ { return (a * a + b * b + c * c + d * d) / 4; }\n\n  static Hurwitz next_even(Hurwitz\
    \ x) {\n    auto f = [&](T a) -> T { return a + (a & 1); };\n    return Hurwitz(f(x.a),\
    \ f(x.b), f(x.c), f(x.d));\n  }\n  static Hurwitz next_odd(Hurwitz x) {\n    auto\
    \ f = [&](T a) -> T { return a + 1 - (a & 1); };\n    return Hurwitz(f(x.a), f(x.b),\
    \ f(x.c), f(x.d));\n  }\n\n  // x/y=(q,r): x=yq+r. \u5272\u308A\u5207\u308C\u308B\
    \u3068\u304D\u306B y \u304C left divisor \u306B\u306A\u308B\u5411\u304D\n  static\
    \ pair<Hurwitz, Hurwitz> left_division(Hurwitz x, Hurwitz y) {\n    Hurwitz z\
    \ = y.conjugate() * x;\n    T k = y.norm();\n    Hurwitz q;\n    q.a = floor<T>(z.a,\
    \ k);\n    q.b = floor<T>(z.b, k);\n    q.c = floor<T>(z.c, k);\n    q.d = floor<T>(z.d,\
    \ k);\n    Hurwitz q0 = next_even(q), q1 = next_odd(q);\n    Hurwitz r0 = x -\
    \ y * q0, r1 = x - y * q1;\n    if (r0.norm() < r1.norm()) return {q0, r0};\n\
    \    return {q1, r1};\n  }\n\n  // x/y=(q,r): x=qy+r. \u5272\u308A\u5207\u308C\
    \u308B\u3068\u304D\u306B y \u304C right divisor \u306B\u306A\u308B\u5411\u304D\
    \n  static pair<Hurwitz, Hurwitz> right_division(Hurwitz x, Hurwitz y) {\n   \
    \ Hurwitz z = x * y.conjugate();\n    T k = y.norm();\n    Hurwitz q;\n    q.a\
    \ = floor<T>(z.a, k);\n    q.b = floor<T>(z.b, k);\n    q.c = floor<T>(z.c, k);\n\
    \    q.d = floor<T>(z.d, k);\n    Hurwitz q0 = next_even(q), q1 = next_odd(q);\n\
    \    Hurwitz r0 = x - q0 * y, r1 = x - q1 * y;\n    if (r0.norm() < r1.norm())\
    \ return {q0, r0};\n    return {q1, r1};\n  }\n\n  // x=gs, y=gt, g=xu+yv \u3068\
    \u66F8\u3051\u308B g\n  static Hurwitz left_gcd(Hurwitz x, Hurwitz y) {\n    while\
    \ (!y.is_zero()) {\n      x = left_division(x, y).se;\n      swap(x, y);\n   \
    \ }\n    return x;\n  }\n\n  // x=sg, y=tg, g=ux+vy \u3068\u66F8\u3051\u308B g\n\
    \  static Hurwitz right_gcd(Hurwitz x, Hurwitz y) {\n    while (!y.is_zero())\
    \ {\n      x = right_division(x, y).se;\n      swap(x, y);\n    }\n    return\
    \ x;\n  }\n};\n"
  code: "\n/*\nhttps://codeforces.com/contest/1375/problem/I\nHurwitz integers\nq=a+bi+cj+dk,\
    \ a,b,c,d \u306F\u5168\u90E8\u6574\u6570\u307E\u305F\u306F\u5168\u90E8\u534A\u6574\
    \u6570\n\u5B9F\u88C5\u5185\u90E8\u3067\u306F q=(a+bi+cj+dk)/2 \u3068\u3044\u3046\
    \ a,b,c,d \u3092\u6301\u3064\n\n\u7ACB\u65B9\u4F53\u683C\u5B50\u306E\u7279\u5FB4\
    \u3065\u3051\nq: Hurwitz \u3092\u7528\u3044\u3066 q (Zi+Zj+Zk) conjugate(q) \u3068\
    \u66F8\u3051\u308B\n*/\ntemplate <typename T>\nstruct Hurwitz {\n  static_assert(is_same_v<T,\
    \ ll> || is_same_v<T, i128>);\n  T a, b, c, d;\n  Hurwitz(T a, T b, T c, T d)\
    \ : a(a), b(b), c(c), d(d) { validate(); }\n  Hurwitz(T x = 0) : a(2 * x), b(0),\
    \ c(0), d(0) {}\n\n  inline void validate() {\n    assert((a + b) % 2 == 0 &&\
    \ (a + c) % 2 == 0 && (a + d) % 2 == 0);\n  }\n\n  Hurwitz conjugate() { return\
    \ Hurwitz(a, -b, -c, -d); }\n  bool is_real() { return (b == 0 && c == 0 && d\
    \ == 0); }\n  bool is_pure_imaginary() { return (a == 0); }\n  bool is_zero()\
    \ { return (a == 0 && b == 0 && c == 0 && d == 0); }\n\n  Hurwitz &operator+=(const\
    \ Hurwitz &p) {\n    a += p.a, b += p.b, c += p.c, d += p.d;\n    return *this;\n\
    \  }\n  Hurwitz &operator-=(const Hurwitz &p) {\n    a -= p.a, b -= p.b, c -=\
    \ p.c, d -= p.d;\n    return *this;\n  }\n  Hurwitz &operator*=(const Hurwitz\
    \ &p) {\n    T a1 = (a * p.a - b * p.b - c * p.c - d * p.d) / 2;\n    T b1 = (a\
    \ * p.b + b * p.a + c * p.d - d * p.c) / 2;\n    T c1 = (a * p.c - b * p.d + c\
    \ * p.a + d * p.b) / 2;\n    T d1 = (a * p.d + b * p.c - c * p.b + d * p.a) /\
    \ 2;\n    a = a1, b = b1, c = c1, d = d1;\n    return *this;\n  }\n  Hurwitz operator-()\
    \ const { return Hurwitz(-a, -b, -c, -d); }\n  Hurwitz operator+(const Hurwitz\
    \ &p) const { return Hurwitz(*this) += p; }\n  Hurwitz operator-(const Hurwitz\
    \ &p) const { return Hurwitz(*this) -= p; }\n  Hurwitz operator*(const Hurwitz\
    \ &p) const { return Hurwitz(*this) *= p; }\n  bool operator==(const Hurwitz &p)\
    \ const {\n    return (a == p.a && b == p.b && c == p.c && d == p.d);\n  }\n \
    \ bool operator!=(const Hurwitz &p) const { return !(*(this) == p); }\n  T norm()\
    \ { return (a * a + b * b + c * c + d * d) / 4; }\n\n  static Hurwitz next_even(Hurwitz\
    \ x) {\n    auto f = [&](T a) -> T { return a + (a & 1); };\n    return Hurwitz(f(x.a),\
    \ f(x.b), f(x.c), f(x.d));\n  }\n  static Hurwitz next_odd(Hurwitz x) {\n    auto\
    \ f = [&](T a) -> T { return a + 1 - (a & 1); };\n    return Hurwitz(f(x.a), f(x.b),\
    \ f(x.c), f(x.d));\n  }\n\n  // x/y=(q,r): x=yq+r. \u5272\u308A\u5207\u308C\u308B\
    \u3068\u304D\u306B y \u304C left divisor \u306B\u306A\u308B\u5411\u304D\n  static\
    \ pair<Hurwitz, Hurwitz> left_division(Hurwitz x, Hurwitz y) {\n    Hurwitz z\
    \ = y.conjugate() * x;\n    T k = y.norm();\n    Hurwitz q;\n    q.a = floor<T>(z.a,\
    \ k);\n    q.b = floor<T>(z.b, k);\n    q.c = floor<T>(z.c, k);\n    q.d = floor<T>(z.d,\
    \ k);\n    Hurwitz q0 = next_even(q), q1 = next_odd(q);\n    Hurwitz r0 = x -\
    \ y * q0, r1 = x - y * q1;\n    if (r0.norm() < r1.norm()) return {q0, r0};\n\
    \    return {q1, r1};\n  }\n\n  // x/y=(q,r): x=qy+r. \u5272\u308A\u5207\u308C\
    \u308B\u3068\u304D\u306B y \u304C right divisor \u306B\u306A\u308B\u5411\u304D\
    \n  static pair<Hurwitz, Hurwitz> right_division(Hurwitz x, Hurwitz y) {\n   \
    \ Hurwitz z = x * y.conjugate();\n    T k = y.norm();\n    Hurwitz q;\n    q.a\
    \ = floor<T>(z.a, k);\n    q.b = floor<T>(z.b, k);\n    q.c = floor<T>(z.c, k);\n\
    \    q.d = floor<T>(z.d, k);\n    Hurwitz q0 = next_even(q), q1 = next_odd(q);\n\
    \    Hurwitz r0 = x - q0 * y, r1 = x - q1 * y;\n    if (r0.norm() < r1.norm())\
    \ return {q0, r0};\n    return {q1, r1};\n  }\n\n  // x=gs, y=gt, g=xu+yv \u3068\
    \u66F8\u3051\u308B g\n  static Hurwitz left_gcd(Hurwitz x, Hurwitz y) {\n    while\
    \ (!y.is_zero()) {\n      x = left_division(x, y).se;\n      swap(x, y);\n   \
    \ }\n    return x;\n  }\n\n  // x=sg, y=tg, g=ux+vy \u3068\u66F8\u3051\u308B g\n\
    \  static Hurwitz right_gcd(Hurwitz x, Hurwitz y) {\n    while (!y.is_zero())\
    \ {\n      x = right_division(x, y).se;\n      swap(x, y);\n    }\n    return\
    \ x;\n  }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: nt/hurwitz.hpp
  requiredBy: []
  timestamp: '2026-06-15 22:08:56+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: nt/hurwitz.hpp
layout: document
redirect_from:
- /library/nt/hurwitz.hpp
- /library/nt/hurwitz.hpp.html
title: nt/hurwitz.hpp
---
