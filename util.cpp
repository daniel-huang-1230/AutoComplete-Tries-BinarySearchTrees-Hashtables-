#include <iostream>
#include <sstream>
#include "util.h"

using std::istream;
using std::endl;
using std::cout;
using std::istringstream;
using std::string;
using std::vector;

/*
 * Starts the timer. Saves the current time.
 */
void Timer::begin_timer()
{
    
    start = std::chrono::high_resolution_clock::now();
}

/*
 * Ends the timer. Compares end time with the start time and returns number of nanoseconds
 */
long long Timer::end_timer()
{
    
    std::chrono::time_point<std::chrono::high_resolution_clock> end;
    end = std::chrono::high_resolution_clock::now();
    
    return (long long)std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count();
}

/* Parse a line from a dictionary file.  This line has the frequency as 
 * the first string, and the "word" (which may be a multi-word phrase)	
 * as the rest of the string.  This function will remove the frequency,
 * leaving "word".  It assumes the first set of characters before the 
 * space is the number, and will always remove it.  If there is no space
 * before the end of the line, it will not change the string.
 *
 * Input: a line from a dictionary file.  This line will be modified.
 */
unsigned int Utils::stripFrequency(string& line)
{
    // Count the number of characters past the first space
    int count = 0;
    string::iterator last = line.end();
    for (string::iterator it = line.begin(); it != last; ++it) {
        count++;
        if (*it == ' ') {
            break;
        }
    }
    unsigned int freq = std::stoi(line.substr(0, count));
    line.erase(0, count);
    return freq;
}


/* 
 * Load all of the words from the stream, words, into the vector, vec, in 
 * the order in which they appear in the stream. 
 */
void Utils::load_vector(vector<string>& vec, istream& words)
{
    
    string line = "";
    while (1) {
        getline(words, line);
        if (words.eof())
            break;
        Utils::stripFrequency(line);
        vec.push_back(line);
    }
}

/* 
 * Load num_words words from the stream, words, into the vector, vec, in 
 * the order in which they appear in the stream. 
 */
void Utils::load_vector(vector<string>& vec, istream& words, unsigned int num_words)
{
    string line = "";
    for (unsigned int i = 0; i < num_words; i++) {
        getline(words, line);
        if (words.eof()) {
            std::cout << "Warning!  Only " << i << " words read from file." << endl;
            break;
        }
        Utils::stripFrequency(line);
        vec.push_back(line);
    }
}

/* 
 * Load all of the words from the stream, words, into the BST-backed 
 * dictionary, dict.
 */
void Utils::load_dict(DictionaryBST& dict, istream& words)
{
    
    string line = "";
    while (1) {
        getline(words, line);
        if (words.eof())
            break;
        Utils::stripFrequency(line);
        dict.insert(line);
    }
}

/* 
 * Load num_words words from the stream, words, into the BST-backed 
 * dictionary, dict.
 */
void Utils::load_dict(DictionaryBST& dict, istream& words, unsigned int num_words)
{
    string line = "";
    for (unsigned int i = 0; i < num_words; i++) {
        getline(words, line);
        if (words.eof()) {
            std::cout << "Warning!  Only " << i << " words read from file." << endl;
            break;
        }
        Utils::stripFrequency(line);
        dict.insert(line);
    }
}

/* 
 * Load all of the words from the stream, words, into the Hashtable-backed 
 * dictionary, dict.
 */
void Utils::load_dict(DictionaryHashtable& dict, istream& words)
{
    
    string line = "";
    while (1) {
        getline(words, line);
        if (words.eof())
            break;
        Utils::stripFrequency(line);
        dict.insert(line);
    }
}

/* 
 * Load num_words words from the stream, words, into the Hashtable-backed 
 * dictionary, dict.
 */
void Utils::load_dict(DictionaryHashtable& dict, istream& words, unsigned int num_words)
{
    string line = "";
    for (unsigned int i = 0; i < num_words; i++) {
        getline(words, line);
        if (words.eof()) {
            std::cout << "Warning!  Only " << i << " words read from file." << endl;
            break;
        }
        Utils::stripFrequency(line);
        dict.insert(line);
    }
}

/* 
 * Load all of the words from the stream, words, into the Trie-backed 
 * dictionary, dict.
 */
 void Utils::load_dict(DictionaryTrie& dict, istream& words)
{
    
    string line = "";
    while (1) {
        getline(words, line);
        if (words.eof())
            break;
        unsigned int freq = Utils::stripFrequency(line);
        dict.insert(line, freq);
    }
}

/* 
 * Load num_words words from the stream, words, into the Trie-backed 
 * dictionary, dict.
 */
void Utils::load_dict(DictionaryTrie& dict, istream& words, unsigned int num_words)
{
    string line = "";
    for (unsigned int i = 0; i < num_words; i++) {
        getline(words, line);
        if (words.eof()) {
            std::cout << "Warning!  Only " << i << " words read from file." << endl;
            break;
        }
        unsigned int freq = Utils::stripFrequency(line);
        dict.insert(line, freq);
    }
}
