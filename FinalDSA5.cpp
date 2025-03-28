//Construct an expression tree from the given prefix expression eg. +--a*bc/def and
//traverse it using post order traversal (non recursive) and then delete the entire tree.

#include <iostream>
#include<stack>
using namespace std ;

class Node{
	
	public:
	char data ;
	Node* left ;
	Node* right ;
	
	Node( char val ){
		this -> data = val;
		this -> left = NULL ;
		this -> right = NULL ;
	}

};

void create( Node* &root ){

	string str = "+--a*bc/def";
	stack<Node*> s ;
	
	for( int i = 0 ; i < str.size() ; i++ ){
		if( str[i] >= 'a' && str[i] <= 'z' ){
			Node* temp = new Node( str[i] );
			s.push(temp);
		}
	}
	for( int i = 0 ; i < str.size() ; i++ ){
		
		if( str[i] == '+' || str[i] == '-' || str[i] == '*' || str[i] == '/' ){
			
			Node* ope1 = s.top();
			s.pop();
			Node* ope2 = s.top();
			s.pop();
			Node* operand = new Node(str[i]);
			operand -> left = ope1 ;
			operand -> right = ope2 ;
			s.push(operand);
		}
	}
	root = s.top();
	
}

void postOrder( Node* &root ){
	
	if( root == NULL ){
		return ;
	}
	
	postOrder( root -> left );
	postOrder( root -> right );
	cout << root -> data << " ";
	
}

int main(){

	Node* root ;
	create( root );
	//preOrder(root);
	cout << endl;
	//inOrder(root);
	cout << endl;
	postOrder(root);
	
	return 0 ;
	
}

/*
(base) comp-proj-sys04@compprojsys04-OptiPlex-3010:~/Abhay Comp B2$ g++ FinalDSA5.cpp
(base) comp-proj-sys04@compprojsys04-OptiPlex-3010:~/Abhay Comp B2$ ./a.out

f e + d - c - b * a / (base) comp-proj-sys04@compprojsys04-OptiPlex-3010:~/Abhay Comp B2$ 

*/
