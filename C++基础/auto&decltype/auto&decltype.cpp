#include <iostream>
#include <type_traits>
// auto和deltype的作用和区别:
// 用于实现类型自动推导，让编译器来操心变量的类型；auto不能用于函数传参和推导数组类型，但decltype可以解决这个问题


// 尾置返回允许我们在参数列表之后声明返回类型
template <typename It>
// 函数模板 fcn2 接受两个迭代器 beg 和 end，定义了一个序列的范围
auto fcn(It beg, It end) -> decltype(*beg) // 尾置返回类型（trailing return type）
{
  // 处理序列
  return *beg;    // 返回序列中一个元素的引用
}


// 为了使用模板参数成员，必须用 typename
template <typename It>
// decltype(*beg) 推导出迭代器 beg 所指向对象的类型。
// remove_reference 用于移除 decltype(*beg) 推导出的类型的引用限定符。 
auto fcn2(It beg, It end) -> typename std::remove_reference<decltype(*beg)>::type  
{
  // 处理序列
  // return *beg;    // 返回序列中一个元素的拷贝
  return *std::prev(end); // 最后一个元素
}

int main()
{
  int arr[] = {1, 2, 3, 4, 5};
  auto result = fcn2(std::begin(arr), std::end(arr)); // 调用函数模板
  std::cout << "Result: " << result << std::endl;
  return 0;
}