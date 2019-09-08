#ifndef QSTYLESHEETSTRING_H
#define QSTYLESHEETSTRING_H

#include <QString>
#include <QLatin1String>

class QStyleSheetString
{
    QString style_sheet;
    QString name;

    void CreateState(QString state, QString propereties, QString value);
    void CreatePropereties(int position, QString propereties, QString value);
public:
    QStyleSheetString(QString object);
    void SetStyleSheet(QString style);
    void SetPropereties(QString state, QString propereties, QString value);
    QString GetStyleSheet();
    QString GetPropereties(QString state, QString propereties);
};

#endif // QSTYLESHEETSTRING_H
