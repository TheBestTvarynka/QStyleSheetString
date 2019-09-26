#include <QtTest>
#include <QDebug>
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
    void test_CreateState();
    void test_SetPropereties();
    void test_GetPropereties();
};

TestQStyleSheetString::TestQStyleSheetString()
{
    QStyleSheetString style(".QLabel");
    QCOMPARE(style.GetStyleSheet(), QLatin1String(".QLabel {"
                                                  "background: white;"
                                                  "color: black; }"
                                                  ""));
}

TestQStyleSheetString::~TestQStyleSheetString()
{

}

void TestQStyleSheetString::test_CreateState()
{
    QStyleSheetString style(".QLabel");
    style.CreateState("::hover", "color", "#ff00f0");
    QCOMPARE(style.GetStyleSheet(), QLatin1String(".QLabel {"
                                                  "background: white;"
                                                  "color: black; }"
                                                  ".QLabel::hover {"
                                                  "color: #ff00f0; }"
                                                  ""));
    style.CreateState("::presed", "color", "#00ff00");
    QCOMPARE(style.GetStyleSheet(), QLatin1String(".QLabel {"
                                                  "background: white;"
                                                  "color: black; }"
                                                  ".QLabel::hover {"
                                                  "color: #ff00f0; }"
                                                  ".QLabel::presed {"
                                                  "color: #00ff00; }"
                                                  ""));
}

void TestQStyleSheetString::test_SetPropereties()
{
    QStyleSheetString style(".QLabel");
    style.SetPropereties("", "color", "#00f0f0");
    QCOMPARE(style.GetStyleSheet(), QLatin1String(".QLabel {"
                                                  "background: white;"
                                                  "color: #00f0f0; }"
                                                  ""));
    style.CreateState("::hover", "color", "#ff00f0");
    style.SetPropereties("::hover", "color", "#121212");
    QCOMPARE(style.GetStyleSheet(), QLatin1String(".QLabel {"
                                                  "background: white;"
                                                  "color: #00f0f0; }"
                                                  ".QLabel::hover {"
                                                  "color: #121212; }"
                                                  ""));
    style.SetPropereties("::hover", "border-color", "#00000");
    QCOMPARE(style.GetStyleSheet(), QLatin1String(".QLabel {"
                                                  "background: white;"
                                                  "color: #00f0f0; }"
                                                  ".QLabel::hover {"
                                                  "border-color: #00000;"
                                                  "color: #121212; }"
                                                  ""));
    style.SetPropereties("", "border-radius", "5px");
    QCOMPARE(style.GetStyleSheet(), QLatin1String(".QLabel {"
                                                  "border-radius: 5px;"
                                                  "background: white;"
                                                  "color: #00f0f0; }"
                                                  ".QLabel::hover {"
                                                  "border-color: #00000;"
                                                  "color: #121212; }"
                                                  ""));
    style.SetPropereties("::clicked", "mergin", "5px 6px");
    QCOMPARE(style.GetStyleSheet(), QLatin1String(".QLabel {"
                                                  "border-radius: 5px;"
                                                  "background: white;"
                                                  "color: #00f0f0; }"
                                                  ".QLabel::hover {"
                                                  "border-color: #00000;"
                                                  "color: #121212; }"
                                                  ".QLabel::clicked {"
                                                  "mergin: 5px 6px; }"
                                                  ""));
}

void TestQStyleSheetString::test_GetPropereties()
{
    QStyleSheetString style(".QLabel");
    style.SetPropereties("", "color", "#00f0f0");
    style.SetPropereties("::hover", "color", "#121212");
    QCOMPARE(style.GetPropereties("", "color"), "#00f0f0");
    QCOMPARE(style.GetPropereties("::hover", "color"), "#121212");
    QCOMPARE(style.GetPropereties("::clicked", "color"), "");
    QCOMPARE(style.GetPropereties("::hover", "background"), "");
}

QTEST_APPLESS_MAIN(TestQStyleSheetString)

#include "tst_testqstylesheetstring.moc"
