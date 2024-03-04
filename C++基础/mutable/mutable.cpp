#include <iostream>
class Test
{
public:
  // 使类中被声明为const的函数可以修改类中的非静态成员
  Test() : val_(0) {}
  ~Test() { }

  // 允许在常量成员函数中修改 mutable 成员变量
  int getVal() const { 
    val_++;
    return val_;
  }

private:
  mutable int val_; 
};

int main()
{
  Test test;
  std::cout << test.getVal() << std::endl;
  return 0;
}