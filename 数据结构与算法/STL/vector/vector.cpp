/* vector 底层实现原理: */
// vector的底层由数组实现，通过3个迭代器指针来动态管理容器
// vector插入新元素时，如果未超过当时的容量，则还有剩余空间，那么直接插入到指定位置，然后调整迭代器
// 如果没有剩余空间了，则会重新配置有元素个数的vs(1.5)gcc(2)倍空间，然后将原空间元素复制到新空间，在向新空间添加元素，最后析构并释放原空间，之前的迭代器会失效
// 随机读改、尾部插入、尾部删除 O(1) 头部插入、头部删除 O(n)

#include <iostream>
#include <vector>

void growPushBack(std::vector<int> &vec, uint16_t size)
{
  for(int i = 0; i < 100; i++)
  { 
    vec.push_back(i);
    if(size != vec.capacity())
    {
      std::cout << "Capacity changed: " << vec.capacity() << std::endl;
    }
  }
}

int main()
{
  std::vector<int> my_vector;

  for(int i = 0; i < 10; i++) {
    my_vector.push_back(i);
  }
  
  for(auto it = my_vector.begin(); it != my_vector.end(); ++it)
    std::cout << ' ' << *it;
  std::cout << std::endl;

  // size() 返回数组中元素的个数
  std::cout << "size of my_vector:" << my_vector.size() << std::endl;

  // max_size() 返回系统限制的最大数量 
  std::cout << "max size of my_vector:" << my_vector.max_size() << std::endl;

  // resize() 调整容器大小使其包含n个元素 （控制的是容器的大小）
  my_vector.resize(5);
  my_vector.resize(8,100);
  my_vector.resize(12);
  for(auto it = my_vector.begin(); it != my_vector.end(); ++it)
    std::cout << ' ' << *it;
  std::cout << std::endl;
  
  // capacity() 返回当前vector所分配的空间大小
  std::cout << "size: " << (int) my_vector.size() << std::endl;
  std::cout << "capacity: " << (int) my_vector.capacity() << std::endl;
  

  // reserve()请求vector容量至少足以包含n个元素（控制的是容器的容量）vs(1.5倍扩容)gcc(2倍扩容)
  // 直接扩充到已经确定的大小，可以减少多次开辟、释放空间的问题（优化 push_back），就可以提高效率，其次还可以减少多次要拷贝数据的问题
  uint16_t vec_size = 0;

  std::vector<int> vec_int_a;
  vec_size = vec_int_a.capacity();
 
  std::cout << "Making vec_int_a growing:" << std::endl;
  std::cout << "current size: " << vec_size << std::endl;
  growPushBack(vec_int_a, vec_size);  //声明vector后未使用reserve，直接进行push_back操作 
  
  //-------------------------------------- //
  
  std::vector<int> vec_int_b;
  vec_int_b.reserve(100);
  vec_size = vec_int_b.capacity();
  std::cout << "Making vec_int_a growing:" << std::endl;
  std::cout << "current size: " << vec_size << std::endl;
  growPushBack(vec_int_b, vec_size);



  return 0;
}