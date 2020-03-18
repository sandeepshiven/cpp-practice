#include<bits/stdc++.h>

using namespace std;

struct MyHash{

    int *table;
    int cap, size;
    

    MyHash(int C){    // constructor for the structure
        size = 0;
        cap = C;
        table = new int [cap];
        for(int i=0; i<cap; i++)
            table[i] = -1;   // -1 for empty cell and -2 for deleted cell

    } 

    void insert(int key){
        if (size >= cap){
            cout << "\nTable full Cannot insert\n";
            return;
        }
        int index1 = hash1(key);
        int index2 = hash2(key);
        int slot = index1;
        if(table[index1] != -1 && table[index1] != -2 && table[index1] != key){
            slot = (index1 + index2)%cap;
            for(int i = 2; (table[slot] != -1 && table[slot] != -2 && table[slot] != key); i++){
                slot = (index1 + i*index2)%cap;
            }
        }
        table[slot] = key;
        size++;
    }
    void search(int key){
        if (size == 0){
            cout << "\nTable is empty\n";
            return;
        }
        int index1 = hash1(key);
        int index2 = hash2(key);
        int slot = (index1 + index2)%cap;
        int j = slot;
        if (table[index1] == key || table[slot] == key){
            cout <<key <<" is present in table\n";
            return;
        }
        slot = (index1 + 2*index2)%cap;
        int k = 3;
        while(table[slot]!= -1 && slot != j ){
            if (table[slot] == key){
                cout <<key <<" is present in table\n";
                return;
            }
            slot = (index1 + k*index2)%cap;
            k++;
        }
        cout <<key <<" is not present in table\n";
                
    }


    void _delete(int key){
        if (size == 0){
            cout << "\nTable is empty\n";
            return;
        }
        int index1 = hash1(key);
        int index2 = hash2(key);
        if (table[index1] == key){
            table[index1] = -2;
            size--;
            return;
        }
        int slot = (index1 + index2)%cap;
        int j = slot;
        int k=3;
        if (table[slot] == key){
            table[slot] = -2;
            size--;
            return;
        }
        slot = (index1 + 2*index2)%cap;
        while(table[slot]!= -1 && slot != j ){
            if (table[slot] == key){
                table[slot] = -2;
                size--;
                return;
            }
            slot = (index1 + k*index2)%cap;
            k++;
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
        int hash1(int key){return key%cap;}
        int hash2(int key){return (cap-1)-(key%(cap-1));}


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





























































