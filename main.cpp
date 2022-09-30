//
//  main.cpp
//  黑马c++
//
//  Created by Zhuofan Dong on 4/16/22.
//

#include <iostream>

//4.类和对象
//c++面向对象的三大特性为：封装，继承，多态。万事万物皆为对象，对象上有其属性和行为
//4.1 封装
//1.封装的意义一：将属性和行为作为一个整体，表现生活中的事物
//设计一个圆类，求圆的周长：2*pi*r
const double pi = 3.14;//圆周率是不可以改的

//代表设计一个类，后面紧跟着类名
class Circle{
    //访问权限
    //公共权限
public:
    
    //属性(变量)
    //半径
    int m_r;
    
    //行为
    //获取圆的周长
    double calculatePerimeter(){
        return 2*pi*m_r;
    }
};
//设计一个学生类
class Student{
public: //公共权限
    
    //类中的属性和行为统称为成员
    //属性 成员属性 成员变量
    //行为 成员函数 成员方法
    
    //属性
    std::string m_name;
    int m_id;
    
    //行为
    //显示姓名和学号
    void show(){
        std::cout << m_name << "的学号为： " << m_id << std::endl;
    }
    
    //给姓名赋值
    void setName(std::string name){
        m_name = name;
    }
    
    void setId(int id){
        m_id = id;
    }
};

//封装的意义二：在设计类时，可以把属性和行为放在不同的权限下，加以控制
//访问权限有三种：public公共权限；protected保护权限；private私有权限
//public公共权限：成员类内可以访问，类外也可以访问
//protected保护权限：成员类内可以访问，类外不可以访问 儿子可以访问父亲中的保护内容
//private私有权限：成员类内可以访问，类外不可以访问 儿子不可以访问父亲的私有内容

class Person{
public:
    //公共权限
    std::string name;
    
protected:
    //保护权限
    std::string car;
    
private:
    //私有权限
    int password;
    
public:
    void func(){
        name = "张三";
        car = "拖拉机";
        password = 123456;
    }//类内可以访问
    
};


//2. struct和class的区别
//struct的默认权限是public，class是private

//3.成员属性设置为私有：
//1.可以自己控制读写权限
//2. 对于写权限，我们可以检测数据的有效性
class Person1{
public:
    //设置姓名
    void setName(std::string name){
        m_name = name;
    }
    //获取姓名
    std::string getName(){
        return m_name;
    }
    //获取年龄 只读，年龄必须是0～150
    int getAge(){
        //m_age = 0;//初始化为0岁
        return m_age;
    }
    //设置情人 只写
    void setLover(std::string lover){
        m_lover = lover;
    }
    //设置年龄
    void setAge(int age){
        if (age < 0 || age > 150){
            m_age = 0;
            std::cout << "年龄错误" << std::endl;
            return;
        }//
        m_age = age;
    }

    
private:
    //姓名 可读可写
    std::string m_name;
    //年龄 只读
    int m_age;
    //情人 只写
    std::string m_lover;
    
};

//封装设计案例1
class Cube{
private:
    //属性:长宽高
    double m_l;
    double m_w;
    double m_h;

public:
    //行为
    
    //设置长宽高
    void setL(double l){
        if (l <= 0){
            std::cout << "Invalid Number" << std::endl;
            return;
        }
        m_l = l;
    }
    
    void setW(double w){
        if (w <= 0){
            std::cout << "Invalid Number" << std::endl;
            return;
        }
        m_w = w;
    }
    
    void setH(double h){
        if (h <= 0){
            std::cout << "Invalid Number" << std::endl;
            return;
        }
        m_h = h;
    }
    //获取长宽高
    double getL(){
        return m_l;
    }
    
    double getW(){
        return m_w;
    }
    
    double getH(){
        return m_h;
    }
    
    //获取面积
    double calculateArea(){
        return 2*(m_w*m_l+m_h*m_w+m_l*m_h);
    }
    //获取体积
    double calculateVol(){
        return m_w*m_l*m_h;
    }
    //分别利用全局函数和成员函数判断两个立方体是否相等
    
