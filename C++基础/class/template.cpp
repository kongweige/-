#include <iostream>
/* 模板所解决的问题和缺点：*/
// 1. 代码重用问题，通过编写通用模板代码，适用于不同的类型
// 2. 类型安全：编译时进行类型检查，确保代码在不同数据类型间是类型安全的
// 3. 性能优化：模板可以再编译期间生成特定类型的代码，避免运行时的性能开销
// 缺点：
// 编译时需要为每一种数据类型生成对应的代码，增加编译时间

/* 编译器生成代码时，是否会生成相同的代码，相同的该如何处理：*/
// 编译器会根据不同的参数类型生成不同的代码，参数类型相同 编译器为了优化会使用相同的重复代码


// 类模板
template<typename T,typename U>
class MyTemplate
{
public:
  MyTemplate(T a,T b) : first_val_(a),second_val_(b) { }
  ~MyTemplate() {}
  
  T getFirstVal() const { return first_val_; }
  T getSecondVal() const { return second_val_; }

private:
  T first_val_;
  T second_val_;
};

// 特化 为模板指定一个特定的类型
template <>
class MyTemplate<int,int> 
{
public:
  MyTemplate(int a, int b) : first_(a), second_(b) {}

  // 模板成员函数
  template<typename U>
  void printVal(U val) const { std::cout << "print val: " << val << std::endl; }

private:
    int first_;
    int second_;
};

// 偏特化 为模板部分参数指定一个特定类型
template <typename U>
class MyTemplate<int,U> 
{
public:
  MyTemplate(int a, U b) : first_(a), second_(b) {}

  void printSecond() const { std::cout << "print second: " << second_ << std::endl; }

private:
    int first_;
    U second_;
};

// 模板函数和模板函数的重载
// 通用模板函数，用于比较两个相同类型的值并返回较大值
template <typename T>
T getMax(T a, T b) 
{
  return (a > b) ? a : b;
}

// 特化版本，专门处理 const char* 类型的参数
template <>
const char* getMax<const char*>(const char* a, const char* b)
{
  return (strcmp(a, b) > 0) ? a : b; // 挨个比较字符的 ASCII 码值
}

int main()
{
  // 通用模板
  MyTemplate<double,double> my_template(3.14,3.15);
  std::cout << "First val: " << my_template.getFirstVal() << std::endl;
  std::cout << "Second val: " << my_template.getSecondVal() << std::endl;

  // 特化模板 int
  MyTemplate<int,int> my_template_int(10,20);
  my_template_int.printVal("hello!");

  // 偏特化 int string
  MyTemplate<int,std::string> my_template_int_string(10,"my_template_int_string");
  my_template_int_string.printSecond();

  int max_int = getMax(10, 20);
  std::cout << "Max of integers: " << max_int << std::endl;

  double max_double = getMax(3.14, 2.71);
  std::cout << "Max of doubles: " << max_double << std::endl;

  const char* max_string = getMax("apple", "banana");
  std::cout << "Max of strings: " << max_string << std::endl;
  return 0;
}