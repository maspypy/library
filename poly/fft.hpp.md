---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: poly/convolution_fft.hpp
    title: poly/convolution_fft.hpp
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links:
    - https://github.com/maspypy/library/blob/main/poly/fft.hpp
  bundledCode: "#line 1 \"poly/fft.hpp\"\n// Source: https://github.com/maspypy/library/blob/main/poly/fft.hpp\n\
    namespace CFFT {\nusing real = double;\n\nstruct C {\n  real x, y;\n\n  C() :\
    \ x(0), y(0) {}\n\n  C(real x, real y) : x(x), y(y) {}\n  inline C operator+(const\
    \ C& c) const { return C(x + c.x, y + c.y); }\n  inline C operator-(const C& c)\
    \ const { return C(x - c.x, y - c.y); }\n  inline C operator*(const C& c) const\
    \ {\n    return C(x * c.x - y * c.y, x * c.y + y * c.x);\n  }\n\n  inline C conj()\
    \ const { return C(x, -y); }\n};\n\nconst real PI = acosl(-1);\nint base = 1;\n\
    vector<C> rts = {{0, 0}, {1, 0}};\nvector<int> rev = {0, 1};\n\nvoid ensure_base(int\
    \ nbase) {\n  if (nbase <= base) return;\n  rev.resize(1 << nbase);\n  rts.resize(1\
    \ << nbase);\n  for (int i = 0; i < (1 << nbase); i++) {\n    rev[i] = (rev[i\
    \ >> 1] >> 1) + ((i & 1) << (nbase - 1));\n  }\n  while (base < nbase) {\n   \
    \ real angle = PI * 2.0 / (1 << (base + 1));\n    for (int i = 1 << (base - 1);\
    \ i < (1 << base); i++) {\n      rts[i << 1] = rts[i];\n      real angle_i = angle\
    \ * (2 * i + 1 - (1 << base));\n      rts[(i << 1) + 1] = C(cos(angle_i), sin(angle_i));\n\
    \    }\n    ++base;\n  }\n}\n\nvoid fft(vector<C>& a, int n) {\n  assert((n &\
    \ (n - 1)) == 0);\n  int zeros = __builtin_ctz(n);\n  ensure_base(zeros);\n  int\
    \ shift = base - zeros;\n  for (int i = 0; i < n; i++) {\n    if (i < (rev[i]\
    \ >> shift)) { swap(a[i], a[rev[i] >> shift]); }\n  }\n  for (int k = 1; k < n;\
    \ k <<= 1) {\n    for (int i = 0; i < n; i += 2 * k) {\n      for (int j = 0;\
    \ j < k; j++) {\n        C z = a[i + j + k] * rts[j + k];\n        a[i + j + k]\
    \ = a[i + j] - z;\n        a[i + j] = a[i + j] + z;\n      }\n    }\n  }\n}\n\
    } // namespace CFFT\n"
  code: "// Source: https://github.com/maspypy/library/blob/main/poly/fft.hpp\nnamespace\
    \ CFFT {\nusing real = double;\n\nstruct C {\n  real x, y;\n\n  C() : x(0), y(0)\
    \ {}\n\n  C(real x, real y) : x(x), y(y) {}\n  inline C operator+(const C& c)\
    \ const { return C(x + c.x, y + c.y); }\n  inline C operator-(const C& c) const\
    \ { return C(x - c.x, y - c.y); }\n  inline C operator*(const C& c) const {\n\
    \    return C(x * c.x - y * c.y, x * c.y + y * c.x);\n  }\n\n  inline C conj()\
    \ const { return C(x, -y); }\n};\n\nconst real PI = acosl(-1);\nint base = 1;\n\
    vector<C> rts = {{0, 0}, {1, 0}};\nvector<int> rev = {0, 1};\n\nvoid ensure_base(int\
    \ nbase) {\n  if (nbase <= base) return;\n  rev.resize(1 << nbase);\n  rts.resize(1\
    \ << nbase);\n  for (int i = 0; i < (1 << nbase); i++) {\n    rev[i] = (rev[i\
    \ >> 1] >> 1) + ((i & 1) << (nbase - 1));\n  }\n  while (base < nbase) {\n   \
    \ real angle = PI * 2.0 / (1 << (base + 1));\n    for (int i = 1 << (base - 1);\
    \ i < (1 << base); i++) {\n      rts[i << 1] = rts[i];\n      real angle_i = angle\
    \ * (2 * i + 1 - (1 << base));\n      rts[(i << 1) + 1] = C(cos(angle_i), sin(angle_i));\n\
    \    }\n    ++base;\n  }\n}\n\nvoid fft(vector<C>& a, int n) {\n  assert((n &\
    \ (n - 1)) == 0);\n  int zeros = __builtin_ctz(n);\n  ensure_base(zeros);\n  int\
    \ shift = base - zeros;\n  for (int i = 0; i < n; i++) {\n    if (i < (rev[i]\
    \ >> shift)) { swap(a[i], a[rev[i] >> shift]); }\n  }\n  for (int k = 1; k < n;\
    \ k <<= 1) {\n    for (int i = 0; i < n; i += 2 * k) {\n      for (int j = 0;\
    \ j < k; j++) {\n        C z = a[i + j + k] * rts[j + k];\n        a[i + j + k]\
    \ = a[i + j] - z;\n        a[i + j] = a[i + j] + z;\n      }\n    }\n  }\n}\n\
    } // namespace CFFT"
  dependsOn: []
  isVerificationFile: false
  path: poly/fft.hpp
  requiredBy:
  - poly/convolution_fft.hpp
  timestamp: '2026-10-15 19:54:56+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: poly/fft.hpp
layout: document
redirect_from:
- /library/poly/fft.hpp
- /library/poly/fft.hpp.html
title: poly/fft.hpp
---
