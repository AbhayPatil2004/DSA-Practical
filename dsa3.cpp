// A book consists of chapters, chapters consist of 
// sections and sections consist of subsections.  
// Construct a tree and print the nodes. Find the time 
// and space requirements of your method. 

#include<iostream>
#include<vector>
using namespace std ;

class Node{

    public:
    string name ;
    vector<Node*> childern ;
    
    Node( string str ){
        this -> name = str ;
    }

    void addChildern( Node* child ){
        childern.push_back(child);
    }
};

void print( Node* root ){
    if( root == NULL ){
        return ;
    }
    cout << "Name of Book :- "<<root -> name <<endl;
    vector<Node*> chapters = root -> childern ;
    for( int i = 0 ; i < chapters.size() ; i++ ){
        cout << " Chapter" << i+1 << chapters[i]->name <<" ";
        vector<Node*> sections = chapters[i] -> childern ;
        for( int j = 0 ; j < sections.size() ; j++ ){
            cout << " Section of " << j+1 << sections[i]->name <<" ";
        }
    }

}

int main(){

    
    string name ;
    cout << "Enter the name of Book :- ";
    cin >> name ;
    Node* book = new Node(name);

    int n ;
    cout << "Enter the Number of Chaptes :- "<<endl;
    cin >> n ;

    for( int i = 0 ; i < n ; i++ ){

        cout << "Enter the name of " << i+1 << " Chapter :- ";
        cin >> name ; 
        Node* chapter = new Node(name);
        book->addChildern(chapter) ;

        cout << "Enter the Number of Section :- "<<endl;
        cin >> n ;

        for( int j = 0 ; j < n ; j ++ ){
            cout << "Enter the name of " << j+1 << " section :- ";
            cin >> name ; 
            Node* section = new Node(name);
            chapter->addChildern(section);

        }

    }

    print(book);

    return 0 ;
}