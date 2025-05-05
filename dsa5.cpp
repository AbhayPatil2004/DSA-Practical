// Construct an expression tree from the given 
// prefix expression eg.+--a*bc/def and traverse it 
// using post order traversal (non- recursive) and 
// then delete the entire tree.

#include<iostream>
#include<stack>
using namespace std ;

class Node{

    public:
    char data ;
    Node* left ;
    Node* right ;

    Node( char ch ){
        this -> data = ch ;
        this -> left = NULL ;
        this -> right = NULL ;
    }
};

Node* insertData( string str ){

    stack<Node*> expression ;

    for( int i = str.size() - 1 ; i >= 0 ; i-- ){
        char ch = str[i] ;
        Node* newNode = new Node(ch);
        if( ch >= 'a' && ch <= 'z' ){
            expression.push(newNode);
        }
        else{
            newNode -> left = expression.top();
            expression.pop();
            newNode -> right = expression.top();
            expression.pop();
            expression.push(newNode);
        }
    }
    
    return expression.top();
}

void postOrder( Node* root ){

    if( !root ){
        return ;
    }
    stack<Node*> s1 , s2 ;
    s1.push(root);

    while( !s1.empty() ){

        Node* top = s1.top();
        s1.pop();
        s2.push(top) ;

        if( top -> left ){
            s1.push( top -> left );
        }
        if( top -> right ){
            s1.push( top -> right );
        }
    }

    while( !s2.empty() ){
        cout << s2.top() -> data << " ";
        s2.pop() ;
    }

    cout << endl;
}

void postorder( Node* root ){

    if( root == NULL ){
        return ;
    }
    postorder(root -> left );
    postorder(root -> right );
    cout << root -> data << " ";
}

void deleteTree( Node* root ){

    if( root == NULL ){
        return ;
    }
    deleteTree( root -> left );
    deleteTree( root -> right );

    delete root ;
}

int main(){

    string str = "+--a*bc/def";
    Node* root = insertData(str);
    // cout << root -> data ;
    postOrder(root) ;
    postorder(root);
    deleteTree(root);
    return 0;
}