<!-- @format -->

# English README 　[Jump to Japanese Version](#japanese)

# Recover Project

## Overview

The Recover project is a C program designed to recover JPEG images from a forensic image of a memory card. It involves reading and processing raw binary data to identify and extract JPEG files.

### Key Features

- Recovers JPEG files from a raw memory card image (`card.raw`).
- Identifies JPEGs based on their unique byte signatures.
- Efficiently processes data in blocks, consistent with memory card's FAT file system.

### Functionality

- Iterates over the forensic image to locate JPEG signatures.
- Writes each recovered JPEG to a separate file in the format `###.jpg`.
- Handles memory efficiently to ensure no leaks.

### Usage

- Compile the program: `make recover`.
- Run the program: `./recover card.raw`.

### Development Process

- Ensure the program accepts the name of the forensic image as a command-line argument.
- Handle file I/O errors gracefully.
- Manage memory efficiently.

### Testing

- Test the program with provided `card.raw`.
- Check the correctness of recovered JPEG files visually.

<a name="japanese"></a>

# 日本語版の README

# リカバープロジェクト

## 概要

リカバープロジェクトは、メモリーカードのフォレンジックイメージから JPEG 画像を回復するために設計された C 言語のプログラムです。生のバイナリーデータを読み取り、処理して JPEG ファイルを識別し、抽出する作業を含みます。

### 主な特徴

- 生のメモリーカードイメージ（`card.raw`）から JPEG ファイルを回復。
- ユニークなバイトシグネチャに基づいて JPEG を識別。
- メモリーカードの FAT ファイルシステムに準拠して、効率的にデータをブロック処理。

### 機能

- フォレンジックイメージを反復処理し、JPEG シグネチャを探す。
- 回復した JPEG を`###.jpg`の形式で個別のファイルに書き込む。
- 効率的なメモリ管理でメモリリークを防ぐ。

### 使用方法

- プログラムのコンパイル：`make recover`。
- プログラムの実行：`./recover card.raw`。

### 開発プロセス

- プログラムがフォレンジックイメージの名前をコマンドライン引数として受け入れることを確認。
- ファイル I/O のエラーを円滑に処理。
- 効率的なメモリ管理を実施。

### テスト

- 提供された`card.raw`でプログラムをテスト。
- 回復した JPEG ファイルの正確性を視覚的にチェック。
