//
//  main.cpp
//  黑马c++继承多态
//
//  Created by Zhuofan Dong on 4/27/22.
//

#include <iostream>
#include <fstream>
//4.6 继承：减少重复代码（公共类）
//4.6.1
//下级别的成员除了拥有上一级的共性，还有自己的特点

//普通实现页面

//不用继承写页面
//class java{
//public:
//    void header(){
//        std::cout << "首页，公开课.." << std::endl;
//    }
//
//    void footer(){
//        std::cout << "帮助中心，交流合作.." << std::endl;
//    }
//
//    void content(){
//        std::cout << "java学科视频" << std::endl;
//    }
//};
//
//class python{
//public:
//    void header(){
//        std::cout << "首页，公开课.." << std::endl;
//    }
//
//    void footer(){
//        std::cout << "帮助中心，交流合作.." << std::endl;
//    }
//
//    void content(){
//        std::cout << "python学科视频" << std::endl;
//    }
//};
//
//class cpp{
//public:
//    void header(){
//        std::cout << "首页，公开课.." << std::endl;
//    }
//
//    void footer(){
//        std::cout << "帮助中心，交流合作.." << std::endl;
//    }
//
//    void content(){
//        std::cout << "c++学科视频" << std::endl;
//    }
//};
//
//void test01(){
//    std::cout << "java" << std::endl;
//
//    java ja;
//    ja.header();
//    ja.footer();
//    ja.content();
//
//    std::cout << "==============" << std::endl;
//
//    python py;
//    py.content();
//    py.footer();
//    py.header();
//
//    std::cout << "==============" << std::endl;
//
//    cpp cp;
//    cp.content();
//    cp.footer();
//    cp.header();
//}

//继承写页面
//语法：class子类（派生类） : 继承方式 父类（基类）
//公共页面
class basePage{
public:
    void header(){
        std::cout << "首页，公开课.." << std::endl;
    }
    void footer(){
        std::cout << "帮助中心，交流合作.." << std::endl;
    }
    
    
};

class java: public basePage{//继承
public:
    void content(){
        std::cout << "java" << std::endl;
    }
};

//4.6.2 继承方式
//public, private, protected
//公共继承
class base1{
public:
    int m_a;
private:
    int m_c;
protected:
    int m_b;
};

class son1 : public base1{
public:
    void func(){
        m_a = 10;//父类中公共权限成员到子类中依然是公共权限
        m_b = 10;//父类中保护权限成员到子类中依然是保护权限
        //m_c = 10; 父类中的私有成员子类访问不到
    }
};

void test02(){
    son1 s1;
    s1.m_a = 10;
    //s1.m_b = 10;类内保护权限，类外访问不到
}

class son2 : protected base1{
public:
    void func(){
        m_a = 10;//父类中公共权限成员到子类中是保护权限
        m_b = 10;//父类中保护权限成员到子类中依然是保护权限
        //m_c = 10; 父类中的私有成员子类访问不到
    }
};

void test02_1(){
    son2 s2;
    //s2.m_a = 10;类内保护权限，类外访问不到
    //s2.m_b = 10;类内保护权限，类外访问不到
}

class son3 : private base1{
public:
    void func(){
        m_a = 10;//父类中公共权限成员到子类中是私有权限
        m_b = 10;//父类中保护权限成员到子类中是私有权限
        //m_c = 10; 父类中的私有成员子类访问不到
    }
};

void test02_2(){
    son3 s3;
    //s3.m_a = 10;类内私有权限，类外访问不到
    //s3.m_b = 10;类内私有权限，类外访问不到
}

//4.6.3 继承中的对象模型
class base{
public:
    int m_a;
protected:
    int m_b;
private:
    int m_c;
};

class son : public base{
public:
    int m_d;
};

void test03(){
    std::cout << sizeof(son) << std::endl;//16字节，父类中所有非静态成员属性都会被子类继承下去
    //父类中私有成员属性是被编译器给隐藏了，但是会被继承下去
}

