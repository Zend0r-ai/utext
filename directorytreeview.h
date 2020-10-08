#ifndef DIRECTORYTREEVIEW_H
#define DIRECTORYTREEVIEW_H

#include <QWidget>
#include <QTreeView>
#include <QtGui>
#include <QtCore>
#include <QFileSystemModel>
#include <textedittab.h>


class DirectoryTreeView : public QTreeView
{
    Q_OBJECT
public:
    explicit DirectoryTreeView(QWidget *parent = nullptr);
    void readDirectory(const QString& dir_path);

signals:

protected:
    virtual void mouseDoubleClickEvent(QMouseEvent * event);


private:
  QTimer timer;

private slots:
  void onSingleClick();
};

#endif // DIRECTORYTREEVIEW_H
