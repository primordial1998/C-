//
//  advancedFunction.cpp
//  C++ Primer
//
//  Created by Zhuofan Dong on 4/15/22.
//

#include "advancedFunction.hpp"
#include <iostream>

//c++中函数的形参是可以有默认值的
int func(int a, int b = 20, int c = 30){
    return a + b + c;
}

//1.如果某个位置已经有了默认参数，那么这个位置往后从左到右都必须有默认值
//2.如果函数声明有默认参数，函数实现就不能有默认参数

int func(int a, int b  = 20, int c){
    return a + b + c;
}//报错
  
    
//函数占位参数:返回值类型 函数名（数据类型）
void func1(int a, int){//第二个int就是占位参数,还可以有默认参数
    std::cout << "this is func1" << std::endl;
}

//函数重载：函数名可以相同，提高复用性
//满足条件：1.同一个作用域下 2.函数名称相同 3. 函数参数类型不同 或 顺序不同 或 个数不同
//函数的返回值不算函数重载的满足条件

void overload_func(){
    std::cout << "func1" << std::endl;
    
}

void overload_func(int a){
    std::cout << "func1 is " << a << std::endl;
}//都在全局域，但是参数不同，c++就能辨认调用的是什么函数

//引用做为函数重载的参数
void overload_funct_ref(int &a){//版本1
    std::cout << "func1 is int &a " << a << std::endl;
}

void overload_funct_ref(const int &a){//版本2
    std::cout << "func1 is const int &a" << a << std::endl;
}

//2.函数重载遇到默认参数
void overload_func1(int a, int b){
    std::cout << "func1" << std::endl;
    
}

void overload_func1(int a){
    std::cout << "func1" << std::endl;
    
}


void main_func(){
    func(10);
    func(10, 20);//如果我们自己传入了数据就用我们的数据，如果没有就用默认值
    
    //占位参数
    func1(10,10);
    
    //引用重载
    int a = 10;
    overload_func_ref(a);//版本1，int &a = 10不合法
    overload_func_ref(10);//版本2，const int &a = 10合法
    
    //默认值重载
    overload_func1(10);//报错，因为两个函数都能调用，编译器不知道该调用哪一个，有二义性
}
