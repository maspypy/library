---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: py
  _verificationStatusIcon: ':warning:'
  attributes:
    links:
    - https://example.invalid/old.hpp\n#pragma
    - https://github.com/maspypy/library/blob/main/a.hpp\n/*
    - https://github.com/maspypy/library/blob/main/dir/a%20b.hpp\n"))
    - https://github.com/maspypy/library/blob/main/dir/a%20b.hpp\n#pragma
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.12.15/x64/lib/python3.12/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n          \
    \         ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \  File \"/opt/hostedtoolcache/Python/3.12.15/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/python.py\"\
    , line 96, in bundle\n    raise NotImplementedError\nNotImplementedError\n"
  code: "#!/usr/bin/env python3\n\"\"\"Regression tests for scripts/update_source_urls.py.\"\
    \"\"\n\nimport importlib.util\nimport subprocess\nimport tempfile\nimport unittest\n\
    from pathlib import Path\n\n\nSCRIPT = Path(__file__).with_name(\"update_source_urls.py\"\
    )\nspec = importlib.util.spec_from_file_location(\"update_source_urls\", SCRIPT)\n\
    module = importlib.util.module_from_spec(spec)\nassert spec.loader is not None\n\
    spec.loader.exec_module(module)\n\n\nclass UpdateSourceUrlsTest(unittest.TestCase):\n\
    \    def setUp(self):\n        self.temporary_directory = tempfile.TemporaryDirectory()\n\
    \        self.root = Path(self.temporary_directory.name)\n        subprocess.run([\"\
    git\", \"init\", \"-q\", str(self.root)], check=True)\n\n    def tearDown(self):\n\
    \        self.temporary_directory.cleanup()\n\n    def write_and_track(self, relative_path:\
    \ str, content: bytes) -> Path:\n        path = self.root / relative_path\n  \
    \      path.parent.mkdir(parents=True, exist_ok=True)\n        path.write_bytes(content)\n\
    \        subprocess.run([\"git\", \"-C\", str(self.root), \"add\", relative_path],\
    \ check=True)\n        return path\n\n    def test_insert_repair_and_idempotence(self):\n\
    \        header = self.write_and_track(\"dir/a b.hpp\", b\"#pragma once\\nint\
    \ x;\\n\")\n        self.assertEqual(module.update(self.root, check=True), 1)\n\
    \        self.assertEqual(module.update(self.root, check=False), 0)\n        expected\
    \ = b\"// Source: https://github.com/maspypy/library/blob/main/dir/a%20b.hpp\\\
    n#pragma once\\nint x;\\n\"\n        self.assertEqual(header.read_bytes(), expected)\n\
    \        self.assertEqual(module.update(self.root, check=True), 0)\n\n       \
    \ header.write_bytes(b\"// Source: https://example.invalid/old.hpp\\n#pragma once\\\
    n\")\n        self.assertEqual(module.update(self.root, check=False), 0)\n   \
    \     self.assertTrue(header.read_bytes().startswith(b\"// Source: https://github.com/maspypy/library/blob/main/dir/a%20b.hpp\\\
    n\"))\n\n    def test_moves_source_line_before_existing_comment_and_normalizes_crlf(self):\n\
    \        header = self.write_and_track(\"a.hpp\", b\"/* note */\\r\\n// Source:\
    \ stale\\r\\nint x;\\r\\n\")\n        self.assertEqual(module.update(self.root,\
    \ check=False), 0)\n        self.assertEqual(\n            header.read_bytes(),\n\
    \            b\"// Source: https://github.com/maspypy/library/blob/main/a.hpp\\\
    n/* note */\\nint x;\\n\",\n        )\n\n\nif __name__ == \"__main__\":\n    unittest.main()\n"
  dependsOn: []
  isVerificationFile: false
  path: scripts/test_update_source_urls.py
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: scripts/test_update_source_urls.py
layout: document
redirect_from:
- /library/scripts/test_update_source_urls.py
- /library/scripts/test_update_source_urls.py.html
title: scripts/test_update_source_urls.py
---
