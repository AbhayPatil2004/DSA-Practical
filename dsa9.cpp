// A Dictionary stores keywords & its meanings. Provide facility for adding new keywords, 
// deleting keywords, updating values of any entry. Provide facility to display whole data sorted in 
// ascending/ Descending order. Also find how many maximum comparisons may require for 
// finding any keyword. Use Height balance tree and find the complexity for finding a keyword 

#include<iostream>
using namespace std ;

class TrieNode{

    public:
    char data ;
    TrieNode* children[26];
    bool isTerminal ;

    TrieNode( char ch ){
        this -> data = ch ;
        for( int i = 0 ; i < 26 ; i++ ){
            children[i] = NULL ;
        }
        isTerminal = false ;
    }
};

class Trie{

    public:
    TrieNode* root ;

    Trie(){
        root = new TrieNode('\0');
    }

    void insertUtil( TrieNode* root , string word ){

        if( word.length() == 0 ){
            root -> isTerminal = true ;
            return ;
        }

        int index = word[0] - 'a' ;
        TrieNode* child;

        if (root->children[index] != NULL) {
            child = root->children[index];
        } else {
            child = new TrieNode(word[0]);
            root->children[index] = child;
        }

        insertUtil( child , word.substr() );

    }

    // void searchUtil( TrieNode* root , string word , bool &flag ){

    //     int i = 0 ;
    //     TrieNode* temp = root ;

    //     while( temp != NULL && i < word.size() ){

    //         int index = word[i] - 'a';
    //         if( temp -> children[index] == NULL ){
    //             flag = false ;
    //             return ;
    //         }
    //         else{
    //             temp = temp -> children[index] ;
    //         }
    //         i++ ;
    //     }
    //     if( temp == NULL && i == word.size() ){
    //         flag = true ;
    //     }
    //     else if( temp == NULL && i != word.size() ){
    //         flag = false ;
    //     }
    //     else if( i == word.size() && temp -> isTerminal ){
    //         flag = true ;
    //     }
    //     else{
    //         flag = false ;
    //     }
    // }

    void searchUtil(TrieNode* root, string word, bool &flag) {
        TrieNode* temp = root;
        
        for (int i = 0; i < word.size(); i++) {
            int index = word[i] - 'a';
            if (temp->children[index] == NULL) {
                flag = false;
                return;
            }
            temp = temp->children[index];
        }
    
        
        flag = temp->isTerminal;
    }

    void insertWord(string word){
        insertUtil( root , word );
    }
    void searchWord( string word ){
        bool flag = true ;
        searchUtil( root , word , flag );

    }
};

int main(){

    Trie t ;
    t.insertWord("abcd");
}