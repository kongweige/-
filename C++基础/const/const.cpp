#include <iostream>

class MyConst
{
public:
  MyConst() {}
  ~MyConst() {}

  // const 修饰的函数可以重载，修饰的成员函数不能改变类内成员，也无法调用非const成员函数
  inline std::string OutFunction() {
    std::cout << "out func " << std::endl;
    printValue();
    return const_member_var_; 
  }

  inline std::string OutFunction() const {
    std::cout << "const out func " << std::endl; 
    // printValue(); // 无法调用非const成员函数
    return const_member_var_; 
  }

  void printValue() {
    std::cout << "number var: " << member_var_ << std::endl;
  }
private:

  const std::string const_member_var_ = "my const member var";

  std::string member_var_ = "member var";

};

// 函数
// &传递别名防止拷贝，提高效率，const修饰防止发生改变
void function3(const std::string& var);

int main()
{
  // 类对象
  MyConst my_const;          // const与非const都可以调用
  const MyConst my_const_1;  // 常对象 只能调用const成员
  const MyConst *my_const_2 = &my_const_1; // 指针变量 指向常对象
  const MyConst &my_const_3 = my_const_1;  // 指向常对象的& 
 
  std::cout << "my_const: " << my_const.OutFunction() << std::endl;
  std::cout << std::endl;
  std::cout << "my_const_1: " << my_const_1.OutFunction() << std::endl;
  std::cout << std::endl;
  std::cout << "my_const_2: " << my_const_2->OutFunction() << std::endl;
  std::cout << std::endl;
  std::cout << "my_const_3: " << my_const_3.OutFunction() << std::endl;
  std::cout << std::endl;

  // 指针
  char ptr_varibale[] = "Hello World"; 
  char ptr_varibale_1[] = "World"; 

  // 变量
  const int variable = 1; // 修饰局部变量存放在栈空间
  // variable = 2;
  std::cout << "修饰局部变量 局部变量不可以发生改变 " << variable << std::endl;

  // 指针
  // 指针常量 指针在const右侧
  const char* ptr_const = ptr_varibale;
  std::cout << "指针常量 指针指向的值不能变，可以指向其他地址 " << *ptr_const << std::endl;
  
  // 常量指针 const在指针左侧
  char *const const_ptr = ptr_varibale; 
  std::cout << "常量指针 指针指向的地址不能变，值可以通过解引用发生改变 " << *const_ptr << std::endl;
  *const_ptr = *ptr_varibale_1;
  std::cout << "常量指针 " << *const_ptr << std::endl;
  std::cout << "原指针 " << *ptr_varibale << std::endl;

  return 0;
}