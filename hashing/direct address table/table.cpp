#include<bits/stdc++.h>

using namespace std;


void search(vector<int> &arr, int num);
void _delete(vector<int> &arr, int num);
void insert(vector<int> &arr, int num);

int main(){

    vector<int>arr(1000);
    while(true){
        int choice;
        cout<<"Operations\n1. Insert\n2. Search\n3. Delete\n4. Exit\nEnter your choice: ";
        cin >> choice;
        int num; 
        switch (choice)
        {
        case 1:
            cout <<"Enter the number you want to insert: ";
            cin >>num;
            insert(arr,num);
            break;
        case 2:
            cout <<"Enter the number you want to search: ";
         
            cin >>num;
            search(arr,num);
            break;

        case 3:
            cout <<"Enter the number you want to delete: ";
            cin >>num;
            _delete(arr,num);
            break;


        default:
            break;
        }
        
    }

    return 0;
}

void insert(vector<int> &arr, int num){
    arr[num] = 1;
    cout << num <<" inserted\n";
}
void search(vector<int> &arr, int num){
    if(arr[num] == 0){

    cout << num <<" is not present\n";
    }
    else{
        cout << num <<" is present\n";
    }
}

void _delete(vector<int> &arr, int num){
    arr[num] = 0;
    cout << num <<" deleted\n";
}




























