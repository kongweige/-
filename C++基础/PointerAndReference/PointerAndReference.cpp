/* 指针和引用的区别: */
// 1. 指针本质是一个地址，有自己的内存空间，引用只是一个别名
// 2. 指针可以指向其他对象，引用不能，在初始化之后就不能改变了
// 3. 指针可以初始化为nullptr，而引用必须初始化为一个已有对象的引用

/* 野指针: */
// 野指针是指未被初始化或指向无效内存地址的指针
// 1. 指针未被初始化，但被使用
// 2. 指针被释放后未置空，继续被使用
// 3. 指针被错误地赋予了一个无效的地址

/* 悬挂指针: */
// 指向已经释放的指针，导致未定义行为

#include <iostream>

void printVal(double& val)
{
  std::cout << sizeof(val) << std::endl;
}

class MyClass 
{
public:
  MyClass() 
  {
    std::cout << "MyClass Constructor" << std::endl;
  }
  
  ~MyClass() 
  {
    std::cout << "MyClass Destructor" << std::endl;
  }
};

int main()
{
  double val = 3.14;
  double* pter = nullptr;
  std::cout << sizeof(pter) << std::endl;
  pter = &val;
  std::cout << *pter << std::endl;
  printVal(val);

  // 野指针
  // int* ptr;
  // std::cout << ptr << std::endl; // 未初始化

  // int* ptr = new int(5);
  // free(ptr);
  // std::cout << ptr << std::endl; // 位置空 继续使用

  // int *invalidPtr = nullptr;
  // std::cout << *invalidPtr << std::endl; // 错误地解引用指针

  // 悬挂指针  
  MyClass* ptr = new MyClass(); // 分配内存并创建对象
  delete ptr; // 释放对象
  ptr = nullptr; // 将指针置空

  // 悬挂指针：指向已经释放的内存
  std::cout << ptr << std::endl; // 输出悬挂指针的值
  
  // 尝试使用悬挂指针
  // 悬挂指针的行为是未定义的，可能导致程序崩溃或其他意外结果
  // 由于是未定义的行为，实际结果可能因系统环境、编译器等而异
  // std::cout << *ptr << std::endl;

  return 0;
}
