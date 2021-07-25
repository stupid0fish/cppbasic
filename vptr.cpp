#include <iostream>

class Base1
{
public:
    virtual void base1_funq1()
    {
        std::cout << "base1 fun1" << std::endl;
    }
    virtual void base1_fun2()
    {
        std::cout << "base1 fun2" << std::endl;
    }
    virtual void base1_fun3()
    {
        std::cout << "base1 fun3" << std::endl;
    }
};

class Base2
{
public:
    virtual void base2_fun1()
    {
        std::cout << "base2 fun1" << std::endl;
    }
    virtual void base2_fun2()
    {
        std::cout << "base2 fun2" << std::endl;
    }
    virtual void base2_fun3()
    {
        std::cout << "base2 fun3" << std::endl;
    }
};

class Drive1 : public Base1 //子类重写了弗雷的函数，并且有新的虚函数
{
public:
    virtual void base1_funq1()
    {
        std::cout << " Drive1:: base1 fun1" << std::endl;
    }
    virtual void drive1_fun1()
    {
        std::cout << "Drive1:: Drive1 fun1" << std::endl;
    }
};

class Drive1_1 : public Base1   //子类没有新的虚函数
{

};

class Drive2 : public Base1, public Base2  //多继承，子类没有新的虚函数，但是没有新的虚函数
{
public:
    virtual void base1_fun2()
    {
        std::cout << "Drive2::base1 fun2" << std::endl;
    }
    virtual void base2_fun2()
    {
        std::cout << "Drive2::base2 fun2" << std::endl;
    }
    virtual void drive2_fun1()
    {
        std::cout << "Drive2::drive2 fun1" << std::endl;
    }
};

class Drive2_1 : public Base1, public Base2
{
};



int main()
{
    std::cout << "Base1: " << sizeof(Base1) << std::endl;
    std::cout << "Base2: " << sizeof(Base2) << std::endl;
    std::cout << "Drive1: " << sizeof(Drive1) << std::endl;
    std::cout << "Drive1_1: " << sizeof(Drive1_1) << std::endl;
    std::cout << "Drive2: " << sizeof(Drive2) << std::endl;
    std::cout << "Drive2_1: " << sizeof(Drive2_1) << std::endl;

    Base1 b1;
    Base2 b2;
    

    Base1* pb1 = new Drive1();
    pb1->base1_funq1();
    Base1* pb1_1 = new Drive1_1();
    pb1_1->base1_fun2();
    Base2* pb2 = new Drive2();
    pb2->base2_fun2();
    Base2* pb2_1 = new Drive2_1();
    pb2_1->base2_fun2();
    return 0;
}
