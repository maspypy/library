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
  bundledCode: "#line 1 \"poly/fft.hpp\"\nnamespace CFFT {\r\nusing real = double;\r\
    \n\r\nstruct C {\r\n  real x, y;\r\n\r\n  C() : x(0), y(0) {}\r\n\r\n  C(real\
    \ x, real y) : x(x), y(y) {}\r\n  inline C operator+(const C& c) const { return\
    \ C(x + c.x, y + c.y); }\r\n  inline C operator-(const C& c) const { return C(x\
    \ - c.x, y - c.y); }\r\n  inline C operator*(const C& c) const {\r\n    return\
    \ C(x * c.x - y * c.y, x * c.y + y * c.x);\r\n  }\r\n\r\n  inline C conj() const\
    \ { return C(x, -y); }\r\n};\r\n\r\nconst real PI = acosl(-1);\r\nint base = 1;\r\
    \nvector<C> rts = {{0, 0}, {1, 0}};\r\nvector<int> rev = {0, 1};\r\n\r\nvoid ensure_base(int\
    \ nbase) {\r\n  if (nbase <= base) return;\r\n  rev.resize(1 << nbase);\r\n  rts.resize(1\
    \ << nbase);\r\n  for (int i = 0; i < (1 << nbase); i++) {\r\n    rev[i] = (rev[i\
    \ >> 1] >> 1) + ((i & 1) << (nbase - 1));\r\n  }\r\n  while (base < nbase) {\r\
    \n    real angle = PI * 2.0 / (1 << (base + 1));\r\n    for (int i = 1 << (base\
    \ - 1); i < (1 << base); i++) {\r\n      rts[i << 1] = rts[i];\r\n      real angle_i\
    \ = angle * (2 * i + 1 - (1 << base));\r\n      rts[(i << 1) + 1] = C(cos(angle_i),\
    \ sin(angle_i));\r\n    }\r\n    ++base;\r\n  }\r\n}\r\n\r\nvoid fft(vector<C>&\
    \ a, int n) {\r\n  assert((n & (n - 1)) == 0);\r\n  int zeros = __builtin_ctz(n);\r\
    \n  ensure_base(zeros);\r\n  int shift = base - zeros;\r\n  for (int i = 0; i\
    \ < n; i++) {\r\n    if (i < (rev[i] >> shift)) { swap(a[i], a[rev[i] >> shift]);\
    \ }\r\n  }\r\n  for (int k = 1; k < n; k <<= 1) {\r\n    for (int i = 0; i < n;\
    \ i += 2 * k) {\r\n      for (int j = 0; j < k; j++) {\r\n        C z = a[i +\
    \ j + k] * rts[j + k];\r\n        a[i + j + k] = a[i + j] - z;\r\n        a[i\
    \ + j] = a[i + j] + z;\r\n      }\r\n    }\r\n  }\r\n}\r\n} // namespace CFFT\n"
  code: "namespace CFFT {\r\nusing real = double;\r\n\r\nstruct C {\r\n  real x, y;\r\
    \n\r\n  C() : x(0), y(0) {}\r\n\r\n  C(real x, real y) : x(x), y(y) {}\r\n  inline\
    \ C operator+(const C& c) const { return C(x + c.x, y + c.y); }\r\n  inline C\
    \ operator-(const C& c) const { return C(x - c.x, y - c.y); }\r\n  inline C operator*(const\
    \ C& c) const {\r\n    return C(x * c.x - y * c.y, x * c.y + y * c.x);\r\n  }\r\
    \n\r\n  inline C conj() const { return C(x, -y); }\r\n};\r\n\r\nconst real PI\
    \ = acosl(-1);\r\nint base = 1;\r\nvector<C> rts = {{0, 0}, {1, 0}};\r\nvector<int>\
    \ rev = {0, 1};\r\n\r\nvoid ensure_base(int nbase) {\r\n  if (nbase <= base) return;\r\
    \n  rev.resize(1 << nbase);\r\n  rts.resize(1 << nbase);\r\n  for (int i = 0;\
    \ i < (1 << nbase); i++) {\r\n    rev[i] = (rev[i >> 1] >> 1) + ((i & 1) << (nbase\
    \ - 1));\r\n  }\r\n  while (base < nbase) {\r\n    real angle = PI * 2.0 / (1\
    \ << (base + 1));\r\n    for (int i = 1 << (base - 1); i < (1 << base); i++) {\r\
    \n      rts[i << 1] = rts[i];\r\n      real angle_i = angle * (2 * i + 1 - (1\
    \ << base));\r\n      rts[(i << 1) + 1] = C(cos(angle_i), sin(angle_i));\r\n \
    \   }\r\n    ++base;\r\n  }\r\n}\r\n\r\nvoid fft(vector<C>& a, int n) {\r\n  assert((n\
    \ & (n - 1)) == 0);\r\n  int zeros = __builtin_ctz(n);\r\n  ensure_base(zeros);\r\
    \n  int shift = base - zeros;\r\n  for (int i = 0; i < n; i++) {\r\n    if (i\
    \ < (rev[i] >> shift)) { swap(a[i], a[rev[i] >> shift]); }\r\n  }\r\n  for (int\
    \ k = 1; k < n; k <<= 1) {\r\n    for (int i = 0; i < n; i += 2 * k) {\r\n   \
    \   for (int j = 0; j < k; j++) {\r\n        C z = a[i + j + k] * rts[j + k];\r\
    \n        a[i + j + k] = a[i + j] - z;\r\n        a[i + j] = a[i + j] + z;\r\n\
    \      }\r\n    }\r\n  }\r\n}\r\n} // namespace CFFT"
  dependsOn: []
  isVerificationFile: false
  path: poly/fft.hpp
  requiredBy: []
  timestamp: '2022-05-02 12:36:42+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: poly/fft.hpp
layout: document
redirect_from:
- /library/poly/fft.hpp
- /library/poly/fft.hpp.html
title: poly/fft.hpp
---