//4.6.4 继承中构造和析构顺序
//构造是先父再子，析构的顺序与构造相反

//4.6.5 继承同名成员处理方式
class base2{
public:
    base2(){
        m_a = 100;
    }
    
    void func(){
        std::cout << "base2" << std::endl;
    }
    
    int m_a;
};

class son4: public base2{
public:
    son4(){
        m_a = 200;
    }
    
    void func(){
        std::cout << "son4" << std::endl;
    }
    
    int m_a;
};

void test04(){
    son4 s4;
    
    std::cout << s4.m_a << std::endl;
    
    std::cout << s4.base2::m_a << std::endl;//如果通过子类对象访问父类中同名成员需要加作用域符
    
    s4.func();
    
    s4.base2::func();//同名函数同理
    
    //如果子类中出现和父类同名的成员函数，子类的同名成员会隐藏父类中所有同名成员函数
    //如果想访问到父类中被隐藏的同名成员函数，需要加作用域符
}

//4.6.6 继承同名静态成员处理方式
//静态成员和非静态成员出现同名，处理方式一样，即加作用域符
class base_static{
public:
    static int m_a;
    static void func(){
        std::cout << "base_static" << std::endl;
    }
};

int base_static::m_a = 100;

class son_static: public base_static{
public:
    static int m_a;
    static void func(){
        std::cout << "son_static" << std::endl;
    }
};

int son_static::m_a = 200;

//同名静态成员属性
void test05_1(){
    //1.通过对象访问
    son_static s_s;
    std::cout << s_s.m_a << std::endl;
    base_static b_s;
    std::cout << s_s.m_a << std::endl;
    
    //2.通过类名访问
    std::cout << son_static::m_a << std::endl;
    std::cout << son_static::base_static::m_a << std::endl;//通过子类访问父类成员属性
    
}

//同名静态函数
void test05_2(){
    son_static s_s1;
    base_static b_s1;
    s_s1.func();
    s_s1.base_static::func();
    
    son_static::func();
    son_static::base_static::func();
    
}

//4.6.7多继承语法
//语法： class 子类: 继承方式 父类1, 继承方式 父类2..... {};

//4.6.8 菱形继承
//两个派生类继承同一个基类，又有某个类同时继承这两个派生类
//动物类
class animal{
public:
    int m_age;
};

//利用虚继承解决菱形继承问题
//继承之前 加上关键字 virtual， 变成虚继承
//animal类称为 虚基类

//羊类
class sheep:virtual public animal{};
//驼类
class tuo:virtual public animal{};
//羊驼类
class sheeptuo:public sheep, public tuo{};

void test06(){
    sheeptuo st;
    //st.m_age = 18;不明确
    st.sheep::m_age = 18;
    st.tuo::m_age = 28;
    //当菱形继承的时候，两个父类拥有相同数据，需要加以作用域区分
    
    //这份数据我们知道只要有一份就可以了，菱形继承导致数据有两份，资源浪费
    //利用virtual
}
//virtual底层实现
//继承了子类的虚指针，通过虚指针的偏移量能够找到对应的属性，此属性只有一份




//============================================================

//多态
//分为静态多态和动态多态
//静态多态：函数重载 和 运算符重载，它的函数地址早绑定，编译阶段确定函数地址
//动态多态：派生类和虚函数实现运行时多态，它的地址晚绑定，运行阶段确定函数地址

//动物类
class animal1{
public:
    //虚函数
    virtual void speak(){
        std::cout << "speak" << std::endl;
    }
};

//猫类
class cat: public animal1{
    void speak(){
        std::cout << "cat speak" << std::endl;
    }
};

class dog: public animal1{
public:
    void speak(){
        std::cout << "dog speak" << std::endl;
    }
};

//执行说话的函数
//地址早绑定，在编译阶段确定函数地址
//如果想执行让猫说话，那么函数的地址就不能提前绑定，需要在运行的阶段进行绑定，地址晚绑定

