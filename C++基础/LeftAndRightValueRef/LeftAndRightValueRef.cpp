#include <iostream>
#include <utility>
/* 深浅拷贝: */
// 浅拷贝只是简单直接地复制指向某个对象的指针，而不复制对象本身，新旧对象还是共享同一块内存
// 深拷贝会另外创造一个一模一样的对象，新对象跟原对象不共享内存，修改新对象不会改到原对象

#if 0
// 左值: 简单说就是=左边的变量，直到离开作用域才销毁
// 右值: 即将销毁的临时对象，具有短暂的状态，比如字面值常量“hello”

// 左值引用
void lvalueReference(int& x) {
  std::cout << "Inside lvalueReference function, x = " << x << std::endl;
}

// 右值引用
void rvalueReference(int&& x) {
  std::cout << "Inside rvalueReference function, x = " << x << std::endl;
}

int main() {
  int a = 10; // a 是左值
  int&& b = 20; // 20 是右值

  // 调用左值引用函数
  lvalueReference(a);

  // 调用右值引用函数
  rvalueReference(std::move(b)); 

  return 0;
}
#else

/* 右值引用的作用： */
// 1. 通过移动构造函数和移动赋值运算符，避免不必要的资源拷贝，从而提高性能

class MyResource {
private:
  int* data;

public:
  // 构造函数：分配资源
  MyResource(int val);

  // // 拷贝构造函数：深拷贝资源
  // MyResource(const MyResource& other) : data(new int(*other.data)) {
  //     std::cout << "Copy constructor called" << std::endl;
  // }

  // 移动构造函数：转移资源所有权
  MyResource(MyResource&& other) noexcept;

  // 禁止拷贝构造函数和赋值运算符
  MyResource(const MyResource&) = delete;
  MyResource& operator=(const MyResource&) = delete;
  
  // 析构函数：释放资源
  ~MyResource();

  // 获取资源值
  int getValue() const {
    return (data != nullptr) ? *data : -1;
  }
};

MyResource::MyResource(int val) : data(new int(val)) 
{
  std::cout << "Resource allocated, value: " << *data << std::endl;
}

MyResource::MyResource(MyResource&& other) noexcept : data(nullptr) 
{
  std::cout << "Move constructor called" << std::endl;
  data = other.data; // 转移资源所有权
  other.data = nullptr; // 将原对象的资源指针置为空
}

MyResource::~MyResource() 
{
  if (data != nullptr) {
    std::cout << "Resource deallocated, value: " << *data << std::endl;
    delete data;
  }
}

// 函数接受 MyResource 对象作为参数
// void processResource(MyResource& res) {
//     std::cout << "Inside processResource function, value: " << res.getValue() << std::endl;
// }

// 函数接受 MyResource 对象作为右值引用参数
void processResource(MyResource&& res) 
{
  std::cout << "Inside processResource function, value: " << res.getValue() << std::endl;
}


// 2. 实现完美转发，精确传递参数，无论是左值还是右值，都可以精确地转发到目标函数

// 使用完美转发将参数传递给其他函数
// template<typename Func,typename... Args>
// void callFunc(Func&& func, Args&&... args)
// {
//   // 使用完美转发 将参数args传递给函数对象func
//   std::forward<Func>(func)(std::forward<Args>(args)...);
// }

// // 接受任意数量的参数，并打印它们
// template<typename... Args>
// void printValues(Args&&... args)
// {
//   (std::cout << ... << std::forward<Args>(args)) << std::endl;
// }

//重载被调用函数，查看完美转发的效果
void printValue(int& value) 
{
  std::cout << "Left value: " << value << std::endl;
}

void printValue(const int& value) 
{
  std::cout << "Right value: " << value << std::endl;
}

//实现完美转发的函数模板
template <typename Args>
void callFunc(Args&& args) 
{
  printValue(std::forward<Args>(args));
}

int main() 
{
  /* 移动构造 */
  // 创建一个 MyResource 对象
  MyResource resource(42);
  // 将对象传递给函数
  // processResource(resource);
    
  MyResource moved_resource(std::move(resource));
  // 将对象传递给函数（使用 std::move() 转换为右值引用）
  processResource(std::move(moved_resource));


  //
  //
  //


  /* 完美转发 */
  // callFunc(printValues<int,const char*,double>,10,"hello",3.14);
  callFunc(5);
  int x = 1;
  callFunc(x);

  return 0;
}

#endif