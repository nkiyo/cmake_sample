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
```

## カバレッジ計測方法

## linter 実行方法

## formatter 実行方法

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

- アプリのビルド方法、実行方法を記載する
- テストのビルド方法を記載する
- カバレッジ計測方法を記載する
- formatter を実行する
- linter を実行する
- コード行数をカウントする
- コンパイラどっちつかうか
- thrid party用のディレクトリに依存ライブラリをまとめる？？
- c+11
- json
- hiredis
