#include "mylineedit.h"
#include <QDebug>

MyLineEdit::MyLineEdit(QWidget *parent) : QLineEdit(parent) {
    //wordList = parent->parentWidget()->findChild<WordList *>("listWidget");
    mainWindow = (MainWindow *)(parent->parentWidget()->parentWidget()->parentWidget());
    //mainWindow.setLineEdit(this);
    connect(this, SIGNAL(textEdited(const QString &)),
            this, SLOT(storeOriginal(const QString &)));
}

MyLineEdit::~MyLineEdit() {}

void MyLineEdit::storeOriginal() {
    originalString = text();
}

void MyLineEdit::storeOriginal(const QString & str) {
    originalString = str;
}

void MyLineEdit::clearTextBox() {
    setText("");
    mainWindow->dropDownClear();
}

void MyLineEdit::keyPressEvent(QKeyEvent *event)
{
    switch(event->key()) {
        case Qt::Key_Down: // move down highlighter of wordList
            mainWindow->dropDownSelNext();
            break;
        case Qt::Key_Up:   // move up highlighter of wordList
            mainWindow->dropDownSelPrev();
            break;
        case Qt::Key_Return:
            mainWindow->dropDownClear();
            break;
        default:
            // default handler for event
            QLineEdit::keyPressEvent(event);
    }
}
