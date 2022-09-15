ご自由にどうぞ。
- 大部分が 2022 年から作り始めたやつです。それほど使い込まれていないし、破壊的な設計変更もよくしているので注意してください。
- バグってたらごめん＋教えてくれると助かります。
- 他の人が使いやすい想定で作っていないので、使いにくい可能性が割とあります。
- 例えば、単体でコピペしてもダメで、テンプレの一部を上手く拾ってこないと動かないはずです。

## こういうライブラリまとめの作り方
- online-judge-tools/verification-helper
    - 公開テストケースをダウンロードして、出力が正しいかを判定してくれる
    - Library Checker の問題だと特殊ジャッジも対応可
    - Library Checker, yukicoder はかなり安定して使える
    - AOJ の問題はときどき上手くダウンロードできないようだが割と使える
    - AtCoder の問題は、dropbox (https://atcoder.jp/posts/20) にあれば割とできる？
- [ドキュメント](https://github.com/online-judge-tools/verification-helper/blob/master/README.ja.md)を見て頑張る
- ちょっと導入が難しかったけど、個人的には導入してめちゃくちゃ助っている
- 困ったら聞いてもらえると分かる範囲で助けます（が、分かる範囲があまり大きくないです）

## 雑多なメモ
- 一度なんか壊れたのでコピーして別レポジトリとして再生した。パソコンわからない。
- workflow：oj の導入方法の解説に従った場合、不要なものまでいろいろインストールする。
    - 結構減らせる。他の人の verify.yml を見ながら調整。
    - [https://github.com/maspypy/library/blob/main/.github/workflows/verify.yml](https://github.com/maspypy/library/blob/main/.github/workflows/verify.yml)
- github の使い方：私も無知よりですが、add, commit, pull, push だけ使えるようになればあまり困らないっぽいです。
    - ブラウザ上でもファイル編集できることを最近知った。
- github actions による 自動verify
    - oj 側か github 側どちらの意図か知らないが、1 push あたり 10 分くらいで verify が止まる。
    - empty commit （`git commit --allow-empty`）を push するなどして続きを動かすようにしている。
        - ~/.bashrc に `alias empty_c='git commit --allow-empty -m "empty";git push'` と書いている
- atcoder の dropbox 内のものを verify に使う場合には、URL を適当にいじると上手くいくことがあるっぽい？
    - abcxxx_h → abcxxx_Ex
    - AGCxxx_x → agcxxx_x
    - 当然、dropbox に上がるまでは何もできない。
- atcoder
    - 一度上手くいったものがまた落ちることがある？エラーログではログインしてみたいなことを言われてそう。うーん。
    - なんか DROPBOX_TOKEN をもう一回設定しなおしたらいけた
    - atcoder の問題を追加するたびにやる必要あり？
- 誤差ジャッジ：#define ERROR を指定するとできる
- 「ココ」の文章：[.verify-helper/docs/index.md](https://github.com/maspypy/library/blob/main/.verify-helper/docs/index.md) に書く

## 同じスタイルで整理された人のライブラリ（個人的によく参考にするやつもの抜粋）
- [Nyaan さん](https://nyaannyaan.github.io/library/)
- [ei1333 さん](https://ei1333.github.io/library/)
- [suisen さん](https://suisen-cp.github.io/cp-library-cpp/)
- [hitonanode さん](https://hitonanode.github.io/cplib-cpp/)
- [beet さん](https://beet-aizu.github.io/library/)
