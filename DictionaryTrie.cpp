#include "util.h"
#include "DictionaryTrie.h"

/**
 * Name: Daniel Huang
 * Date: 2/05/2017
 * Assignment: PA2
 */




/*the helper functions from the Node class to return the child node ptr*/
Node* Node:: findChild(char c){
    
    for(int i=0; i<children.size();i++){
        Node* temp=children.at(i);
        if(temp->content()==c){
            
            return temp; //the character is found
        }
    }
    return NULL;  //character not found
}



/* Create a new Dictionary that uses a Trie back end */
DictionaryTrie::DictionaryTrie(){
    root=new Node(); // initialize the root node
}

/* Insert a word with its frequency into the dictionary.
 * Return true if the word was inserted, and false if it
 * was not (i.e. it was already in the dictionary or it was
 * invalid (empty string) */
bool DictionaryTrie::insert(std::string word, unsigned int freq)
{
    Node* curr = root; //set the curr to root first
    
    if(word.length()==0||find(word)){ //if trying to insert an empty string
        return false; //or the word is already present, so return false
    }
    
    
    //ready to insert
    for(int i=0;i<word.length();i++) {
        Node* child = curr->findChild(word[i]);
        if(child!=NULL){ //the character is already in the  dictionary
        
            curr=child; //traverse to the child node
            
        }
        else { //character not in the dictionary
            Node* temp=new Node();
            temp->setContent(word[i]); //set the character
            curr->addChild(temp); //add the node
            
            temp->wordStr=curr->wordStr + temp->content();
            
            curr=temp; //update the curr node ptr
            
            
        }
        if(i==word.length()-1) {
            //when we have reach the last character of the word
            curr->setWordNode(); //label the curr node as word node
            curr->setFreq(freq); //set the frequency only at the word node
        }
        
    }
    
    return true;  //successful insertion
}

/* Return true if word is in the dictionary, and false otherwise */
bool DictionaryTrie::find(std::string word) const
{
    Node* curr=root; //start from the root
    while(curr!=NULL) {
        for(int i=0;i<word.length();i++){
            Node* temp=curr->findChild(word[i]);
            if(temp==NULL){
                return false; //return immediately if any character
                // is not present
            }
            curr=temp; //update curr ptr
        }
        //finished while loop
        if(curr->wordNode()){
            return true; //only return true when reaching word node
        }
        else{
            return false;
        }
        
        
    }
    
    return false;
}



/*The implementation of the private DFS method*/
void DictionaryTrie::DFS(Node* start,std::set<std::pair<unsigned int,std::string>> &freqSet){
    
    std::stack<Node *> stack= std::stack<Node *>(); //initialize the stack
    stack.push(start);
    Node* curr=start;
    while(!stack.empty()){
        
        stack.pop();
        if(curr->wordNode()){
            std::pair< unsigned int, std::string> wordPair;
            wordPair=make_pair(curr->getFreq(),curr->wordStr); //construct the pair
            
            freqSet.insert(wordPair); //insert the pair into the BST
        }
        for(int i=0;i<curr->getChildren().size();i++){
            stack.push(curr->getChildren()[i]); //push each children into the stack
        }
        if(!stack.empty()) {
            curr=stack.top(); }//point to the top of the stack
    }
    //done searching
    
}

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
std::vector<std::string> DictionaryTrie::predictCompletions(std::string prefix, unsigned int num_completions)
{
    //vector initialized empty
    std::vector<std::string> vec = std::vector<std::string>();
    
    Node* curr= root; //start from the root
    
    if(prefix==""||curr==NULL) {
        //check for invalid input first(empty prefix) or empty trie
        cout<<"Invalid Input. Please retry with correct input"<<endl;
        return vec;
    }
    
        for(int i=0; i<prefix.length();i++){
            
            Node* temp=curr->findChild(prefix[i]);
           if(temp==NULL){
                //if the character in the prefix is not in the dictionary trie
                cout<<"Invalid Input. Please retry with correct input"<<endl;
                return vec;
            }
            curr=temp; //update the curr node
        }
    
    //now we've travered to the last character of the prefix, ready to search
    //for completions
    if(find(prefix)){
        
    }
    std:: set<std::pair<unsigned int, std::string>> freqSet= std:: set<std::pair<unsigned int,std::string>>();
    //instantiate a set (BST) to store the word pair
    
    DFS(curr,freqSet); //call DFS
    
    
    
    
    //return an iterator pointing to the last object in the set
    std:: set<std::pair<unsigned int, std::string>>::reverse_iterator ite=freqSet.rbegin();
    
    
    if(freqSet.size()<num_completions) {  //if there are fewer completions than
                                          //num_completions
        for(int i=0; i<freqSet.size();i++) {
            vec.push_back((*ite).second);
            ite ++;
                    }
        
    }
    
    else{
        //num_completions
        for(int i=0; i<num_completions;i++) {
            vec.push_back((*ite).second);
            ite ++;
        }
    }
   
       
    return vec; //return the final vector containing the words with top n_complemetion
    //frequencies

}







// the helper method that would delete all node pointers in the trie
void DictionaryTrie::deleteAll(Node* n){
    if(n->getChildren().size()==0) {
        delete n;
        return;
    }
    
    for(int i=0;i<n->getChildren().size();i++){
        deleteAll(n->getChildren()[i]);
        
    }
    delete n;
}

/* Destructor */
DictionaryTrie::~DictionaryTrie(){
    
    deleteAll(root);
    
    //---delete all dynamically allocated memory
    
}
