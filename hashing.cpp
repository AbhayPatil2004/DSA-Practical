#include<iostream>
using namespace std ;

class hash{
	
	public:
	int arr[10] ;
	int count ;
	
	hash(){
		this -> count = 0 ;
		for( int i = 0 ; i < 10 ; i++ ){
			arr[i] = -1 ;
		}
	}
	
	void insert( int data ){
		
		int index = data % 10 ;
		if( arr[index] == -1 ){
			arr[index] = data ;
		}
		else if( count < 10) {
			while( count < 10 && arr[count] != -1 ){
				count ++ ;
			}
			if( count < 10 ){
				arr[count] = data ;
			}
			else{
				cout << "The Hash table is Full "<<endl;
			}
		}
	}
	
	void display(){
	
		for( int i = 0 ; i < 10 ; i++ ){
			cout << arr[i] << " " ;
		}
		
		cout << endl;
	}
};
															
int main(){

	hash h;
	for( int i = 0 ; i < 10 ; i++ ){
		int n ;
		cout << "Enter the Number "<< " " ;
		cin >> n ;
		h.insert(n);
	}
	cout << endl;	

	h.display();
	
	return 0 ;
}




