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
    links:
    - https://github.com/maspypy/library/blob/main/poly/convolution_fft.hpp
  bundledCode: "#line 1 \"poly/convolution_fft.hpp\"\n// Source: https://github.com/maspypy/library/blob/main/poly/convolution_fft.hpp\n\
    #line 1 \"poly/fft.hpp\"\n// Source: https://github.com/maspypy/library/blob/main/poly/fft.hpp\n\
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
    } // namespace CFFT\n#line 3 \"poly/convolution_fft.hpp\"\n\ntemplate <typename\
    \ R>\nvc<double> convolution_fft(const vc<R>& a, const vc<R>& b) {\n  using C\
    \ = CFFT::C;\n  int need = (int)a.size() + (int)b.size() - 1;\n  int nbase = 1;\n\
    \  while ((1 << nbase) < need) nbase++;\n  CFFT::ensure_base(nbase);\n  int sz\
    \ = 1 << nbase;\n  vector<C> fa(sz);\n  for (int i = 0; i < sz; i++) {\n    double\
    \ x = (i < (int)a.size() ? a[i] : 0);\n    double y = (i < (int)b.size() ? b[i]\
    \ : 0);\n    fa[i] = C(x, y);\n  }\n  CFFT::fft(fa, sz);\n  C r(0, -0.25 / (sz\
    \ >> 1)), s(0, 1), t(0.5, 0);\n  for (int i = 0; i <= (sz >> 1); i++) {\n    int\
    \ j = (sz - i) & (sz - 1);\n    C z = (fa[j] * fa[j] - (fa[i] * fa[i]).conj())\
    \ * r;\n    fa[j] = (fa[i] * fa[i] - (fa[j] * fa[j]).conj()) * r;\n    fa[i] =\
    \ z;\n  }\n  for (int i = 0; i < (sz >> 1); i++) {\n    C A0 = (fa[i] + fa[i +\
    \ (sz >> 1)]) * t;\n    C A1 = (fa[i] - fa[i + (sz >> 1)]) * t * CFFT::rts[(sz\
    \ >> 1) + i];\n    fa[i] = A0 + A1 * s;\n  }\n  CFFT::fft(fa, sz >> 1);\n  vector<double>\
    \ ret(need);\n  for (int i = 0; i < need; i++) { ret[i] = (i & 1 ? fa[i >> 1].y\
    \ : fa[i >> 1].x); }\n  return ret;\n}\n"
  code: "// Source: https://github.com/maspypy/library/blob/main/poly/convolution_fft.hpp\n\
    #include \"poly/fft.hpp\"\n\ntemplate <typename R>\nvc<double> convolution_fft(const\
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
  timestamp: '2026-10-15 19:54:56+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: poly/convolution_fft.hpp
layout: document
redirect_from:
- /library/poly/convolution_fft.hpp
- /library/poly/convolution_fft.hpp.html
title: poly/convolution_fft.hpp
---
