#include <iostream>
#include <string>

// 3种继承方式
// Public Inheritance:
// 公有是公有的
// 保护是保护的
// 私有不可访问

// Private Inheritance:
// 公有和保护都是私有的
// 私有不可访问

// Protected Inheritance: 
// 公有和保护都是保护的
// 私有不可访问

// Person 类定义
class Person 
{
public:
  Person(std::string name, int age) : name_(name), age_(age) {}

  void setName(std::string name) {
    name_ = name;
  }

  void setAge(int a) {
    age_ = a;
  }

  std::string getName() const {
    return name_;
  }

  int getAge() const {
    return age_;
  }

private:
  std::string name_;
  int age_;

};

// Student 类继承自 Person 类
class Student : public Person 
{
public:
  // 构造函数调用基类构造函数
  Student(std::string name, int age, int id) : Person(name, age), student_id_(id) {}
  
  // 学生特有的方法
  void setStudentID(int id) {
    student_id_ = id;
  }

  int getStudentID() const {
    return student_id_;
  }

private:
  // 学生特有的学号
  int student_id_;

};

int main()
{
  
  // 创建一个 Studen 对象
  Student student("C++",41,1979);
  
  // 调用基类方法
  student.setName("python");
  student.setAge(33);
  
  
  // 使用派生类的方法设置学生ID
  student.setStudentID(1991);

  // 输出学生的姓名、年龄和学生ID
  std::cout << "Name: " << student.getName() << std::endl;
  std::cout << "Age: " << student.getAge() << std::endl;
  std::cout << "Student ID: " << student.getStudentID() << std::endl;
  
  return 0;
}