// 队列 先进先出 数据结构。在队列中，最先插入的元素最先被移除

// 入队(Enqueue)操作:O(1)
// 队列尾部添加元素，时间复杂度是常数时间，因为不需要移动其他元素

// 出队(Dequeue)操作:O(1)
// 队列头部移除元素，时间复杂度是常数时间，因为只需将头部元素弹出

// 查看队首元素(Front)操作:O(1)
// 查看队首元素只需访问队列头部元素，时间复杂度是常数时间

// 查看队列是否为空(Empty)操作:O(1)
// 检查队列是否为空通常只需检查队列中的元素数量是否为零，因此时间复杂度是常数时间

#include <iostream>
#include <queue>

// 225 队列实现栈
class MyStack
{
public:
  MyStack() { }
  ~MyStack() { }

  void push(int value);

  int pop();
  
  int top();
  
  bool empty();

private:
  std::queue<int> data_;
};

void MyStack::push(int value)
{
  std::queue<int> temp_queue;
  temp_queue.push(value);
  
  // 双队列交换数据 最终将数据存储到data队列中
  while(!data_.empty())
  {
    temp_queue.push(data_.front());
    data_.pop();
  }

  while(!temp_queue.empty())
  {
    data_.push(temp_queue.front());
    temp_queue.pop();
  }
}

int MyStack::pop()
{
  int x = data_.front();
  data_.pop();
  return x;
}

int MyStack::top()
{
  return data_.front();
}

bool MyStack::empty()
{
  return data_.empty(); // 如果队列为空则返回1，否则返回0。
}

// 239 移动滑动窗口
std::vector<int> maxSlidingWindow(std::vector<int>& nums, int k) 
{
  int n = nums.size();
  std::priority_queue<std::pair<int,int>> q;
  std::vector<int> ans;
  for(int i = 0; i< k;++i)
  {
    q.emplace(nums[i],i);
  }

  ans.push_back(q.top().first);

  for(int i = k;i < n;++i)
  {
    q.emplace(nums[i],i);
    while (q.top().second <= i-k)
    {
      q.pop();
    }
    
    ans.push_back(q.top().first);
  }

  return ans;
}

int main()
{
  MyStack my_stack;
  
  my_stack.push(1);
  my_stack.push(2);
  my_stack.push(3);
  std::cout << my_stack.top() << std::endl;
  std::cout << my_stack.pop() << std::endl;
  std::string res = (my_stack.empty() == 1) ? "True" : "Fasle";
  std::cout << res << std::endl; // 返回 False
 
  std::vector<int> nums = {1,3,-1,-3,5,3,6,7};
  std::vector<int>aa = maxSlidingWindow(nums,3);

  return 0;
}