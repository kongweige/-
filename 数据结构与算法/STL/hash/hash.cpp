// unordered_set：存储的元素是唯一的，每个元素只能在集合中出现一次
// unordered_multiset：存储的元素可以重复，每个元素在集合中可以出现多次
// unordered_map：存储的键是唯一的，每个键对应一个值，因此每个键只能在 unordered_map 中出现一次
// unordered_multimap：允许存储多个具有相同键的键值对，即每个键可以对应多个值，因此键在 unordered_multimap 中可以重复出现
#include <iostream>

#if 0

#include <unordered_set>

int main() 
{
  // 使用 std::unordered_set
  std::unordered_set<int> my_set = {10, 20, 30, 40, 50};

  // 使用 std::unordered_multiset
  std::unordered_multiset<int> my_multiset = {10, 20, 20, 30, 30, 30};

  // 插入元素
  my_set.insert(60);
  my_multiset.insert(40);

  // 删除元素
  my_set.erase(20);
  my_multiset.erase(30);

  // 遍历元素
  for (int num : my_set) {
    std::cout << num << " ";
  }
  std::cout << std::endl;

  for (int num : my_multiset) {
    std::cout << num << " ";
  }
  std::cout << std::endl;

  return 0;
}

#else

#include <unordered_map>

int main() 
{
  // 使用 std::unordered_map
  std::unordered_map<int, std::string> my_map = {{1, "one"}, {2, "two"}, {3, "three"}};

  // 使用 std::unordered_multimap
  std::unordered_multimap<int, std::string> my_multimap = {{1, "one"}, {2, "two"}, {2, "dos"}, {3, "three"}};

  // 插入元素
  my_map.insert({4, "four"});
  my_multimap.insert({4, "four"});

  // 删除元素
  my_map.erase(2);
  my_multimap.erase(3);

  // 遍历元素
  for (const auto& pair : my_map) {
    std::cout << pair.first << ": " << pair.second << std::endl;
  }

  for (const auto& pair : my_multimap) {
    std::cout << pair.first << ": " << pair.second << std::endl;
  }

  return 0;
}

#endif