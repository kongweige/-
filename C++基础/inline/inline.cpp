#include <iostream>

class MyClass
{
public:
  MyClass(){}
  virtual ~MyClass(){}

  // 类内默认隐式建议内联
  int rturnValue() { return value; }
  
  int func();

  inline virtual void who()
  {
    std::cout << "I am Base\n" << std::endl;
  }

private:
  int value = 10;
};

class SunClass
{
public:
  SunClass(){}
  
};

// 类外需要显示建议内联
inline int MyClass::func()
{
  return 0;
}

int main()
{
  MyClass my_calss;
//优点:
// 内联函数 通过在函数调用处展开代码  避免了函数调用时涉及到的参数传递 减少了函数调用开销
// 内联函数在代码展开时，会做安全类型检查和自动类型转换

//缺点:
// 内联函数通过代码膨胀提高效率，如果函数内部执行时间过长，效率会下降，而且在调用处复制代码，也会带来内存空间的消耗
// 内敛函数在函数库升级的时候需要重新编译
// 内联函数只是建议内敛，最终取决于编译器
  std::cout << my_calss.rturnValue() << std::endl;
  std::cout << my_calss.func() << std::endl;
 
  return 0;
}