// const_cast
// 用于将 const 或 volatile 对象转换为非 const 或非 volatile 对象，以便修改对象的值。

#include <iostream>

int main()
{
  
  const int val = 10;
  int& non_const_val = const_cast<int&>(val);
  non_const_val = 100;
  std::cout << "non const val: " << non_const_val << std::endl;

  return 0;
}