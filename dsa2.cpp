// Implement all the functions of dictionary 
// (ADT) using hashing and handle collisions 
// using chaining with / without replacement. 
// Data: Set of (key, value) pairs, Keys are 
// mapped to values, Keys must be comparable, 
// a) Keys must be unique. 
// b) Standard Operations: Insert (key, value), 
// Find(key), Delete(key) 

#include<iostream>
#include<vector>
using namespace std ;

class Node{

    public:
    int key ;
    int val ;
    Node* next ;

    Node( int k , int v ){
        this -> key = k ;
        this -> val = v ;
        this -> next = NULL ;
    }
};

class Dict{

    public:
    vector<Node*> data ;

    Dict(){
        data.resize( 10 , NULL );
    }

    void insertData( int key , int val ){

        int index = key % 10 ;
        Node* head = data[index] ;

        if( head == NULL ){
            head = new Node( key , val );
            data[index] = head ;
            cout << "Data Succesfully Inserted "<<endl;
        }
        else{
            Node* temp = head ;
            while( temp != NULL ){

                if( temp -> key == key ){
                    temp -> val = val ;
                    cout << "The key Value is Succesfully Updated "<<endl;
                    return ;
                }
                if( temp -> next == NULL ){
                    break ;
                }
                temp = temp -> next ;
            }
            Node* newNode = new Node( key , val );
            temp -> next = newNode ;
            cout << "Data Succesfully Inserted "<<endl;
        }
    }

    void showData( int key ){

        int index = key % 10 ;
        Node* head = data[index] ;
        Node* temp = head ;

        while( temp != NULL ){

            if( temp -> key == key ){
                cout << "The Key Value is :- "<<temp -> val <<endl;
                return ;
            }
            temp = temp -> next ;
        }
        cout <<"The key not Found "<<endl;
    }

    void displayData(){

        for( int i = 0 ; i < 10 ; i++ ){

            Node* temp = data[i] ;

            while( temp != NULL ){
                cout << temp -> key <<":"<<temp -> val << " -> ";
                temp = temp -> next ;
            }
            cout << endl;
        }
    }
};

int main(){

    Dict d;
    d.insertData(10, 20);
    d.insertData(20, 100);
    d.insertData(30, 202);
    d.insertData(10, 205); // update
    d.insertData(11, 205);
    d.insertData(21, 255);

    d.showData(10);
    d.showData(22);
    d.showData(20);

    d.displayData();
}