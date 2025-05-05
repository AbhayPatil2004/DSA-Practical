// Department maintains a student information. The file contains roll number, name, division and 
// address. Allow user to add, delete information of student. Display information of particular 
// employee. If record of student does not exist an appropriate message is displayed. If it is, then the 
// system displays the student details. Use sequential file to main the data. 

// #include<iostream>
// #include<fstream>

// using namespace std ;

// int main(){

//     // string s = "Abhay Patil";
//     // string data ;
//     // ofstream out("sample.txt");
//     // out<<s; 
//     // out.close();

//     // ifstream in("sample.txt");
//     // // in >> data ;
//     // getline( in , data );
//     // in.close();
//     // cout << data ;

//     // ofstream out("Hello.txt" , ios :: app);
//     // out<<"Abhay Ramkrushna Patil";
//     // out.close() ;

//     // ifstream in("Hello.txt");
//     // string word ;

//     // while( in >> word ){
//     //     cout << word ;
//     // }
//     // return 0 ;
// }

#include<iostream>
#include<fstream>
using namespace std ;

class student{

    public:
    int rollNo ;
    string name ;
    string div ;
    string add ;
};

void input(){

    student s;
    ofstream out("students.txt" , ios::app );

    cout <<"Enter the RollNo of Student :- ";
    cin >> s.rollNo ;
    cout << endl;
    cout <<"Enter the Name of Student :- ";
    cin >> s.name ;
    cout << endl;
    cout <<"Enter the Division of Student :- ";
    cin >> s.div ;
    cout << endl;
    cout <<"Enter the Address of Student :- ";
    cin >> s.add ;
    cout << endl;

    out << " Roll No :- "<< s.rollNo << " , " << " Name :- "<< s.name << " , " << " Division :- "<< s.div << " , " << " Address :- "<< s.add << "\n";
    out.close() ;
    cout << "Student Data Added Succesfully "<<endl;
}

bool check( string word , int n ){

    string rollNo = to_string(n) ;
    string temp ;

    for( int i = 0 ; i < word.size() ; i++ ){
        if( word[i] >= '0' && word[i] <= '9' ){
            temp.push_back(word[i]);
        }
    }

    if( temp == rollNo ){
        return true ;
    }
    return false ;
}

void search(){

    int n ;
    cout << "Enter the Roll No of Student :- ";
    cin >> n ;

    ifstream in("students.txt");
    string word ;
    
    while( getline( in , word )){
        if( check( word , n ) ){
            cout <<"Student Data Succesfully Found "<<endl;
            cout << word << endl;
            return ;
        }
    }
    in.close() ;
    cout <<"Student Data Not Found "<<endl;
}

void deletData(){

    int n ;
    cout << "Enter the Roll No of Student :- ";
    cin >> n ;

    ifstream in("students.txt");
    ofstream out("temp.txt",ios::app);
    string word ;
    bool flag = true ;

    while( getline( in , word )){
        if( !check( word , n ) ){
            out<<word<<"\n";
        }
        else{
            flag = false ;
        }
    }
    in.close() ;
    out.close() ;
    remove("students.txt");
    rename("temp.txt", "students.txt");

    if( flag ){
        cout<<"Student Data not Found "<<endl;
    }
    else{
        cout <<"Student Data is Succesfully Deleted "<<endl;
    }

}

void display(){

    ifstream in("students.txt");
    string word ;
    cout <<"Student Data "<<endl;
    while( getline( in , word )){
        cout << word << endl;
    }

}

int main(){

    input();
    search();
    deletData() ;
    display() ;
    return 0 ;
}
