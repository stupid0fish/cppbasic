#include <iostream>

class StaticMember;

class UseStaticMember
{
public:
    static StaticMember sm;
    //StaticMember sm1;  field ‘sm1’ has incomplete type ‘StaticMember’
};

class StaticMember
{
public:
    static int si;
    int nostaticm;
    static StaticMember sm;
    StaticMember& smm;
    StaticMember* psm;
    //StaticMember smr;    //definition of ‘class StaticMember’ is not complete until the closing brace
    void fun(int param = si);
//    void fun1(int param = nonstaticm); 非静态成员变量不能作为参数
};
