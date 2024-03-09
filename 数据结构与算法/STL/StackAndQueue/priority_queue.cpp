// priority_queue优先队列，底层是由以vector作为底层容器，以heap作为处理规则，heap的本质是一个完全二叉树

#include <iostream>
#include <queue>

#if 0
// 最大堆（Max Heap）
// 在最大堆中，每个节点的值都大于或等于其子节点的值。根节点包含堆中的最大元素

int main() 
{
  std::priority_queue<int> max_heap;

  max_heap.push(3);
  max_heap.push(1);
  max_heap.push(4);
  max_heap.push(1);
  max_heap.push(5);

  while (!max_heap.empty()) {
    std::cout << max_heap.top() << " "; // 输出最大元素
    max_heap.pop(); // 移除最大元素
  }

  return 0;
}

#else 

// 最小堆（Min Heap）
// 在最小堆中，每个节点的值都小于或等于其子节点的值。根节点包含堆中的最小元素
#include <iostream>
#include <queue>

int main()
{
  std::priority_queue<int, std::vector<int>, std::greater<int>> min_heap;

  min_heap.push(3);
  min_heap.push(1);
  min_heap.push(4);
  min_heap.push(1);
  min_heap.push(5);

  while (!min_heap.empty()) {
    std::cout << min_heap.top() << " "; // 输出最小元素
    min_heap.pop(); // 移除最小元素
  }

  return 0;
}

#endif
