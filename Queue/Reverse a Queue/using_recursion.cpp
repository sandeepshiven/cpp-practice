#include<bits/stdc++.h>

using namespace std;






void reverse(queue<int> &q){
    
    if(q.empty()){
        return;
    }
    int x = q.front();
    q.pop();
    reverse(q);
    q.push(x);

}




int main(){

    queue<int>q;
    
    reverse(q);

    return 0;
}