    //成员函数判断
    bool isSameinClass(Cube &c){
        if (c.getH() == m_h && c.getL() == m_l && c.getW() == m_w){
            return true;
        }
        return false;
    }
    
    
};
//利用全局函数判断两个立方体是否相等
bool isSame(Cube &c1, Cube&c2){
    if (c1.getH() == c2.getH() && c1.getL() == c2.getL() && c1.getW() == c2.getW()){
        return true;
    }
    return false;
}


//4.2 对象的初始化和清理
//4.2.1 构造函数和析构函数
//构造函数：类名(){}
//1.没有返回值也不需要void 2.函数名称与类名相同 3. 构造函数可以有参数，因此可以发生重载 4. 程序在调用对象时候会自动调用构造，无需手动调用，而且只会调用一次
//析构函数：~类名(){}
//1. 没有返回值也不写void 2.函数名称与类名相同，在名称前面加上符号~ 3. 析构函数不可以有参数，因此无法发生重载 4.程序在对象销毁前会自动调用析构无需手动调用，而且只会调用一次

class Person2{
public:
    //1.1构造函数
    Person2(){
        std::cout << "person2 constructor" << std::endl;
    }
    
    //1.2析构函数
    ~Person2(){
        std::cout << "person2 destructor" << std::endl;
    }
    
};

void test01(){//test构造函数
    Person2 p;//程序在调用对象时候会自动调用构造，无需手动调用，而且只会调用一次
    //局部变量存在在栈上，test01执行完毕后系统自动释放这个对象
}

//4.2.2 构造函数的分类和调用
//分类方式：1.按参数分为有参构造和无参构造 2.按类型分为普通构造和拷贝构造
class Person3{
public:
    //1.1构造函数
    Person3(){
        std::cout << "无参（默认）person3 constructor" << std::endl;
    }
    
    Person3(int a){
        age = a;
        std::cout << "有参person3 constructor" << std::endl;
    }
    
    //拷贝构造函数
    Person3(const Person3 &p){//有参
        //将传入的的人身上的所有属性，拷贝到我身上来(谁调用这个拷贝构造函数就拷贝到谁身上)
        int age = p.age;
        std::cout << "有参person3 constructor拷贝构造" << std::endl;
    }
    
    //1.2析构函数
    ~Person3(){
        std::cout << "person3 destructor" << std::endl;
    }
    int age;
};
//调用
//三种调用方式：1.括号法 2.显示法 3.隐式转换法
void test02(){
    //1.括号法
    Person3 p1;//默认构造函数
    Person3 p2(10);
    Person3 p3(p2);//p2和p3的age都是10
    //调用默认构造函数的时候，不要加()，例如：Person3 p1(); ,因为编译器会认为这是一个函数的声明，不会认为在创建对象
    
    //2.显示法
    Person3 p11;
    Person3 p22 = Person3(10);//有参构造
    Person3 p33 = Person3(p22);//拷贝构造
    
    Person3(10);//匿名对象 特点：当前行执行结束后，系统会立即回收匿名对象
    
    //不要利用拷贝构造函数来初始化匿名对象,编译器会认为Person3(p3) == Person3 p3
    //Person3(p3);
    
    //3.隐式转换法
    Person3 p4 = 10;
    Person3 p5 = p4;
}

//4.2.3 拷贝构造函数调用时机
class Person4{
public:
    //1.1构造函数
    Person4(){
        std::cout << "无参（默认）person4 constructor" << std::endl;
    }
    
    Person4(int a){
        age = a;
        std::cout << "有参person4 constructor" << std::endl;
    }
    
    //拷贝构造函数
    Person4(const Person4 &p){//有参
        //将传入的的人身上的所有属性，拷贝到我身上来(谁调用这个拷贝构造函数就拷贝到谁身上)
        int age = p.age;
        std::cout << "有参person4 constructor拷贝构造" << std::endl;
    }
    
