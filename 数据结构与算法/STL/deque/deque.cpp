// 支持随机访问O(1)，但性能比vector要低；支持双端扩容，因此在头部和尾部插入和删除元素很快，为O(1)，但是在中间插入和删除元素O(n)

#include <iostream>
#include <deque>

int main()
{
  std::deque<int> my_dq;
  // push_back 容器末尾添加一个新元素
  for(int i = 0;i < 10; ++i) {
    my_dq.push_back(i);
  }
  
  // push_front 第一个元素之前添加一个新元素
  my_dq.push_front(-1);

  // pop_back 删除 deque 容器中的最后一个元素 9
  my_dq.pop_back();

  // pop_front 删除 deque 容器中的第一个元素 -1
  my_dq.pop_front();
  
  // emplace_front 在 deque 的开头插入一个新的元素
  my_dq.emplace_front(100);
  
  // emplace_back 在 deque 的末尾插入一个新的元素
  my_dq.emplace_back(100);

  for (std::deque<int>::iterator it = my_dq.begin(); it!=my_dq.end(); ++it)
    std::cout << ' ' << *it;

  return 0;
}