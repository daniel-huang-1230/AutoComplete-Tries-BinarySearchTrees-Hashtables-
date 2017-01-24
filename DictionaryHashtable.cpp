#include "util.h"
#include "DictionaryHashtable.h"

/**
 * Name: Daniel Huang
 * Date: 1/23/2017
 * Assignment: PA2
 * This file contains the implementation of a dictionary, using the hash table 
 * as the backing data structure
 */

/* Create a new Dictionary that uses a Hashset back end */
DictionaryHashtable::DictionaryHashtable(){
    dict=unordered_set<string>(); // initialize an empty unordered set
}

/* Insert a word into the dictionary. */
bool DictionaryHashtable::insert(std::string word)
{
     return get<1>(dict.insert(word)); //get the bool value from the pair and return
}

/* Return true if word is in the dictionary, and false otherwise */
bool DictionaryHashtable::find(std::string word) const
{
    if(dict.find(word)!=dict.end()){
        return true; //word found!
        
    }
    return false; //word not found in the dictionary

}

/* Destructor */
DictionaryHashtable::~DictionaryHashtable(){}
//just use the default (trivial) destructor