    //1.2析构函数
    ~Person4(){
        std::cout << "person4 destructor" << std::endl;
    }
    int age;
};
//1.使用一个已经创建完毕的对象来初始化一个新对象
void test03(){
    Person4 p1(20);
    Person4 p2(p1);
    
}
//2.值传递的方式来给函数参数传值
void dowork(Person4 p){
    
}

void test03_1(){
    Person4 p;
    dowork(p);
}

//3.值方式返回局部对象
Person4 dowork2(){
    Person4 p1;
    return p1;
}

void test03_2(){
    Person4 p = dowork2();
}

//4.2.4构造函数调用规则
//默认情况下，c++编译器至少给一个类添加三个函数：默认构造函数（空实现），默认析构函数（空实现），默认拷贝构造函数（值拷贝）
//如果用户定义有参构造函数,编译器就不再提供默认构造，依然提供拷贝构造（不能调用默认构造）
//如果用户定义拷贝构造函数，编译器就不再提供其他的函数了
class Person5{
public:
    //1.1构造函数
    Person5(){
        std::cout << "无参（默认）person5 constructor" << std::endl;
    }
    
    Person5(int a){
        age = a;
        std::cout << "有参person5 constructor" << std::endl;
    }
    
    //拷贝构造函数
//    Person5(const Person5 &p){//有参
//        //将传入的的人身上的所有属性，拷贝到我身上来(谁调用这个拷贝构造函数就拷贝到谁身上)
//        int age = p.age;
//        std::cout << "有参person5 constructor拷贝构造" << std::endl;
//    }
//
    //1.2析构函数
    ~Person5(){
        std::cout << "person5 destructor" << std::endl;
    }
    int age;
};

void test04(){
    Person5 p;
    p.age = 18;
    
    Person5 p2(p);
    std::cout << "age is " << p2.age << std::endl;
}


//4.2.5 深拷贝和浅拷贝
class Person6{
public:
    //1.1构造函数
    Person6(){
        std::cout << "无参（默认）person6 constructor" << std::endl;
    }
    
    Person6(int a, int height){
        age = a;
        m_height = new int(height);//堆区开辟的内存需要手动在析构函数释放
        std::cout << "有参person6 constructor" << std::endl;
    }
    
    //拷贝构造函数
    Person6(const Person6 &p){//有参
        //将传入的的人身上的所有属性，拷贝到我身上来(谁调用这个拷贝构造函数就拷贝到谁身上)
        int age = p.age;
        //m_height = p.m_height;编译器默认实现这行代码
        
        //深拷贝操作
        m_height = new int(*p.m_height);//深拷贝
        std::cout << "有参person6 constructor拷贝构造" << std::endl;
    }
    
    

    ~Person6(){
        if (NULL != m_height){
            delete m_height;
            m_height = nullptr;
        }
        std::cout << "person6 destructor" << std::endl;
    }
    int age;
    int *m_height;
};
void test05(){
    Person6 p1(18,160);//浅拷贝
    std::cout << "p1's age is " << p1.age << *p1.m_height << std::endl;
    
    Person6 p2(p1);
    std::cout << "p2's age is " << p2.age << *p2.m_height << std::endl;
}//栈区先进后出，所以p2的析构函数先执行，由于拷贝函数将p1的m_height的地址拷贝给了p2，p2的析构函数在释放内存时将m_height中的数据释放完毕了，但是之后p1又执行了一次析构函数并且也释放了一次m_height的内存，导致p1非法重复释放堆区内存。
//浅拷贝的问题需要利用深拷贝解决

//4.2.6 初始化列表
//用来初始化属性
class Person_ini{
public:
    //传统初始化
    
//    Person_ini(int a, int b, int c){
//        ma = a;
//        mb = b;
//        mc = c;
//    }
    Person_ini(int a, int b, int c):ma(a),mb(b),mc(c){
        
    }
    
    int ma;
    int mb;
    int mc;
    
    
};
void test06(){
    Person_ini p(10,20,30);

}

//4.2.7 类对象作为类成员
//类中的成员是另一个类的对象
//class A{};
//class B{
//      A a;
//};

class Phone{
public:
    
