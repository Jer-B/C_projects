<!-- @format -->

# English README 　[Jump to Japanese Version](#japanese)

### C Photo Filter

**Description**  
This program allows you to edit photos by inputting the photo name and path as parameters.  
Examples: Changing the color of photos, applying blur, mirror effects, etc.

Language: C  
The code is provided below for testing.

1. Create files filter.c, helpers.c, bmp.h, and helpers.h in the same folder.
2. Filter effects parameters:
   - -b (Blur)
   - -g (Grayscale)
   - -r (Reflection)
   - -s (Sepia)
   - -e (Edge) [Only in filter_more program] [here](https://github.com/Jer-B/C_projects/tree/main/filter_more/filter)
3. Compile the program.
4. Run the program with this command. The parameter here is -g.

**Usage**  
Execute the following command:  
`./filter -g images/yard.bmp out.bmp`

#### Photo Samples

**「Original」**  
<br/>

<p align="center">
<img src="https://jer-b.github.io/assets/code_img/c/yard.bmp" width="900" alt="Original">
</p>
<br/>

**「Blur」**  
<br/>

<p align="center">
<img src="https://jer-b.github.io/assets/code_img/c/blur.JPG" width="900" alt="Blur">
</p>
<br/>

**「Grayscale」**  
<br/>

<p align="center">
<img src="https://jer-b.github.io/assets/code_img/c/grayscale.JPG" width="900" alt="Grayscale">
</p>
<br/>

**「Reflection」**  
<br/>

<p align="center">
<img src="https://jer-b.github.io/assets/code_img/c/reflect.JPG" width="900" alt="Reflection">
</p>
<br/>

**「Sepia」**  
<br/>

<p align="center">
<img src="https://jer-b.github.io/assets/code_img/c/Sepia.JPG" width="900" alt="Sepia">
</p>
<br/>

**「Blur blue_sum=green」**  
<br/>

<p align="center">
<img src="https://jer-b.github.io/assets/code_img/c/blur_blue_sum=green.JPG" width="900" alt="Sepia">
</p>
<br/>

**「Edge」**  
<br/>

<p align="center">
<img src="https://jer-b.github.io/assets/code_img/c/Edge_out.bmp" width="900" alt="Sepia">
</p>
<br/>

<a name="japanese"></a>

# 日本語版の README

### C・写真フィルター

**内容**  
プログラムにパラメーターとして写真名とパスを入れて、写真自体を編集する事が出来るプログラムです。  
例：写真の色を変えたり、ぼかし加工、ミラーエフェクトなど。

言語: C  
テストのため下にコードを載せました。

1. 同じフォルダーに filter.c、helpers.c、bmp.h、helpers.h、のファイルを作成する。
2. フィルターエフェクトのパラメーター:
   - -b (Blur)
   - -g (Grayscale)
   - -r (Reflection)
   - -s (Sepia)
   - -e (Edge) [filter_more プログラムのみ] [こちら](https://github.com/Jer-B/C_projects/tree/main/filter_more/filter)
3. コンパイルする。
4. このコマンドでプログラムを実行する。パラメーターは-g となっています。

**使用方法**  
下記のコマンドを実行する：  
`./filter -g images/yard.bmp out.bmp`

#### 写真サンプル

**「Original」**  
<br/>

<p align="center">
<img src="https://jer-b.github.io/assets/code_img/c/yard.bmp" width="900" alt="Original">
</p>
<br/>

**「Blur」**  
<br/>

<p align="center">
<img src="https://jer-b.github.io/assets/code_img/c/blur.JPG" width="900" alt="Blur">
</p>
<br/>

**「Grayscale」**  
<br/>

<p align="center">
<img src="https://jer-b.github.io/assets/code_img/c/grayscale.JPG" width="900" alt="Grayscale">
</p>
<br/>

**「Reflection」**  
<br/>

<p align="center">
<img src="https://jer-b.github.io/assets/code_img/c/reflect.JPG" width="900" alt="Reflection">
</p>
<br/>

**「Sepia」**  
<br/>

<p align="center">
<img src="https://jer-b.github.io/assets/code_img/c/Sepia.JPG" width="900" alt="Sepia">
</p>
<br/>

**「Blur blue_sum=green」**  
<br/>

<p align="center">
<img src="https://jer-b.github.io/assets/code_img/c/blur_blue_sum=green.JPG" width="900" alt="Sepia">
</p>
<br/>

**「Edge」**  
<br/>

<p align="center">
<img src="https://jer-b.github.io/assets/code_img/c/Edge_out.bmp" width="900" alt="Sepia">
</p>
<br/>
