#include <iostream>
using std::cout;
using std::endl;

class Singleton
{
    class AutoRelease
    {
    public:
        AutoRelease()
        {   cout << "AutoRelease()" << endl;    }

        ~AutoRelease()
        {
            cout << "~AutoRelease()" << endl;   
            if(_pInstance)
                delete _pInstance;
        }
    };
public:
    static Singleton * getInstance()
    {
        if(_pInstance == nullptr)
            _pInstance = new Singleton();
        return _pInstance;
    }

    void print() const {    cout << "print()" << endl;  }   

    static void destroy()
    {
        if(_pInstance)
            delete _pInstance;

    }

private:
    Singleton() {   cout << "Singleton()" << endl;  }
    ~Singleton() {  cout << "~Singleton()" << endl; }

    friend class AutoRelease;
private:
    static Singleton * _pInstance;
    static AutoRelease _autoRelease;

};

Singleton::AutoRelease Singleton::_autoRelease;
Singleton * Singleton::_pInstance = nullptr; 

int main(void)
{
    Singleton * p = Singleton::getInstance();
    p->print();
    return 0;
}

