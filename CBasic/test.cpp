#include <stdio.h>
#include <iostream>
#include <string.h>

using namespace std;

/**
 * # 输入输出流
 * 
 * # 1. 格式化输出函数实现（浮点数的两位小数输出、整数格式化输出、字符串自动填充输出）
 */

float test11 = 3.1415926;  //保留两位小数
int test12 = 214456;  //金额单位由元->万元
char* test13 = "123";  //输出7位字符串

int main(){
    printf("%2f\n", test11);
    printf("%2d\n", test12);
    printf("%07s", test13);
    return 0;
}
