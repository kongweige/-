// 先进后出 数据结构。在栈中，最后插入的元素最先被移除

// 压入(Push)操作:
// 时间复杂度:O(1)
// 将一个元素放入栈顶(插入)

// 弹出(Pop)操作:
// 时间复杂度:O(1)
// 栈顶移除一个元素(删除)

// 查看栈顶元素(Top)操作:
// 时间复杂度:O(1)
// 查看栈顶元素操作只需访问栈顶元素，不涉及移动或删除操作，时间复杂度是常数时间

// 检查栈是否为空(Empty)操作:
// 时间复杂度:O(1)
// 检查栈是否为空通常只需检查栈中的元素数量是否为零，时间复杂度是常数时间

// 都需要逐个弹出检查
// 访问(Access):时间复杂度:O(n)
// 查找(Search):时间复杂度:O(n)

#include <iostream>
#include <stack>

// 有效的括号
bool isValid(std::string s) 
{
  std::stack<char> str_stack;

  for(auto c : s)
  {
    // c [ { 压入栈中
    if(c == '(' || c == '[' || c== '{')
      str_stack.push(c);
    else {
      // 第一次输入 ) ] }
      if(str_stack.empty()){
        return false;
      }
      switch(c)
      {
        case ')': 
          if(str_stack.top() == '(')
            str_stack.pop();
          else 
            return false;
        break;
        
        case ']': 
          if(str_stack.top() == '[')
            str_stack.pop();
          else 
            return false;
        break;
        
        case '}': 
          if(str_stack.top() == '{')
            str_stack.pop();
          else 
            return false;
        break;

        default: 
          break;
        }    
    }
  }
  return str_stack.empty();
}

// 235 栈实现队列
class MyQueue
{
public:
  MyQueue() { }
  ~MyQueue() { }
    
  void push(int value);
    
  int pop();
    
  int peek();
    
  bool empty();
private:
  std::stack<int> data_;
};

void MyQueue::push(int value)
{
  std::stack<int> temp_stk;
  while(!data_.empty())
  {
    temp_stk.push(data_.top());
    data_.pop();
  }
  
  temp_stk.push(value);
 
  while(!temp_stk.empty())
  {
    data_.push(temp_stk.top());
    temp_stk.pop();
  }
}
   
int MyQueue::pop()
{
  int val = data_.top();
  data_.pop();
  return val;
}

int MyQueue::peek()
{
  return data_.top();
}   

bool MyQueue::empty()
{
  return data_.empty();
}

int main()
{
  std::string str = "({[]})";
  std::string str1 = "([[]})";
  
  if(isValid(str1))
    std::cout << "true" << std::endl;
  else 
    std::cout << "false" << std::endl;


  // 栈实现队列
  MyQueue my_queue;

  my_queue.push(1); 
  my_queue.push(2); 
  std::cout << my_queue.peek() << std::endl;
  std::cout << my_queue.pop() << std::endl ; 

  std::string res = (my_queue.empty() == 1) ? "True" : "Fasle";
  std::cout << res << std::endl; 

  return 0;
}