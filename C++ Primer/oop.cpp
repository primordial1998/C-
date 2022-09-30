//
//  oop.cpp
//  C++ Primer
//
//  Created by Zhuofan Dong on 4/12/22.
//

#include "oop.hpp"
#include <iostream>

//c++核心编程
//1.内存分区模型：不同区域存放的数据赋予不同的生命周期，给我们更大的灵活编程
//（程序运行前）
//代码区：存放函数体的二进制代码，由操作系统进行管理的
//存放cpu执行的机器指令
//代码区是共享的，对于频繁执行的程序只需要在内存中有一份代码
//代码区是只读的，防止程序意外的修改了他的指令

//全局区：存放全局变量和静态变量以及常量
//该区域的数据在程序结束后由操作系统释放

//创建一个全局变量
int g_a = 10;//全局区

const int c_g_a = 10;//全局常量

void global_var(){
    //创建普通局部变量
    int a = 10;//存放在另外一个区域
    
    //静态变量
    static int s_a = 10;//在普通变量前面加static，属于静态变量
    
    //常量
    //字符串常量
    std::cout << "字符串地址为： " << (int)&"hello world" << std::endl;
    
    //const修饰常量
    //const修饰的全局变量：c_g_a 放在全局区
    
    //const修饰的局部变量不在全局区
    const int c_l_a = 10;//不在全局区
}

//（程序运行后）
//栈区：由编译器自动分配释放，存放函数的参数值，局部变量等
//栈区数据的注意事项 -- 不要返回局部变量的地址
int* func(int b){//形参数据也会放在栈区
    b= 100;
    int a = 10;//局部变量，存放在栈区，栈区的数据在函数执行完后自动释放
    return &a;//返回局部变量的地址
}

//堆区：由程序员分配和释放，若程序员不释放程序结束时由操作系统回收
//在c++中主要利用new在堆区开辟内存

int *func1(){
    
   int *p = new int(10);
    return p;
}
void new_heeap1(){
    //利用new关键字，可以将数据开辟到堆区，而用new创建的数据，会返回该数据对应类型的指针
    int *p = func1();
    //*p输出为10；
}
//堆区数据释放

int func2(){
    int *p = new int(10);
    return p;
}

void test01(){
    //创建10整型数据的数组在堆区
    int arr = new int[10];//数组有10个元素
    
    for (int = 0; i < 10; i++){
        arr[i] = i + 100;
    }
    
    delete[] arr;//释放数组需要加一个中括号
}

void new_heap2(){
    int *p = func2();//*p输出为10，并且由程序员开辟和释放
    //释放堆区数据利用关键字delete
    delete p;
    
}
