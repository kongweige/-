// pragma pack(n) 设定以n字节进行排列
#include <iostream>
/*
  内存对齐规则:
    1. 结构(struct)或联合(union)的数据成员，第一个数据成员放在偏移量为0的地方，以后每个数据成员存储的起始位置要从该成员大小或者成员的子成员大小的整数倍开始。
    2. 结构体成员要从其内部"最宽基本类型成员"的整数倍地址开始存储。
    3. 结构体的总大小，必须是其内部最大成员的"最宽基本类型成员"的 
*/

// 为什么要内存对齐: 提高内存访问的效率和性能
// 什么时候不希望内存对齐: 数据结构大小优化 (在某些情况下，希望通过减少数据结构的大小来优化内存使用。默认的内存对齐可能会导致数据结构的大小增加)

/*
    char：通常占用1个字节。
    bool：通常占用1个字节。
    short：通常占用2个字节。
    int：通常占用4个字节。
    long：在32位系统上通常占用4个字节，在64位系统上通常占用8个字节。
    long long：通常占用8个字节。
    float：通常占用4个字节。
    double：通常占用8个字节。
    long double：大小可能因编译器和硬件平台而异，通常大于8个字节。
*/

#pragma pack(push)  // 保存对齐状态
#pragma pack(4)     // 设定为 4 字节对齐

// m1 (1 byte)  padding (3 bytes)  m4 (8 bytes)  m3 (4 bytes) 

struct test
{
  char m1;
  double m4;
  int m3;
};

#pragma pack(pop)   // 恢复对齐状态

struct test1
{
  char m1;
  double m4;
  int m3;
};

int main()
{
    
  std::cout << sizeof(test) << std::endl;
  std::cout << sizeof(test1) << std::endl;

  return 0;
}