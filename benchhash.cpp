#include<string>
#include<cstdlib>
#include <stdlib.h>
#include<iostream>
#include <vector>
#include <fstream>
#include "util.h"
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
unsigned int hashFunc1(const std::string & key, int size) {
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

/*
 The main function that drives the benchhash program
 */
int main(int argc, char* argv[]){
    /* cout<<"testing the first hash function"<<endl;
     
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
     
     cout<<endl;
     */
    
    std::string str(argv[1]);
    std::string& dictfile=str;  //pass in the command line arguments
    unsigned int num_words = atoi(argv[2]);
    
    //start simulating inserting words from dictionary to a hash table and benchmarking
    
    cout<<"Printing the statistics for hashFunction1 with hash table size "<< num_words*2 <<endl;
    
    //a temporay vector into which we load the dictfile
    std:: vector<std::string> vec = std::vector<std::string>(num_words);
    
    ifstream in(dictfile);
    
    
    in.seekg(0, in.beg);
    Utils::load_vector(vec, in, num_words);
    
    //now iterate through every string in the temporary vec and
    //calculate the hash values of every string in it
    
    //initialize a simulated hash table of size=2*num_words
    std::vector<int> simHashtable=std::vector<int>(2*num_words);
    for (std::vector<string>::const_iterator i = vec.begin(); i != vec.end(); ++i)
    {
        int hashVal=hashFunc1(*i, num_words*2);
        simHashtable[hashVal]+=1; //record the hits
        
    }
    
    
    
    cout<<"#hits"<<"\t"<<"#slots receiving the #hits"<<endl;
    
    std::vector<int> hits =std::vector<int>(num_words*2+1);
    //the range of # of hits: 0~num_words
    
    for(int i=0;i<=num_words*2;i++){ //iterate over every possible # of
        // hits
        
        for(int j=0; j<simHashtable.size();j++)
        {
            if(simHashtable[j]==i)
            {
                hits[i]+=1;
                
            }
        }
    }
    
    
    
    for(int i=0;i<=num_words*2;i++) {
        if(hits[i]!=0){
            cout<<i<<"\t"<<hits[i]<<endl;
            
        }
    }
    
    int maxHits=0;
    for(int i=0; i<=num_words*2;i++){
        if(hits[i]!=0)
        {
            maxHits=i; //update the max # of hits
        }
    }
    float total=0;
    for(int i=0; i<=num_words*2;i++){
        int sum=0;
        for(int k=i; k<=maxHits;k++){
            
            sum=sum+hits[k];
        }
        if(hits[i]!=0){
            total=total+(sum*i);
        }
    }
    
    float average=total/num_words;
    
    cout<<"The average number of steps for a successful search for hash function 1 would be "<<average<<endl;
    
    
    
    cout<<"The worst case steps that would be needed to find a word is "<<maxHits<<endl;
    
    //now do the same but use the second hash function
    
    cout<<"Printing the statistics for hashFunction2 with hash table size "<< num_words*2 <<endl;
    
    std::vector<int> simHashtable2=std::vector<int>(2*num_words);
    for (std::vector<string>::const_iterator i = vec.begin(); i != vec.end(); ++i)
    {
        int hashVal=hashFunc2(*i, num_words*2); //use the second has function
        simHashtable2[hashVal]+=1; //record the hits
        
    }
    cout<<"#hits"<<"\t"<<"#slots receiving the #hits"<<endl;
    
    std::vector<int> hits2 =std::vector<int>(num_words*2+1);
    //the range of # of hits: 0~num_words
    
    for(int i=0;i<=num_words*2;i++){ //iterate over every possible # of
        // hits
        
        for(int j=0; j<simHashtable2.size();j++)
        {
            if(simHashtable2[j]==i)
            {
                hits2[i]+=1;
                
            }
        }
    }
    
    
    
    for(int i=0;i<=num_words*2;i++) {
        if(hits2[i]!=0){
            cout<<i<<"\t"<<hits2[i]<<endl;
            
        }
    }
    
    int maxHits2=0;
    for(int i=0; i<=num_words*2;i++){
        if(hits2[i]!=0)
        {
            maxHits2=i; //update the max # of hits
        }
    }
    float total2=0;
    for(int i=0; i<=num_words*2;i++){
        int sum=0;
        for(int k=i; k<=maxHits;k++){
            
            sum=sum+hits2[k];
        }
        if(hits2[i]!=0){
            total2=total2+(sum*i);
        }
    }
    
    float average2=total2/num_words;
    
    cout<<"The average number of steps for a successful search for hash function 1 would be "<<average2<<endl;
    
    
    
    cout<<"The worst case steps that would be needed to find a word is "<<maxHits2<<endl;
    
    
    
    
    
    return 0;
}
