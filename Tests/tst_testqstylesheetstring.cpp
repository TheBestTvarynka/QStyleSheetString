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
    void test_RemovePropereties();
    void test_RemoveState();
    void test_AddState();
    void test_RenameObject();
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

void TestQStyleSheetString::test_RemovePropereties()
{
    QStyleSheetString style(".QLabel");
    style.SetPropereties("", "border", "5px solid grey");
    style.RemovePropereties("", "border");
    QCOMPARE(style.GetStyleSheet(), QLatin1String(".QLabel {"
                                                  "background: white;"
                                                  "color: black; }"
                                                  ""));
    style.RemovePropereties("", "color");
    QCOMPARE(style.GetStyleSheet(), QLatin1String(".QLabel {"
                                                  "background: white; }"
                                                  ""));
    style.RemovePropereties("", "background");
    QCOMPARE(style.GetStyleSheet(), QLatin1String(".QLabel { }"
                                                  ""));
}

void TestQStyleSheetString::test_RemoveState()
{
    QStyleSheetString style(".QLabel");
    style.SetPropereties("::hover", "color", "white");
    style.SetPropereties("::clicked", "background", "black");
    style.RemoveState("::hover");
    QCOMPARE(style.GetStyleSheet(), QLatin1String(".QLabel {"
                                                  "background: white;"
                                                  "color: black; }"
                                                  ".QLabel::clicked {"
                                                  "background: black; }"
                                                  ""));
    style.RemoveState("::clicked");
    QCOMPARE(style.GetStyleSheet(), QLatin1String(".QLabel {"
                                                  "background: white;"
                                                  "color: black; }"
                                                  ""));
    style.RemoveState("");
    QCOMPARE(style.GetStyleSheet(), QLatin1String(""
                                                  ""));
}

void TestQStyleSheetString::test_AddState()
{
    QStyleSheetString style(".QLabel");
    style.AddState(QLatin1String("::hover {"
                   "border-color: #00000;"
                   "color: #121212; }"));
    QCOMPARE(style.GetStyleSheet(), QLatin1String(".QLabel {"
                                                  "background: white;"
                                                  "color: black; }"
                                                  ".QLabel::hover {"
                                                  "border-color: #00000;"
                                                  "color: #121212; }"
                                                  ""));
}

void TestQStyleSheetString::test_RenameObject()
{
    QStyleSheetString style(".QLabel");
    style.RenameObject(".QPushButton");
    QCOMPARE(style.GetStyleSheet(), QLatin1String(".QPushButton {"
                                                  "background: white;"
                                                  "color: black; }"
                                                  ""));
    style.AddState(QLatin1String("::hover {"
                   "border-color: #00000;"
                   "color: #121212; }"));
    style.RenameObject(".QWidget");
    QCOMPARE(style.GetStyleSheet(), QLatin1String(".QWidget {"
                                                  "background: white;"
                                                  "color: black; }"
                                                  ".QWidget::hover {"
                                                  "border-color: #00000;"
                                                  "color: #121212; }"
                                                  ""));
}

QTEST_APPLESS_MAIN(TestQStyleSheetString)

#include "tst_testqstylesheetstring.moc"
