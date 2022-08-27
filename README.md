# library
https://maspypy.github.io/library/

ご自由にどうぞ

----
導入メモ

- 一度なんか壊れたのでコピーして別レポジトリとして再生した。パソコンわからない。
- workflow：oj の導入方法の解説に従った場合、不要なものまでいろいろインストールする。結構減らせる。他の人の verify.yml を見ながら調整。
- github：add, commit, pull, push だけ使えるようになれば困らなさそう。ブラウザ上でもファイル編集できる。
- actions：oj 側か github 側どちらの意図か知らないが、1 push あたり 10 分くらいで verify が止まる。
empty commit （git commit --allow-empty）を push することで再挑戦できる。
- atcoder の dropbox 内のものを verify に使う場合には、URL ではなく dropbox 内のフォルダ名に合わせると上手くいくことがある （abcxxx_h → abcxxx_Ex など）
- atcoder の verify：一度上手くいったものがまた落ちることがある？ログインしてみたいなことを言われてそう。うーん。
→ なんか DROPBOX_TOKEN をもう一回設定しなおしたらいけた？
- 誤差ジャッジ：#define ERROR を指定するとできる！
