/*
 * Author: Huayin Zhou
 * Date: 01/28/2015
 */
#include "wordlist.h"
#include <unistd.h>
#include <QDebug>
#include <fstream>
#include <algorithm>

using std::vector;
using std::string;

WordList::WordList(QWidget *parent) : QListWidget(parent) {
    mainWindow = (MainWindow *)(parent->parentWidget()->parentWidget()
                                    ->parentWidget()->parentWidget());

    connect(this, SIGNAL(itemClicked(QListWidgetItem*)),
           this, SLOT(mouseClickClearItems(QListWidgetItem *)));

    trie = new DictionaryTrie();
    // Read the dictionary into DictTrie
    std::ifstream in;
    in.open("../freq_dict.txt");
    Utils U;
    U.load_dict(*trie, in);
    in.close();
}

WordList::~WordList() {
    delete trie;
}

// Select the next item in drop down menu. The selected text will be sent to
// input bar, but the original input can be retrieved later.
void WordList::selectNext() {
    int currRow = currentRow();
    if (currRow == count() - 1) {
        currRow = -1;
    } else {
        currRow++;
    }

    setCurrentRow(currRow);
    if (currentRow() != -1) {
        mainWindow->textFieldSetText(currentItem()->text());
    } else {
        mainWindow->textFieldSetText(mainWindow->getTextFieldOriginalString());
    }
}

// Select the prev item in drop down menu. The selected text will be sent to
// input bar, but the original input can be retrieved later.
void WordList::selectPrev() {
    int currRow = currentRow();
    if (currRow == -1) {
        currRow = count() - 1;
    } else {
        currRow--;
    }

    setCurrentRow(currRow);
    if (currentRow() != -1) {
        mainWindow->textFieldSetText(currentItem()->text());
    } else {
        mainWindow->textFieldSetText(mainWindow->getTextFieldOriginalString());
    }
}

// Populate the drop down menu by searching prediction of word in input bar
void WordList::setItems(const QString &newString) {
    clear();
    mainWindow->clearStatusBarText();
    if (!newString.isEmpty()) {
        vector<string> prefixString;
        vector<string> searchString;
        string originString = newString.toUtf8().constData();
        string trailingSpaces = string();
        // Get the trailing spaces
        while (originString.length() > 0
             &&  originString.find_last_of(' ') == originString.length() - 1) {
         originString.pop_back();
         trailingSpaces += " ";
        }

        int spacePos = originString.length();
        // Construct postfixes
        for (int i = 0; i < MAX_POSTFIX_TO_SEARCH; i++) {
            spacePos = originString.find_last_of(' ', spacePos - 1);

            prefixString.push_back(originString.substr(0, spacePos + 1));
            searchString.push_back(
                originString.substr(spacePos + 1) + trailingSpaces);
         
            if (spacePos == string::npos) break;
        }

/*    
      for (int i = searchString.size() - 1; i >= 0; i--) {
         qDebug() << "Prefix " << i << ": " << QString::fromUtf8(prefixString[i].c_str());
         qDebug() << "Search " << i << ": " << QString::fromUtf8(searchString[i].c_str());
         qDebug() << "Trail :" << trailingSpaces.length() << endl;
      }
*/
        // Search each postfix
        mainWindow->setStatusBarText(tr("Searching..."));
        vector<string> final;
        for (int i = searchString.size() - 1; i >= 0; i--) {
            vector<string> v =
                trie->predictCompletions(searchString[i], MAX_DISPLAY);
            for(vector<string>::iterator it = v.begin();
                it != v.end(); ++it) {
                if(std::find(final.begin(),final.end(),
                             prefixString[i]+(*it)) == final.end())
                    final.push_back(prefixString[i]+(*it));
                if (final.size() >= MAX_DISPLAY) break;
            }

            if (final.size() >= MAX_DISPLAY) break;
        }
        for(vector<string>::iterator it = final.begin();
            it != final.end(); ++it) {
            addItem(QString::fromUtf8(it->c_str()));
        }
        mainWindow->setStatusBarText(tr("Finish Searching"), 2000);
    }

    // Resize drop down menu
    if (count() > 0) {
        setVisible(true);
        resize(width(), rectForIndex(
                            indexFromItem(item(0))).height()*count() + 5);
    } else {
        resize(width(), 0);
    }
}


// Clear the drop down menu BUT RETAIN the content in input bar
void WordList::clearItems() {
    mainWindow->textFieldSaveCurrTextAsOriginal();
    clear();
    resize(width(), 0);
}

// Clear the drop down menu, replace the content in input bar with
// the clicked item
void WordList::mouseClickClearItems(QListWidgetItem * item) {
    mainWindow->textFieldSetText(item->text());
    mainWindow->textFieldSaveCurrTextAsOriginal();
    clear();
    resize(width(), 0);
}
