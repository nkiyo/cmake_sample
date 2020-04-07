# 開発中のコマンド操作
## アプリのビルド方法、実行方法

```bash
cd build
cmake ..
make
./CMakeSample # ビルドされたファイルを実行
```

## テストのビルド方法

```bash
cd test/build
cmake ..
make
./UnitTest # ビルドされたファイルを実行
```

## カバレッジ計測方法

## linter 実行方法

.clang-tidy にlint内容を記載の上、以下を実行する。

```bash
cd build
cmake -DCMAKE_EXPORT_COMPILE_COMMANDS=ON ..
# => 同じディレクトリに compile_commands.json ができたらOK
cd ..
clang-tidy-6.0 main.cc -p build/compile_commands.json
# 自動で修正したい場合
clang-tidy-6.0 main.cc -p build/compile_commands.json -fix
```

## formatter 実行方法

.clang-format にフォーマット定義を記載の上、以下を実行する。

```bash
clang-format-6.0 -i -style=file main.cc
```

# third party libraries

- json
- hiredis
- googletest

## googletest

```bash
cd googletest
mkdir build
cd build
cmake ..
cd lib # ここに .a ファイルができている
```

# TODO

- POST API 追加
- json
- 何らかのシリアライズライブラリ
- backward-cpp
- clang asan
- test テストクラスファイルを追加
- ALE と clang-tidy 連携
- カバレッジ計測方法を記載する
- hiredis
- .clang-tidy いい感じにする
- .clang-format いい感じにする
- コード行数をカウントする
- コンパイラどっちつかうか
- thrid party用のディレクトリに依存ライブラリをまとめる？？
- c+11
- [x] httpserver


- [x] 出力引数未使用
  - 可能。ただし、勝手にコメントアウトされるfixが動いて終わり

- [ ] 暗黙的なキャストの禁止
- [ ] 未使用のメンバ変数
- [ ] ローカル変数のスコープをギリギリまで狭くする
- [ ] 非constな参照を禁止する
- [ ] クラス宣言のフォーマット規則。メンバ変数👉メンバ関数とか、public👉private、とか。BasedOnStyle=google
- [ ] 関数引数順序。入力👉出力
- [ ] 初期化リストの使用強制



