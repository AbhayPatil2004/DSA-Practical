// You have a business with several offices; you want to lease phone lines to connect them up with each 
// other; and the phone company charges different amounts of money to connect different pairs of 
// cities. You want a set of lines that connects all your offices with a minimum total cost. Solve the 
// problem by suggesting appropriate data structures.

#include<iostream>
#include<vector>
#include <climits>

using namespace std ;

class buisness{

    public:
    vector<char> offices;
    vector<vector<int>> distance ;
    vector<pair<int,bool>> mst ;
    vector<int>parent;

    buisness( int n ){
        offices.resize( n );
        distance.resize( n , vector<int> ( n , INT_MAX ));
        mst.resize( n , { INT_MAX , false });
        parent.resize( n , -1 );
    }

    void takeOffices( int n ){
        char ch ;
        for( int i = 0 ; i < n ; i++ ){
            cout <<"Enter the name of "<<i+1<<" City :- ";
            cin >> ch ;
            offices[i] = ch ;
        }
    }

    void takeDistance(){

        int n ;
        for( int i = 0 ; i < distance.size() ; i++ ){

            for( int j = 0 ; j < distance.size() ; j++ ){

                if( j > i ){
                    cout << "Enter the Distance from City "<<offices[i]<<" to "<<offices[j] << " / If no Edge is Present enter -1 :- "<<endl;
                    
                    cin >> n ;
                    if( n != -1 ){
                        distance[i][j] = n ;
                    }
                    
                }
                else if( i == j ){
                    distance[i][j] = 0 ;
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
        for( int i = 0 ; i < offices.size() ; i++ ){
            cout << offices[i] << "  ";
        }
        cout << endl <<endl;
        for( int i = 0 ; i < offices.size() ; i++ ){

            cout <<offices[i] << "  ";
            for( int j = 0 ; j < distance[i].size() ; j++ ){
                cout << distance[i][j]<<"  ";
            }
            cout << endl<<endl;
        }
    }

    // void prims(){
         
    //     mst[0] = { 0 , true };
    //     int minIndex = 0 ;
      
    //     while( true ){

    //         for( int i = 0 ; i < distance.size() ; i++ ){
    //             if( distance[minIndex][i] < mst[i].first ){
    //                 mst[i].first = distance[minIndex][i];
    //                 parent[i] = minIndex ;
    //             }
    //         }
            
    //         int minValue = INT8_MAX ;
    //         for( int i = 0 ; i < mst.size() ; i++ ){

    //             if( mst[i].first < minValue && !mst[i].second ){
    //                 minValue = mst[i].first ;
    //                 minIndex = i;
    //             }
    //         }

    //         if( minValue == INT8_MAX ){
    //             break ;
    //         }
    //         else{
    //             parent[minIndex] = true ;
    //         }

    //     }

    //     int minDistance = 0 ;
    //     for( int i = 0 ; i < mst.size() ; i++ ){
    //         minDistance += mst[i].first ;
    //     }
    // }

     // For INT_MAX

    void prims() {

        int n = distance.size();
        mst[0] = {0, false}; // Start with first vertex
        parent[0] = -1;

        for (int count = 0; count < n - 1; count++) {
            int minValue = INT_MAX, minIndex;

            // Find the minimum value vertex not yet in MST
            for (int i = 0; i < n; i++) {
                if (!mst[i].second && mst[i].first < minValue) {
                    minValue = mst[i].first;
                    minIndex = i;
                }
            }

            // Add selected vertex to MST
            mst[minIndex].second = true;

            // Update key values of adjacent vertices
            for (int i = 0; i < n; i++) {
                if (!mst[i].second && distance[minIndex][i] < mst[i].first) {
                    mst[i].first = distance[minIndex][i];
                    parent[i] = minIndex;
                }
            }
        }

        // Display MST
        int totalCost = 0;
        cout << "\nMinimum Spanning Tree:\n";
        for (int i = 1; i < n; i++) {
            cout << offices[parent[i]] << " - " << offices[i] << " : " << distance[i][parent[i]] << endl;
            totalCost += distance[i][parent[i]];
        }
        cout << "Total Minimum Cost: " << totalCost << endl;
    }

};

int main(){

    int n ;
    cout << "Enter the Number of Offices :- ";
    cin >> n ;

    buisness b(n);
    cout << endl;
    b.takeOffices(n) ;
    cout << endl;
    b.takeDistance() ;
    cout << endl;
    b.printDistance() ;
    cout << endl;
    b.prims() ;
    cout << endl;

    return 0;

}

