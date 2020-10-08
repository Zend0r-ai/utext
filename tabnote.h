#ifndef TABNOTE_H
#define TABNOTE_H

#include <QWidget>
#include <QPlainTextEdit>
#include <QMenu>

class TabNote : public QPlainTextEdit
{
    Q_OBJECT
public:
    explicit TabNote(QWidget *parent = nullptr);
    bool getEditStatus() const;
    void setEditStatus(bool status);
    void setText(const QString& data);
    void set_WrapMode(QPlainTextEdit::LineWrapMode mode);
signals:

private:
    bool is_new;

};

#endif // TABNOTE_H
