#include <iostream>


// 定义枚举类 open_modes
enum class open_modes { input, output, append };

// 定义普通枚举类型 color
enum color { red, yellow, green };

// 定义匿名枚举
enum { floatPrec = 6, doublePrec = 10 };

int main() 
{
  // 使用枚举类的枚举值
  open_modes mode = open_modes::output;

  // 判断枚举值
  if (mode == open_modes::input) {
    std::cout << "Mode is input" << std::endl;
  } else if (mode == open_modes::output) {
    std::cout << "Mode is output" << std::endl;
  } else if (mode == open_modes::append) {
    std::cout << "Mode is append" << std::endl;
  } else {
    std::cout << "Invalid mode" << std::endl;
  }

  // 使用普通枚举类型
  color c = red;

  // 使用匿名枚举
  int float_precision = floatPrec;
  int double_precision = doublePrec;

  std::cout << "Color: " << c << std::endl;
  std::cout << "Float precision: " << float_precision << std::endl;
  std::cout << "Double precision: " << double_precision << std::endl;

  return 0;
}