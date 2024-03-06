// static_cast（静态转换）
// 用于转换非多态类型，如基础类型、指针、引用，基类转子类，子类转基类（可能出问题，因为子类可能有父类没有的字段和方法）  
// 转换在编译时进行，不会进行运行时类型检查
#include <iostream>

class MyBase
{
public:
  MyBase() { }
  ~MyBase() { }
};

class MyDerived : public MyBase
{
public:
  MyDerived() { }
  ~MyDerived() { }
  void printVal() { std::cout << "Derived class" << std::endl; }
};

int main()
{
  // static_cast
  int val = 10;
  double db_val = static_cast<double>(val);
  std::cout << "static cast: " << db_val << std::endl;

  MyBase* base_ptr = new MyDerived();
  MyDerived* derived_ptr = static_cast<MyDerived*>(base_ptr); // 基类指针转换成子类
  derived_ptr->printVal();
  
  return 0;
}
