#include<bits/stdc++.h>

using namespace std;

int main(){

    cout << "Enter the size of array: ";
    int n; 
    cin >> n;
    cout << "Enter "<<n<<" elements of array: ";
    vector<int>vec(n);
    for(int i=0; i<n; i++){
        cin >> vec[i];
    }
    cout << "Enter value of k: ";
    int k;
    cin >> k;

    deque<int>dq;
    
    for(int i=0; i<k; i++){
        while(!dq.empty() &&(vec[dq.back()]<=vec[i])){
            dq.pop_back();
        }
        dq.push_back(i);
    }

    for(int i=k; i<n; i++){
        cout << vec[dq.front()]<<" ";
        while(!dq.empty() && (dq.front()<=i-k)){
            dq.pop_front();
        }
        while(!dq.empty()&&(vec[i]>=vec[dq.back()])){
            dq.pop_back();
        }
        dq.push_back(i);
    }
    cout<<vec[dq.front()]<<'\n';

    return 0;
}