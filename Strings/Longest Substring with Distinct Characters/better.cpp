#include<bits/stdc++.h>

using namespace std;





int main(){

    string txt;
    cout << "Enter string: ";
    cin >> txt;
    int n = txt.length();

    int res = 0, i=0;
    vector<int>prev(256, -1);
    for(int j=0; j<n; j++){
        i = max(i, prev[txt[j]]+1);
        int maxEnd = j - i + 1;
        res = max(res, maxEnd);
        prev[txt[j]] = j;
    }
    cout << res << '\n';


    return 0;

}



























