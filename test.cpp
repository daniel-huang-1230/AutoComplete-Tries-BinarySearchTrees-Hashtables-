#include<iostream>
#include<string>
#include<algorithm>
#include<set>
#include<cstdlib>
#include "util.h"
#include "DictionaryTrie.h"
#include "DictionaryBST.h"
#include "DictionaryHashtable.h"
#define LETTERS 26
using namespace std;



/**
 * Name: Daniel Huang
 * Date: 1/23/2017
 * Assignment: PA2
 */

int main(int argc, char** argv)
{

  //Initialize words
  vector<std::string> words;
  vector<string>::iterator wit;
  vector<string>::iterator wen;
  //initialize nonwords
  set<string> nope;
  set<string>::iterator nit;
  set<string>::iterator nen;

  //Initialize data structures
  DictionaryBST d_bst;
  DictionaryHashtable d_ht;
  DictionaryTrie dt;
  int t_bst, t_ht, tt;

  words.push_back("harry");
  words.push_back("sriram");
  words.push_back("cse");
  words.push_back("crucio");
  words.push_back("autocomplete");
  
  
  cout << "Inserting into Dictionaries..." << endl;

  wit = words.begin();
  wen = words.end();
  for(; wit != wen; ++wit)
    {
      cout << "Inserting: \"" << *wit << "\"... ";
      t_bst = d_bst.insert(*wit);
      t_ht = d_ht.insert(*wit);
      tt = dt.insert(*wit, 1);
      //cout << t_bst << " " << t_ht << " "<< tt << "... ";
      if(!t_bst)
	{
	  cout << "failed for DictionaryBST... ";
	}
      if(!t_ht)
	{
	  cout << "failed for DictionaryHashset... ";
	}
      if(!tt)
	{
	  cout << "failed for DictionaryTrie... ";
	}
      if(t_bst && t_ht && tt)
	{
	  cout << "PASSED! :D ";
	}
      cout << endl;
    }

  cout << endl << "Re-inserting elements that were just inserted into Dictionaries..." << endl;

  wit = words.begin();
  wen = words.end();
  for(; wit != wen; ++wit)
    {
      cout << "Inserting: \"" << *wit << "\"... ";
      t_bst = d_bst.insert(*wit);
      t_ht = d_ht.insert(*wit);
      tt = dt.insert(*wit, 0);
      if(t_bst)
        {
          cout << "failed for DictionaryBST... ";
        }
      if(t_ht)
        {
          cout << "failed for DictionaryHashset... ";
        }
      if(tt)
        {
          cout << "failed for DictionaryTrie... ";
        }
      if(!t_bst && !t_ht && !tt)
        {
          cout << "PASSED! :D ";
        }
      cout << endl;
    }

  cout << endl;

  
/*You are supposed to add more test cases in this file */

    //test inserting empty world
    t_bst = d_bst.insert("");
    t_ht = d_ht.insert("");
    tt = dt.insert("", 0);
    
    //should not be inserted into any of these data structures
        if(tt)
    {
        cout << "failed for DictionaryTrie... ";
    }
    if(!tt)
    {
        cout << "PASSED the check for inserting empty string into Trie :D ";
        cout << endl;
    }

    
    //corner case where there is only one word in the dictionary
    DictionaryBST d_bst2;
    DictionaryHashtable d_ht2;
    DictionaryTrie dt2;
    if(d_bst2.find("apple"))
       {
           cout<<"the dictionary should be empty"<<endl;
       }
    
    if(d_ht2.find("apple"))
    {
        cout<<"the dictionary should be empty"<<endl;
    }
    if(dt2.find("apple"))
    {
        cout<<"the dictionary should be empty"<<endl;
    }
    
    cout<<"Passed the empty dictionary test :D"<<endl;
   
   
    //test the find() function with a small set of words

    vector<std::string> words2;
    words2.push_back("Daniel");
    words2.push_back("Johnny");
    words2.push_back("Alice/Claire");
    words2.push_back("Ramon");
    
    wit = words2.begin();
    wen = words2.end();
    for(; wit != wen; ++wit)
    {
        cout << "Inserting: \"" << *wit << "\"... ";
        t_bst = d_bst2.insert(*wit);
        t_ht = d_ht2.insert(*wit);
        tt = dt2.insert(*wit, 0);
        if(!t_bst)
        {
            cout << "failed for DictionaryBST... ";
        }
        if(!t_ht)
        {
            cout << "failed for DictionaryHashset... ";
        }
        if(!tt)
        {
            cout << "failed for DictionaryTrie... ";
        }
        if(t_bst && t_ht && tt)
        {
            cout<< "inserting "<<*wit<< " success!"<<endl;
                   }
        cout << endl;
    }
    
    cout << "Now proceed to test find()! :D "<<endl;

    wit = words2.begin();
    wen = words2.end();
    for(;wit!=wen;++wit){
        cout<<"Searching: \""<<*wit<<"\"...";
        if(!d_bst2.find(*wit)){
            cout<< "Failed to find "<<*wit<<"in DictionaryBST...";
        }
        if(!d_ht2.find(*wit)){
            cout<< "Failed to find "<<*wit<<"in DictionaryHashset...";
        }
        if(!dt2.find(*wit)){
            cout<< "Failed to find "<<*wit<<"in DictionaryTrIe...";
            
        }
        
        
        else {
            cout<<*wit<<" FOUND. PASSED! :D"<<endl;
        }
        cout<<endl;
    }

    //test for inserting empty string and searching for empty string
    if(d_bst.insert("")||d_ht.insert("")||dt.insert("",0)){
        cout<< "Failed to identify the case of inserting empty string"<<endl;
        
    }
    
    
    else if(d_bst.find("")||d_ht.find("")||dt.find("")){
        cout<< "Failed to identify the case of searching empty string"<<endl;
        
    }
    else{
        cout<<"Passed both tests for checking empty string :D"<<endl;
    }
    

    
    
//use the util.cpp functions to load dictionarys to my data structures(TODO)
   
    DictionaryTrie dict =DictionaryTrie();
    std::string a="att";
    std::string b="ate";
    
    std::string prefix="at";
    dict.insert(a,5);
    dict.insert(b,4);
    std::vector<std::string> vec=dict.predictCompletions(prefix, 3);
    for (std::vector<string>::const_iterator i = vec.begin(); i != vec.end(); ++i)
    {
        cout<< *i<<endl;
    }
    
    
    
  return 0;
}