    Phone(std::string pname){
        m_pname = pname;
    }
    
    std::string m_pname;
};

class Person_class{
public:
    Person_class(std::string name, std::string pname):m_name(name),m_phone(pname){}
    
    //name
    std::string m_name;
    //cell phone
    //Phine m_phone = pname;
    Phone m_phone;
};

//当其他类对象作为本类成员，构造时先构造类对象，再构造自身
//析构顺序与构造相反

void test07(){
    Person_class p("san","apple");
    
    std::cout << p.m_name << std::endl;
}


//静态成员
//1.静态成员变量
//所有对象共享同一份数据
//在编译阶段分配内存（全局区）
//类内声明，类外初始化

class Person_static{
public:
    
    
    static int a;
private:
    //静态成员变量也是有访问权限的
    static int b;
};

int Person_static::a = 100;//类外初始化
int Person_static::b = 100;


void test08(){
    Person_static p;
    Person_static p2;
    
    p2.a = 200;
    
    std::cout << p2.a << std::endl;//此时这个数变成200了；因为所有对象共享一份数据，这个数据改了类内也改了
}

void test08_1(){
    //静态成员变量不属于某个对象上，所有对象都共享同一份数据
    //因此静态成员变量有两种访问方式
    //1.通过对象进行访问
    Person_static p;
    std::cout << p.a << std::endl;
    
    //2.通过类名进行访问
    std::cout << Person_static::a << std::endl;
    //std::cout << Person_static::b << std::endl;类外私有成员变量访问不到
}

//静态成员函数
//所有对象共享同一个函数
//静态成员函数只能访问静态成员变量
class Person_static1{
public:
    //静态成员函数
    static void func(){
        aa = 200;
        //bb = 200;静态成员函数不可以访问非静态成员变量,无法区分到底是哪个对象的调用
        std::cout << "static void调用：" << std::endl;
    }
    static int aa;
    int bb;
    
private:
    static void func2(){
        std::cout << "statics func" << std::endl;//类外不可以访问私有静态成员函数
    }
    
};

int Person_static1::aa = 100;

void test08_2(){
    //1.通过对象访问
    Person_static1 p;
    p.func();
    
    //2.通过类名访问
    Person_static1::func();
    
}

//4.3 c++对象模型和this指针
//类内的成员变量和成员函数分开储存
//只有非静态成员变量才属于类的对象
class Person_{
    int m_a;//非静态
    static int m_b;
    void func(){
        
    }
    
    static void func1(){
        
    }
    
};

void test09(){
    Person_ p;
    std::cout << sizeof(p) << std::endl;//空对象占用内存空间为1，因为编译器会给每个空对象也分配一个字节的空间，是为了区分空对象占内存的位置
    //每个空对象也应该有一个独一无二的内存地址
    
    Person_ p1;
    std::cout << sizeof(p1) << std::endl; //类内int m_a; 4字节
    
    Person_ p2;
    std::cout << sizeof(p2) << std::endl; //类内int m_a; 4字节，加上static成员变量和成员函数后还是4字节
    
}

//this指针
//1.解决名称冲突，比如多同类型对象调用同一块代码 2.返回对象本身用*this
//this指针指向被调用的成员函数所属的对象的地址
class Person_this{
public:
    Person_this(int age){
        this->age = age;//this指针指向test09_1里的p
    }
    
    void personAddAge(Person_this &p){
        this->age += p.age;
    }
    
    Person_this& personAddAge1(Person_this &p){//用引用是因为返回的是调用对象本体，因为引用就是给调用对象起别名
        this->age += p.age;
        
        return *this;//被调用对象的本体
    }

    //以下就是返回一个值，如果进行p2.personAddAge1(p1).personAddAge1(p1).personAddAge1(p1).personAddAge1(p1);操作的话，编译器会在每次调用personAddAge1函数时创建一个新的对象，所以原来的对象，也就是p2，不会改变
//    Person_this personAddAge1(Person_this &p){//用引用是因为返回的是调用对象本体，因为引用就是给调用对象起别名
//        this->age += p.age;
//
//        return *this;//被调用对象的本体
//    }
    
