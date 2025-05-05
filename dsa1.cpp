// Consider telephone book database of N 
// clients. Make use of a hash table 
// implementation to quickly lookup client‘s 
// telephone number. Make use of two collision 
// handling techniques and compare them using 
// number of comparisons required to find a set 
// of telephone numbers. 

#include<iostream>
#include<vector>
using namespace std ;

class telephone{
        
    public:
    vector<int> user;
    

    telephone() : user(10, -1){
    };

    void insertData(int data) {
        int index = data % 10;
        int comparisons = 1;

        int start = index;
        while (user[index] != -1) {
            index = (index + 1) % 10;
            comparisons++;

            if (index == start) {
                cout << "Hash table is full, can't insert " << data << endl;
                return;
            }
        }

        user[index] = data;
        cout << "Inserted " << data << " at index " << index
             << " (Comparisons: " << comparisons << ")\n";
    }

    void showData( int data ){
        
        int index = data % 10 ;
        if( user[index] == data ){
            cout <<"The data is found at Index "<<index<<endl;
        }
        else{
            bool flag = false ;
            for( int i = 0 ; i < 10 ; i++ ){
                if( user[i] == data ){
                    flag = true ;
                    cout <<"The data is found at Index "<<i<<endl;
                }
            }
            if( !flag ){
                cout <<"The data is not Found"<<endl;
            }
            
        }
        
    }

    void printData(){
        for( int i = 0 ; i < 10 ; i++ ){
            if( user[i] != -1 ){
                cout << "The key is "<<i<<" and the Value is "<<user[i]<<endl;
            }
        }
    }

};

int main(){

    telephone t ;
    t.insertData(10);
    t.insertData(12);
    t.insertData(15);
    t.insertData(22);
    t.insertData(224);
    t.insertData(28);

    t.showData(12);
    t.showData(25);

    t.printData();

    return 0 ;
}