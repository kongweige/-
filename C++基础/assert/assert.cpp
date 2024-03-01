// #define NDEBUG          // assert 不可用
#include <iostream>
// #include <assert.h> // c
#include <cassert> // c++

int divide(int dividend, int divisor) 
{
  // 断言：确保除数不为零
  assert(divisor != 0);
  return dividend / divisor;
}

int main() 
{
  int a = 10;
  int b = 0; 

  int result = divide(a, b); // 调用 divide 函数  
  
  std::cout << "Result: " << result << std::endl;  
  
  return 0;
}