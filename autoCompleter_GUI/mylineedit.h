#ifndef MYLINEEDIT_H
#define MYLINEEDIT_H

#include <QLineEdit>
#include <QListWidget>
#include <QKeyEvent>
#include "mainwindow.h"

class MainWindow;
class MyLineEdit : public QLineEdit
{
    Q_OBJECT

public:
    QString originalString;
    MyLineEdit(QWidget *parent = 0);
    ~MyLineEdit();
    void storeOriginal();

private slots:
    void storeOriginal(const QString &);
    void clearTextBox();

protected:
    void keyPressEvent(QKeyEvent *event);


private:
    MainWindow *mainWindow;
};

#endif // MYLINEEDIT_H
