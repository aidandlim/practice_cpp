#include <iostream>
#include "Calculator.h"

using namespace std;

int main(void)
{
    Calculator cal;
    cal.Init();
    cout << cal.Add(5.0, 3.5) << endl;
    cout << cal.Min(3.5, 2.1) << endl;
    cout << cal.Mul(3.3, 2.4) << endl;
    cout << cal.Div(1.5, 0.3) << endl;
    cout << cal.Add(3.2, 7.3) << endl;
    cout << cal.Min(4.2, 1.9) << endl;
    cal.ShowOpCount();
    return 0;
}