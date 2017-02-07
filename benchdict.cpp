#include<iostream>
#include <fstream>
#include<string>
#include<algorithm>
#include<set>
#include<cstdlib>
#include "util.h"
#include "DictionaryTrie.h"
#include "DictionaryBST.h"
#include "DictionaryHashtable.h"
#include <stdlib.h>
/**
 * Name: Daniel Huang
 * Date: 2/06/2017
 * Assignment: PA2
 */


/**
 The program that performs the benchmarking of three data structures
 of dictionary
 
 min_size - The minimum size of the dictionary you want to test
 
 step_size - The step size (how much to increase the dictionary size each iteration)
 
 num_iterations - The number of iterations (e.g. how many times do you want to
 increase your dictionary size)
 
 dictfile - The name of a dictionary file to use
 **/
int main(int argc, char* argv[]) {
    //passed in the command line arguments
    int min_size=atoi(argv[1]);
    int step_size=atoi(argv[2]);
    int num_iterations=atoi(argv[3]);
    std::string str(argv[4]);
    std::string &dictfile=str;
    int MULTIPLERUNS=20;  // to avoid magic number in finding the average time
    
    cout<<"DictionaryBST"<<endl;
    cout<<endl;
    for(int i=0; i<num_iterations;i++){
        //allocate the data structure on the heap
        DictionaryBST * bst=new DictionaryBST();
        
        Timer timer;
        ifstream in(dictfile);
       
        
        in.seekg(0, in.beg); //reset the istream to the start
        
        int errorCode=Utils::load_dict(*bst, in, min_size + i*step_size);
        
        if(errorCode!=0){
            break; //to handle the edge case where the dictionary size is smaller
            
        }
        std::vector<std::string> vec;
        Utils::load_vector(vec, in, 500); //load the next 500 words into a vector
        
        
        //begin the timer
        
        long long totalTime=0;
        for(int run=0; run<MULTIPLERUNS;run++) {
            timer.begin_timer(); //start the timer
            
            
            for (std::vector<string>::const_iterator i = vec.begin(); i != vec.end(); ++i)
            {
                if(bst->find(*i)){
                    break; //if any of the 100 words is found, break-> it shouldn't
                    //happen though
                }
            }
            totalTime+= timer.end_timer(); //end the timer and add to the total
        }
        
        long long average=totalTime/MULTIPLERUNS; //calculate the average
        
        cout<<min_size+i*step_size<<"\t"<<average<<endl; //print out the average time
        cout<<endl;
        
        delete bst; //delete the dictionary to free up memory
    }
    
    
    
    
    cout<<"DictionaryHashtable"<<endl;
    cout<<endl;
    for(int i=0; i<num_iterations;i++){
        //allocate the data structure on the heap
        DictionaryHashtable * htb=new DictionaryHashtable();
        
        Timer timer;
        ifstream in(dictfile);
        
        
        in.seekg(0, in.beg); //reset the istream to the start
        

        int errorCode= Utils::load_dict(*htb, in, min_size + i*step_size);
        
        if(errorCode!=0){
            break; //to handle the edge case where the dictionary size is smaller
        }
        
        std::vector<std::string> vec;
        Utils::load_vector(vec, in, 500); //load the next 500 words into a vector
        
        
        //begin the timer
        
        long long totalTime=0;
        for(int run=0; run<MULTIPLERUNS;run++) {
            timer.begin_timer(); //start the timer
            
            
            for (std::vector<string>::const_iterator i = vec.begin(); i != vec.end(); ++i)
            {
                if(htb->find(*i)){
                    break; //if any of the 100 words is found, break-> it shouldn't
                    //happen though
                }
            }
            totalTime+= timer.end_timer(); //end the timer and add to the total
        }
        
        long long average=totalTime/MULTIPLERUNS; //calculate the average
        
        cout<<min_size+i*step_size<<"\t"<<average<<endl; //print out the average time
        cout<<endl;
        
        delete htb; //delete the dictionary to free up memory
    }

    
    cout<<"DictionaryTrie"<<endl;
    cout<<endl;
    for(int i=0; i<num_iterations;i++){
        //allocate the data structure on the heap
        DictionaryTrie * trie=new DictionaryTrie();
        
        Timer timer;
        ifstream in(dictfile);
        
        
        in.seekg(0, in.beg); //reset the istream to the start

        int errorCode=Utils::load_dict(*trie, in, min_size + i*step_size);
        
        if(errorCode!=0){
            break; //to handle the edge case where the dictionary size is smaller
        }

        
        std::vector<std::string> vec;
        Utils::load_vector(vec, in, 500); //load the next 500 words into a vector
        
        
        //begin the timer
        
        long long totalTime=0;
        for(int run=0; run<MULTIPLERUNS;run++) {
            timer.begin_timer(); //start the timer
            
            
            for (std::vector<string>::const_iterator i = vec.begin(); i != vec.end(); ++i)
            {
                if(trie->find(*i)){
                    break; //if any of the 100 words is found, break-> it shouldn't
                    //happen though
                }
            }
            totalTime+= timer.end_timer(); //end the timer and add to the total
        }
        
        long long average=totalTime/MULTIPLERUNS; //calculate the average
        
        cout<<min_size+i*step_size<<"\t"<<average<<endl; //print out the average time
        cout<<endl;
        
        delete trie; //delete the dictionary to free up memory
    }

    
    
    
    return 0;
}
