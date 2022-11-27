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
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.11.0/x64/lib/python3.11/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n          \
    \         ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \  File \"/opt/hostedtoolcache/Python/3.11.0/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.11.0/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \                ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n \
    \ File \"/opt/hostedtoolcache/Python/3.11.0/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: alg/group/mul.hpp:\
    \ line -1: no such header\n"
  code: "#include \"alg/group/mul.hpp\"\n\n// \u5B9A\u6570\u3092\u3079\u304D\u4E57\
    \u3059\u308B\u30AF\u30A8\u30EA\u3002 B \u4E57\u5206\u305A\u3064\u524D\u8A08\u7B97\
    \u3002\ntemplate <typename Mono, int B = 1024>\nstruct PowerQuery {\n  using X\
    \ = typename Mono::value_type;\n  vvc<X> dat;\n\n  PowerQuery(X a) { dat.eb(make_pow(a));\
    \ }\n\n  X operator()(ll n) {\n    X res = Mono::unit();\n    int k = 0;\n   \
    \ while (n) {\n      int r = n % B;\n      n /= B;\n      if (len(dat) == k) {\
    \ dat.eb(make_pow(dat[k - 1].back())); }\n      res = Mono::op(res, dat[k][r]);\n\
    \      ++k;\n    }\n    return res;\n  }\n\n  X operator[](ll n) { return (*this)(n);\
    \ }\n\nprivate:\n  vc<X> make_pow(X a) {\n    vc<X> res = {Mono::unit()};\n  \
    \  FOR(B) { res.eb(Mono::op(res.back(), a)); }\n    return res;\n  }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: ds/query/powerquery.hpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: ds/query/powerquery.hpp
layout: document
redirect_from:
- /library/ds/query/powerquery.hpp
- /library/ds/query/powerquery.hpp.html
title: ds/query/powerquery.hpp
---