    int age;
};
void test09_1(){
    Person_this p(18);

}
void test09_2(){
    Person_this p1(10);
    
    Person_this p2(18);
    
    p2.personAddAge(p1);
    
    std::cout << p2.age << " is the age of p2." << std::endl;
    
    //p2.personAddAge(p1).personAddAge(p1) ,因为personAddAge是void函数，所以p2.personAddAge(p1)返回的不是对象
    
    p2.personAddAge1(p1).personAddAge1(p1).personAddAge1(p1).personAddAge1(p1);
}

//4.3.3 空指针调用成员函数
class Person_null{
public:
    void show(){
        std::cout << "this is person_null class" << std::endl;
        
    }
    
    void showage(){
        
        if(this == NULL){
            return;
        }
        
        std::cout << "the age is " << m_age << std::endl;
    }//m_age等于this->m_age
    
    int m_age;
};

void test10(){
    Person_null *p = NULL;
    
    p->show();
    
    //p->showage();报错，因为指针为空所以里面也没有相应的属性；
    
}

//4.3.4 const修饰成员函数
//常函数
class Person_const{
public:

    void showPerson() const { //const Person_const * const this
        //m_a = 100；
        m_b = 19;
    }
    
    void func(){
        
    }
    
    int m_a;
    mutable int m_b;//特殊变量，即使在常函数中
};

//常对象：常对象只能调用常函数
void test11(){
    const Person_const p{};//在对象前加const，变为常对象
    //p.m_a = 100;报错，因为这个对象的属性不可以修改
    p.m_b = 100;//因为m_b有mutable修饰，在常函数和常对象下都可以修改
    
    p.showPerson();
    //p.func();常对象只能调用常函数
}

//4.4 友元
//4.4.1
class Building{
    friend void goodgay(Building *building);//goodgay全局函数是这个类的好朋友，可以访问私有成员
public:
    std::string m_sittingroom;
    
    Building(){
        m_sittingroom = "sittingroom";
        m_bedroom = "bedroom";
    }
    
private:
    std::string m_bedroom;
};

void goodgay(Building *building){
    std::cout << building->m_sittingroom << std::endl;
    
    //std::cout << building->m_bedroom << std::endl;私有函数不能被访问，当加了友元后才能访问私有成员
}

void test12(){
    Building building;
    goodgay(&building);
}

//类做友元

class Building1;
class goodgay1{
public:
    goodgay1();
    Building1 *building;
    void visit();//参观函数，访问building中的属性
};

class Building1{
    
    friend class goodgay1;//goodgay1是这个类的好朋友，可以访问私有属性
    
public:
    
    Building1();
    std::string m_sittingroom;

private:
    std::string m_bedroom;
};

Building1::Building1(){//类外实现成员函数
    m_bedroom = "bedroom";
    m_sittingroom = "sittingroom";
}

goodgay1::goodgay1(){
    building = new Building1;
}

void goodgay1::visit(){
    std::cout << "friend is entering " << building->m_sittingroom << std::endl;
    
    std::cout << "friend is entering " << building->m_bedroom << std::endl;
}

void test13(){
    goodgay1 gg;
    gg.visit();
    
}

//成员函数做友元
class Building2;

class goodgay2{
public:
    goodgay2();
    Building2 *building;
    void visit();//参观函数，访问building中的属性
    void visit2();//让这个函数不可以访问building中的私有成员
};

class Building2{
    friend void goodgay2::visit();
    
public:
    
    Building2();
    std::string m_sittingroom;

private:
    std::string m_bedroom;
};

Building2::Building2(){
    m_sittingroom = "sittingroom";
    
    m_bedroom = "bedroom";
}

goodgay2::goodgay2(){
    building = new Building2;
}
void goodgay2::visit(){
    std::cout << "friend is entering " << building->m_sittingroom << std::endl;
    std::cout << "friend is entering " << building->m_bedroom << std::endl;
}

