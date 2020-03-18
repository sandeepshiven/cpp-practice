#include<bits/stdc++.h>

using namespace std;

struct MyHash{

    int BUCKET;
    list<int> *table;

    MyHash(int b){    // constructor for the structure
        BUCKET = b;
        table = new list<int> [BUCKET];
    } 

    void insert(int key){
        int num = hashfunction(key);
        table[num].push_back(key);
    }
    void search(int key){
        int num = hashfunction(key);
        for(auto i : table[num]){
            if (i == key){
                cout <<key <<" is present in table\n";
                return;
            }
        }
        cout <<key <<" is not present in table\n";
                
    }


    void _delete(int key){
        int num = hashfunction(key);
        table[num].remove(key);
    }
    void show(){
        for(int i=0; i<BUCKET;i++){
            for(auto i: table[i]){
                cout << i << "-->";
            }
            cout <<"\n";
        }
    }
    private:
        int hashfunction(int key){return key%BUCKET;}


};



int main(){

    cout << "Enter the size of BUCKET: ";
    int s; 
    cin >> s;
    MyHash Table(s);
    while(true){
        int c;
        int num;
        cout <<"\nEnter the operation\n1. Insert\n2. Search\n3. Delete\n4. Show Table\n5. Exit\n";
        cout <<"Enter choice: ";
        cin >> c;
        switch(c){
        case 1:
            cout << "Enter the number you want to insert: ";
            cin >> num;
            Table.insert(num);           
            break;

        case 2:
            cout << "Enter the number you want to search: ";
            cin >> num;
            Table.search(num);           
            break;
        
        case 3:
            cout << "Enter the number you want to delete: ";
            cin >> num;
            Table._delete(num);           
            break;

        case 4:
            Table.show();           
            break;
            
        

        default:
            exit(0);
        }
    }
}





























































