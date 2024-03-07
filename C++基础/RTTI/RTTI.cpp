// RTTI提供了一种在程序运行时确定对象类型的机制
// dynamic_cast：动态类型转换操作符，用于在继承层次结构中进行安全的向下转型。dynamic_cast会在运行时检查类型，如果转换是安全的，则返回被转换类型的指针或引用；如果转换不安全，则返回空指针或引发异常（如果是引用类型）
// typeid：用于返回表达式的运行时类型信息。typeid操作符返回一个std::type_info对象，它包含有关表达式的类型信息。通常与dynamic_cast结合使用，以检查对象的实际类型是否与预期类型相匹配

// class type_info
// {
// public:
//     const char* name() const;
//     bool operator == (const type_info & rhs) const;
//     bool operator != (const type_info & rhs) const;
//     int before(const type_info & rhs) const;
//     virtual ~type_info();
// private:
//     ...
// };

#include <iostream>

class Flyable                       // 能飞的
{
public:
  virtual void takeoff() = 0;     // 起飞
  virtual void land() = 0;        // 降落
};

class Bird : public Flyable         // 鸟
{
public:
  void foraging() { std::cout << "eat!" << std::endl; }           // 觅食
  virtual void takeoff() { std::cout << "Bird takeoff" << std::endl; }
  virtual void land() { std::cout << "Bird land" << std::endl; }
  virtual ~Bird(){}
};

class Plane : public Flyable        // 飞机
{
public:
  void carry() { std::cout << "carry!" << std::endl; }              // 运输
  virtual void takeoff() { std::cout << "Plane takeoff" << std::endl; }
  virtual void land() { std::cout << "Plane land" << std::endl; }
};

void doSomething(Flyable *obj)                 // 做些事情
{
  obj->takeoff();

  std::cout << typeid(*obj).name() << std::endl;        // 输出传入对象类型（"class Bird" or "class Plane"）

  if(typeid(*obj) == typeid(Bird))            // 判断对象类型
  {
    Bird *bird = dynamic_cast<Bird *>(obj); // 对象转化
    bird->foraging();
  }

  obj->land();
}

int main()
{
  Bird *obj = new Bird();
  // Plane *obj = new Plane();
  doSomething(obj);
  delete obj;
  obj = nullptr;
  return 0;
}