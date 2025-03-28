#include<iostream>

using namespace std ;

class hash{
	
	public:
	int size ;
	int *arr ;
	int count ;
	
	hash( int n ){
	
		this -> size = n ;
		arr = new int[size];
		this -> count = 0 ;
		for( int i = 0 ; i < size ; i++ ){
			arr[i] = -1 ;
		}
	}
	
	void insert( int data ){
		
		int index = data % 10 ;
		if( index < size && arr[index] == -1 ){
			arr[index] = data ;
		}
		else if( count < size) {
			while( count < size && arr[count] != -1 ){
				count ++ ;
			}
			if( count < size ){
				arr[count] = data ;
			}
			else{
				cout << "The Hash table is Full "<<endl;
			}
		}
	}
	
	void input(){
		
		int n ;
		for( int i = 0 ; i < size ; i++){
			cout << "Enter the Data "<<" ";
			cin >> n ;
			insert(n) ; 
		}
	}
	
	int search( int key ){
		
		for( int i = 0 ; i < size ; i++ ){
			if( arr[i] == key ){
				cout <<"Key found at index "<< i << endl;
				return i ;
			}
		}
		
		cout<<"Key not Found "<<endl;
		return -1 ;
	}
	
	void remove( int key ){
		int n = search( key );
		
		if( n != -1 ){
			cout <<" Key succsesfully Deleted "<<endl;
			arr[n] = -1 ;
		}
		else{
			cout <<"Key deletion not Posible "<<endl;
		}
	}
	
	void display(){
	
		for( int i = 0 ; i < size ; i++ ){
			cout << arr[i] << " " ;
		}
		
		cout << endl;
	}
};
															
int main(){
	
	int n ;
	cout << "Enter the Size of HashTable "<<endl;
	cin >> n ;
	hash h(n);
	h.input() ;
	h.display();
	h.search(154564) ;
	h.search(8) ;
	h.remove(12);
	h.remove(21256);
	
	return 0 ;
}

/*
(base) comp-proj-sys04@compprojsys04-OptiPlex-3010:~/Abhay Comp B2$ g++ FinalDSA1.cpp
(base) comp-proj-sys04@compprojsys04-OptiPlex-3010:~/Abhay Comp B2$ ./a.out
Enter the Size of HashTable 
5
Enter the Data  1
Enter the Data  2
Enter the Data  3
Enter the Data  4
Enter the Data  5
5 1 2 3 4 
Key not Found 
Key not Found 
Key not Found 
Key deletion not Posible 
Key not Found 
Key deletion not Posible 
(base) comp-proj-sys04@compprojsys0

*/

