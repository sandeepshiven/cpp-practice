#include <bits/stdc++.h> 
using namespace std;


class LRUCache{
    
    list<int>dq;

    unordered_map<int, list<int>::iterator> ma;
    int csize;

    public:
        LRUCache(int);
        void refer(int);
        void display();
};

LRUCache::LRUCache(int n){
    csize = n;
}

void LRUCache::refer(int x){

    if(ma.find(x) == ma.end()){
        if(dq.size() == csize){
            int last = dq.back();
            dq.pop_back();
            ma.erase(last);
        }
        
    }
    else{
        dq.erase(ma[x]);
    }
    dq.push_front(x);
    ma[x] = dq.begin();

}

void LRUCache::display(){

    for(auto i: dq){
        cout << i << " ⇄ ";
    }
    cout << "NULL\n";

    
}





int main(){

    int s;
    cout << "Enter the size of cache: ";
    cin >> s;
    cout << "Enter reference sequence size: ";
    int temp;
    cin >> temp;

    vector<int>vec(temp);

    cout << "Enter reference sequence: ";

    for(int i=0; i<temp; i++){
        cin >> vec[i];
    }

    LRUCache ca(s);

    for(auto i: vec){
        
        ca.refer(i);
        ca.display();

    }


    return 0;
}




















