#include <iostream>

class MClass //成员类
{
public:
    MClass()
    {
        std::cout << "mclass defualt" <<std::endl;
    }
    MClass& operator=(const MClass& inclass)
    {
        std::cout << "mclass perator=" << std::endl;
        return *this;
    }
    MClass(const MClass&)
    {
        std::cout << "mcopy constructor" << std::endl;
    }
};

class SClass //作为局部变量用的类
{
public:
    SClass(MClass meb, int):member(meb)
    {
    }
    SClass(MClass meb)
    {
        member = meb;
    }
private:
    MClass member;
};

int main()
{
    MClass m;
    SClass s(m, 0);
    SClass s1(m);
    exit(0);
}
