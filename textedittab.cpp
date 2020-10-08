#include "textedittab.h"

TextEditTab::TextEditTab(QWidget *parent) : QTabWidget(parent)
{
   QTextEdit* search_entry = new QTextEdit();
//   search_entry->sets
   this->setCornerWidget(search_entry);
   this->setMovable(true);
//   this->setTabBarAutoHide(true);
   QString tabStyle = "QTabBar {color:#ffffff;}"
                      "QTabBar::tab:!selected {"
                      "height: 15px;"
                      "padding: 2px;"
                      "width: 80px; "
                      "border: 1px solid #3E3E3E;"
                      "background-color: #ffffff; "
                      "color:#000000;"
                      "font-size:8pt;"
                      "}"
                      "QTabBar::tab:selected {"
                      "height: 15px;"
                      "padding: 2px;"
                      "width: 80px;"
                      "border: 2px solid #26A707;"
                      "background-color: #0E4904; "
                      "color:#ffffff;"
                      "font-size:10pt;"
                      "}";
   this->setStyleSheet(tabStyle);
}


void TextEditTab::addFileTab(){
    TabNote* note = new TabNote();
    note->set_WrapMode(tab_mode);
//    note->setText("ferfef");
    this->addTab(note, "untitled");
}

void TextEditTab::readFile(const QString &file_path){
    TabNote* note = new TabNote();
    note->set_WrapMode(tab_mode);
    QFile file(file_path);
    file.open(QIODevice::Text | QIODevice::ReadOnly);
    QString content;
    while(!file.atEnd())
        content.append(file.readLine());
    note->setText(content);
    this->addTab(note, file_path);
    file.close();
}

void TextEditTab::setWrapMode(QPlainTextEdit::LineWrapMode new_tab_mode){
    tab_mode = new_tab_mode;
    changeWrapMode();
}

void TextEditTab::changeWrapMode(){
    QList<QPlainTextEdit *> tab_list = this->findChildren<QPlainTextEdit *>();
    for(const auto& it : tab_list){
        it->setLineWrapMode(tab_mode);
    }
}
