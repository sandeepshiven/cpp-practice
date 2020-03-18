// INCOMPLETE CODE DO NOT RUN


#include<bits/stdc++.h>

using namespace std;

struct MyHash{

    int *table;
    int cap, size;
    

    MyHash(int C){    // constructor for the structure
        size = 0;
        cap = C;
        table = new int [cap*3];
        for(int i=0; i<cap; i++)
            table[i] = -1;   // -1 for empty cell and -2 for deleted cell

    } 

    void insert(int key){
        if (size >= cap){
            cout << "\nTable full Cannot insert\n";
            return;
        }
        
        int slot = hashfunction(key);
        int j = slot;
        for(int i = 1; (table[j] != -1 && table[j] != -2 && table[j] != key); i++){
            j = (slot + (i*i))%cap; 
        }
        table[j] = key;
        size++;
    }


    void search(int key){
        if (size == 0){
            cout << "\nTable is empty\n";
            return;
        }
        int i = hashfunction(key);
        int j = i;
        if (table[i] == key){
            cout <<key <<" is present in table\n";
            return;
        }
        i = (i+1)%cap;
        int k=2;
        while(table[i]!= -1 && i != j ){
            if (table[i] == key){
                cout <<key <<" is present in table\n";
                return;
            }
            i = (j+(k*k))%cap;
        }
        cout <<key <<" is not present in table\n";
                
    }


    void _delete(int key){
        if (size == 0){
            cout << "\nTable is empty\n";
            return;
        }
        int i = hashfunction(key);
        int j = i;
        if (table[i] == key){
            table[i] = -2;
            size--;
            return;
        }
        i = (i+1)%cap;
        while(table[i]!= -1 && i != j ){
            if (table[i] == key){
                table[i] = -2;
                size--;
                return;
            }
            i = (i+1)%cap;
        }
    }
    void show(){
        for(int i=0; i<cap;i++){
            cout << "Slot "<< i << "--> ";
            if(table[i] == -1){
                cout << "EMPTY";
            }
            else if(table[i] == -2){
                cout << "DELETED";
            }
            else{
                cout << table[i];
            }
            cout <<"\n";
        }
    }
    private:
        int hashfunction(int key){return key%cap;}


};



int main(){

    cout << "Enter the size of Table: ";
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





























































