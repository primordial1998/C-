//
//  pointers.cpp
//  C++ Primer
//
//  Created by Zhuofan Dong on 4/8/22.
//

#include "pointers.hpp"
#include <iostream>

//指针的作用：可以通过指针间接访问地址；可以通过指针来保存一个变量的地址，or, 指针就是地址
void pointers(){
    
    int a = 10;
    //1.定义指针： 数据类型 *指针变量名
    int *p;
    //让指针记录变量a的地址:取地址符&
    p = &a;
    // int *p = &a;
    //2.使用指针：通过解引用的方式来找到指针指向的内存
    //指针前加*代表解引用，找到指针指向的内存中的数据
    *p = 1000;//运行结果为*p = 1000, a也等于1000
    //无论什么数据类型，指针都占4个字节
    
    //空指针和野指针
    //空指针是指针变量指向内存中编号为0的空间，它用来给指针变量初始化，而且空指针不可以进行访问的。
    //0~255的内存为系统占用内存，是不可以访问的
    int *p2 = NULL;
    
    //野指针是指针变量指向非法的内存空间
    int *p3 = (int *)0x1100;//空指针和野指针都不是我们申请的内存空间，所以不能随意访问
    
}

//const修饰指针:常量指针
void const_pointers(){
    int a = 10;
    int b = 20;
    int *p = &a;
    const int *p2 = &a;//常量指针
    //指针指向可以改，指针指向的值不可以改
    *p = 20;//错误，值不可以改
    p = &b;//正确，指向可以改
    
    int *const p3 = &a;//指针常量，指针指向不可以改，指针指向的值可以改
    *p = 20;//正确，值可以改
    p = &b;//错误，指向不能改
    
    const int *const p4 = &a;//指向和指向的值都不能改
    
}

void arr_pointers(){
    int arr[10] = {1,2,3,4,5,6,7,8,9,10};
    
    int *p = arr;//arr就是数组的首地址，*p = 1
    p++;//让指针向后偏移4个字节（整型指针）
    
    //用指针遍历数组
    for (int i = 0; i < 10; i++){
        std::cout << *p << std::endl;
        p++;
    }
}

//地址传递
void swap02(int *p1, int *p2){
    int temp = *p1;
    *p1 = *p2;
    *p2 = temp;

}

void main_function(){
    
    int a = 10;
    int b = 20;
    swap02(&a, &b);
    
}

//指针，数组，函数
void bubblesort(int *arr, int len){//参数1:数组首地址，参数2:数组的长度
    for (int i = 0; i < len -1; i++){
        for (int j = 0; j < len -i - 1;j++){
            if (arr[j] > arr[j+1]){
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

void print_arr(int *arr,int len){
    for (int i = 0; i < len; i++){
        std::cout << arr[i] << std::endl;
    }
}

void pointer_case(){
    //1.创建数组
    int arr[10] = {4,3,6,9,1,2,10,8,7,5};
    //数组长度
    int len = sizeof(arr)/sizeof(arr[0]);
    
    //2.创建函数，实现冒泡排序
    bubblesort(arr, len);
    //3.打印排序后的数组
    print_arr(arr,len);
}
