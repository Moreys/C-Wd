#include <iostream>
using std::cout;
using std::endl;

void display(void)
{
    cout << "display()" << endl;

}

int main(void)
{
    cout << "main start ...." << endl;
    atexit(display);
    atexit(display);
    atexit(display);

    cout << "main exit...." << endl;
    return 0;

}

