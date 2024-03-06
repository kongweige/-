#include <iostream>

// 修饰普通变量
// 1. 全局静态变量
// 程序运行时初始化，在定义的文件内可见避免重定义，程序结束时释放，存储在全局区
static int g_static_val = 5;

void printVal()
{
  // 2. 局部静态变量
  // 第一次调用函数时初始化，不会在每次调用函数时重置，只在这个函数内可见，程序结束释放 存储在静态存储区
  static int local_static_val = 10;
  std::cout << "Local static val: " << local_static_val << std::endl;
}

// 修饰普通函数
// 只在文本文件内可见，避免重定义问题
// 在多人开发项目时，为了防止与他人命名空间里的函数重名，可以将函数定位为 static
static int getVal()
{
  return g_static_val;
}

class MyClass
{
public:
  MyClass() { }
  ~MyClass() { }

  // 修饰成员变量
  // 所有类对象共享，而非每个对象独有，而且不需要生成对象就可以访问该成员
  static int g_public_val_;

  // 修饰成员函数
  // 不需要生成对象就可以访问，但在静态成员函数中不能访问非静态成员
  static int getVal()
  {
    // val_ = 0;
    return g_private_val_;
  }

private:
  static int g_private_val_;
  int val_;
};

int MyClass::g_public_val_ = 0;
int MyClass::g_private_val_ = 0;

int main()
{
  printVal();
  std::cout << "getVal: " << getVal() << std::endl;
  
  std::cout << "getVal: " << MyClass::getVal() << std::endl;

  MyClass::g_public_val_ = 100;
  std::cout << "MyClass static: " << MyClass::g_public_val_ << std::endl;
  
  return 0;
}