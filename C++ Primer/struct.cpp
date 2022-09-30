//
//  struct.cpp
//  C++ Primer
//
//  Created by Zhuofan Dong on 4/9/22.
//

#include "struct.hpp"
#include<iostream>
#include <string>
//结构体属于用户自定义的数据类型
/*
 struct 结构体名 {结构体成员列表}{
    语句
 }
 */
//1.创建学生数据类型：姓名，年龄，分数

struct Student{
    //成员列表
    
    //姓名
    std::string name;
    
    //年龄
    int age;
    
    //分数
    int score;
}s3;//2.3 顺便创建结构体变量

//2.通过学生类型创建具体学生
//2.1 struct Student s1
//2.2 struct Student s2 = {...}
//2.3 在定义结构体时顺便创建结构体变量

void main_function(){
    //2.1
    struct Student s1;
    //给s1属性赋值，通过.访问结构体变量中的属性
    s1.name = "张三";
    s1.age = 18;
    s1.score = 100;
    
    //2.2
    struct Student s2 = {"李四", 19, 80};
    
    //2.3
    s3.name = "王五";
    s3.age = 20;
    s3.score = 60;
    
    //一般用1或者2
    //struct在创建变量的时候可以忽略
    Student s4;
    s4.name = "..";
    s4.age = 21;
    s4.score = 50;
}

//结构体数组
//1.定义结构体
//struct Student{...}见顶部
//2.创建结构体数组
void struct_arr(){
    struct Student stuArr[3] = {
        {"张三", 18, 100},
        {"李四", 28, 99},
        {"王五", 38, 66}
    };
    //3.给结构体数组中的元素赋值
    stuArr[2].name = "赵六";
    stuArr[2].age = 80;
    stuArr[2].score = 60;
    //4.遍历
    //for循环
}

//结构体指针，利用操作符->
struct student{
    std::string name;
    int age;
    int score;
};

void struct_pointers(){
    //1.创建学生结构体变量
    struct student s = {"张三", 18, 100};
    //2.通过指针指向结构体变量
    student *p = &s;//int *p = &s会报错，因为左右两边的数据类型不一致
    
    //3.通过指针访问结构体变量中的数据
    std::cout << p->age << p->name << p->score << std::endl;
}


//结构体嵌套结构体
struct teacher{
    int id;
    std::string name;
    int age;
    struct student stu;
};

void struct_qiantao(){
    teacher t;
    t.id = 10000;
    t.name = "老王";
    t.age = 50;
    //结构体嵌套结构体
    t.stu.name = "小王";
    t.stu.age = 20;
    t.stu.score = 60;
}

//结构体做函数参数
//1.值传递
void printStudent01(struct student s){
    s.age = 100;//不会修改实参
    std::cout << s.age << s.name << s.score << std::endl;
}
//地址传递
void printStudent02(struct student *p){
    p->age = 200;//会修改实参
    std::cout << p->age << p->name << p->score << std::endl;
}

void struct_parameter(){
    struct student s;
    s.name = "张三";
    s.age = 20;
    s.score = 85;
    
    printStudent01(s);
    printStudent02(&s);
}
//不想修改主函数内容，用值传递，反之用地址传递

//结构体中const的使用场景

//使用值传递会将结构体内的数据全部拷贝一份，数据量大的话会造成空间不足；使用地址传递只需要占一个指针的空间（4个字节）
void printStudent (const student *s){
    s->age = 200;//会修改实参,但是如果传递的参数加上const，一旦有修改的操作就会报错，可以防止我们的错误操作，比如这个例子里程序就报错了
    std::cout << s->age << s->name << s->score << std::endl;
}

void struct_const(){
    struct student s = {"张三", 15, 70};
    
}


