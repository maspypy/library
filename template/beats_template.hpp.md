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
  bundledCode: "#line 1 \"template/beats_template.hpp\"\n// template/beats_template.hpp\n\
    struct Beats {\n  struct MonoX {\n    struct X {\n      bool fail;\n      int\
    \ size;\n    };\n    using value_type = X;\n    static X op(X x, X y) {\n    \
    \  if (!x.size) return y;\n      if (!y.size) return x;\n      // fail \u306F\
    \ 0 \u306E\u307E\u307E\u3002\n      return X({});\n    }\n    static constexpr\
    \ X id() {\n      // size \u3092 0 \u306B\u3057\u3066\u304A\u3051\u3070\u306A\u3093\
    \u3067\u3082\u3088\u3044\n      return X({});\n    }\n    static constexpr bool\
    \ commute = ;\n  };\n\n  struct MonoA {\n    // \u4F5C\u7528\u30E2\u30CE\u30A4\
    \u30C9\u306F\u7279\u306B\u6C17\u306B\u305B\u305A\u5B9F\u88C5\n    using value_type\
    \ = ;\n    using X = value_type;\n    static X op(X x, X y) {}\n    static constexpr\
    \ X id() {}\n    static constexpr bool commute = ;\n  };\n\n  using MX = MonoX;\n\
    \  using MA = MonoA;\n  using X_structure = MX;\n  using A_structure = MA;\n \
    \ using X = typename MX::value_type;\n  using A = typename MA::value_type;\n\n\
    \  template <typename T>\n  static X from_element(T a) {\n    // fail = 0, size\
    \ = 1\n    return X({});\n  }\n\n  static const X act(X x, const A& a) {\n   \
    \ assert(!x.fail);\n    // \u66F4\u65B0\u306B\u5931\u6557\u3057\u305F\u3089\u3001\
    x.fail = 1 \u3068\u3057\u3066 return x \u3059\u308B\u3053\u3068\n  }\n};\n"
  code: "// template/beats_template.hpp\nstruct Beats {\n  struct MonoX {\n    struct\
    \ X {\n      bool fail;\n      int size;\n    };\n    using value_type = X;\n\
    \    static X op(X x, X y) {\n      if (!x.size) return y;\n      if (!y.size)\
    \ return x;\n      // fail \u306F 0 \u306E\u307E\u307E\u3002\n      return X({});\n\
    \    }\n    static constexpr X id() {\n      // size \u3092 0 \u306B\u3057\u3066\
    \u304A\u3051\u3070\u306A\u3093\u3067\u3082\u3088\u3044\n      return X({});\n\
    \    }\n    static constexpr bool commute = ;\n  };\n\n  struct MonoA {\n    //\
    \ \u4F5C\u7528\u30E2\u30CE\u30A4\u30C9\u306F\u7279\u306B\u6C17\u306B\u305B\u305A\
    \u5B9F\u88C5\n    using value_type = ;\n    using X = value_type;\n    static\
    \ X op(X x, X y) {}\n    static constexpr X id() {}\n    static constexpr bool\
    \ commute = ;\n  };\n\n  using MX = MonoX;\n  using MA = MonoA;\n  using X_structure\
    \ = MX;\n  using A_structure = MA;\n  using X = typename MX::value_type;\n  using\
    \ A = typename MA::value_type;\n\n  template <typename T>\n  static X from_element(T\
    \ a) {\n    // fail = 0, size = 1\n    return X({});\n  }\n\n  static const X\
    \ act(X x, const A& a) {\n    assert(!x.fail);\n    // \u66F4\u65B0\u306B\u5931\
    \u6557\u3057\u305F\u3089\u3001x.fail = 1 \u3068\u3057\u3066 return x \u3059\u308B\
    \u3053\u3068\n  }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: template/beats_template.hpp
  requiredBy: []
  timestamp: '2026-08-30 21:09:36+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: template/beats_template.hpp
layout: document
redirect_from:
- /library/template/beats_template.hpp
- /library/template/beats_template.hpp.html
title: template/beats_template.hpp
---
