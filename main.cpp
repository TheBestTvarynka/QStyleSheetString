#include <iostream>
#include <QCoreApplication>

#include "QStyleSheetString/qstylesheetstring.h"

using namespace std;

int main()
{
    cout << "Hello World!" << endl;
    QStyleSheetString test("QLabel");
    test.SetPropereties("", "background", "#ff26fa");
    return 0;
}
