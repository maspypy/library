# Setup

このライブラリレポジトリを前提とした競プロ環境構築メモ。

私個人が困らないようにするためのものですが、他の人も同じようにやれば同じように動作すると思います。

## インストール

```
git clone https://github.com/maspypy/library.git
sudo apt install build-essential bc clang-format
```

レポジトリを clone したディレクトリを path/to を記述する。

vscode を起動して以下の拡張機能も入れる。

- C/C++
- clang-format

## `compro.sh` の読み込み

`library/shell/compro.sh` を `source` すると、競プロ用の alias / function が使えるようになる。

```bash
source path/to/library/shell/compro.sh
```

主なコマンド：

```bash
cc    # debug compile
cc2   # sanitize compile
ccf   # fast compile
tt    # sample test
rt    # random test
aa    # ./a.out
```

毎回自動で読み込みたい場合には、`~/.bashrc` に次を追加する。例えば自分の PC に環境構築する場合を想定。

```bash
source "path/to/library/shell/compro.sh"
```

チーム共有 PC などで、一時的に自分用に使う場合には、VS Code を開くたびに `source` する。

## precompile
`precompile` を実行すると、`my_template.hpp` の事前コンパイルがされる。library clone 後に一度実行すればよい。`my_template.hpp` が更新された場合にはレポジトリを最新にしたあとで再び実行する。

