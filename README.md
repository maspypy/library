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

`expander.py` omits source URL headers by default; the existing
`my_template.hpp` library attribution remains. Set `MASPY_KEEP_SOURCE_URL=1`
to retain source URL headers in expanded output.
