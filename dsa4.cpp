// Beginning with an empty binary search tree, 
// construct binary search tree by inserting values in 
// the order given. After constructing a binary tree 
// i. Insert new node 
// ii.  Find number of nodes in longest path 
// iii.  Minimum data value found in the tree 
// iv. Change a tree so that the roles of the left 
// and right pointers are swapped at every 
// node.

#include<iostream>
using namespace std ;

class Node{

    public:
    int data ;
    Node* left ;
    Node* right ;

    Node( int n ){
        this -> data = n ;
        this -> left = NULL ;
        this -> right = NULL ;
    }
};

void insertNode( Node* &root , int n ){

    if( root == NULL ){
        root = new Node(n);
        return ;
    }
    
    if( root -> data > n ){
        insertNode( root -> left , n );
    }
    else{
        insertNode( root -> right , n );
    }
}

int longestPath( Node* root ){

    if( root == NULL ){
        return 0 ;
    }

    int left = longestPath( root -> left );
    int right = longestPath( root -> right );

    return max( left , right ) + 1 ;
}

int minimum( Node* root ){

    while( root -> left != NULL ){
        root = root -> left ;
    }
    return root -> data ;
}

void swap( Node* &root ){

    if( root == NULL ){
        return ;
    }

    Node* temp = root -> left ;
    root -> left = root -> right ;
    root -> right = temp ;

    swap( root -> left );
    swap( root -> right );
}

void inorder( Node* root ){

    if( root == NULL ){
        return ;
    }
    
    inorder( root -> left );
    cout << root -> data << " ";
    inorder( root -> right );
}

int main() {
    Node* root = NULL;

    // Initial BST construction
    int values[] = {10, 5, 15, 3, 7, 18};
    for (int val : values) {
        insertNode(root, val);
    }

    cout << "In-order";
    inorder(root);
    // i. Insert new node
    insertNode(root, 8);

    // ii. Find number of nodes in longest path
    cout << "Height (Longest Path): " << longestPath(root) << endl;

    // iii. Minimum data value
    cout << "Minimum value: " << minimum(root) << endl;

    // iv. Swap left and right pointers
    swap(root);
    
    cout << "In-order after swapping: ";
    inorder(root);
    cout << endl;

    return 0;
}
