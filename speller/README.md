<!-- @format -->

# English README 　[Jump to Japanese Version](#japanese)

# Speller Project

## Overview

The Speller project is a C program designed to spell-check a file using a hash table. This is about implementing efficient algorithms to optimize spell-checking speed.

### Key Features

- Implements a spell-checker for text files.
- Utilizes a hash table for efficient data handling.

### Functionality

- Spell-checks files and reports misspelled words.
- Measures performance metrics like load, check, size, unload times.

### Usage

- Compile the program: `make speller`.
- Run the program: `./speller [dictionary] text`.
- Default dictionary used if none provided.
- Example command: `./speller texts/lalaland.txt`.

### Development Process

- Optimized for actual wall-clock time, not just algorithmic efficiency.
- Memory management with no leaks.

### Testing

- Test with various texts and dictionaries.
- Compare outputs with expected results.
- Use `valgrind` to check for memory leaks.

<a name="japanese"></a>

# 日本語版の README

# スペラープロジェクト

## 概要

スペラープロジェクトは、ハッシュテーブルを使用してファイルのスペルチェックを行う C プログラムです。
このスペルチェックの速度を最適化するための効率的なアルゴリズムを実装することに焦点を当てています。

### 主な特徴

- テキストファイルのスペルチェッカーを実装。
- 効率的なデータ処理のためにハッシュテーブルを利用。

### 機能

- ファイルをスペルチェックし、誤字を報告。
- 読み込み、チェック、サイズ、アンロードの時間などのパフォーマンス指標を測定。

### 使用方法

- プログラムのコンパイル：`make speller`。
- プログラムの実行：`./speller [dictionary] text`。
- 辞書が提供されない場合はデフォルトの辞書を使用。
- 例：`./speller texts/lalaland.txt`。

### 開発プロセス

- 実際の壁時計時間の最適化、単にアルゴリズム効率のみならず。
- メモリリークのないメモリ管理。

### テスト

- 様々なテキストと辞書でテスト。
- 出力を期待される結果と比較。
- メモリリークのチェックには`valgrind`を使用。
