#ifndef UTIL_H
#define UTIL_H

#include <chrono>
#include "DictionaryTrie.h"
#include "DictionaryBST.h"
#include "DictionaryHashtable.h"
#include <vector>
#include <string>
#include <iostream>

using std::istream;

class Timer{
private:
    /* start the timer */
    std::chrono::time_point<std::chrono::high_resolution_clock> start;
    
public:
    
    /*
     * Function called when starting the timer.
     */
    void begin_timer();
    
    /*
     * Function called when ending the timer. Returns duration in nanoseconds
     * PRECONDITION: begin_timer() must be called before this function
     */
    long long end_timer();
    
    
};

class Utils{
private:
    
    /* Remove the first set of characters before the first space
	 * from the string line.  This function assumes these will 
	 * be a numeric frequency and the rest of the line is a word
	 * or phrase.
	 */
	unsigned static int stripFrequency(std::string& line);
    
    
    
public:
    /*
     * Load the words in the stream into the dictionary
     */
    void static load_dict(DictionaryBST& dict, istream& words);
    
    
    /*
     * Load num_words from words stream into the dictionary
     */
    void static load_dict(DictionaryBST& dict, istream& words, unsigned int num_words);
    
    /*
     * Load the words in the file into the dictionary
     */
    void static load_dict(DictionaryHashtable& dict, istream& words);
    
    /*
     * Load num_words from words stream into the dictionary
     */
    void static load_dict(DictionaryHashtable& dict, istream& words, unsigned int num_words);
    
    
    /*
     * Load the words in the file into the dictionary
     */
    void static load_dict(DictionaryTrie& dict, istream& words);
    
    
    /*
     * Load num_words from words stream into the dictionary
     */
    void static load_dict(DictionaryTrie& dict, istream& words, unsigned int num_words);
    
    /*
     *Load words in the file into the vector
     */
    
    void static load_vector(std::vector<std::string>& dict, istream& words);
    
    /*
     * Load num_words from words stream into the vector
     */
    void static load_vector(std::vector<std::string>& dict, istream& words, unsigned int num_words);
    
    
    
    
};


#endif //UTIL_H
