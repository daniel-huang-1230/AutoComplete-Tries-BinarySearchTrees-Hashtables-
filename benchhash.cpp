#include<string>
#include<cstdlib>
#include <stdlib.h>

/**
 * Name: Daniel Huang
 * Date: 2/08/2017
 * Assignment: PA2
 */

/**The first hash function that would take a string as the key, and return
   a nontrivial hash value
   size: the size of the hash table
   Reference source: lecture 08, slide 14.
 */
int hashFunc1(std::string & key, int size) {
    int hashVal=0;
    for (int i=0; i<key.length();i++)
    {
        hashVal+=key[i];
        
    }
    return hashVal%size;
}


/**The first hash function that would take a string as the key, and return
 a nontrivial hash value
 size: the size of the hash table
 Reference source: stackoverflow, below is the URL
http://stackoverflow.com/questions/98153/whats-the-best-hashing-algorithm-to-use-on-a-stl-string-when-using-hash-map
 */
int hashFunc2(std::string & key, int size) {
    int hashVal=0;
    for(int i=0; i<key.length();i++){
        hashVal=hashVal*101 + key[i];
    }
    return hashVal%size;
}


int main(int argc, char* argv[]){
    
    
    
    
    return 0;
}
