import sys
import os
import re

INCLUDE_PATHS = ['.', os.path.expanduser('~/compro/library')]
visited = set()

def resolve_include(header):
    for path in INCLUDE_PATHS:
        full_path = os.path.join(path, header)
        if os.path.isfile(full_path):
            return os.path.abspath(full_path)
    return None

def expand_file(path, display_name=None, caller_file=None, caller_line=None):
    abs_path = os.path.abspath(path)
    if abs_path in visited:
        return
    visited.add(abs_path)

    if display_name is None:
        display_name = os.path.basename(path)

    print(f'// BEGIN: {display_name}')
    print(f'#line 1 "{display_name}"')  # ファイルの冒頭で `#line` を入れる

    with open(path) as f:
        for i, line in enumerate(f, start=1):
            if line.strip() == "#pragma once":
                continue

            m = re.match(r'#\s*include\s*"([^"]+)"', line)
            if m:
                header = m.group(1)
                resolved = resolve_include(header)
                if resolved:
                    expand_file(resolved, header, display_name, i + 1)
                    print(f'#line {i + 1} "{display_name}"')  # ← 呼び出し元に戻る位置
                else:
                    print(f'// [warning] include not found: {header}')
            elif re.match(r'#\s*include\s*<[^>]+>', line):
                print(line, end='')
            else:
                print(line, end='')

    print(f'// END: {display_name}')

if __name__ == '__main__':
    if len(sys.argv) != 2:
        print("Usage: python3 expander.py main.cpp > singlefile.cpp")
        sys.exit(1)

    expand_file(sys.argv[1])
