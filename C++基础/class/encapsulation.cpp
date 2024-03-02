#include <iostream>

// 封装：将数据和操作数据的方法打包在一起，对外部隐藏对象的具体实现细节
class Language
{
public:
  // 在构造函数中进行各种初始化操作 
  // 优点：
  // 无需考虑类是否被初始化
  // 经过构造函数完全初始化后的对象可以为const 类型，也能更方便被标准容器或算法使用
  Language() { }
  Language(std::string name,int age) : name_(name),age_(age) {  }
  ~Language() { }

  void setName(std::string name);
  void setAge(int age);

  std::string getName() const;
  int getAge() const;
  
private:
  std::string name_;
  int age_;

};

void Language::setName(std::string name)
{
  name_ = name;
}

void Language::setAge(int age)
{
  age_ = age;
}

std::string Language::getName() const
{
  return name_;
}

int Language::getAge() const
{
  return age_;
}

int main()
{
  // 创建一个 Person 对象
  // Language language;
  Language language("C++", 41);

  // 使用成员函数设置姓名和年龄
  language.setName("Python");
  language.setAge(33);

  // 使用成员函数获取姓名和年龄并输出
  std::cout << "Name: " << language.getName() << std::endl;
  std::cout << "Age: " << language.getAge() << std::endl;
  
  return 0;
}