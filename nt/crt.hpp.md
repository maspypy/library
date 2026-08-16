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
    \                ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n \
    \ File \"/opt/hostedtoolcache/Python/3.12.13/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: nt/primetest.hpp:\
    \ line -1: no such header\n"
  code: "#include \"mod/mod_inv.hpp\"\n#include \"nt/coprime_factorization.hpp\"\n\
    #include \"nt/factor.hpp\"\n#include \"mod/barrett.hpp\"\n\n// \u975E\u8CA0\u6700\
    \u5C0F\u89E3\u3092 mod new_mod \u3067\u8FD4\u3059 (garner), \u306A\u3051\u308C\
    \u3070 -1.\ntemplate <typename T>\ni128 CRT(vc<T> vals, vc<T> mods, ll new_mod\
    \ = -1, bool coprime = false) {\n  int n = len(vals);\n  FOR(i, n) { vals[i] =\
    \ ((vals[i] %= mods[i]) >= 0 ? vals[i] : vals[i] + mods[i]); }\n\n  bool ng =\
    \ 0;\n  auto reduction_by_factor = [&]() -> void {\n    unordered_map<T, pair<T,\
    \ T>> MP;\n    FOR(i, n) {\n      for (auto&& [p, e]: factor(mods[i])) {\n   \
    \     T mod = 1;\n        FOR(e) mod *= p;\n        T val = vals[i] % mod;\n \
    \       if (!MP.count(p)) {\n          MP[p] = {mod, val % mod};\n          continue;\n\
    \        }\n        auto& [mod1, val1] = MP[p];\n        if (mod > mod1) swap(mod,\
    \ mod1), swap(val, val1);\n        if (val1 % mod != val) {\n          ng = 1;\n\
    \          return;\n        }\n      }\n    }\n    mods.clear(), vals.clear();\n\
    \    for (auto&& [p, x]: MP) {\n      auto [mod, val] = x;\n      mods.eb(mod),\
    \ vals.eb(val);\n    }\n    n = len(vals);\n  };\n  auto reduction_by_coprime_factor\
    \ = [&]() -> void {\n    auto [basis, pfs] = coprime_factorization<T>(mods);\n\
    \    int k = len(basis);\n    vc<pair<T, T>> dat(k, {1, 0});\n    FOR(i, n) {\n\
    \      for (auto&& [pid, exp]: pfs[i]) {\n        T mod = 1;\n        FOR(exp)\
    \ mod *= basis[pid];\n        T val = vals[i] % mod;\n        auto& [mod1, val1]\
    \ = dat[pid];\n        if (mod > mod1) swap(mod, mod1), swap(val, val1);\n   \
    \     if (val1 % mod != val) {\n          ng = 1;\n          return;\n       \
    \ }\n      }\n    }\n    mods.clear(), vals.clear();\n    for (auto&& [mod, val]:\
    \ dat) { mods.eb(mod), vals.eb(val); }\n    n = len(vals);\n  };\n  if (!coprime)\
    \ { (n <= 10 ? reduction_by_coprime_factor() : reduction_by_factor()); }\n\n \
    \ if (ng) return -1;\n  if (n == 0) return 0;\n\n  vc<ll> cfs(n);\n  if (MAX(mods)\
    \ < (1LL << 31)) {\n    FOR(i, n) {\n      Barrett bt(mods[i]);\n      ll a =\
    \ vals[i], prod = 1;\n      FOR(j, i) {\n        a = bt.modulo(a + cfs[j] * (mods[i]\
    \ - prod));\n        prod = bt.mul(prod, mods[j]);\n      }\n      cfs[i] = bt.mul(mod_inv(prod,\
    \ mods[i]), a);\n    }\n  } else {\n    FOR(i, n) {\n      ll a = vals[i], prod\
    \ = 1;\n      FOR(j, i) {\n        a = (a + i128(cfs[j]) * (mods[i] - prod)) %\
    \ mods[i];\n        prod = i128(prod) * mods[j] % mods[i];\n      }\n      cfs[i]\
    \ = mod_inv(prod, mods[i]) * i128(a) % mods[i];\n    }\n  }\n  i128 ret = 0, prod\
    \ = 1;\n  FOR(i, n) {\n    ret += prod * cfs[i], prod *= mods[i];\n    if (new_mod\
    \ != -1) { ret %= new_mod, prod %= new_mod; }\n  }\n  return ret;\n}"
  dependsOn: []
  isVerificationFile: false
  path: nt/crt.hpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: nt/crt.hpp
layout: document
redirect_from:
- /library/nt/crt.hpp
- /library/nt/crt.hpp.html
title: nt/crt.hpp
---
