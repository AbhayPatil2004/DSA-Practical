//Implement all the functions of a dictionary (ADT) using hashing and handle collisions
//using chaining with / without replacement.
//Data: Set of (key, value) pairs, Keys are mapped to values, Keys must be comparable,
//Keys must be unique. Standard Operations: Insert(key, value), Find(key), Delete(key)

#include <iostream>
#include <vector>

using namespace std ;

class Node{
	
	public:
	int data ;
	Node *next ;
	
	Node( int val ){
		this -> data = val;
		this -> next = NULL ;
	}
};

class HashMap{
	
	public:
	vector<Node*> map ;
	
	HashMap(){
	
		for( int i = 0 ; i < 10 ; i++ ){
			map.push_back(NULL);
		}
	}
	
	void insert( int val ){
	
		Node* temp = new Node(val) ;
		int index = val % 10 ;
		
		if( map[index] == NULL ){
			map[index] = temp ;
		}
		else{
			Node* firstNode = map[index] ;
			while( firstNode -> next != NULL ){
				firstNode = firstNode -> next ;
			}
			firstNode -> next = temp ;
		}
	}
	
	void display(){
		
		for( int i = 0 ; i < 10 ; i++ ){
			
			if( map[i] == NULL ){
				cout << "NULL" ;
			}
			else{
				Node* temp = map[i] ;
				while( temp != NULL ){
					cout << temp -> data << " ";
					temp = temp -> next ;
				}
			}
			cout << endl;
		}
	}
	
	
	void search( int val ){
		
		int index = val % 10 ;
		if( map[index] == NULL ){
			cout << "Element not Found "<<endl;
			return ;
		}
		else{
			Node* temp = map[index] ;
			while( temp != NULL ){
				if( temp -> data == val ){
					cout <<"The value is Found at index "<<index <<endl;
					return ;
				}
				temp = temp -> next ;
			}
			
		}
		cout << "Element not Found "<<endl;
	
	}
	
	void remove( int val ){
		
		int index = val % 10 ;
		
		if( map[index] == NULL ){
			cout <<"Deletion is Not Possible as element not Found "<<endl;
			return ;
		}
		else{
			Node* temp = map[index] ;
			if( temp -> data == val ){
				cout << "The data is Succesfully Deletd "<<endl;
				map[index] = temp -> next ;
				temp -> next = NULL ;
				return ;
			}
			else{
				
				while( temp -> next != NULL ){
				
					if( temp -> next -> data == val ){
						cout << "The data is Succesfully Deletd "<<endl;
						temp -> next = temp -> next -> next ;
						return ;
					}
					
					temp = temp -> next ;
				}
			}
			cout <<"Deletion is Not Possible as element not Found "<<endl;
			
		}
		
	}
	
};

int main(){

	HashMap h ;
	int num ;
	int n ;
	
	do{
	
		cout << "Enter your Choice :-"<<endl;
		cout << " 1 :- Insert "<<endl;
		cout << " 2 :- Display "<<endl;
		cout << " 3 :- Search "<<endl;
		cout << " 4 :- Delete "<<endl;
		cout << " 5 :- Exit "<<endl;
		cin >> n ;
		
		switch(n){
		
			case 1 :
				
				cout << "Enter the Number to be Insert "<<endl;
				cin >> num ;
				h.insert(num);
				break ;
				
			case 2 :
				h.display();
				break ;
				
			case 3 :
				cout << "Enter the Number to be Search "<<endl;
				cin >> num ;
				h.search(num);
				break ;
				
			case 4 :
				cout << "Enter the Number to be Delete "<<endl;
				cin >> num ;
				h.remove(num);
				break ;
				
			case 5 :
				cout <<"You exit Succesfully "<<endl;
				break ;
				
			default :
				cout <<"Invalid Choice "<<endl;
		}
	
	}while( n > 0 && n < 5 );
	
	return 0 ;

}




