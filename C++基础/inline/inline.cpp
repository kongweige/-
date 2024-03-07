#include <iostream>

// 虚函数（virtual）可以是内联函数（inline）吗：
// 虚函数可以是内联函数，内联是可以修饰虚函数的，但是当虚函数表现多态性的时候不能内联
// 内联是在编译期建议编译器内联，而虚函数的多态性在运行期，编译器无法知道运行期调用哪个代码，因此虚函数表现为多态性时（运行期）不可以内联。

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
    std::cout << "I am Base" << std::endl;
  }

private:
  int value = 10;
};

class SunClass : public MyClass
{
public:
  SunClass(){}
  
  inline virtual void who()
  {
    std::cout << "I am Sun" << std::endl;
  }
};

// 类外需要显示建议内联
inline int MyClass::func()
{
  return 0;
}

int main()
{
	// 此处的虚函数 who()，是通过类（MyClass）的具体对象（b）来调用的，编译期间就能确定了，所以它可以是内联的，但最终是否内联取决于编译器
	MyClass b;
	b.who();

	// 此处的虚函数是通过指针调用的，呈现多态性，需要在运行时期间才能确定，所以不能为内联
  MyClass* my_calss = new SunClass();
  my_calss->who();

//优点:
// 内联函数 通过在函数调用处展开代码  避免了函数调用时涉及到的参数传递 减少了函数调用开销
// 内联函数在代码展开时，会做安全类型检查和自动类型转换

//缺点:
// 内联函数通过代码膨胀提高效率，如果函数内部执行时间过长，效率会下降，而且在调用处复制代码，也会带来内存空间的消耗
// 内敛函数在函数库升级的时候需要重新编译
// 内联函数只是建议内敛，最终取决于编译器
  std::cout << my_calss->rturnValue() << std::endl;
  std::cout << my_calss->func() << std::endl;
 
  delete my_calss;
  my_calss = nullptr;

  return 0;
}