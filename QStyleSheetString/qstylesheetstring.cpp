#include "qstylesheetstring.h"

#include <QDebug>

void QStyleSheetString::CreateState(QString state, QString propereties, QString value)
{
    QString new_state = name + state + QLatin1String(" {"
                                                     "") + propereties + ": " + value +
                                       QLatin1String("; }"
                                                     "");
    qDebug() << style_sheet;
    style_sheet.append(new_state);
    qDebug() << style_sheet;
}

void QStyleSheetString::CreatePropereties(int position, QString propereties, QString value)
{
    QString new_propereties = propereties + ": " + value + ";" + QLatin1String(""
                                                                               "");
    int start = style_sheet.indexOf("{", position);
    qDebug() << style_sheet;
    style_sheet.insert(start + 1, new_propereties);
    qDebug() << style_sheet;
}

QStyleSheetString::QStyleSheetString(QString object)
{
    name = object;
    style_sheet = name + QLatin1String(" {"
                                       "background: white;"
                                       "color: black; }");
}

void QStyleSheetString::SetStyleSheet(QString style)
{
    style_sheet = style;
}

void QStyleSheetString::SetPropereties(QString state, QString propereties, QString value)
{
    int start = style_sheet.indexOf(name+state);
    if (start == -1)
    {
        CreateState(state, propereties, value);
        return;
    }
    qDebug() << start;
    int range = style_sheet.indexOf("}", start);
    int prop_loc = style_sheet.indexOf(propereties, start);
    qDebug() << prop_loc << range;
    if (prop_loc == -1 || prop_loc > range)
    {
        CreatePropereties(start, propereties, value);
    }
}

QString QStyleSheetString::GetStyleSheet()
{
    return style_sheet;
}

QString QStyleSheetString::GetPropereties(QString state, QString propereties)
{

}
