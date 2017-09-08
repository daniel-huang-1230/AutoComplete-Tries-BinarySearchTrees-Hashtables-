/*
 * Author: Huayin Zhou
 * Description: WordList is a customized QListWidget to keep track of the text
 * changes in QLineEdit and print strings to the changes accordingly by
 * calling pa3 function:
 * vector<std::string> autocomplete(unsigned int num_words, std::string prefix).
 * Date: 01/28/2015
 */
#ifndef WORDLIST_H
#define WORDLIST_H

#include <QListWidget>
#include <QString>
#include <QLineEdit>
#include <string>
#include "mainwindow.h"
#include "../DictionaryTrie.h"
#include "../util.h"

#define MAX_DISPLAY 10
#define MAX_POSTFIX_TO_SEARCH 5

class MainWindow;
class WordList : public QListWidget
{
    Q_OBJECT

public:
    WordList(QWidget *parent = 0);
    void selectNext();
    void selectPrev();
    ~WordList();

public slots:
    void setItems(const QString &newString);
    void clearItems();
    void mouseClickClearItems(QListWidgetItem * item);

private:
    MainWindow *mainWindow;
    DictionaryTrie * trie;
};

#endif // WORDLIST_H
