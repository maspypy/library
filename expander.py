import sys
import os
import re

SCRIPT_DIR = os.path.dirname(os.path.abspath(__file__))
LIBRARY_DIR = SCRIPT_DIR

INCLUDE_PATHS = [
    '.',
    LIBRARY_DIR,
]

extra_paths = os.environ.get('MASPY_EXPANDER_INCLUDE_PATHS')
if extra_paths:
    INCLUDE_PATHS.extend(extra_paths.split(os.pathsep))

visited = set()
keep_source_url = os.environ.get('MASPY_KEEP_SOURCE_URL') == '1'


def resolve_include(header, including_file):
    for path in INCLUDE_PATHS:
        full_path = os.path.join(path, header)
        if os.path.isfile(full_path):
            return os.path.abspath(full_path)

    # Fall back to the directory of the file containing the #include.
    # Search INCLUDE_PATHS first to preserve existing behavior.
    full_path = os.path.join(os.path.dirname(including_file), header)
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
    next_output_line = None

    with open(path) as f:
        for i, line in enumerate(f, start=1):
            if line.strip() == "#pragma once":
                continue
            if not keep_source_url and line.startswith('// Source: '):
                # The source URL was physical line i.  The location directive
                # for the next emitted line is produced lazily below.
                continue

            m = re.match(r'#\s*include\s*"([^"]+)"', line)
            if m:
                header = m.group(1)
                resolved = resolve_include(header, abs_path)
                if resolved:
                    if resolved not in visited:
                        expand_file(resolved, header, display_name, i + 1)
                    next_output_line = None
                else:
                    if next_output_line != i:
                        print(f'#line {i} "{display_name}"')
                    print(f'// [warning] include not found: {header}')
                    next_output_line = i + 1
            elif re.match(r'#\s*include\s*<[^>]+>', line):
                if next_output_line != i:
                    print(f'#line {i} "{display_name}"')
                print(line, end='')
                next_output_line = i + 1
            else:
                if next_output_line != i:
                    print(f'#line {i} "{display_name}"')
                print(line, end='')
                next_output_line = i + 1

    print(f'// END: {display_name}')


if __name__ == '__main__':
    if len(sys.argv) != 2:
        print("Usage: python3 expander.py main.cpp > singlefile.cpp")
        sys.exit(1)

    expand_file(sys.argv[1])
