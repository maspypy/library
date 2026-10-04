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
    - https://codeforces.com/contest/815/problem/D
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.12.14/x64/lib/python3.12/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n          \
    \         ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \  File \"/opt/hostedtoolcache/Python/3.12.14/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.12.14/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.12.14/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.12.14/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \                ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n \
    \ File \"/opt/hostedtoolcache/Python/3.12.14/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: other/bit.hpp:\
    \ line -1: no such header\n"
  code: "#include \"ds/incremental_rectangle_union.hpp\"\n\n// [0,a] x [0,b] x [0,c]\
    \ \u306E\u548C\u96C6\u5408\u306E\u4F53\u7A4D\n// https://codeforces.com/contest/815/problem/D\n\
    template <typename XYZ, typename T, bool SMALL_X>\nT cuboid_union_volume(vc<tuple<XYZ,\
    \ XYZ, XYZ>> dat) {\n  if constexpr (SMALL_X) {\n    int mx_x = 0, mx_z = 0;\n\
    \    for (auto& [x, y, z]: dat) chmax(mx_x, x), chmax(mx_z, z);\n    vc<int> ptr(mx_z\
    \ + 1);\n    for (auto& [x, y, z]: dat) ptr[z]++;\n    ptr = cumsum<int>(ptr);\n\
    \    vc<pair<int, int>> rect(len(dat));\n    for (auto& [x, y, z]: dat) { rect[ptr[z]++]\
    \ = {x, y}; }\n    T vol = 0;\n    Incremental_Rectangle_Union<XYZ, T, true> I(mx_x);\n\
    \    FOR_R(z, 1, mx_z + 1) {\n      FOR(i, ptr[z - 1], ptr[z]) {\n        auto\
    \ [a, b] = rect[i];\n        I.add(a, b);\n      }\n      vol += I.area;\n   \
    \ }\n    return vol;\n  } else {\n    sort(all(dat),\n         [&](auto& a, auto&\
    \ b) -> bool { return get<2>(a) > get<2>(b); });\n    XYZ z = infty<XYZ>;\n  \
    \  T vol = 0, area = 0;\n    Incremental_Rectangle_Union<XYZ, T, false> I;\n \
    \   for (auto& [a, b, c]: dat) {\n      vol += T(z - c) * area, area = I.add(a,\
    \ b), z = c;\n    }\n    vol += z * I.area;\n    return vol;\n  }\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: other/cuboid_union_volume.hpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: other/cuboid_union_volume.hpp
layout: document
redirect_from:
- /library/other/cuboid_union_volume.hpp
- /library/other/cuboid_union_volume.hpp.html
title: other/cuboid_union_volume.hpp
---
