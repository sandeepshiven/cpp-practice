#include<bits/stdc++.h>

using namespace std;





int main(){

    string txt;
    cout << "Enter string: ";
    cin >> txt;
    int n = txt.length();

    int res = 0;
    for(int i=0; i<n; i++){
        vector<bool>count(256, false);
        for(int j =i; j<n; j++){
            if(count[txt[j]] == true){
                break;
            }
            else{
                res = max(res, j-i+1);
                count[txt[j]] = true;
            }
        }
    }
    cout << res << '\n';


    return 0;

}



























