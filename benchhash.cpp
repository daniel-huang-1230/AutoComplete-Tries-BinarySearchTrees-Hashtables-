#include<string>
#include<cstdlib>
#include <stdlib.h>
#include<iostream>
using namespace std;
/**
 * Name: Daniel Huang
 * Date: 2/08/2017
 * Assignment: PA2
 */

/**The first hash function that would take a string as the key, and return
   a nontrivial hash value
   size: the size of the hash table
   Reference/source: lecture 08, slide 14.
 */
unsigned int hashFunc1(std::string & key, int size) {
    int hashVal=0;
    for (int i=0; i<key.length();i++)
    {
        hashVal+=key[i];
        
    }
    return hashVal%size;
}


/**The second hash function that would take a string as the key, and return
 a nontrivial hash value. The function is called JSHash
 size: the size of the hash table
  Reference/source: http://www.partow.net/programming/hashfunctions/#top
 */
unsigned int hashFunc2(const std::string& key, int size)
{
    unsigned int hash = 1315423911;
    
    for(std::size_t i = 0; i < key.length(); i++)
    {
        hash ^= ((hash << 5) + key[i] + (hash >> 2));
        
    }
    
    return hash%size;
}

int main(int argc, char* argv[]){
    cout<<"testing the first hash function"<<endl;
    
    //print them all out and verify the hash values by hand
    string s1="APPLE";
    cout<< hashFunc1(s1, 10)<<endl;
    
    string s2="dam";
    cout<< hashFunc1(s2, 10)<<endl;
    
    string s3="yeah";
    
    cout<< hashFunc1(s3, 10)<<endl;
    
    cout<<"testing the second hash function"<<endl;
    
    //print them all out and verify the hash values by hand
    cout<< hashFunc2(s1, 10)<<endl;
    
    cout<< hashFunc2(s2, 10)<<endl;
    
    
    cout<< hashFunc2(s3, 10)<<endl;
    
    
    
    return 0;
}
