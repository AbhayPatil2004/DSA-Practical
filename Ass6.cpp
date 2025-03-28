#include<iostream> 
#include<vector>
using namespace std ;

class graph{

	public:
	int arr[100][100] ;
	int row , col ;
	
	graph(){
		for( int i = 0 ; i < 100 ; i++ ){
			for( int j = 0 ; j < 100 ; j++ ){
				arr[i][j] = 0 ;
			}
		}
	}
	
	void vertex( ){
		int n ;
		cout << "Enter the Number of Vertex :- "<<endl;
		cin >> n ;
		row = n ;
		col = n ;
		
		for( int i = 0 ; i < n ; i++ ){
			int temp ;
			cout << "Enter the Vertex Number "<< i + 1 << endl;
			cin >> temp ;
			arr[i][0] = temp ;
		}
	
	}
	
	void edges( ){
	
		for( int i = 0 ; i < row ; i++ ){
			cout <<"Enter the Edges btn "<< i + 1 << "vertex to other vertex :- "<<endl;
			
			for( int j = 1 ; j <= col ; j++ ){
				int temp ;
				cout <<"Enter the Edge btn "<< i + 1 << "vertex to " << j + 1 <<"vertex :-"<<endl;
				cin >> temp ;
				
				
			}
		}
	}
	
	
};	

