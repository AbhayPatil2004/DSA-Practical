//Beginning with an empty binary search tree, Construct binary search tree by inserting
//the values in the order given. After constructing a binary tree -
//i. Insert new node, ii. Find number of nodes in longest path from root, iii. Minimum data
//value found in the tree, iv. Change a tree so that the roles of the left and right pointers
//are swapped at every node, v. Search a value

#include<iostream>
using namespace std ;

class TreeNode{
	
	public:
	int data ;
	TreeNode* left ;
	TreeNode* right ;
	
	TreeNode( int val ){
		this -> data = val ;
		this -> left = NULL ;
		this -> right = NULL ;
	}
};

void insert( TreeNode* &root , int val ){
	
	if( root == NULL ){
		return ;
	}
		
	if( root -> left == NULL && root -> data > val ){
		TreeNode *temp = new TreeNode(val);
		root -> left = temp ;
		return ;
	}
	else if( root -> right == NULL && root -> data < val ){
		TreeNode *temp = new TreeNode(val);
		root -> right = temp ;
		return ;
	}
	else{
		insert( root -> left , val  );
		insert( root -> right , val  );
	}
	
}

void display( TreeNode* &root , int &n ){
	
	if( root == NULL ){
		return ;
	}
	if( root -> data < n ){
		n = root -> data ;
	}
	
	display( root -> left , n );
	cout << root -> data << " ";
	display( root -> right , n );
}


int main(){

	TreeNode *root = new TreeNode(10);
	
	insert( root , 9  );
	
	insert( root , 11  );
	
	insert( root , 8  );
	
	insert( root , 12 );
	
	insert( root , 7  );
	
	insert( root , 5  );
	
	insert( root , 15  );
	int n = 10000000;
	display(root,n);
	
	cout <<"Minimun Value is "<<n<<endl;
	return 0 ;
	
}






