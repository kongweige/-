#include <iostream>
#include <unistd.h>
#include <sys/types.h>

int main() 
{
  pid_t pid;

  // 创建新进程
  pid = fork();

  if (pid < 0) 
  {
    // 创建进程失败
    std::cerr << "Fork failed" << std::endl;
    return 1;
  } 
  else if (pid == 0)
  {
    // 子进程执行代码
    std::cout << "Child process is running with PID: " << getpid() << std::endl;
  }
  else
  {
    // 父进程执行代码
    std::cout << "Parent process is running with PID: " << getpid() << std::endl;
    std::cout << "Child process PID: " << pid << std::endl;
  }

  return 0;
}
