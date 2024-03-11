/* list 底层实现原理: */
// list的底层是通过双向链表实现，节点都是相互独立的，之间的线性关系是通过指针维持，没插入和删除一个元素，就配置或释放一个元素空间
// list底层由链表实现，不支持随机访问，插入和删除时间复杂度都是O(1),访问只能从头遍历,时间复杂度为O(n)
// list不会造成内存的浪费，占用内存较小
#include <iostream>

# if 0
#include <list>

int main()
{
  std::list<int> my_list;

  for(int i = 0; i < 10;i++) {
    my_list.push_back(i);
  }
  
  // 使用迭代器访问元素
  std::list<int>::iterator it;
  for (it = my_list.begin(); it != my_list.end(); ++it) {
    std::cout << *it << " " ;
  }
  std::cout << std::endl;

  // 使用范围 for 循环访问元素
  for (int x : my_list) {
    std::cout << x << " ";
  }
  
  // reverse() 反转链表中的元素
  my_list.reverse();
  
  std::cout << "\n";
  for (int x : my_list) {
    std::cout << x << " ";
  }
  
  return 0;    
}

#else
/* forward_list 底层实现原理: */
// 单向链表结构：std::forward_list 是一个单向链表，每个节点包含一个指向下一个节点的指针，因此只能从头部开始顺序遍历链表
// 轻量级：与 std::list 相比，std::forward_list 更加轻量级，因为它只有一个指向下一个节点的指针，而 std::list 有两个指针（指向前一个和后一个节点）
// 迭代器：std::forward_list 提供了单向迭代器，只支持单向遍历，无法逆向遍历链表
// 空间效率：由于 std::forward_list 是单向链表，每个节点只包含指向下一个节点的指针，因此内存空间利用率相对较高
#include <forward_list>

int main()
{
  // 创建一个存储 int 类型的 forward_list
  std::forward_list<int> my_list;

  // 在列表头部插入元素
  my_list.push_front(5); 
  
  // 在指定位置后插入元素
  auto it = my_list.insert_after(my_list.before_begin(), 10); 
  
  // 删除指定位置后的元素
  my_list.erase_after(it); 

  // 遍历输出列表中的元素
  for (int x : my_list) {
    std::cout << x << " ";
  }

  return 0;
}

#endif