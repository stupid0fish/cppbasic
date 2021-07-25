//此情况为循环引用，会导致内存泄漏，可使用weak_ptr解圈
#include <iostream>
#include <memory>

class Parent;
class Child;

class Parent
{
private:
    std::shared_ptr<Child> m_childPtr;
public:
    Parent() : m_childPtr(nullptr)
    {
    }
    ~Parent()
    {
    }
    void SetChild(std::shared_ptr<Child> child)
    {
        m_childPtr = child;
    }
};

class Child
{
private:
    std::shared_ptr<Parent> m_parentPtr;
public:
    Child() : m_parentPtr(nullptr)
    {
    }
    ~Child()
    {
    }
    void SetParent(std::shared_ptr<Parent> parent)
    {
        m_parentPtr = parent;
    }
};

int main()
{
    std::weak_ptr<Parent> wpp;
    std::weak_ptr<Child> wcp;
    {
        std::shared_ptr<Parent> p(new Parent());
        std::shared_ptr<Child> c(new Child());
        c->SetParent(p);
        p->SetChild(c);
        std::cout << p.use_count() << std::endl;
        std::cout << c.use_count() << std::endl;
        wpp = p;
        wcp = c;
        std::cout << p.use_count() << std::endl;
        std::cout << c.use_count() << std::endl;
        std::cout << wpp.use_count() << std::endl;
        std::cout << wcp.use_count() << std::endl;
    }
    std::cout << wpp.use_count() << std::endl;
    std::cout << wcp.use_count() << std::endl;
    exit(0);
}
