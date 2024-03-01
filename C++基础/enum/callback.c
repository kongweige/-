#include <stdio.h>

// 定义枚举类型
enum CallbackType {
    Callback1,
    Callback2,
    Callback3
};

// 回调函数类型
typedef void (*CallbackFunc)(void);

// 具体的回调函数
void callback1() {
    printf("Callback 1 called\n");
}

void callback2() {
    printf("Callback 2 called\n");
}

void callback3() {
    printf("Callback 3 called\n");
}

// 调用回调函数的函数
void performCallback(enum CallbackType type) {
    // 定义一个函数指针数组，用于存储不同枚举值对应的回调函数
    CallbackFunc callbacks[] = {callback1, callback2, callback3};

    // 根据枚举值选择对应的回调函数，并调用它
    CallbackFunc selectedCallback = callbacks[type];
    selectedCallback();
}

int main() {
    // 通过枚举值来选择回调函数
    performCallback(Callback1);
    performCallback(Callback2);
    performCallback(Callback3);

    return 0;
}