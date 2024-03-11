// set 和 multiset 底层通过红黑树实现
// 都是有序的，set 中元素不允许重复，multiset 可以重复。
// 插入、删除、查找 O(log2n)
#include <iostream>

#include <set>

void printSet(const std::set<int>& my_set) 
{
  for (auto it = my_set.begin(); it != my_set.end(); ++it) {
    std::cout << *it << ' ';
  }
  std::cout << std::endl;
}

int main()
{
  std::set<int> my_set;

  // 使用 set
  my_set.insert(10);
  my_set.insert(20);
  my_set.insert(30);
  my_set.insert(10); // 重复元素，将被忽略

  std::cout << "Set elements: ";
  for (const auto& elem : my_set) {
    std::cout << elem << " ";
  }
  std::cout << std::endl;

  // 使用 multiset
  std::multiset<int> my_multiset;
  my_multiset.insert(10);
  my_multiset.insert(20);
  my_multiset.insert(30);
  my_multiset.insert(10); // 允许重复元素

  std::cout << "Multiset elements: ";
  for (const auto& elem : my_multiset) {
    std::cout << elem << " ";
  }
  std::cout << std::endl;

  my_multiset.erase(10); // 删除所有元素为10的

  std::cout << "Multiset elements: ";
  for (const auto& elem : my_multiset) {
    std::cout << elem << " ";
  }
  std::cout << std::endl;
  
  
  my_set.insert(11);
  printSet(my_set);
  
  // 在集合中查找元素 11
  auto it = my_set.find(11); // 如果找到则返回指向该元素的迭代器，否则返回集合尾部迭代器
  // 检查是否找到了元素
  if (it != my_set.end()) {
    std::cout << "Element found: " << *it << std::endl;
    my_set.erase(11); // erase(val): 从集合中删除值为 val 的元素
  } 
  else {
    std::cout << "Element not found" << std::endl;
  }

  printSet(my_set);

  return 0;
}