//动态多态的满足条件
//1.有继承关系
//2.子类要重写父类的虚函数，重写 函数返回值类型 函数名 参数列表 都完全相同

//动态多态使用
//父类的指针或者引用指向子类的对象

void dospeak(animal1 &animal1){//animal1 animal1 = cat;
    animal1.speak();
}

void test07(){
    cat c;
    dospeak(c);
    
    dog d;
    dospeak(d);
    
}

//4.7.1 多态的原理剖析
//加了virtual后，animal1类从1个字节变成4个字节，因为内部结构多了一个指针，vfptr虚函数指针，这个指针指向vftable虚函数表，表的内部记录虚函数的地址
//cat类继承animal1之后，虚函数和虚函数表也继承到自己的虚函数表内来，当子类重写父类的虚函数，子类中的虚函数表内部会替换成子类的虚函数地址
//&animal1::speak 当重写后 -> &cat::speak
//当父类的指针或者引用指向子类对象的时候，发生多态
//animal1 &animal = cat;
//animal.speak();

//4.7.2 多态案例 计算器类
//普通写法
class calculator{
public:
    int m_num1;
    int m_num2;
    float getResult(std::string oper){
        if (oper == "+"){
            return m_num1 + m_num2;
        }
        else if (oper == "-"){
            return m_num1 - m_num2;
        }
        else if (oper == "*"){
            return m_num1 * m_num2;
        }
        else
            return m_num1/m_num2;
    }
};

void test08(){
    calculator cal;
    cal.m_num1 = 10;
    cal.m_num2 = 10;
    cal.getResult("+");
}

//利用多态
//实现计算器抽象类
class abCalculator{
public:
    int m_num1;
    int m_num2;
    virtual int getResult(){
        return 0;
    }
};

//
class addCalculator: public abCalculator{
public:
    int getResult(){
        return m_num1 + m_num2;
    }
};

class minusCalculator: public abCalculator{
public:
    int getResult(){
        return m_num1 - m_num2;
    }
};

class timesCalculator: public abCalculator{
public:
    int getResult(){
        return m_num1 * m_num2;
    }
};

void test08_1(){
    abCalculator *abc = new addCalculator;
    abc->m_num1 = 10;
    abc->m_num2 = 10;
    abc->getResult();
    
    delete abc;
}

void test07_1(){
    std::cout << sizeof(animal1) << std::endl;
}

//4.7.3 纯虚函数和抽象类
//纯虚函数语法： vortual 返回值类型 函数名 (参数列表) = 0；
//当类中有了纯虚函数，这个类也称为抽象类
//特点：无法实例化对象，子类必须重写抽象类中的纯虚函数，否则也属于抽象类
class virtual_base{
public:
    //纯虚函数
    //只要有一个纯虚函数，这个类称为抽象类
    //1.无法实例化对象：
    //virtual_base vb; 报错！因为抽象类无法实例化对象
    //2.抽象类的子类必须重写父类中的纯虚函数，否则也属于抽象类
    virtual void func() = 0;
};

//使用纯虚函数的意义在于想用子类重写父类中的纯虚函数

class virtual_son: public virtual_base{
public:
    virtual void func(){
        std::cout << "virtual_son" << std::endl;
    }
};

//4.7.5虚析构和纯虚析构
//可以解决父类指针释放子类对象
//当子类有对象属性开辟到堆区，才需要使用虚析构和纯虚析构来进行父类指针释放子类对象
//子类中没有堆区数据，可以不写为虚析构和纯虚析构

class animal2{
public:
    animal2(){
        std::cout << "animal2构造" << std::endl;
    }
    //纯虚函数
    virtual void speak() = 0;
    
//    virtual ~animal2(){
//        std::cout << "animal2析构" << std::endl;
//    }
    
    //纯虚析构
    virtual ~animal2() = 0;
};
//因为父类有可能有堆区内存也需要释放，用纯虚析构的话是不能释放父类中的堆区内存的，需要在全局区将纯虚函数的内部实现
//有了纯虚析构之后，这个类也属于抽象类，无法实例化对象

