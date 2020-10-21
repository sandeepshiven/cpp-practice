#include<bits/stdc++.h>

using namespace std;






void reverse(queue<int> &q){
    stack<int>s;
    while(!(q.empty())){
        s.push(q.front());
        q.pop();
    }
    while(!(s.empty())){
        q.push(s.top());
        s.pop();
    }
}




int main(){

    queue<int>q;
    
    reverse(q);

    return 0;
}