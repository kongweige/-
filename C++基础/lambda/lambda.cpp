#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>

// 作为函数参数使用

// 函数接受一个 vector 和一个 Lambda 表达式作为参数
void processVector(const std::vector<int>& vec, const std::function<void(int)>& func) 
{
  for (int num : vec) 
  {
    func(num); // 调用 Lambda 表达式处理每个元素
  }
}

// Lambda表达式可以作为函数的返回值。

int main()
{
  
  // 作为函数使用
  std::vector<int> nums = {1, 2, 3, 4, 5};
  // 判断容器中偶数的个数
  int count = std::count_if(nums.begin(), nums.end(), [](int x) { return x % 2 == 0; });
  std::cout << "Number of even elements: " << count << std::endl;

  // Lambda表达式可以捕获外部作用域的变量，捕获的变量可以是值、引用或通过引用捕获所有变量。
  int x = 10;
  auto func = []() { std::cout << "Not capturing any external variables" << std::endl; };  // 不捕获外部变量
  auto func1 = [x]() { return x * 2; }; // 值捕获
  auto func2 = [&x]() { x *= 3; };      // 引用捕获
  auto func3 = [&]() { return x * 2; }; // 捕获所有变量的值
  auto func4 = [=]() { return x * 2; }; // 捕获所有变量的值

  func();
  std::cout << "func1: " << func1() << std::endl;
  func2();
  std::cout << "func2: " << x << std::endl;
  std::cout << "func3: " << func3() << std::endl;
  std::cout << "func4: " << func4() << std::endl;

  // 使用 Lambda 表达式打印每个元素的平方
  std::cout << "Squared numbers: ";
  processVector(nums, [](int x) { std::cout << x * x << " "; });
  std::cout << std::endl; 
  
  // 返回值
  auto getLambda = []() {
    return [](int x, int y) { return x + y; }; 
  };
  auto lambda = getLambda();
  int result = lambda(3, 4); // result 的值为 7
  std::cout << result << std::endl;

  return 0;
}