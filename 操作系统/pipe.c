
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main() 
{
  int pipefd[2];
  pid_t pid;
  char buffer[1024];

  // 创建管道
  if (pipe(pipefd) == -1) {
    perror("pipe");
    exit(EXIT_FAILURE);
  }

  // 创建子进程
  pid = fork();

  if (pid == -1) {
    perror("fork");
    exit(EXIT_FAILURE);
  }

  if (pid == 0) {
    // 子进程
    close(pipefd[1]); // 关闭写端

    // 从管道中读取数据
    read(pipefd[0], buffer, sizeof(buffer));
    printf("Child process received: %s\n", buffer);

    close(pipefd[0]); // 关闭读端
    exit(EXIT_SUCCESS);
  } else {
    // 父进程
    close(pipefd[0]); // 关闭读端

    // 向管道中写入数据
    write(pipefd[1], "Hello from parent", 17);

    close(pipefd[1]); // 关闭写端
    wait(NULL); // 等待子进程结束
    exit(EXIT_SUCCESS);
  }

  return 0;
}
