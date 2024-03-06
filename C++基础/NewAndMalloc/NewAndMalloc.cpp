#include <iostream>
#include <cassert>
#include <vector>

/* malloc和new的区别: */
// 1.malloc 需要申请指定字节的内存，new不需要会自动自己算所需要的字节数
// 2.new的底层是由mallc分配内存之后，调用构造函数创建对象
// 3.new返回类型指针，类型安全，malloc返回void*，需要强转成所需的类型
// delete 调用析构函数（清理资源），调用free（释放内存空间）

int main()
{
  // 申请内存并确定内存是否申请成功
  char *str = new char[100];
  assert(str != nullptr);

  delete[] str; // 释放动态分配的数组内存
  str = nullptr;
  
  std::vector<int>* vec = new std::vector<int>(10); // 动态分配一个 vector 对象

  std::cout << sizeof(*vec) << std::endl; // 输出 vector 对象的大小
  
  delete vec;    // 释放动态分配的 vector 对象
  vec = nullptr; // 将指针设置为nullptr

  return 0;
}