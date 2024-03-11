// 底层都是由红黑树实现
// map 中元素的 key 不允许重复，multimap 可以重复
// (O(logn))
#include <iostream>
#include <map>

int main()
{
  std::map<int,std::string>my_map;

  my_map.insert({1, "one"}); // 插入键值对 {1, "one"}
  my_map.insert({2, "two"}); // 插入键值对 {2, "two"}
  my_map.erase(1); // 删除键为 1 的键值对

  std::cout << my_map[2] << std::endl; // 使用下标操作符访问键为 2 的值
  std::cout << my_map.at(2) << std::endl; // 使用 at() 方法访问键为 2 的值
  
  // 使用迭代器来遍历 map 中的键值对。
  for (auto it = my_map.begin(); it != my_map.end(); ++it) {
    std::cout << "Key: " << it->first << ", Value: " << it->second << std::endl;
  }
  

  std::multimap<int,std::string> my_multimap; // 创建一个键类型为 KeyType，值类型为 ValueType 的 multimap

  my_multimap.insert({1, "one"}); // 插入键值对 {1, "one"}
  my_multimap.insert({1, "two"}); // 插入键值对 {1, "two"}，与上一个键相同
  // my_multimap.erase(1); // 删除键为 1 的所有键值对

  // 使用 equal_range() 方法获取键为 2 的所有值的范围
  auto range = my_multimap.equal_range(1);

  // 使用迭代器遍历范围内的所有值
  for (auto it = range.first; it != range.second; ++it) {
    std::cout << it->second << std::endl;
  }
  
  for (auto it = my_multimap.begin(); it != my_multimap.end(); ++it) {
    std::cout << "Key: " << it->first << ", Value: " << it->second << std::endl;
  }

  return 0;
}