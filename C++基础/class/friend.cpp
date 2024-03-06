// 友元
// 可以访问一个类的私有和保护成员
// 友元关系破坏了类的封装性
#include <iostream>

// 声明 MyClass
class MyClass;

// 声明友元类 FriendClass
class FriendClass 
{
public:
  void accessPrivateMember(MyClass& obj);
};

// 声明 MyClass
class MyClass 
{
private:
  int privateMember;

  // 声明 FriendClass 为友元类
  friend class FriendClass;

public:
  MyClass(int value) : privateMember(value) {}

  // 在成员函数中可以直接访问 FriendClass 的成员
  void useFriend() 
  {
    FriendClass fc;
    fc.accessPrivateMember(*this);
  }

};

// 定义 FriendClass 中的成员函数
void FriendClass::accessPrivateMember(MyClass& obj) 
{
  std::cout << "Accessing private member of MyClass from FriendClass: " << obj.privateMember << std::endl;
}

int main() 
{
  MyClass obj(10);
  obj.useFriend(); // 通过MyClass的成员函数调用FriendClass
  
  return 0;
}