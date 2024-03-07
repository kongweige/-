// array 是固定大小的顺序容器，它们保存了一个以严格的线性顺序排列的特定数量的元素,编译时确定数组大小
#include <iostream>
#include <array>

int main()
{
  // begine()/end() 第一个和最后一个元素的迭代器
  std::array<int, 5> my_array = {2, 16, 77,34, 50};
  std::cout << "my array contains:";
  for(auto it = my_array.begin(); it != my_array.end(); ++it)
    std::cout << ' ' << *it;
  std::cout << std::endl;
  
  // rbegin()/rend() 指向最后一个元素和第一个元素的反向迭代器
  std::cout << "my array contains:";
  for(auto rit = my_array.rbegin(); rit < my_array.rend(); ++rit)
    std::cout << ' ' << *rit;  
  std::cout << std::endl;

  //size() 返回数组容器中元素的数量
  std::cout << "size of my array:" << my_array.size() << std::endl;
  std::cout << "sizeof(my array):" << sizeof(my_array) << std::endl;

  //max_size() 数组容器中可容纳的最大元素数
  std::cout << "size of my_array: " << my_array.size() << std::endl;
  std::cout << "max_size of my_array: " << my_array.max_size() << std::endl;
  
  //empty() 数组容器是否为空
  std::cout << "my_array: " << (my_array.empty() ? "is empty" : "is not empty") << std::endl;

  //at() 返回数组中第n个位置的元素的引用
  std::cout << "my_array contains:";
  for (int i = 0; i < 5; i++)
    std::cout << ' ' << my_array.at(i);
  std::cout << std::endl;
  
  //front()/back() 返回对数组容器中第一个和最后一个元素的引用
  std::cout << "front is: " << my_array.front() << std::endl;  
  std::cout << "back is: " << my_array.back() << std::endl;    
  
  // data() 返回指向数组对象中第一个元素的指针
  // 数组中的元素存储在连续的存储位置，所以检索到的指针可以偏移以访问数组中的任何元素
  const char* cstr = "Test string";
  std::array<char,12> ch_array;
  std::memcpy (ch_array.data(),cstr,12);
  std::cout << ch_array.data() << std::endl;

  // fill() 填充数组所有元素
  my_array.fill(0);
  std::cout << "my_array contains:";
  for ( int& x : my_array) {
    std::cout << ' ' << x; 
  }
  std::cout << std::endl;
  
  // swap() 通过x的内容交换数组的内容，这是另一个相同类型的数组对象（包括相同的大小）
  // 以线性时间进行交换
  std::array<int,5> first = {10, 20, 30, 40, 50};
  std::array<int,5> second = {11, 22, 33, 44, 55};

  first.swap (second);

  std::cout << "first:";
  for (int& x : first) std::cout << ' ' << x;
  std::cout << std::endl;

  std::cout << "second:";
  for (int& x : second) std::cout << ' ' << x;
  std::cout << std::endl;

  // get<>()传入一个数组容器，返回指定位置元素的引用
  std::cout << "first element in first array: " << std::get<0>(first) << std::endl;

  return 0;
}