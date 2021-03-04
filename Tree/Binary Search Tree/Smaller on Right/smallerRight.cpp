#include<bits/stdc++.h>

#include <iostream>
using namespace std;


int main() {
	//code
	int t;
	cin >> t;
	while(t--){
	    set<int>s;
	    int sz, res=0;
	    cin >>sz;
	    vector<int>vc(sz);
	    for(int i=0; i<sz; i++){
	        cin >> vc[i];
	    }
	    s.insert(vc[sz-1]);
	    for(int i=sz-2; i>=0; i--){
	        s.insert(vc[i]);
	        auto it = s.find(vc[i]);
	        int dis = distance(s.begin(), it);
	        res = max(res, dis);
	    }
	    cout << res <<'\n';
	}
	return 0;
}