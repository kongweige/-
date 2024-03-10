// 信号量的使用方法：
// 初始化信号量：在程序中创建信号量对象，并初始化其初始值。
// P（Wait）操作：当线程需要访问临界区或者获取资源时，执行 P 操作。如果信号量值大于 0，则将其减 1；如果信号量值为 0，则线程将被阻塞，直到信号量值大于 0。
// V（Signal）操作：当线程完成对临界区的访问或者释放资源时，执行 V 操作。将信号量的值加 1，并唤醒等待队列中的一个线程。
// 等待队列：当信号量的值为 0 时，线程将进入等待队列，直到信号量的值大于 0 才会被唤醒。

#include <iostream>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>

// 全局变量
sem_t sem;
int g_sem_val;

// 线程函数
void* threadFunction(void* arg) 
{  
  // 获取信号量
  sem_wait(&sem);

  sem_getvalue(&sem, &g_sem_val);
  std::cout << "func Semaphore value: " << g_sem_val << std::endl;

  // 临界区代码
  std::cout << "Entered critical section in thread " << pthread_self() << std::endl;
  sleep(2); // 模拟临界区代码的执行时间

  // 释放信号量
  sem_post(&sem);

  pthread_exit(NULL);
}

int main() 
{
  // 初始化信号量
//   sem_init(&sem, 0, 0);
  sem_init(&sem, 0, 1);
  // 获取信号量的当前值

  sem_getvalue(&sem, &g_sem_val);
  std::cout << "Semaphore value: " << g_sem_val << std::endl;

  // 创建线程
  pthread_t thread1, thread2;
  pthread_create(&thread1, NULL, threadFunction, NULL);

  sem_getvalue(&sem, &g_sem_val);
  std::cout << "thread1 Semaphore value: " << g_sem_val << std::endl;
  
  pthread_create(&thread2, NULL, threadFunction, NULL);

  sem_getvalue(&sem, &g_sem_val);
  std::cout << "thread2 Semaphore value: " << g_sem_val << std::endl;
  
  // 等待线程结束
  pthread_join(thread1, NULL);
  pthread_join(thread2, NULL);

  // 销毁信号量
  sem_destroy(&sem);

  return 0;
}