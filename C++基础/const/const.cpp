#include <iostream>

class MyConst
{
public:
  MyConst() {}
  ~MyConst() {}

  // const �������أ�const�����Ըı��������ݳ�Ա
  inline std::string OutFunction() {std::cout << "out func "; return const_member_var; }

  inline std::string OutFunction() const { std::cout << "const out func "; return const_member_var; }

private:
  const std::string const_member_var = "my const member var";

};

// ����
// &ֻ���ݱ�������ֹ�˿�����const��ֹ���ݵ����ݱ��ı� 
void function3(const std::string& var);

int main()
{
  std::cout << "const cpp" << std::endl;
  // �����
  MyConst my_const;          // const���const�����Ե���
  const MyConst my_const_1;  // ������ ֻ�ܵ���const��Ա
  const MyConst *my_const_2 = &my_const_1; // ָ����� ָ�򳣶���
  const MyConst &my_const_3 = my_const_1;  // ָ�򳣶����& 
 
  std::cout << "???????: " << my_const.OutFunction() << std::endl;
  std::cout << "??????: " << my_const_1.OutFunction() << std::endl;
  std::cout << "??????: " << my_const_2->OutFunction() << std::endl;
  std::cout << "??????: " << my_const_3.OutFunction() << std::endl;

  // ָ��
  char ptr_varibale[] = "Hello World"; 
  char ptr_varibale_1[] = "World"; 

  // ����
  const int variable = 1;
  std::cout << "???��??? ????????? " << variable << std::endl;

  // ָ��
  // ָ�볣��
  const char* ptr_const = ptr_varibale;
  std::cout << "ָ�볣�� ָ��ָ���ֵ���ܱ� ָ�����ָ��������ַ " << *ptr_const << std::endl;
  
  // ����ָ��
  char *const const_ptr = ptr_varibale; 
  std::cout << "����ָ�� ָ���ָ���ܱ� ����ָ��ָ���ֵ����ͨ�������øı�" << *const_ptr << std::endl;
  *const_ptr = *ptr_varibale_1;
  std::cout << "??????? ??????????? ????????????????????" << *const_ptr << std::endl;
  std::cout << "??????? ??????????? ????????????????????" << *ptr_varibale << std::endl;

  return 0;
}