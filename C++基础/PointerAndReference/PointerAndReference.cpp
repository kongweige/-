/* 指针和引用的区别: */
// 1.指针本质是一个地址，有自己的内存空间，引用只是一个别名
// 2.指针可以指向其他对象，引用不能，在初始化之后就不能改变了
// 3.指针可以初始化为nullptr，而引用必须初始化为一个已有对象的引用


#include <iostream>

void printVal(double& val)
{
  std::cout << sizeof(val) << std::endl;
}

int main()
{
  double val = 3.14;
  double* pter = nullptr;
  std::cout << sizeof(pter) << std::endl;
  pter = &val;
  std::cout << *pter << std::endl;
  printVal(val);
  return 0;
}
