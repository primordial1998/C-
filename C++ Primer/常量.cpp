//
//  常量.cpp
//  C++ Primer
//
//  Created by Zhuofan Dong on 4/6/22.
//
//常量的定义方式：
//1. #define 宏常量
//2. const修饰的变量
#define day = 7

#include "常量.hpp"
#include<iostream>

void Changliang(){
    //day = 14: 错误，day是常量，一旦修改就会报错
    
    //2. const修饰的变量
    const int month = 12;
    //month = 24; :报错，month是常量
    
    std::cout << "Month is " << month << std::endl;
    
}
