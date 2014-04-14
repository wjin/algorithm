#include <iostream>
#include <cstring>

using namespace std;

class CMyString
{
public:
    CMyString(const char *str = nullptr);
    CMyString(const CMyString &str);
    ~CMyString();
    CMyString & operator = (const CMyString &str);
    void display();

private:
    char *m_pData;
};

CMyString::CMyString(const char *str)
{
    if(str == nullptr) {
        // m_pData = nullptr; error
        m_pData = new char[1];
        *m_pData = '\0';
    } else {
        int len = strlen(str);
        m_pData = new char[len + 1];
        if(m_pData == nullptr) exit(1); // no memory
        strncpy(m_pData, str, len + 1);
    }
}

CMyString::CMyString(const CMyString &other)
{
    int len = strlen(other.m_pData);
    m_pData = new char[len + 1];
    strncpy(m_pData, other.m_pData, len + 1);
}

CMyString::~CMyString()
{
    delete [] m_pData;
}

// exception safe
CMyString & CMyString::operator = (const CMyString &other)
{
    if (this != &other) {
        CMyString tmp(other);
        swap(tmp.m_pData, this->m_pData);
    }
    return *this;
}

#if 0
CMyString & CMyString::operator = (const CMyString &other)
{
    if(this == &other) return *this;
    delete [] m_pData;

    m_pData = nullptr;
    int len = strlen(other.m_pData);
    m_pData = new char[len + 1];
    // m_pData == nullptr ?
    strncpy(m_pData, other.m_pData, len + 1);
    return *this;
}
#endif

void CMyString::display()
{
    cout << m_pData << endl;
}

int main()
{
    CMyString s1;
    CMyString s2("abc");
    CMyString s3("xyzxyz");

    s1.display();
    s2.display();
    s3.display();

    s1 = s2;
    s1.display();

    s2 = s3;
    s2.display();
    s1.display();

    return 0;
}
