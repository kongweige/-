#include <iostream>

// 宏定义，相当于字符替换
// 预处理器处理
// 无类型安全检查
// 不分配内存
// 存储在代码段
#define DEBUG
#define MAX(a, b) (((a) > (b)) ? (a) : (b))
#define ADD(a,b) (a + b) 
#define PI 3.141592  // 简单宏定义

int main()
{
  int sum = ADD(1,2);
  std::cout << sum << std::endl;
  std::cout << sum * PI << std::endl;
  return 0;
}
