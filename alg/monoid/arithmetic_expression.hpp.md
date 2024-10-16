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
    - https://ac.nowcoder.com/acm/contest/81599/K
  bundledCode: "#line 1 \"alg/monoid/arithmetic_expression.hpp\"\n// https://ac.nowcoder.com/acm/contest/81599/K\n\
    \n/*\ntype=0: empty\ntype=1: a\ntype=2: a*b*c\ntype=3: a*b+c+d*e\n\u5DE6\u7AEF\
    (a,c,e)\u306E\u6841\u6570\u306E10\u3079\u304D\u3082\u3082\u3064\n*/\ntemplate\
    \ <typename mint>\nstruct Arithmetic_Expression {\n  int type;\n  mint a, b, c,\
    \ d, e, ten;\n  Arithmetic_Expression(char ch = ' ') {\n    if (ch == ' ') { type\
    \ = 0; }\n    elif (ch == '+') { type = 3, a = 0, b = 1, c = 0, d = 1, e = 0,\
    \ ten = 1; }\n    elif (ch == '*') { type = 2, a = 0, b = 1, c = 0, ten = 1; }\n\
    \    elif ('0' <= ch && ch <= '9') { type = 1, a = (ch - '0'), ten = 10; }\n \
    \   else {\n      assert(0);\n    }\n  }\n  mint eval() {\n    if (type == 0)\
    \ return 0;\n    if (type == 1) return a;\n    if (type == 2) return a * b * c;\n\
    \    if (type == 3) return a * b + c + d * e;\n    assert(0);\n    return 0;\n\
    \  }\n};\n\ntemplate <typename mint>\nstruct Monoid_Arithmetic_Expression {\n\
    \  using value_type = Arithmetic_Expression<mint>;\n  using X = value_type;\n\
    \  static X op(const X& L, const X& R) {\n    if (L.type == 0) return R;\n   \
    \ if (R.type == 0) return L;\n    assert(1 <= L.type && L.type <= 3);\n    assert(1\
    \ <= R.type && R.type <= 3);\n    X ANS;\n    if (L.type == 1 && R.type == 1)\
    \ {\n      ANS.type = 1, ANS.a = L.a * R.ten + R.a;\n      ANS.ten = L.ten * R.ten;\n\
    \    }\n    if (L.type == 1 && R.type == 2) {\n      ANS.type = 2, ANS.a = L.a\
    \ * R.ten + R.a, ANS.b = R.b, ANS.c = R.c;\n      ANS.ten = L.ten * R.ten;\n \
    \   }\n    if (L.type == 1 && R.type == 3) {\n      ANS.type = 3, ANS.a = L.a\
    \ * R.ten + R.a, ANS.b = R.b, ANS.c = R.c, ANS.d = R.d, ANS.e = R.e;\n      ANS.ten\
    \ = L.ten * R.ten;\n    }\n    if (L.type == 2 && R.type == 1) {\n      ANS.type\
    \ = 2, ANS.a = L.a, ANS.b = L.b, ANS.c = L.c * R.ten + R.a;\n      ANS.ten = L.ten;\n\
    \    }\n    if (L.type == 2 && R.type == 2) {\n      ANS.type = 2;\n      ANS.a\
    \ = L.a, ANS.b = L.b * (L.c * R.ten + R.a) * R.b, ANS.c = R.c;\n      ANS.ten\
    \ = L.ten;\n    }\n    if (L.type == 2 && R.type == 3) {\n      ANS.type = 3;\n\
    \      ANS.a = L.a, ANS.b = L.b * (L.c * R.ten + R.a) * R.b, ANS.c = R.c, ANS.d\
    \ = R.d, ANS.e = R.e;\n      ANS.ten = L.ten;\n    }\n    if (L.type == 3 && R.type\
    \ == 1) {\n      ANS.type = 3;\n      ANS.a = L.a, ANS.b = L.b, ANS.c = L.c, ANS.d\
    \ = L.d, ANS.e = (L.e * R.ten + R.a);\n      ANS.ten = L.ten;\n    }\n    if (L.type\
    \ == 3 && R.type == 2) {\n      ANS.type = 3;\n      ANS.a = L.a, ANS.b = L.b,\
    \ ANS.c = L.c, ANS.d = L.d * (L.e * R.ten + R.a) * R.b, ANS.e = R.c;\n      ANS.ten\
    \ = L.ten;\n    }\n    if (L.type == 3 && R.type == 3) {\n      ANS.type = 3;\n\
    \      ANS.a = L.a, ANS.b = L.b, ANS.c = L.c + L.d * (L.e * R.ten + R.a) * R.b\
    \ + R.c, ANS.d = R.d, ANS.e = R.e;\n      ANS.ten = L.ten;\n    }\n    return\
    \ ANS;\n  }\n  static constexpr X unit() { return X(); }\n  static constexpr bool\
    \ commute = 0;\n};\n"
  code: "// https://ac.nowcoder.com/acm/contest/81599/K\n\n/*\ntype=0: empty\ntype=1:\
    \ a\ntype=2: a*b*c\ntype=3: a*b+c+d*e\n\u5DE6\u7AEF(a,c,e)\u306E\u6841\u6570\u306E\
    10\u3079\u304D\u3082\u3082\u3064\n*/\ntemplate <typename mint>\nstruct Arithmetic_Expression\
    \ {\n  int type;\n  mint a, b, c, d, e, ten;\n  Arithmetic_Expression(char ch\
    \ = ' ') {\n    if (ch == ' ') { type = 0; }\n    elif (ch == '+') { type = 3,\
    \ a = 0, b = 1, c = 0, d = 1, e = 0, ten = 1; }\n    elif (ch == '*') { type =\
    \ 2, a = 0, b = 1, c = 0, ten = 1; }\n    elif ('0' <= ch && ch <= '9') { type\
    \ = 1, a = (ch - '0'), ten = 10; }\n    else {\n      assert(0);\n    }\n  }\n\
    \  mint eval() {\n    if (type == 0) return 0;\n    if (type == 1) return a;\n\
    \    if (type == 2) return a * b * c;\n    if (type == 3) return a * b + c + d\
    \ * e;\n    assert(0);\n    return 0;\n  }\n};\n\ntemplate <typename mint>\nstruct\
    \ Monoid_Arithmetic_Expression {\n  using value_type = Arithmetic_Expression<mint>;\n\
    \  using X = value_type;\n  static X op(const X& L, const X& R) {\n    if (L.type\
    \ == 0) return R;\n    if (R.type == 0) return L;\n    assert(1 <= L.type && L.type\
    \ <= 3);\n    assert(1 <= R.type && R.type <= 3);\n    X ANS;\n    if (L.type\
    \ == 1 && R.type == 1) {\n      ANS.type = 1, ANS.a = L.a * R.ten + R.a;\n   \
    \   ANS.ten = L.ten * R.ten;\n    }\n    if (L.type == 1 && R.type == 2) {\n \
    \     ANS.type = 2, ANS.a = L.a * R.ten + R.a, ANS.b = R.b, ANS.c = R.c;\n   \
    \   ANS.ten = L.ten * R.ten;\n    }\n    if (L.type == 1 && R.type == 3) {\n \
    \     ANS.type = 3, ANS.a = L.a * R.ten + R.a, ANS.b = R.b, ANS.c = R.c, ANS.d\
    \ = R.d, ANS.e = R.e;\n      ANS.ten = L.ten * R.ten;\n    }\n    if (L.type ==\
    \ 2 && R.type == 1) {\n      ANS.type = 2, ANS.a = L.a, ANS.b = L.b, ANS.c = L.c\
    \ * R.ten + R.a;\n      ANS.ten = L.ten;\n    }\n    if (L.type == 2 && R.type\
    \ == 2) {\n      ANS.type = 2;\n      ANS.a = L.a, ANS.b = L.b * (L.c * R.ten\
    \ + R.a) * R.b, ANS.c = R.c;\n      ANS.ten = L.ten;\n    }\n    if (L.type ==\
    \ 2 && R.type == 3) {\n      ANS.type = 3;\n      ANS.a = L.a, ANS.b = L.b * (L.c\
    \ * R.ten + R.a) * R.b, ANS.c = R.c, ANS.d = R.d, ANS.e = R.e;\n      ANS.ten\
    \ = L.ten;\n    }\n    if (L.type == 3 && R.type == 1) {\n      ANS.type = 3;\n\
    \      ANS.a = L.a, ANS.b = L.b, ANS.c = L.c, ANS.d = L.d, ANS.e = (L.e * R.ten\
    \ + R.a);\n      ANS.ten = L.ten;\n    }\n    if (L.type == 3 && R.type == 2)\
    \ {\n      ANS.type = 3;\n      ANS.a = L.a, ANS.b = L.b, ANS.c = L.c, ANS.d =\
    \ L.d * (L.e * R.ten + R.a) * R.b, ANS.e = R.c;\n      ANS.ten = L.ten;\n    }\n\
    \    if (L.type == 3 && R.type == 3) {\n      ANS.type = 3;\n      ANS.a = L.a,\
    \ ANS.b = L.b, ANS.c = L.c + L.d * (L.e * R.ten + R.a) * R.b + R.c, ANS.d = R.d,\
    \ ANS.e = R.e;\n      ANS.ten = L.ten;\n    }\n    return ANS;\n  }\n  static\
    \ constexpr X unit() { return X(); }\n  static constexpr bool commute = 0;\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: alg/monoid/arithmetic_expression.hpp
  requiredBy: []
  timestamp: '2024-10-16 22:34:39+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: alg/monoid/arithmetic_expression.hpp
layout: document
redirect_from:
- /library/alg/monoid/arithmetic_expression.hpp
- /library/alg/monoid/arithmetic_expression.hpp.html
title: alg/monoid/arithmetic_expression.hpp
---
