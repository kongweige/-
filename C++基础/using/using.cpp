#include <iostream>
#include <vector>
/* using */
// using namespace 用于引入命名空间中的所有成员，使得在当前作用域内可以直接访问命名空间中的变量、函数、类等
// using namespace std;
// using std::cin;

// using 为已存在的类型定义一个新的别名
using my_int = int;

// using 定义模板别名
template<typename T>
using vec = std::vector<T>;

// using 定义函数指针别名
using FuncPtr = void(*)(int);




/* :: 范围解析运算符 */
// 全局作用域符（::name）：用于类型名称（类、类成员、成员函数、变量等）前，表示作用域为全局命名空间
// 类作用域符（class::name）：用于表示指定类型的作用域范围是具体某个类的
// 命名空间作用域符（namespace::name）:用于表示指定类型的作用域范围是具体某个命名空间的
int count = 11;         // 全局（::）的 count

class MyTest 
{
public:
  MyTest();
  ~MyTest();

  static int count;   // 类 A 的 count（A::count）
};

// MyTest 的构造和析构函数
MyTest::MyTest() { }
MyTest::~MyTest() { }

int MyTest::count = 21;

void fun()
{
  int count = 31;     // 初始化局部的 count 为 31
  count = 32;         // 设置局部的 count 的值为 32
}

int main() 
{

  ::count = 12;       // 测试 1：设置全局的 count 的值为 12
  MyTest::count = 22; // 测试 2：设置类 A 的 count 为 22
  fun();		          // 测试 3

  return 0;
}