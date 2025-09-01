---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: my_template.hpp
    title: my_template.hpp
  - icon: ':question:'
    path: other/io.hpp
    title: other/io.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.13.7/x64/lib/python3.13/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n          \
    \         ~~~~~~~~~~~~~~~^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \  File \"/opt/hostedtoolcache/Python/3.13.7/x64/lib/python3.13/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n    ~~~~~~~~~~~~~~^^^^^^\n  File\
    \ \"/opt/hostedtoolcache/Python/3.13.7/x64/lib/python3.13/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \    ~~~~~~~~~~~^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \  File \"/opt/hostedtoolcache/Python/3.13.7/x64/lib/python3.13/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 289, in update\n    uncommented_lines = get_uncommented_code(path, iquotes=self.iquotes,\
    \ compiler=self.compiler).splitlines(keepends=True)\n                        ~~~~~~~~~~~~~~~~~~~~^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \  File \"/opt/hostedtoolcache/Python/3.13.7/x64/lib/python3.13/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 195, in get_uncommented_code\n    code = _get_uncommented_code(path.resolve(),\
    \ iquotes_options=tuple(iquotes_options), compiler=compiler)\n  File \"/opt/hostedtoolcache/Python/3.13.7/x64/lib/python3.13/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 188, in _get_uncommented_code\n    return subprocess.check_output(command)\n\
    \           ~~~~~~~~~~~~~~~~~~~~~~~^^^^^^^^^\n  File \"/opt/hostedtoolcache/Python/3.13.7/x64/lib/python3.13/subprocess.py\"\
    , line 472, in check_output\n    return run(*popenargs, stdout=PIPE, timeout=timeout,\
    \ check=True,\n           ~~~^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \               **kwargs).stdout\n               ^^^^^^^^^\n  File \"/opt/hostedtoolcache/Python/3.13.7/x64/lib/python3.13/subprocess.py\"\
    , line 577, in run\n    raise CalledProcessError(retcode, process.args,\n    \
    \                         output=stdout, stderr=stderr)\nsubprocess.CalledProcessError:\
    \ Command '['g++', '-x', 'c++', '-I', '/home/runner/work/library/library', '-fpreprocessed',\
    \ '-dD', '-E', '/home/runner/work/library/library/other/io.hpp']' returned non-zero\
    \ exit status 1.\n"
  code: "#include \"my_template.hpp\"\n#include \"other/io.hpp\"\n\nusing TestCase\
    \ = tuple<ll, ll, ll, vvc<int>>;\nusing Result = ll;\n\n// \u30C6\u30B9\u30C8\u30B1\
    \u30FC\u30B9\u306E\u5165\u529B\u3092\u8AAD\u307F\u8FBC\u3080\u95A2\u6570\nTestCase\
    \ read_input(int i) {}\n\nResult solve(const TestCase& tc) {}\n\nsigned main()\
    \ {\n  INT(T);\n\n  std::vector<TestCase> cases;\n  std::vector<std::future<Result>>\
    \ futures; // \u4E26\u5217\u51E6\u7406\u7528\u306Efuture\u30D9\u30AF\u30BF\u30FC\
    \n  std::vector<Result> results;              // \u7D50\u679C\u3092\u683C\u7D0D\
    \u3059\u308B\u30D9\u30AF\u30BF\u30FC\n\n  // \u5165\u529B\u3092\u8AAD\u307F\u8FBC\
    \u3093\u3067cases\u306B\u683C\u7D0D\n  for (int t = 0; t < T; ++t) { cases.push_back(read_input(t));\
    \ }\n\n  // \u4E26\u5217\u51E6\u7406\u306E\u5B9F\u884C\n  for (int t = 0; t <\
    \ T; ++t) {\n    // \u975E\u540C\u671F\u30BF\u30B9\u30AF\u3092\u751F\u6210\u3057\
    \u3001solve\u95A2\u6570\u3092\u4E26\u5217\u306B\u5B9F\u884C\n    futures.push_back(std::async(std::launch::async,\
    \ solve, cases[t]));\n  }\n\n  // \u5404\u975E\u540C\u671F\u30BF\u30B9\u30AF\u306E\
    \u7D50\u679C\u3092\u53D6\u5F97\n  for (int t = 0; t < T; ++t) {\n    results.push_back(futures[t].get());\
    \ // `futures[t]`\u304B\u3089\u7D50\u679C\u3092\u53D6\u5F97\u3057\u3066`results[t]`\u306B\
    \u683C\u7D0D\n  }\n\n  // \u7D50\u679C\u306E\u51FA\u529B\n  for (int t = 0; t\
    \ < T; ++t) {\n    string off = \"Case #\";\n    off += to_string(t + 1);\n  \
    \  off += \":\";\n    print(off, results[t]);\n  }\n  return 0;\n}\n"
  dependsOn:
  - my_template.hpp
  - other/io.hpp
  isVerificationFile: false
  path: other/mhc_template_directory/para.cpp
  requiredBy: []
  timestamp: '2025-09-01 20:17:42+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: other/mhc_template_directory/para.cpp
layout: document
redirect_from:
- /library/other/mhc_template_directory/para.cpp
- /library/other/mhc_template_directory/para.cpp.html
title: other/mhc_template_directory/para.cpp
---
