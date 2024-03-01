#include <iostream>

// union 变量所占的内存长度等于最长成员的内存长度
// (共享内存 同一内存空间中存储不同类型的数据 节省空间) 任意情况下只有一个数据成员可以有值。当某个成员被赋值时刻后其他成员变为未定义状态

/*
    默认访问控制符为public
    可以有构造函数和析构函数
    不能存在引用类型成员
    不能继承其他类，不能作为基类
    不能含有虚函数
    union匿名在所在定义作用域可以直接访问union成员
    全局匿名联合必须是静态的
*/

union Union
{
  Union() : i(10) {};
  int i;
  double d;
  // int& ref; // 引用类型成员
};

// 全局静态匿名联合
static union {
  int i;
  double d;
};

// 即使你的 Union 类型没有任何成员变量，C++ 编译器也会为其分配至少一个字节的内存空间，以确保每个对象都有一个唯一的地址。
// union Union
// {
//   Union() {};
// };

union test
{
  char mark;
  double num;
  float score;
}a;
 
int main()
{
  
  std::cout << sizeof(a) << std::endl;
  // std::cout << sizeof(Union) << std::endl;
  
  Union u;
 
  // 匿名
  union {
    int i;
    double d;
  };

  std::cout << u.i << std::endl;  // 输出 Union 联合的 10

  ::i = 20;
  std::cout << ::i << std::endl;  // 输出全局静态匿名联合的 20

  i = 30;
  std::cout << i << std::endl;    // 输出局部匿名联合的 30
  return 0;
}