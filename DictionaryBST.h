/**
 *  CSE 100 PA2 C++ Autocomplete
 *  Authors: Jor-el Briones, Christine Alvarado
 */

/**
 * Name: Daniel Huang
 * Date: 1/23/2017
 * Assignment: PA2
 */


#ifndef DICTIONARY_BST_H
#define DICTIONARY_BST_H

#include <string>
#include <set>
using namespace std; // using std namespace for cleaner codes

/**
 *  The class for a dictionary ADT, implemented as a BST
 * When you implement this class, you MUST use a balanced binary
 * search tree in its implementation.  The C++ set implements 
 * a balanced BST, so we strongly suggest you use that to store 
 * the dictionary.
 */
class DictionaryBST
{
public:

  /* Create a new Dictionary that uses a BST back end */
  DictionaryBST();

  /* Insert a word into the dictionary. Return false if the word is already in it*/
  bool insert(std::string word);

  /* Return true if word is in the dictionary, and false otherwise */
  bool find(std::string word) const;

  /* Destructor */
  ~DictionaryBST();

private:
  // Add your own data members and methods here
    set<string> dict;  //the std::set that will store strings 
    
};

#endif // DICTIONARY_BST_H
