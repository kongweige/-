#include <iostream>

// 作为一个对函数或者全局变量的外部声明，提示编译器遇到此变量或函数时，在其它模块中寻找其定义
// 在文件1中声明全局变量
extern int globalVariable;

// 被extern "C"修饰的变量和函数是按照C语言方式编译和链接的


int main()
{
  std::cout << globalVariable << std::endl;

  return 0;
}