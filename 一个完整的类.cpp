#include <iostream>
#include <string>
using namespace std;

class myClass
{
public:
    myClass(const string s = string("")) ://默认构造
        m_s(new string(s)), 
        m_id(0) 
    { 
        cout << "默认构造调用..." << m_s << endl; 
    }
    myClass(const myClass& mc) //拷贝构造
    {
        m_id = mc.m_id;
        if (m_s) delete m_s;
        m_s = new string(*mc.m_s);//分配内存操作（拷贝）
        cout << "拷贝构造调用..." << m_s << endl;
    }
    myClass(myClass&& mc)//移动构造
    {
        m_id = mc.m_id;
        m_s = mc.m_s;
        mc.m_s = nullptr;
        cout << "移动构造调用..." << m_s << endl;
    }

    myClass& operator=(myClass& mc) //拷贝赋值
    {
        m_id = mc.m_id;
        string* temp = new string(*mc.m_s);//分配内存操作（拷贝）
        if (m_s) delete m_s;
        m_s = temp;
        temp = nullptr;
        cout << "拷贝赋值调用..." << m_s << endl;
        return *this;
    }
    myClass& operator=(myClass&& mc)//移动赋值
    {
        if (this != &mc)
        {
            m_id = mc.m_id;
            m_s = mc.m_s;
            mc.m_s = nullptr;
        }
        cout << "移动赋值调用..." << m_s << endl;
        return *this;
    }

    ~myClass()
    {
        if (m_s) 
        {
            delete m_s;
            m_s = nullptr;
        }
        cout << "析构函数调用..." << endl;
    }

private:
    int m_id;
    string* m_s;
};

int main()
{
    myClass A;//默认构造
    myClass B(A);//拷贝构造
    myClass C(std::move(B));//移动构造
    cout << endl;
    C = A;// 拷贝赋值
    C = std::move(A);//移动赋值

    system("pause");
    return 0;
}
