#include <iostream>

class MyClass
{
public:
  MyClass(){};
  virtual ~MyClass(){};

  // ����Ĭ����ʽ��������
  int rturnValue() { return value; }
  
  int func();

  inline virtual void who()
  {
    std::cout << "I am Base\n" << std::endl;
  }

private:
  int value = 10;
};

class SunClass
{
public:
  SunClass(){};
  
};

// ������Ҫ��ʾ��������
inline int MyClass::func()
{
  return 0;
}

int main()
{
  MyClass my_calss;
//�ŵ㣺
  // �������� ͨ���ں������ô�չ������  �����˺�������ʱ�漰���Ĳ������ݡ�ջ֡���������� �����˺������ÿ���
  // ����������Ⱥ꺯����˵���ڴ���չ��ʱ��������ȫ���ͼ����Զ�����ת��
//ȱ�㣺
  // ��������ʱͨ�������������Ч�ʵģ����ִ��ʱ��ȵ���ʱ�䳤��Ч�ʻ��½���������Ҫ�ڵ��ô����ƴ��룬��ʹ��������࣬�����ڴ�ռ�
  // ���������ں�����������ʱ����Ҫ���±���
  // inlineֻ�ǽ����������Ƿ�����ȡ���ڱ�����
  std::cout << my_calss.rturnValue() << std::endl;
  std::cout << my_calss.func() << std::endl;
 
  return 0;
}