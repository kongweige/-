// dynamic_cast（动态类型转换）
// 用于具有继承关系的基类和派生类之间的转换，并且只能用于多态类型转换  
// dynamic_cast用于在运行时进行类型检查，并且在转换失败时返回空指针(对于指针类型)或抛出异常std::bad_cast异常(对于引用类型)

#include <iostream>
#include <typeinfo> // 包含 std::bad_cast 类型的头文件
#include <stdexcept> // 包含异常类的头文件

class MyBase
{
public:
  virtual ~MyBase() {}
};

class MyDerived : public MyBase
{
public:
  void printVal() 
  {
    std::cout << "Derived class" << std::endl;
  }
};

int main() 
{
  // MyBase* basePtr = new MyBase();
  MyBase* base_ptr = new MyDerived();

  try {
    // 使用 dynamic_cast 将基类指针转换为派生类指针
    MyDerived* derived_ptr = dynamic_cast<MyDerived*>(base_ptr);
        
    if (derived_ptr) 
    {
      // 转换成功
      derived_ptr->printVal();
    } 
    else 
    {
      // 转换失败，抛出异常
      throw std::bad_cast();
    }
  } catch (const std::bad_cast& e) {
    // 处理转换失败的情况
    std::cerr << "Dynamic cast failed: " << e.what() << std::endl;
  }

  delete base_ptr;

  return 0;
}