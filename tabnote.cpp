#include "tabnote.h"

TabNote::TabNote(QWidget *parent) : QPlainTextEdit(parent)
{
    QMenu* node_menu = new QMenu();
    is_new = true;
//    this->hea
}

void TabNote::setText(const QString &data){
    this->appendPlainText(data);
    is_new = false;
}

void TabNote::set_WrapMode(QPlainTextEdit::LineWrapMode mode){
    this->setLineWrapMode(mode);
}
