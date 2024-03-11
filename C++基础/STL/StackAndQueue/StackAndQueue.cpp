// 栈和队列。都是由deque作为底层容器实现的，都是修改了deque的接口，使其具有自己独特的性质（此二者也可以用list作为底层实现）；
// stack是deque封住了头端的开口，先进后出
// queue是deque封住了尾端的开口，先进先出
// 插入和删除时间复度都是O(1)

#include <iostream>
#include <stack>
#include <queue>

int main()
{
  std::stack<int> my_stack;

  my_stack.push(5); // 将元素 5 压入栈顶
  my_stack.pop(); // 弹出栈顶元素
  my_stack.push(6); // 将元素 5 压入栈顶

  std::cout << my_stack.top() << std::endl; // 获取栈顶元素但不弹出
  
  std::queue<int> my_queue;

  my_queue.push(10); // 将元素 10 加入队列尾部
  my_queue.pop(); // 移除队列头部的元素
  for(int i= 0;i < my_queue.size();++i) {
    std::cout << my_queue.front() << std::endl; // 返回队列头部的元素但不移除
    my_queue.pop(); // 移除队列头部的元素
  }

  return 0;
}