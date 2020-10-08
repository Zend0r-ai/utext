#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFileDialog>
#include <QList>
#include <QTextOption>
#include <tabnote.h>
#include <directorytreeview.h>
#include <textedittab.h>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void setWrapMode(QPlainTextEdit::LineWrapMode mode);
    QPlainTextEdit::LineWrapMode get_WrapMode() const;

private slots:
    void on_actionAdd_new_note_triggered();

    void on_actionOpen_file_triggered();

    void on_actionLog_triggered();

    void on_actionWord_Wrap_triggered();

private:
    Ui::MainWindow *ui;
    QPlainTextEdit::LineWrapMode tab_mode = QPlainTextEdit::WidgetWidth;
};
#endif // MAINWINDOW_H
