// shared_ptr
// 共享式智能指针，多个智能指针指向同一个对象，采用引用计数的机制，当最后一个引用销毁时，释放内存空间
// shadred_ptr是不是线程安全的:
// 多个线程同时读同一个shared_ptr对象是线程安全的，但是如果是多个线程对同一个shared_ptr对象进行读和写，则需要加锁。

#include <iostream>
#include <memory>

class MyClass 
{
public:
  MyClass(int val) : data_(val) 
  {
    std::cout << "Constructing MyClass with data: " << data_ << std::endl;
  }

  ~MyClass()
  {
    std::cout << "Destroying MyClass with data: " << data_ << std::endl;
  }

  void setData(int val) 
  {
    data_ = val;
  }

  int getData() const 
  {
    return data_;
  }

private:
    int data_;
};

int main() {
    // 创建 shared_ptr 智能指针，并指向一个 MyClass 对象
    std::shared_ptr<MyClass> ptr(new MyClass(10));

    // 使用箭头操作符访问对象的成员函数和成员变量
    std::cout << "Data from MyClass: " << ptr->getData() << std::endl;

    // 使用 get() 方法获取指向的原始指针
    MyClass* raw_ptr = ptr.get();
    std::cout << "Data from raw pointer: " << raw_ptr->getData() << std::endl;

    // 使用 reset() 方法重置 shared_ptr 指向一个新的对象
    ptr.reset(new MyClass(20));
    std::cout << "Data from reset MyClass: " << ptr->getData() << std::endl;

    // 拷贝构造函数和赋值操作符
    std::shared_ptr<MyClass> ptr2 = ptr; // 拷贝构造函数
    std::shared_ptr<MyClass> ptr3;
    ptr3 = ptr; // 赋值操作符

    // 使用 use_count() 方法获取当前共享的指针数量
    std::cout << "Use count of ptr: " << ptr.use_count() << std::endl;
    ptr.reset(); // 显示重置未空 减少引用计数
    std::cout << "Use count of ptr2: " << ptr2.use_count() << std::endl;
    std::cout << "Use count of ptr3: " << ptr3.use_count() << std::endl;

    return 0;
}