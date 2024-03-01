#include <iostream>

// 告诉编译器每次操作该变量时一定要从内存中真正取出，而不是使用已经存在寄存器中的备份 并且不对其进行优化
// 可以用const修饰

int main()
{
  // 通常在访问硬件寄存器或者与外部环境交互的变量 可能会在程序控制之外被修改，因此需要声明为volatile，以避免编译器对其进行优化，保证对变量的读取和写入都会被生成对应的机器指令。
  volatile int* hardware_register = (volatile int*)0x12345678;
  return 0;
}
