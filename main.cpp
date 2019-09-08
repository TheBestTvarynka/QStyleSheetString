#include <iostream>
#include <QCoreApplication>

#include "QStyleSheetString/qstylesheetstring.h"

using namespace std;

int main()
{
    cout << "Hello World!" << endl;
    QStyleSheetString test("QLabel");
    test.SetPropereties("", "border-radius", "5px");
    return 0;
}
