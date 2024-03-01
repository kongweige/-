#include <iostream>

class MyConst
{
public:
  MyConst() {};
  ~MyConst() {};

  // const 可以重载，const不可以改变类内数据成员
  inline std::string OutFunction() {std::cout << "out func "; return const_member_var; }

  inline std::string OutFunction() const { std::cout << "const out func "; return const_member_var; }

private:
  const std::string const_member_var = "my const member var";

};

// 函数
// &只传递别名，防止了拷贝。const防止传递的数据被改变 
void function3(const std::string& var);

int main()
{
  std::cout << "const cpp" << std::endl;
  // 类对象
  MyConst my_const;          // const与非const都可以调用
  const MyConst my_const_1;  // 常对象 只能调用const成员
  const MyConst *my_const_2 = &my_const_1; // 指针变量 指向常对象
  const MyConst &my_const_3 = my_const_1;  // 指向常对象的& 
 
  std::cout << "???????: " << my_const.OutFunction() << std::endl;
  std::cout << "??????: " << my_const_1.OutFunction() << std::endl;
  std::cout << "??????: " << my_const_2->OutFunction() << std::endl;
  std::cout << "??????: " << my_const_3.OutFunction() << std::endl;

  // 指针
  char ptr_varibale[] = "Hello World"; 
  char ptr_varibale_1[] = "World"; 

  // 常量
  const int variable = 1;
  std::cout << "???α??? ????????? " << variable << std::endl;

  // 指针
  // 指针常量
  const char* ptr_const = ptr_varibale;
  std::cout << "指针常量 指针指向的值不能变 指针可以指向其他地址 " << *ptr_const << std::endl;
  
  // 常量指针
  char *const const_ptr = ptr_varibale; 
  std::cout << "常量指针 指针的指向不能变 但是指针指向的值可以通过解引用改变" << *const_ptr << std::endl;
  *const_ptr = *ptr_varibale_1;
  std::cout << "??????? ??????????? ????????????????????" << *const_ptr << std::endl;
  std::cout << "??????? ??????????? ????????????????????" << *ptr_varibale << std::endl;

  return 0;
}