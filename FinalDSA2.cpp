//Implement all the functions of a dictionary (ADT) using hashing and handle collisions
//using chaining with / without replacement.
//Data: Set of (key, value) pairs, Keys are mapped to values, Keys must be comparable,
//Keys must be unique. Standard Operations: Insert(key, value), Find(key), Delete(key)

#include <iostream>
#include <vector>
using namespace std ;

class Node{
	
	public : 
	
	int key ;
	int val ;
	Node* next ;
	
	Node( int key , int val ){
		this -> key = key ;
		this -> val = val ;
		this -> next = NULL ;
	}
};

class dict{
	
	public :
	
	vector<Node*> map ;
	dict(){
		for( int i = 0 ; i < 10 ; i++ ){
			map.push_back(NULL);
		}
	}
	
	
	void insert( int key , int val ){
		
		Node* temp = new Node( key , val );
		int index = key % 10 ;
		if( map[index] == NULL ){
			map[index] = temp ;
			cout << "Key is Successfully inserted "<<endl;
			return ;
		}
		else{
			Node* temp = map[index] ;
			while( temp -> next != NULL ){
				if( temp -> key == key ){
					temp -> val = val ;
					cout << "The Key value is Updated Succesfully "<<endl;
					return ;	
				}
			}
			if( temp -> key == key ){
				temp -> val = val ;
				cout << "The Key value is Updated Succesfully "<<endl;
				return ;	
			}
			Node *newNode = new Node( key , val );
			temp -> next = newNode ;
			cout << "Key is Successfully inserted "<<endl;
			
		}
	}
	
	void display(){
		
		cout << endl;
		for( int i = 0 ; i < 10 ; i++ ){
			
			if( map[i] == NULL ){
				cout << "NULL" ;
			}
			else{
				Node* temp = map[i] ;
				while( temp != NULL ){
					cout << temp -> key << " :- " << temp -> val << "  ";
					temp = temp -> next ;
				}
			}
			cout << endl;
		}
		cout<<endl;
	}
	
	void search( int key ){
		
		int index = key % 10 ;
		if( map[index] == NULL ){
			cout <<"Key not Found "<<endl;
			return ;
		}
		Node* temp = map[index] ;
		
		while( temp != NULL ){
			if( temp -> key == key ){
				cout << "Key Successfully Found and its value is "<<temp -> val << endl;
				return ;
			}
			temp = temp -> next ;
		}
		
		cout <<"Key not Found "<<endl;
	}
	
	void remove( int key ){
		
		int index = key % 10 ;
		
		if( map[index] == NULL ){
			cout <<"Deletion is Not Possible as key not Found "<<endl;
			return ;
		}
		else{
			
			Node *temp = map[index];
			if( temp -> key == key ){
				map[index] = temp -> next ;
				cout <<"The key is SuccessFully Deleted "<<endl;
				return ;
			}
			
			while( temp -> next != NULL ){
			
				if( temp -> next -> key == key ){
					temp -> next = temp -> next -> next ;
					cout <<"The key is SuccessFully Deleted "<<endl;
					return ;
				}
				temp = temp -> next ;
			}
		}
		
		cout <<"Deletion is Not Possible as key not Found "<<endl;
	}
	
};

int main(){

	dict d ;
	
	int key ;
	int val ;
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
				
				cout << "Enter the key to be Insert "<<endl;
				cin >> key ;
				cout << "Enter the value of key "<<endl;
				cin>>val;
				d.insert( key , val );
				break ;
				
			case 2 :
				d.display();
				break ;
			
			case 3 :
				cout << "Enter the Key to be Search "<<endl;
				cin >> key ;
				d.search(key);
				break ;
				
			case 4 :
				cout << "Enter the Key to be Delete "<<endl;
				cin >> key ;
				d.remove(key);
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



/*
(base) comp-proj-sys04@compprojsys04-OptiPlex-3010:~/Abhay Comp B2$ g++ FinalDSA2.cpp
(base) comp-proj-sys04@compprojsys04-OptiPlex-3010:~/Abhay Comp B2$ ./a.outEnter your Choice :-
 1 :- Insert 
 2 :- Display 
 3 :- Search 
 4 :- Delete 
 5 :- Exit 
1
Enter the key to be Insert 
1
Enter the value of key 
10
Key is Successfully inserted 
Enter your Choice :-
 1 :- Insert 
 2 :- Display 
 3 :- Search 
 4 :- Delete 
 5 :- Exit 
1
Enter the key to be Insert 
2
Enter the value of key 
20
Key is Successfully inserted 
Enter your Choice :-
 1 :- Insert 
 2 :- Display 
 3 :- Search 
 4 :- Delete 
 5 :- Exit 
1
Enter the key to be Insert 
3
Enter the value of key 
30
Key is Successfully inserted 
Enter your Choice :-
 1 :- Insert 
 2 :- Display 
 3 :- Search 
 4 :- Delete 
 5 :- Exit 
1
Enter the key to be Insert 
4
Enter the value of key 
40
Key is Successfully inserted 
Enter your Choice :-
 1 :- Insert 
 2 :- Display 
 3 :- Search 
 4 :- Delete 
 5 :- Exit 
1
Enter the key to be Insert 
5
Enter the value of key 
50
Key is Successfully inserted 
Enter your Choice :-
 1 :- Insert 
 2 :- Display 
 3 :- Search 
 4 :- Delete 
 5 :- Exit 
2

NULL
1 :- 10  
2 :- 20  
3 :- 30  
4 :- 40  
5 :- 50  
NULL
NULL
NULL
NULL

Enter your Choice :-
 1 :- Insert 
 2 :- Display 
 3 :- Search 
 4 :- Delete 
 5 :- Exit 
3
Enter the Key to be Search 
4
Key Successfully Found and its value is 40
Enter your Choice :-
 1 :- Insert 
 2 :- Display 
 3 :- Search 
 4 :- Delete 
 5 :- Exit 
3
Enter the Key to be Search 
6
Key not Found 
Enter your Choice :-
 1 :- Insert 
 2 :- Display 
 3 :- Search 
 4 :- Delete 
 5 :- Exit 
4
Enter the Key to be Delete 
4
The key is SuccessFully Deleted 
Enter your Choice :-
 1 :- Insert 
 2 :- Display 
 3 :- Search 
 4 :- Delete 
 5 :- Exit 
2

NULL
1 :- 10  
2 :- 20  
3 :- 30  
NULL
5 :- 50  
NULL
NULL
NULL
NULL

Enter your Choice :-
 1 :- Insert 
 2 :- Display 
 3 :- Search 
 4 :- Delete 
 5 :- Exit 
5
You exit Succesfully 
(base) comp-proj-sys04@compprojsys04-OptiPlex-3010:~/Abhay Comp B2$ 

*/
