#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->treeView, SIGNAL(sendData(const QFileInfo&)), ui->tabWidget, SLOT(recieveData(const QFileInfo&)));
    connect(ui->tabWidget, SIGNAL(tabCloseRequested(int)), this, SLOT(closeTab(int)));
    ui->treeView->hide();
    ui->logWindow->hide();
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::setWrapMode(QPlainTextEdit::LineWrapMode mode){
    tab_mode = mode;
}

QPlainTextEdit::LineWrapMode MainWindow::get_WrapMode() const{
    return tab_mode;
}

void MainWindow::moveCursor(QTextCursor::MoveOperation op){
    if(ui->tabWidget->count() != 0){
        TabNote* note = dynamic_cast<TabNote *>(ui->tabWidget->currentWidget());
        //    qDebug() << note->toPlainText();
        note->moveCursor(op);
    }
}

void MainWindow::closeTab(const int& index)
{
    if (index == -1) {
        return;
    }

    QWidget* tabItem = ui->tabWidget->widget(index);
    // Removes the tab at position index from this stack of widgets.
    // The page widget itself is not deleted.
    ui->tabWidget->removeTab(index);

    delete(tabItem);
    tabItem = nullptr;
}


//Signals

void MainWindow::on_actionAdd_new_note_triggered()
{
    ui->tabWidget->addFileTab();
}

void MainWindow::on_actionOpen_file_triggered()
{
    QString dir = QFileDialog::getExistingDirectory(this, tr("Open Directory"),
                                                    "",
                                                    QFileDialog::ShowDirsOnly
                                                    | QFileDialog::DontResolveSymlinks);
    ui->treeView->readDirectory(dir);
    ui->treeView->show();
}

void MainWindow::on_actionLog_triggered()
{
    if(ui->actionLog->isChecked())
        ui->logWindow->show();
    else
        ui->logWindow->hide();
}

void MainWindow::on_actionWord_Wrap_triggered()
{
    if(ui->actionWord_Wrap->isChecked())
        ui->tabWidget->setWrapMode(QPlainTextEdit::WidgetWidth);
    else
        ui->tabWidget->setWrapMode(QPlainTextEdit::NoWrap);

}

void MainWindow::on_actionJump_Back_triggered()
{
    moveCursor(QTextCursor::Start);
}

void MainWindow::on_actionJump_Forward_triggered()
{
    moveCursor(QTextCursor::End);
}
