---
data:
  _extendedDependsOn:
  - icon: ':warning:'
    path: poly/fft.hpp
    title: poly/fft.hpp
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
    \ + j] = a[i + j] + z;\r\n      }\r\n    }\r\n  }\r\n}\r\n} // namespace CFFT\n\
    #line 2 \"poly/convolution_fft.hpp\"\n\ntemplate <typename R>\nvc<double> convolution_fft(const\
    \ vc<R>& a, const vc<R>& b) {\n  using C = CFFT::C;\n  int need = (int)a.size()\
    \ + (int)b.size() - 1;\n  int nbase = 1;\n  while ((1 << nbase) < need) nbase++;\n\
    \  CFFT::ensure_base(nbase);\n  int sz = 1 << nbase;\n  vector<C> fa(sz);\n  for\
    \ (int i = 0; i < sz; i++) {\n    double x = (i < (int)a.size() ? a[i] : 0);\n\
    \    double y = (i < (int)b.size() ? b[i] : 0);\n    fa[i] = C(x, y);\n  }\n \
    \ CFFT::fft(fa, sz);\n  C r(0, -0.25 / (sz >> 1)), s(0, 1), t(0.5, 0);\n  for\
    \ (int i = 0; i <= (sz >> 1); i++) {\n    int j = (sz - i) & (sz - 1);\n    C\
    \ z = (fa[j] * fa[j] - (fa[i] * fa[i]).conj()) * r;\n    fa[j] = (fa[i] * fa[i]\
    \ - (fa[j] * fa[j]).conj()) * r;\n    fa[i] = z;\n  }\n  for (int i = 0; i < (sz\
    \ >> 1); i++) {\n    C A0 = (fa[i] + fa[i + (sz >> 1)]) * t;\n    C A1 = (fa[i]\
    \ - fa[i + (sz >> 1)]) * t * CFFT::rts[(sz >> 1) + i];\n    fa[i] = A0 + A1 *\
    \ s;\n  }\n  CFFT::fft(fa, sz >> 1);\n  vector<double> ret(need);\n  for (int\
    \ i = 0; i < need; i++) { ret[i] = (i & 1 ? fa[i >> 1].y : fa[i >> 1].x); }\n\
    \  return ret;\n}\n"
  code: "#include \"poly/fft.hpp\"\n\ntemplate <typename R>\nvc<double> convolution_fft(const\
    \ vc<R>& a, const vc<R>& b) {\n  using C = CFFT::C;\n  int need = (int)a.size()\
    \ + (int)b.size() - 1;\n  int nbase = 1;\n  while ((1 << nbase) < need) nbase++;\n\
    \  CFFT::ensure_base(nbase);\n  int sz = 1 << nbase;\n  vector<C> fa(sz);\n  for\
    \ (int i = 0; i < sz; i++) {\n    double x = (i < (int)a.size() ? a[i] : 0);\n\
    \    double y = (i < (int)b.size() ? b[i] : 0);\n    fa[i] = C(x, y);\n  }\n \
    \ CFFT::fft(fa, sz);\n  C r(0, -0.25 / (sz >> 1)), s(0, 1), t(0.5, 0);\n  for\
    \ (int i = 0; i <= (sz >> 1); i++) {\n    int j = (sz - i) & (sz - 1);\n    C\
    \ z = (fa[j] * fa[j] - (fa[i] * fa[i]).conj()) * r;\n    fa[j] = (fa[i] * fa[i]\
    \ - (fa[j] * fa[j]).conj()) * r;\n    fa[i] = z;\n  }\n  for (int i = 0; i < (sz\
    \ >> 1); i++) {\n    C A0 = (fa[i] + fa[i + (sz >> 1)]) * t;\n    C A1 = (fa[i]\
    \ - fa[i + (sz >> 1)]) * t * CFFT::rts[(sz >> 1) + i];\n    fa[i] = A0 + A1 *\
    \ s;\n  }\n  CFFT::fft(fa, sz >> 1);\n  vector<double> ret(need);\n  for (int\
    \ i = 0; i < need; i++) { ret[i] = (i & 1 ? fa[i >> 1].y : fa[i >> 1].x); }\n\
    \  return ret;\n}\n"
  dependsOn:
  - poly/fft.hpp
  isVerificationFile: false
  path: poly/convolution_fft.hpp
  requiredBy: []
  timestamp: '2024-10-25 01:17:46+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: poly/convolution_fft.hpp
layout: document
redirect_from:
- /library/poly/convolution_fft.hpp
- /library/poly/convolution_fft.hpp.html
title: poly/convolution_fft.hpp
---
