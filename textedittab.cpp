#include "textedittab.h"

TextEditTab::TextEditTab(QWidget *parent) : QTabWidget(parent)
{
   QLineEdit* search_entry = new QLineEdit();
//   search_entry->sets
   this->setCornerWidget(search_entry);
   this->setMovable(true);
//   this->setTabBarAutoHide(true);
//   QString tabStyle = "QTabBar {color:#ffffff;}"
//                      "QTabBar::tab:!selected {"
//                      "height: 15px;"
//                      "padding: 2px;"
//                      "min-width: 100px;"
//                      "border: 1px solid #3E3E3E;"
//                      "background-color: #ffffff; "
//                      "color:#000000;"
//                      "font-size:8pt;"
//                      "}"
//                      "QTabBar::tab:selected {"
//                      "height: 15px;"
//                      "padding: 2px;"
//                      "min-width: 100px;"
//                      "border: 2px solid #26A707;"
//                      "background-color: #0E4904; "
//                      "color:#ffffff;"
//                      "font-size:8pt;"
//                      "}";
   QString tabStyle = "QTabWidget::tab-bar {border: 1px solid gray;}QTabBar::tab {background: gray; color: white;padding: 10px;border-left: 1px solid #A9A9A9;border-right: 1px solid #A9A9A9;border-top: 1px solid #A9A9A9;}QTabBar::tab:selected {background: lightgray;}"
           "QTabWidget::pane {"
              "border: none;"
           "}"
           "QTabBar::close-button {"
              "image: url(:/button/close);"
              "subcontrol-position: right;"
           "}";
   this->setStyleSheet(tabStyle);
}


void TextEditTab::addFileTab(){
    TabNote* note = new TabNote();
    note->set_WrapMode(tab_mode);
    this->addTab(note, "untitled");
    this->setCurrentWidget(note);
}

void TextEditTab::readFile(const QFileInfo& file_info){
    TabNote* note = new TabNote();
    note->set_WrapMode(tab_mode);
    QFile file(file_info.filePath());
    file.open(QIODevice::Text | QIODevice::ReadOnly);
    QTextStream in(&file);
    QString content;
    while(!in.atEnd()){
        content.append(in.readLine());
//        qDebug()<< "." << in.padChar() << ".";
        content.append('\n');
    }
    note->setText(content);
    this->addTab(note, file_info.fileName());
    this->setCurrentWidget(note);
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

void TextEditTab::recieveData(const QFileInfo& data){
    qDebug() << data << "text edit";
    readFile(data.filePath());
}
