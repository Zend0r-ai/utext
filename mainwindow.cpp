#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->treeView, SIGNAL(sendData(const QFileInfo&)), ui->tabWidget, SLOT(recieveData(const QFileInfo&)));
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