void goodgay2::visit2(){
    std::cout << "friend is entering " << building->m_sittingroom << std::endl;
    //std::cout << "friend is entering " << building->m_bedroom << std::endl;
}

void test14(){
    goodgay2 gg;
    gg.visit();
    gg.visit2();
}

//4.5 运算符重载
//4..5.1 加号运算符重载

class Person_operator{
public:
    //成员函数重载+号
//    Person_operator operator+(Person_operator &p){
//        Person_operator temp;
//        temp.m_a = this->m_a + p.m_a;
//        temp.m_b = this->m_b + p.m_b;
//        return temp;
//    }
    //成员函数的本质调用
    //Person_operator p3 = p1.operator+(p2);
    //全局函数的本质调用
    //Person_operator p3 = p1.operator+(p1,p2);
    int m_a;
    int m_b;
};

//全局函数重载
Person_operator operator+(Person_operator &p1, Person_operator &p2){
    Person_operator temp;
    temp.m_a = p1.m_a + p2.m_a;
    temp.m_b = p1.m_b + p2.m_b;
    return temp;
}

//函数重载的版本,运算符重载也能发生函数重载
Person_operator operator+(Person_operator &p1, int a){
    Person_operator temp;
    temp.m_a = p1.m_a;
    temp.m_b = p1.m_b + a;
    return temp;
}


void test15(){
    Person_operator p1;
    
    Person_operator p2;
    
    p1.m_a = 10;
    p2.m_a = 20;
    p1.m_b = 30;
    p2.m_b = 40;
    
    Person_operator p3 = p1 + p2;
}


//4.5.2 左移运算符重载，可以输出自定义的运算符
class Person_leftoperator{
    friend std::ostream &operator<<(std::ostream &cout, Person_leftoperator p);
    
    
public:
    //利用成员函数重载左移运算符
    //不会利用成员函数去重载左移运算符
//    void operator<<(){
//
//    }
    
    Person_leftoperator(int a, int b){
        m_a = a;
        m_b = b;
    }
    
private:
    int m_a;
    int m_b;
};
//只能利用全局函数去做左移运算符重载
std::ostream &operator<<(std::ostream &cout, Person_leftoperator p){
    std::cout << p.m_a << p.m_b;
    return cout;
}

void test15_1(){
    Person_leftoperator p(10,10);
    
    std::cout << p << std::endl;
}

//4.5.3 递增运算符重载
//自定义的整型
class myinteger{
    friend std::ostream &operator<<(std::ostream &cout, myinteger myint);
public:
    myinteger(){
        m_int = 0;
    }
    
    //重载前置++运算符
    myinteger& operator++(){//返回引用是为了一直操作同一个对象
        m_int++;
        return *this;//将自身返回
    }
    
    //重载后置++运算符
    //void operator++(int) int代表占位参数，可以用于区分前置和后置
    myinteger operator++(int){
        //先记录当时结果
        myinteger temp = *this;//局部变量函数运行完就会释放，如果返回引用的话再次调用这个函数就会导致非法操作
        //后 递增
        m_int++;
        //最后将结果做返回
        return temp;
    }
    
private:
    int m_int;
};

std::ostream &operator<<(std::ostream &cout, myinteger myint){
    std::cout << myint.m_int;
    return cout;
}

void test15_2(){
    myinteger myint;
    
    std::cout << ++myint << std::endl;
    
    std::cout << myint++ << std::endl;
}

//4.5.4 赋值运算符重载

class Person_operator_equal{
public:
    Person_operator_equal(int age){
        m_age = new int(age);
    }
    
    ~Person_operator_equal(){
        if (m_age != NULL){
            delete m_age;
            m_age = NULL;
        }
    }
    
    //重载赋值运算符
    Person_operator_equal& operator=(Person_operator_equal &p){
        //编译器提供的是浅拷贝
        //m.age = p.m_age;
        
        //应该前判断是否有属性在堆区，如果有先释放干净，然后再深拷贝
        if (m_age !=NULL){
            delete m_age;
            m_age = NULL;
        }
        
        m_age = new int(*p.m_age);//深拷贝
        return *this;
    }
    
