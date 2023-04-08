ご自由にどうぞ。
- 破壊的な設計変更もよくしているので注意してください。
- バグってたらごめん＋教えてくれると助かります。
- 他の人が使いやすい想定で作っていないので、使いにくい可能性が割とあります。
- 例えば、単体でコピペしてもダメで、テンプレの一部を上手く拾ってこないと動かないことはよくあります。

<details>
    <summary>こういうライブラリまとめの作り方</summary>
    
<ul>
    <li>「online-judge-tools/verification-helper」を使う。</li>
    <li> https://github.com/online-judge-tools/verification-helper/blob/master/README.ja.md を見て頑張ります。</li>
    <li>公開テストケースをダウンロードして、出力が正しいかを判定してくれる</li>
    <li>Library Checker の問題だと特殊ジャッジも対応可</li>
    <li>Library Checker, yukicoder はかなり安定して使える</li>
    <li>AOJ の問題はときどき上手くダウンロードできないようだが割と使える</li>
    <li>AtCoder の問題は、dropbox (https://atcoder.jp/posts/20) にあれば割とできる？</li>
</ul>

困ったら聞いてもらえると分かる範囲で助けます（が、分かる範囲があまり大きくないです）
</details>

<details>
    <summary>雑多なメモ</summary>

<ul>
    <li>一度なんか壊れたのでコピーして別レポジトリとして再生した。パソコンわからない。</li>
    <li>workflow：oj の導入方法の解説に従った場合、不要なものまでいろいろインストールするが、結構減らせる。他の人の verify.yml を見ながら調整するとよい。</li>
    <li> https://github.com/maspypy/library/blob/main/.github/workflows/verify.yml</li>
    <li>github の使い方：私も無知よりですが、add, commit, pull, push だけ使えるようになればあまり困らないっぽいです。</li>
    <li>github actions による 自動verify：oj 側か github 側どちらの意図か知らないが、1 push あたり 10 分くらいで verify が止まる。empty commit を push するなどして続きを動かすようにしている。</li>
    <li> ~/.bashrc に alias empty_c='git commit --allow-empty -m "empty";git push' と書いている</li>
    <li>atcoder の dropbox 内のものを verify に使う場合には、define PROBLEM の URL 指定を適当にいじると上手くいくことがあるっぽい？</li>
    <li>abcxxx_h → abcxxx_Ex</li>
    <li>AGCxxx_x → agcxxx_x</li>
    <li>atcoder：一度上手くいったものがまた落ちることがある？こまめに DROPBOX_TOKEN を設定しなおす必要があるかも？</li>
    <li>誤差ジャッジ：#define ERROR を指定するとできる</li>
    <li>「ココ」の文章：https://github.com/maspypy/library/blob/main/.verify-helper/docs/index.md に書く</li>
</ul>

</details>

<details>
    <summary>同じスタイルで整理された人のライブラリ（個人的によく参考にするやつもの抜粋）</summary>
    
<ul>
    <li>[Nyaan さん](https://nyaannyaan.github.io/library/)</li>
    <li>[ei1333 さん](https://ei1333.github.io/library/)</li>
    <li>[suisen さん](https://suisen-cp.github.io/cp-library-cpp/)</li>
    <li>[hitonanode さん](https://hitonanode.github.io/cplib-cpp/)</li>
    <li>[beet さん](https://beet-aizu.github.io/library/)</li>
</ul>
</details>
