#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>

std::mutex mtx;
std::condition_variable cv;
bool ready = false;

void print_id(int id) {
  std::unique_lock<std::mutex> lock(mtx); // 自动加锁和解锁 在其生命周期结束时自动调用析构函数，释放互斥量 mtx 的所有权，执行解锁操作
  while (!ready) {
    cv.wait(lock); // 等待条件变量通知
  }
  // 条件满足，执行任务
  std::cout << "Thread " << id << " is executing." << std::endl;
}

void go() {
  std::unique_lock<std::mutex> lock(mtx);
  ready = true;
  cv.notify_all(); // 通知所有等待线程
}

int main() {
  const int num_threads = 5;
  std::thread threads[num_threads];

  // 创建多个线程
  for (int i = 0; i < num_threads; ++i) {
    threads[i] = std::thread(print_id, i + 1);
  }

  std::cout << "Threads are ready." << std::endl;
  std::this_thread::sleep_for(std::chrono::seconds(2)); // 等待一段时间
  go(); // 设置条件变量为真

  // 等待所有线程结束
  for (int i = 0; i < num_threads; ++i) {
    threads[i].join();
  }

  return 0;
}