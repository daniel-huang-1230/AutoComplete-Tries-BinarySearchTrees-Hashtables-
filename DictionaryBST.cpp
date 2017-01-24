#include "util.h"
#include "DictionaryBST.h"

/**
 * Name: Daniel Huang
 * Date: 1/23/2017
 * Assignment: PA2
 * This file contains the implementation of a dictionary, using a balanced BST 
 * as the backing data structure
 /

// Constructor that creates a new Dictionary that uses a BST back end*/
DictionaryBST::DictionaryBST(){

    dict=set<string> ();  //instantiate a new empty set

}

/* Insert a word into the dictionary. */
bool DictionaryBST::insert(std::string word)
{
   
    return get<1>(dict.insert(word)); //get the bool value from the pair and return
}

/* Return true if word is in the dictionary, and false otherwise */
bool DictionaryBST::find(std::string word) const
{
    if(dict.find(word)!=dict.end()){
        return true; //word found!
        
    }
    return false; //word not found in the dictionary
}

/* Destructor */
DictionaryBST::~DictionaryBST(){}
