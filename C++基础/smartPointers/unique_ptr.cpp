/* auto_ptr: */
// c++11 淘汰 被 unique_ptr取代
/* unique_ptr: */
// 独占式智能指针，确保一个对象和其相应的资源同一时间只被一个 pointer 拥有
/* auto_ptr 与 unique_ptr 比较: */
// auto_ptr通过赋值拷贝，转移所有权，unique_ptr没有赋值语义，通过move转移所有权
// unique_ptr可以管理数组，auto_ptr不可以 

#include <iostream>
#include <memory>

class MyClass 
{
public:
  MyClass(int val) : data_(val) {}
  void printData() { std::cout << "Data: " << data_ << std::endl; }

private:
  int data_;
};

int main()
{
  // 使用 auto_ptr
  std::auto_ptr<MyClass> autoPtr(new MyClass(10));
  autoPtr->printData();

  // auto_ptr 可以赋值拷贝，复制拷贝后所有权转移
  std::auto_ptr<MyClass> autoPtrCopy;
  autoPtrCopy = autoPtr;
  autoPtrCopy->printData();
  
  // auto_ptr 对象不能管理数组
  // std::auto_ptr<int> intArray(new int[5]); // 这样的写法会导致错误
 
  // 使用 unique_ptr
  std::unique_ptr<MyClass> uniquePtr(new MyClass(20));
  uniquePtr->printData();
  
  // unique_ptr 无拷贝赋值语义，但实现了 move 语义
  // std::unique_ptr<MyClass> uniquePtrCopy = uniquePtr; // 这样的写法会导致编译错误
  std::unique_ptr<MyClass>uniquePtrCopy = std::move(uniquePtr);
  if(uniquePtr == nullptr)
    std::cout << "uniquePtr is nullptr" << std::endl;
  uniquePtrCopy->printData();

  // unique_ptr 可以管理数组
  std::unique_ptr<int[]> intArray(new int[5]);
  for (int i = 0; i < 5; ++i)
  {
    intArray[i] = i * 2;
    std::cout << "Element " << i << ": " << intArray[i] << std::endl;
  }
 
  return 0;
}