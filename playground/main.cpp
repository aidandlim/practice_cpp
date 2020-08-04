#include <iostream>

using namespace std;

int main(void)
{
    int value = 10;
    int &ref = value;
    int *ptr = &value;

    cout << "[1] value : " << value << endl;
    cout << "[1] ref : " << ref << endl;
    cout << "[1] ptr : " << *ptr << endl;

    value = 20;
    ptr = &ref;
    ref = 15;

    cout << "[2] value : " << value << endl;
    cout << "[2] ref : " << ref << endl;
    cout << "[2] ptr : " << *ptr << endl;

    cout << "[3] value : " << &value << endl;
    cout << "[3] ref : " << &ref << endl;
    cout << "[3] ptr : " << ptr << endl;

    return 0;
}