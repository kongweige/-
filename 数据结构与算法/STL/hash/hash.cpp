// unordered_set
// unordered_multiset
// unordered_map
// unordered_multimap

#include <iostream>
#include <unordered_set>

int main() 
{
    // 使用 std::unordered_set
    std::unordered_set<int> mySet = {10, 20, 30, 40, 50};

    // 使用 std::unordered_multiset
    std::unordered_multiset<int> myMultiset = {10, 20, 20, 30, 30, 30};

    // 插入元素
    mySet.insert(60);
    myMultiset.insert(40);

    // 删除元素
    mySet.erase(20);
    myMultiset.erase(30);

    // 遍历元素
    for (int num : mySet) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    for (int num : myMultiset) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}