    int *m_age;
};

void test15_3(){
    Person_operator_equal p1(18);
    
    Person_operator_equal p2(20);
    
    p2 = p1;//赋值操作,因为p1和p2指向同一块堆区内存，会导致p2 p1重复释放内存而导致程序崩溃
    
    Person_operator_equal p3(30);
    
    p3 = p2 = p1;//连续赋值
    //
}

//4.5.5 关系运算符的重载
class Person_operator_relation{
public:
    Person_operator_relation(std::string name, int age){
        m_age = age;
        m_name = name;
    }
    
    //==重载
    bool operator==(Person_operator_relation &p){
        if (this->m_age == p.m_age && this->m_name == p.m_name){
            return true;
        }
        return false;
    }
    
    std::string m_name;
    int m_age;
};

void test15_4(){
    Person_operator_relation p1("tom",18);
    
    Person_operator_relation p2("tom",18);
    
    if (p1 == p2){
        std::cout << "p1 p2 are equal" << std::endl;
    };
    
}

//4.5.6函数调用运算符重载
class myprint{
public:
    //重载的函数调用运算符
    void operator()(std::string test){
        std::cout << test << std::endl;
    }

};

void test15_5(){
    myprint my_print;
    my_print("hello world");//因为用起来非常像函数调用，因此称为仿函数
}

class myadd{
public:
    int operator()(int num1, int num2){
        return num1 + num2;
    }
};

void test15_6(){
    myadd my_add;
    
    my_add(10,10);
    
    //匿名函数对象
    myadd()(10,10);//myadd()匿名对象
}





int main(int argc, const char * argv[]){
    //4.1.1
    //通过圆类来创建一个具体的圆（对象）
    Circle c1;//实例化
    //给这个圆的属性赋值
    c1.m_r = 10;
    std::cout << "圆的周长为： " << c1.calculatePerimeter() << std::endl;
    
    //创建一个具体的学生
    Student s1;
    //给s1对象进行属性赋值操作
    s1.m_name = "张三";
    s1.setName("张三");
    s1.setId(1);
    s1.m_id = 1;
    s1.show();
    
    //访问权限
    Person p1;
    p1.name = "李四";
    //p1.car和p1.password是访问不到的
    
    //4.1.2
    //struct的默认权限是public，class是private
    
    //4.1.3
    Person1 m_p;
    m_p.setName("Alex");
    std::cout << m_p.getName() << std::endl;
    
    m_p.setAge(1000);
    
    std::cout << m_p.getAge() << std::endl;//只读
    
    m_p.setLover("Annie");//只写权限
    //有效性
    m_p.setAge(1000);
    
    //封装设计案例1
    //cube1
    Cube cube1;
    cube1.setH(10);
    cube1.setL(10);
    cube1.setW(10);
    
    std::cout << "The area and volume of cube1 is: " << cube1.calculateArea() << " and " << cube1.calculateVol() << std::endl;
    
    //cube2
    Cube cube2;
    cube2.setH(10);
    cube2.setL(10);
    cube2.setW(10);
    
    //全局函数判断
    std::cout << isSame(cube1, cube2) << std::endl;
    //成员函数判断
    std::cout << cube2.isSameinClass(cube1) << std::endl;
    
    //4.2 对象的初始化和清理
    test01();//test构造函数
    
    Person2 p;//只会调用构造函数，在程序销毁时会调用析构
    
    //4.2.2 构造函数的分类和调用
    test02();
    
    //4.2.3 拷贝构造函数的调用时机
    test03();
    
    //4.2.4构造函数调用规则
    test04();
    
    //4.2.5 深拷贝和浅拷贝
    
    //4.2.7类对象作为类成员
    test07();
    
    //4.2.8 静态成员
    test08();
    test08_1();
    
    //4.3 c++对象模型和this指针
    test09();
    test09_2();
    
    //4.4 友元
    test12();
    
    //4.4.2
    test13();
    
    //4.5函数运算符重载
    test15();
    
    
    return 0;
}
