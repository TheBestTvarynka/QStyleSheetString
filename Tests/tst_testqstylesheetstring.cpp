#include <QtTest>

// add necessary includes here
#include "../QStyleSheetString/qstylesheetstring.h"
#include "../QStyleSheetString/qstylesheetstring.cpp"

class TestQStyleSheetString : public QObject
{
    Q_OBJECT

public:
    TestQStyleSheetString();
    ~TestQStyleSheetString();

private slots:
    void test_constructor();

};

TestQStyleSheetString::TestQStyleSheetString()
{

}

TestQStyleSheetString::~TestQStyleSheetString()
{

}

void TestQStyleSheetString::test_constructor()
{
    QStyleSheetString style(".QLabel");
    QCOMPARE(style.GetStyleSheet(), QLatin1String(".QLabel {"
                                                  "background: white;"
                                                  "color: black; }"));
}

QTEST_APPLESS_MAIN(TestQStyleSheetString)

#include "tst_testqstylesheetstring.moc"
