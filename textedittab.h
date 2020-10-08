#ifndef TEXTEDITTAB_H
#define TEXTEDITTAB_H

#include <QWidget>
#include <QTabWidget>
#include <QTextEdit>
#include <QLineEdit>
#include "tabnote.h"
#include <mainwindow.h>

class TextEditTab : public QTabWidget
{
    Q_OBJECT
public:
    explicit TextEditTab(QWidget *parent = nullptr);
    void setTabStyle(const QString& style);
    void addFileTab();
    void changeWrapMode();
    void setWrapMode(QPlainTextEdit::LineWrapMode new_tab_mode);
    void readFile(const QFileInfo& file_info);

signals:

public slots:
    void recieveData(const QFileInfo& data);

private:
    QPlainTextEdit::LineWrapMode tab_mode = QPlainTextEdit::LineWrapMode::WidgetWidth;

};

#endif // TEXTEDITTAB_H
