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
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.13.3/x64/lib/python3.13/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n          \
    \         ~~~~~~~~~~~~~~~^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \  File \"/opt/hostedtoolcache/Python/3.13.3/x64/lib/python3.13/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n    ~~~~~~~~~~~~~~^^^^^^\n  File\
    \ \"/opt/hostedtoolcache/Python/3.13.3/x64/lib/python3.13/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \                ~~~~~~~~~~~~~^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n \
    \ File \"/opt/hostedtoolcache/Python/3.13.3/x64/lib/python3.13/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: setfunc/online/oniline_subset_zeta.hpp:\
    \ line -1: no such header\n"
  code: "#include \"setfunc/online/oniline_subset_zeta.hpp\"\n#include \"setfunc/online/oniline_subset_mobius.hpp\"\
    \n\ntemplate <typename T>\nstruct Online_Or_Convolution {\n  Online_Subset_Zeta<T>\
    \ X1, X2;\n  Online_Subset_Mobius<T> Y;\n  Online_Or_Convolution(int LOG) : X1(LOG),\
    \ X2(LOG), Y(LOG) {}\n  // set a[i] and b[i], return conv(a,b)[i]\n  T set(int\
    \ i, T ai, T bi) { return Y.set(i, X1.set(i, ai) * X2.set(i, bi)); }\n  // assume\
    \ a[i],b[i], return zeta(a)[i]. not increment the pointer.\n  T assume(int i,\
    \ T ai, T bi) { return Y.assume(i, X1.assume(i, ai) * X2.assume(i, bi)); }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: setfunc/online/online_or_convolution.hpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: setfunc/online/online_or_convolution.hpp
layout: document
redirect_from:
- /library/setfunc/online/online_or_convolution.hpp
- /library/setfunc/online/online_or_convolution.hpp.html
title: setfunc/online/online_or_convolution.hpp
---
