//
//  dataType.cpp
//  C++ Primer
//
//  Created by Zhuofan Dong on 4/6/22.
//

//给变量分配一个合理的内存空间
#include <iostream>
#include "dataType.hpp"
#include <string>
void dataType(){
    //整形：short(-32768-32767), int, long, long long.
    
    //sizeof关键字：可以统计数据类型所占的内存大小
    short num1 = 10;
    std::cout << sizeof(num1) << std::endl;
    
    //浮点型：表示小数: float(7位有效数字）, double（15到16位有效数字）
    float a = 3.14f;//加f表示这是单精度
    double b = 3.14;//双精度
    
    //字符型
    char ch = 'a';//只能写一个字符，不是字符串，只占一个字节，因为他将对应的ASCII编码放入存储单元
    //a的ASCII码：97；A：65
    
    //转义字符：
    //换行符：\n
    //反斜杠：\\ - 两个反斜杠输出一个反斜杠
    //水平制表符：\t 一个\t占8个位置，使输出对齐
    std::cout << "aaaa\thelloworld" << std::endl;
    std::cout << "aa\thelloworld" << std::endl;
    std::cout << "a\thelloworld" << std::endl;
    
    //c语言字符串型 - 加中括号以及双引号不是单引号
    char str[] = "hello world";
    //c++字符串
    //需要包含一个头文件#include<string>
    std::string str2 = "hello world";
    
    //布尔型 - 一个字节
    bool fool = true;
    
    //数据的输入
    int cat = 0;//initialization
    std::cin >> cat;
    
    //运算符
    //前置递增(++a)，后置递增(a++)：前置先让变量+1然后进行表达式运算；后置先进行表达式运算，再进行变量+1
    
    //三目运算符
    //将a和b做一个比较，将变量大的值赋值给变量c
    int d = 10;
    int e = 20;
    int f = 0;
    f = (d > e ? d : e);
}

void movieScoring(){
    //switch语句
    //给电影进行打分：10/9 经典；8/7 非常好；6/5 一般；5以下 烂片
    //1.提示用户给电影评分
    //2.用户开始进行打分
    //3.根据用户输入的分数来提示用户最后的结果
    std::cout << "请给电影打分：" << std::endl;
    int score = 0;
    std::cin >> score;
    switch (score) {
        case 10:
            std::cout << "经典电影" << std::endl;
            break;
        case 9:
            std::cout << "经典电影" << std::endl;
            break;
        case 8:
            std::cout << "非常好" << std::endl;
            break;
        case 7:
            std::cout << "非常好" << std::endl;
            break;
        case 6:
            std::cout << "一般" << std::endl;
            break;
        case 5:
            std::cout << "一般" << std::endl;
            break;
        default:
            std::cout << "烂片" << std::endl;
            break;
    }
}

void doWhile(){
   //do...while语句
    int num = 0;
    do{
        std::cout << num << std::endl;
        num++;
    }
    while (num < 10);
    //while先判断条件再执行循环语句；do...while先执行循环语句再判断条件
    
    //goto语句
    //...
    goto FLAG;
    
    //...这行代码被跳过，直接转去goto行
    
    FLAG:
    
    std::cout << "..." << std::endl;
    
}

void defArray(){
    /*
     数组特点：
     1.放在一块连续的内存空间中
     2.每个元素都是相同的数据类型
     */
    //定义方式1：数据类型+数组名+[数组长度]
    int arr[5];
    arr[0] = 10;
    arr[1] = 20;
    arr[2] = 30;
    arr[3] = 40;
    arr[4] = 50;
    
    //定义方式2:数据类型+数组名[数组长度] = {值1，值2....}；如果在初始化数据的时候没有全部填写完全数组，系统会自动用0来填充。
    int arr2[5] = {10, 20, 30, 40, 50};
    
    //定义方式3:数据类型+数组名[] = {值1，值2....}
    //定义数组的时候必须有初始长度
    int arr3[] = {90, 80, 70, 60, 50, 40, 30, 20, 10};
    
    //数组名
    //1.整个数组的内存长度
    int s_arr2 = sizeof(arr2);
    int s_arr2_0 = sizeof(arr2[0]);
    
    //2.数组在内存中的首地址
    std::cout << arr2 << std::endl;
    //数组中第一个元素的地址
    std::cout << &arr2[0] << std::endl;
    //他们是相同的
    //数组名是常量，不可以进行赋值
    
    //元素逆置
    int arr4[] = {1, 3, 2, 5, 4};
    
    int start = 0;
    int end = sizeof(arr4)/sizeof(arr4[0]) - 1;//末尾元素下标
    while (start < end) {
        int temp = arr4[start];
        arr4[start] = arr4[end];
        arr4[end] = temp;
        start++;
        end--;
    }
    
    //冒泡排序
    //1.比较相邻的元素，如果第一个比第二个大，就交换他们俩。2.执行完毕后找到第一个最大值。3.重复以上步骤，每次比较次数减1，直到不需要比较。
    int arr5[] = {4,2,8,0,5,7,1,3,9};
    //总共排序轮数为元素个数-1
    for (int i = 0; i < 9 - 1;i++){
        for (int j = 0; j < 9 - i - 1; j++){
            if (arr5[j] > arr5[j+1]){
                int temp = arr5[j];
                arr5[j] = arr5[j+1];
                arr5[j+1] = temp;
            }
        }
    }
    
    //二维数组
    //定义1
    int arr6[2][3];
    arr6[0][0] = 1;
    //...
    
    //定义2
    int arr7[2][3] = {
        {1,2,3},
        {4,5,6}
    };
    
    //定义3
    int arr8[2][3] = {1,2,3,4,5,6};
    
    //定义4
    int arr9[][3] = {1,2,3,4,5,6};
    
}
