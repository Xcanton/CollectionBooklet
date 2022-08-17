#include <stdio.h>
#include <iostream>
#include <string.h>

using namespace std;

/**
 * # 输入输出流
 * 
 * ## 1. 格式化输出函数实现（浮点数的两位小数输出、整数格式化输出、字符串自动填充输出）
 */

float test11 = 3.1415926;  //保留两位小数
int test12 = 214456;  //金额单位由元->万元
char* test13="123";  //输出7位字符串

void test1(){
    printf("%2f\n", test11);
    printf("%2d\n", test12);
    printf("%07s\n", test13);
}

/**
 * # 输入输出流
 * 
 * ## 2. 标准输入输出（实现一个加法器，对标准输入的两个整数求和）
 */


void test2(){
    int a,b;
    std::cin>>a>>b;
    std::cout << "Sum is: " << a+b <<endl;
}


/**
 * # 控制流流
 * 
 * ## 2.变形（加法器实现对不定长输入的求和）
 * ## 3. 分别使用两种循环实现三层等腰三角形输出
 *        *  
 *       ***
 *      *****
 */

void test2_(){
    int sum = 0, value = 0;
    while (std::cin >> value)
    {
        sum += value;
    }
    std::cout << "Sum is: " << sum << std::endl;
}

void test3_1(){}

void test3_2(){}

/**
 * # 常量、拷贝（浅拷贝与深拷贝）、指针
 * 
 * ## 4. 定义一个常量 pi 为3.14
 * ## 4-1. 实现常量pi的浅拷贝
 * ## 4-2. 实现常量pi的深拷贝
 * 
 * ## 5. 定义一个变量 a 等于自定义类A
 * ## 5-1. 实现 a 的浅拷贝
 */
class A{
    public:
    A(int _data) : data(_data){}
    int GetX() {return data;}
    A(){}
    private:
    int data;
};

void test4(){
    const float pi = 3.14;
    const float &result = pi;
    const float result_deep = pi;
}

void test5(){
    A a(5);
    A b;
    b = a;
    A c(a);
}


int main(){
    test1();
    test2();
    test2_();
    test3_1();
    test3_2();
    test4();
    test5();
    return 0;
}
