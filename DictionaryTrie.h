/**
 *  CSE 100 PA3 C++ Autocomplete
 *  Authors: Jor-el Briones, Christine Alvarado
 */

#ifndef DICTIONARY_TRIE_H
#define DICTIONARY_TRIE_H

#include <vector>
#include <string>
#include <set>
#include <stack>
using namespace std;  // use namespace for cleaner codes
/**
 * Name: Daniel Huang
 * Date: 1/23/2017
 * Assignment: PA2
 */

/**
 *  The class for a dictionary ADT, implemented as a trie
 *  You may implement this class as either a mulit-way trie
 *  or a ternary search trie, but you must use one or the other.
 *
 */

// The following is the Node class created in order to implement trie
class Node {
public:
    Node(){wordChar=' '; word=false;};  // Node constructor
    //notice the root is initialized with a space character
    
    ~Node() {} //the destructor
    
    char content() {return wordChar; } //getter that returns the character
    // in the node
    void setContent(char c){wordChar=c; } //setter
    
    bool wordNode() { return word; } // check if the node is a word node
    
    void setWordNode() { word=true; } // label a node as a word node
    
    void setFreq(unsigned int freq) { this->freq=freq; }
    
    int  getFreq() { return this->freq; } // the getter for the frequency of a word
    
    Node* findChild(char c);  //implemented in .cpp file
    
    void addChild(Node* child) { children.push_back(child); }
    //append a new node to the vector(container)
    
    vector<Node*> getChildren() { return children;} //getter that returns
    // the children vector
    
    std::string wordStr=""; //used to keep track of the concatenation of characters
    
private:
    char wordChar; //the character stored on the edge pointing to the
    // node(technically it's stored IN the node here)
    bool word = false;  // Node's "word" label
    
    int freq=0; //initialize the frequency to 0
    
    
    
    vector<Node*> children; //use vector to store all the children nodes
    //in order to keep track of all the edges pointing from one node
    
};

class DictionaryTrie
{
public:

  /* Create a new Dictionary that uses a Trie back end */
  DictionaryTrie();

  /* Insert a word with its frequency into the dictionary.
   * Return true if the word was inserted, and false if it
   * was not (i.e. it was already in the dictionary or it was
   * invalid (empty string) */
  bool insert(std::string word, unsigned int freq);

  /* Return true if word is in the dictionary, and false otherwise */
  bool find(std::string word) const;

   
  /* Return up to num_completions of the most frequent completions
   * of the prefix, such that the completions are words in the dictionary.
   * These completions should be listed from most frequent to least.
   * If there are fewer than num_completions legal completions, this
   * function returns a vector with as many completions as possible.
   * If no completions exist, then the function returns a vector of size 0.
   * The prefix itself might be included in the returned words if the prefix
   * is a word (and is among the num_completions most frequent completions
   * of the prefix)
   */
  std::vector<std::string>
  predictCompletions(std::string prefix, unsigned int num_completions);

  /* Destructor */
  ~DictionaryTrie();

   void  deleteAll(Node* n); //helper method for destructor
    
private:
  // Add your own data members and methods here
    Node* root; //node pointer pointing to the root
    
      
    };








#endif // DICTIONARY_TRIE_H
