#include <iostream>

// this指针在类的成员函数中，this 指针被隐式地传递，指向当前对象的地址，可以用来访问当前对象的成员变量和成员函数
class MyCar
{
public:
  MyCar();
  ~MyCar();
  MyCar& setColor() {  std::cout << "color: " << color << std::endl;  return *this; }
  MyCar& setVersion() {  std::cout << "version: " << version;  return *this; }
private:
 std::string version = "1.0.0.1";
 std::string color = "black";
};

MyCar::MyCar()
{

}

MyCar::~MyCar()
{

    
}

int main()
{
  MyCar MyCar;
  MyCar.setColor().setVersion(); // 链式调用 代码简洁
  return 0;
}