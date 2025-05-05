// There are flight paths between cities. If there is a flight between city A and city B then there is an 
// edge between the cities. The cost of the edge can be the time that flight take to reach city B from A, 
// or the amount of fuel used for the journey. Represent this as a graph. The node can be represented by 
// airport name or name of the city. Use adjacency list representation of the graph or use adjacency 
// matrix representation of the graph. Justify the storage representation used. 

#include<iostream>
#include<vector>
using namespace std ;

class flight{

    public:
    vector<char> cities;
    vector<vector<int>> distance ;

    flight( int n ){
        cities.resize( n );
        distance.resize( n , vector<int> ( n , 0 ));
    }

    void takeCities( int n ){
        char ch ;
        for( int i = 0 ; i < n ; i++ ){
            cout <<"Enter the name of "<<i+1<<" City :- ";
            cin >> ch ;
            cities[i] = ch ;
        }
    }

    void takeDistance(){

        int n ;
        for( int i = 0 ; i < distance.size() ; i++ ){

            for( int j = 0 ; j < distance.size() ; j++ ){

                if( j > i ){
                    cout << "Enter the Distance from City "<<cities[i]<<" to "<<cities[j] << " :- ";
                    cin >> n ;
                    distance[i][j] = n ;
                }
                else if( i != j ){
                    distance[i][j] = distance[j][i];
                }
                cout << endl;
            }
            cout << endl;
        }
        
    }

    void printDistance(){

        cout << "   ";
        for( int i = 0 ; i < cities.size() ; i++ ){
            cout << cities[i] << "  ";
        }
        cout << endl <<endl;
        for( int i = 0 ; i < cities.size() ; i++ ){

            cout <<cities[i] << "  ";
            for( int j = 0 ; j < distance[i].size() ; j++ ){
                cout << distance[i][j]<<"  ";
            }
            cout << endl<<endl;
        }
    }
};

int main(){

    int n ;
    cout << "Enter the Number of Cities :- ";
    cin >> n ;
    flight f(n);
    f.takeCities(n);
    f.takeDistance() ;
    f.printDistance();

    return 0 ;
}