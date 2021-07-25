#include <iostream>
#include <memory>

template <class Type>
class SmartPtr
{
public:
    SmartPtr(Type ptr = nullptr) : m_ptr(ptr)
    {
        if(this->m_ptr == nullptr)
        {
            this->m_count = new int(0);
        }
        else
        {
            this->m_count = new int(1);
        }
    }

    SmartPtr(const SmartPtr& smartPtr)
    {
        this->m_ptr = smartPtr.m_ptr;
        this->m_count = smartPtr.m_count;
        *(this->m_count)++;
    }

    SmartPtr& operator=(const SmartPtr& smartPtr)
    {
        if(this->m_ptr == smartPtr.m_ptr)
            return *this;
        if(this->m_ptr)
        {
            *m_count--;
            if(*m_count == 0)
            {
                delete m_ptr;
                delete m_count;
                m_ptr = nullptr;
            }
        }
        this->m_ptr = smartPtr.m_ptr;
        this->m_count = smartPtr.m_count;
        *(this->m_count)++;
        return *this;
    }

    Type* operator->()
    {
        assert(this->m_ptr != nullptr);
        return this->m_ptr;
    }

    Type& operator*()
    {
        assert(this->m_ptr != nullptr);
        return (this->m_ptr);
    }

    size_t use_count()
    {
        return *(this->m_count);
    }
private:
    Type* m_ptr;
    size_t* m_count;
};
