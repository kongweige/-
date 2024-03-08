# 帮助

## man

### 介绍

**man: 显示查找的手册页**

man手册共分为9个章节：

1. **User Commands (用户命令)：** 这个章节包含了大多数用户使用的命令的文档，比如ls、cp、rm等。
2. **System Calls (系统调用)：** 这部分包含了与系统内核直接交互的系统调用的文档，包括与进程管理、文件系统、网络、设备等相关的系统调用。
3. **Library Functions (库函数)：** 这个章节包含了C语言库函数的文档，比如标准C库、数学库等。
4. **Special Files (特殊文件)：** 这部分包含了设备文件、文件系统和网络接口的文档，例如/dev/null、/proc文件系统等。
5. **File Formats and Conventions (文件格式和约定)：** 这个章节包含了常见文件格式和约定的文档，比如passwd文件、fstab文件等。
6. **Games et. al. (游戏等)：** 这个章节包含了游戏的文档，以及其他一些与游戏相关的内容。
7. **Miscellaneous (杂项)：** 这个章节包含了一些与系统相关的杂项文档，比如环境变量、文件权限等。
8. **System Administration tools and Daemons (系统管理工具和守护进程)：** 这部分包含了系统管理工具和守护进程的文档，比如cron、systemd等。
9. **Kernel routines (内核函数)：** 这个章节包含了与Linux内核开发相关的文档，比如内核函数、数据结构、设备驱动等。

### 使用

```
1. man [cmd] 
man ls
man man
2. man [手册目录] [cmd]
man 5 passwd
3. man [选项来列出所有匹配的手册页] [cmd]
man -a passwd
```

## hellp

### 介绍

**hellp: 主要用于显示bash shell内置命令的帮助信息**

### 使用

```
type命令用于区分内部和外部命令
type cd 

内部命令
help cd 
外部命令
ls --help
```

## info

### 介绍

**info：帮助信息比help更详细，作为help的补充**

### 使用

```
info ls
```

