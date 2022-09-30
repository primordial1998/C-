//
//  function.cpp
//  C++ Primer
//
//  Created by Zhuofan Dong on 4/8/22.
//

#include "function.hpp"
#include <iostream>

//定义一个函数
//num1和num2并没有真实数据，它们是形参。
int add(int num1, int num2){
    int sum = num1 + num2;
    return  sum;
}
/*
 返回值类型 函数名(参数列表){
    函数体语句
    return值
 }
 */

//值传递
//如果函数不需要返回值，声明的时候可以写void
void swap(int num1, int num2){
    int temp = num1;
    num1 = num2;
    num2 = temp;
    //返回值不需要的时候可以不用写return
}
//当我们做值传递的时候函数的形参发生改变，并不会影响实参。

//函数的样式：
//1.五参无返
void test01(){
    std::cout << "this is test01" << std::endl;
}
//2.有参无返
void test02(int a){
    std::cout << "this is test02 = " << a << std::endl;
}
//3.无参有返
int test03(){
    std::cout << "this is test03" << std::endl;
    return 1000;
}

//4.有参有返
int test04(int a){
    std::cout << "this is test04 = " << std::endl;
    return a;
}


//函数的声明
int maX(int a, int b);//提前告诉程序这个函数是存在的，函数定义可以写在main函数后。
//声明可以多次，但是定义只能有一次。
//比较函数，实现两个整型数字进行比较，返回较大值。


//void main_function(){
//    int a = 10;
//    int b = 20;
//    
//    add(a,b);//a和b有实际数据，实参把数值传给形参。
//    
//    swap(a, b);
//    
//    test01();
//    test02(1000);
//    test03();
//    test04(a);
//    
//    
//}

int max(int a, int b){
    return a>b ? a:b;
}

//函数的分文件编写
//1.创建后缀名为.h的头文件
//2.创建后缀名为.cpp的源文件
//3.在头文件中写函数的声明
//4.在源文件中写函数的定义
