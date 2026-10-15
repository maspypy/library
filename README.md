# library
https://maspypy.github.io/library/

## Source URL headers

Every tracked `.hpp` begins with its canonical GitHub URL. Update headers after
adding or moving a header with:

```sh
python scripts/update_source_urls.py
```

To reject missing or stale headers without modifying files, use:

```sh
python scripts/update_source_urls.py --check
```

Enable the included local pre-commit check once per clone:

```sh
git config core.hooksPath .githooks
```

`expander.py` preserves source URL headers by default. Set
`MASPY_STRIP_SOURCE_URL=1` to omit only those lines from expanded output; the
existing `my_template.hpp` library attribution remains.
