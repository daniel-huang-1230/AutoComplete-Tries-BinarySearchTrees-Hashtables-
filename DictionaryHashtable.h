/**
 *  CSE 100 PA3 C++ Autocomplete
 *  Authors: Jor-el Briones, Christine Alvarado
 */

/**
 * Name: Daniel Huang
 * Date: 1/23/2017
 * Assignment: PA2
 * Header file that contains constructors and function declarations
 */

#ifndef DICTIONARY_HASHTABLE_H
#define DICTIONARY_HASHTABLE_H

#include <string>
#include <unordered_set>
using namespace std; // using std namespace for cleaner codes

/**
 *  The class for a dictionary ADT, implemented as a Hashtable
 * When you implement this class, you MUST use a Hashtable
 * in its implementation.  The C++ unordered_set implements
 * a Hashtable, so we strongly suggest you use that to store
 * the dictionary.
 */
class DictionaryHashtable
{
public:
    
    /* Create a new Dictionary that uses a Hashset back end */
    DictionaryHashtable();
    
    /* Insert a word into the dictionary. */
    bool insert(std::string word);
    
    /* Return true if word is in the dictionary, and false otherwise */
    bool find(std::string word) const;
    
    /* Destructor */
    ~DictionaryHashtable();
    
private:
    // Add your own data members and methods here
    unordered_set<string> dict; //the unordered set from C++ std that would store strings
};

#endif // DICTIONARY_HASHTABLE_H
