#include "qstylesheetstring.h"
#include <QDebug>

void QStyleSheetString::CreateState(QString state, QString propereties, QString value)
{
    QString new_state = name + state + QLatin1String(" {"
                                                     "") + propereties + ": " + value +
                                       QLatin1String("; }"
                                                     "");
    style_sheet.append(new_state);
}

void QStyleSheetString::CreatePropereties(int position, QString propereties, QString value)
{
    QString new_propereties = propereties + ": " + value + ";" + QLatin1String(""
                                                                               "");
    int start = style_sheet.indexOf("{", position);
    style_sheet.insert(start + 1, new_propereties);
}

QStyleSheetString::QStyleSheetString(QString object)
{
    name = object;
    style_sheet = name + QLatin1String(" {"
                                       "background: white;"
                                       "color: black; }"
                                       "");
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
    int range = style_sheet.indexOf("}", start);
    int prop_loc = style_sheet.indexOf(propereties, start);
    if (prop_loc == -1 || prop_loc > range)
    {
        CreatePropereties(start, propereties, value);
        return;
    }
    int value_loc = style_sheet.indexOf(":", prop_loc) + 2;
    int value_end = style_sheet.indexOf(";", value_loc);
    style_sheet.replace(value_loc, value_end - value_loc, value);
}

QString QStyleSheetString::GetStyleSheet()
{
    return style_sheet;
}

QString QStyleSheetString::GetPropereties(QString state, QString propereties)
{
    int start = style_sheet.indexOf(name+state);
    if (start == -1)
    {
        return "";
    }
    int range = style_sheet.indexOf("}", start);
    int prop_loc = style_sheet.indexOf(propereties, start);
    if (prop_loc == -1 || prop_loc > range)
    {
        return "";
    }
    int value_loc = style_sheet.indexOf(":", prop_loc) + 2;
    int value_end = style_sheet.indexOf(";", value_loc);
    return style_sheet.mid(value_loc, value_end - value_loc);
}

bool QStyleSheetString::RemovePropereties(QString state, QString propereties)
{

}