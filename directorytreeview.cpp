#include "directorytreeview.h"
#include <iostream>

DirectoryTreeView::DirectoryTreeView(QWidget *parent) : QTreeView(parent)
{
    this->readDirectory("");
    this->setEditTriggers(QAbstractItemView::NoEditTriggers);
    connect(&timer,SIGNAL(timeout()),this,SLOT(onSingleClick()));
}

void DirectoryTreeView::readDirectory(const QString &dir_path){
    QFileSystemModel *dir_model = new QFileSystemModel();
    dir_model->setRootPath(dir_path);
    this->setModel(dir_model);
    this->setRootIndex(dir_model->index(dir_path));
    this->setHeaderHidden(true);
    int column_count = dir_model->columnCount();
    for(int i = 1; i < column_count; ++i){
        this->hideColumn(i);
    }

}

void DirectoryTreeView::mouseDoubleClickEvent(QMouseEvent * event){
    Q_UNUSED(event);
    qDebug() << "This happens on double click";
    QFileInfo *file = new QFileInfo(dynamic_cast<QFileSystemModel *>(model())->filePath(currentIndex()));
    qDebug() << file->filePath();
//    this->readFile(file->filePath());
}
void DirectoryTreeView::onSingleClick()
{
  qDebug() << "This happens on single click";
  timer.stop();
}
