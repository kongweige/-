# 文件管理

## 文件操作命令

### pwd

**pwd: 显示当前目录名称**

```shell
pwd
```

###  cd

**cd: 更改当前的操作目录**

```
cd /path/to/...  绝对路径
cd ./path/to/... 相对路径
cd ../path/to/...相对路径

回到上一次操作的目录
cd -
```

### ls

**ls: 查看当前目录下的文件**

```
ls [选项] [参数]

ls ./

查看root目录和根目录下的文件
ls /root / 

// 长文件
ls -l
// 显示隐藏文件
ls -a
// 逆向显示(默认文件名逆向)
ls -l -r
// 逆向显示(按时间逆向)
ls -l -r -t
// 显示子文件
ls -R
// 简化操作
ls -lrt
```

### touch

**touch: 创建文件**

```
touch filename.txt
```

### mkdir

**mkdir: 创建文件夹**

```
根目录下创建a文件夹
mkdir /a
当前目录创建a文件夹
mkdir a
创建多个目录
mkdir a b c
创建多级目录
mkdir -p a/b/c/d
```

### rmdir

**rmdir: 删除目录（只能是空白目录）**

```
rmdir [文件]
```

### rm

**rm：删除非空目录**

```
删除目录及其下的所有文件和子目录
-r 递归
-f 表示强制
rm -rf [file name]
```

### cp

**cp: 复制文件和目录到指定位置（默认复制文件；-r复制目录）**

```
-v: 显示详细的复制过程
cp [选项] [源文件] [目标文件或目录]
```

### mv

**mv: 移动文件或重命名**

```
mv [选项] [源文件] [目标文件或目录]
```



## 文本查看命令

### cat

**cat: 文件内容显示到终端**

```
cat [file name]
```

### head

**head: 查看文件开头**

```
head [file name]
```

### tail

**tail: 查看文件结尾**

```
tail [file name]
```

### wc

**wc: 统计文件内容信息**

```
wc [file name]
```



## 打包和压缩

**打包并压缩：**

- `-c`：表示创建新的 tar 文件。
- `-z`：表示使用 gzip 压缩文件。即，在创建 tar 文件的同时，使用 gzip 压缩工具进行压缩。
- `-v`：表示 verbose 模式，即详细输出执行过程中的信息，使您能够看到哪些文件被打包并压缩。
- `-f`：表示后面紧跟着一个文件名，用于指定将要创建的 tar 文件的名称。

```
将目录 directory/ 中的所有文件和子目录打包成一个 tar 文件，并使用 gzip 压缩，压缩后的文件名为archive.tar.gz(压缩更小)
tar -czvf archive.tar.gz directory/

使用bzip2压缩文件，生成.tar.bz2格式文件(压缩更快)
tar -cjvf archive.tar.bz2 directory/
```

**解压缩：**

- `-x`：表示解压缩（或提取）文件。
- `-z`：表示使用 gzip 解压缩文件。即，解压缩时使用 gzip 解压缩工具进行解压。

```
gzip 解压缩文件
tar -xzvf archive.tar.gz

bzip2 解压缩
tar -xjvf archive.tar.gz
```
