//
//  reference.cpp
//  C++ Primer
//
//  Created by Zhuofan Dong on 4/12/22.
//

#include "reference.hpp"
#include<iostream>

//引用的作用是给变量起别名
//数据类型 &别名 = 原名
//注意事项：引用必须要初始化；引用一旦初始化后就不可以更改
//函数传参时，可以利用引用让形参修饰实参来简化指针修改实参
//1.值传递
void my_swap01(int a, int b){
    int temp = a;
    a = b;
    b = temp;
}
//地址传递
void my_swap02(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}
//3.引用传递
void my_swap03(int &a, int &b){
    int temp = a;
    a = b;
    b = temp;
}
//引用做函数返回值
//1.不要返回局部变量的引用
int &test01(){
    int a = 10;
    return a;
}

//2.函数的调用可以作为左值
int &test02(){
    static int a = 10;
    return a;
}
void main_funuc(){
    int a = 10;
    
    int &b = a;
    
    b = 20;
    std::cout << b << std::endl;//输出的是20,因为b和a访问的是同一块内存
    
    //
    int c = 10;
    int d = 20;
    my_swap01(c,d);//形参不会修饰实参
    std::cout << c << d << std::endl;//c = 10, d = 20;
    my_swap02(&c,&d);//形参会修饰实参
    std::cout << c << d << std::endl;//c = 20; d = 10;
    my_swap03(c,d);//形参会修饰实参
    std::cout << c << d << std::endl;//c = 20, d= 10;
    
    
    //引用做为函数的返回值
    int &ref = test01();
    std::cout << ref << std::endl;//编译器会保留一次，所以输出是10；
    std::cout << ref << std::endl;//局部变量在函数被调用完就会自动释放，所以第二次打印时会出错。
    
    int &ref1 = test02();
    std::cout << ref1 << std::endl;
    std::cout << ref1 << std::endl;
    std::cout << ref1 << std::endl;//输出都是10，因为static是全局区，全局区的内存是由系统在程序运行结束后才释放
    
    test02() = 1000;//如果函数的返回值是引用，这个函数调用可以作为左值
    
    
}

//引用的本质在c++内部实现是一个指针常量
//int &ref = a等价于int * const ref = &a，系统自动生成了一个指针常量
//ref = 20等于 *ref = 20;

//常量引用主要用来修饰形参防止错误操作
void const_ref(){
    int a = 10;
    int &ref = a;
    
    int &ref1 = 10;//报错，因为它指向一块我们未定义的内存空间
    const int &ref2 = 10;//正确，加上const后编译器将代码修改为：int temp = 10; const int &ref2 = temp;
    ref2 = 20;//报错，加入const之后变为只读，不可以修改
    
}
