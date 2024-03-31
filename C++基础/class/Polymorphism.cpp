#include <iostream>

void printValue(int value);
void printValue(double value);

/* 静态多态由重载实现 */
// 编译期/早绑定
void printValue(int value) {
  std::cout << "int: " << value << std::endl;
}

void printValue(double value) {
  std::cout << "double: " << value << std::endl;
}

// 类中静态多态
// 函数的调用会根据对象的静态类型来确定，即在编译时就确定了调用哪个函数
// class A {
// public:
//   void show() {
//     std::cout << "父类A的方法" << std::endl;
//   }
// };

// class B : public A {
// public:
//   // 即在编译时就确定了调用哪个函数
//   void show() {
//     std::cout << "子类B的方法" << std::endl;
//   }
// };

// int main() {
//   B b;
//   b.show();  // 将调用子类B的show方法
//   return 0;
// }


/* 动态多态由虚函数实现 */
// 运行期/晚绑定

/* 虚函数的机制： */
// 虚函数是通过虚函数表和虚函数指针实现的，虚函数表是一个数组，其中存储了虚函数的地址，虚函数指针存放在类对象的内存空间头部，用来管理虚函数表。当子类重写父类虚函数时，父类的虚函数地址会替换成子类的虚函数地址，操作时指向的也就是子类的虚函数

/* 虚表和虚指针存放在哪里，什么时候创建：*/
// 虚函数表和指针在编译时创建，构造函数运行完成之后设置到对象内存空间中，位于开头

/* 虚函数存在类中还是类对象中： */
// 存在类中，不同的类对象共享一张虚函数表(为了节省内存空间)，但是每个包含虚函数的基类都有一个虚表

// 虚析构的作用:
// 基类指针指向子类对象，当需要释放子类对象时，如果基类的析构函数不是虚函数，将不会调用子类的析构函数，从而造成内存泄漏

class Person
{
public:
  // 在调用类的构造函数时，对象的虚表指针（vptr）并不会立即被构造出来，而是在构造函数调用完成后才会被设置
  Person() { } // 构造函数不能是虚函数
  Person(std::string n, int a) : name_(n), age_(a) {}
  
  virtual ~Person() { std::cout << "Person destructor function" << std::endl; }
  // ~Person() { std::cout << "Person destructor function" << std::endl; }
  
  virtual void display() const 
  {
    std::cout << "Name: " << name_ << ", Age: " << age_ << std::endl;
  }
  
  // 纯虚函数只是一个接口，只是个函数的声明而已，它要留到子类里去实现
  virtual void eat() = 0;

private:
  std::string name_;
  int age_;
};

class Student : public Person
{
public:
  
  Student() { }

  Student(std::string name,int age,int id) : Person(name,age),student_id_(id)  { }

  ~Student() { std::cout << "Student destructor function" << std::endl;  }
 
  virtual void display() const override
  {
    Person::display();
    std::cout << "Student ID: " << student_id_ << std::endl;
  }

  void eat() override { std::cout << "Juice" << std::endl; }

private:
  int student_id_;
};

class Teacher : public Person
{
public:
  
  Teacher() { }

  Teacher(std::string name,int age,int id) : Person(name,age),teacher_id_(id)  { }

  ~Teacher() { std::cout << "Teacher destructor function" << std::endl;  }
 
  virtual void display() const override
  {
    Person::display();
    std::cout << "Teacher ID: " << teacher_id_ << std::endl;
  }

  void eat() override { std::cout << "Coffee" << std::endl; }

private:
  int teacher_id_;
};

int main()
{
  // 静态
  printValue(10);
  printValue(3.14);

  // 动态
  // Person* person = new Person("zhangSan",20);  // 抽象类不能被实例化
  Person * person_student = new Student("LiSi", 20,1802);
  Person * person_teacher = new Teacher("Teacher", 50,666);

  // person->display();  // 调用基类Person的方法
  person_student->display(); // 调用子类Student的方法
  person_teacher->display(); // 调用子类Student的方法
  person_student->eat();
  person_teacher->eat();
  
  // delete person;
  // person = nullptr;
  
  delete person_student;
  person_student = nullptr;
  
  delete person_teacher;
  person_teacher = nullptr;

  return 0;
}