animal2::~animal2(){
    std::cout << "animal2析构" << std::endl;
}

class cat1: public animal2{
public:
    void speak(){
        std::cout << "cat speak" << std::endl;
    }
    
    std::string *m_name;
    cat1(std::string name){
        std::cout << "cat1构造" << std::endl;
        m_name = new std::string(name);
        
    }
    
    ~cat1(){
        if (m_name != NULL){
            std::cout << "cat1析构" << std::endl;
            delete m_name;
            m_name = NULL;
        }
    }
};

void test09(){
    animal2 *anim = new cat1("tom");
    anim->speak();
    //父类指针在析构的时候，不会调用子类中的析构函数，导致子类如果有堆区属性，出现内存泄漏
    //解决办法就是在父类析构函数前加一个virtual,成为虚析构函数
    delete anim;
}

//5 文件操作
//需要包含头文件<fstream>
//文件类型分为两种：文本文件，二进制文件
//操作文件三大类：
//ofstream写操作
//ifstream读操作
//fstream读写操作
//5.1 文本文件
//5.1.1 写文件
//1.包含头文件
//2.创建流对象 ofstream ofs
//3.打开文件 ofs.open("文件路径",打开方式)
/*
 打开方式：
 ios::in 为读文件而打开文件
 ios::out 为写文件而打开文件
 ios::ate 初始位置：文件尾
 ios::app 追加方式写文件
 ios::trunc 如果文件存在先删除，再创建
 ios::binary 二进制方式
 */
//4.写数据 ofs << "写入的数据"
//5.关闭文件 ofs.close()
//文件打开方式可以配合使用，利用|操作符

void test10(){
    //创建流对象
    std::ofstream ofs;
    //指定打开方式
    ofs.open("test.txt");
    //写内容
    ofs << "name" << std::endl;
    ofs << "sex" << std::endl;
    ofs.close();
}

//5.1.2 读文件
//1.包含头文件
//2.创建流对象 ifstream ifs
//3.打开文件 ifs.open("文件路径",打开方式),并且判断文件是否打开成功
//4.读数据 四种方式读取
//5.关闭文件 ifs.close()
void test10_1(){
    //包含头文件
    
    //创建流对象
    std::ifstream ifs;
    //打开文件并判断是否打开成功
    ifs.open("test.txt");
    if (!ifs.is_open()) {
        std::cout << "falied to open" << std::endl;
        return;
    }
    //读数据
    //第一种
//    char buf[1024] = {0};
//    while (ifs >> buf) {
//        std::cout << buf << std::endl;
//    }
    
    //第二种
//    char bu[1024] = {0};
//    while (ifs.getline(bu,sizeof(bu))) {
//        std::cout << bu << std::endl;
//    }
    
    //第三种
//    std::string buf;
//    while (getline(ifs, buf)) {
//        std::cout << buf << std::endl;
//    }
    
    //第四种
    char c;
    while ((c = ifs.get()) != EOF) {
        std::cout << c;
    }
    //关闭文件
    ifs.close();
}

//5.2 二进制文件
//5.2.1 写文件
class person_fstream{
public:
    char m_name[64];
    int m_age;
};

void test10_2(){
    std::ofstream ofs;
    ofs.open("person.txt", std::ios::out|std::ios::binary);
    person_fstream p = {"alex",18};
    ofs.write((const char*) &p, sizeof(person_fstream));
    ofs.close();
}

//5.2.2读文件
void test10_3(){
    std::ifstream ifs;
    ifs.open("person.txt",std::ios::in|std::ios::binary);
    if (!ifs.is_open()) {
        std::cout << "failed to open" << std::endl;
        return;
    }
    
    person_fstream p;
    
    ifs.read((char *)&p, sizeof(person_fstream));
    
    std::cout << p.m_age << p.m_name << std::endl;
}


int main(int argc, const char * argv[]) {
    
    test10_3();
    return 0;
}
